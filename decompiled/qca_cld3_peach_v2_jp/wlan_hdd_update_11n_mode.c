__int64 __fastcall wlan_hdd_update_11n_mode(__int64 *a1)
{
  _DWORD *v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0

  v2 = (_DWORD *)a1[13];
  if ( (sme_is_feature_supported_by_fw(2) & 1) != 0 )
    return qdf_trace_msg(0x33u, 8u, "%s: support 11ac", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_hdd_update_11n_mode");
  result = qdf_trace_msg(0x33u, 8u, "%s: not support 11ac", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_hdd_update_11n_mode");
  if ( (*v2 & 0xFFFFFFFE) == 8 )
  {
    *v2 = 4;
    wlan_mlme_set_sap_11ac_override(*a1, 0);
    return wlan_mlme_set_go_11ac_override(*a1, 0);
  }
  return result;
}
