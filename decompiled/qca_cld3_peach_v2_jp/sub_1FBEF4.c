__int64 sub_1FBEF4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x202EC8);
  return wlan_scan_cfg_get_active_6g_dwelltime();
}
