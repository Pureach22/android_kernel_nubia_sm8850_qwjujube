unsigned __int64 __fastcall a6xx_snapshot_cp_roq(_QWORD *a1, _DWORD *a2, unsigned __int64 a3)
{
  unsigned int v6; // w0
  __int64 v7; // x25
  unsigned __int64 v8; // x20
  unsigned int v9; // w22
  _DWORD *v10; // x21

  v6 = kgsl_regmap_read(a1 + 1650);
  v7 = v6 >> 14;
  v8 = (unsigned int)(4 * v7 + 8);
  if ( v8 <= a3 )
  {
    v9 = v6;
    *a2 = 10;
    a2[1] = v7;
    kgsl_regmap_write(a1 + 1650, 0);
    if ( v9 >= 0x4000 )
    {
      v10 = a2 + 2;
      do
      {
        --v7;
        *v10++ = kgsl_regmap_read(a1 + 1650);
      }
      while ( v7 );
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a6xx_snapshot_cp_roq__rs, "a6xx_snapshot_cp_roq") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "CP ROQ DEBUG");
    return 0;
  }
  return v8;
}
