#include <iostream>

using namespace std;

class CQueue {
private:
  int capacity_;
  int size_;
  string* container_;
  int rear_, front_;
  void Resize();

public:
  CQueue(int val = 3);
  ~CQueue();

  void Push(const string& val);
  void Pop();

  bool IsEmpty();
  void Clear();
  int Size();
  int Capacity();
  void Print();
};

CQueue::CQueue(int val) {
  capacity_ = val;
  size_ = 0;
  rear_ = -1;
  front_ = -1;
  container_ = new string[capacity_];
}

CQueue::~CQueue() {
  delete[] container_;
  container_ = NULL;
}

void CQueue::Push(const string& val) {

  if (rear_ == -1) {
    container_[++rear_] = val;
    front_ = rear_;
    size_++;
  }

  else if ((front_ < capacity_ - 1) && (front_ + 1 != rear_)) {
    container_[++front_] = val;
    size_++;
  }

  else if (front_ == capacity_ - 1 && rear_ != 0) {
    front_ = 0;
    container_[front_] = val;
    size_++;
  }

  else {
    cout << "---------------" << endl;
    cout << "Capacity >> " << Size()*2 << endl;
    cout << "---------------" << endl;
    Resize();
    Push(val);
    return;
  }
  cout << "Pushed value > " << val << endl;
}

void CQueue::Pop() {
  if (rear_ == -1) {
    cout << "---------------" << endl;
    cout << "Queue is empty" << endl;
    cout << "---------------" << endl;
    return;
  }
  string& val = container_[rear_];
  if (rear_ == front_)
    rear_ = front_ = -1;
  else if (rear_ == capacity_ - 1)
    rear_ = 0;
  else
    rear_++;

  size_--;
  cout << "Poped value > " << val << endl;
}

void CQueue::Clear() {
  front_ = rear_ = -1;
  size_ == 0;
}

void CQueue::Resize() {
  string* arrTemp = new string[2 * capacity_];
  int j = -1;

  for (int i = rear_; i <= front_; i++) {
    arrTemp[++j] = container_[i];
  }

  if (front_ < rear_) {
    for (int i = rear_; i < capacity_; i++) {
      arrTemp[++j] = container_[i];
    }

    for (int i = 0; i <= front_; i++) {
      arrTemp[++j] = container_[i];
    }
  }
  delete[] container_;
  container_ = arrTemp;
  rear_ = 0;
  front_ = j;
  capacity_ *= 2;
}
void CQueue::Print() {
  if (rear_ == -1) {
    cout << "---------------" << endl;
    cout << "Queue is empty" << endl;
    cout << "---------------" << endl;
    return;
  }
  cout << "---------------" << endl;
  cout << "     Items     " << endl;
  for (int i = rear_; i <= front_; i++) {
    cout << container_[i] << " ";
  }
  if (front_ < rear_) {
    for (int i = rear_; i < capacity_; i++) {
      cout << container_[i] << " ";
    }
    for (int i = 0; i <= front_; i++) {
      cout << container_[i] << " ";
    }
  }
  cout << endl;
  cout << "Size > " << Size() << endl;
  cout << "Capacity > " << Capacity() << endl;
  cout << "---------------" << endl;
}
int CQueue::Size() {
  return size_;
}
int CQueue::Capacity() {
  return capacity_;
}
bool CQueue::IsEmpty() {
  return (size_ > 0) ? true : false;
}
