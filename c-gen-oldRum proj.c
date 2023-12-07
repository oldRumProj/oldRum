#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef enum { false, true } bool;

void genfailed(){
	HWND 	hWnd;
	LPCTSTR lpCaption = "Failed...";
	LPCTSTR lpText = "Generation failed";
	
	MessageBox( NULL, lpText,  lpCaption, MB_OK | MB_ICONWARNING ); 
}
void gensuccesful(){
	HWND 	hWnd;
	LPCTSTR lpCaption = "Succes...";
	LPCTSTR lpText = "Generation finished. Good job. Time to publish.";	
	MessageBox( NULL, lpText,  lpCaption, MB_OK | MB_ICONASTERISK ); 
	//MessageBox( NULL, lpCaption, lpText,  MB_OK | MB_ICONASTERISK ); 
}
void tb_gen(FILE* fptr){
	fprintf(fptr, "<table>\n");
	fprintf(fptr, "<tr>\n");
//	l_gen(fptr);
	fprintf(fptr, "</tr>\n");
	fprintf(fptr, "</table>\n");
}
void tab(FILE* fptr, int i){
	int n;
	if(fptr == NULL){genfailed();}
	
	for(n = 0;n < i; n++){
		fprintf(fptr, "  ");
	}
}

void cell(FILE* fptr, LPCTSTR content){
	tab(fptr,1); fprintf(fptr, "<td>\n");
	tab(fptr,1); fprintf(fptr, "</td>\n");	
}

int main(int argc, char *argv[]) {
	
	short f0 = 'À';
	short f1 = 'ß';
	short  f2 = 'à';
	short  f3 = 'ÿ';
	
   FILE *source;
   char buff[255];
   char *outp;
   char out;
   source = fopen("source.html", "r");
   FILE *ref;
   ref = fopen("ref.txt", "w");
   int n = 940;
   int i = 0; int i2 = 0;
   bool r;
   
	for(i = 0; i < 3290; i++){
   	fscanf(source, "%s", buff);

   	for (i2 = 0; i2 < 255; i2++){
		r = false;
		if ((buff[i2] >= f0)&&(buff[i2] <= f1)){ r = true; outp = &buff[i2];}
		if ((buff[i2] >= f2)&&(buff[i2] <= f3)){ r = true; outp = &buff[i2];}
		if (buff[i2] == ' '){r = true; outp = &buff[i2];}
		
		if(r == true){ fprintf(ref, "%c", *(outp));}
	   
	   }
	   fprint(ref, "\n");
	   i2 = 0;
	}
	//https://stackoverflow.com/questions/9697137/print-characters-from-an-array-to-an-output-file-in-c
	
	
	
   /*

	r = false;
		for(i2 = 0; i2 < 255; i2++){
		if (buff[i2] >= f0){ r = true;}
		if (buff[i2] <= f1){ r = true;}
		if (buff[i2] >= f2){ r = true;} 
		if (buff[i2] <= f3){ r = true;}

		if (buff[i2] < f0){ r = false;}
		if (buff[i2] < f3){ r = false;}

	
 	//printf("%s\n", buff );
   }
   	if(r == true){
		fprintf(ref, buff);
		fprintf(ref,"\n");
	} 
	r = false;
	}
   fclose(source);
	*/
	
	
	FILE *fptr;
	fptr = fopen("SE.html", "w");
	fprintf(fptr, "<TITLE>oldRum shedule &#9752 </TITLE>\n");

	fprintf(fptr, "<HTML>\n");
	fprintf(fptr, "<HEAD>\n");
			
	fprintf(fptr, "  </HEAD>\n");
	
	
	fprintf(fptr, "  <BODY>\n");	
	tb_gen(fptr);
	fprintf(fptr, "	  </BODY>\n");	
	
	
	fprintf(fptr, "</HTML>\n");
	fclose(fptr);
	
	gensuccesful();
	system("SE.html");

	return 0;
}
