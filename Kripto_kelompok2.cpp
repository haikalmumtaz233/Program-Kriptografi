// KELOMPOK 2
// Adrian Hedrin Montilalu - 123210037
// Muhammad Raditya Haikal Mumtaz - 123210062
// Frederick Roberto Wifani - 123210190
// PROGRAM KRIPTOGRAFI
#include <bits/stdc++.h>
#include <string.h>
#include <iomanip>
using namespace std;

string caesar_proses(string text, int key);
void caesar();

string railfence_enkripsi(string text, int key);
string railfence_dekripsi(string text, int key);
void railfence();

string vigenere_kunci(string text, int key);
string vigenere_enkripsi(string text, int key);
string vigenere_dekripsi(string text, int key);
void vigenere();

void super_enkripsi();
void super_dekripsi();

int main(){
    int pilih;
	char loop;
	do {
        system("cls");
		cout << setfill('=')
             << setw(51)
             << "="
             << endl;
        cout << "| "
             << setfill(' ')
             << setw(47)
             << ' '
             << " |"
             << endl;
        cout << "| "
             << "    PROGRAM ALGORITMA ENKRIPSI DAN DEKRIPSI     |" << endl;
        cout << "| "
             << setfill(' ')
             << setw(47)
             << ' '
             << " |"
             << endl;
        cout << setfill('=')
             << setw(51)
             << "="
             << endl
             << endl;

		cout << "[MENU]" << endl;
		cout << "[1] Caesar Cipher" << endl;
		cout << "[2] Rail Fence Cipher" << endl;
		cout << "[3] Vigenere Cipher" << endl;
		cout << "[4] Super Enkripsi (Gabungan)" << endl;
		cout << "[5] Super Dekripsi (Gabungan)" << endl;
		cout << "[0] Keluar" << endl;
		cout << "Pilih: "; 
        cin >> pilih;
		cout << endl;

		switch(pilih){
			case 1:
                system("cls");
				caesar();
				break;

			case 2:
                system("cls");
				railfence();
				break;

			case 3:
                system("cls");
				vigenere();
				break;

			case 4:
                system("cls");
				super_enkripsi();
				break;

			case 5:
                system("cls");
			    super_dekripsi();
				break;

            case 0:
                exit(0);
                break;

			default:
				cout << "Menu Tidak Tersedia!" << endl;
				break;

		}
		cout << "Kembali ke menu utama(y/n) = ";
		cin >> loop;
	} while (loop == 'y' || loop == 'Y');

    return 0;
}

string caesar_proses(string text, int key){
	string result = "";

	for(int i=0; i < text.length(); i++)
	{
		// Proses mengubah tiap karakter huruf
		// Enkripsi huruf kapital
		if(isupper(text[i]))
			result+=char(int(text[i]+key-65)%26 + 65);
		// Enkripsi huruf kecil
		else if(text[i] == ' ')
			result+=char(int(text[i]-text[i]+ 32));
		else
			result+=char(int(text[i]+key-97)%26 + 97);
	}
	//Mereturn hasil result
	return result;
}

void caesar(){
	int pilih;
	int key;
	string teks;

	system("cls");
		cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "    CAESAR CHIPER     |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;

	cout << "[1] Enkripsi" << endl;
	cout << "[2] Dekripsi" << endl;
	cout << "Pilih : "; 
    cin >> pilih;
	cout << endl;
	cin.ignore();
    
    if(pilih == 1){
        cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      ENKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;
            
        cout << "Plainteks\t: "; 
        getline(cin, teks);
        cout << "Kunci (angka)\t: "; 
        cin >> key;

        string cipherteks = caesar_proses(teks, key);
        cout << "Hasil enkripsi\t: "<< cipherteks << endl;
    }
    else if(pilih == 2){
        cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      DEKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;
		
        cout << "Cipherteks\t: ";
        getline(cin, teks);
        cout << "Kunci (angka)\t: "; 
        cin >> key;

        key = key%26; // Memastikan kunci diantara 0-25
        string plainteks = caesar_proses(teks, 26-key);
        cout << "Hasil dekripsi\t: "<< plainteks << endl;
    }
    else
        cout << "Menu tidak tersedia" << endl;

}

