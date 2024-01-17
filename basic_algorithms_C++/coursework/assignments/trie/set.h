#ifndef SET_H
#define SET_H

template<typename T>
struct Set
{
    virtual ~Set() { };
    virtual bool add(const T&) = 0;
    virtual bool contains(const T&) const = 0;
    virtual bool remove(const T &) = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};

#endif /* SET_H */
