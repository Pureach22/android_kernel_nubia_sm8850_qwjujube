bool __fastcall policy_mgr_is_sta_chan_valid_for_connect_and_roam(__int64 a1, unsigned __int16 a2)
{
  __int64 v2; // x21
  char v4; // w22
  int sap_mode_count; // w0
  _BOOL8 result; // x0

  v2 = *(_QWORD *)(a1 + 80);
  result = true;
  if ( v2 )
  {
    v4 = wlan_scan_cfg_skip_6g_and_indoor_freq(*(_QWORD *)(a1 + 80));
    sap_mode_count = policy_mgr_get_sap_mode_count(v2, nullptr);
    if ( (v4 & 1) != 0
      && sap_mode_count
      && (policy_mgr_is_hw_dbs_capable(v2) & 1) == 0
      && (wlan_reg_is_6ghz_chan_freq(a2) || (wlan_reg_is_freq_indoor() & 1) != 0) )
    {
      return false;
    }
  }
  return result;
}
