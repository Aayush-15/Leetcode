 class NumArray {
    private:
        vector<int> _nums;
        vector<int> bit;
        
        int lower_bit(int i){
            return i&-i;
        }
        
        int query(int i){
            i++;
            int sum=0;
            while(i>0){
                sum+=bit[i];
                i-=lower_bit(i);
            }
            return sum;
        }
        
        void add(int i, int val){
            i++;
            while(i<bit.size()){
                bit[i]+=val;
                i+=lower_bit(i);
            }
        }
        
    public:
        NumArray(vector<int> &nums) : _nums(nums) {
            bit.resize(nums.size()+1);
            for(int i=0; i<nums.size(); i++){
                add(i, nums[i]);
            }
        }
    
        void update(int i, int val) {
            if(val!=_nums[i]){
                add(i, val-_nums[i]);
                _nums[i]=val;
            }
        }
    
        int sumRange(int i, int j) {
            return query(j)-query(i-1);
        }
    };
