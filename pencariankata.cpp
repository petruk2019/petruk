#include <iostream>
using namespace std;

char b0[15]	= 	{'T','G','B','W','W','I','N','T','E','R','W','S','E','S','N'};
char b1[15]	=	{'A','A','U','N','T','T','M','M','H','F','O','O','D','N','B'};
char b2[15]	=	{'J','L','W','C','Q','L','D','Z','M','P','M','V','D','M','R'};
char b3[15]	=	{'A','S','A','G','M','Q','U','W','V','V','B','S','O','H','I'};
char b4[15]	=	{'B','W','P','L','O','T','A','N','A','D','T','P','G','N','C'};
char b5[15]	=	{'R','E','W','N','G','O','D','J','C','P','N','A','T','N','K'};
char b6[15]	=	{'E','E','O','T','W','O','S','B','Q','H','A','R','R','S','A'};
char b7[15]	=	{'A','Z','C','G','E','S','W','E','W','N','A','K','N','P','B'};
char b8[15]	=	{'D','I','N','N','E','R','Q','O','D','L','W','D','C','A','R'};
char b9[15]	=	{'O','N','O','P','K','W','M','P','A','R','K','T','Z','C','C'};
char b10[15]	=	{'Q','B','F','R','O','G','M','A','M','W','P','W','E','E','Y'};
char b11[15]	=	{'L','Q','Z','Q','N','N','M','R','Z','J','J','S','C','L','G'};
char b12[15]	=	{'M','O','S','G','Z','C','Z','D','T','D','B','O','O','T','O'};
char b13[15]	=	{'P','D','C','R','Z','M','S','N','G','R','D','N','R','P','Z'};
char b14[15]	= 	{'O','H','N','K','Z','W','A','T','E','R','J','G','T','R','A'};
char *(puzzle[15]) = {b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14};

void hurufacak(){
	for (int baris=0;baris<15;baris++){
		for (int kolom=0;kolom<15;kolom++){
		cout<<*(*(puzzle+baris)+kolom)<<" ";
		}
	cout<<endl;
	}
}


void atas( char *word){
	int x = 'A' - 'a';
	if (x < 0) x*=-1;
	
	for (int i=0;*(word+i);i++){
		if ('A' < 'a'){
		if (*(word+i) >= 'a') *(word+i)-=x;}
		else{
		if (*(word+i) <= 'A') *(word+i)+=x;}
		
	}
}

int panjang(char *word){
	int x;
	for (int i=0;*(word+i);i++){
		x = i;
	}	
	return x;
}
void pencarian (char *(word)){
int banyak =0;
	for (int baris=0;baris<15;baris++){
		for (int kolom=0;kolom<15;kolom++){
			int ada[8] = {0,0,0,0,0,0,0,0};
			if (*(*(puzzle+baris)+kolom) == *(word+0)){
				for(int i=1;i<=panjang(word);i++){
					if (baris <(15-panjang(word)))
					if (*(*(puzzle+(baris+i))+kolom) == *(word+i)) ada[0]++;
					
					if (baris >=(0+panjang(word)))
					if (*(*(puzzle+(baris-i))+kolom) == *(word+i)) ada[1]++; 
					
					if (kolom <(15-panjang(word)))
					if (*(*(puzzle+baris)+(kolom+i)) == *(word+i)) ada[2]++;
					
					if (kolom >=(0+panjang(word)))
					if (*(*(puzzle+baris)+(kolom-i)) == *(word+i)) ada[3]++;
					
					if (baris <(15-panjang(word)) && kolom <(15-panjang(word))) 
					if (*(*(puzzle+(baris+i))+(kolom+i)) == *(word+i)) ada[4]++;
					
					if (baris <(15-panjang(word)) && kolom >=(0+panjang(word)))
					if (*(*(puzzle+(baris+i))+(kolom-i)) == *(word+i)) ada[5]++;
					
					if (baris >=(0+panjang(word)) && kolom <(15-panjang(word)))
					if (*(*(puzzle+(baris-i))+(kolom+i)) == *(word+i)) ada[6]++;
					
					if (baris >=(0+panjang(word)) && kolom >=(0+panjang(word)))
					if (*(*(puzzle+(baris-i))+(kolom-i)) == *(word+i)) ada[7]++;
				}
			
				if (panjang(word) == 0){
					banyak++;
				}
			
				else {
					for(int l=0;l<8;l++){
						if (ada[l] == panjang(word)) banyak++;
					}
				}
			}
		}
	}		

	if (banyak != 0 ) cout<<"ada\n";
	else cout<<"tidak ada \n";	}
int main(){

hurufacak();	
int kata;
cout<<"\n\nmasukan jumlah kata yg dicari = ";cin>>kata;
char word[kata][15];
	for (int i=0;i<kata;i++)
	{
		cout<<"kata yg ingin dicari = ";
		cin>>word[i];
		panjang(*(word+i));
	}

	for (int i=0;i<kata;i++) 
	{
		atas(*(word+i));
		pencarian(*(word+i));
	}	
}
