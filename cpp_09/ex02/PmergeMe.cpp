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
