#pragma once

#include <utility>
#include <deque>

template <typename T>
class max_queue {
    public:
        std::deque<std::pair<T, int>> __dq;
        unsigned __size;
        unsigned size() {
            return __size;
        }
        bool empty() {
            return __dq.empty();
        }
        void push_back(T elem) {
            int cnt = 0;
            while(!__dq.empty() && __dq.back().first <= elem) {
                cnt = cnt + __dq.back().second + 1;
                __dq.pop_back();
            }
            __dq.push_back({ elem, cnt });
            __size++;
        }
        void pop_front() {
            if(__dq.front().second == 0) {
                __dq.pop_front();
            }
            else {
                __dq.front().second--;
            }
            __size--;
        }
        T& max() {
            return __dq.front().first;
        }
};