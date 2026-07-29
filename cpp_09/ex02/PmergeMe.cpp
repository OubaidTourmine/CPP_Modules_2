#include "PmergeMe.hpp"
static std::vector<unsigned int> g_vec;
static std::deque<unsigned int> g_deq;

bool is_valid_number(const std::string &str)
{
    if (str.empty())
        return false;

    for (std::size_t i = 0; i < str.size(); ++i)
    {
        if (std::isspace(static_cast<unsigned char>(str[i])))
            return false;
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

bool parse_args(int ac, char **av)
{
    if (ac < 2)
        return false;

    g_vec.clear();
    g_deq.clear();

    for (int i = 1; i < ac; ++i)
    {
        std::string str(av[i]);
        if (!is_valid_number(str))
            return false;

        int value = std::atoi(str.c_str());
        if(value < 0)
            return false;
        g_vec.push_back(value);
        g_deq.push_back(value);
    }
    return true;
}

static unsigned int jacobsthal(unsigned int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned int prev = 0;
    unsigned int curr = 1;
    for (unsigned int i = 2; i <= n; ++i)
    {
        unsigned int next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

template <typename Container>
static Container mergeInsertSort(Container &arr)
{
    if (arr.size() < 2)
        return arr;

    typedef std::pair<unsigned int, unsigned int> Pair;
    std::vector<Pair> pairs;
    int straggler = -1;
    bool hasStraggler = false;
    
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
    }

    std::size_t pair_count = arr.size() / 2;
    for (std::size_t i = 0; i < pair_count; ++i)
    {
        unsigned int a = arr[i * 2];
        unsigned int b = arr[i * 2 + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(Pair(a, b));
    }

    for (std::size_t i = 1; i < pairs.size(); ++i)
    {
        Pair key = pairs[i];
        std::size_t j = i;
        while (j > 0 && pairs[j - 1].first > key.first)
        {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }

    Container mainChain;
    Container pend;

    for (std::size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    Container insertionOrder;
    std::size_t jacobIndex = 3;
    std::size_t lastJacob = 1;

    while (lastJacob < pend.size())
    {
        std::size_t currentJacob = jacobsthal(jacobIndex);
        std::size_t start = std::min(static_cast<std::size_t>(currentJacob), pend.size());
        for (std::size_t i = start; i > lastJacob; --i)
        {
            insertionOrder.push_back(i - 1);
        }

        lastJacob = start;
        jacobIndex++;
    }

    for (std::size_t i = 0; i < insertionOrder.size(); i++)
    {
        std::size_t index = insertionOrder[i];
        unsigned int element = pend[index];
        unsigned int partner = pairs[index].first;

        typename Container::iterator partnerIt = std::lower_bound(mainChain.begin(), mainChain.end(), partner);
        typename Container::iterator insertIt = std::lower_bound(mainChain.begin(), partnerIt, element);

        mainChain.insert(insertIt, element);
    }

    if (hasStraggler)
    {
        typename Container::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    return mainChain;
}

template <typename Container>
static void print_limited(const Container &values, const std::string &label)
{
    std::cout << label << " ";

    std::size_t print_count = values.size();
    if (print_count > 5)
        print_count = 5;

    for (std::size_t i = 0; i < print_count; ++i)
        std::cout << values[i] << " ";

    if (values.size() > 5)
        std::cout << "[...]";

    std::cout << std::endl;
}

template <typename Container>
static double get_sort_time(const Container &values)
{
    struct timeval start;
    struct timeval end;
    Container copy = values;

    gettimeofday(&start, NULL);
    mergeInsertSort(copy);
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0;
    elapsed += (end.tv_usec - start.tv_usec);
    return elapsed;
}

void run()
{
    std::vector<unsigned int> vec_sorted = mergeInsertSort(g_vec);
    std::deque<unsigned int> deq_sorted = mergeInsertSort(g_deq);

    print_limited(g_vec, "Before:");
    print_limited(vec_sorted, "After:");

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << g_vec.size() << " elements with std::vector : "
              << get_sort_time(g_vec) << " us" << std::endl;
    std::cout << "Time to process a range of " << g_deq.size() << " elements with std::deque : "
              << get_sort_time(g_deq) << " us" << std::endl;
}