string railfence_enkripsi(string text, int key)
{
	// Membuat matriks ke cipher plain text
	// Kunci = baris , panjang(text) = kolom
	char rail[key][(text.length())];

	// Mengisi matriks rail untuk membedakan tempat yg berisi dengan yg kosong
	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	// Menemukan arah
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++)
	{
		//Mengecek arah flow balik jika kita sudah mengisi rail atas/bawah
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// Mengisi huruf alphabet yg sesuai
		rail[row][col++] = text[i];

		//Mencari baris selanjutnya menggunakan direction flag
		dir_down?row++ : row--;
	}

	//Sekarang sudah bisa membuat cipher menggunakan matriks rail fence
	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);

	return result;
}

string railfence_dekripsi(string cipher, int key)
{
	// Membuat matriks cipher plain text
	// Kunci = baris , panjang(text) = kolom
	char rail[key][cipher.length()];

	// Mengisi matriks rail untuk membedakan tempat yg berisi dengan yg kosong
	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			rail[i][j] = '\n';

	// Untuk menemukan arah
	bool dir_down;

	int row = 0, col = 0;

	// Menandai tempatnya dengan '*'
	for (int i=0; i < cipher.length(); i++)
	{
		// Mengecek arah aliran
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// Menempatkan penanda
		rail[row][col++] = '*';

		// Mencari baris selanjutnya menggunakan direction flag
		dir_down?row++ : row--;
	}

	// Sekarang bisa membuat isian matriks rail fence
	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];


	/*Sekarang bisa membaca matriks dengan cara zig zag 
	untuk membuat teks yg akan dihasilkan*/
	string result;

	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		// Mengecek arah aliran
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// Menempatkan penanda
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		//Mencari baris selanjutnya menggunakan direction flag
		dir_down?row++: row--;
	}
	return result;
}

void railfence()
{
	int pilih;
	string teks; 
	int key;

    cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "  RAIL FENCE CHIPER   |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;
	cout << "[1] Enkripsi" << endl;
	cout << "[2] Dekripsi" << endl;
	cout << "Pilih: "; 
    cin >> pilih;
	cout << endl;
	cin.ignore();
	if (pilih == 1){
		cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      ENKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;
		
        cout << "Plainteks\t: "; 
        getline(cin, teks);
		cout << "Kunci (angka)\t: "; 
        cin >> key;

		string cipherteks = railfence_enkripsi(teks, key);
		cout << "Hasil enkripsi\t: "<< cipherteks << endl;
	}
	else if (pilih == 2){
		cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      DEKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;

		cout << "Cipherteks\t: "; 
        getline(cin, teks);
		cout << "Kunci (angka)\t: "; 
        cin >> key;

		string plainteks = railfence_dekripsi(teks, key);
		cout << "Hasil dekripsi\t: "<< plainteks << endl;
	}
	else{
		cout << "Menu tidak tersedia" << endl;
	}
}

class Vig {
   public:
      string key;
   Vig(string key) {
      for (int i = 0; i < key.size(); ++i) {
         if (key[i] >= 'A' && key[i] <= 'Z')
            this->key += key[i];
         else if (key[i] >= 'a' && key[i] <= 'z')
            this->key += key[i] + 'A' - 'a';
      }
   }
   string vigenere_enkripsi(string text)
	{
		string cipher_text;
		
		 for (int i = 0, j = 0; i < text.length(); ++i){
	    char c = text[i];
	
	        if (c >= 'a' && c <= 'z'){
			
	            c += 'A' - 'a';
	            cipher_text += (c + key[j] - 2 * 'A') % 26 + 'A';
	            j = (j + 1) % key.length();
	        }
	        else if (c < 'A' || c > 'Z' || c == ' '){
	        	cipher_text += ' ';
	        }
	        else if(c>='A' && c <= 'Z'){
	        	cipher_text += (c + key[j] - 2 * 'A') % 26 + 'A';
	            j = (j + 1) % key.length();
			}
	    		
	    }
		return cipher_text;
	}
	
	string vigenere_dekripsi(string cipher_text)
	{
		string orig_text;
		
		for (int i = 0, j = 0; i < cipher_text.length(); ++i) {
	         char c = cipher_text[i];
	         if (c >= 'a' && c <= 'z'){
	            c += 'A' - 'a';
	            orig_text += (c - key[j] + 26) % 26 + 'A';//Ditambahkan 'A' untuk membawanya ke range alfabet ASCII [ 65-90 | A-Z ]
	         	j = (j + 1) % key.length();
	         }
	         else if (c < 'A' || c > 'Z' || c == ' '){
	        	orig_text += ' ';
	        }
	        else if(c>='A' && c <= 'Z'){
	        	orig_text += (c - key[j] + 26) % 26 + 'A';//Ditambahkan 'A' untuk membawanya ke range alfabet ASCII [ 65-90 | A-Z ]
				j = (j + 1) % key.length();
			}
	      }
		return orig_text;
	}
};

void vigenere()
{
	int pilih;
	string teks, key;

	cout << setfill('=')
             << setw(26)
             << "="
             << endl;
        cout << "| "
             << "    VIGNERE CHIPER     |" << endl;
        cout << setfill('=')
             << setw(26)
             << "="
             << endl
             << endl;

	cout << "[1] Enkripsi" << endl;
	cout << "[2] Dekripsi" << endl;
	cout << "Pilih: "; 
    cin >> pilih;
	cout << endl;
	cin.ignore();

	if (pilih == 1){
		cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      ENKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;

		cout << "Plainteks\t: "; 
        getline(cin, teks);
		cout << "Kunci (teks)\t: "; 
        getline(cin, key);
		Vig v(key);
		string kunci_ulang = teks;
		string cipherteks = v.vigenere_enkripsi(kunci_ulang);
		cout << "Hasil enkripsi\t: "<< cipherteks << endl;
	}

	else if (pilih == 2){
		cout << setfill('=')
             << setw(25)
             << "="
             << endl;
        cout << "| "
             << "      DEKRIPSI        |" << endl;
        cout << setfill('=')
             << setw(25)
             << "="
             << endl
             << endl;

		cout << "Cipherteks\t: "; 
        getline(cin, teks);
		cout << "Kunci (teks)\t: "; 
        getline(cin, key);
		Vig v(key);
		string kunci_ulang = teks;
		string plainteks = v.vigenere_dekripsi(teks);
		cout << "Hasil dekripsi\t: " << endl;
	}

	else{
		cout << "Menu tidak tersedia" << endl;
	}
}

void super_enkripsi(){
    int pilih[3];
	string teks;
	string cipherText[3];
	string vigenere_key;
	int caesar_key, railfence_key;
	cin.ignore();

	 cout << setfill('=')
             << setw(39)
             << "="
             << endl;
        cout << "| "
             << "     ALGORITMA SUPER ENKRIPSI       |" << endl;
        cout << setfill('=')
             << setw(39)
             << "="
             << endl
             << endl;
    cout << "========URUTAN ENKRIPSI=========" << endl;
    cout << "(1) Caesar" << endl;
    cout << "(2) Rail Fence" << endl;
    cout << "(3) Vigenere" << endl;
    cout << "Pilih (Contoh: 1 2 3) : ";
    cin >> pilih[0] >> pilih[1] >> pilih[2];

    cin.ignore();
	cout << "\nPlainteks: "; 
    getline(cin, teks);
	cout << endl;
	
    for(int i = 0; i < 3; i++){
        if(i == 0){
            if (pilih[i] == 1) 
            {
                 cout << setfill('=')
                      << setw(42)
                      << "="
                      << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher    |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(teks, caesar_key);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_enkripsi(teks, railfence_key);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 3)
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_enkripsi(teks);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            }
        }
        if(i == 1){
            if (pilih[i] == 1) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(cipherText[0], caesar_key);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher  |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_enkripsi(cipherText[0], railfence_key);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 3)
            {
                cin.ignore();
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_enkripsi(cipherText[0]);
                cout << "Hasil enkripsi\t: " << cipherText[i] << endl << endl;
            }
        }
        if(i == 2){
            if (pilih[i] == 1) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(cipherText[1], caesar_key);
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher  |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_enkripsi(cipherText[1], railfence_key);
            } 
            else if(pilih[i] == 3)
            {
                cin.ignore();
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_enkripsi(cipherText[1]);
            }
        }
    }
    cout << setfill('=')
         << setw(42)
         << "="
         << endl;
    cout << "| "
         << "      HASIL AKHIR SUPER ENKRIPSI       |" << endl;
    cout << setfill('=')
         << setw(42)
         << "="
         << endl
         << endl;
    cout << "PlainText Asal = " << teks << endl;
    cout << "CipherText = " << cipherText[2] << endl << endl;
}

