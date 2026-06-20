unsigned __int64 __fastcall drm_dp_max_dprx_data_rate(int a1, int a2)
{
  unsigned int v2; // w8

  v2 = 800000;
  if ( a1 > 999999 )
    v2 = 967100;
  return (unsigned __int64)((v2 * (unsigned __int64)(unsigned int)(10 * a1 * a2) * (unsigned __int128)0x8637BD05AF6C7uLL) >> 64) >> 10;
}
