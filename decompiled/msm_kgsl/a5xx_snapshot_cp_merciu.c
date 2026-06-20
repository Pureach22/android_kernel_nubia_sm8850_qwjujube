unsigned __int64 __fastcall a5xx_snapshot_cp_merciu(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  int v4; // w9
  unsigned int v5; // w8
  __int64 v9; // x21
  unsigned __int64 v10; // x20
  _DWORD *v12; // x23

  v4 = **(_DWORD **)(a1 + 14264);
  if ( v4 == 510 )
    v5 = 64;
  else
    v5 = 128;
  if ( (unsigned int)(v4 - 505) < 2 || v4 == 540 || v4 == 508 || v4 == 512 )
    v9 = 2048;
  else
    v9 = v5;
  v10 = (4 * (_DWORD)v9) | 8u;
  if ( v10 <= a3 )
  {
    *a2 = 12;
    a2[1] = v9;
    kgsl_regmap_write(a1 + 13200, 0);
    v12 = a2 + 3;
    do
    {
      *(v12 - 1) = kgsl_regmap_read(a1 + 13200);
      --v9;
      *v12 = kgsl_regmap_read(a1 + 13200);
      v12 += 2;
    }
    while ( v9 );
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a5xx_snapshot_cp_merciu__rs, "a5xx_snapshot_cp_merciu") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "CP MERCIU DEBUG");
    return 0;
  }
  return v10;
}
