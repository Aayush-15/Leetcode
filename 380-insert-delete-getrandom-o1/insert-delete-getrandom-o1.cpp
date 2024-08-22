class RandomizedSet {
public:
    RandomizedSet() {
        // Constructor doesn't need to do anything since the vector and 
        // unordered_map are initialized by default
    }

    // Inserts a value to the set. Returns true if the set did not already contain the specified element
    bool insert(int val) {
        if (indexMap.count(val)) {
            // Value is already in the set, so insertion is not possible
            return false;
        }
        indexMap[val] = values.size(); // Map value to its index in 'values'
        values.push_back(val);         // Add value to the end of 'values'
        return true;
    }

    // Removes a value from the set. Returns true if the set contained the specified element
    bool remove(int val) {
        if (!indexMap.count(val)) {
            // Value is not in the set, so removal is not possible
            return false;
        }
      
        int index = indexMap[val];               // Get index of the element to remove
        indexMap[values.back()] = index;         // Map last element's index to the index of the one to be removed
        values[index] = values.back();           // Replace the element to remove with the last element
        values.pop_back();                       // Remove last element
        indexMap.erase(val);                      // Remove element from map
      
        return true;
    }

    // Gets a random element from the set
    int getRandom() {
        return values[rand() % values.size()]; // Return a random element by index
    }

private:
    std::unordered_map<int, int> indexMap; // Maps value to its index in 'values'
    std::vector<int> values;               // Stores the actual values
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */