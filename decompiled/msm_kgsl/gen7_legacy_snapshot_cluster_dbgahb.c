unsigned __int64 __fastcall gen7_legacy_snapshot_cluster_dbgahb(
        _QWORD *a1,
        _DWORD *a2,
        unsigned __int64 a3,
        __int64 a4)
{
  unsigned __int64 v8; // x21
  unsigned int *v9; // x24
  unsigned int v10; // w8
  unsigned int *v11; // x22
  unsigned int v12; // w8
  unsigned int v13; // w25
  unsigned int v14; // t1

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*(_QWORD *)(a4 + 24)) + 16LL;
  if ( v8 <= a3 )
  {
    *a2 = *(_DWORD *)(a4 + 12);
    a2[1] = *(_DWORD *)a4;
    a2[2] = *(_DWORD *)(a4 + 8);
    a2[3] = *(_DWORD *)(a4 + 16);
    kgsl_regmap_write(
      a1 + 1650,
      ((*(_DWORD *)(a4 + 16) & 3) << 18)
    | ((*(_DWORD *)(a4 + 8) & 3) << 16)
    | ((unsigned __int8)*(_DWORD *)(a4 + 4) << 8));
    __dsb(0xFu);
    v9 = *(unsigned int **)(a4 + 24);
    v10 = *v9;
    if ( *v9 != -1 )
    {
      v11 = a2 + 4;
      do
      {
        if ( v9[1] == v10 )
        {
          *v11++ = v10;
          v13 = *v9;
          v12 = v9[1];
        }
        else
        {
          *v11 = v10 | 0x80000000;
          v12 = v9[1];
          v11[1] = v12;
          v11 += 2;
          v13 = *v9;
        }
        while ( v13 <= v12 )
        {
          *v11++ = kgsl_regmap_read(a1 + 1650);
          ++v13;
          v12 = v9[1];
        }
        v14 = v9[2];
        v9 += 2;
        v10 = v14;
      }
      while ( v14 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_legacy_snapshot_cluster_dbgahb__rs, "gen7_legacy_snapshot_cluster_dbgahb") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v8;
}
