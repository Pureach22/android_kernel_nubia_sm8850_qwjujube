__int64 __fastcall gen8_legacy_snapshot_shader(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  _DWORD *v4; // x21
  int v8; // w8
  unsigned __int64 v9; // x23
  _DWORD *v10; // x20
  unsigned __int64 v11; // x8

  v4 = *(_DWORD **)a4;
  if ( (unsigned __int64)(unsigned int)(4 * *(_DWORD *)(*(_QWORD *)a4 + 4LL)) + 32 <= a3 )
  {
    *a2 = *v4;
    if ( v4[6] == 1 )
      v8 = a4[4];
    else
      v8 = -1;
    a2[1] = v8;
    a2[2] = a4[2];
    a2[3] = a4[3];
    a2[4] = v4[4];
    a2[5] = v4[5];
    a2[6] = a4[6];
    a2[7] = v4[1];
    kgsl_regmap_write(
      a1 + 1650,
      ((a4[6] & 0x1F) << 26)
    | ((a4[4] & 0x1F) << 21)
    | ((v4[5] & 7) << 18)
    | ((v4[4] & 3) << 16)
    | ((unsigned __int8)*v4 << 8)
    | (16 * (a4[3] & 0xF))
    | a4[2] & 0xFu);
    __dsb(0xFu);
    if ( v4[1] )
    {
      v9 = 0;
      v10 = a2 + 8;
      do
      {
        v10[v9++] = kgsl_regmap_read(a1 + 1650);
        v11 = (unsigned int)v4[1];
      }
      while ( v9 < v11 );
      return (unsigned int)(4 * v11) + 32LL;
    }
    else
    {
      return 32;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_legacy_snapshot_shader__rs, "gen8_legacy_snapshot_shader") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "SHADER MEMORY");
    return 0;
  }
}
