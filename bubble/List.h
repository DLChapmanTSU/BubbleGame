#pragma once
#include <list>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <functional>

template <typename T>
class List{
private:
    std::list<T> m_list;
    std::mutex m_mutex;
public:
    void ForEach(std::function<void(T)> f){
        std::unique_lock<std::mutex> lock(m_mutex);
        std::for_each(m_list.begin(), m_list.end(), f);
    };

    void Push(const T& i){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_list.push_back(i);
    }

    List() = default;
    List(const List&) = delete;
    List operator=(const List&) = delete;
};