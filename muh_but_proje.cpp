#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//De�i�kenleri tan�mlad�k
string ogrenciadi, ogrencisoyadi, ogrencibolum, ogretimelemaniadi, ogretimelemanisoyadi, ogretimelemanibolum, dersadi;
int ogrencino, ogrencisinif, ogretimelemanisicilno, derssaat;
double ortalama, vize, final; 
float derskredi;
int secim=0;

void ogrencimodulu();
void ogretimelemanimodulu();
void dersmodulu();
void notgirismodulu();
//Men�y� olu�turduk
void ogrenciisleriotomasyonu()
{
	system("cls"); //Console ekran� temizler.
	cout<<"��renci ��leri Otomasyonu"<<endl;
    cout << "1. ��renci Mod�l�\n" 
    << "2. ��retim Eleman� Mod�l�\n" 
    << "3. Ders Mod�l�\n" 
    << "4. Not Giri� Mod�l�\n" 
    << "5. Programdan Cikis\n" 
    << "Seciminiz: "; 
    cin >> secim;
	
	A:
	switch (secim) 
	{ 
		case 1: ogrencimodulu(); break;
		case 2: ogretimelemanimodulu(); break; 
		case 3: dersmodulu(); break; 
		case 4: notgirismodulu(); break;
		case 5: break;
		default: 
		cout<<"L�ften 1 ile 5 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A; 
	} 
}
//��renci Mod�l� dosyas�n�n sat�r say�s�n� hasaplayan fonksiyon
int satirsayisi(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");
	
	char ch;
    while(!dosya.eof())  //bu d�ng� dosya sonuna gelene kadar dosyay� okur
    {
        dosya.get(ch); //okuma i�lemi get(); ile yap�l�r
        if(ch=='\n'){ //E�er ch ifadesi bo�lu�a denk gelirse sat�r say�s�n� 1 artt�r�yoruz.
			satirsayisi++;
		}
  	}
	return satirsayisi;
}
//��renci bilgilerinin kay�t edildi�i fonksiyon 
void ogrencikayit(){
	int N;
	
	ifstream dosya;
	ofstream dosya1;
	dosya.open("��renci Mod�l�.txt");
	dosya1.open("��renci Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi(); j++){
		dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;  
		dosya1 <<ogrenciadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
	}

    cout << "Ka� Adet ��renci Gireceksiniz: "; 
    cin >> N;
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". ��rencinin Ad�n� giriniz: "; 
        cin >> ogrenciadi; 
        cout << i + 1 << ". ��rencinin Soyad�n� giriniz: "; 
        cin >> ogrencisoyadi;
        cout << i + 1 << ". ��rencinin Okul numaras�n� giriniz: "; 
        cin >> ogrencino;
		cout << i + 1 << ". ��rencinin B�l�m�: "; 
        cin >> ogrencibolum; 
		cout << i + 1 << ". ��rencinin S�n�f�: "; 
        cin >> ogrencisinif;
		
		dosya1 <<ogrenciadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kulland�k ve dosyaya bilgileri kaydektik.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
    } 
	
	dosya.close();//dosyay� kapatt�k.
	dosya1.close();//dosyay� kapatt�k.

	remove("��renci Mod�l�.txt");
	rename("��renci Mod�l�1.txt","��renci Mod�l�.txt");
	ogrenciisleriotomasyonu();	
}

