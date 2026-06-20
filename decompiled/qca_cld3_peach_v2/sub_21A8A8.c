__int64 sub_21A8A8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x22187C);
  return wlan_scan_cfg_get_passive_6g_dwelltime();
}
