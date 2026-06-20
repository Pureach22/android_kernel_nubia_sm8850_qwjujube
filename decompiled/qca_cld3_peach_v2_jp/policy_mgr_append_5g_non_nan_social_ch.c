__int64 __fastcall policy_mgr_append_5g_non_nan_social_ch(
        __int64 result,
        unsigned int *a2,
        _DWORD *a3,
        __int64 a4,
        _DWORD *a5,
        unsigned int a6)
{
  __int64 v11; // x24
  unsigned __int64 v12; // x25
  unsigned int v13; // w27
  unsigned int v14; // w10
  unsigned int *v15; // x8

  if ( *a3 )
  {
    v11 = result;
    v12 = 0;
    do
    {
      if ( wlan_reg_is_5ghz_ch_freq(*a2) || (result = wlan_reg_is_6ghz_chan_freq(*a2), (result & 1) != 0) )
      {
        v13 = *a2;
        result = wlan_nan_get_5ghz_social_ch_freq(v11);
        if ( v13 != (_DWORD)result )
        {
          v14 = a2[2];
          v15 = (unsigned int *)(a4 + 12LL * (unsigned int)*a5);
          *v15 = *a2;
          v15[1] = a6;
          v15[2] = v14;
          ++*a5;
        }
      }
      ++v12;
      a2 += 3;
    }
    while ( v12 < (unsigned int)*a3 );
  }
  return result;
}
