#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class OddEvenPrinter {
public:
    OddEvenPrinter(int max) : max_number(max), current_number(1) {}

    void printOdd() {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 1; i <= max_number; i += 2) {
            cv.wait(lock, [this] { return current_number % 2 != 0; });
            std::cout << "Odd: " << current_number << std::endl;
            current_number++;
            cv.notify_all();
        }
    }

    void printEven() {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 2; i <= max_number; i += 2) {
            cv.wait(lock, [this] { return current_number % 2 == 0; });
            std::cout << "Even: " << current_number << std::endl;
            current_number++;
            cv.notify_all();
        }
    }

private:
    int max_number;
    int current_number;
    std::mutex mtx;
    std::condition_variable cv;
};

int main() {
    int max_number = 10;
    OddEvenPrinter printer(max_number);

    std::thread t1(&OddEvenPrinter::printOdd, &printer);
    std::thread t2(&OddEvenPrinter::printEven, &printer);

    t1.join();
    t2.join();
    
	system("pause");
    return 0;
}
