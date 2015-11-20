#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <sys\stat.h>
////////////////////////////////////////////////
struct Dosya{
	char word[200];
	struct Dosya *onceki,*sonraki;
};
struct Dosya *ilk,*son;
void ekle(char *kelime);
void sil(char *kelime);
///////////////////////////////////////////////
void LineerquarativeOlustur();
void LineerKelimeSorgula();   
void LineerKelimeEkle();  
void LineerKelimeSil();
void LineerMenu();          
//////////////////////////////////////////////
void QuadraticquarativeOlustur();
void QuadraticKelimeSorgula();   
void QuadraticKelimeEkle();
void QuadraticKelimeSil();
void QuadraticMenu();           
//////////////////////////////////////////////
void DoublequarativeOlustur();  
void DoubleKelimeSorgula();     
void DoubleKelimeEkle();        
void DoubleKelimeSil();
void DoubleMenu();
//////////////////////////////////////////////
void AnaMenu();
void QuarativeOlustur();
void SozlukSec();
//////////////////////////////////////////////
void SorguLineerOlustur();
void SorguQuadOlustur();
void SorguDoubleOlustur();
void SorguMenu();
void SorguLineer();
void SorguQuad();
void SorguDouble();
///////////////////////////////////////////////
unsigned int Hash(char *);
int Hash2(char *);
unsigned int SorguHash (char *);
int ArtisBelirle();
int SorguArtisBelirle();
void AnaMenu();
int BuyukBul();
int SorguBuyukBul();
int SorguHashSize=SorguBuyukBul()+100+SorguArtisBelirle();
int HashArtis=600;
int HashSize=(int)(BuyukBul()+HashArtis+ArtisBelirle());
int KelimeBoy=(int)BuyukBul();
/////////////////////////////////////////////
char *BirinciKelime(char *);
char *IkinciKelime(char *);
char *SagKes(char *);
/////////////////////////////////////////////
/////////////////////////////////////////////

