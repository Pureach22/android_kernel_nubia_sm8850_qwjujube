__int64 __fastcall tdls_get_offchan_bw(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w19
  unsigned int max_bw; // w21
  int v6; // w8

  v2 = *(_DWORD *)(a1 + 168);
  max_bw = wlan_mlme_get_max_bw();
  if ( wlan_reg_is_5ghz_ch_freq(a2) || max_bw <= 2 )
  {
    v6 = *(_DWORD *)(a1 + 168);
    if ( (v6 & 8) != 0 )
      return v6 & 0xFFFFFFF7;
  }
  return v2;
}
