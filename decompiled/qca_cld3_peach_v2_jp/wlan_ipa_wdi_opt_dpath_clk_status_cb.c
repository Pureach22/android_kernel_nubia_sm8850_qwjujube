__int64 __fastcall wlan_ipa_wdi_opt_dpath_clk_status_cb(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x1
  int v13; // w2
  int v14; // w3
  int v15; // w4
  int v16; // w5
  int v17; // w6
  int v18; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: notification of clk from ipa, status: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ipa_wdi_opt_dpath_clk_status_cb",
    a2 & 1);
  ++*(_DWORD *)(a1 + 8412);
  if ( (a2 & 1) != 0 )
    qdf_event_set(a1 + 8152, v12);
  else
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_clk_status_cb",
      (int)"ipa failed to enable clk",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      vars0);
  return 0;
}
