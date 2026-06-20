__int64 __fastcall hdd_wlan_shutdown(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 **context; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x0
  __int64 v26; // x19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  void (__fastcall *v63)(_QWORD); // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7

  context = (__int64 **)_cds_get_context(71, (__int64)"hdd_wlan_shutdown", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x33u, 4u, "%s: WLAN driver shutting down!", v9, v10, v11, v12, v13, v14, v15, v16, "hdd_wlan_shutdown");
  v25 = _cds_get_context(51, (__int64)"hdd_wlan_shutdown", v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v25 )
    return 16;
  v26 = (__int64)v25;
  if ( (ucfg_ipa_is_enabled(v25) & 1) != 0 )
  {
    ucfg_ipa_uc_force_pipe_shutdown(*(_QWORD *)(v26 + 8));
    if ( (unsigned int)pld_is_fw_rejuvenate(*(_QWORD *)(v26 + 96)) || (unsigned int)pld_is_pdr(*(_QWORD *)(v26 + 96)) )
      v27 = ucfg_ipa_fw_rejuvenate_send_msg(*(_QWORD *)(v26 + 8));
  }
  hdd_set_connection_in_progress(0, v27, v28, v29, v30, v31, v32, v33, v34);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Invoking packetdump deregistration API",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "hdd_wlan_shutdown");
  v43 = wlan_deregister_txrx_packetdump();
  if ( *(_BYTE *)(v26 + 184) == 1 )
  {
    scheduler_resume(v43);
    v52 = *(_QWORD *)v26;
    *(_WORD *)(v26 + 184) = 0;
    *(_BYTE *)(v26 + 488) = 0;
    v44 = ucfg_pmo_resume_all_components(v52, 0);
  }
  hdd_reset_all_adapters((__int64 *)v26, v44, v45, v46, v47, v48, v49, v50, v51);
  v53 = ucfg_ipa_uc_ssr_cleanup(*(_QWORD *)(v26 + 8));
  if ( context )
  {
    if ( *context )
    {
      v62 = **context;
      if ( v62 )
      {
        v63 = *(void (__fastcall **)(_QWORD))(v62 + 504);
        if ( v63 )
        {
          if ( *((_DWORD *)v63 - 1) != -440107680 )
            __break(0x8228u);
          v63(v53);
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "cdp_flush_cache_rx_queue");
    }
  }
  hdd_deregister_cb(v26, v54, v55, v56, v57, v58, v59, v60, v61);
  hdd_wlan_stop_modules((_QWORD *)v26, 0, v65, v66, v67, v68, v69, v70, v71, v72);
  hdd_lpass_notify_stop(v26);
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: WLAN driver shutdown complete",
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    "hdd_wlan_shutdown");
  return 0;
}