void super_dekripsi(){
    int pilih[3];
	string teks;
	string cipherText[3];
	string vigenere_key;
	int caesar_key, railfence_key;
	cin.ignore();

	 cout << setfill('=')
          << setw(39)
          << "="
          << endl;
     cout << "| "
          << "     ALGORITMA SUPER DEKRIPSI       |" << endl;
     cout << setfill('=')
          << setw(39)
          << "="
          << endl
          << endl;
    cout << "========URUTAN DEKRIPSI=========" << endl;
    cout << "(1) Caesar" << endl;
    cout << "(2) Rail Fence" << endl;
    cout << "(3) Vigenere" << endl;
    cout << "Pilih (Contoh: 1 2 3) : ";
    cin >> pilih[0] >> pilih[1] >> pilih[2];

    cin.ignore();
	cout << "\nCipherteks: "; 
    getline(cin, teks);
	cout << endl;
	
    for(int i = 0; i < 3; i++){
        if(i == 0){
            if (pilih[i] == 1) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(teks, 26-caesar_key);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher  |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_dekripsi(teks, railfence_key);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 3)
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_dekripsi(teks);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            }
        }
        if(i == 1){
            if (pilih[i] == 1) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(cipherText[0], 26-caesar_key);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher  |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_dekripsi(cipherText[0], railfence_key);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            } 
            else if(pilih[i] == 3)
            {
                cin.ignore();
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_dekripsi(cipherText[0]);
                cout << "Hasil dekripsi\t: " << cipherText[i] << endl << endl;
            }
        }
        if(i == 2){
            if (pilih[i] == 1) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "   Enkripsi #" << i + 1 << " dengan Caesar Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> caesar_key;
                cipherText[i] = caesar_proses(cipherText[1], 26-caesar_key);
            } 
            else if(pilih[i] == 2) 
            {
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << " Enkripsi #" << i + 1 << " dengan Rail Fence Cipher  |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (angka)\t: "; 
                cin >> railfence_key;
                cipherText[i] = railfence_dekripsi(cipherText[1], railfence_key);
            } 
            else if(pilih[i] == 3)
            {
                cin.ignore();
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl;
                cout << "| "
                     << "  Enkripsi #" << i + 1 << " dengan Vigenere Cipher   |" << endl;
                cout << setfill('=')
                     << setw(42)
                     << "="
                     << endl
                     << endl;
                cout << "Kunci (teks)\t: "; 
                getline(cin, vigenere_key);
                Vig v(vigenere_key);
                cipherText[i] = v.vigenere_dekripsi(cipherText[1]);
            }
        }
    }
    cout << setfill('=')
         << setw(42)
         << "="
         << endl;
    cout << "| "
         << "      HASIL AKHIR SUPER DEKRIPSI       |" << endl;
    cout << setfill('=')
         << setw(42)
         << "="
         << endl
         << endl;
    cout << "CipherText Asal = " << teks << endl;
    cout << "PlainText = " << cipherText[2] << endl << endl;
}