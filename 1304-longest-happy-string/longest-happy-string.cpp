class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char last_used='z';
        string result="";
        set<pair<int,char>>set_;
        if(a>0)
        set_.insert({a,'a'});
        if(b>0)
        set_.insert({b,'b'});
        if(c>0)
        set_.insert({c,'c'});
        while(set_.size()>0){
            auto it1= set_.end();
            it1--;
            char current_last =it1->second; 
            if(last_used!=current_last){
                auto it=set_.end();
                it--;
                int occ_used=0;
                char current_char=it->second;
                occ_used=min(it->first,2);
                last_used = it->second;
                for(int i=0;i<occ_used;i++){
                    result+=(current_char);
                }
                int total_occurance=it->first;
                set_.erase(it);
                int new_occurance=total_occurance-occ_used;
                if(new_occurance>0){
                    set_.insert({new_occurance,current_char});
                }
            }
            else{
                if(set_.size()<=1){
                    break;
                }
                it1--;
                int occ_used=0;
                char current_char=it1->second;
                int total_occurance=it1->first;
                if(total_occurance==0){
                    break;
                }
                // cout<<"2nd:Else:"<<current_char<<":"<<total_occurance<<endl;
                occ_used=min(it1->first,1);
                last_used = it1->second;
                for(int i=0;i<occ_used;i++){
                    result+=(current_char);
                }
                int new_occurance=total_occurance-occ_used;
                set_.erase(it1);
                if(new_occurance>0){
                    set_.insert({new_occurance,current_char});
                }
            }


        }
        return result;


        
    }
};