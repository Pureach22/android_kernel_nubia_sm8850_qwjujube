bool __fastcall policy_mgr_list_has_24GHz_channel(unsigned int *a1, unsigned int a2)
{
  __int64 v5; // x8
  unsigned __int64 v6; // x21
  bool is_24ghz_ch_freq; // w0

  if ( !a2 )
    return 0;
  if ( wlan_reg_is_24ghz_ch_freq(*a1) )
    return 1;
  v5 = 1;
  do
  {
    v6 = v5;
    if ( a2 == v5 )
      break;
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a1[v5]);
    v5 = v6 + 1;
  }
  while ( !is_24ghz_ch_freq );
  return v6 < a2;
}
