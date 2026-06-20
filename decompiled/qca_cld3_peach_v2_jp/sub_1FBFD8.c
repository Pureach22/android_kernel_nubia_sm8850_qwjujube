__int64 sub_1FBFD8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x202FAC);
  return wlan_scan_cfg_get_passive_6g_dwelltime();
}
