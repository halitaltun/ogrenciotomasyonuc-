#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Deðiþkenleri tanýmladýk
string ogrenciadi, ogrencisoyadi, ogrencibolum, ogretimelemaniadi, ogretimelemanisoyadi, ogretimelemanibolum, dersadi;
int ogrencino, ogrencisinif, ogretimelemanisicilno, derssaat;
double ortalama, vize, final; 
float derskredi;
int secim=0;

void ogrencimodulu();
void ogretimelemanimodulu();
void dersmodulu();
void notgirismodulu();
//Menüyü oluþturduk
void ogrenciisleriotomasyonu()
{
	system("cls"); //Console ekraný temizler.
	cout<<"Öðrenci Ýþleri Otomasyonu"<<endl;
    cout << "1. Öðrenci Modülü\n" 
    << "2. Öðretim Elemaný Modülü\n" 
    << "3. Ders Modülü\n" 
    << "4. Not Giriþ Modülü\n" 
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
		cout<<"Lüften 1 ile 5 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A; 
	} 
}
//Öðrenci Modülü dosyasýnýn satýr sayýsýný hasaplayan fonksiyon
int satirsayisi(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");
	
	char ch;
    while(!dosya.eof())  //bu döngü dosya sonuna gelene kadar dosyayý okur
    {
        dosya.get(ch); //okuma iþlemi get(); ile yapýlýr
        if(ch=='\n'){ //Eðer ch ifadesi boþluða denk gelirse satýr sayýsýný 1 arttýrýyoruz.
			satirsayisi++;
		}
  	}
	return satirsayisi;
}
//Öðrenci bilgilerinin kayýt edildiði fonksiyon 
void ogrencikayit(){
	int N;
	
	ifstream dosya;
	ofstream dosya1;
	dosya.open("Öðrenci Modülü.txt");
	dosya1.open("Öðrenci Modülü1.txt"); 
	for(int j=1; j<satirsayisi(); j++){
		dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;  
		dosya1 <<ogrenciadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
	}

    cout << "Kaç Adet Öðrenci Gireceksiniz: "; 
    cin >> N;
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". Öðrencinin Adýný giriniz: "; 
        cin >> ogrenciadi; 
        cout << i + 1 << ". Öðrencinin Soyadýný giriniz: "; 
        cin >> ogrencisoyadi;
        cout << i + 1 << ". Öðrencinin Okul numarasýný giriniz: "; 
        cin >> ogrencino;
		cout << i + 1 << ". Öðrencinin Bölümü: "; 
        cin >> ogrencibolum; 
		cout << i + 1 << ". Öðrencinin Sýnýfý: "; 
        cin >> ogrencisinif;
		
		dosya1 <<ogrenciadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullandýk ve dosyaya bilgileri kaydektik.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
    } 
	
	dosya.close();//dosyayý kapattýk.
	dosya1.close();//dosyayý kapattýk.

	remove("Öðrenci Modülü.txt");
	rename("Öðrenci Modülü1.txt","Öðrenci Modülü.txt");
	ogrenciisleriotomasyonu();	
}