//��renciyi numaras�na g�re arayan fonksiyon
void ogrencinumarasinagorearama(){
	int arananno, kontrol=0, secenek;
 	
	A:
	cout<<"Arad���n�z ��rencinin Numaras�n� Giriniz: ";
	cin>>arananno;
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");

    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
	    if(arananno==ogrencino){
	    	cout<<"ad: "<<ogrenciadi<<endl;
	    	cout<<"soyad: "<<ogrencisoyadi<<endl;
			cout<<"numara: "<<ogrencino<<endl;
	    	cout<<"bolum: "<<ogrencibolum<<endl;
	    	cout<<"sinif: "<<ogrencisinif<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	
	if(kontrol==0){
		cout<<"Bu Numarada ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}
}
//��renciyi ad�na g�re arayan fonksiyon
void ogrenciadinagorearama(){
	int kontrol=0, secenek;
	string arananad;
	
	A:
	cout<<"Arad���n�z ��rencinin Ad�n� Giriniz: ";
	cin>>arananad;
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
	    if(arananad==ogrenciadi){
	    	cout<<"ad: "<<ogrenciadi<<endl;
	    	cout<<"soyad: "<<ogrencisoyadi<<endl;
			cout<<"numara: "<<ogrencino<<endl;
	    	cout<<"bolum: "<<ogrencibolum<<endl;
	    	cout<<"sinif: "<<ogrencisinif<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	
	if(kontrol==0){
		cout<<"Bu �simde ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}	
}
//��renci arama men�s�
void ogrenciarama(){
	system("cls"); //Console ekran� temizler.
	cout<<"��renci arama"<<endl;
    cout << "1. ��renci numaras�na g�re\n" 
    << "2. ��renci ad�na g�re\n" 
    << "3. ��renci ��leri Otomasyonu\n" 
    << "4. Programdan Cikis\n"
    << "Seciminiz: "; 
    cin >> secim;
	
	A:
	switch (secim) 
	{ 
		case 1: ogrencinumarasinagorearama(); break;
		case 2: ogrenciadinagorearama(); break; 
		case 3: ogrenciisleriotomasyonu(); break;
		case 4: break;
		default: 
		cout<<"L�ften 1 ile 4 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A; 
	}  			
}
//��renciyi b�l�m�ne g�re listeleme
void bolumegorelisteleme(){
	int kontrol=0, secenek;
	string arananbolum;
	
	A:
	cout<<"Hangi B�l�mden ��renci Ar�yorsunuz: ";
	cin>>arananbolum;
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
	    if(arananbolum==ogrencibolum){
	    	cout<<"ad: "<<ogrenciadi<<endl;
	    	cout<<"soyad: "<<ogrencisoyadi<<endl;
			cout<<"numara: "<<ogrencino<<endl;
	    	cout<<"bolum: "<<ogrencibolum<<endl;
	    	cout<<"sinif: "<<ogrencisinif<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	dosya.close();
	if(kontrol==0){
		cout<<"Bu B�l�mden ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}		
}
//��renciyi s�n�f�na g�re listeleme
void sinifagorelisteleme(){
	int kontrol=0, secenek, aranansinif;
	
	A:
	cout<<"Hangi S�n�ftan ��renci Ar�yorsunuz: ";
	cin>>aranansinif;
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
	    if(aranansinif==ogrencisinif){
	    	cout<<"ad: "<<ogrenciadi<<endl;
	    	cout<<"soyad: "<<ogrencisoyadi<<endl;
			cout<<"numara: "<<ogrencino<<endl;
	    	cout<<"bolum: "<<ogrencibolum<<endl;
	    	cout<<"sinif: "<<ogrencisinif<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	dosya.close();
	
	if(kontrol==0){
		cout<<"Bu S�n�ftan ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}	
}
//��renci listeleme men�s�
void ogrencilisteleme(){
	system("cls");
	cout<<"��renci Listeleme"<<endl;
    cout << "1. B�l�me g�re listeleme\n" 
    << "2. S�n�fa g�re listeleme\n" 
    << "3. ��renci ��leri Otomasyonu\n" 
    << "4. Programdan Cikis\n"
    << "Seciminiz: "; 
    cin >> secim;
	
	A:
	switch (secim) 
    { 
	    case 1: bolumegorelisteleme(); break;
		case 2: sinifagorelisteleme(); break; 
	    case 3: ogrenciisleriotomasyonu(); break;
	    case 4: break;
		default: 
		cout<<"L�ften 1 ile 4 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A;   
    } 
}
//��renci bilgilerinin g�ncellendi�i fonksiyon
void ogrencibilgileriduzeltme(){
	int arananno, kontrol=0, secenek;
	ifstream dosya;
	ofstream dosya1;

	A:
	cout<<"G�ncellenecek ��rencinin Numaras�: ";
	cin>>arananno;
	dosya.open("��renci Mod�l�.txt");
	dosya1.open("��renci Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi(); j++){
		dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;  
		if(arananno==ogrencino){
			cout<<"Eski Bilgiler"<<endl;
			cout<<"ad: "<<ogrenciadi<<endl;
	    	cout<<"soyad: "<<ogrencisoyadi<<endl;
			cout<<"numara: "<<ogrencino<<endl;
	    	cout<<"bolum: "<<ogrencibolum<<endl;
	    	cout<<"sinif: "<<ogrencisinif<<endl;
	    	cout<<"================================="<<endl;
	    	
			cout<<"Yeni Bilgiler"<<endl;
			cout<<"��rencinin Ad�n� giriniz: ";
			cin>>ogrenciadi;
			cout << "��rencinin Soyad�n� giriniz: "; 
	        cin >> ogrencisoyadi; 
	        cout << "��rencinin Okul numaras�n� giriniz: "; 
	        cin >> ogrencino;
			cout << "��rencinin B�l�m�: "; 
	        cin >> ogrencibolum;
			cout << "��rencinin S�n�f�: "; 
	        cin >> ogrencisinif;
	        kontrol++;
		} 
	
		dosya1 <<ogrenciadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
	}

	dosya.close();
	dosya1.close();

	remove("��renci Mod�l�.txt");
	rename("��renci Mod�l�1.txt","��renci Mod�l�.txt");
		
	if(kontrol==0){
		cout<<"Bu Numarada ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar G�ncelleme Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}
}
//��renci modul� men�s�
void ogrencimodulu(){ 
    system("cls");
	cout<<"��renci Mod�l�"<<endl;
	
	cout << "1. ��renci Kay�t\n" 
        << "2. ��renci Arama\n" 
        << "3. ��renci Listeleme\n" 
        << "4. ��renci bilgileri d�zeltme\n" 
        << "5. ��renci ��leri Otomasyonu\n" 
        << "6. Programdan Cikis\n"
        << "Seciminiz: "; 
    cin >> secim; 
 	
	A:
    switch (secim) 
    { 
	    case 1: ogrencikayit(); break;
		case 2: ogrenciarama();  break; 
	    case 3: ogrencilisteleme(); break; 
	    case 4: ogrencibilgileriduzeltme(); break;
		case 5: ogrenciisleriotomasyonu(); break;
		case 6: break;
		default: 
		cout<<"L�ften 1 ile 6 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A;  
    }
} 
//��retim Eleman� Mod�l� sat�r say�s�n� hesaplayan fonksiyon
int satirsayisi1(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("��retim Eleman� Mod�l�.txt");
	
	char ch;
    while(!dosya.eof())  //bu d�ng� dosya sonuna gelene kadar dosyay� okur
    {
        dosya.get(ch);//okuma i�lemi get(); ile yap�l�r
        if(ch=='\n'){//E�er ch ifadesi bo�lu�a denk gelirse sat�r say�s�n� 1 artt�r�yoruz.
			satirsayisi++;
		}
  	}
	return satirsayisi;
}
//��retim eleman� kay�t fonksiyonu
void ogretimelemanikayit(){
	int N, secenek;
	
	ifstream dosya; //ofstream s�n�f�ndan bir nesne olu�turduk.
	ofstream dosya1;
	dosya.open("��retim Eleman� Mod�l�.txt"); //��retim Eleman� Mod�l�.txt isimli bir dosya a�t�k.
	dosya1.open("��retim Eleman� Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi1(); j++){
		dosya>>ogretimelemaniadi>>ogretimelemanisoyadi>>ogretimelemanisicilno>>ogretimelemanibolum;  
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl; 
	}
	
    cout << "Ka� Adet ��retim Eleman� Gireceksiniz: "; 
    cin >> N; 
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". ��retim Eleman� Ad�n� giriniz: "; 
        cin >> ogretimelemaniadi; 
        cout << i + 1 << ". ��retim Eleman� Soyad�n� giriniz: "; 
        cin >> ogretimelemanisoyadi;
        cout << i + 1 << ". ��retim Eleman� Sicil numaras�n� giriniz: "; 
        cin >> ogretimelemanisicilno;
		cout << i + 1 << ". ��retim Eleman� B�l�m�: "; 
        cin >> ogretimelemanibolum; 
		
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl;
	}
	
	dosya.close();
	dosya1.close();

	remove("��retim Eleman� Mod�l�.txt");
	rename("��retim Eleman� Mod�l�1.txt","��retim Eleman� Mod�l�.txt");
	
	ogrenciisleriotomasyonu();	
} 
//��retim eleman� arama fonksiyonu
void ogretimelemaniarama(){
	int kontrol=0, secenek, aranansicilno;
	
	A:
	cout<<"Arad���n�z ��retim Eleman�n�n Sicil Numaras�n� Giriniz: ";
	cin>>aranansicilno;
	ifstream dosya;
	dosya.open("��retim Eleman� Mod�l�.txt");
    for(int j=1; j<satirsayisi1(); j++){
    	dosya>>ogretimelemaniadi>>ogretimelemanisoyadi>>ogretimelemanisicilno>>ogretimelemanibolum;
	    if(aranansicilno==ogretimelemanisicilno){
	    	cout<<"ad: "<<ogretimelemaniadi<<endl;
	    	cout<<"soyad: "<<ogretimelemanisoyadi<<endl;
			cout<<"sicil no: "<<ogretimelemanisicilno<<endl;
	    	cout<<"bolum: "<<ogretimelemanibolum<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	
	if(kontrol==0){
		cout<<"Bu Sicil Numaras�nda ��retim Eleman� Bulunmamaktad�r!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}
}
//��retim eleman�n�n bilgilerinin g�ncellendi�i fonksiyon
void ogretimelemanibilgileriduzeltme(){
	int aranansicilno, kontrol=0, secenek;

	ifstream dosya;
	ofstream dosya1;
	A:
	cout<<"G�ncellenecek ��retim Eleman�n�n Sicil Numaras�n� Giriniz: ";
	cin>>aranansicilno;
	dosya.open("��retim Eleman� Mod�l�.txt");
	dosya1.open("��retim Eleman� Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi1(); j++){
		dosya>>ogretimelemaniadi>>ogretimelemanisoyadi>>ogretimelemanisicilno>>ogretimelemanibolum;  
		if(aranansicilno==ogretimelemanisicilno){
			cout<<"Eski Bilgiler"<<endl;
			cout<<"ad: "<<ogretimelemaniadi<<endl;
	    	cout<<"soyad: "<<ogretimelemanisoyadi<<endl;
			cout<<"Sicil No: "<<ogretimelemanisicilno<<endl;
	    	cout<<"bolum: "<<ogretimelemanibolum<<endl;
	    	cout<<"================================="<<endl;
	    	
			cout<<"Yeni Bilgiler"<<endl;
			cout<<"��retim Eleman� Ad�n� giriniz: ";
			cin>>ogretimelemaniadi;
			cout << "��retim Eleman� Soyad�n� giriniz: "; 
	        cin >> ogretimelemanisoyadi; 
	        cout << "��retim Eleman� Sicil numaras�n� giriniz: "; 
	        cin >> ogretimelemanisicilno;
			cout << "��retim Eleman� B�l�m�: "; 
	        cin >> ogretimelemanibolum;
	        kontrol++;
		} 
	
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl; 
	}

	dosya.close();
	dosya1.close();

	remove("��retim Eleman� Mod�l�.txt");
	rename("��retim Eleman� Mod�l�1.txt","��retim Eleman� Mod�l�.txt");
	
	if(kontrol==0){
		cout<<"Bu Sicil Numaras�nda ��retim Eleman� Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar G�ncelleme Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}	
}
//��retim eleman� listeleme fonksiyonu
void ogretimelemanilisteleme(){
	int kontrol=0, secenek; 
	string arananbolum;

	A:
	cout<<"Arad���n�z ��retim Eleman�n�n B�l�m�n� Giriniz: ";
	cin>>arananbolum;
	ifstream dosya;
	dosya.open("��retim Eleman� Mod�l�.txt");
    for(int j=1; j<satirsayisi1(); j++){
    	dosya>>ogretimelemaniadi>>ogretimelemanisoyadi>>ogretimelemanisicilno>>ogretimelemanibolum;
	    if(arananbolum==ogretimelemanibolum){
	    	cout<<"ad: "<<ogretimelemaniadi<<endl;
	    	cout<<"soyad: "<<ogretimelemanisoyadi<<endl;
			cout<<"sicil no: "<<ogretimelemanisicilno<<endl;
	    	cout<<"bolum: "<<ogretimelemanibolum<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	
	if(kontrol==0){
		cout<<"Bu B�l�mden ��retim Eleman� Bulunmamaktad�r!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}	
}
//��retim eleman� men�s�
void ogretimelemanimodulu(){
	system("cls");
	cout<<"��retim Eleman� Mod�l� "<<endl;
	
	cout << "1. ��retim eleman� kay�t\n" 
    << "2. ��retim eleman� arama\n" 
    << "3. ��retim eleman� bilgileri d�zeltme\n" 
    << "4. ��retim eleman� listeleme\n"
    << "5. ��renci ��leri Otomasyonu\n" 
    << "6. Programdan Cikis\n"
    << "Seciminiz: "; 
    cin >> secim; 
	
	A:
    switch (secim) 
    { 
	    case 1: ogretimelemanikayit(); break;
		case 2: ogretimelemaniarama();  break; 
	    case 3: ogretimelemanibilgileriduzeltme(); break; 
	    case 4: ogretimelemanilisteleme(); break;
		case 5: ogrenciisleriotomasyonu(); break;
		case 6: break;
		default: 
		cout<<"L�ften 1 ile 6 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A;  
    }
}
//Ders Mod�l� dosyas�n�n sat�r say�s�n�n hesapaland��� fonksiyon
int satirsayisi2(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("Ders Mod�l�.txt");
	
	char ch;
    while(!dosya.eof())  //bu d�ng� dosya sonuna gelene kadar dosyay� okur
    {
        dosya.get(ch);//okuma i�lemi get(); ile yap�l�r
        if(ch=='\n'){//E�er ch ifadesi bo�lu�a denk gelirse sat�r say�s�n� 1 artt�r�yoruz.
			satirsayisi++;
		}
  	}
  	dosya.close();
	return satirsayisi;
}
//Ders kay�t� yap�lan fonksiyon
void derskayit(){
	int N;
	
	ifstream dosya; //ofstream s�n�f�ndan bir nesne olu�turduk.
	dosya.open("Ders Mod�l�.txt"); //Ders Mod�l�.txt isimli bir dosya a�t�k.
	ofstream dosya1;
	dosya1.open("Ders Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi2(); j++){
		dosya>>dersadi>>derssaat>>derskredi; 
		dosya1 <<dersadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}
	
    cout << "Ka� Adet Ders Gireceksiniz: "; 
    cin >> N; 
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". Ders Ad�n� giriniz: "; 
        cin >> dersadi; 
        cout << i + 1 << ". Ders Saatini giriniz: "; 
        cin >> derssaat;
        cout << i + 1 << ". Ders Kredisini giriniz: "; 
        cin >> derskredi;
		
		dosya1 <<dersadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}
	
	dosya.close();
	dosya1.close();

	remove("Ders Mod�l�.txt");
	rename("Ders Mod�l�1.txt","Ders Mod�l�.txt");
	ogrenciisleriotomasyonu();	
}
//Ders bilgilerinin g�ncellendi�i fonksiyon
void dersbilgileriduzenleme(){
	int kontrol=0, secenek;
	string arananders;

	ifstream dosya;
	ofstream dosya1;
	A:
	cout<<"G�ncellenecek Dersin Ad�n� Giriniz: ";
	cin>>arananders;
	dosya.open("Ders Mod�l�.txt");
	dosya1.open("Ders Mod�l�1.txt"); 
	for(int j=1; j<satirsayisi2(); j++){
		dosya>>dersadi>>derssaat>>derskredi; 
		if(arananders==dersadi){
			cout<<"Eski Bilgiler"<<endl;
	    	cout<<"Ders Ad�: "<<dersadi<<endl;
	    	cout<<"Ders Saat: "<<derssaat<<endl;
			cout<<"Ders Kredi: "<<derskredi<<endl;
	    	cout<<"================================="<<endl;
	    	
			cout<<"Yeni Bilgiler"<<endl;
			cout<<"Dersin Ad�n� giriniz: ";
			cin>>dersadi;
			cout << "Dersin Saatini giriniz: "; 
	        cin >> derssaat; 
	        cout << "Dersin Kredisini giriniz: "; 
	        cin >> derskredi;
	        kontrol++;
		} 
	
		dosya1 <<dersadi<<"\t"; //Burada olu�turdu�umuz nesneyi cout gibi kullan�yoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}

	dosya.close();
	dosya1.close();

	remove("Ders Mod�l�.txt");
	rename("Ders Mod�l�1.txt","Ders Mod�l�.txt");
	
	if(kontrol==0){
		cout<<"Bu �simde Ders Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar G�ncelleme Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}	
}
//Ders arama fonksiyonu
void dersarama(){
	int kontrol=0, secenek;
	string arananders;

	A:
	cout<<"Arad���n�z Dersin Ad�n� Giriniz: ";
	cin>>arananders;
	ifstream dosya;
	dosya.open("Ders Mod�l�.txt");
    for(int j=1; j<satirsayisi2(); j++){
    	dosya>>dersadi>>derssaat>>derskredi;
	    if(arananders==dersadi){
	    	cout<<"Ders Ad�: "<<dersadi<<endl;
	    	cout<<"Ders Saat: "<<derssaat<<endl;
			cout<<"Ders Kredi: "<<derskredi<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	dosya.close();
	if(kontrol==0){
		cout<<"Bu �simde Ders Bulunmamaktad�r!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}
}
//Ders listeleme fonksiyonu
void derslisteleme(){
	int secenek; 

	ifstream dosya;
	dosya.open("Ders Mod�l�.txt");
    for(int j=1; j<satirsayisi2(); j++){
    	dosya>>dersadi>>derssaat>>derskredi;
	    cout<<"Ders Ad�: "<<dersadi<<endl;
	    cout<<"Ders Saati: "<<derssaat<<endl;
		cout<<"Ders Kredi: "<<derskredi<<endl;
	    cout<<"================================="<<endl;
	}

	A:	
	cout<<"Devam Etmek ��in 1 Bas�n�z: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();	
}
//Ders modul� men�s�
void dersmodulu(){
	system("cls");
	cout<<"Ders Mod�l� "<<endl;
	
	cout << "1. Ders kay�t\n" 
    << "2. Ders arama\n" 
    << "3. Ders bilgileri d�zeltme\n" 
    << "4. Ders listeleme\n"
    << "5. ��renci ��leri Otomasyonu\n" 
    << "6. Programdan Cikis\n"
    << "Seciminiz: "; 
    cin >> secim; 

	A:
    switch (secim) 
    { 
	    case 1: derskayit(); break;
		case 2: dersarama();  break; 
	    case 3: dersbilgileriduzenleme(); break; 
	    case 4: derslisteleme(); break;
		case 5: ogrenciisleriotomasyonu(); break;
		case 6: break;
		default: 
		cout<<"L�ften 1 ile 6 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A;  
    }	
}
//��renci Ders Ekleme dosyas�n�n sat�r say�s�n� hesaplayan fonksiyon
int satirsayisi3(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("��renci Ders Ekleme.txt");
	
	char ch;
    while(!dosya.eof())  //bu d�ng� dosya sonuna gelene kadar dosyay� okur
    {
        dosya.get(ch);//okuma i�lemi get(); ile yap�l�r
        if(ch=='\n'){//E�er ch ifadesi bo�lu�a denk gelirse sat�r say�s�n� 1 artt�r�yoruz.
			satirsayisi++;
		}
  	}
  	dosya.close();
	return satirsayisi;
}
//��renciye ders ekleme fonksiyonu
void ogrencidersekleme(){
	int dersadet, satir=0, dersnumara, satir1=0;;
	string dersadidizi[satirsayisi2()];
	int derssaatdizi[satirsayisi2()], derskredidizi[satirsayisi2()];
	ofstream dosya1;
	dosya1.open("��renci Ders Ekleme.txt");
	ifstream dosya;
	dosya.open("��renci Mod�l�.txt");
	ifstream dosya2;
	dosya2.open("Ders Mod�l�.txt");
	satir1=satirsayisi2();
	
	for(int j=1; j<satir1; j++){
	    dosya2>>dersadi>>derssaat>>derskredi;
		dersadidizi[satir]=dersadi;
		derssaatdizi[satir]=derssaat;
		derskredidizi[satir]=derskredi;
		satir++;
	} 
	
    for(int j=1; j<satirsayisi(); j++){
    	system("cls");
		for(int j=1; j<satir1; j++){
	    	cout<<j<<". Ders"<<endl;
		    cout<<"Ders Ad�: "<<dersadidizi[j-1]<<endl;
		    cout<<"Ders Saati: "<<derssaatdizi[j-1]<<endl;
			cout<<"Ders Kredi: "<<derskredidizi[j-1]<<endl;
		    cout<<"================================="<<endl;
		}    	
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
		cout<<"��renci Bilgileri"<<endl;
	    cout<<"ad: "<<ogrenciadi<<endl;
	    cout<<"soyad: "<<ogrencisoyadi<<endl;
		cout<<"numara: "<<ogrencino<<endl;
	    cout<<"bolum: "<<ogrencibolum<<endl;
	    cout<<"sinif: "<<ogrencisinif<<endl;
	    cout<<"================================="<<endl;
		
		dosya1<<ogrenciadi<<"\t";
	    dosya1<<ogrencisoyadi<<"\t";
	    dosya1<<ogrencino<<"\t";
	    dosya1<<ogrencibolum<<"\t";
	    dosya1<<ogrencisinif<<endl;
		
		B:
		cout<<"L�tfen "<<satir<<" den Fazla Ders Girmeyiniz!"<<endl;
		cout<<ogrencino<<" Numaral� ��renci ��in Ka� Tane Ders Gireceksiniz: ";
		cin>>dersadet;
		if(dersadet>satir){
			goto B;
		}
		else{ 
        	for (int j = 0; j < dersadet; j++) 
        	{ 
        		C:
            	cout << ogrencino << " Numaral� ��rencinin " << j + 1 << ". Dersinin Numaras�n� Giriniz:"; 
            	cin >> dersnumara;
            	if(dersnumara<=satir)
            	{
            		dosya1<<dersadidizi[dersnumara-1]<<endl;
				}
				else{
					cout<<dersnumara<<" Numaral� Ders Yok L�tfen Olan Derslerden Se�iniz!"<<endl;
					goto C;
				}
        	}
			for(int i=0; i<satir-dersadet; i++){
				dosya1<<"null"<<endl; 		
			}	
		} 
	}
		
	dosya.close();
	dosya1.close();
	A:	
	cout<<"Devam Etmek ��in 1 Bas�n�z: ";
	cin>>secim;
	if(secim!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//��renci not giri� fonksiyonu
void ogrencinotgirisi(){
	int secenek;
	ifstream dosya;
	ofstream dosya1;
	dosya.open("��renci Ders Ekleme.txt");
	dosya1.open("��renci Not Giri�.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
		dosya1<<ogrenciadi<<"\t";
	    dosya1<<ogrencisoyadi<<"\t";
	    dosya1<<ogrencino<<"\t";
	    dosya1<<ogrencibolum<<"\t";
	    dosya1<<ogrencisinif<<endl;
    	cout<<ogrencino<<" Numaral� ��rencinin ��in Not Giri�i"<<endl;
    	cout<<"L�tfen Notlar� 100 den B�y�k Girmeyiniz!"<<endl;
		for(int i=1; i<satirsayisi2(); i++){
			dosya>>dersadi;
			if(dersadi!="null"){
				C:
				cout<<dersadi<<" Vize Notunu Giriniz: ";
				cin>>vize;
				if(vize>100){
					cout<<"L�tfen Notlar� 100 den B�y�k Girmeyiniz!"<<endl;
					goto C;
				}
				B:
				cout<<dersadi<<" Final Notunu Giriniz: ";
				cin>>final;
				if(final>100){
					cout<<"L�tfen Notlar� 100 den B�y�k Girmeyiniz!"<<endl;
					goto B;	
				}
				ortalama=((vize*40)/100)+((final*60)/100);
				cout<<"Ortalama: "<<ortalama<<endl;
				dosya1<<dersadi<<"\t";
				dosya1<<vize<<"\t";
				dosya1<<final<<"\t";
				dosya1<<ortalama<<endl;				
			}
			else{
				dosya1<<"null"<<endl;
			}	
		}
		cout<<"================================="<<endl;
	}
	dosya.close();
	dosya1.close();
	A:	
	cout<<"Devam Etmek ��in 1 Bas�n�z: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//��rencinin ald��� derslerin listelendi�i fonksiyon
void ogrenciderslisteleme(){
	int secenek; 
	ifstream dosya;
	dosya.open("��renci Ders Ekleme.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
    	cout<<ogrencino<<" Numaral� ��rencinin Ald��� Dersler"<<endl;
		for(int i=1; i<satirsayisi2(); i++){
			dosya>>dersadi;
			if(dersadi!="null"){
				cout<<"Ders Ad�: "<<dersadi<<endl;				
			}
		}
		cout<<"================================="<<endl;
	}
	dosya.close();
	A:	
	cout<<"Devam Etmek ��in 1 Bas�n�z: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//��rencinin karnesini olu�turan fonksiyon
void karneolusturma(){
	int arananno, kontrol=0, satirders=0, secenek;
	string dersadidizi[satirsayisi2()];
	double vizedizi[satirsayisi2()], finaldizi[satirsayisi2()], ortalamadizi[satirsayisi2()];
	char ch;
		
	ifstream dosya;
	ofstream dosya1;
	ifstream dosya2;
	A:
	dosya.open("��renci Not Giri�.txt");
	dosya1.open("��renci Karne.txt");
	dosya2.open("��renci Karne.txt");			
	cout<<"Karnesini �stedi�iniz ��rencinin Numaras�n� Giriniz: ";
	cin>>arananno;
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
    	for(int k=1; k<satirsayisi2(); k++){
    		dosya>>dersadi;
    		dersadidizi[k-1]=dersadi;
    		if(dersadi!="null"){
    			dosya>>vize>>final>>ortalama;
    			vizedizi[k-1]=vize;
    			finaldizi[k-1]=final;
    			ortalamadizi[k-1]=ortalama;
    			satirders++;
			}
		}
		if(arananno==ogrencino){
			dosya1<<"Ad:"<<ogrenciadi<<endl;
			dosya1<<"Soyad:"<<ogrencisoyadi<<endl;
			dosya1<<"Numara:"<<ogrencino<<endl;
			dosya1<<"Bolum:"<<ogrencibolum<<endl;
			dosya1<<"Sinif:"<<ogrencisinif<<endl;
			dosya1<<endl;	
			dosya1<<"DERS ADI\t   "<<"VIZE NOTU\t"<<"FINAL NOTU\t"<<"ORTALAMA\t"<<"HARF\t"<<"DURUM"<<endl;
			for(int i=0; i<satirders; i++){
				if(dersadidizi[i]!="null"){	
					if(dersadidizi[i].length()>7)
					{
						dosya1<<dersadidizi[i]<<"\t      ";
						dosya1<<vizedizi[i]<<"\t    "    ;
						dosya1<<finaldizi[i]<<"\t\t";
						dosya1<<ortalamadizi[i]<<"\t\t";						
					}
					else{
						dosya1<<dersadidizi[i]<<"\t\t      ";
						dosya1<<vizedizi[i]<<"\t    "    ;
						dosya1<<finaldizi[i]<<"\t\t";
						dosya1<<ortalamadizi[i]<<"\t\t";						
					}		
					if(finaldizi[i]>=45){
						if(ortalamadizi[i]>=85)
						{
							dosya1<<"AA\t";
							dosya1<<"Gecti"<<endl;
						}
						else if(ortalamadizi[i]>=75)
						{
							dosya1<<"BA\t";
							dosya1<<"Gecti"<<endl;
						}
						else if(ortalamadizi[i]>=65)
						{
							dosya1<<"BB\t";
							dosya1<<"Gecti"<<endl;	
						}
						else if(ortalamadizi[i]>=55)
						{
							dosya1<<"CB\t";
							dosya1<<"Gecti"<<endl;
						}
						else if(ortalamadizi[i]>=45)
						{
							dosya1<<"CC\t";
							dosya1<<"Gecti"<<endl;
						}
						else if(ortalamadizi[i]>=35)
						{
							dosya1<<"DC\t";
							dosya1<<"Sartli Gecti"<<endl;
						}
						else
						{
							dosya1<<"FF\t";
							dosya1<<"Kald�"<<endl;
						}
					}
					else{
						dosya1<<"FF\t";
						dosya1<<"Kald�"<<endl;	
					}
				}
			}
			kontrol++;				
		}
		satirders=0;
	}	
	
	if(kontrol==0){
		cout<<"Bu Numarada ��renci Bulunmamaktad�r!"<<endl;
	}
	kontrol=0;
    while(!dosya2.eof())  //bu d�ng� dosya sonuna gelene kadar dosyay� okur
    {
        dosya2.get(ch);//okuma i�lemi get(); ile yap�l�r
        cout<<ch;
  	}
  	dosya.close();
	dosya1.close();
	dosya2.close();
	B:	
	cout<<"Tekrar Karne Olu�turmak ��in 1'e Ba�a D�nmek ��in 2'ye Bas�n�z: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekran� temizler.
			goto A;
			break;
			case 2:
			ogrenciisleriotomasyonu(); 
			break; 
	    } 
	}
	else{
		goto B;
	}
}
//Not giri� mod�l� men�s�
void notgirismodulu(){
	system("cls");
	cout<<"Not Giri� Mod�l� "<<endl;
	
	cout << "1. ��renciye ders ekleme\n" 
    << "2. ��rencinin ald��� ders i�in not giri�i \n" 
    << "3. ��renci ders listeleme \n" 
    << "4. ��renci karnesi olu�turma ve g�rselle�tirme\n"
    << "5. ��renci ��leri Otomasyonu\n" 
    << "6. Programdan Cikis\n"
    << "Seciminiz: "; 
    cin >> secim; 

	A:
    switch (secim) 
    { 
	    case 1: ogrencidersekleme(); break;
		case 2: ogrencinotgirisi();  break; 
	    case 3: ogrenciderslisteleme(); break; 
	    case 4: karneolusturma(); break;
		case 5: ogrenciisleriotomasyonu(); break;
		case 6: break;
		default: 
		cout<<"L�ften 1 ile 6 Aras�nda Bir Say� Giriniz: ";
		cin>>secim;
		goto A; 
    } 
}

int main()
{
	//system("color F0");
	setlocale(LC_ALL, "Turkish"); //T�rk�e karakterler i�in kulland�k.
	ogrenciisleriotomasyonu();
}
