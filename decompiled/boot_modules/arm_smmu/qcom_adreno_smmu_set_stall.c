_BYTE *__fastcall qcom_adreno_smmu_set_stall(_BYTE *result, char a2)
{
  __int64 v2; // x8
  int v3; // w10
  int v4; // w11
  int v5; // w8

  v2 = 1LL << result[48];
  v3 = *(_DWORD *)(*(_QWORD *)result + 340LL);
  v4 = v3 & ~(_DWORD)v2;
  v5 = v3 | v2;
  if ( (a2 & 1) == 0 )
    v5 = v4;
  *(_DWORD *)(*(_QWORD *)result + 340LL) = v5;
  return result;
}
