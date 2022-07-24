struct Food{
  string Name;
  string Cuisine;
  int rating;
  
    Food(string name_,string cuis_,int rating_)
    {
        Name=name_;
        Cuisine=cuis_;
        rating=rating_;
    }
    
    friend bool operator<(const Food &x,const Food &y)
    {
        if(x.rating==y.rating)
        {
            return x.Name<y.Name;
        }
        return x.rating>y.rating;
    }
};


class FoodRatings {
public:
    map<string,set<Food>>all_info;
    map<string, pair<string, int>> cuisine_and_rating_per_food;//maps food To Cuisine
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
       for(int i=0;i<foods.size();i++)
       {
           cuisine_and_rating_per_food[foods[i]] = {cuisines[i], ratings[i]};
           all_info[cuisines[i]].insert(Food(foods[i],cuisines[i],ratings[i]));
       }
    }
    void changeRating(string food, int newRating) 
    {
        int old_rating=cuisine_and_rating_per_food[food].second;
        string cuisine_=cuisine_and_rating_per_food[food].first;
        all_info[cuisine_].erase(Food(food,cuisine_,old_rating));
        all_info[cuisine_].insert(Food(food,cuisine_,newRating));
        cuisine_and_rating_per_food[food]={cuisine_,newRating};
    }
    
    string highestRated(string cuisine) {
        return all_info[cuisine].begin()->Name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */