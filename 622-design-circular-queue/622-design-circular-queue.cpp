class MyCircularQueue {
public:
    vector<int> a;
    int n;
    MyCircularQueue(int k) {
        n=k;
    }
    
    bool enQueue(int value) {
        if(a.size()<n)
        {
            a.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!(a.empty()))
        {
            a.erase(a.begin());
            return true;
        }
        return false;
    }
    
    int Front() {
       if(!(a.empty()))
           return a[0];
        else
            return -1;
    }
    
    int Rear() {
         if(!(a.empty()))
           return a[a.size()-1];
        else
            return -1;
    }
    
    bool isEmpty() {
        return a.empty();
    }
    
    bool isFull() {
        return (a.size()==n);
            
    }
};