__int64 __fastcall wlan_ipa_wdi_opt_dpath_disable_clk_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0

  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: request ipa to disable clock",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_wdi_opt_dpath_disable_clk_req");
  v10 = *(unsigned int *)(a1 + 7460);
  ++*(_DWORD *)(a1 + 8420);
  return ipa_wdi_opt_dpath_disable_clk_per_inst(v10);
}
