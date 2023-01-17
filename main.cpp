// rsig CMake test
// Copyright 2022 Sean Farrell <sean.farrell@rioki.org>
//
// This program is free software. It comes without any warranty, to
// the extent permitted by applicable law. You can redistribute it
// and/or modify it under the terms of the Do What The Fuck You Want
// To Public License, Version 2, as published by Sam Hocevar. See
// LICENSE.txt for more details.

#include <iostream>
#include <c9y/coroutine.h>

std::future<int> compute_async() {
    using namespace c9y::co_async;
    int a = co_await c9y::async<int>([] { return 6; });
    int b = co_await c9y::async<int>([] { return 7; });
    co_return a * b;
}

std::future<int> compute_sync() {
    using namespace c9y::co_sync;
    int a = co_await c9y::async<int>([] { return 6; });
    int b = co_await c9y::async<int>([] { return 7; });
    co_return a * b;
}

int main(int argc, char* argv[])
{
    using namespace std::chrono_literals;

    auto f = compute_sync();

    while (f.wait_for(0s) == std::future_status::timeout)
    {
        c9y::sync_point();
    }

    std::cout << "Result:" << f.get() << std::endl;
    return 0;
}