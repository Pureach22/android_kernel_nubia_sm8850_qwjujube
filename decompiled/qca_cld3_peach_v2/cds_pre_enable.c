__int64 __fastcall cds_pre_enable(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  __int64 v18; // x19
  __int64 conparam; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  _DWORD *v29; // x8
  const char *v30; // x2
  __int64 result; // x0
  __int64 v32; // x4
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w20
  const char *v43; // x2
  unsigned int v44; // w0
  __int64 v45; // x0
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  _DWORD *v56; // x8
  unsigned int ready; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w20
  __int64 v83; // x8
  _QWORD *context; // x21
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0

  v8 = qdf_trace_msg(0x38u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "cds_pre_enable");
  if ( !gp_cds_context )
  {
    v30 = "%s: cds context is null";
LABEL_15:
    qdf_trace_msg(0x38u, 2u, v30, v9, v10, v11, v12, v13, v14, v15, v16, "cds_pre_enable");
    return 4;
  }
  if ( !*(_QWORD *)(gp_cds_context + 24) )
  {
    v30 = "%s: wma context is null";
    goto LABEL_15;
  }
  v17 = *(_QWORD *)(gp_cds_context + 32);
  if ( !v17 )
  {
    v32 = 61;
LABEL_18:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__cds_get_context",
      v32,
      "cds_pre_enable");
    return 4;
  }
  v18 = *(_QWORD *)(gp_cds_context + 64);
  if ( !v18 )
  {
    v32 = 71;
    goto LABEL_18;
  }
  conparam = hdd_get_conparam(v8);
  if ( (_DWORD)conparam != 5 )
  {
    conparam = hdd_get_conparam(conparam);
    if ( (_DWORD)conparam != 8 )
    {
      if ( *(_QWORD *)v18 && (v28 = *(_QWORD *)(*(_QWORD *)v18 + 64LL)) != 0 )
      {
        v29 = *(_DWORD **)(v28 + 160);
        if ( v29 )
        {
          if ( *(v29 - 1) != 1099376095 )
            __break(0x8228u);
          conparam = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v29)(v18, 0, v17);
        }
      }
      else
      {
        conparam = qdf_trace_msg(
                     0x45u,
                     1u,
                     "%s invalid instance",
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     "cdp_pkt_log_con_service");
      }
    }
  }
  v33 = wma_pre_start(conparam);
  if ( !v33 )
  {
    v44 = htc_start(*(__int64 **)(gp_cds_context + 40));
    if ( v44 )
    {
      v42 = v44;
      v43 = "%s: Failed to Start HTC";
      goto LABEL_24;
    }
    ready = wma_wait_for_ready_event(*(_QWORD *)(gp_cds_context + 24));
    if ( ready )
    {
      v42 = ready;
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Failed to wait for ready event; status: %u",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "cds_pre_enable");
    }
    else
    {
      result = cdp_pdev_post_attach(v18);
      if ( !(_DWORD)result )
        return result;
      v82 = result;
      qdf_trace_msg(0x38u, 2u, "%s: Failed to attach pdev", v74, v75, v76, v77, v78, v79, v80, v81, "cds_pre_enable");
      v42 = qdf_status_from_os_return(v82);
    }
    v83 = gp_cds_context;
    if ( gp_cds_context )
    {
      if ( (*(_BYTE *)(gp_cds_context + 16) & 8) != 0 )
        goto LABEL_48;
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: global cds context is NULL",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "cds_get_driver_state");
      v83 = gp_cds_context;
      if ( !gp_cds_context )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: global cds context is NULL",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "cds_get_driver_state");
        v83 = gp_cds_context;
LABEL_47:
        v66 = cds_suspend_target(*(_QWORD *)(v83 + 24));
LABEL_48:
        context = _cds_get_context(61, (__int64)"cds_pre_enable", v66, v67, v68, v69, v70, v71, v72, v73);
        wma_wmi_stop();
        if ( context )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Disable the isr & reset the soc!",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "cds_pre_enable");
          hif_disable_isr((__int64)context);
          hif_reset_soc((__int64)context);
        }
        v93 = htc_stop(*(_QWORD *)(gp_cds_context + 40));
        v45 = wma_wmi_work_close(v93);
        goto LABEL_25;
      }
    }
    if ( (*(_BYTE *)(v83 + 16) & 0x10) != 0 )
      goto LABEL_48;
    goto LABEL_47;
  }
  v42 = v33;
  v43 = "%s: Failed to WMA prestart";
LABEL_24:
  v45 = qdf_trace_msg(0x38u, 2u, v43, v34, v35, v36, v37, v38, v39, v40, v41, "cds_pre_enable");
LABEL_25:
  v46 = hdd_get_conparam(v45);
  if ( (_DWORD)v46 != 5 && (unsigned int)hdd_get_conparam(v46) != 8 )
  {
    if ( *(_QWORD *)v18 && (v55 = *(_QWORD *)(*(_QWORD *)v18 + 64LL)) != 0 )
    {
      v56 = *(_DWORD **)(v55 + 168);
      if ( v56 )
      {
        if ( *(v56 - 1) != -251540498 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v56)(v18, 0);
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v47, v48, v49, v50, v51, v52, v53, v54, "cdp_pkt_log_exit");
    }
  }
  return v42;
}
