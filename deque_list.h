#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

constexpr size_t arr_size = 1000000;
size_t loc_size = 100;

template <typename T>
class deque
{
    using matrix = std::vector<std::vector<T>>;

public:
    // struct iterator
    // {
    // public:
    //     node *curr_iter;
    //     int pos;

    //     iterator()
    //     {
    //         curr_iter = nullptr;
    //         pos = 0;
    //     }
    //     // iterator(iterator src_iter)
    //     // {
    //     //     curr_iter = src_iter->curr_iter;
    //     //     pos = src_iter->pos;
    //     // }
    //     ~iterator()
    //     {
    //         curr_iter = nullptr;
    //         pos = 0;
    //     }
    //     T &operator*()
    //     {
    //         return curr_iter->data[pos];
    //     }
    //     bool operator!=(iterator src_iter)
    //     {
    //         return src_iter.curr_iter != curr_iter || pos != src_iter.pos;
    //     }

    //     iterator operator+(int count)
    //     {
    //         for (int i = 0; i < count; ++i)
    //         {
    //             if (pos == arr_size)
    //             {
    //                 curr_iter = curr_iter->pointer_next;
    //                 pos = 0;
    //             }
    //             else
    //                 ++pos;
    //         }
    //         return *this;
    //     }

    //     iterator &operator++()
    //     {
    //         if (pos == arr_size)
    //         {
    //             curr_iter = curr_iter->pointer_next;
    //             pos = 0;
    //         }
    //         else
    //             ++pos;
    //         return *this;
    //     }

    //     iterator operator++(int)
    //     {
    //         iterator it = *this;
    //         ++*this;
    //         return it;
    //     }

    //     iterator &operator--()
    //     {
    //         --pos;
    //         if (pos == -1)
    //         {
    //             curr_iter = curr_iter->pointer_prev;
    //             pos = arr_size - 1;
    //         }
    //         return *this;
    //     }

    //     iterator operator--(int)
    //     {
    //         iterator it = *this;
    //         --*this;
    //         return it;
    //     }
    // };

    deque();
    deque(size_t size);
    deque(size_t size, T data);
    // deque(std::vector<T> const &data);
    // ~deque();

    void push_back(T data);
    // void push_back(std::vector<T> const &data);
    void push_front(T data);
    // void push_front(std::vector<T> const &data);

    // void insert(T data, int pos);
    // void insert(T data, iterator pos);
    // void insert(T data, int pos, int count);
    // void insert(T data, iterator pos, int count);
    // void insert(std::vector<T> const &data, int pos);
    // void insert(std::vector<T> const &data, iterator pos);
    // void insert(iterator pos, iterator secfpos, iterator seclpos);

    // // iterator emplace(iterator pos, T data);
    // // iterator emplace_back(T data);
    // // iterator emplace_front(T data);

    // void clear();
    // void pop_back();
    // void pop_front();

    // iterator begin();
    // iterator end();

    // size_t size() { return Size; }
    T &operator[](size_t ind);

private:
    matrix buffer;
    size_t pos_begin;
    size_t pos_end;
    size_t pos_buff_begin;
    size_t pos_buff_end;
    size_t _size;
};

template <typename T>
deque<T>::deque()
{
    buffer.resize(loc_size, std::vector<T>(arr_size));
    pos_buff_begin = loc_size / 2;
    pos_buff_end = loc_size / 2;
    pos_begin = 0;
    pos_end = 0;
    _size = 0;
}

template <typename T>
deque<T>::deque(size_t size)
{
    buffer.resize(loc_size, std::vector<T>(arr_size));
    pos_buff_begin = loc_size / 2;
    pos_buff_end = loc_size / 2;
    pos_begin = 0;
    _size = size;
    pos_end = 0;

    for (int i = 0; i < size; ++i)
    {
        if (pos_end == arr_size)
        {
            if (pos_buff_end == loc_size - 1)
            {
                loc_size *= 2;
                matrix new_buffer(loc_size, std::vector<T>(arr_size));

                for (int j = 0; j < loc_size / 2 - pos_buff_begin; ++j)
                    new_buffer[loc_size / 4 + j] = buffer[j + pos_buff_begin];

                pos_buff_end = loc_size / 4 + (loc_size / 2 - pos_buff_begin) - 1;
                pos_buff_begin = loc_size / 4;
                buffer = new_buffer;
            }
            pos_end = 0;
            ++pos_buff_end;
        }
        buffer[pos_buff_end][pos_end] = {};
        ++pos_end;
    }
}

template <typename T>
deque<T>::deque(size_t size, T data)
{
    buffer.resize(loc_size, std::vector<T>(arr_size));
    pos_buff_begin = loc_size / 2;
    pos_buff_end = loc_size / 2;
    pos_begin = 0;
    _size = size;
    pos_end = 0;

    for (int i = 0; i < size; ++i)
    {
        if (pos_end == arr_size)
        {
            if (pos_buff_end == loc_size - 1)
            {
                loc_size *= 2;
                matrix new_buffer(loc_size, std::vector<T>(arr_size));

                for (int j = 0; j < loc_size / 2 - pos_buff_begin; ++j)
                    new_buffer[loc_size / 4 + j] = buffer[j + pos_buff_begin];

                pos_buff_end = loc_size / 4 + (loc_size / 2 - pos_buff_begin) - 1;
                pos_buff_begin = loc_size / 4;
                buffer = new_buffer;
            }
            pos_end = 0;
            ++pos_buff_end;
        }
        buffer[pos_buff_end][pos_end] = data;
        ++pos_end;
    }
}

