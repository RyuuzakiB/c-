#include <windows.h>
#include <stdio.h>
void *getConsoleFunction(char *name);
BOOL (WINAPI *doSetConsoleTextAttribute)(HANDLE hConsoleOutput, WORD attr);
int main() {
   HANDLE hCon;
   int i,j;
   hCon=GetStdHandle(STD_OUTPUT_HANDLE);
   doSetConsoleTextAttribute=getConsoleFunction("SetConsoleTextAttribute");
         (*doSetConsoleTextAttribute)(hCon,(5*160)+4);                      //ESCOLHE COR
        for(i=0;i<24;i++)
         printf("                                                               ");
         printf("Foda-se\n\n");
         (*doSetConsoleTextAttribute)(hCon,1000);                      //ESCOLHE COR
        for(i=0;i<8;i++)
         printf("                                                               ");
         
   (*doSetConsoleTextAttribute)(hCon,7);         //volta ao normal
   return 0;
}
void *getConsoleFunction(char *name) {
   static HMODULE kernel32=(HMODULE)0xffffffff;
   if(kernel32==0)
      return NULL;
   if(kernel32==(HMODULE)0xffffffff) {
      kernel32=LoadLibrary("kernel32.dll");
      if(kernel32==0)
         return 0;         
   }
   return GetProcAddress(kernel32,name);
}
