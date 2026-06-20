__int64 __fastcall gen7_snapshot_cx_dbgc_debugbus_block(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  __int64 v5; // x21
  __int64 v7; // x23
  _DWORD *v8; // x26
  unsigned int v9; // w22

  if ( a3 > 0x807 )
  {
    v7 = 0;
    v8 = a2 + 3;
    v5 = 2056;
    *a2 = *a4;
    a2[1] = 512;
    do
    {
      v9 = v7 + ((*a4 & 0x1FF) << 16);
      kgsl_regmap_write(a1 + 1650, v9);
      kgsl_regmap_write(a1 + 1650, v9);
      kgsl_regmap_write(a1 + 1650, v9);
      kgsl_regmap_write(a1 + 1650, v9);
      _const_udelay(4295);
      *(v8 - 1) = kgsl_regmap_read(a1 + 1650);
      ++v7;
      *v8 = kgsl_regmap_read(a1 + 1650);
      v8 += 2;
    }
    while ( v7 != 256 );
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_snapshot_cx_dbgc_debugbus_block__rs, "gen7_snapshot_cx_dbgc_debugbus_block") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "DEBUGBUS");
    return 0;
  }
  return v5;
}
