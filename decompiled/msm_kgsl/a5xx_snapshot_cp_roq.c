unsigned __int64 __fastcall a5xx_snapshot_cp_roq(__int64 a1, _DWORD *a2, unsigned __int64 a3)
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
    v7 = 256;
  else
    v7 = 512;
  v8 = (((v7 >> 8) & 3) << 10) | 8;
  if ( v8 <= a3 )
  {
    *a2 = 10;
    a2[1] = v7;
    kgsl_regmap_read_indexed(a1 + 13200, 2081, 2082, a2 + 2);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_cp_roq__rs, "a5xx_snapshot_cp_roq") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "CP ROQ DEBUG");
    return 0;
  }
  return v8;
}
