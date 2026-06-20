unsigned __int64 __fastcall gen7_snapshot_registers(_QWORD *a1, char *a2, unsigned __int64 a3, int **a4)
{
  unsigned __int64 v8; // x19
  int v9; // w8
  int *v10; // x23
  char *v11; // x21
  char *v12; // x22
  __int64 v13; // x9
  int v14; // w9
  unsigned int v15; // w24

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*a4);
  if ( v8 <= a3 )
  {
    v9 = **a4;
    if ( v9 != -1 )
    {
      v10 = *a4 + 2;
      v11 = (char *)a4[2] + *(_QWORD *)(gen7_crashdump_registers + 8);
      do
      {
        v14 = *(v10 - 1) - v9;
        v15 = v14 + 1;
        if ( v14 )
        {
          v12 = a2 + 8;
          *((_DWORD *)a2 + 1) = v15;
        }
        else
        {
          v9 |= 0x80000000;
          v12 = a2 + 4;
        }
        *(_DWORD *)a2 = v9;
        memcpy(v12, v11, 4 * v15);
        v9 = *v10;
        v13 = 4LL * v15;
        v10 += 2;
        a2 = &v12[v13];
        v11 += v13;
      }
      while ( v9 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_registers__rs, "gen7_snapshot_registers") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  return v8;
}