main()
{
	setlocale(LC_ALL,"Turkish");
	system("color 1F");
	SozlukSec();
}
int ArtisBelirle()
{
	int Artis=0;
	if(BuyukBul()%2==0)
	{
		Artis=1;
	}
	return Artis;
}
int SorguArtisBelirle()
{
	int Artis=0;
	if(SorguBuyukBul()%2==0)
	{
		Artis=1;
	}
	return Artis;
}
void QuarativeOlustur()
{
	LineerquarativeOlustur();
	system("pause");
	QuadraticquarativeOlustur();
	system("pause");
	DoublequarativeOlustur();
	system("pause");
}
void SozlukSec()
{
	nokta1:
	int islem;
	printf("\n\n");
	printf("\t\t********** ISLEM YAPILACAK DOSYA SEC ***********\n");
	printf("\t\t********** [1] sorgu.txt ***********************\n");
    printf("\t\t********** [2] dictionary.txt ******************\n");
    printf("\t\t********** [3] cikis ***************************\n");
    
    printf("\nislem: ");scanf("%d",&islem);
    switch(islem)
	{
		case 1:
			system("cls");
			SorguMenu();
			break;
		case 2:
			system("cls");
			AnaMenu();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			system("pause");
			system("cls");
			goto nokta1;

	}
    
}
void SorguMenu()
{
	nokta1:
	int islem;
	printf("\n\n");
	printf("\t\t********** ISLEM SECINIZ *******************************\n");
    printf("\t\t********** [1] LINEER KELIME SORGULAMA******************\n");
    printf("\t\t********** [2] QUADRATIC KELIME SORGULAMA **************\n");
    printf("\t\t********** [3] DOUBLE KELIME SORGULAMA *****************\n");
    printf("\t\t********** [4] UST MENUYE DON **************************\n");
    printf("\t\t********** [5] CIKIS ***********************************\n");
    printf("\nislem: ");scanf("%d",&islem);
    switch(islem)
	{
		case 1:
			system("cls");
			SorguLineer();
			goto nokta1;
			break;
		case 2:
			system("cls");
			SorguQuad();
			goto nokta1;
			break;
		case 3:
			system("cls");
			SorguDouble();
			goto nokta1;
			break;
		case 4:
			system("cls");
			SozlukSec();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			system("pause");
			system("cls");
			goto nokta1;

	}
}
void AnaMenu()
{
	
	
	int islem;
	nokta1:
	printf("\n\n");
	printf("\t\t********** dictionary.txt islemler***********\n");
	printf("\t\t********** [1] BAGIL DOSYA OLUSTUR***********\n");
	printf("\t\t********** [2] LINEER ***********************\n");
    printf("\t\t********** [3] QUADRATIC ********************\n");
    printf("\t\t********** [4] DOUBLE ***********************\n");
    printf("\t\t********** [5] CIKIS ************************\n");
	printf("\nislem: ");scanf("%d",&islem);

	switch(islem)
	{
		case 1:
			system("cls");
			QuarativeOlustur();
			goto nokta1;
			break;
		case 2:
			system("cls");
			LineerMenu();
			goto nokta1;
			break;
		case 3:
			system("cls");
			QuadraticMenu();
			goto nokta1;
			break;
		case 4:
			system("cls");
			DoubleMenu();
			goto nokta1;
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			system("pause");
			system("cls");
			goto nokta1;

	}
}
void LineerMenu()
{
	int islem;
	nokta1:
	printf("\n\n");
	printf("\t\t********** SOZLUK UYGULAMASI *****************\n");
	printf("\t\t********** [1] Kelime Sorgula ****************\n");
    printf("\t\t********** [2] Kelime Ekle *******************\n");
    printf("\t\t********** [3] Kelime Sil ********************\n");
    printf("\t\t********** [4] Ust Menuye Don ****************\n");
    printf("\t\t********** [5] Cikis *************************\n");
	printf("\nislem: ");scanf("%d",&islem);

	switch(islem)
	{
		case 1:
			system("cls");
			LineerKelimeSorgula();
			goto nokta1;
			break;
		case 2:
			system("cls");
			LineerKelimeEkle();
			goto nokta1;
			break;
		case 3:
			system("cls");
			LineerKelimeSil();
			goto nokta1;
			break;
		case 4:
			AnaMenu();
			break;
		case 5:
			exit(0);
			break;

		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			exit(0);

	}
}
void QuadraticMenu()
{
	int islem;
	nokta1:
	printf("\n\n");
	printf("\t\t********** SOZLUK UYGULAMASI *****************\n");
	printf("\t\t********** [1] Kelime Sorgula ****************\n");
    printf("\t\t********** [2] Kelime Ekle *******************\n");
    printf("\t\t********** [3] Kelime Sil ********************\n");
    printf("\t\t********** [4] Ust Menuye Don ****************\n");
    printf("\t\t********** [5] Cikis *************************\n");
	printf("\nislem: ");scanf("%d",&islem);

	switch(islem)
	{
		case 1:
			system("cls");
			QuadraticKelimeSorgula();
			goto nokta1;
			break;
		case 2:
			system("cls");
			QuadraticKelimeEkle();
			goto nokta1;
			break;
		case 3:
			system("cls");
			QuadraticKelimeSil();
			goto nokta1;
			break;
		case 4:
			AnaMenu();
			break;
		case 5:
			exit(0);
			break;

		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			exit(0);

	}

}
void DoubleMenu()
{
	int islem;
	nokta1:
	printf("\n\n");
	printf("\t\t********** SOZLUK UYGULAMASI *****************\n");
	printf("\t\t********** [1] Kelime Sorgula ****************\n");
    printf("\t\t********** [2] Kelime Ekle *******************\n");
    printf("\t\t********** [3] Kelime Sil ********************\n");
    printf("\t\t********** [4] Ust Menuye Don ****************\n");
    printf("\t\t********** [5] Cikis *************************\n");
	printf("\nislem: ");scanf("%d",&islem);

	switch(islem)
	{
		case 1:
			system("cls");
			DoubleKelimeSorgula();
			goto nokta1;
			break;
		case 2:
			system("cls");
			DoubleKelimeEkle();
			goto nokta1;
			break;
		case 3:
			system("cls");
			DoubleKelimeSil();
			goto nokta1;
			break;
		case 4:
			AnaMenu();
			break;
		case 5:
			exit(0);
			break;

		default:
			printf("Yanlis Secim Yaptiniz Tekrar Deneyin!!\n");
			exit(0);

	}
}
int BuyukBul()
{
	FILE *d;
	char *kelime[100000];
	int i=0,sayac;
	if((d=fopen("dictionary.txt","r"))==NULL)
	{
		printf("dictionary.txt okuma modunda acilmadi!!\n");
	}
	while(!feof(d))
	{
		fscanf(d,"%[^\n]\n",&kelime[i]);
		i++;
		sayac=i;
	}
	fclose(d);
	return sayac;

}
int SorguBuyukBul()
{
	FILE *d;
	char *kelime[100000];
	int i=0,sayac;
	if((d=fopen("sorgu.txt","r"))==NULL)
	{
		printf("sorgu.txt okuma modunda acilmadi!!\n");
	}
	while(!feof(d))
	{
		fscanf(d,"%[^\n]\n",&kelime[i]);
		i++;
		sayac=i;
	}
	fclose(d);
	return sayac;

}
////////////////////////////////////////////////////////
unsigned int Hash (char *key)
{
	
  	unsigned int toplam = 0;
  	int uzunluk=strlen(key);
  	for (int i=0; i<uzunluk; i++)
  	{
  		toplam=toplam+(key[uzunluk-(i+1)]*pow(2,i));
  	}
  	return toplam % HashSize;
}
int Hash2 (char *key)
{
  	int toplam = 0;
  	int uzunluk=strlen(key);
  	for (int i=0; i<uzunluk; i++)
  	{
  		toplam=toplam+key[uzunluk-(i+1)];
  	}

  	return 11-(toplam%11)+1;
}
//////////////////////////////////////////////
unsigned int SorguHash (char *key)
{
	//////////////////////////
  	unsigned int toplam = 0;
  	int uzunluk=strlen(key);
  	for (int i=0; i<uzunluk; i++)
  	{
  		toplam=toplam+(key[uzunluk-(i+1)] * pow(2,i));
  	}
  	return toplam % SorguHashSize;
}
//////////////////////////////////////////////
void LineerquarativeOlustur()
{
	struct stat status;
	FILE *dic,*rel;
	char ing[100],tr[100],kelime[200],c;
	int Adr,Temp,cakisma=0;
	dic = fopen("dictionary.txt", "r");
	rel = fopen("lineer.txt", "w+");

	for(int i=0; i<=HashSize; i++)
	{
		fseek(rel,i*200,0);
		fputc('*', rel );
	}
	time_t s,s2;
	time(&s);
	printf("Lineerquarative Olusturuluyor...\n");
	for(int i=0; i<KelimeBoy; i++)
	{

		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ing,BirinciKelime(kelime));
		strcpy(tr,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ing);
		//printf("%s\n",tr);
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}
		Adr = Hash(ing);
		fseek(rel,Adr*200,0);
		c=fgetc(rel);
		Temp=Adr;
		while( c != '*')
		{
			cakisma++;
			Adr = (Adr + 1) % HashSize;
			if(Adr==Temp)
			{
				printf("lineer Dosya Dolu ! \n");
				break;
			}
			fseek(rel,Adr*200,0);
			c=fgetc(rel);
		}

		fseek(rel,Adr*200,0);
		fprintf(rel, "%s", ing);
		fprintf(rel, "  ");
		fprintf(rel, "%s", tr);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(rel),&status);
	fclose(dic);
	fclose(rel);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");
	
	//printf("\nLineerquarative Dosya Olustruldu\n");

}
//////////////////////////////////////////////
void LineerKelimeSorgula()
{
	FILE *rel;
	char sorgu[100],index[200],index2[100],index3[100],index4[100];
	int Adr=0;
	rel = fopen("lineer.txt", "r");
	fflush(stdin);
	printf("Kelimeyi Giriniz: ");gets(sorgu);
	Adr=Hash(sorgu);
	printf("Adres: %d\n",Adr);
	fseek(rel,Adr*200,0);
	
	fread(&index,sizeof(char),200,rel);
	strcpy(index,SagKes(index));
	strcpy(index3,BirinciKelime(index));
	while(strcmp(sorgu,index3)!=0)
	{
		Adr=(Adr+1) % HashSize;
		fseek(rel,Adr*200,0);
		fread(&index,sizeof(char),200,rel);
		strcpy(index,SagKes(index));
		strcpy(index3,BirinciKelime(index));
		printf("Adres: %d\n",Adr);
	}

	strcpy(index4,IkinciKelime(index));
	
	printf("Sonuc: %s\n",index4);
	fclose(rel);

}
///////////////////////////////////////////////////////////////////////////////////
void LineerKelimeEkle()
{
	
	FILE *dic;
	char ingilizce[100],turkce[100],c;
	int Adr;
	dic = fopen("dictionary.txt", "a+");
	fflush(stdin);
	printf("Eklenecek Kelimeyi Giriniz: ");gets(ingilizce);fflush(stdin);
	printf("Eklencek Kelimenin Turkcesini Giriniz: ");gets(turkce);
	fprintf(dic,"\n%s", ingilizce);
	fprintf(dic,"  ");
	fprintf(dic,"%s", turkce);
	fclose(dic);
	++KelimeBoy;
	LineerquarativeOlustur();
	system("cls");
	printf("%s  %s Kelimesi Basarili Bir Sekilde Eklenmistir\n",ingilizce,turkce);
}
//////////////////////////////////////////////////////////////////////////////////////////
void LineerKelimeSil()
{
	
	FILE *dic,*dic2;
	char kelime[200];
	int bul=0;
	char sorgu[200],index[200];
	int sayi;
	dic = fopen("dictionary.txt", "r");
	for(int i=0;i<=KelimeBoy;i++)
	{
		fscanf(dic,"%[^\n]\n",sorgu);
		ekle(sorgu);
	}
	fclose(dic);
	fflush(stdin);
	printf("Silinecek Kelimenin Ingilizcesini Giriniz: ");gets(kelime);
	sil(kelime);

	if((dic2 = fopen("dictionary.txt", "w+"))==NULL)
	{
		printf("Dosya Acilmadi!!\n");
	}
	struct Dosya *listele;
	
	listele=ilk;
	while(listele)
	{
		fprintf(dic2,"%s\n",listele->word);
		listele=listele->sonraki;
	}
	LineerquarativeOlustur();
	
}
void ekle(char *kelime)
{
	struct Dosya *ekle;
	ekle=(Dosya *) malloc(sizeof(struct Dosya));
	strcpy(ekle->word,kelime);
	if(ilk==NULL)
	{
		ilk=ekle;
		son=ekle;
		ilk->sonraki=NULL;
		ilk->onceki=NULL;
	}
	else
	{
		son->sonraki=ekle;
		ekle->onceki=son;
		son=ekle;
		son->sonraki=NULL;
	}
}
void sil(char *kelime)
{
	struct Dosya *sil;
	sil=ilk;
	while(sil)
	{
		if(strcmp(BirinciKelime(sil->word),kelime)==0)
		{
			if(sil==ilk)
			{
				ilk=sil->sonraki;
				ilk->onceki=NULL;
			}
			else
			{
				sil->onceki->sonraki=sil->sonraki;
				
				if(sil!=son)
				{
					sil->sonraki->onceki=sil->onceki;
				}
				
				else
				{
					son=sil->onceki;
				}
			}
		}
		sil=sil->sonraki;
			
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
void QuadraticquarativeOlustur()
{
	struct stat status;
	FILE *dic,*quar;
	char ingilizce[100],turkce[100],kelime[200],c;
	int Adr,Temp,cakisma=0;
	dic = fopen("dictionary.txt", "r");
	quar = fopen("quadratic.txt", "w+");
	
	for(int i=0; i<HashSize; i++)
	{
		fseek(quar,i*200,0);
		fputc('*', quar );
	}
	time_t s,s2;
	time(&s);
	printf("Quadraticquarative Olusturuluyor...\n");
	for(int i=0; i<KelimeBoy; i++)
	{
		int sayac=1;

		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ingilizce,BirinciKelime(kelime));
		strcpy(turkce,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ingilizce);
		//printf("%s\n",turkce);
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}

		Adr = Hash(ingilizce);
		fseek(quar,Adr*200,0);
		c=fgetc(quar);

		Temp=Adr;
		while( c != '*')
		{

			cakisma++;
			Adr = (Adr + (sayac*sayac)) % HashSize;
			if(Adr==Temp)
			{
				printf("Quadratic Dosya Dolu ! \n");
				break;
			}

			fseek(quar,Adr*200,0);
			c=fgetc(quar);
			sayac++;


		}

		fseek(quar,Adr*200,0);
		fprintf(quar, "%s", ingilizce);
		fprintf(quar, "  ");
		fprintf(quar, "%s", turkce);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(quar),&status);
	fclose(quar);
	fclose(dic);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");	
	//printf("\nQuadraticquarative Dosya Olustruldu\n");


}
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
void QuadraticKelimeSorgula()
{
	FILE *quar;
	char sorgu[100],index[200],index2[100],index3[100],index4[100];
	int Adr,count=1;
	if((quar = fopen("quadratic.txt", "r"))==NULL)
	{
		printf("Dosya Acilmadi!!");
	}
	fflush(stdin);
	printf("Kelimeyi Giriniz: ");gets(sorgu);
	Adr=Hash(sorgu);
	printf("Adres: %d\n",Adr);
	
	fseek(quar,Adr*200,0);
	fread(&index,sizeof(char),200,quar);
	strcpy(index,SagKes(index));
	strcpy(index3,BirinciKelime(index));
	
	while(strcmp(sorgu,index3)!=0)
	{
		Adr=(Adr+(count*count)) % HashSize;
		fseek(quar,Adr*200,0);
		fread(&index,sizeof(char),200,quar);
		strcpy(index,SagKes(index));
		strcpy(index3,BirinciKelime(index));
	
		printf("Adres: %d\n",Adr);
		count++;
	}
	
	strcpy(index4,IkinciKelime(index));
	printf("Sonuc: %s\n",index4);

	fclose(quar);

}
////////////////////////////////////////////////////////////////////////////////////////////////
void QuadraticKelimeEkle()
{
	FILE *dic;
	char ingilizce[100],turkce[100],c;
	int Adr;
	dic = fopen("dictionary.txt", "a+");
	fflush(stdin);
	printf("Eklenecek Kelimeyi Giriniz: ");gets(ingilizce);fflush(stdin);
	printf("Eklencek Kelimenin Turkcesini Giriniz: ");gets(turkce);
	fprintf(dic,"\n%s", ingilizce);
	fprintf(dic,"  ");
	fprintf(dic,"%s", turkce);
	fclose(dic);
	++KelimeBoy;
	QuadraticquarativeOlustur();
	system("cls");
	printf("%s  %s Kelimesi Basarili Bir Sekilde Eklenmistir\n",ingilizce,turkce);

}
//////////////////////////////////////////////////////////////////////////////////////////////////
void QuadraticKelimeSil()
{
	FILE *dic,*dic2;
	char kelime[200];
	int bul=0;
	char sorgu[200],index[200];
	int sayi;
	dic = fopen("dictionary.txt", "r");
	for(int i=0;i<=KelimeBoy;i++)
	{
		fscanf(dic,"%[^\n]\n",sorgu);
		ekle(sorgu);
	}
	fclose(dic);
	fflush(stdin);
	printf("Silinecek Kelimenin Ingilizcesini Giriniz: ");gets(kelime);
	sil(kelime);

	if((dic2 = fopen("dictionary.txt", "w+"))==NULL)
	{
		printf("Dosya Acilmadi!!\n");
	}
	struct Dosya *listele;
	
	listele=ilk;
	while(listele)
	{
		fprintf(dic2,"%s\n",listele->word);
		listele=listele->sonraki;
	}
	QuadraticquarativeOlustur();
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void DoublequarativeOlustur()
{
	struct stat status;
	FILE *dic,*dob;
	char ingilizce[100],turkce[100],kelime[100],c;
	int Adr,Temp,Adr2,cakisma=0;
	dic = fopen("dictionary.txt", "r");
	dob = fopen("double.txt", "w+");

	for(int i=0; i<=HashSize; i++)  
	{
		fseek(dob,i*200,0);
		fputc('*', dob );
	}
	time_t s,s2;
	time(&s);
	printf("Doublequarative Olusturuluyor...\n");

	for(int i=0; i<KelimeBoy; i++)  
	{
		int sayac=1;

		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ingilizce,BirinciKelime(kelime));
		strcpy(turkce,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ingilizce);
		//printf("%s\n",turkce);
		
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}

		

		Adr = Hash(ingilizce);
		Adr2= Hash2(ingilizce);
		fseek(dob,Adr*200,0);
		c=fgetc(dob);

		Temp=Adr;
		while( c != '*')
		{
			cakisma++;
			Adr = (Adr + sayac*Adr2) % HashSize;
			if(Adr==Temp)
			{
				printf("Double Dosya Dolu ! \n");
				break;
			}

			fseek(dob,Adr*200,0);
			c=fgetc(dob);
			sayac++;

		}

		fseek(dob,Adr*200,0);
		fprintf(dob, "%s", ingilizce);
		fprintf(dob, "  ");
		fprintf(dob, "%s", turkce);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(dob),&status);
	fclose(dob);
	fclose(dic);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");
	//printf("\nDoublequarative Dosya Olustruldu\n");

}
void DoubleKelimeSorgula()
{
	FILE *doub;
	char sorgu[100],index[200],index2[100],index3[100],index4[100];
	int Adr,count=1,Adr2;
	if((doub = fopen("double.txt", "r"))==NULL)
	{
		printf("Dosya Acilmadi!!");
	}
	fflush(stdin);
	printf("Kelimeyi Giriniz: ");gets(sorgu);
	Adr=Hash(sorgu);
	Adr2= Hash2(sorgu);
	printf("Adres: %d\n",Adr);
	
	fseek(doub,Adr*200,0);
	fread(&index,sizeof(char),200,doub);
	strcpy(index,SagKes(index));
	strcpy(index3,BirinciKelime(index));

	while(strcmp(sorgu,index3)!=0)
	{
		Adr=(Adr+(count*Adr2)) % HashSize;
		fseek(doub,Adr*200,0);
		fread(&index,sizeof(char),200,doub);
		strcpy(index,SagKes(index));
		strcpy(index3,BirinciKelime(index));
		count++;
		printf("Adres: %d\n",Adr);
	}

	strcpy(index4,IkinciKelime(index));
	printf("Sonuc: %s\n",index4);

	fclose(doub);
}
////////////////////////////////////////////////////////////////////
void DoubleKelimeEkle()
{
	FILE *dic;
	char ingilizce[100],turkce[100],c;
	int Adr;
	dic = fopen("dictionary.txt", "a+");
	fflush(stdin);
	printf("Eklenecek Kelimeyi Giriniz: ");gets(ingilizce);fflush(stdin);
	printf("Eklencek Kelimenin Turkcesini Giriniz: ");gets(turkce);
	fprintf(dic,"\n%s", ingilizce);
	fprintf(dic,"  ");
	fprintf(dic,"%s", turkce);
	fclose(dic);
	++KelimeBoy;
	DoublequarativeOlustur();
	system("cls");
	printf("%s  %s Kelimesi Basarili Bir Sekilde Eklenmistir\n",ingilizce,turkce);
}
/////////////////////////////////////////////////////////////////////
void DoubleKelimeSil()
{
	FILE *dic,*dic2;
	char kelime[200];
	int bul=0;
	char sorgu[200],index[200];
	int sayi;
	dic = fopen("dictionary.txt", "r");
	for(int i=0;i<=KelimeBoy;i++)
	{
		fscanf(dic,"%[^\n]\n",sorgu);
		ekle(sorgu);
	}
	fclose(dic);
	fflush(stdin);
	printf("Silinecek Kelimenin Ingilizcesini Giriniz: ");gets(kelime);
	sil(kelime);

	if((dic2 = fopen("dictionary.txt", "w+"))==NULL)
	{
		printf("Dosya Acilmadi!!\n");
	}
	struct Dosya *listele;
	
	listele=ilk;
	while(listele)
	{
		fprintf(dic2,"%s\n",listele->word);
		listele=listele->sonraki;
	}
	DoublequarativeOlustur();
}
////////////////////////////////////////////////////////////////////
char *BirinciKelime(char *kelime)
{
	int sayi;
	for(int i=0;i<strlen(kelime);i++)
	{
		if(kelime[i]==' ' && kelime[i+1]==' ')
		{				
		    sayi=i;
			break;
		}	
	}
	char *ing=(char*)malloc(sayi*sizeof(char));
	for(int i=0;i<sayi;i++)
	{			
		ing[i]=kelime[i];
	}
	ing[sayi]=NULL;
	return ing;
	
	
}
////////////////////////////////////////////////////////////////
char *IkinciKelime(char *kelime)
{
	int sayi;
	for(int i=strlen(kelime);i>0;i--)
	{
		if(kelime[i]==' ' && kelime[i-1]==' ')
		{
			sayi=i;
			break;
		}
	}
	int ayir=strlen(kelime)-sayi;
	char *tr=(char*)malloc(ayir*sizeof(char));
	++sayi;
	for(int i=sayi;i<strlen(kelime);i++)
	{
		tr[i-sayi]=kelime[i];
	}
	tr[strlen(kelime)-sayi]=NULL;
	
	return tr;
	
}
char *SagKes(char *str)
{
  size_t n;
  n = strlen(str);
  while (n > 0 && isspace((unsigned char)str[n - 1])) {
    n--;
  }
  str[n] = '\0';
  return str;
}
void SorguLineerOlustur()
{
	struct stat status;
	FILE *dic,*rel;
	char ing[100],tr[100],kelime[200],c;
	int Adr,Temp,cakisma=0;
	dic = fopen("sorgu.txt", "r");
	rel = fopen("sorgulineer.txt", "w+");

	for(int i=0; i<=SorguHashSize; i++)
	{
		fseek(rel,i*200,0);
		fputc('*', rel );
	}
	time_t s,s2;
	time(&s);
	printf("Lineerquarative Olusturuluyor...\n");
	for(int i=0; i<SorguBuyukBul(); i++)
	{

		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ing,BirinciKelime(kelime));
		strcpy(tr,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ing);
		//printf("%s\n",tr);
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}
		Adr = SorguHash(ing);
		fseek(rel,Adr*200,0);
		c=fgetc(rel);
		Temp=Adr;
		while( c != '*')
		{
			cakisma++;
			Adr = (Adr + 1) % SorguHashSize;
			if(Adr==Temp)
			{
				printf("lineer Dosya Dolu ! \n");
				break;
			}
			fseek(rel,Adr*200,0);
			c=fgetc(rel);
		}

		fseek(rel,Adr*200,0);
		fprintf(rel, "%s", ing);
		fprintf(rel, "  ");
		fprintf(rel, "%s", tr);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(rel),&status);
	fclose(dic);
	fclose(rel);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");
	
	//printf("\nLineerquarative Dosya Olustruldu\n");
}
void SorguLineer()
{
	SorguLineerOlustur();
	//////////////////////////////
	FILE *di;
	char sorgu[200],tampon[100];
	di = fopen("sorgu.txt", "r");
	for(int i=0;i<SorguBuyukBul();i++)
	{
		fscanf(di,"%[^\n]\n",sorgu);
		strcpy(tampon,BirinciKelime(sorgu));
		ekle(tampon);
	}
	fclose(di);
	////////////////////////////////////
	struct Dosya *listele;
	time_t s,s2;
	FILE *srel;
	char oku[200],index[200],index2[100],index3[100],index4[100],ingilizce[100];
	int Adr=0;
	srel = fopen("sorgulineer.txt", "r");
	listele=ilk;
	while(listele)
	{
		time(&s);
		Adr=SorguHash(listele->word);
		fseek(srel,Adr*200,0);
		
		fread(&index,sizeof(char),200,srel);
		strcpy(index,SagKes(index));
		strcpy(index3,BirinciKelime(index));
		while(strcmp(listele->word,index3)!=0)
		{
			Adr=(Adr+1) % SorguHashSize;
			fseek(srel,Adr*200,0);
			fread(&index,sizeof(char),200,srel);
			strcpy(index,SagKes(index));
			strcpy(index3,BirinciKelime(index));
		}
	
		strcpy(index4,IkinciKelime(index));
		time(&s2);
		printf("\n------------------------------\n");
		printf("Aranan Kelime: %s\n",listele->word);
		printf("Turkce Karsiligi: %s\n",index4);
		printf("Bulunma Suresi: %.6f sn\n",difftime(s2,s));
		
		listele=listele->sonraki;
	}

	fclose(srel);
}
void SorguQuadOlustur()
{
	struct stat status;
	FILE *dic,*rel;
	int sayac;
	char ing[100],tr[100],kelime[200],c;
	int Adr,Temp,cakisma=0;
	dic = fopen("sorgu.txt", "r");
	rel = fopen("sorguquad.txt", "w+");

	for(int i=0; i<=SorguHashSize; i++)
	{
		fseek(rel,i*200,0);
		fputc('*', rel );
	}
	time_t s,s2;
	time(&s);
	printf("Quadraticquarative Olusturuluyor...\n");
	for(int i=0; i<SorguBuyukBul(); i++)
	{
		sayac=1;
		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ing,BirinciKelime(kelime));
		strcpy(tr,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ing);
		//printf("%s\n",tr);
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}
		Adr = SorguHash(ing);
		fseek(rel,Adr*200,0);
		c=fgetc(rel);
		Temp=Adr;
		while( c != '*')
		{
			cakisma++;
			Adr = (Adr + (sayac*sayac)) % SorguHashSize;
			if(Adr==Temp)
			{
				printf("Quadratic Dosya Dolu ! \n");
				break;
			}
			fseek(rel,Adr*200,0);
			c=fgetc(rel);
			sayac++;
		}

		fseek(rel,Adr*200,0);
		fprintf(rel, "%s", ing);
		fprintf(rel, "  ");
		fprintf(rel, "%s", tr);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(rel),&status);
	fclose(dic);
	fclose(rel);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");
	
}
void SorguDoubleOlustur()
{
	struct stat status;
	FILE *dic,*rel;
	int sayac;
	char ing[100],tr[100],kelime[200],c;
	int Adr,Temp,cakisma=0,Adr2;
	dic = fopen("sorgu.txt", "r");
	rel = fopen("sorgudouble.txt", "w+");

	for(int i=0; i<=SorguHashSize; i++)
	{
		fseek(rel,i*200,0);
		fputc('*', rel );
	}
	time_t s,s2;
	time(&s);
	printf("Doublequarative Olusturuluyor...\n");
	for(int i=0; i<SorguBuyukBul(); i++)
	{
		sayac=1;
		fscanf(dic,"%[^\n]\n",kelime);
		strcpy(ing,BirinciKelime(kelime));
		strcpy(tr,IkinciKelime(kelime));
		//printf("%d.===>>> %s\t",i+1,ing);
		//printf("%s\n",tr);
		time(&s2);
		if((int)difftime(s2,s)%2==0)
		{
			printf("*");
		}
		Adr = SorguHash(ing);
		Adr2= Hash2(ing);
		fseek(rel,Adr*200,0);
		c=fgetc(rel);
		Temp=Adr;
		while( c != '*')
		{
			cakisma++;
			Adr = (Adr + (sayac*Adr2)) % SorguHashSize;
			if(Adr==Temp)
			{
				printf("Quadratic Dosya Dolu ! \n");
				break;
			}
			fseek(rel,Adr*200,0);
			c=fgetc(rel);
			sayac++;
		}

		fseek(rel,Adr*200,0);
		fprintf(rel, "%s", ing);
		fprintf(rel, "  ");
		fprintf(rel, "%s", tr);
	}
	time_t s1;
	time(&s1);
	fstat(fileno(rel),&status);
	fclose(dic);
	fclose(rel);
	printf("\n\n----------------------------------------\n");
	printf("\nOlusturma Suresi:  %.2f sn\nCakisma Sayisi: %d\nDosya Boyutu: %d Byte\n",difftime(s1,s),cakisma,status.st_size);
	printf("\n----------------------------------------\n\n");
}
void SorguQuad()
{
	SorguQuadOlustur();
	//////////////////////////////
	FILE *di;
	char sorgu[200],tampon[100];
	di = fopen("sorgu.txt", "r");
	for(int i=0;i<SorguBuyukBul();i++)
	{
		fscanf(di,"%[^\n]\n",sorgu);
		strcpy(tampon,BirinciKelime(sorgu));
		ekle(tampon);
	}
	fclose(di);
	////////////////////////////////////
	struct Dosya *listele;
	
	time_t s,s2;
	FILE *srel;
	char oku[200],index[200],index2[100],index3[100],index4[100],ingilizce[100];
	int Adr=0;
	srel = fopen("sorguquad.txt", "r");
	listele=ilk;
	while(listele)
	{
		int count=1;
		time(&s);
		Adr=SorguHash(listele->word);
		fseek(srel,Adr*200,0);
		
		fread(&index,sizeof(char),200,srel);
		strcpy(index,SagKes(index));
		strcpy(index3,BirinciKelime(index));
		while(strcmp(listele->word,index3)!=0)
		{
			Adr=(Adr+(count*count)) % SorguHashSize;
			fseek(srel,Adr*200,0);
			fread(&index,sizeof(char),200,srel);
			strcpy(index,SagKes(index));
			strcpy(index3,BirinciKelime(index));
			count++;
		}
	
		strcpy(index4,IkinciKelime(index));
		time(&s2);
		printf("\n------------------------------\n");
		printf("Aranan Kelime: %s\n",listele->word);
		printf("Turkce Karsiligi: %s\n",index4);
		printf("Bulunma Suresi: %.6f sn\n",difftime(s2,s));
		
		listele=listele->sonraki;
	}

	fclose(srel);
	
}
void SorguDouble()
{
	SorguDoubleOlustur();
	//////////////////////////////
	FILE *di;
	char sorgu[200],tampon[100];
	di = fopen("sorgu.txt", "r");
	for(int i=0;i<SorguBuyukBul();i++)
	{
		fscanf(di,"%[^\n]\n",sorgu);
		strcpy(tampon,BirinciKelime(sorgu));
		ekle(tampon);
	}
	fclose(di);
	////////////////////////////////////
	struct Dosya *listele;
	
	time_t s,s2;
	FILE *srel;
	char index[200],index2[100],index3[100],index4[100],ingilizce[100],index5[100];
	int Adr=0,Adr2=0;
	srel = fopen("sorgudouble.txt", "r");
	listele=ilk;
	while(listele)
	{
		int count=1;
		time(&s);
		Adr=SorguHash(listele->word);
		Adr2=Hash2(listele->word);
		fseek(srel,Adr*200,0);
		
		fread(index,sizeof(char),200,srel);
		strcpy(index5,SagKes(index));
		strcpy(index3,BirinciKelime(index5));
		while(strcmp(listele->word,index3)!=0)
		{
			Adr=(Adr+(count*Adr2)) % SorguHashSize;
			fseek(srel,Adr*200,0);
			fread(index,sizeof(char),200,srel);
			strcpy(index5,SagKes(index));
			strcpy(index3,BirinciKelime(index5));
			
			count++;
		}
	
		strcpy(index4,IkinciKelime(index5));
		time(&s2);
		printf("\n------------------------------\n");
		printf("Aranan Kelime: %s\n",listele->word);
		printf("Turkce Karsiligi: %s\n",index4);
		printf("Bulunma Suresi: %.6f sn\n",difftime(s2,s));
		
		listele=listele->sonraki;
		fflush(stdin);
	}

	fclose(srel);
}