template <typename T>
void deque<T>::push_back(T data)
{
    if (pos_end == arr_size)
    {
        if (pos_buff_end == loc_size - 1)
        {
            loc_size *= 2;
            matrix new_buffer(loc_size, std::vector<T>(arr_size));

            for (int j = 0; j < loc_size / 2 - pos_buff_begin; ++j)
                new_buffer[loc_size / 4 + j] = buffer[j + pos_buff_begin];

            pos_buff_end = loc_size / 4 + (loc_size / 2 - pos_buff_begin) - 1;
            pos_buff_begin = loc_size / 4;
            buffer = new_buffer;
        }
        pos_end = 0;
        ++pos_buff_end;
    }
    buffer[pos_buff_end][pos_end] = data;
    ++pos_end;
    ++_size;
}

template <typename T>
void deque<T>::push_front(T data)
{
    if (pos_begin == 0)
    {
        if (_size != 0)
        {
            if (pos_buff_begin == 0)
            {
                loc_size *= 2;
                matrix new_buffer(loc_size, std::vector<T>(arr_size));

                for (int j = 0; j < loc_size / 2 - pos_buff_begin; ++j)
                    new_buffer[loc_size / 4 + j] = buffer[j + pos_buff_begin];

                pos_buff_end = loc_size / 4 + (loc_size / 2 - pos_buff_begin) - 1;
                pos_buff_begin = loc_size / 4;
                buffer = new_buffer;
            }
            pos_begin = arr_size;
            --pos_buff_begin;
        }
        else
        {
            pos_begin = 1;
            ++pos_end;
        }
    }
    --pos_begin;
    buffer[pos_buff_begin][pos_begin] = data;
    ++_size;
}

template <typename T>
T &deque<T>::operator[](size_t ind)
{
    if (ind < arr_size)
        return buffer[pos_buff_begin][ind + pos_begin];
    return buffer[pos_buff_begin + ind / arr_size][ind % arr_size];
    // T *pos = data.front();
    // if (ind == 0)
    //     return *pos;
    // else
    // {
    //     typename std::list<T *>::iterator it = data.begin();

    //     for (int i = 0; i < (ind + Begin) / arr_size; ++i)
    //         ++it;

    //     pos = *it;
    //     pos += (ind + Begin) % arr_size;
    //     return *pos;
    // }
}

// template <typename T>
// deque<T>::deque(std::vector<T> const &data)
// {
//     Begin = new node;
//     reserve_(Begin);
//     Begin->pointer_prev = Begin;
//     Begin->pointer_next = nullptr;
//     Begin->node_size = 0;
//     End = Begin;
//     Size = 0;
//     i_begin = 0;
//     for (int i = 0; i < data.size(); ++i)
//         push_back(data[i]);
// }

// template <typename T>
// deque<T>::~deque()
// {
//     clear();
// }

// template <typename T>
// void deque<T>::push_back(std::vector<T> const &data)
// {
//     for (int i = 0; i < data.size(); ++i)
//         push_back(data[i]);
// }

// template <typename T>
// void deque<T>::push_front(std::vector<T> const &data)
// {
//     for (int i = data.size() - 1; i >= 0; --i)
//         push_front(data[i]);
// }

// template <typename T>
// void deque<T>::insert(T data, int pos)
// {
//     if (pos == Size)
//         push_back(data);
//     else if (!pos)
//         push_front(data);
//     else
//     {
//         push_back({});
//         node *temp = Begin, *temp_rep = End;
//         int cncrt_pos = (pos + i_begin) % arr_size, rep_pos = End->node_size - 1;

//         for (int i = 0; i < (pos + i_begin) / arr_size; ++i)
//             temp = temp->pointer_next;

//         for (; temp_rep != temp || rep_pos > cncrt_pos; --rep_pos)
//         {
//             if (!rep_pos)
//             {
//                 temp_rep->data[rep_pos] = temp_rep->pointer_prev->data[temp_rep->pointer_prev->node_size - 1];
//                 temp_rep = temp_rep->pointer_prev;
//                 rep_pos = temp_rep->node_size - 1;
//             }
//             temp_rep->data[rep_pos] = temp_rep->data[rep_pos - 1];
//         }
//         temp->data[cncrt_pos] = data;
//     }
// }

// template <typename T>
// void deque<T>::insert(T data, int pos, int count)
// {
//     if (!pos)
//         for (int i = 0; i < count; ++i)
//             push_front(data);
//     else if (pos == Size)
//         for (int i = 0; i < count; ++i)
//             push_back(data);
//     else
//     {
//         for (int i = 0; i < count; ++i)
//             insert(data, pos);
//     }
// }

