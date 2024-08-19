#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// - count char using slow repeated string::find_first_of
int count_char_using_find_first_of(string s, char delim)
{
    int count = 0;
    // note: string::size_type pos = s.find_first_of(delim);
    auto pos = s.find_first_of(delim);
    while ((pos = s.find_first_of(delim, pos)) != string::npos)
    {
        count++;
        pos++;
    }
    return count;
}

// - count char using fast std::count
int count_char_using_count(string s, char delim)
{
    return count(s.begin(), s.end(), delim);
}

void exponential_rampup_test()
{

    cout << " << Exponential Ramp-up Test >> " << endl;
    int total;
    // ull (suffix) == "unsigned long long" in c
    for (auto size = 1ull; size < 100000ull; size *= 10)
    {
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / size << "s/int" << endl;

        // TIP: time in nanoseconds? Cast result of chrono::duration.count() ...
        // auto _dur = duration_cast<nanoseconds>( end - start ).count();
        // cout << _dur << endl;
    }
    cout << "done." << endl;
}

void linear_rampup_test()
{
    cout << " << Linear Ramp-up Test >> " << endl;
    int total;
    for (auto size = 1; size <= 5; size += 1)
    {
        int vec_size = size * 10000;
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(vec_size, 42);
        // std::accumulate (from <numeric>) collects from begin, to end
        // - in this case (default) it is the sum total of all the values in v
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << vec_size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / vec_size << "s/int" << endl;
    }
    cout << "done." << endl;
}

void linear_rampdown_test()
{
    cout << " << Linear Ramp-Down Test >> " << endl;
    int total;
    for (auto size = 10; size >= 1; size -= 1)
    {
        int vec_size = size * 10000;
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(vec_size, 42);
        // std::accumulate (from <numeric>) collects from begin, to end
        // - in this case (default) it is the sum total of all the values in v
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << vec_size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / vec_size << "s/int" << endl;
    }
    cout << "done." << endl;
}

void exponential_rampdown_test()
{
    cout << " << Exponential Ramp-Down Test >> " << endl;
    int total;
    for (auto size = 10000ull; size >= 1ull; size /= 10)
    {
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / size << "s/int" << endl;
    }
    cout << "done." << endl;
}

int main()
{
    // linear_rampdown_test();
    // linear_rampup_test();
    // exponential_rampdown_test();
    // exponential_rampup_test();
    //  Compare the two different methods of counting in a string
    //  - show result in nanoseconds?

    string s1 = "The debugger will load only a .pdb file for an executable file that exactly matches the .pdb file that was created when the executable was built (that is, the .pdb must be the original or a copy of the original .pdb file). For more information, see Why does Visual Studio require debugger symbol files to exactly match the binary files that they were built with?.The debugger will load only a .pdb file for an executable file that exactly matches the .pdb file that was created when the executable was built (that is, the .pdb must be the original or a copy of the original .pdb file). For more information, see Why does Visual Studio require debugger symbol files to exactly match the binary files that they were built with?.";
    int result;
    // get start time
    auto start = steady_clock::now();
    result = count_char_using_find_first_of(s1, 's');
    cout << "result: " << result << endl;
    // show duration time
    auto end = steady_clock::now();
    duration<double> diff = end - start;
    cout << "Time (find-first-of): " << diff.count() << " s" << endl;

    // get start time
    auto start2 = steady_clock::now();
    result = count_char_using_count(s1, 's');
    cout << "result: " << result << endl;
    // show duration time
    auto end2 = steady_clock::now();
    duration<double> diff2 = end2 - start2;
    cout << "Time (count): " << diff2.count() << " s" << endl;
}
