__int64 __fastcall wlan_cfg80211_tdls_is_fw_6ghz_capable(__int64 a1)
{
  __int64 v1; // x0

  v1 = *(_QWORD *)(a1 + 80);
  if ( v1 )
    LOBYTE(v1) = ucfg_tdls_is_fw_6g_capable(v1);
  return v1 & 1;
}
