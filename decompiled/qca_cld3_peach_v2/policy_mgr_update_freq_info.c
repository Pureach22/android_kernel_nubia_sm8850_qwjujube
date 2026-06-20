__int64 __fastcall policy_mgr_update_freq_info(__int64 result, _DWORD *a2, unsigned int a3, unsigned int a4)
{
  int v5; // w8
  _DWORD *v6; // x21
  unsigned int v7; // w20
  int v8; // w0
  unsigned int v9; // w20
  unsigned int v10; // w20
  unsigned int v11; // w22
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned int v14; // w8

  v5 = a2[6];
  v6 = (_DWORD *)(result + 32LL * a3 + 16LL * a4 + 1204);
  if ( (v5 & 1) != 0 )
  {
    v7 = a2[58];
    if ( v7 <= (unsigned int)wlan_reg_min_24ghz_chan_freq() )
      v8 = wlan_reg_min_24ghz_chan_freq();
    else
      v8 = a2[58];
    *v6 = v8;
    v9 = a2[59];
    result = wlan_reg_max_24ghz_chan_freq();
    if ( v9 )
    {
      if ( v9 >= (unsigned int)result )
        result = wlan_reg_max_24ghz_chan_freq();
      else
        result = (unsigned int)a2[59];
    }
    v6[1] = result;
    v5 = a2[6];
  }
  if ( (v5 & 2) != 0 )
  {
    if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
      v10 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
    else
      v10 = wlan_reg_max_5ghz_chan_freq();
    v11 = a2[60];
    if ( v11 <= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
      result = wlan_reg_min_5ghz_chan_freq();
    else
      result = (unsigned int)a2[60];
    v6[2] = result;
    v12 = a2[61];
    if ( v12 >= v10 )
      v13 = v10;
    else
      v13 = a2[61];
    if ( v12 )
      v14 = v13;
    else
      v14 = v10;
    v6[3] = v14;
  }
  return result;
}
