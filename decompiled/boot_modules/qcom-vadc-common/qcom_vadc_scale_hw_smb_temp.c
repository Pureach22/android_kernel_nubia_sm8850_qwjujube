__int64 __fastcall qcom_vadc_scale_hw_smb_temp(_DWORD *a1, __int64 a2, __int16 a3, int *a4)
{
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x9
  int v6; // w8

  v4 = *(unsigned int *)(a2 + 8);
  v5 = 1875000LL * ((__int16)(100 * a3) & (unsigned int)~((__int16)(100 * a3) >> 31));
  v6 = 419400;
  if ( v5 >= v4 )
    v6 = 419400 - (__int64)(v5 / v4 * (unsigned int)a1[1]) / (unsigned int)(356 * *a1);
  *a4 = v6;
  return 0;
}
