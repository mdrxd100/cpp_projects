#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using namespace std;
using namespace boost::multiprecision;

void printvector(vector<int> n); // imprime un vector
vector<int> dec2bin(cpp_int n, vector<int> &resultado); // transforma a binario
vector<int> twoscomplement(vector<int> &negative); // complemento del 2 del numero

int main() {
  vector<int> nice;
  cpp_int n;
  while (cin >> n) {
    nice.clear();
    dec2bin(n, nice);
    printvector(nice);
  }
  return 0;
}

void printvector(vector<int> n) {
  int bitcount = 0;
  for (size_t i = 0; i < n.size(); ++i) {
    cout << n[i];
    bitcount += n[i] == 1 ? 1 : 0;
  }
  cout << endl << "Bitcount: " << bitcount << endl;
}

vector<int> dec2bin(cpp_int n, vector<int> &resultado) {
  int counter = 31;
  bool isNegative = 0;
  if (n < 1) { // si es negativo, se calcula el valor absoluto
    n = -n;
    isNegative = 1;
  }
  for (int i = 0; i < 32; ++i) { // transforma el numero a binario al reves
    resultado.push_back(n % 2 == 1 ? 1 : 0);
	n /= 2;
  }
  for (int i = 0; i < 16; ++i) { // reordena el numero al reves
    swap(resultado[i], resultado[counter]);
    --counter;
  }
  return (isNegative == 1) ? twoscomplement(resultado) : resultado;
}

vector<int> twoscomplement(vector<int> &negative) {
  for (int i = 0; i < 32; ++i) { // cambia 1 por 0 y vice-versa
    negative[i] = (negative[i] == 0) ? 1 : 0;
  }
  for (int i = 31; i >= 0; --i) { // suma 1 al numero
    if (negative[i] != 0) {
      negative[i] = 0;
    } else {
      negative[i] = 1;
      break;
    }
  }
  return negative;
}
