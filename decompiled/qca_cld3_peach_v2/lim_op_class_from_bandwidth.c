__int64 __fastcall lim_op_class_from_bandwidth(__int64 a1, unsigned __int16 a2, int a3)
{
  _ReadStatusReg(SP_EL0);
  if ( a3 == 1 )
    wlan_reg_is_24ghz_ch_freq(a2);
  wlan_reg_freq_width_to_chan_op_class();
  _ReadStatusReg(SP_EL0);
  return 0;
}
