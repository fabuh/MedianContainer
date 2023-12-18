#include "MedianContainer.h"

int main() {
    MedianContainer<int> container;

    container.Insert(10);
    container.Insert(4);
    container.Insert(7);
    container.Insert(3);
    container.Insert(12);

    container.GetMedian();

    return 0;
}