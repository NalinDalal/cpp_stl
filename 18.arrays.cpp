#include <iostream>
#include <array>

void PrintArray(const std::array<int,5>& data){
    for(int i=0;i<data.size(););
}
int main(){
    std::array<int,5> data; //dtata type and no
    data[0]=2;
    data[4]=1;

    std::array<int,5> dataOld;
    dataOld[0]=0;

    int data[5];
    data[0]=0;

    //stored in stack😂

    std::cout<<data[0]<<std::endl;
    std::cin.get();
}