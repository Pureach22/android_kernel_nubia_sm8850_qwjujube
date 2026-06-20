__int64 __fastcall wlan_hdd_pld_reinit(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v13; // w24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *context; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _QWORD *v66; // x0
  __int64 v67; // x1
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x21
  char is_ready; // w0
  __int64 v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int gfp_flags; // w19
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  _QWORD *v131; // x0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x0
  const char *v141; // x2
  __int64 v142; // [xsp+0h] [xbp-10h] BYREF
  __int64 v143; // [xsp+8h] [xbp-8h]

  v143 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 8 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid bus type %d->%d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_pld_reinit",
      a2,
      0xFFFFFFFFLL);
    result = 4294967274LL;
    goto LABEL_27;
  }
  v13 = dword_B355E8[a2];
  v142 = 0;
  if ( (qdf_is_driver_unloading() & 1) == 0 )
  {
    result = osif_psoc_sync_trans_resume(a1, &v142);
    if ( (_DWORD)result )
      goto LABEL_27;
    context = _cds_get_context(51, (__int64)"__hdd_soc_recovery_reinit", v25, v26, v27, v28, v29, v30, v31, v32);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: re-probing driver",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "__hdd_soc_recovery_reinit");
    if ( !context )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_ctx is null!",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "__hdd_soc_recovery_reinit",
        v142,
        v143);
      v96 = qdf_status_to_os_return(1u);
LABEL_26:
      osif_psoc_sync_trans_stop(v142);
      hdd_start_complete(0);
      result = v96;
      goto LABEL_27;
    }
    hdd_prevent_suspend(0);
    v50 = pld_request_pm_qos(a1, 1);
    cds_clear_driver_state(16, v50, v51, v52, v53, v54, v55, v56, v57);
    v66 = _cds_get_context(64, (__int64)"hdd_init_qdf_ctx", v58, v59, v60, v61, v62, v63, v64, v65);
    if ( !v66 )
    {
      v96 = -22;
      goto LABEL_14;
    }
    v66[5] = a1;
    v76 = (__int64)v66;
    v66[1] = a3;
    *((_DWORD *)v66 + 148) = v13;
    v66[75] = a4;
    is_ready = ucfg_ipa_is_ready(v66, v67);
    v78 = cds_smmu_mem_map_setup(v76, is_ready & 1);
    if ( (_DWORD)v78 )
      v78 = qdf_trace_msg(
              0x33u,
              2u,
              "%s: cds_smmu_mem_map_setup() failed",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "hdd_init_qdf_ctx",
              v142,
              v143);
    v87 = hdd_wlan_re_init(v78);
    if ( v87 )
    {
      v96 = v87;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: consecutive reinit failures:%u",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "__hdd_soc_recovery_reinit",
        (unsigned __int8)++re_init_fail_cnt);
LABEL_14:
      cds_set_driver_state(16, v68, v69, v70, v71, v72, v73, v74, v75);
      pld_remove_pm_qos(a1);
      hdd_allow_suspend(0);
      hdd_start_complete(v96);
      goto LABEL_26;
    }
    re_init_fail_cnt = 0;
    if ( (qdf_is_fw_down(v88, v89, v90, v91, v92, v93, v94, v95) & 1) == 0 )
    {
      v105 = cds_clear_driver_state(8, v97, v98, v99, v100, v101, v102, v103, v104);
      hdd_handle_cached_commands(v105);
    }
    if ( (hdd_is_any_interface_open(context) & 1) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: restarting idle shutdown timer",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "__hdd_soc_recovery_reinit");
      hdd_psoc_idle_timer_start(context);
    }
    pld_remove_pm_qos(a1);
    hdd_allow_suspend(0);
    gfp_flags = cds_get_gfp_flags();
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "hdd_send_driver_ready_to_user");
    v131 = _cds_get_context(
             51,
             (__int64)"hdd_send_driver_ready_to_user",
             v123,
             v124,
             v125,
             v126,
             v127,
             v128,
             v129,
             v130);
    if ( v131 )
    {
      v140 = _cfg80211_alloc_event_skb(v131[3], 0, 103, 197, 0, 54, 0, gfp_flags);
      if ( v140 )
      {
        _cfg80211_send_event_skb(v140, gfp_flags);
LABEL_25:
        v96 = 0;
        goto LABEL_26;
      }
      v141 = "%s: wlan_cfg80211_vendor_event_alloc failed";
    }
    else
    {
      v141 = "%s: HDD Context is NULL";
    }
    qdf_trace_msg(
      0x33u,
      2u,
      v141,
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      "hdd_send_driver_ready_to_user",
      v142);
    goto LABEL_25;
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: driver is unloading, avoid SSR",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "hdd_soc_recovery_reinit",
    v142,
    v143);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
