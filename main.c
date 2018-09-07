#include <stdio.h>
#include <stdlib.h>
#define CINQ 5
#define DIX 10
#define HUIT 8
int verif(int dt, char txt[]);
int main(int argc, char *argv[])
{
	int t_compt = CINQ, d_compt = DIX, loop = 0;
	char s_date_time[18];
	while(loop == 0){
	   scanf("%s", &s_date_time);
	   if((verif(t_compt, s_date_time) == CINQ) || (verif(d_compt, s_date_time) == DIX)){
		   printf("%s\n", s_date_time);
		   loop++;
	   }else
		   printf("\nErreur '%s' n'est pas une date ou une heure.\nVeuillez réessayer:\n", s_date_time);
	}
   return 0;
}
int verif(int dt, char txt[])
{
	int this, mois_ver = 0, k = 0, loop, year, annee = ((txt[6] - '0') * 1000) + ((txt[7] - '0') * 100) + ((txt[8] - '0') * 10) + (txt[9] - '0');
	char month[9], *mois[12] = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};
	if(txt[CINQ] == 0)
		this = CINQ;
	if((txt[CINQ] != 0) && (txt[DIX] == 0))
		this = DIX;
	dt = 0;
	for(year = 0;year < annee;year += 4);
	for(int x = 10;x <= 17;x++){
		int j = x + 1, c = x - 1, v = x- 2, b = x - 3, d = x - 4;
		if((txt[x] != 0) && (txt[j] == 0) && (loop = x - 7) && (txt[DIX] != 0)){
			this = HUIT;
			annee = ((txt[b] - '0') * 1000) + ((txt[v] - '0') * 100) + ((txt[c] - '0') * 10) + (txt[x] - '0');
		for(year = 0;year < annee;year += 4){}
			for(int y = 0;y < 12;y++){
				for(int i = 0;i < loop;i++){
					month[i] = txt[i + 3];
						if(mois[y][i] == month[i]){
							dt++;
						}
				}
				if(dt == loop){
					mois_ver = 1;
					if((y == 1) && (year == annee))
						mois_ver = 2;
					for(int v = 1;v <= 12;v += 2){
						int u = y + 1;
						if(mois_ver != 2){
							if(((y != v) && (v <= 6))||((y != v) && (v > 6)))
								mois_ver = 3;
							if(((u == v) && (y <= 6))||((y == v) && (y > 6)))
								k = 1;
						}
					}
					if(k == 1)
						mois_ver = 1;
					if(((txt[d] != 47) || (txt[2] != 47)) || ((txt[1] > 48) && (txt[0] > 50) && (mois_ver == 3)) || ((txt[2] != 47)) || ((txt[1] > 49) && (txt[0] > 51)) || ((((txt[1] > 56) && (txt[0] == 50)) || (txt[0] > 50)) && (mois_ver == 2) && (year == annee)))
						mois_ver = 0;
					y = 12;
				}else
					dt = 0;
			}
		}
	}
	if((this == DIX) || (this == CINQ)){
	   for(int i = 0;i < this;i++){
		   if((txt[i] == 48 + i) || ((txt[2] == 104) || (txt[2] == 58)) || ((txt[2] == 47) && (txt[5] == 47)))
			   dt++;
		   else
			   dt = 0;
	   }
	}
   if(this == DIX){
	   if(((txt[3] > 49) || (txt[0] > 51)) || ((txt[1] > 56) && (txt[0] >= 50) && (year == annee) && (txt[3] == 48) && (txt[4] == 50)) || ((txt[0] >= 51) && (txt[1] > 49)))
		   dt = 0;
	   else if((txt[1] == 49) && (txt[0] == 51)){
		   for(int i = 1;i <= 9; i += 2){
			   if(((txt[4] != 48 + i) && (i <= 7)) || (((txt[4] == 48 + i) || ((txt[3] == 49) && (txt[4] == 48 + i))) && (i > 7)))
					   dt--;
		   }
		   dt += 4;
	   }
	   if((txt[DIX] != 0) || (txt[2] != 47))
		   dt = 0;
   }else if(this == CINQ){
	   if((txt[0] > 50) || (txt[3] > 53) || ((txt[0] == 50) && (txt[1] > 52)) || (txt[CINQ] != 0))
			   dt = 0;
   }else if((this == HUIT) && (mois_ver > 0))
	   dt = 10;
   else
	   dt = 0;
   return dt;
}
