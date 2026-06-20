__int64 __fastcall qcom_vadc_scale_hw_smb1398_temp(_DWORD *a1, __int64 a2, __int16 a3, int *a4)
{
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x9
  int v6; // w8

  v4 = *(unsigned int *)(a2 + 8);
  v5 = 1875000LL * (a3 & (unsigned int)~(a3 >> 31));
  v6 = -268235;
  if ( v5 >= v4 )
    v6 = 100 * v5 / v4 * (unsigned int)a1[1] / (unsigned int)(340 * *a1) - 268235;
  *a4 = v6;
  return 0;
}
