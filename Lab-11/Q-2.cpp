#include "iostream"
#include "exception"
using namespace std;

class QueueOverflowException : public exception {
    private:
    string text;
    public:
    QueueOverflowException(const string &text) : text(text) {}
    void Error() {
        cout << text << endl;
    }
};

class QueueUnderflowException : public exception {
    private:
    string text;
    public:
    QueueUnderflowException(const string &text) : text(text) {}
    void Error() {
        cout << text << endl;
    }
};


template<typename T>
class Queue {
    T data[50]; //fixing the capacity of the queue to 50.
    int count;
    public:
    Queue() : count(0) {}

    void Enque(int values[], int size) {
        try {
            if (count > 4) {throw QueueOverflowException("Caught QueueOverflowException");}
            for(int i=count,j=0;i<size;i++,j++) {
                data[i] = values[j];
                count++;
            }
            if (count > 4) {throw QueueOverflowException("Caught QueueOverflowException");}
        }
        catch (QueueOverflowException &E) {
                E.Error();
        }
    }

    void Deque() {
        try {
            if (count < 0) throw QueueUnderflowException("Caught QueueUnderflowException");
            for (int i = 0; i < count - 1; i++)
                {
                    data[i] = data[i + 1];
                }
                count--;
        }
        catch (QueueUnderflowException &E) {
                E.Error();
        }
    }
};

int main() {
    Queue<int> Queue;
    int arr[] = {1, 2, 3, 4, 5};
    Queue.Enque(arr, 5);
    for (int i=0;i<7;i++) {
    Queue.Deque(); }
    return 0;
}
