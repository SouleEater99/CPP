#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(int argc, char **argv) {

    parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
        throw std::invalid_argument("Error: No input provided.");
    for (int i = 1; i < argc; ++i)
    {
        char *endptr;
        long num = std::strtol(argv[i], &endptr, 10);
        
        // Check if conversion failed or has trailing characters
        if (*endptr != '\0' || num <= 0)
        throw std::invalid_argument("Error: Invalid argument.");
        
        _vector.push_back(static_cast<int>(num));
        _deque.push_back(static_cast<int>(num));
    }
}


void PmergeMe::mergeInsertSort(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;
    
    // Create pairs and separate big/small
    std::vector<int> big_numbers;
    std::vector<int> small_numbers;
    
    // Process pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
        {
            big_numbers.push_back(vec[i]);
            small_numbers.push_back(vec[i + 1]);
        }
        else
        {
            big_numbers.push_back(vec[i + 1]);
            small_numbers.push_back(vec[i]);
        }
    }
    
    // Handle odd element (if exists)
    if (vec.size() % 2 == 1)
    {
        small_numbers.push_back(vec.back());
    }
    
    // Recursively sort big numbers
    mergeInsertSort(big_numbers);

    // Insert small numbers into sorted big numbers
    for (size_t i = 0; i < small_numbers.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(big_numbers.begin(), big_numbers.end(), small_numbers[i]);
        big_numbers.insert(pos, small_numbers[i]);
    }
    
    // Copy sorted result back to original vector
    vec = big_numbers;
}

void PmergeMe::mergeInsertSort(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return;

    // Create pairs and separate big/small
    std::deque<int> big_numbers;
    std::deque<int> small_numbers;

    // Process pairs
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
        {
            big_numbers.push_back(deq[i]);
            small_numbers.push_back(deq[i + 1]);
        }
        else
        {
            big_numbers.push_back(deq[i + 1]);
            small_numbers.push_back(deq[i]);
        }
    }

    // Handle odd element (if exists)
    if (deq.size() % 2 == 1)
    {
        small_numbers.push_back(deq.back());
    }

    // Recursively sort big numbers
    mergeInsertSort(big_numbers);

    // Insert small numbers into sorted big numbers
    for (size_t i = 0; i < small_numbers.size(); ++i)
    {
        std::deque<int>::iterator pos = std::lower_bound(big_numbers.begin(), big_numbers.end(), small_numbers[i]);
        big_numbers.insert(pos, small_numbers[i]);
    }

    // Copy sorted result back to original deque
    deq = big_numbers;
}

void PmergeMe::sort()
{

    // Time sorting for vector
    std::clock_t start_vec = std::clock();
    std::vector<int> temp_vector = _vector; // Copy for timing
    mergeInsertSort(temp_vector);
    std::clock_t end_vec = std::clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000; // microseconds

    // Time sorting for deque
    std::clock_t start_deq = std::clock();
    std::deque<int> temp_deque = _deque; // Copy for timing
    mergeInsertSort(temp_deque);
    std::clock_t end_deq = std::clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000; // microseconds

    // Print timing results
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "After:  ";
    for (size_t i = 0; i < temp_vector.size(); ++i)
        std::cout << temp_vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << time_deq << " us" << std::endl;
}
