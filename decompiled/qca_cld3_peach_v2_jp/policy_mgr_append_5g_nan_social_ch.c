__int64 __fastcall policy_mgr_append_5g_nan_social_ch(
        __int64 result,
        int *a2,
        _DWORD *a3,
        __int64 a4,
        _DWORD *a5,
        int a6)
{
  __int64 v11; // x24
  unsigned __int64 v12; // x25
  int v13; // w26
  int v14; // w10
  int *v15; // x8

  if ( *a3 )
  {
    v11 = result;
    v12 = 0;
    while ( 1 )
    {
      v13 = *a2;
      result = wlan_nan_get_5ghz_social_ch_freq(v11);
      if ( v13 == (_DWORD)result )
        break;
      ++v12;
      a2 += 3;
      if ( v12 >= (unsigned int)*a3 )
        return result;
    }
    v14 = a2[2];
    v15 = (int *)(a4 + 12LL * (unsigned int)*a5);
    *v15 = *a2;
    v15[1] = a6;
    v15[2] = v14;
    ++*a5;
  }
  return result;
}
