__int64 __fastcall wlan_cfg80211_tdls_is_fw_wideband_capable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 216);
  if ( !v1 )
    return 0;
  v2 = *(_QWORD *)(v1 + 80);
  if ( v2 )
    LOBYTE(v2) = ucfg_tdls_is_fw_wideband_capable(v2);
  return v2 & 1;
}
