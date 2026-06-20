__int64 __fastcall gen8_snapshot_cx_dbgc_debugbus_block(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  _DWORD *v8; // x22
  __int64 i; // x23
  _DWORD *v10; // x22
  __int64 v11; // x21
  bool v12; // cf
  _DWORD *v13; // x22
  __int64 v14; // x21
  __int64 v15; // x21
  _DWORD *v16; // x28
  unsigned int v17; // w26

  if ( a3 > 0x807 )
  {
    *a2 = *a4;
    a2[1] = 512;
    if ( *a4 == 3 )
    {
      v8 = a2 + 2;
      kgsl_regmap_write(a1 + 1650, 1879048192);
      kgsl_regmap_write(a1 + 1650, 671088640);
      kgsl_regmap_write(a1 + 1650, 12);
      kgsl_regmap_write(a1 + 1650, 240);
      kgsl_regmap_write(a1 + 1650, 117440512);
      for ( i = 0; i != 128; ++i )
      {
        gen8_cx_gc_us_i_0_debugbus_read(a1, (unsigned int)*a4, (unsigned int)i, v8);
        v8 += 2;
      }
      v10 = a2 + 386;
      v11 = -64;
      do
      {
        gen8_cx_gc_us_i_0_debugbus_read(a1, (unsigned int)*a4, (unsigned int)(v11 + 256), v10);
        v12 = __CFADD__(v11++, 1);
        v10 += 2;
      }
      while ( !v12 );
      v13 = a2 + 258;
      v14 = -64;
      do
      {
        gen8_cx_gc_us_i_0_debugbus_read(a1, (unsigned int)*a4, (unsigned int)(v14 + 192), v13);
        v12 = __CFADD__(v14++, 1);
        v13 += 2;
      }
      while ( !v12 );
    }
    else
    {
      v15 = 0;
      v16 = a2 + 3;
      do
      {
        v17 = v15 + ((*a4 & 0x1FF) << 16);
        kgsl_regmap_write(a1 + 1650, v17);
        kgsl_regmap_write(a1 + 1650, v17);
        kgsl_regmap_write(a1 + 1650, v17);
        kgsl_regmap_write(a1 + 1650, v17);
        _const_udelay(4295);
        *(v16 - 1) = kgsl_regmap_read(a1 + 1650);
        ++v15;
        *v16 = kgsl_regmap_read(a1 + 1650);
        v16 += 2;
      }
      while ( v15 != 256 );
    }
    return 2056;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_cx_dbgc_debugbus_block__rs, "gen8_snapshot_cx_dbgc_debugbus_block") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "DEBUGBUS");
    return 0;
  }
}
