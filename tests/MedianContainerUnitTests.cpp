#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <chrono>
#include "MedianContainer.h"

TEST_CASE("Insertion and Median Calculation") {
    SECTION("Empty Container") {
        MedianContainer<int> container;
        REQUIRE(container.Empty());
        REQUIRE_THROWS(container.GetMedian());
    }

    SECTION("Insertion and Median Calculation - Integer Values") {
        MedianContainer<int> container;

        container.Insert(10);
        container.Insert(2);
        container.Insert(7);
        container.Insert(1);
        container.Insert(11);

        REQUIRE(container.GetMedian() == 7.0);
    }

    SECTION("Insertion and Median Calculation - Floating-Point Values") {
        MedianContainer<double> container;

        container.Insert(3.5);
        container.Insert(1.5);
        container.Insert(4.0);
        container.Insert(2.0);

        REQUIRE(container.GetMedian() == Catch::Approx(2.75));
    }

    SECTION("Median Calculation After Inserting Duplicates") {
        MedianContainer<int> container;

        container.Insert(10);
        container.Insert(5);
        container.Insert(10);
        container.Insert(15);

        REQUIRE(container.GetMedian() == 10.0);
    }

    SECTION("Inserting Large Number of Elements") {
        MedianContainer<int> container;

        for (int i = 1; i <= 1000; ++i) {
            container.Insert(i);
        }

        REQUIRE(container.GetMedian() == 500.5);
    }

    SECTION("Inserting Extreme Values") {
        MedianContainer<int> container;

        container.Insert(INT_MIN);
        container.Insert(0);
        container.Insert(INT_MAX);

        REQUIRE(container.GetMedian() == 0.0);
    }
}

TEST_CASE("Median Container Benchmarks", "[benchmark]") {
    BENCHMARK("Insertion and Median Calculation") {
        MedianContainer<int> container;
        for (int i = 1; i <= 1000; ++i) {
            container.Insert(i);
            container.GetMedian();
        }
    };
    BENCHMARK("Insertion and Single Median Calculation") {

        MedianContainer<int> container;
        for (int i = 1; i <= 1000; ++i) {
            container.Insert(i);
        }
        container.GetMedian();
    };
}