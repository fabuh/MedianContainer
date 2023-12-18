#include <set>

template <typename T>
class MedianContainer {
public:
    // Function to insert an element
    void Insert(const T& value) {
        elements.insert(value);
    }

    // Function to calculate the median
    double GetMedian() const {
        size_t size = elements.size();
        auto it = elements.begin();

        std::advance(it, size / 2);

        if (size % 2 != 0) {
            return *it;
        }
        else {
            auto it2 = it;
            --it2;
            return static_cast<double>(*it + *it2) / 2.0;
        }
    }

private:
    std::multiset<T> elements;
};