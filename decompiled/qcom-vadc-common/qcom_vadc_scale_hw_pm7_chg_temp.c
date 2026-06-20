__int64 __fastcall qcom_vadc_scale_hw_pm7_chg_temp(unsigned int *a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x8

  v4 = 1875000LL * (a3 & (unsigned int)~(a3 >> 31));
  v5 = *(unsigned int *)(a2 + 8);
  if ( v4 >= v5 )
  {
    v7 = (unsigned __int128)((30303LL * (int)((__int64)(v4 / v5 * a1[1]) / *a1) - 27712000000LL)
                           * (__int128)0x29F16B11C6D1E109LL) >> 64;
    v6 = (v7 >> 14) + ((unsigned __int64)v7 >> 63);
  }
  else
  {
    v6 = -277120;
  }
  *a4 = v6 & ~(unsigned int)(v6 >> 63);
  return 0;
}
