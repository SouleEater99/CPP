#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    void parseInput(int argc, char **argv);
    void mergeInsertSort(std::vector<int> &vec);
    void mergeInsertSort(std::deque<int> &deq);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(int argc, char **argv);
    void printResults() const;

};




#endif