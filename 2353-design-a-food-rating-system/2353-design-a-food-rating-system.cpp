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
    //Custom Comperator
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
    map<string,set<Food>>Food_Info;//Map Cuisine to Food
    map<string, pair<string, int>> food_to_cuisine;//maps food To Cuisine
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
       for(int i=0;i<foods.size();i++)
       {
           food_to_cuisine[foods[i]] = {cuisines[i], ratings[i]};
           Food_Info[cuisines[i]].insert(Food(foods[i],cuisines[i],ratings[i]));
       }
    }
    
    void changeRating(string food, int newRating) 
    {
        int old_rating=food_to_cuisine[food].second;
        string cuisine_=food_to_cuisine[food].first;
        Food_Info[cuisine_].erase(Food(food,cuisine_,old_rating));
        Food_Info[cuisine_].insert(Food(food,cuisine_,newRating));
        food_to_cuisine[food]={cuisine_,newRating};
    }
    
    string highestRated(string cuisine) {
        return Food_Info[cuisine].begin()->Name;
    }
};
