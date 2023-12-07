#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
	l_gen(fptr);
	fprintf(fptr, "</tr>\n");
	fprintf(fptr, "</table>\n");
}
void tab(FILE* fptr, int i){
	int n;
	if(fptr == NULL){genfailed();}
	
	for(n = 0;n < i; n++){
		fprintf(fptr, "		");
	}
}

void l_gen(FILE* fptr){
	cell(fptr, (LPCTSTR)"Fool");
	
}
void cell(FILE* fptr, LPCTSTR content){
	tab(fptr,1); fprintf(fptr, "<td>\n");
	tab(fptr,1); fprintf(fptr, "</td>\n");	
}

int main(int argc, char *argv[]) {
	FILE *fptr;
	fptr = fopen("SE.html", "w");
	fprintf(fptr, "<TITLE>old shedule &#9752 </TITLE>\n");

	fprintf(fptr, "<HTML>\n");
	fprintf(fptr, "<HEAD>\n");
			
	fprintf(fptr, "		</HEAD>\n");
	
	
	fprintf(fptr, "		<BODY>\n");	
	tb_gen(fptr);
	fprintf(fptr, "		</BODY>\n");	
	
	<style>
	table, th, td {
  	border: 1px solid black;
	}
</style>
	
	fprintf(fptr, "</HTML>\n");
	fclose(fptr);
	
	gensuccesful();
	system("SE.html");

	return 0;
}
