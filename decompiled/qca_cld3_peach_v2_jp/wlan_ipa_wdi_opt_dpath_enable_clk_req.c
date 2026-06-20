__int64 __fastcall wlan_ipa_wdi_opt_dpath_enable_clk_req(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x0

  qdf_event_reset(a1 + 8152);
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: request ipa to enable clock",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "wlan_ipa_wdi_opt_dpath_enable_clk_req");
  v10 = *(unsigned int *)(a1 + 7460);
  ++*(_DWORD *)(a1 + 8416);
  return ipa_wdi_opt_dpath_enable_clk_per_inst(v10);
}
