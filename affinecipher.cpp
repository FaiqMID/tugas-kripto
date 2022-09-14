/*
  140810200011 Faiq Muhammad
  140810200017 M. Keenan Febriansyah
  140810200021 Rifqi Akmal Fauzi
  140810200029 Adnan Rafiyansyah Majid
  140810200031 Ahmad Yahya Salim

  --- Affine Cipher ---
*/

#include <iostream>
using namespace std;

string enkripsi(string plain_text, int a, int b){
	string cipher_text = "";	
	for(int i = 0; i < plain_text.size(); i++){
		if(isupper(plain_text[i])){
			cipher_text += char((a * int(plain_text[i] - 65) + b) % 26 + 65); //65 = A-Z
		} else {
			cipher_text += char((a * int(plain_text[i] - 97) + b) % 26 + 97); //97 = a-z
		}
	}
	return cipher_text;
}

int inverseMod26(int x){
  int mod = 26;
  for (int i = 0; i < mod; i++)
  {
    if (((x % mod) * (i % mod)) % mod == 1)
    {
      return i;
    }   
  }  
}

string dekripsi(string cipher_text, int a, int b){
	string plain_text="";	
  int a_inv = inverseMod26(a);
	for(int i = 0; i < cipher_text.size(); i++){
		if(isupper(cipher_text[i])){
			plain_text += char(((a_inv * (int(cipher_text[i] - 65) - b)) % 26 + 26) % 26 + 65);
		} else {
			plain_text+=  char(((a_inv * (int(cipher_text[i] - 97) - b)) % 26 + 26) % 26 + 97);
		}
	}
	return plain_text;
}
int main(){
	string plain_text;
  int a, b;

	cout << "Masukkan plain text: ";
	cin >> plain_text;
	
	cout << "Masukkan a: ";
	cin >> a;

  cout << "Masukkan b: ";
	cin >> b;

	string cipher_text = enkripsi(plain_text, a, b);
	
	cout << "\nEnkripsi: \n";
	cout << "Cipher text: " << cipher_text << endl;
	
	cout << "\nDekripsi:\n";
	cout << "Plain Text: "<< dekripsi(cipher_text, a, b) << endl;
}