#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <thread>
#include <future>
#include <numeric>

#include "e2.h"

//create shortcut
namespace sc = std::chrono;



int main() {

    std::vector<int> myVec (50000000);
    std::srand(0);

    //another, better option would be to use std::generate and a c++11ish random generator
    for(int i = 0; i < myVec.capacity(); ++i) {
        myVec[i] = std::rand() % 1000;
    }

    //http://en.cppreference.com/w/cpp/chrono
    auto start = sc::high_resolution_clock::now();

    int minVal;
    int maxVal;
    uint64_t sum;
    double average;

    //todo:  insert code here to populate these values
    //       the final execution time must be faster
    //       than what can be achieved with a single thread
    //      bonus points will be rewarded for fastest times

    // serial execution
//    sum = std::accumulate(myVec.begin(), myVec.end(), (uint64_t)0);
//    auto it = std::minmax_element(myVec.begin(), myVec.end());
//    minVal = *it.first;
//    maxVal = *it.second;
//    average = sum / myVec.size();

    std::future<uint64_t> f_sum1 = std::async(std::launch::async, [&] { return std::accumulate(myVec.begin(), myVec.end(), (uint64_t) 0); } );
    std::future f_it = std::async(std::launch::async, [&] { return std::minmax_element(myVec.begin(), myVec.end()); } );

    auto it = f_it.get();
    minVal = *it.first;
    maxVal = *it.second;
    sum = f_sum1.get();
    average = sum/myVec.size();

    auto end = sc::high_resolution_clock::now();

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cout << "Elapsed Time: " << sc::duration_cast<sc::milliseconds>(end - start).count() << "ms" << std::endl;
}