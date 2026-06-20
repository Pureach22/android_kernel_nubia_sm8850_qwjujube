unsigned __int64 __fastcall gen8_legacy_snapshot_cluster_dbgahb(
        _QWORD *a1,
        _DWORD *a2,
        unsigned __int64 a3,
        _DWORD *a4)
{
  unsigned int *v8; // x22
  unsigned __int64 v9; // x21
  int v10; // w8
  unsigned int v11; // w8
  unsigned int *v12; // x23
  unsigned int v13; // w8
  unsigned int v14; // w25
  unsigned int v15; // t1

  v8 = *(unsigned int **)(*(_QWORD *)a4 + 32LL);
  v9 = 4 * (unsigned int)adreno_snapshot_regs_count(v8) + 28LL;
  if ( v9 <= a3 )
  {
    *a2 = a4[8];
    a2[1] = a4[2];
    a2[2] = a4[4];
    a2[3] = a4[7];
    a2[5] = a4[5];
    a2[6] = a4[6];
    if ( *(_DWORD *)(*(_QWORD *)a4 + 4LL) == 1 )
      v10 = a4[3];
    else
      v10 = -1;
    a2[4] = v10;
    kgsl_regmap_write(
      a1 + 1650,
      ((a4[3] & 0x1F) << 21)
    | ((a4[7] & 7) << 18)
    | ((a4[4] & 3) << 16)
    | ((unsigned __int8)a4[9] << 8)
    | (16 * (a4[6] & 0xF))
    | a4[5] & 0xFu);
    __dsb(0xFu);
    v11 = *v8;
    if ( *v8 != -1 )
    {
      v12 = a2 + 7;
      do
      {
        if ( v8[1] == v11 )
        {
          *v12++ = v11;
          v14 = *v8;
          v13 = v8[1];
        }
        else
        {
          *v12 = v11 | 0x80000000;
          v13 = v8[1];
          v12[1] = v13;
          v12 += 2;
          v14 = *v8;
        }
        while ( v14 <= v13 )
        {
          *v12++ = kgsl_regmap_read(a1 + 1650);
          ++v14;
          v13 = v8[1];
        }
        v15 = v8[2];
        v8 += 2;
        v11 = v15;
      }
      while ( v15 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_legacy_snapshot_cluster_dbgahb__rs, "gen8_legacy_snapshot_cluster_dbgahb") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v9;
}
