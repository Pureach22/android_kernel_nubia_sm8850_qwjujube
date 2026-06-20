__int64 __fastcall target_if_p2p_unreg_assist_dfs_group_bmiss_evt_handler(
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
  _QWORD *wmi_unified_hdl; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  wmi_unified_hdl = (_QWORD *)lmac_get_wmi_unified_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( wmi_unified_hdl )
  {
    v18 = wmi_unified_unregister_event(wmi_unified_hdl, 0x118u, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( v18 )
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: Failed to unregister event handler %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "target_if_p2p_unreg_assist_dfs_group_bmiss_evt_handler",
        v18);
  }
  else
  {
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
      "target_if_p2p_unreg_assist_dfs_group_bmiss_evt_handler");
    return 4;
  }
  return v18;
}
