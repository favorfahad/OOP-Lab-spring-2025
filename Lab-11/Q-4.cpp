#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    DatabaseConnector() {}

    void connect(const T& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw DatabaseException();
        }
        cout << "Connected to " << dbName << " successfully." << endl;
    }

    void executeQuery(const T& query) {
        if (query == "timeout_query") {
            throw QueryTimeoutException();
        }
        cout << "Executed query: " << query << endl;
    }
};

int main() {
    DatabaseConnector<string> connector;

    try {
        connector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        connector.connect("slow_db");
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    try {
        connector.executeQuery("timeout_query");
    } catch (const QueryTimeoutException& e) {
        cout << "Caught QueryTimeoutException - what(): " << e.what() << endl;
    }

    return 0;
}
