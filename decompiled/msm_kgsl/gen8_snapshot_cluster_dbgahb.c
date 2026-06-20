unsigned __int64 __fastcall gen8_snapshot_cluster_dbgahb(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned __int64 v8; // x19
  int v9; // w8
  unsigned int *v10; // x9
  unsigned int v11; // w8
  __int64 v12; // x11
  unsigned int *v13; // x20
  unsigned int *v14; // x22
  char *v15; // x21
  char *v16; // x20
  unsigned int v17; // w23
  __int64 v18; // x9
  unsigned int v19; // w9

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*(_QWORD *)(*(_QWORD *)a4 + 32LL)) + 28LL;
  if ( v8 <= a3 )
  {
    *a2 = a4[8];
    a2[1] = a4[2];
    a2[2] = a4[4];
    a2[3] = a4[7];
    a2[5] = a4[5];
    a2[6] = a4[6];
    if ( *(_DWORD *)(*(_QWORD *)a4 + 4LL) == 1 )
      v9 = a4[3];
    else
      v9 = -1;
    a2[4] = v9;
    v10 = *(unsigned int **)(*(_QWORD *)a4 + 32LL);
    v11 = *v10;
    if ( *v10 != -1 )
    {
      v12 = *((_QWORD *)a4 + 5);
      v13 = a2 + 7;
      v14 = v10 + 1;
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
        v13 = (unsigned int *)&v16[v18];
        v15 += v18;
      }
      while ( v11 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_cluster_dbgahb__rs, "gen8_snapshot_cluster_dbgahb") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  return v8;
}
