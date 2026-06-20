__int64 sub_342A54()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hdd_get_wlan_driver_status();
}
