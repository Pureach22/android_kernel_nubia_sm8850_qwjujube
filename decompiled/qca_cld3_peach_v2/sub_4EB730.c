__int64 __fastcall sub_4EB730(long double a1, long double a2, float a3, __n128 a4)
{
  short float v4; // h12
  short float v5; // h29

  *(short float *)&a3 = v5 + (short float)(v4 * *(short float *)a4.n128_u16);
  return wma_disable_uapsd_mode(a1, a2, a3);
}
