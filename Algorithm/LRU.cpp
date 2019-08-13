#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>

using namespace std;

class LRU{
private:
    int capicity;
    list<pair<int,int>>cacheLists;
    unordered_map<int,list<pair<int,int>>::iterator>hmap;
public:
    LRU(int size):capicity(size){}
    int get(int key){
        if(hmap.find(key)!=hmap.end()){
            cacheLists.splice(cacheLists.begin(),cacheLists,hmap[key]);
            hmap[key] = cacheLists.begin();
            return hmap[key]->second;
        }
        return -1;
    }

    void put(int key,int value){
        if(hmap.find(key)!=hmap.end()){
            hmap[key]->second = value;
            cacheLists.splice(cacheLists.begin(),cacheLists,hmap[key]);
            hmap[key] = cacheLists.begin();
        }else{
            if(cacheLists.size()==capicity){
                hmap.erase(cacheLists.back().first);
                cacheLists.pop_back();
            }
            cacheLists.push_front(make_pair(key,value));
            hmap[key] = cacheLists.begin();
        }
    }

    void printf() const{
        for(const auto&a:cacheLists){
            cout<<"key: "<<a.first<<"\t";
            cout<<"value: "<<a.second<<endl;
        }
        cout<<endl;
    }
};

int main(){
    LRU cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cache.printf();
    cache.get(1);       // returns 1
    cache.printf();
    cache.put(3, 3);    // evicts key 2
    cache.printf();
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.printf();
    cache.get(1);       // returns -1 (not found)
    cache.printf();
    cache.get(3);       // returns 3
    cache.printf();
    cache.get(4);       // returns 4
    cache.printf();
}
