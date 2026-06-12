class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        int s = q.size();

        // Add new element
        q.push(x);

        // Move previous elements behind it
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};