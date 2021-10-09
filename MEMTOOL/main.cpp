#include <stdio.h>
//#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <thread>
//#include "MemoryTools.h"
#include <iostream>
#include <iostream>

#include "Loger.h"
//#include "Memory.h"
#include "MemoryTools.h"
#include "obfuscate.h"
int count;
struct little_map
{
 std::uintptr_t address;
 std::int64_t value;
};

long int get_module_base(int pid, const char *module_name)
{
 FILE *fp;
 long addr = 0;
 char *pch;
 char filename[32];
 char line[1024];
 snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
 fp = fopen(filename, "r");
 if (fp != NULL)
 {
  while (fgets(line, sizeof(line), fp))
  {
   if (strstr(line, module_name))
   {
    pch = strtok(line, "-");
    addr = strtoul(pch, NULL, 16);
    break;
   }
  }
  fclose(fp);
 }
 return addr;
}

int BaseAddress_FLOAT(long int addr, float value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}

int BaseAddress_DWORD(long int addr, int value)
{
 pwrite64(handle, &value, 4, addr);
 return 0;
}

int main(int argc, char **argv)
{
 int Fitur = atoi(argv[1]);
 {
  char pkg[100];
        if (isapkrunning(OBFUSCATE("com.tencent.ig")) == 1)
        {
            sprintf(pkg, "com.tencent.ig");
        }
        else if (isapkrunning(OBFUSCATE("com.vng.pubgmobile")) == 1)
        {
            sprintf(pkg, "com.vng.pubgmobile");
        }
        else if (isapkrunning(OBFUSCATE("com.pubg.krmobile")) == 1)
        {
            sprintf(pkg, "com.pubg.krmobile");
        }
        else if (isapkrunning(OBFUSCATE("com.rekoo.pubgm")) == 1)
        {
            sprintf(pkg, "com.rekoo.pubgm");
        }

  char getRoot[100];
  if (getuid() == 0)
  {
   sprintf(getRoot, "MODE_ROOT");
  }
  else
  {
   sprintf(getRoot, "MODE_NO_ROOT");
  }

  int ipid = getPID(pkg);

  char lj[64];
  sprintf(lj, "/proc/%d/mem", ipid);
  handle = open(lj, O_RDWR);
  if (handle == -1)
  {
   puts("Gagal mendapatkan memory!\n");
   puts("Restart Game, Execute in Lobby/Game!\n");
   exit(1);
  }

  char mname[] = "libUE4.so";
  long int libbase = get_module_base(ipid, mname);
  
  switch (Fitur)
  {
  	  case 1: //
		    SetSearchRange(A_ANONMYOUS);
			MemorySearch(pkg,OBFUSCATE("1.348.759.109"),&count, DWORD);
			MemoryOffset(pkg,OBFUSCATE("1.953.067.887"), 4, &count,DWORD);
			MemoryOffset(pkg,OBFUSCATE("1.634.692.166"), 28, &count,DWORD);
			MemoryOffset(pkg,OBFUSCATE("1.920.287.604"), 4, &count,DWORD);
			MemoryWrite(pkg,OBFUSCATE("0"), 0, DWORD);
			ClearResults();
			break
		}
	}
}
