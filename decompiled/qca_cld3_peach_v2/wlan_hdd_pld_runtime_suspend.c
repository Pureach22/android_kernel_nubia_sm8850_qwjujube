__int64 __fastcall wlan_hdd_pld_runtime_suspend(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 *context; // x19
  int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  int v45; // w19
  unsigned int v48; // w20
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int64 StatusReg; // x8
  unsigned int v59; // w21
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x9
  unsigned __int64 v62; // x5
  _QWORD v63[2]; // [xsp+0h] [xbp-10h] BYREF

  v63[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63[0] = 0;
  LODWORD(result) = _osif_psoc_sync_op_start(a1, v63, "wlan_hdd_pld_runtime_suspend");
  if ( (_DWORD)result )
    goto LABEL_13;
  qdf_trace_msg(0x33u, 8u, "%s: Starting runtime suspend", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_hdd_runtime_suspend");
  context = _cds_get_context(51, (__int64)"wlan_hdd_runtime_suspend", v10, v11, v12, v13, v14, v15, v16, v17);
  v19 = _wlan_hdd_validate_context(context, "wlan_hdd_runtime_suspend");
  if ( v19 )
    goto LABEL_12;
  if ( *((_DWORD *)context + 366) != 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Driver module closed skipping runtime suspend",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_hdd_runtime_suspend");
    goto LABEL_8;
  }
  if ( (hdd_is_runtime_pm_enabled(context) & 1) == 0 )
  {
LABEL_8:
    v19 = 0;
    goto LABEL_12;
  }
  if ( (unsigned int)ucfg_scan_get_pdev_status(context[1], v28, v29, v30, v31, v32, v33, v34, v35) )
  {
    v44 = "%s: Scan in progress, ignore runtime suspend";
  }
  else if ( (ucfg_ipa_is_tx_pending(context[1]) & 1) != 0 )
  {
    v44 = "%s: IPA TX comps pending, ignore rtpm suspend";
  }
  else
  {
    if ( *(_BYTE *)(context[13] + 123) != 2 || (wlan_hdd_is_cpu_pm_qos_in_progress(context) & 1) == 0 )
    {
      v48 = ucfg_pmo_psoc_bus_runtime_suspend(*context, hdd_pld_runtime_suspend_cb);
      v49 = qdf_status_to_os_return(v48);
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v59 = v49;
      if ( 10 * StatusReg >= StatusReg )
        v60 = 10 * StatusReg / 0xC0;
      else
        v60 = 10 * (StatusReg / 0xC0);
      v61 = context[527];
      context[528] = v60;
      v62 = v60 - v61;
      if ( v60 > v61 )
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Runtime suspend done result: %d total cxpc up time %lu microseconds",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "wlan_hdd_runtime_suspend",
          v49,
          v62);
      if ( !v48 )
        ucfg_dp_bus_bw_compute_timer_stop(*context, v50, v51, v52, v53, v54, v55, v56, v57);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Runtime suspend done result: %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "wlan_hdd_runtime_suspend",
        v59,
        v62);
      v19 = v59;
      goto LABEL_12;
    }
    v44 = "%s: PM QoS Latency constraint, ignore runtime suspend";
  }
  qdf_trace_msg(0x33u, 8u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "wlan_hdd_runtime_suspend");
  v19 = -16;
LABEL_12:
  v45 = v19;
  _osif_psoc_sync_op_stop(v63[0], "wlan_hdd_pld_runtime_suspend");
  LODWORD(result) = v45;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  if ( (_DWORD)result == -11 || (_DWORD)result == 0 || (_DWORD)result == -16 )
    return (unsigned int)result;
  else
    return 4294967285LL;
}
