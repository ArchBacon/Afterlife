#pragma once

#include <vector>

struct Vector2
{
    int x;
    int y;

    Vector2 operator -(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
};

template <class T>
class Array
{
    std::vector<T> data;

public:
    /**
     * Syntactic sugar
     */
    const std::vector<T>& iterator = data;
    
    /**
     * Adds a new item to the end of the array
     */
    void Add(T item);

    /**
     * Adds unique element to array if it doesn't exist.
     */
    void AddUnique(T item);

    /**
     * Checks if this array contains the element.
     */
    bool Contains(T item);

    /**
     * Finds element within the array.
     * 
     * Returns index of the found element. -1 otherwise.
     */
    int Find(T item);

    /**
     * Removes as many instances of [item] as there are in the array.
     */
    void Remove(T item);
};

template <class T>
void Array<T>::Add(T item)
{
    data.push_back(item);
}

template <class T>
void Array<T>::AddUnique(T item)
{
    if (!Contains(item))
    {
        Add(item);
    }
}

template <class T>
bool Array<T>::Contains(T item)
{
    return Find(item) != -1;
}

template <class T>
int Array<T>::Find(T item)
{
    auto index = std::find(data.begin(), data.end(), item);
    if (index == data.end())
    {
        return -1;
    }

    return static_cast<int>(index - data.begin());
}

template <class T>
void Array<T>::Remove(T item)
{
    const int index = Find(item);
    if (index == -1)
    {
        return;
    }

    data.erase(std::remove(data.begin(), data.end(), index), data.end());
}
