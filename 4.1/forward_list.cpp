//
// Created by root on 23-7-18.
//


// forward_list demo
#include<iostream>
#include<forward_list>

int main(){
    std::forward_list<int> fList = {1,2,3,4,5};
    for(auto it=fList.begin();it!=fList.end();it++){
        std::cout<<*it<<std::endl;
    }
    // fList.size(); // error
    return 0;
}
