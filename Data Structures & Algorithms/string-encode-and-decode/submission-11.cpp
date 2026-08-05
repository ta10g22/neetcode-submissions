#include <string>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string string_encoded = "";
        for (int i = 0; i < strs.size() ; i++){
            string_encoded += to_string(strs[i].size());
            string_encoded += '#';

            for(int j = 0 ; j < strs[i].size(); j++ ){
                string_encoded += strs[i][j];
            }
        }
        return string_encoded;
    }

    vector<string> decode(string s) {
        vector<string> string_decoded = {};
        int i = 0;

        while(i < s.size()){
            string num = "";
            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            int size_n = stoi(num);
            i++;

            string buffer = "";
            int j = 0;
            while(j < size_n){
                buffer.push_back(s[i]);
                i++;
                j++;
            }
            string_decoded.push_back(buffer);
        }

        return string_decoded;
    }
};
