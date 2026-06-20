__int64 __fastcall ipa3_cal_ep_holb_scale_base_val(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w9
  unsigned int v4; // w10

  v2 = 1;
  v3 = 31;
  do
  {
    v4 = (unsigned int)result / v2;
    v2 <<= v3 != 31;
  }
  while ( v4 >= 0x20 && v3-- != 0 );
  *(_DWORD *)(a2 + 4) = v4;
  *(_DWORD *)(a2 + 8) = v2;
  return result;
}