//Öðrenciyi numarasýna göre arayan fonksiyon
void ogrencinumarasinagorearama(){
	int arananno, kontrol=0, secenek;
 	
	A:
	cout<<"Aradýðýnýz Öðrencinin Numarasýný Giriniz: ";
	cin>>arananno;
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");

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
		cout<<"Bu Numarada Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðrenciyi adýna göre arayan fonksiyon
void ogrenciadinagorearama(){
	int kontrol=0, secenek;
	string arananad;
	
	A:
	cout<<"Aradýðýnýz Öðrencinin Adýný Giriniz: ";
	cin>>arananad;
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");
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
		cout<<"Bu Ýsimde Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðrenci arama menüsü
void ogrenciarama(){
	system("cls"); //Console ekraný temizler.
	cout<<"Öðrenci arama"<<endl;
    cout << "1. Öðrenci numarasýna göre\n" 
    << "2. Öðrenci adýna göre\n" 
    << "3. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 4 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A; 
	}  			
}
//Öðrenciyi bölümüne göre listeleme
void bolumegorelisteleme(){
	int kontrol=0, secenek;
	string arananbolum;
	
	A:
	cout<<"Hangi Bölümden Öðrenci Arýyorsunuz: ";
	cin>>arananbolum;
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");
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
		cout<<"Bu Bölümden Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðrenciyi sýnýfýna göre listeleme
void sinifagorelisteleme(){
	int kontrol=0, secenek, aranansinif;
	
	A:
	cout<<"Hangi Sýnýftan Öðrenci Arýyorsunuz: ";
	cin>>aranansinif;
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");
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
		cout<<"Bu Sýnýftan Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðrenci listeleme menüsü
void ogrencilisteleme(){
	system("cls");
	cout<<"Öðrenci Listeleme"<<endl;
    cout << "1. Bölüme göre listeleme\n" 
    << "2. Sýnýfa göre listeleme\n" 
    << "3. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 4 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A;   
    } 
}
//Öðrenci bilgilerinin güncellendiði fonksiyon
void ogrencibilgileriduzeltme(){
	int arananno, kontrol=0, secenek;
	ifstream dosya;
	ofstream dosya1;

	A:
	cout<<"Güncellenecek Öðrencinin Numarasý: ";
	cin>>arananno;
	dosya.open("Öðrenci Modülü.txt");
	dosya1.open("Öðrenci Modülü1.txt"); 
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
			cout<<"Öðrencinin Adýný giriniz: ";
			cin>>ogrenciadi;
			cout << "Öðrencinin Soyadýný giriniz: "; 
	        cin >> ogrencisoyadi; 
	        cout << "Öðrencinin Okul numarasýný giriniz: "; 
	        cin >> ogrencino;
			cout << "Öðrencinin Bölümü: "; 
	        cin >> ogrencibolum;
			cout << "Öðrencinin Sýnýfý: "; 
	        cin >> ogrencisinif;
	        kontrol++;
		} 
	
		dosya1 <<ogrenciadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<ogrencisoyadi<<"\t";
		dosya1 <<ogrencino<<"\t";
		dosya1 <<ogrencibolum<<"\t";
		dosya1 <<ogrencisinif<<endl; 
	}

	dosya.close();
	dosya1.close();

	remove("Öðrenci Modülü.txt");
	rename("Öðrenci Modülü1.txt","Öðrenci Modülü.txt");
		
	if(kontrol==0){
		cout<<"Bu Numarada Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Güncelleme Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðrenci modulü menüsü
void ogrencimodulu(){ 
    system("cls");
	cout<<"Öðrenci Modülü"<<endl;
	
	cout << "1. Öðrenci Kayýt\n" 
        << "2. Öðrenci Arama\n" 
        << "3. Öðrenci Listeleme\n" 
        << "4. Öðrenci bilgileri düzeltme\n" 
        << "5. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 6 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A;  
    }
} 
//Öðretim Elemaný Modülü satýr sayýsýný hesaplayan fonksiyon
int satirsayisi1(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("Öðretim Elemaný Modülü.txt");
	
	char ch;
    while(!dosya.eof())  //bu döngü dosya sonuna gelene kadar dosyayý okur
    {
        dosya.get(ch);//okuma iþlemi get(); ile yapýlýr
        if(ch=='\n'){//Eðer ch ifadesi boþluða denk gelirse satýr sayýsýný 1 arttýrýyoruz.
			satirsayisi++;
		}
  	}
	return satirsayisi;
}
//Öðretim elemaný kayýt fonksiyonu
void ogretimelemanikayit(){
	int N, secenek;
	
	ifstream dosya; //ofstream sýnýfýndan bir nesne oluþturduk.
	ofstream dosya1;
	dosya.open("Öðretim Elemaný Modülü.txt"); //Öðretim Elemaný Modülü.txt isimli bir dosya açtýk.
	dosya1.open("Öðretim Elemaný Modülü1.txt"); 
	for(int j=1; j<satirsayisi1(); j++){
		dosya>>ogretimelemaniadi>>ogretimelemanisoyadi>>ogretimelemanisicilno>>ogretimelemanibolum;  
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl; 
	}
	
    cout << "Kaç Adet Öðretim Elemaný Gireceksiniz: "; 
    cin >> N; 
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". Öðretim Elemaný Adýný giriniz: "; 
        cin >> ogretimelemaniadi; 
        cout << i + 1 << ". Öðretim Elemaný Soyadýný giriniz: "; 
        cin >> ogretimelemanisoyadi;
        cout << i + 1 << ". Öðretim Elemaný Sicil numarasýný giriniz: "; 
        cin >> ogretimelemanisicilno;
		cout << i + 1 << ". Öðretim Elemaný Bölümü: "; 
        cin >> ogretimelemanibolum; 
		
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl;
	}
	
	dosya.close();
	dosya1.close();

	remove("Öðretim Elemaný Modülü.txt");
	rename("Öðretim Elemaný Modülü1.txt","Öðretim Elemaný Modülü.txt");
	
	ogrenciisleriotomasyonu();	
} 
//Öðretim elemaný arama fonksiyonu
void ogretimelemaniarama(){
	int kontrol=0, secenek, aranansicilno;
	
	A:
	cout<<"Aradýðýnýz Öðretim Elemanýnýn Sicil Numarasýný Giriniz: ";
	cin>>aranansicilno;
	ifstream dosya;
	dosya.open("Öðretim Elemaný Modülü.txt");
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
		cout<<"Bu Sicil Numarasýnda Öðretim Elemaný Bulunmamaktadýr!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðretim elemanýnýn bilgilerinin güncellendiði fonksiyon
void ogretimelemanibilgileriduzeltme(){
	int aranansicilno, kontrol=0, secenek;

	ifstream dosya;
	ofstream dosya1;
	A:
	cout<<"Güncellenecek Öðretim Elemanýnýn Sicil Numarasýný Giriniz: ";
	cin>>aranansicilno;
	dosya.open("Öðretim Elemaný Modülü.txt");
	dosya1.open("Öðretim Elemaný Modülü1.txt"); 
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
			cout<<"Öðretim Elemaný Adýný giriniz: ";
			cin>>ogretimelemaniadi;
			cout << "Öðretim Elemaný Soyadýný giriniz: "; 
	        cin >> ogretimelemanisoyadi; 
	        cout << "Öðretim Elemaný Sicil numarasýný giriniz: "; 
	        cin >> ogretimelemanisicilno;
			cout << "Öðretim Elemaný Bölümü: "; 
	        cin >> ogretimelemanibolum;
	        kontrol++;
		} 
	
		dosya1 <<ogretimelemaniadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<ogretimelemanisoyadi<<"\t";
		dosya1 <<ogretimelemanisicilno<<"\t";
		dosya1 <<ogretimelemanibolum<<endl; 
	}

	dosya.close();
	dosya1.close();

	remove("Öðretim Elemaný Modülü.txt");
	rename("Öðretim Elemaný Modülü1.txt","Öðretim Elemaný Modülü.txt");
	
	if(kontrol==0){
		cout<<"Bu Sicil Numarasýnda Öðretim Elemaný Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Güncelleme Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðretim elemaný listeleme fonksiyonu
void ogretimelemanilisteleme(){
	int kontrol=0, secenek; 
	string arananbolum;

	A:
	cout<<"Aradýðýnýz Öðretim Elemanýnýn Bölümünü Giriniz: ";
	cin>>arananbolum;
	ifstream dosya;
	dosya.open("Öðretim Elemaný Modülü.txt");
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
		cout<<"Bu Bölümden Öðretim Elemaný Bulunmamaktadýr!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Öðretim elemaný menüsü
void ogretimelemanimodulu(){
	system("cls");
	cout<<"Öðretim Elemaný Modülü "<<endl;
	
	cout << "1. Öðretim elemaný kayýt\n" 
    << "2. Öðretim elemaný arama\n" 
    << "3. Öðretim elemaný bilgileri düzeltme\n" 
    << "4. Öðretim elemaný listeleme\n"
    << "5. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 6 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A;  
    }
}
//Ders Modülü dosyasýnýn satýr sayýsýnýn hesapalandýðý fonksiyon
int satirsayisi2(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("Ders Modülü.txt");
	
	char ch;
    while(!dosya.eof())  //bu döngü dosya sonuna gelene kadar dosyayý okur
    {
        dosya.get(ch);//okuma iþlemi get(); ile yapýlýr
        if(ch=='\n'){//Eðer ch ifadesi boþluða denk gelirse satýr sayýsýný 1 arttýrýyoruz.
			satirsayisi++;
		}
  	}
  	dosya.close();
	return satirsayisi;
}
//Ders kayýtý yapýlan fonksiyon
void derskayit(){
	int N;
	
	ifstream dosya; //ofstream sýnýfýndan bir nesne oluþturduk.
	dosya.open("Ders Modülü.txt"); //Ders Modülü.txt isimli bir dosya açtýk.
	ofstream dosya1;
	dosya1.open("Ders Modülü1.txt"); 
	for(int j=1; j<satirsayisi2(); j++){
		dosya>>dersadi>>derssaat>>derskredi; 
		dosya1 <<dersadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}
	
    cout << "Kaç Adet Ders Gireceksiniz: "; 
    cin >> N; 
    for (int i = 0; i < N; i++) 
    { 
        cout << i + 1 << ". Ders Adýný giriniz: "; 
        cin >> dersadi; 
        cout << i + 1 << ". Ders Saatini giriniz: "; 
        cin >> derssaat;
        cout << i + 1 << ". Ders Kredisini giriniz: "; 
        cin >> derskredi;
		
		dosya1 <<dersadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}
	
	dosya.close();
	dosya1.close();

	remove("Ders Modülü.txt");
	rename("Ders Modülü1.txt","Ders Modülü.txt");
	ogrenciisleriotomasyonu();	
}
//Ders bilgilerinin güncellendiði fonksiyon
void dersbilgileriduzenleme(){
	int kontrol=0, secenek;
	string arananders;

	ifstream dosya;
	ofstream dosya1;
	A:
	cout<<"Güncellenecek Dersin Adýný Giriniz: ";
	cin>>arananders;
	dosya.open("Ders Modülü.txt");
	dosya1.open("Ders Modülü1.txt"); 
	for(int j=1; j<satirsayisi2(); j++){
		dosya>>dersadi>>derssaat>>derskredi; 
		if(arananders==dersadi){
			cout<<"Eski Bilgiler"<<endl;
	    	cout<<"Ders Adý: "<<dersadi<<endl;
	    	cout<<"Ders Saat: "<<derssaat<<endl;
			cout<<"Ders Kredi: "<<derskredi<<endl;
	    	cout<<"================================="<<endl;
	    	
			cout<<"Yeni Bilgiler"<<endl;
			cout<<"Dersin Adýný giriniz: ";
			cin>>dersadi;
			cout << "Dersin Saatini giriniz: "; 
	        cin >> derssaat; 
	        cout << "Dersin Kredisini giriniz: "; 
	        cin >> derskredi;
	        kontrol++;
		} 
	
		dosya1 <<dersadi<<"\t"; //Burada oluþturduðumuz nesneyi cout gibi kullanýyoruz.
		dosya1 <<derssaat<<"\t";
		dosya1 <<derskredi<<endl;
	}

	dosya.close();
	dosya1.close();

	remove("Ders Modülü.txt");
	rename("Ders Modülü1.txt","Ders Modülü.txt");
	
	if(kontrol==0){
		cout<<"Bu Ýsimde Ders Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
	B:	
	cout<<"Tekrar Güncelleme Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
	cout<<"Aradýðýnýz Dersin Adýný Giriniz: ";
	cin>>arananders;
	ifstream dosya;
	dosya.open("Ders Modülü.txt");
    for(int j=1; j<satirsayisi2(); j++){
    	dosya>>dersadi>>derssaat>>derskredi;
	    if(arananders==dersadi){
	    	cout<<"Ders Adý: "<<dersadi<<endl;
	    	cout<<"Ders Saat: "<<derssaat<<endl;
			cout<<"Ders Kredi: "<<derskredi<<endl;
	    	cout<<"================================="<<endl;
	    	kontrol++;
		}
	}
	dosya.close();
	if(kontrol==0){
		cout<<"Bu Ýsimde Ders Bulunmamaktadýr!"<<endl;
	} 
	kontrol=0;
	B:	
	cout<<"Tekrar Arama Yapmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
	dosya.open("Ders Modülü.txt");
    for(int j=1; j<satirsayisi2(); j++){
    	dosya>>dersadi>>derssaat>>derskredi;
	    cout<<"Ders Adý: "<<dersadi<<endl;
	    cout<<"Ders Saati: "<<derssaat<<endl;
		cout<<"Ders Kredi: "<<derskredi<<endl;
	    cout<<"================================="<<endl;
	}

	A:	
	cout<<"Devam Etmek Ýçin 1 Basýnýz: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();	
}
//Ders modulü menüsü
void dersmodulu(){
	system("cls");
	cout<<"Ders Modülü "<<endl;
	
	cout << "1. Ders kayýt\n" 
    << "2. Ders arama\n" 
    << "3. Ders bilgileri düzeltme\n" 
    << "4. Ders listeleme\n"
    << "5. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 6 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A;  
    }	
}
//Öðrenci Ders Ekleme dosyasýnýn satýr sayýsýný hesaplayan fonksiyon
int satirsayisi3(){
	int satirsayisi=0;
	
	ifstream dosya;
	dosya.open("Öðrenci Ders Ekleme.txt");
	
	char ch;
    while(!dosya.eof())  //bu döngü dosya sonuna gelene kadar dosyayý okur
    {
        dosya.get(ch);//okuma iþlemi get(); ile yapýlýr
        if(ch=='\n'){//Eðer ch ifadesi boþluða denk gelirse satýr sayýsýný 1 arttýrýyoruz.
			satirsayisi++;
		}
  	}
  	dosya.close();
	return satirsayisi;
}
//Öðrenciye ders ekleme fonksiyonu
void ogrencidersekleme(){
	int dersadet, satir=0, dersnumara, satir1=0;;
	string dersadidizi[satirsayisi2()];
	int derssaatdizi[satirsayisi2()], derskredidizi[satirsayisi2()];
	ofstream dosya1;
	dosya1.open("Öðrenci Ders Ekleme.txt");
	ifstream dosya;
	dosya.open("Öðrenci Modülü.txt");
	ifstream dosya2;
	dosya2.open("Ders Modülü.txt");
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
		    cout<<"Ders Adý: "<<dersadidizi[j-1]<<endl;
		    cout<<"Ders Saati: "<<derssaatdizi[j-1]<<endl;
			cout<<"Ders Kredi: "<<derskredidizi[j-1]<<endl;
		    cout<<"================================="<<endl;
		}    	
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
		cout<<"Öðrenci Bilgileri"<<endl;
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
		cout<<"Lütfen "<<satir<<" den Fazla Ders Girmeyiniz!"<<endl;
		cout<<ogrencino<<" Numaralý Öðrenci Ýçin Kaç Tane Ders Gireceksiniz: ";
		cin>>dersadet;
		if(dersadet>satir){
			goto B;
		}
		else{ 
        	for (int j = 0; j < dersadet; j++) 
        	{ 
        		C:
            	cout << ogrencino << " Numaralý Öðrencinin " << j + 1 << ". Dersinin Numarasýný Giriniz:"; 
            	cin >> dersnumara;
            	if(dersnumara<=satir)
            	{
            		dosya1<<dersadidizi[dersnumara-1]<<endl;
				}
				else{
					cout<<dersnumara<<" Numaralý Ders Yok Lütfen Olan Derslerden Seçiniz!"<<endl;
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
	cout<<"Devam Etmek Ýçin 1 Basýnýz: ";
	cin>>secim;
	if(secim!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//Öðrenci not giriþ fonksiyonu
void ogrencinotgirisi(){
	int secenek;
	ifstream dosya;
	ofstream dosya1;
	dosya.open("Öðrenci Ders Ekleme.txt");
	dosya1.open("Öðrenci Not Giriþ.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
		dosya1<<ogrenciadi<<"\t";
	    dosya1<<ogrencisoyadi<<"\t";
	    dosya1<<ogrencino<<"\t";
	    dosya1<<ogrencibolum<<"\t";
	    dosya1<<ogrencisinif<<endl;
    	cout<<ogrencino<<" Numaralý Öðrencinin Ýçin Not Giriþi"<<endl;
    	cout<<"Lütfen Notlarý 100 den Büyük Girmeyiniz!"<<endl;
		for(int i=1; i<satirsayisi2(); i++){
			dosya>>dersadi;
			if(dersadi!="null"){
				C:
				cout<<dersadi<<" Vize Notunu Giriniz: ";
				cin>>vize;
				if(vize>100){
					cout<<"Lütfen Notlarý 100 den Büyük Girmeyiniz!"<<endl;
					goto C;
				}
				B:
				cout<<dersadi<<" Final Notunu Giriniz: ";
				cin>>final;
				if(final>100){
					cout<<"Lütfen Notlarý 100 den Büyük Girmeyiniz!"<<endl;
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
	cout<<"Devam Etmek Ýçin 1 Basýnýz: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//Öðrencinin aldýðý derslerin listelendiði fonksiyon
void ogrenciderslisteleme(){
	int secenek; 
	ifstream dosya;
	dosya.open("Öðrenci Ders Ekleme.txt");
    for(int j=1; j<satirsayisi(); j++){
    	dosya>>ogrenciadi>>ogrencisoyadi>>ogrencino>>ogrencibolum>>ogrencisinif;
    	cout<<ogrencino<<" Numaralý Öðrencinin Aldýðý Dersler"<<endl;
		for(int i=1; i<satirsayisi2(); i++){
			dosya>>dersadi;
			if(dersadi!="null"){
				cout<<"Ders Adý: "<<dersadi<<endl;				
			}
		}
		cout<<"================================="<<endl;
	}
	dosya.close();
	A:	
	cout<<"Devam Etmek Ýçin 1 Basýnýz: ";
	cin>>secenek;
	if(secenek!=1){
		goto A;
	}
	ogrenciisleriotomasyonu();
}
//Öðrencinin karnesini oluþturan fonksiyon
void karneolusturma(){
	int arananno, kontrol=0, satirders=0, secenek;
	string dersadidizi[satirsayisi2()];
	double vizedizi[satirsayisi2()], finaldizi[satirsayisi2()], ortalamadizi[satirsayisi2()];
	char ch;
		
	ifstream dosya;
	ofstream dosya1;
	ifstream dosya2;
	A:
	dosya.open("Öðrenci Not Giriþ.txt");
	dosya1.open("Öðrenci Karne.txt");
	dosya2.open("Öðrenci Karne.txt");			
	cout<<"Karnesini Ýstediðiniz Öðrencinin Numarasýný Giriniz: ";
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
							dosya1<<"Kaldý"<<endl;
						}
					}
					else{
						dosya1<<"FF\t";
						dosya1<<"Kaldý"<<endl;	
					}
				}
			}
			kontrol++;				
		}
		satirders=0;
	}	
	
	if(kontrol==0){
		cout<<"Bu Numarada Öðrenci Bulunmamaktadýr!"<<endl;
	}
	kontrol=0;
    while(!dosya2.eof())  //bu döngü dosya sonuna gelene kadar dosyayý okur
    {
        dosya2.get(ch);//okuma iþlemi get(); ile yapýlýr
        cout<<ch;
  	}
  	dosya.close();
	dosya1.close();
	dosya2.close();
	B:	
	cout<<"Tekrar Karne Oluþturmak Ýçin 1'e Baþa Dönmek Ýçin 2'ye Basýnýz: ";
	cin>>secenek;
	if(secenek<3){
		switch (secenek) 
	    { 
		    case 1: 
			system("cls"); //Console ekraný temizler.
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
//Not giriþ modülü menüsü
void notgirismodulu(){
	system("cls");
	cout<<"Not Giriþ Modülü "<<endl;
	
	cout << "1. Öðrenciye ders ekleme\n" 
    << "2. Öðrencinin aldýðý ders için not giriþi \n" 
    << "3. Öðrenci ders listeleme \n" 
    << "4. Öðrenci karnesi oluþturma ve görselleþtirme\n"
    << "5. Öðrenci Ýþleri Otomasyonu\n" 
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
		cout<<"Lüften 1 ile 6 Arasýnda Bir Sayý Giriniz: ";
		cin>>secim;
		goto A; 
    } 
}

int main()
{
	//system("color F0");
	setlocale(LC_ALL, "Turkish"); //Türkçe karakterler için kullandýk.
	ogrenciisleriotomasyonu();
}
