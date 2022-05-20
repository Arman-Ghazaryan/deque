#include <iostream>
#include <algorithm>
#include <cassert>
#include <time.h>
#include "deque.h"
#include <deque>

int main()
{
    {
        deque<int> deq;
        assert(!deq.size());
    }

    {
        deque<int> deq(20);
        assert(deq.size() == 20);
        for (int i = 0; i < deq.size(); ++i)
            assert(deq[i] == 0);
    }

    {
        deque<int> deq(3, 7);
        assert(deq.size() == 3);
        for (int i = 0; i < deq.size(); ++i)
            assert(deq[i] == 7);
    }

    {
        deque<int> std_vec({1, 2, 3});
        assert(std_vec.size() == 3);
        for (int i = 0; i < std_vec.size(); ++i)
            assert(std_vec[i] == i + 1);
    }

    {
        deque<int> deq;
        for (int i = 0; i < 3; ++i)
        {
            deq.push_back(i);
            assert(deq[i] == i);
        }
    }

    {
        deque<int> deq;
        for (int i = 0; i < 100; ++i)
        {
            deq.push_front(i);
            assert(deq[0] == i);
        }
    }

    {
        std::vector<int> std_vec({0, 1, 2});
        deque<int> deq;

        deq.push_back(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(deq[i] == i);
        }
    }

    {
        std::vector<int> std_vec({0, 1, 2});
        deque<int> deq;

        deq.push_front(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(deq[i] == i);
        }
    }

    {
        deque<int> deq;

        deq.insert(0, 0);
        deq.insert(2, 1);
        deq.insert(1, 1);

        for (int i = 0; i < deq.size(); ++i)
            assert(deq[i] == i);
    }

    {
        deque<int> deq;

        deq.insert(0, 0, 3);
        deq.insert(2, 3, 3);
        deq.insert(1, 3, 3);

        for (int i = 0, d = 0; i < deq.size(); i += 3, ++d)
        {
            assert(deq[i] == d);
            assert(deq[i + 1] == d);
            assert(deq[i + 2] == d);
        }
    }

    {
        std::vector<int> std_vec({0, 1, 2});
        deque<int> deq;

        deq.insert(std_vec, 0);
        deq.insert(std_vec, 3);
        deq.insert(std_vec, 3);

        for (int i = 0, d = 0; i < deq.size(); i += 3)
        {
            assert(deq[i] == d);
            assert(deq[i + 1] == d + 1);
            assert(deq[i + 2] == d + 2);
        }
    }

    {
        deque<int> deq;
        deque<int>::iterator it;

        deq.insert(0, deq.begin());
        deq.insert(2, deq.end() + 1);
        it = deq.begin();
        ++it;
        deq.insert(1, it);

        for (int i = 0; i < 3; ++i)
        {
            assert(deq[i] == i);
        }
    }

    {
        deque<int> deq;
        deque<int>::iterator it;

        deq.insert(0, deq.begin(), 3);
        deq.insert(2, deq.end(), 3);
        it = deq.begin();
        ++it;
        ++it;
        ++it;
        deq.insert(1, it, 3);

        for (int i = 0, d = 0; i < deq.size(); i += 3, ++d)
        {
            assert(deq[i] == d);
            assert(deq[i + 1] == d);
            assert(deq[i + 2] == d);
        }
    }

    {
        std::vector<int> std_vec({0, 1, 2});
        deque<int>::iterator it;
        deque<int> deq;

        deq.insert(std_vec, deq.begin());
        deq.insert(std_vec, deq.end());
        it = deq.begin();
        ++it;
        ++it;
        ++it;
        deq.insert(std_vec, it);

        for (int i = 0, d = 0; i < deq.size(); i += 3)
        {
            assert(deq[i] == d);
            assert(deq[i + 1] == d + 1);
            assert(deq[i + 2] == d + 2);
        }
    }

    {
        deque<int> deq1({0, 1, 2});
        deque<int> deq;

        deq.insert(deq.begin(), deq1.begin(), deq1.end());
        deq.insert(deq.end() + 1, deq1.begin(), deq1.end());
        deq.insert(deq.begin() + 3, deq1.begin(), deq1.end());

        for (int i = 0, d = 0; i < deq.size(); i += 3)
        {
            assert(deq[i] == d);
            assert(deq[i + 1] == d + 1);
            assert(deq[i + 2] == d + 2);
        }
    }

    // // {
    // //     deque<int> deq;

    // //     deq.emplace(deq.begin(), 0);
    // //     deq.emplace(deq.end(), 2);
    // //     deq.emplace(deq.begin() + 1, 1);

    // //     for (int i = 0; i < 3; ++i)
    // //     {
    // //         assert(deq[i] == i);
    // //     }
    // // }

    // // {
    // //     deque<int> deq;

    // //     deque<int>::const_iterator it = deq.begin();
    // //     deq.emplace(it, 0);
    // //     deque<int>::const_iterator it1 = deq.end();
    // //     deq.emplace(it1, 2);
    // //     deque<int>::const_iterator it2 = deq.begin() + 1;
    // //     deq.emplace(it2, 1);

    // //     for (int i = 0; i < 3; ++i)
    // //     {
    // //         assert(deq[i] == i);
    // //     }
    // // }

    // // {
    // //     deque<int> deq(1, 1);

    // //     deq.emplace_front(0);
    // //     deq.emplace_back(2);

    // //     for (int i = 0; i < 3; ++i)
    // //     {
    // //         assert(deq[i] == i);
    // //     }
    // // }

    // // {
    // //     deque<int> deq;

    // //     deq.assign(20, 7);
    // //     assert(deq.size() == 20);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == 7);
    // // }

    // // {
    // //     deque<int> std_vec({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    // //     deque<int> deq;

    // //     deq.assign(std_vec.begin(), std_vec.end());

    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == i);
    // // }

    // // {
    // //     deque<int> deq({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    // //     deq.resize(5);

    // //     assert(deq.size() == 5);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == i);

    // //     deq.resize(10);

    // //     assert(deq.size() == 10);
    // //     for (int i = 5; i < deq.size(); ++i)
    // //         assert(deq[i] == 0);
    // // }

    // // {
    // //     srand(time(NULL));

    // //     deque<int> deq;

    // //     for (int i = 0; i < 10; ++i)
    // //         deq.push_back(rand() % 100);

    // //     std::sort(deq.begin(), deq.end());
    // //     for (int i = 0; i < deq.size() - 1; ++i)
    // //         assert(deq[i] <= deq[i + 1]);

    // //     std::sort(deq.begin(), deq.end(), std::greater<int>());
    // //     for (int i = 0; i < deq.size() - 1; ++i)
    // //         assert(deq[i] >= deq[i + 1]);
    // // }

    // {
    //     deque<int> deq({-1, 0, 1, 2, 3});

    //     deq.pop_back();
    //     deq.pop_front();

    //     assert(deq.size() == 3);
    //     for (int i = 0; i < deq.size(); ++i)
    //         assert(deq[i] == i);

    //     deq.clear();
    //     assert(!deq.size());
    // }

    // // {
    // //     deque<int> deq({-1, 0, 1, 2, 3});

    // //     deq.erase(deq.begin());
    // //     deq.erase(deq.end() - 1);
    // //     deq.erase(deq.end());

    // //     assert(deq.size() == 2);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == i);
    // // }

    // // {
    // //     deque<int> deq({-1, 0, 1, 2, 3});

    // //     deq.erase(deq.begin(), deq.begin() + 1);

    // //     assert(deq.size() == 3);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == i + 1);

    // //     deq.erase(deq.begin(), deq.end());
    // //     assert(deq.size() == 0);

    // //     deq.assign(10, 7);

    // //     deq.erase(deq.begin() + 2, deq.end() - 2);
    // //     assert(deq.size() == 4);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == 7);

    // //     deq.assign(10, 7);

    // //     deq.erase(deq.end() - 3, deq.end());
    // //     assert(deq.size() == 6);
    // //     for (int i = 0; i < deq.size(); ++i)
    // //         assert(deq[i] == 7);

    // //     for (int i = 0; deq.size(); ++i)
    // //         deq.removeAt(0);

    // //     assert(!deq.size());
    // // }

    // // {
    // //     deque<int> std_vec({0, 1, 2});
    // //     deque<int> deq;

    // //     assert(!deq.empty());
    // //     assert(std_vec.empty());

    // //     deq = std_vec;

    // //     assert(deq.front() == 0);
    // //     assert(deq.at(1) == 1);
    // //     assert(deq.back() == 2);
    // // }
}