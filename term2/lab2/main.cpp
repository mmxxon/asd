#include "queue.h"

int main() {
  string V;
  int val;
  cout << "Size of queue > ";
  cin >> V;
  if (isdigit(V[0]))
    val = stoi(V);
  else
    exit(1);
  if (val < 0) {
    cout << "Wrong size" <<endl;
    exit(1);
  }
  CQueue q(val);
  cout << "input to push" <<endl;
  cout << "<out> to pop" <<endl;
  cout << "<quit> to exit" <<endl;
  cout << "<show> to print on screen" <<endl;
  do {
    cout << "> ";
    cin >> V;
    if (V == "show")
    {
      q.Print();
    } else if (V == "out")
    {
      q.Pop();
    } else if (V == "quit")
    {
      system("clear");
      exit(0);
    } else {
      q.Push(V);
    }
  } while (true);
  
}