__int64 __fastcall target_if_p2p_send_ap_assist_dfs_group_params(
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
  __int64 wmi_unified_hdl; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( wmi_unified_hdl )
    return wmi_unified_p2p_send_ap_assist_dfs_group_params(wmi_unified_hdl);
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Invalid wmi handle",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "target_if_p2p_send_ap_assist_dfs_group_params");
  return 4;
}
