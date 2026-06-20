__int64 __fastcall wlan_cfg80211_abort_scan(__int64 a1)
{
  int v1; // w19

  v1 = *(unsigned __int8 *)(a1 + 40);
  if ( (unsigned int)ucfg_scan_get_pdev_status(a1) )
    wlan_abort_scan(a1, v1, 0xFFFFFFFF, 0xFFFFFFFF, 1);
  return 0;
}
