__int64 __fastcall gen7_get_gpu_feature_info(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x8

  if ( **(_DWORD **)(result + 14264) >> 1 == 230528 )
  {
    v1 = result;
    v2 = result + 20440;
    result = kgsl_regmap_read(result + 13200);
    v3 = *(_QWORD *)(v1 + 14264);
    *(_BYTE *)(v2 + 3585) = result & 1;
    *(_BYTE *)(v2 + 3586) = (result & 4) != 0;
    if ( (*(_BYTE *)(v3 + 33) & 0x40) != 0 )
      *(_BYTE *)v2 = (result & 2) != 0;
    *(_DWORD *)(v2 + 3588) = result;
  }
  return result;
}
