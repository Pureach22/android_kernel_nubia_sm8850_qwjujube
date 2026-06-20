__int64 __fastcall util_scan_scm_freq_to_band(unsigned __int16 a1)
{
  if ( wlan_reg_is_24ghz_ch_freq(a1) )
    return 1;
  else
    return 2;
}
