__int64 __fastcall gen7_legacy_snapshot_shader(__int64 a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  int *v4; // x20
  int v6; // w8
  unsigned __int16 v7; // w9
  int v8; // w8
  unsigned int v11; // w23
  _DWORD *v12; // x22
  unsigned int v13; // w8

  v4 = *(int **)a4;
  if ( (unsigned __int64)(unsigned int)(4 * *(_DWORD *)(*(_QWORD *)a4 + 4LL)) + 24 > a3 )
  {
    if ( (unsigned int)__ratelimit(&gen7_legacy_snapshot_shader__rs, "gen7_legacy_snapshot_shader") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "SHADER MEMORY");
    return 0;
  }
  v6 = **(_DWORD **)(a1 + 14264);
  if ( v6 > 459775 )
  {
    if ( v6 == 459776 || v6 == 462336 )
      goto LABEL_11;
    v7 = 4352;
  }
  else
  {
    if ( (unsigned int)(v6 - 458752) < 2 )
      goto LABEL_11;
    v7 = 768;
  }
  if ( v6 != (v7 | 0x70000) )
  {
    v8 = *v4;
    goto LABEL_16;
  }
LABEL_11:
  v8 = *v4;
  if ( (unsigned int)*v4 <= 0x35 && ((1LL << v8) & 0x30018000000000LL) != 0 )
    return 0;
LABEL_16:
  *a2 = v8;
  a2[1] = a4[2];
  a2[5] = v4[1];
  a2[2] = a4[3];
  a2[4] = v4[5];
  a2[3] = v4[4];
  kgsl_regmap_write(
    a1 + 13200,
    ((v4[5] & 3) << 18) | ((v4[4] & 3) << 16) | ((unsigned __int8)*v4 << 8) | (16 * (a4[3] & 0xF)) | a4[2] & 0xFu);
  __dsb(0xFu);
  if ( !v4[1] )
    return 24;
  v11 = 0;
  v12 = a2 + 6;
  do
  {
    v12[v11++] = kgsl_regmap_read(a1 + 13200);
    v13 = v4[1];
  }
  while ( v11 < v13 );
  return 4 * v13 + 24LL;
}
