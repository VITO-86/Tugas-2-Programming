#include <iostream>

using namespace std;

// Operasi integral didesain hanya untuk fungsi berbentuk fugsi kuadrat
double FungsiKuadrat(double a, double b, double c, double x){
  double f = (a*(x*x)) + (b*x) + c;
  return f;
}

int main() {
  cout<<"\nKalkulator hanya dapat menghitung integral tentu dari fungsi kuadrat\n";
  cout<<"Format Fungsi Kuadrat = A*x^2 + B*x + C\n";
  // Input variabel A, B, dan C
  
  double A,B,C;
  cout<<"Masukkan nilai A: \n";
  cin>>A;
  cout<<"Masukkan nilai B: \n";
  cin>>B;
  cout<<"Masukkan nilai C: \n";
  cin>>C;
  
  int n;
  double a,b;
  // Batas atas
  cout<<"Masukkan batas atas: \n";
  cin>>a;
  // Batas bawah
  cout<<"Masukkan batas bawah: \n";
  cin>>b;
  // jumlah segmen
  cout<<"masukkan jumlah segmen N: \n";
  cin>>n;
  
  double h = (a - b)/n;
  double x[n], y[n];
  double sum = FungsiKuadrat(A,B,C,a) + FungsiKuadrat(A,B,C,b) ;
  
  for (int i=1;i<=n-1;i++)            
    {                    
      x[i]=b+i*h;            
      sum = sum + (2 * FungsiKuadrat(A,B,C,x[i]));
    }
  
  double integral=(h/2)*(sum);        
  cout<<"Hasil dari Integral tentunya adalah "<<integral<<endl;
}
