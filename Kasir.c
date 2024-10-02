#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char nama_file[100] = "nota.txt";
FILE *fp;
struct Login{
	char nama[50];
	char pass[50];
}a;

struct Kasir{
	char kode[10];
	int jml;
}b[10];

int pilih;
int i,j,x;

char data_barang[20][4][100] = {
		"001" , "Milo Bubuk" , "3000", "50",
		"002" , "Mie Sedaap" , "2500", "120",
		"003" , "Mie Indomie" , "2500", "120",
		"004" , "Susu Coklat" , "2000", "100",
		"005" , "Gula Pasir" , "12000", "30",
		"006" , "Minyak Goreng" , "20000", "110",
		"007" , "Teh Sariwangi" , "5000", "50",
		"008" , "Kopi Hitam" , "5000", "70",
		"009" , "Kopi Susu" , "2500", "125",
		"010" , "Chocolatos" , "2500", "75",
	};

void login() {
	system("cls");
	printf("LOGIN\n\n");
	printf("Username : ");
	gets(a.nama);
	printf("Password : ");
	gets(a.pass);
	
	if(strcmp(a.pass,"123")==0) {
		menu_utama();
	} else {
		printf("\n!!! USERNAME ATAU PASSWORD SALAH !!!\n");
		printf("Masukkan ulang Username dan Password\n");
		system("pause");
		login();
	}
}

void menu_utama(){
	system ("cls");
	printf("===========================================================\n");
	printf("\t\tTOKO ASD JAYA\n");
	printf("\t\tKasir : %s\n", a.nama);
	printf("===========================================================\n");

	printf("Menu:\n\n");
	printf("1. Tampilkan Data Barang\n");
	printf("2. Tambah Data Barang\n");
	printf("3. Transaksi\n");
	printf("4. Keluar\n");
	
	printf("===========================================================\n");
	printf("Pilih menu: ");
	scanf("%d",&pilih);

	if (pilih == 1){
		menu1();
	} else if (pilih == 2){
		menu2();
	} else if (pilih == 3){
		menu3();
	} else if (pilih == 4){
		keluar();
	} else{
		printf("Menu tidak ada!!!\n");
		system("pause");
		menu_utama();
	}
}

void kodee(){
	system ("cls");
	char data_barang[20][4][100] = {
		"001" , "Milo Bubuk" , "3000", "50",
		"002" , "Mie Sedaap" , "2500", "120",
		"003" , "Mie Indomie" , "2500", "120",
		"004" , "Susu Coklat" , "2000", "100",
		"005" , "Gula Pasir" , "12000", "30",
		"006" , "Minyak Goreng" , "20000", "110",
		"007" , "Teh Sariwangi" , "5000", "50",
		"008" , "Kopi Hitam" , "5000", "70",
		"009" , "Kopi Susu" , "2500", "125",
		"010" , "Chocolatos" , "2500", "75",
	};
	
	printf("===========================================================\n");
   	printf("Data Barang Berdasarkan Kode\n");
   	printf("===========================================================\n");
	printf("Kode\tNama Barang\tHarga\tStock\n");
	printf("===========================================================\n");
	
	for(i=0; i<15; i++){
		
		for(j=0; j<4; j++){
			printf("%s\t",data_barang[i][j]);
		}
		printf("\n");
	}
	
	printf("===========================================================\n");
}

void hargaa(){
	system ("cls");
	int i,j, harga[20],p;
	char q[50], r[50], s[50];
	printf("===========================================================\n");
   	printf("Lihat Data Barang Berdasarkan Harga\n");
   	printf("===========================================================\n");
	
	for (i=0; i<15; i++){
// atoi untuk mengubah string menjadi integer
		harga[i] = atoi(data_barang[i][2]);
    	for(j=i; j>0 && harga[j-1] > harga[j]; j--){
      		p = harga[j];
      		harga[j] = harga[j - 1];
      		harga[j-1] = p;
      		
      		strcpy(q, data_barang[j][0]);
      		strcpy(data_barang[j][0], data_barang[j-1][0]);
      		strcpy(data_barang[j-1][0], q);
      		
      		strcpy(r, data_barang[j][1]);
      		strcpy(data_barang[j][1], data_barang[j-1][1]);
      		strcpy(data_barang[j-1][1], r);
      		
      		strcpy(s, data_barang[j][3]);
      		strcpy(data_barang[j][3], data_barang[j-1][3]);
      		strcpy(data_barang[j-1][3], s);
   		}
	}
	
	printf("Kode\tNama Barang\tHarga\tStock\n");
	printf("===========================================================\n");
	
	for (i=0; i<15; i++){
 		printf("%s\t%s\t%d\t%s\n",data_barang[i][0], data_barang[i][1],harga[i],data_barang[i][3]);
	}
	
	system("pause");
	menu_utama();
}

void menu1(){
	int pil;
	system ("cls");
	
	printf("===========================================================\n");
   	printf("Menu Lihat Data Barang\n");
   	printf("===========================================================\n");
	
	printf("1. Berdasarkan Kode\n");
	printf("2. Berdasarkan Harga\n");
	printf("===========================================================\n");
	printf("Pilih menu: ");
	scanf("%d",&pil);
	if (pil == 1){
		kodee();
		system("pause");
		menu_utama();
	} else if (pil == 2){
		hargaa();
	}  else{
		printf("Menu tidak ada!!!\n");
		system("pause");
		menu1();
	}
}

