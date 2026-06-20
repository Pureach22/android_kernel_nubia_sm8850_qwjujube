unsigned __int64 __fastcall qcom_vadc_decimation_from_dt(unsigned int a1)
{
  unsigned int v1; // w9
  unsigned __int64 result; // x0
  unsigned int v4; // w9

  if ( !a1 )
    return 4294967274LL;
  v1 = a1 - 512;
  result = 4294967274LL;
  if ( v1 <= 0xE00 )
  {
    v4 = ((a1 - ((a1 >> 1) & 0x55555555)) & 0x33333333) + (((a1 - ((a1 >> 1) & 0x55555555)) >> 2) & 0x33333333);
    if ( (16843009 * ((v4 + (v4 >> 4)) & 0xF0F0F0F)) >> 24 <= 1 )
      return __clz(__rbit64(a1 >> 9));
  }
  return result;
}
