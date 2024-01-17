#ifndef KEY_VALUE_H
#define KEY_VALUE_H

struct KeyValue{
    int key;
    double value;
    KeyValue() : key{0}, value{0.0} { }
    KeyValue(int key, double value) : key{key}, value{value} { }
    bool operator==(const KeyValue& other) {
        return key == other.key;
    }
};

#endif