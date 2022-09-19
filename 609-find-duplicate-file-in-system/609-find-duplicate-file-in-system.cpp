class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> tracker;
        
        for (auto& path : paths) {
            stringstream ss(path);
            string folder, file;
            
            ss >> folder;
            
            while (ss >> file) {
                auto pos = file.find('(');
                string name = file.substr(0, pos);
                string content = file.substr(pos + 1); content.pop_back();
                                
                tracker[content].push_back(folder + '/' + name);
            }
        }
        
        vector<vector<string>> result;
        
        for (auto& it : tracker)
            if (it.second.size() > 1)
                result.push_back(it.second);
        
        return result;
    }
};