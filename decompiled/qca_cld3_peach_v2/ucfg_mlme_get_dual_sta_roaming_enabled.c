__int64 __fastcall ucfg_mlme_get_dual_sta_roaming_enabled(__int64 a1)
{
  return wlan_mlme_get_dual_sta_roaming_enabled(a1) & 1;
}
