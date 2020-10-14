#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
bool has_element(const std::pair<int, std::string> i){
    return ((i.first >=3) && (i.first <= 8));
}
int main() {
    std::unordered_multimap<int, std::string> umap;
    for(int i = 1; i<=20; ++i){
        for(int j = 1; j <= 3; ++j){
            umap.insert(std::make_pair(i, "Num" + std::to_string(i) + "_" + std::to_string(j)));
        }
    }
    umap.erase(6);
    umap.erase(7);
    for(int i=1; i<=3; i++){
        umap.insert(std::make_pair(3, "Num3_"+std::to_string(i)));
    }
    std::map<int, std::string> map;
    for(auto i : umap){
        map.insert(std::make_pair(i.first, i.second));
    }
    for(auto i : map){
        std::cout << i.first << ' ' << i.second << std::endl;
    }
    int kol = std::count_if(map.begin(), map.end(), has_element);
    std::cout << "Count of elements in map from 3 to 8 is - " << kol << std::endl;
    std::vector<int> vec;
    std::transform(map.begin(), map.end(), std::back_inserter(vec), [](const std::pair<int, std::string> i){return i.first;});
    for(int i: vec){std::cout << i << " ";}

    return 0;
}
