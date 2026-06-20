__int64 __fastcall wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb(
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
  __int64 v9; // x22
  __int64 v11; // x20
  unsigned int v12; // w10
  int v13; // w2
  int v14; // w3
  int v15; // w4
  int v16; // w5
  int v17; // w6
  int v18; // w7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x9
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w20
  int v38; // w3
  int v39; // w4
  int v40; // w5
  int v41; // w6
  int v42; // w7
  __int64 v43; // x0
  __int64 v44; // x8
  void (*v45)(void); // x8
  int v46; // w3
  int v47; // w4
  int v48; // w5
  int v49; // w6
  int v50; // w7
  unsigned int v51; // w20
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 (*v62)(void); // x8
  unsigned int v63; // w19
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w4
  int v73; // w5
  int v74; // w6
  int v75; // w7
  char v77; // [xsp+0h] [xbp+0h]

  v9 = a1 + 4096;
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 64LL);
  v12 = (unsigned __int8)++*(_BYTE *)(a1 + 7514);
  if ( v12 >= 5 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: opt_dp: filter release attempt reached max cnt",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_opt_dpath_flt_recovery");
    wlan_ipa_log_message(
      (int)"wlan_ipa_opt_dpath_flt_recovery",
      (int)"opt_dp: filter release attempt reached max cnt",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v77);
    *(_BYTE *)(v9 + 3343) = 2;
    v19 = wlan_ipa_wdi_opt_dpath_notify_flt_rlsd(1, 1);
    _cds_trigger_recovery(0, (__int64)"wlan_ipa_opt_dpath_flt_recovery", 7261, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  if ( *(_BYTE *)(v9 + 3343) == 1 )
  {
    v27 = *(_QWORD *)(a1 + 1464);
    *(_BYTE *)(v9 + 3343) = 2;
    if ( (*(_BYTE *)(v27 + 1) & 0x10) != 0 )
    {
      qdf_runtime_pm_allow_suspend((__int64 *)(a1 + 8432));
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp: Enable low power features to release filter",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb");
      v28 = cdp_ipa_opt_dp_enable_disable_low_power_mode(v11, 1);
      if ( v28 )
      {
        v37 = v28;
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: Low power feature enable failed. status %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb",
          v28);
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb",
          (int)"Low power feature enable failed. status %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v77);
      }
      v43 = *(_QWORD *)(a1 + 1456);
      if ( v43 && *(_QWORD *)v43 && (v44 = *(_QWORD *)(*(_QWORD *)v43 + 152LL)) != 0 )
      {
        v45 = *(void (**)(void))(v44 + 96);
        if ( v45 )
        {
          if ( *((_DWORD *)v45 - 1) != -1106481425 )
            __break(0x8228u);
          v45();
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "cdp_ipa_pcie_link_down");
      }
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp: Vote for PCIe link down",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb");
    }
    v60 = *(_QWORD *)(a1 + 1456);
    *(_BYTE *)(v9 + 3432) = 0;
    *(_WORD *)(v9 + 3424) = 512;
    *(_BYTE *)(v9 + 3536) = 0;
    *(_BYTE *)(v9 + 3426) = 2;
    if ( v60 && *(_QWORD *)v60 && (v61 = *(_QWORD *)(*(_QWORD *)v60 + 152LL)) != 0 )
    {
      v62 = *(__int64 (**)(void))(v61 + 224);
      if ( v62 )
      {
        if ( *((_DWORD *)v62 - 1) != -1963433128 )
          __break(0x8228u);
        v51 = v62();
      }
      else
      {
        v51 = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "cdp_ipa_rx_cce_super_rule_setup");
      v51 = 16;
    }
    v63 = qdf_wait_single_event(a1 + 8072, 0x1F4u);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: flt rel response, status - %d, resp - %d",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb",
      v63,
      v51);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb",
      (int)"opt_dp: flt rel response, status - %d, resp - %d",
      v63,
      v51,
      v72,
      v73,
      v74,
      v75,
      v77);
    if ( v63 )
    {
      v51 = v63;
      *(_BYTE *)(v9 + 3343) = 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: filter release inprogress - %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb");
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb",
      (int)"opt_dp: filter release inprogress - %d",
      *(unsigned __int8 *)(v9 + 3343),
      v46,
      v47,
      v48,
      v49,
      v50,
      v77);
    return 0;
  }
  return v51;
}
