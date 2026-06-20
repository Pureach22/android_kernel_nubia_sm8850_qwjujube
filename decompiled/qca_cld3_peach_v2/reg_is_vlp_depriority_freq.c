__int64 __fastcall reg_is_vlp_depriority_freq(__int64 a1, unsigned int a2)
{
  unsigned int thresh_priority_freq; // w20

  thresh_priority_freq = wlan_reg_get_thresh_priority_freq();
  return (unsigned int)wlan_reg_is_6ghz_chan_freq(a2) & (thresh_priority_freq >= a2);
}
