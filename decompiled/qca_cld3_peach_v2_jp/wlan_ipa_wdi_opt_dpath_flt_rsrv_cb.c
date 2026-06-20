__int64 __fastcall wlan_ipa_wdi_opt_dpath_flt_rsrv_cb(
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
  int v9; // w2
  int v10; // w3
  int v11; // w4
  int v12; // w5
  int v13; // w6
  int v14; // w7
  const char *v15; // x1
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x23
  __int64 *v19; // x21
  __int64 v20; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 (*v40)(void); // x8
  unsigned int v41; // w20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w20
  int v53; // w2
  int v54; // w3
  int v55; // w4
  int v56; // w5
  int v57; // w6
  int v58; // w7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w3
  int v68; // w4
  int v69; // w5
  int v70; // w6
  int v71; // w7
  unsigned int v72; // w0
  int v73; // w19
  int v74; // w3
  int v75; // w4
  int v76; // w5
  int v77; // w6
  int v78; // w7
  const char *v79; // x1
  int v80; // w2
  int v81; // w3
  int v82; // w4
  int v83; // w5
  int v84; // w6
  int v85; // w7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 (*v96)(void); // x8
  int v97; // w19
  int v98; // w3
  int v99; // w4
  int v100; // w5
  int v101; // w6
  int v102; // w7
  __int64 v103; // x0
  __int64 *v104; // x8
  __int64 v105; // x9
  void (*v106)(void); // x9
  char v107; // [xsp+0h] [xbp+0h]

  if ( (a1[430] & 1) != 0 || *((_BYTE *)a1 + 3441) == 1 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Pipes are going down. Reject flt rsrv request",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
    v15 = "Pipes are going down. Reject flt rsrv request";
LABEL_17:
    wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb", (int)v15, v9, v10, v11, v12, v13, v14, v107);
    return 49;
  }
  v16 = *a1;
  if ( !*a1 || (v17 = *(_QWORD *)(v16 + 2800)) == 0 || (v18 = *(_QWORD *)(v17 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Unable to get wmi handle",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
    v15 = "Unable to get wmi handle";
    goto LABEL_17;
  }
  v19 = a1 + 512;
  v20 = *(_QWORD *)(v16 + 64);
  *((_WORD *)a1 + 3719) = 257;
  qdf_wake_lock_acquire((__int64)(a1 + 1024), 0x1Fu);
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp: Wakelock acquired",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
  qdf_pm_system_wakeup();
  if ( (*(_BYTE *)(a1[183] + 1) & 0x10) != 0 )
  {
    qdf_runtime_pm_prevent_suspend_sync(a1 + 1054);
    goto LABEL_20;
  }
  v38 = a1[182];
  if ( !v38 || !*(_QWORD *)v38 || (v39 = *(_QWORD *)(*(_QWORD *)v38 + 152LL)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v30, v31, v32, v33, v34, v35, v36, v37, "cdp_ipa_pcie_link_up");
    v41 = 16;
LABEL_28:
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: opt_dp: Pcie link up fail %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
      v41);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
      (int)"opt_dp: Pcie link up fail %d",
      v41,
      v67,
      v68,
      v69,
      v70,
      v71,
      v107);
    goto LABEL_52;
  }
  v40 = *(__int64 (**)(void))(v39 + 88);
  if ( v40 )
  {
    if ( *((_DWORD *)v40 - 1) != 639071501 )
      __break(0x8228u);
    v41 = v40();
    if ( v41 )
      goto LABEL_28;
  }
LABEL_20:
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp :Target suspend state %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
    *(unsigned int *)(v18 + 696));
  if ( *(_DWORD *)(v18 + 696) )
  {
    v51 = 0;
    do
    {
      qdf_sleep();
      if ( !*(_DWORD *)(v18 + 696) )
        break;
    }
    while ( v51++ < 9 );
  }
  if ( *(_DWORD *)(v18 + 696) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Wifi is suspended. Reject request",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
      (int)"Wifi is suspended. Reject request",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v107);
    goto LABEL_42;
  }
  if ( (*(_BYTE *)(a1[183] + 1) & 0x10) == 0 )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: Disable low pwr features to reserve filter",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
    v72 = cdp_ipa_opt_dp_enable_disable_low_power_mode(v20, 0);
    if ( v72 )
    {
      v73 = v72;
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Low power feature disable failed. status %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
        v72);
      v79 = "Low power feature disable failed. status %d";
      v80 = v73;
LABEL_41:
      wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb", (int)v79, v80, v74, v75, v76, v77, v78, v107);
      goto LABEL_42;
    }
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp: Send filter reserve req",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "wlan_ipa_wdi_opt_dpath_flt_rsrv_cb");
  v94 = a1[182];
  *((_BYTE *)v19 + 3418) = 0;
  *((_WORD *)v19 + 1712) = 0;
  *((_WORD *)v19 + 1742) = 0;
  *((_WORD *)v19 + 1794) = 0;
  if ( !v94 || !*(_QWORD *)v94 || (v95 = *(_QWORD *)(*(_QWORD *)v94 + 152LL)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "cdp_ipa_rx_cce_super_rule_setup");
    v79 = "filter reserve request status - %d";
    v80 = 16;
    goto LABEL_41;
  }
  v96 = *(__int64 (**)(void))(v95 + 224);
  if ( v96 )
  {
    if ( *((_DWORD *)v96 - 1) != -1963433128 )
      __break(0x8228u);
    v97 = v96();
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
      (int)"filter reserve request status - %d",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v107);
    if ( v97 )
    {
LABEL_42:
      if ( (*(_BYTE *)(a1[183] + 1) & 0x10) != 0 )
      {
        qdf_runtime_pm_allow_suspend(a1 + 1054);
      }
      else
      {
        v103 = a1[182];
        v104 = a1;
        if ( v103 && *(_QWORD *)v103 && (v105 = *(_QWORD *)(*(_QWORD *)v103 + 152LL)) != 0 )
        {
          v106 = *(void (**)(void))(v105 + 96);
          if ( !v106 )
          {
LABEL_53:
            qdf_wake_lock_release((__int64)(v104 + 1024), 0x1Fu);
            *((_BYTE *)v19 + 3342) = 0;
            return 49;
          }
          if ( *((_DWORD *)v106 - 1) != -1106481425 )
            __break(0x8229u);
          v106();
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "cdp_ipa_pcie_link_down");
        }
      }
LABEL_52:
      v104 = a1;
      goto LABEL_53;
    }
    return 0;
  }
  else
  {
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_cb",
      (int)"filter reserve request status - %d",
      0,
      v81,
      v82,
      v83,
      v84,
      v85,
      v107);
    return 0;
  }
}
