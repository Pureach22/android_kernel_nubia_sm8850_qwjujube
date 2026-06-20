unsigned __int64 __fastcall a5xx_snapshot_debugbus_block(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  __int64 v4; // x23
  unsigned __int64 v6; // x19
  int v8; // w24
  int v9; // w25
  _DWORD *v10; // x26
  _DWORD *v11; // x28
  unsigned int v12; // w22

  v4 = (unsigned int)a4[1];
  v6 = 8 * v4 + 8;
  if ( v6 <= a3 )
  {
    *a2 = *a4;
    a2[1] = 2 * v4;
    if ( (_DWORD)v4 )
    {
      v8 = 0;
      v9 = 0;
      v10 = a2 + 2;
      do
      {
        v11 = &v10[v8];
        v12 = v9 | (*a4 << 8);
        kgsl_regmap_write(a1 + 1650, v12);
        kgsl_regmap_write(a1 + 1650, v12);
        kgsl_regmap_write(a1 + 1650, v12);
        kgsl_regmap_write(a1 + 1650, v12);
        *v11 = kgsl_regmap_read(a1 + 1650);
        ++v9;
        v8 += 2;
        v11[1] = kgsl_regmap_read(a1 + 1650);
      }
      while ( (_DWORD)v4 != v9 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_debugbus_block__rs, "a5xx_snapshot_debugbus_block") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "DEBUGBUS");
    return 0;
  }
  return v6;
}
