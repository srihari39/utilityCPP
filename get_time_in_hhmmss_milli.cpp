// useful libraries
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

// utility function which gives time in HH:MM:SS.milliseconds
std::string time_in_HH_MM_SS_milli() {
    using namespace std::chrono;
    // get current time
    std::chrono::_V2::system_clock::time_point now = system_clock::now();
    // get number of milliseconds for the current second
    // (remainder after division into seconds)
    std::chrono::duration<int64_t, std::milli> ms = duration_cast<milliseconds>(now.time_since_epoch())%1000;
    // convert to std::time_t in order to convert to std::tm (broken time)
    time_t timer_ = system_clock::to_time_t(now);
    // convert to broken time
    std::tm bt = *std::localtime(&timer_);
	// format the string using stringstream
    std::ostringstream oss;
    oss << std::put_time(&bt, "%H:%M:%S"); // HH:MM:SS
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

int main(){
	// get present time now
	std::cout << time_in_HH_MM_SS_milli() << std::endl;
}