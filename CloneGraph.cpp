/*
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *
 *        1
 *              / \
 *                   /   \
 *                       0 --- 2
 *                                / \
 *                                         \_/
 */
/*
 * sol:
 *		like clone a list with random pointer
 *		first add a duplicate node to the end of the neighbors vector
 *		so the neighbors.back() represents the duplicate node
 *
 *		so for each duplicate node, its neighbors are the neighbors.back() for its original node
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void dup(UndirectedGraphNode *node) {
        static unordered_set<UndirectedGraphNode*> searched;
        if (node == NULL || searched.find(node) != searched.end()) {//searched
            return;
        }
        searched.insert(node);
        UndirectedGraphNode *dupnode = new UndirectedGraphNode(node->label);
        dupnode->neighbors = node->neighbors;
        node->neighbors.push_back(dupnode);
        for (size_t i = 0; i+1 < node->neighbors.size(); i++) {
            dup(node->neighbors[i]);
        }
    }
    
    void setToNext(UndirectedGraphNode *node) {
        static unordered_set<UndirectedGraphNode*> searched;
        if (node == NULL || searched.find(node) != searched.end()) {//searched
            return;
        }
        searched.insert(node);
        UndirectedGraphNode *dupnode = node->neighbors.back();
        for (size_t i = 0; i+1 < node->neighbors.size(); i++) {
            dupnode->neighbors[i] = node->neighbors[i]->neighbors.back();
            setToNext(node->neighbors[i]);
        }
    }

    void resume(UndirectedGraphNode *node) {
        static unordered_set<UndirectedGraphNode*> searched;
        if (node == NULL || searched.find(node) != searched.end()) {//searched
            return;
        }
        searched.insert(node);
        node->neighbors.pop_back();
        for (size_t i = 0; i < node->neighbors.size(); i++) {
            resume(node->neighbors[i]);
        }
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        dup(node);
        setToNext(node);
        UndirectedGraphNode *ans = node->neighbors.back();
        resume(node);
        return ans;
    }
};
