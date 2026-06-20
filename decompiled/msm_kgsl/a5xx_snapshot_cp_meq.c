unsigned __int64 __fastcall a5xx_snapshot_cp_meq(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w9
  unsigned int v7; // w4
  unsigned __int64 v8; // x19

  v3 = **(_DWORD **)(a1 + 14264);
  v4 = v3 - 505;
  v5 = v3 & 0xFFFFFFFD;
  if ( v4 < 2 || v5 == 508 )
    v7 = 32;
  else
    v7 = 64;
  v8 = (((v7 >> 5) & 3) << 7) | 8;
  if ( v8 <= a3 )
  {
    *a2 = 7;
    a2[1] = v7;
    kgsl_regmap_read_indexed(a1 + 13200, 2083, 2084, a2 + 2);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_cp_meq__rs, "a5xx_snapshot_cp_meq") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "CP MEQ DEBUG");
    return 0;
  }
  return v8;
}
