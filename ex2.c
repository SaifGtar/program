#include <stdio.h>
#define longueurmaxL 100
#define longueurmaxC 100
void ChargementMat(char mat[longueurmaxL][longueurmaxC],int nb_lignes)
{ int i,j; 
for(i=0;i<nb_lignes;i++){
     j=0; 
     printf("Donnez la ligne  %d ?\n", i);
     rewind(stdin) ;
	 do{   mat[i][j] = getchar();
           j++;
     }while(j<longueurmaxC&&mat[i][j-1]!= '#');
  }
}
void Affichage1(char mat[longueurmaxL][longueurmaxC],int nb_lignes)
{ int i,j;
for(i=0;i<nb_lignes;i++){
     j=0;
	 while(j<longueurmaxC&&mat[i][j]!= '#'){ 
	       printf("%c  ", mat[i][j]);
           j++;} printf("\n");
  }
}
void Affichage(char mat[longueurmaxL][longueurmaxC],int nb_lignes)
{ int i,j;
for(i=0;i<nb_lignes;i++){
	AffichageMatL(mat,i);
  }
}
void  AffichageMatL(char mat[longueurmaxL][longueurmaxC],int i)
{ int j;
     j=0;
	 while(j<longueurmaxC&&mat[i][j]!= '#'){ 
	       printf("%c  ", mat[i][j]);
           j++;} printf("\n");  
}
void  ComptageV(char mat[longueurmaxL][longueurmaxC],int nb_lignes,
                int T[longueurmaxL])
{ int i,j,nb_voy;
for(i=0;i<nb_lignes;i++){
     j=0;
     nb_voy=0;
	 while(j<longueurmaxC&&mat[i][j]!= '#'){ 
	    if(mat[i][j]=='A'||mat[i][j]=='E'||mat[i][j]=='I'||
	       mat[i][j]=='O'||mat[i][j]=='U'||mat[i][j]=='Y'||
		   mat[i][j]=='a'||mat[i][j]=='e'|| mat[i][j]=='i'||
		   mat[i][j]=='o'||mat[i][j]=='u'||mat[i][j]=='y')
			 nb_voy++;
           j++;}
           T[i]=nb_voy;
  }
}
void AffichageTab(int T[longueurmaxL],int nb_lignes)
{ int i;
for(i=0;i<nb_lignes;i++){
           printf("%d  ", T[i]);
  }
}
void  Supprimer(char mat[longueurmaxL][longueurmaxC],
                int nb_lignes,int *nb_espaces)
{
 int i,j,k;
 *nb_espaces=0;
for(i=0;i<nb_lignes;i++){
     j=0;
     k=0;
	 while(j<longueurmaxC&&mat[i][j-1]!= '#'){ 
	      if(mat[i][j]==' ')  
		  (*nb_espaces)++;
		  else {
		  mat[i][k]=mat[i][j];
		  k++;
	      }
		   j++;};
  }
}
void   RechercherMat(char mat[longueurmaxL][longueurmaxC], int nb_lignes,
                     char c,int *pl,int *dl,int *pc,int *dc)
{
 int i,j; *pl=-1;*dl=-1;*pc=-1; *dc=-1;
for(i=0;i<nb_lignes;i++){
     j=0;
	 while(j<longueurmaxC&&mat[i][j]!= '#'){ 
	      if((mat[i][j]==c)&& (*pl==-1))  
		   {*pl =i; *dl =i;*pc =j;*dc =j;}
		  if((mat[i][j]==c)&& (*pl!=-1))
		  {*dl=i; *dc=j;}
		   j++;}
  }
}
int main(){
 char matrice[longueurmaxL][longueurmaxC];
 char c;
 int T1[longueurmaxL];
 int i, nb_lignes, nb_espaces,pl,dl,pc,dc;
 printf("Quelles seront les dimensions de la matrice ? \n");
 do{
 printf("Combien de lignes ? \n");
 scanf("%d", &nb_lignes);} 
 while(nb_lignes<1&&nb_lignes>longueurmaxL);
 ChargementMat(matrice,nb_lignes);
  printf("\nLa matrice que vous avez rentré est : \n");
 Affichage(matrice,nb_lignes);
  printf("\nLe nombre de voyelles par ligne : \n");
 ComptageV(matrice,nb_lignes,T1);
AffichageTab(T1,nb_lignes);
Supprimer(matrice,nb_lignes,&nb_espaces);
 printf("\nLe nombre d'espaces : %d \n", nb_espaces);
 printf("\nLa matrice que vous avez rentré après suppression est : \n");
 Affichage(matrice,nb_lignes);
 printf("\nDonnez un caractère à rechercher\n");
 rewind(stdin) ;
 c= getchar();
 RechercherMat(matrice,nb_lignes,c,&pl,&dl,&pc,&dc); 
printf("\n la première occurrence du caractère %c est : [%d,%d]  \n",c,pl,pc); 
printf("\n la denière occurrence du caractère  %c est : [%d,%d] \n",c,dl,dc); 
 do{
 printf("\n donnez le num de la ligne à afficher:"); 
 rewind(stdin) ;
 scanf("%d",&i);}while(i<0&&i>nb_lignes);
 AffichageMatL(matrice,i);
return 0;
}
