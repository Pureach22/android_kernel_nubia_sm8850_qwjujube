__int64 sub_1F005C()
{
  __int64 v0; // x22

  if ( (v0 & 0x8000000000000LL) == 0 )
    JUMPOUT(0x1F2328);
  return wlan_reg_get_min_max_bw_for_chan_index();
}
