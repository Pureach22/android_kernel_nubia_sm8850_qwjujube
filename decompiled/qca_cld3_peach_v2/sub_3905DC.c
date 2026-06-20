__int64 sub_3905DC()
{
  __asm { STLLR           W23, [X6] }
  return wlan_hdd_cfg80211_set_txpower();
}
