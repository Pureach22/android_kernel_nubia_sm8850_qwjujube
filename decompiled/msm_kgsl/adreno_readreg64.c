__int64 __fastcall adreno_readreg64(__int64 result, unsigned int a2, unsigned int a3, __int64 *a4)
{
  __int64 v5; // x20
  unsigned int v6; // w22
  __int64 v7; // x22
  __int64 v8; // x8

  v5 = result;
  if ( a2 > 0x13 || *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(result + 14264) + 40LL) + 4LL * a2) > 0xFFFFFFFD )
  {
    v7 = 0;
    if ( a3 <= 0x13 )
      goto LABEL_6;
LABEL_8:
    v8 = 0;
    goto LABEL_9;
  }
  v6 = a3;
  result = kgsl_regmap_read(result + 13200);
  a3 = v6;
  v7 = (unsigned int)result;
  if ( a3 > 0x13 )
    goto LABEL_8;
LABEL_6:
  if ( *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(v5 + 14264) + 40LL) + 4LL * a3) > 0xFFFFFFFD )
    goto LABEL_8;
  result = kgsl_regmap_read(v5 + 13200);
  v8 = result << 32;
LABEL_9:
  *a4 = v8 | v7;
  return result;
}
