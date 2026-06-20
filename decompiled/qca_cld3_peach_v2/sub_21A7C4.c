__int64 sub_21A7C4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x221798);
  return wlan_scan_cfg_get_active_6g_dwelltime();
}
