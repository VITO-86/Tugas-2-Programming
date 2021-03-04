#include <iostream>
using namespace std;

// Fungsi penjumlahan
double penjumlahan(double x, double y){
  return x + y;
}

// Fungsi pengurangan
double pengurangan(double x, double y){
  return x - y;
}

// Fungsi perkalian
double perkalian(double x, double y){
  return x * y;
}

// Fungsi pembagian
double pembagian(double x, double y){
  return x / y;
}

// Fungsi pangkat
double perpangkatan(double x, double n){
  // Menggunakan fungsi rekursif untuk mendapatkan operasi pangkat
  if (n == 0){
    return 1;
  }
  else {
    return x*perpangkatan(x,(n-1));
  }
}

// Operasi integral didesain hanya untuk fungsi berbentuk fugsi kuadrat
double FungsiKuadrat(double a, double b, double c, double x){
  double f = (a*(x*x)) + (b*x) + c;
  return f;
}

int main() {
  cout<<"Selamat datang di Program Kalkulator\n\n";
  bool kondisi = true;
  // Menggunakan looping dan akan berhenti saat pengguna sudah selesai menggunakan kalkulator //
  while (kondisi == true){
    string masukan;
    cout<<"Silahkan pilih Operasi Matematika yang Anda inginkan\n\n";
    // Pembuatan kata kunci untuk setiap operasi matematika yang dijalankan
    cout<<"Ketik '+' untuk operasi penjumlahan\n";
    cout<<"Ketik '-' untuk operasi pengurangan\n";
    cout<<"Ketik '*' untuk operasi perkalian\n";
    cout<<"Ketik '/' untuk operasi pembagian\n";
    cout<<"Ketik '^' untuk operasi pangkat\n";
    cout<<"Ketik 'integral' untuk menghitung operasi integral tentu\n";
    // Pengguna memasukkan kata kunci operasi matematika yang akan dijalankan
    cout<<"Ketikan kata kunci: ";
    cin>>masukan;

    // Menggunakan analisis kondisi(if,else if, dan if) untuk //menjalankan operasi sesuai input pengguna
    
    // Operasi penjumlahan
    if (masukan == "+"){
      cout<<"\nSilahkan masukkan bilangan yang ingin Anda operasikan\n";
      double x,y;
      cin>>x;
      cin>>y;
      cout<<x<<" + "<<y<<" = "<<penjumlahan(x,y);
    }
    
    // Operasi pengurangan
    else if (masukan == "-"){
      cout<<"\nSilahkan masukkan bilangan yang ingin Anda operasikan\n";
      double x,y;
      cin>>x;
      cin>>y;
      cout<<x<<" - "<<y<<" = "<<pengurangan(x,y);
    }
    
    // Operasi perkalian
    else if (masukan == "*"){
      cout<<"\nSilahkan masukkan bilangan yang ingin Anda operasikan\n";
      double x,y;
      cin>>x;
      cin>>y;
      cout<<x<<" x "<<y<<" = "<<perkalian(x,y);
    }  
    
    // Operasi pembagian
    else if (masukan == "/"){
      cout<<"\nSilahkan masukkan bilangan yang ingin Anda operasikan\n";
      double x,y;
      cin>>x;
      cin>>y;
      cout<<x<<" : "<<y<<" = "<<pembagian(x,y);
    }  
    
    // Operasi perpangkatan
    else if (masukan == "^"){
      cout<<"\nSilahkan masukkan bilangan yang ingin Anda operasikan\n";
      double x,n;
      cin>>x;
      cout<<"Silahkan masukkan derajat pangkatnya\n";
      cin>>n;
      
      // jika pangkat kurang dari satu maka input invalid
      if (n <=1){
        cout<<"input salah\n";
        cout<<"Pangkat harus lebih besar dari 1\n";
      }
      // program bekerja saat pangkat lebih dari 1
      else{
        cout<<x<<" pangkat "<<n<<" = "<<perpangkatan(x,n);
      }
      
    }
    
    // Operasi integral tentu dengan metode trapesium
    else if (masukan == "integral"){
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
    else {
      cout<<"\nKalkulator tidak dapat memahami keinginan Anda\n";
      cout<<"Kata kunci yang Anda masukkan salah\n";
    }
    
  string lanjut;
  // analasis kondisi yang akan menerima input apakah pengguna akan //menggunakan kalkulator lagi
  cout<<"\nIngin menggunakan kalkulator lagi? Y/T\n";
  cin>>lanjut;
  if (lanjut == "Y" || lanjut == "y"){
    kondisi = true;
  }
  else {
    kondisi = false;
  }
}
  
// Keluar dari looping dan selesai menggunakan Kalkulator
cout <<"\nTerima kasih sudah menggunakan program kalkulator ini";

return 0;
}
