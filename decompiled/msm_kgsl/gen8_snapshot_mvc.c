unsigned __int64 __fastcall gen8_snapshot_mvc(_QWORD *a1, __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned int *v8; // x22
  unsigned __int64 v9; // x19
  int v10; // w8
  unsigned int v11; // w8
  __int64 v12; // x10
  unsigned int *v13; // x20
  unsigned int *v14; // x22
  char *v15; // x21
  char *v16; // x20
  unsigned int v17; // w23
  __int64 v18; // x9
  unsigned int v19; // w9

  v8 = *(unsigned int **)(*(_QWORD *)a4 + 16LL);
  v9 = 4 * (unsigned int)adreno_snapshot_regs_count(v8) + 28LL;
  if ( v9 <= a3 )
  {
    *(_DWORD *)a2 = a4[5] == 3;
    *(_DWORD *)(a2 + 4) = a4[2];
    v10 = -1;
    *(_DWORD *)(a2 + 8) = a4[4];
    *(_DWORD *)(a2 + 12) = -1;
    *(_QWORD *)(a2 + 20) = -1;
    if ( *(_DWORD *)(*(_QWORD *)a4 + 4LL) == 1 )
      v10 = a4[3];
    *(_DWORD *)(a2 + 16) = v10;
    v11 = *v8;
    if ( *v8 != -1 )
    {
      v12 = *((_QWORD *)a4 + 3);
      v13 = (unsigned int *)(a2 + 28);
      v14 = v8 + 1;
      v15 = (char *)(*(_QWORD *)(gen8_crashdump_registers + 8) + v12);
      do
      {
        v19 = *v14 - v11;
        if ( *v14 == v11 )
        {
          *v13 = v11;
          v16 = (char *)(v13 + 1);
        }
        else
        {
          *v13 = v11 | 0x80000000;
          v13[1] = *v14;
          v16 = (char *)(v13 + 2);
        }
        v17 = v19 + 1;
        memcpy(v16, v15, 4 * (v19 + 1));
        v11 = v14[1];
        v18 = 4LL * v17;
        v14 += 2;
        v15 += v18;
        v13 = (unsigned int *)&v16[v18];
      }
      while ( v11 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_mvc__rs, "gen8_snapshot_mvc") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v9;
}