// template <typename T>
// void deque<T>::insert(std::vector<T> const &data, int pos)
// {
//     if (pos == Size)
//         push_back(data);
//     else if (!pos)
//         push_front(data);
//     else
//     {
//         for (int i = data.size() - 1; i >= 0; --i)
//             insert(data[i], pos);
//     }
// }

// template <typename T>
// void deque<T>::insert(T data, iterator pos)
// {
//     if (pos.curr_iter == Begin && pos.pos == i_begin)
//         push_front(data);
//     else if (pos.curr_iter == End && pos.pos == End->node_size || pos.curr_iter == nullptr)
//         push_back(data);
//     else
//     {
//         iterator temp;
//         temp.curr_iter = Begin;
//         temp.pos = i_begin;
//         int i_pos = 0;

//         for (; temp != pos; ++i_pos)
//         {
//             if (temp.pos == arr_size)
//                 ++temp;
//             else
//                 ++temp.pos;
//         }
//         insert(data, i_pos);
//     }
// }

// template <typename T>
// void deque<T>::insert(T data, iterator pos, int count)
// {
//     if (pos.curr_iter == Begin && pos.pos == i_begin)
//         for (int i = 0; i < count; ++i)
//             push_front(data);
//     else if (pos.curr_iter == End && pos.pos == End->node_size || pos.curr_iter == nullptr)
//         for (int i = 0; i < count; ++i)
//             push_back(data);
//     else
//     {
//         iterator temp;
//         temp.curr_iter = Begin;
//         temp.pos = i_begin;
//         int i_pos = 0;

//         for (; temp != pos; ++i_pos)
//         {
//             if (temp.pos == arr_size)
//                 ++temp;
//             else
//                 ++temp.pos;
//         }

//         for (int i = 0; i < count; ++i)
//             insert(data, i_pos);
//     }
// }

// template <typename T>
// void deque<T>::insert(std::vector<T> const &data, iterator pos)
// {
//     if (pos.curr_iter == Begin && pos.pos == i_begin)
//         push_front(data);
//     else if (pos.curr_iter == End && pos.pos == End->node_size || pos.curr_iter == nullptr)
//         push_back(data);
//     else
//     {
//         iterator temp;
//         temp.curr_iter = Begin;
//         temp.pos = i_begin;
//         int i_pos = 0;

//         for (; temp != pos; ++i_pos)
//         {
//             if (temp.pos == arr_size)
//                 ++temp;
//             else
//                 ++temp.pos;
//         }

//         for (int i = data.size() - 1; i >= 0; --i)
//             insert(data[i], i_pos);
//     }
// }

// template <typename T>
// void deque<T>::insert(iterator pos, iterator secfpos, iterator seclpos)
// {
//     if (pos.curr_iter == Begin && pos.pos == i_begin)
//     {
//         for (; seclpos != secfpos; --seclpos)
//             push_front(*seclpos);
//         push_front(*seclpos);
//     }
//     else if (pos.curr_iter == End && pos.pos == End->node_size || pos.curr_iter == nullptr)
//     {
//         while (secfpos != seclpos)
//         {
//             push_back(*secfpos);
//             ++secfpos;
//         }
//         push_back(*secfpos);
//     }
//     else
//     {
//         iterator temp;
//         temp.curr_iter = Begin;
//         temp.pos = i_begin;
//         int i_pos = 0;

//         for (; temp != pos; ++i_pos)
//         {
//             if (temp.pos == arr_size)
//                 ++temp;
//             else
//                 ++temp.pos;
//         }

//         for (; secfpos != seclpos; ++i_pos, ++secfpos)
//             insert(*secfpos, i_pos);
//         insert(*secfpos, i_pos);
//     }
// }

// template <typename T>
// void deque<T>::pop_back()
// {
//     if (Size)
//     {
//         if (!End->node_size)
//         {
//             End = End->pointer_prev;
//             delete End->pointer_next;
//             End->pointer_next = nullptr;
//         }
//         else
//         {
//             --End->node_size;
//         }
//         --Size;
//     }
// }

// template <typename T>
// void deque<T>::pop_front()
// {
//     if (Size)
//     {
//         if (i_begin == arr_size - 1)
//         {
//             Begin = Begin->pointer_next;
//             delete Begin->pointer_prev;
//             Begin->pointer_prev = Begin;
//             i_begin = 0;
//         }
//         else
//         {
//             ++i_begin;
//         }
//         --Size;
//     }
// }

// template <typename T>
// void deque<T>::clear()
// {
//     while (Size)
//         pop_back();
// }

// template <typename T>
// typename deque<T>::iterator deque<T>::begin()
// {
//     iterator it;
//     it.curr_iter = Begin;
//     it.pos = i_begin;
//     return it;
// }

// template <typename T>
// typename deque<T>::iterator deque<T>::end()
// {
//     iterator it;
//     it.curr_iter = End;
//     it.pos = End->node_size - 1;
//     return it;
// }
