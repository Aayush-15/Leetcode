class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        
        sort(products.begin(), products.end());
        
        vector<vector<string>> v;
        string curr = "";
        for(auto& c : searchWord) {
            curr += c;
            
            vector<string> temp;
            
            int pos = (lower_bound(products.begin(), products.end(), curr) - products.begin());
            
            for(int i=pos; i<min(pos+3, n); i++) {
                if(products[i].compare(0, curr.length(), curr)) 
                    break;
                
                temp.push_back(products[i]);
            }
            
            v.push_back(temp);
        }
        
        return v;
    }
};