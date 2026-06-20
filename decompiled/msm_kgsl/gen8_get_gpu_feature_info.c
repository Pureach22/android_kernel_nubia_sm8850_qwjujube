__int64 __fastcall gen8_get_gpu_feature_info(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x8

  v2 = a1 + 20440;
  result = kgsl_regmap_read(a1 + 13200);
  v4 = *(_QWORD *)(a1 + 14264);
  *(_BYTE *)(v2 + 3585) = result & 1;
  *(_BYTE *)(v2 + 3586) = (result & 4) != 0;
  if ( (*(_BYTE *)(v4 + 33) & 0x40) != 0 )
    *(_BYTE *)v2 = (result & 2) != 0;
  *(_DWORD *)(v2 + 3588) = result;
  return result;
}
