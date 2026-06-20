unsigned __int64 __fastcall gen7_snapshot_mvc(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 v8; // x19
  unsigned int *v9; // x9
  unsigned int v10; // w8
  unsigned int *v11; // x21
  unsigned int *v12; // x22
  char *v13; // x20
  char *v14; // x21
  unsigned int v15; // w23
  __int64 v16; // x9
  unsigned int v17; // w9

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*(_QWORD *)(a4 + 16)) + 16LL;
  if ( v8 <= a3 )
  {
    *a2 = *(_DWORD *)(a4 + 8) == 3;
    a2[1] = *(_DWORD *)a4;
    a2[2] = *(_DWORD *)(a4 + 4);
    a2[3] = -1;
    v9 = *(unsigned int **)(a4 + 16);
    v10 = *v9;
    if ( *v9 != -1 )
    {
      v11 = a2 + 4;
      v12 = v9 + 1;
      v13 = (char *)(*(_QWORD *)(gen7_crashdump_registers + 8) + *(unsigned int *)(a4 + 32));
      do
      {
        v17 = *v12 - v10;
        if ( *v12 == v10 )
        {
          *v11 = v10;
          v14 = (char *)(v11 + 1);
        }
        else
        {
          *v11 = v10 | 0x80000000;
          v11[1] = *v12;
          v14 = (char *)(v11 + 2);
        }
        v15 = v17 + 1;
        memcpy(v14, v13, 4 * (v17 + 1));
        v10 = v12[1];
        v16 = 4LL * v15;
        v12 += 2;
        v13 += v16;
        v11 = (unsigned int *)&v14[v16];
      }
      while ( v10 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_mvc__rs, "gen7_snapshot_mvc") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v8;
}
