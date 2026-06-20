__int64 __fastcall wlan_convert_freq_to_diag_band(unsigned int a1)
{
  unsigned int v1; // w0

  v1 = wlan_reg_freq_to_band(a1);
  if ( v1 < 3 )
    return v1 + 1;
  else
    return 0;
}
