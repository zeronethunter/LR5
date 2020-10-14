#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
bool has_element(const std::pair<int, std::string> i){
    return ((i.first >=3) && (i.first <= 8));
}
void print_map(std::pair<int, std::string> pair){
    std::cout << pair.first << ' ' << pair.second << std::endl;
}
void print_vector(int x){
    std::cout << x << ' ';
}
int main() {
    std::unordered_multimap<int, std::string> umap;
    for(int i = 1; i<=20; ++i){
        for(int j = 1; j <= 3; ++j){
            umap.insert(std::make_pair(i, "Num" + std::to_string(i) + "_" + std::to_string(j)));
        }
    }
    std::cout << "Your container:" << std::endl;
    std::for_each(umap.begin(), umap.end(), print_map);
    umap.erase(6);
    umap.erase(7);
    std::cout << "1.1.Your new container:" << std::endl;
    std::for_each(umap.begin(), umap.end(), print_map);
    for(int i=1; i<=3; i++){
        umap.insert(std::make_pair(3, "Num3_"+std::to_string(i)));
    }
    std::cout << "1.2.Your new container:" << std::endl;
    std::for_each(umap.begin(), umap.end(), print_map);
    std::map<int, std::string> map;
    for(auto i : umap){
        map.insert(std::make_pair(i.first, i.second));
    }
    std::cout << "1.3.Your new container:" << std::endl;
    std::for_each(map.begin(), map.end(), print_map);
    int kol = std::count_if(map.begin(), map.end(), has_element);
    std::cout << "2.1.Count of elements in map from 3 to 8 is - " << kol << std::endl;
    std::vector<int> vec;
    std::transform(map.begin(), map.end(), std::back_inserter(vec), [](const std::pair<int, std::string> i){return i.first;});
    std::cout << "2.2.New vector:\n";
    std::for_each(vec.begin(), vec.end(), print_vector);
    std::cout << std::endl;
    auto index_find = std::find(vec.begin(), vec.end(), 3);
    if (index_find == vec.end()){
        std::cout << "3.1.Number 3 is not found in vector\n";
    } else {
        std::cout << "3.1.Number 3 is at index - " << index_find - vec.begin() << std::endl;
    }



    return 0;
}
