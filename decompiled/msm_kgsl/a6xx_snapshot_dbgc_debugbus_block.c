unsigned __int64 __fastcall a6xx_snapshot_dbgc_debugbus_block(__int64 a1, int *a2, unsigned __int64 a3, int *a4)
{
  __int64 v4; // x21
  unsigned __int64 v6; // x19
  unsigned int v7; // w9
  int v8; // w8
  int v9; // w24
  int v10; // w22
  int v11; // w23
  _DWORD *v12; // x25
  _DWORD *v13; // x27

  v4 = (unsigned int)a4[1];
  v6 = 8 * v4 + 8;
  if ( v6 <= a3 )
  {
    *a2 = *a4;
    if ( *a4 == 3 && **(_DWORD **)(a1 + 14264) != 630 )
      *a2 = 26;
    a2[1] = 2 * v4;
    v7 = **(_DWORD **)(a1 + 14264) - 615;
    v8 = *a4;
    if ( v7 <= 0xF && (((1 << v7) & 0x1B) != 0 || **(_DWORD **)(a1 + 14264) == 630) && v8 == 24 )
      v8 = 19;
    if ( (_DWORD)v4 )
    {
      v9 = v8 << 8;
      v10 = 0;
      v11 = 0;
      v12 = a2 + 2;
      do
      {
        v13 = &v12[v10];
        kgsl_regmap_write(a1 + 13200, v11 | (unsigned int)v9);
        kgsl_regmap_write(a1 + 13200, v11 | (unsigned int)v9);
        kgsl_regmap_write(a1 + 13200, v11 | (unsigned int)v9);
        kgsl_regmap_write(a1 + 13200, v11 | (unsigned int)v9);
        _const_udelay(4295);
        *v13 = kgsl_regmap_read(a1 + 13200);
        ++v11;
        v10 += 2;
        v13[1] = kgsl_regmap_read(a1 + 13200);
      }
      while ( (_DWORD)v4 != v11 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a6xx_snapshot_dbgc_debugbus_block__rs, "a6xx_snapshot_dbgc_debugbus_block") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "DEBUGBUS");
    return 0;
  }
  return v6;
}
