__int64 __fastcall qcom_vadc_scale_hw_pm2250_s3_die_temp(unsigned int *a1, __int64 a2, __int16 a3, int *a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  int v6; // w8
  unsigned __int64 v7; // x8

  v4 = 1875000LL * (a3 & (unsigned int)~(a3 >> 31));
  v5 = *(unsigned int *)(a2 + 8);
  if ( v4 >= v5 )
  {
    v7 = (unsigned __int128)(100000 * (720100 - (__int64)(v4 / v5 * a1[1]) / *a1) * (__int128)0x59977B91EE00534BLL) >> 64;
    v6 = (v7 >> 16) + (v7 >> 63);
  }
  else
  {
    v6 = 384539;
  }
  *a4 = v6;
  return 0;
}
