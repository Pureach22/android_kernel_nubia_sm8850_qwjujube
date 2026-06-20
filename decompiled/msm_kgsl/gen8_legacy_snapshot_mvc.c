unsigned __int64 __fastcall gen8_legacy_snapshot_mvc(_QWORD *a1, __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned int *v8; // x21
  unsigned __int64 v9; // x20
  int v10; // w8
  __int64 v11; // x8
  unsigned int v12; // w8
  unsigned int *v13; // x23
  unsigned int v14; // w8
  unsigned int v15; // w22
  unsigned int v16; // t1

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
    kgsl_regmap_write(
      a1 + 1650,
      ((a4[4] & 0xF) << 12) | ((a4[3] & 7) << 16) | ((a4[2] & 0xF) << 8) | (16 * (a4[5] & 3)) | 0x800000u);
    v11 = *(_QWORD *)(*(_QWORD *)a4 + 24LL);
    if ( v11 )
      kgsl_regmap_write(a1 + 1650, *(unsigned int *)(v11 + 8));
    __dsb(0xFu);
    v12 = *v8;
    if ( *v8 != -1 )
    {
      v13 = (unsigned int *)(a2 + 28);
      do
      {
        if ( v8[1] == v12 )
        {
          *v13++ = v12;
          v15 = *v8;
          v14 = v8[1];
        }
        else
        {
          *v13 = v12 | 0x80000000;
          v14 = v8[1];
          v13[1] = v14;
          v13 += 2;
          v15 = *v8;
        }
        while ( v15 <= v14 )
        {
          *v13++ = kgsl_regmap_read(a1 + 1650);
          ++v15;
          v14 = v8[1];
        }
        v16 = v8[2];
        v8 += 2;
        v12 = v16;
      }
      while ( v16 != -1 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_legacy_snapshot_mvc__rs, "gen8_legacy_snapshot_mvc") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    return 0;
  }
  return v9;
}
