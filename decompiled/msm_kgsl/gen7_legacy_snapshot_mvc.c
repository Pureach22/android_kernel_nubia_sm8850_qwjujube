unsigned __int64 __fastcall gen7_legacy_snapshot_mvc(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 v8; // x20
  __int64 v9; // x8
  unsigned int *v10; // x22
  unsigned int v11; // w8
  unsigned int *v12; // x24
  unsigned int v13; // w8
  unsigned int v14; // w21
  unsigned int v15; // t1

  v8 = 4 * (unsigned int)adreno_snapshot_regs_count(*(_QWORD *)(a4 + 16)) + 16LL;
  if ( v8 <= a3 )
  {
    *a2 = *(_DWORD *)(a4 + 8) == 3;
    a2[1] = *(_DWORD *)a4;
    a2[2] = *(_DWORD *)(a4 + 4);
    a2[3] = -1;
    kgsl_regmap_write(
      a1 + 1650,
      ((*(_DWORD *)(a4 + 4) & 3) << 12) | ((*(_DWORD *)a4 & 7) << 8) | (16 * (*(_DWORD *)(a4 + 8) & 3u)));
    v9 = *(_QWORD *)(a4 + 24);
    if ( v9 )
      kgsl_regmap_write(a1 + 1650, *(unsigned int *)(v9 + 8));
    v10 = *(unsigned int **)(a4 + 16);
    v11 = *v10;
    if ( *v10 != -1 )
    {
      v12 = a2 + 4;
      do
      {
        if ( v10[1] == v11 )
        {
          *v12++ = v11;
          v14 = *v10;
          v13 = v10[1];
        }
        else
        {
          *v12 = v11 | 0x80000000;
          v13 = v10[1];
          v12[1] = v13;
          v12 += 2;
          v14 = *v10;
        }
        while ( v14 <= v13 )
        {
          *v12++ = kgsl_regmap_read(a1 + 1650);
          ++v14;
          v13 = v10[1];
        }
        v15 = v10[2];
        v10 += 2;
        v11 = v15;
      }
      while ( v15 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_legacy_snapshot_mvc__rs, "gen7_legacy_snapshot_mvc") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v8;
}