void menu2(){
	system ("cls");
	printf("===========================================================\n");
   	printf("Menu Tambah Data Barang\n");
   	printf("===========================================================\n");
   	
   	printf("Urutan barang : ");
	scanf("%d", &x);
   	
	printf("Masukkan kode barang : ");
	scanf("%s", &data_barang[x-1][0]);
	printf("Masukkan nama barang: ");
	scanf(" %[^\n]", &data_barang[x-1][1]);
	printf("Masukkan harga barang : ");
	scanf("%s", &data_barang[x-1][2]);
	printf("Masukkan jumlah : ");
	scanf("%s", &data_barang[x-1][3]);
	
	printf("===========================================================\n");
    system("pause");
    menu_utama();
}

void menu3(){
	kodee();
	printf("===========================================================\n");
	printf("\t\tTOKO ASD JAYA\n");
	printf("\t\tKasir : %s\n", a.nama);
	printf("===========================================================\n");
	
	fp = fopen(nama_file, "w");
	fprintf(fp, "===========================================================\n");
	fprintf(fp, "\t\tTOKO ASD JAYA\n");
	fprintf(fp, "\t\tKasir : %s\n", a.nama);
	fprintf(fp, "===========================================================\n");
	fclose(fp);
	
	int m,n, jumlah, total, bayar, kembali, kurang;
	char yn[5];
	printf("Jumlah Jenis Barang : ");
	scanf("%d", &m);
	
	fp = fopen(nama_file, "a+");
	fprintf(fp, "Jumlah Jenis Barang : %d", m);
	fclose(fp);
	
	for (n=0; n<m; n++){
		printf("\nBarang ke-%d\n", n+1);
		printf("Kode barang \t: ");
        scanf("%s", &b[n].kode);
        printf("Jumlah \t\t: ");
        scanf("%d", &b[n].jml);
        
        fp = fopen(nama_file, "a+");
		fprintf(fp, "\nBarang ke-%d\n", n+1);
		fprintf(fp, "Kode barang \t: %s\n", b[n].kode);
		fprintf(fp, "Jumlah \t\t: %d\n", b[n].jml);
		fclose(fp);
		
        for(i=0; i<15; i++){
        //atoi untuk mengubah string menjadi integer
        //strcmp untuk membandingkan string
            int harga = atoi(data_barang[i][2]);
            int stok = atoi(data_barang[i][3]);
            if(strcmp(b[n].kode, data_barang[i][0])==0){
            	jumlah = b[n].jml * harga;
            	printf("Nama \t\t: %s\n", data_barang[i][1]);
            	printf("Harga \t\t: %d\n", harga);
            	printf("Jumlah \t\t: %d\n", jumlah);
            	
            	fp = fopen(nama_file, "a+");
            	fprintf(fp, "Nama \t\t: %s\n", data_barang[i][1]);
				fprintf(fp, "Harga \t\t: %d\n", harga);
            	fprintf(fp, "Jumlah \t\t: %d\n", jumlah);
				fclose(fp);
			}
		}
		total += jumlah;
	}
	
	printf("\nTOTAL \t\t: %d\n", total);
	printf("BAYAR \t\t: ");
	scanf("%d", &bayar);
	
	fp = fopen(nama_file, "a+");
	fprintf(fp, "\nTOTAL \t\t: %d\n", total);
	fprintf(fp, "BAYAR \t\t: %d\n", bayar);
	fclose(fp);
		
	kembali = bayar - total;
	if (kembali < 0){
		kurang = -1 * kembali;
		printf("\nMaaf uang kurang : %d\n", kurang);
		printf("Mau bayar kuekurangan [y/n] : ");
		scanf("%s", &yn);
		
		fp = fopen(nama_file, "a+");
		fprintf(fp, "\nKurang \t\t: %d\n", total);
		fclose(fp);
	
		if (strcmp(yn, "y")==0 || strcmp(yn, "Y")==0){
			printf("BAYAR \t\t: ");
			scanf("%d", &bayar);
			
			kembali = bayar - kurang;
			printf("KEMBALIAN \t: %d", kembali);
			
			fp = fopen(nama_file, "a+");
			fprintf(fp, "BAYAR \t\t: %d\n", bayar);
			fprintf(fp, "KEMBALIAN \t: %d\n", kembali);
			fclose(fp);
		
			printf("\n\nTERIMKASIH ATAS KUNJUNGAN ANDA\n");
		} else {
			printf("\nMaaf tidak bisa hutang\n");
			printf("\n\nTERIMKASIH ATAS KUNJUNGAN ANDA\n\n");
			
			fp = fopen(nama_file, "a+");
			fprintf(fp, "\nTIDAK JADI MEMBELI\n");
			fclose(fp);
		}
	} else {
		printf("KEMBALIAN \t: %d", kembali);
		printf("\n\nTERIMKASIH ATAS KUNJUNGAN ANDA\n\n");
		
		fp = fopen(nama_file, "a+");
		fprintf(fp, "KEMBALIAN \t: %d\n", kembali);
		fclose(fp);
	}
	
	system("pause");
	menu_utama();
}


void keluar(){
	system("cls");
	printf("\nSEE YOU ^_^\n");
	exit(1);
}

void main(){
	login();
}
