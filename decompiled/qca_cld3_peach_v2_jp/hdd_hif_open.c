__int64 __fastcall hdd_hif_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        unsigned int a12,
        char a13)
{
  _QWORD *context; // x19
  unsigned int conparam; // w25
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x0
  __int64 *v27; // x26
  __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x3
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w20
  __int64 result; // x0
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x2
  __int64 v60; // x3
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w21
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x0
  unsigned int v88; // w21
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  char napi_enabled; // w0
  __int64 values; // x0
  __int64 v107; // x0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  _QWORD v116[12]; // [xsp+0h] [xbp-60h] BYREF

  v116[11] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(64, (__int64)"hdd_hif_open", a2, a3, a4, a5, a6, a7, a8, a9);
  conparam = cds_get_conparam();
  v26 = _cds_get_context(51, (__int64)"hdd_hif_open", v18, v19, v20, v21, v22, v23, v24, v25);
  if ( v26 )
  {
    v116[0] = a1;
    v116[1] = hdd_set_recovery_in_progress;
    v27 = v26;
    v116[2] = hdd_is_recovery_in_progress;
    v116[3] = hdd_is_load_or_unload_in_progress;
    v116[4] = hdd_is_driver_unloading;
    v116[5] = hdd_is_target_ready;
    v116[6] = hdd_get_bandwidth_level;
    v116[7] = hdd_get_consistent_mem_unaligned;
    v116[8] = hdd_put_consistent_mem_unaligned;
    v116[9] = hdd_dp_prealloc_get_multi_pages;
    v116[10] = hdd_dp_prealloc_put_multi_pages;
    v28 = hif_open((__int64)context, conparam, a12, (int)v116, *v26);
    if ( v28 )
    {
      v39 = v28;
      if ( (unsigned int)cds_set_context(0x3Du, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, v38) )
      {
        v48 = -2;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set global HIF CDS Context err: %d",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "hdd_hif_open",
          4294967294LL);
LABEL_13:
        hif_close(v39);
        result = v48;
        goto LABEL_14;
      }
      v50 = cds_shutdown_notifier_register((__int64)hif_shutdown_notifier_cb, v39);
      if ( v50 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Shutdown notifier register failed: %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_hif_open",
          v50);
        v48 = 0;
        goto LABEL_11;
      }
      v69 = hif_enable(v39);
      if ( v69 )
      {
        v78 = v69;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hif_enable failed status: %d, reinit: %d",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "hdd_hif_open",
          v69,
          a13 & 1);
        v48 = qdf_status_to_os_return(v78);
        goto LABEL_11;
      }
      v87 = cds_set_driver_state(32, v70, v71, v72, v73, v74, v75, v76, v77);
      v88 = hdd_napi_create(v87);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: hdd_napi_create returned: %d",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "hdd_hif_open",
        v88);
      if ( v88 )
      {
        if ( (v88 & 0x80000000) != 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: NAPI creation error, rc: 0x%x, reinit: %d",
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            "hdd_hif_open",
            v88,
            a13 & 1);
          cds_clear_driver_state(32, v108, v109, v110, v111, v112, v113, v114, v115);
          v48 = -14;
LABEL_11:
          if ( (unsigned int)cds_set_context(0x3Du, 0, v59, v60, v61, v62, v63, v64, v65, v66, v67, v68) )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to reset CDS HIF Context",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "hdd_deinit_cds_hif_context");
          goto LABEL_13;
        }
        napi_enabled = ucfg_dp_get_napi_enabled(*v27);
        hdd_napi_event(1, napi_enabled & 1);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: NAPI: no instances are created",
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          "hdd_hif_open");
      }
      values = cfg_psoc_get_values(*v27);
      hif_set_ce_service_max_yield_time(v39, *(_DWORD *)(values + 4020));
      ucfg_pmo_psoc_set_hif_handle(*v27, v39);
      ucfg_dp_set_hif_handle(*v27, v39);
      v107 = cfg_psoc_get_values(*v27);
      hif_set_ce_service_max_rx_ind_flush(v39, *(_DWORD *)(v107 + 4016));
      result = 0;
      goto LABEL_14;
    }
    qdf_trace_msg(0x33u, 2u, "%s: hif_open error", v31, v32, v33, v34, v35, v36, v37, v38, "hdd_hif_open");
    result = 4294967284LL;
  }
  else
  {
    result = 4294967282LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
