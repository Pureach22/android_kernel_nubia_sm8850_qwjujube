__int64 __fastcall wlan_cfg80211_unlink_bss_list(__int64 a1, __int64 a2)
{
  __int64 *v2; // x9

  v2 = *(__int64 **)(a1 + 24);
  if ( v2 )
    return _wlan_cfg80211_unlink_bss_list(
             *v2,
             a1,
             (unsigned __int8 *)(a2 + 1),
             (const char *)(a2 + 14),
             *(_BYTE *)(a2 + 13));
  else
    return qdf_trace_msg(72, 2, "%s: os_priv is NULL", "wlan_cfg80211_unlink_bss_list");
}
