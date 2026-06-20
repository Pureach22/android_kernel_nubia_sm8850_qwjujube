__int64 __fastcall wlan_hdd_register_mcc_quota_event_callback(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return ucfg_p2p_register_mcc_quota_event_os_if_cb(
           *a1,
           (__int64)&wlan_cfg80211_indicate_mcc_quota,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9);
}
