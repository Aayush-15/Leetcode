class Solution {
public:
    string simplifyPath(string path) {
        stack<string>Stack_;
        stringstream StringStream_Path(path);
        vector<string> tokens;
        string curr_subpart;

        while(getline(StringStream_Path,curr_subpart,'/')){
            tokens.push_back(curr_subpart);
        }

        for(auto curr_token:tokens){
            cout<<curr_token<<endl;
            if(curr_token==".."){
                if(!Stack_.empty()){
                    Stack_.pop();
                }
            }
            else if(curr_token=="."){
                continue;
            }
            else if(curr_token.size()>0){
                Stack_.push(curr_token);
            }
        }
        string result="";
        if(Stack_.empty()){
            return "/";
        }
        while(!Stack_.empty()){
            result="/"+Stack_.top()+result;
            Stack_.pop();
        }
        return result; 
    }
};

//getline (istream& is, string& str, char delim);
//Get line from stream into string
// Extracts characters from is and stores them into str until the delimitation character delim is found (or the newline character, '\n', for (2)).
/*What Happens:
The function reads characters from ss (the stringstream) one by one until it encounters the delimiter '/'.
It stores the extracted characters (before the '/') in the temp variable.
After extracting one token, ss moves past the delimiter '/' and continues reading from the next position.*/


