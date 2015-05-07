/*
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution {
public:
    void constructVecpath(string path, vector<string> &vecpath) {
        int st = 0; //position of "/"
        while (st+1 != path.length()) {
            int ed = path.find('/', st+1);  //next "/"
            //[st+1, ed-1] -- len = ed-1-st-1+1
            if (ed > st+1) {
                string str = path.substr(st+1, ed-st-1);
                vecpath.push_back(str);
            }
            st = ed;
        }
    }
    
    void simplifyVecpath(vector<string> &vecpath) {
        vector<string> ans;
        for (size_t i = 0; i < vecpath.size(); i++) {
            if (vecpath[i] == "..") {
                if (!ans.empty())
                    ans.pop_back();
            } else {
                if (vecpath[i] != ".") {
                    ans.push_back(vecpath[i]);
                }
            }
        }
        vecpath = ans;
    }
    
    string toString(vector<string> &vecpath) {
        string str = "";
        for (size_t i = 0; i < vecpath.size(); i++) {
           str += "/" + vecpath[i];
        }
        if (str == "") {
            str = "/";
        }
        return str;
    }

    string simplifyPath(string path) {
        vector<string> vecpath;
        path += "/";
        constructVecpath(path, vecpath);
        simplifyVecpath(vecpath);
        return toString(vecpath);
    }
};
