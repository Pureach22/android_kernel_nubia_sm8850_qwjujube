__int64 __fastcall hdd_deconfigure_cds(
        __int64 *a1,
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v10 = qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_deconfigure_cds");
  wlan_hdd_hang_event_notifier_unregister(v10);
  wlan_hdd_twt_deinit(a1);
  wlan_hdd_deinit_chan_info((__int64)a1);
  wlan_hdd_tsf_deinit(a1);
  if ( (unsigned int)policy_mgr_deregister_mode_change_cb(*a1) )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to deregister mode change cb with Policy Manager",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_deconfigure_cds");
  v19 = cds_disable(*a1);
  if ( v19 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to Disable the CDS Modules! :%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_deconfigure_cds",
      v19);
    v28 = -22;
  }
  else
  {
    v28 = 0;
  }
  if ( (unsigned int)ucfg_ipa_uc_ol_deinit(a1[1]) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to disconnect pipes",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "hdd_deconfigure_cds");
    v28 = -22;
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v29, v30, v31, v32, v33, v34, v35, v36, "hdd_deconfigure_cds");
  return v28;
}
