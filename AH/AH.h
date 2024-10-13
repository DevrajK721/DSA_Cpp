#ifndef AH_H
#define AH_H

#include <iostream>
#include <vector>
#include <list>
#include <functional>  // Include this header for std::hash

class MyHashSet {
public:
    // Constructor to initialize hash set with a given size
    MyHashSet(int size = 10) : size(size), buckets(size) {}

    // Function to add a key to the hash set
    void add(int key) {
        int index = myhash(key);
        // If key is not already present in the bucket, add it
        if (!has(key)) {
            buckets[index].push_back(key);
        } else {
            std::cout << key << " already exists in the hash set" << std::endl;
        }
    }

    // Function to check if a key exists in the hash set
    bool has(int key) {
        int index = myhash(key);
        // Check if the key exists in the corresponding bucket
        for (auto it : buckets[index]) {
            if (it == key) return true;
        }
        return false;
    }

    // Function to remove a key from the hash set
    void remove(int key) {
        int index = myhash(key);
        buckets[index].remove(key); // Removes the key if found
    }

    // Function to print the hash set
    void print() const {
        for (const auto& bucket : buckets) {
            if (!bucket.empty()) {
                for (const auto& key : bucket) {
                    std::cout << key << " ";
                }
                std::cout << std::endl;
            }
        }
    }

private:
    int size;  // Size of the hash set
    std::vector<std::list<int>> buckets;  // Buckets to store elements

    // Hash function to map a key to a bucket index
    int myhash(int key) const {
        return std::hash<int>{}(key) % size;
    }
};

// MyDict class
class MyDict {
public:
    MyDict(int size = 10) : size(size), buckets(size) {}

    void assign(int key, int value) {
        int index = myhash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        buckets[index].emplace_back(key, value);
    }

    int get(int key, int defaultValue = 0) {
        int index = myhash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) return pair.second;
        }
        assign(key, defaultValue);
        return defaultValue;
    }

    void remove(int key) {
        int index = myhash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
        std::cout << key << " not found in the dictionary" << std::endl;
    }

    void print() const {
        for (const auto& bucket : buckets) {
            for (const auto& pair : bucket) {
                std::cout << "{" << pair.first << ", " << pair.second << "} ";
            }
            if (!bucket.empty()) std::cout << std::endl;
        }
    }

private:
    int size;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int myhash(int key) const {
        return std::hash<int>{}(key) % size;
    }
};

#endif // AH_H AH_H
