__int64 sub_751340()
{
  int v0; // w12

  if ( (v0 & 0x10000) == 0 )
    JUMPOUT(0x74C0B8);
  return wlan_dp_stc_update_logmask();
}
