__int64 __fastcall cds_post_disable(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x21
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v19; // x4
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  __int64 target_info_handle; // x0
  unsigned int v48; // w8
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x8
  __int64 **v68; // x0
  __int64 v69; // x8
  void (*v70)(void); // x8

  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      "cds_post_disable");
    return 4;
  }
  v8 = *(_QWORD *)(gp_cds_context + 24);
  if ( !v8 )
  {
    v19 = 54;
LABEL_14:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      v19,
      "cds_post_disable");
    return 4;
  }
  v9 = *(_QWORD *)(gp_cds_context + 32);
  if ( !v9 )
  {
    v19 = 61;
    goto LABEL_14;
  }
  if ( scheduler_get_context() && (unsigned int)scheduler_disable(v10, v11, v12, v13, v14, v15, v16, v17) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to disable scheduler",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cds_post_disable");
    return 4;
  }
  v20 = qdf_trace_msg(
          0x38u,
          8u,
          "%s: send deinit sequence to firmware",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "cds_post_disable");
  if ( gp_cds_context )
  {
    v29 = *(_DWORD *)(gp_cds_context + 16);
    if ( (v29 & 8) != 0 || (v29 & 0x10) != 0 )
      goto LABEL_30;
  }
  else
  {
    v20 = qdf_trace_msg(
            0x38u,
            2u,
            "%s: global cds context is NULL",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "cds_get_driver_state");
    if ( gp_cds_context )
    {
      if ( (*(_DWORD *)(gp_cds_context + 16) & 0x10) != 0 )
        goto LABEL_30;
    }
    else
    {
      v20 = qdf_trace_msg(
              0x38u,
              2u,
              "%s: global cds context is NULL",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "cds_get_driver_state");
    }
  }
  if ( (unsigned int)hdd_get_conparam(v20) == 5 )
  {
    if ( gp_cds_context )
    {
      v46 = *(_QWORD *)(gp_cds_context + 32);
      if ( v46 )
      {
        target_info_handle = hif_get_target_info_handle(v46);
        if ( target_info_handle )
        {
          v48 = *(_DWORD *)(target_info_handle + 4);
          if ( v48 <= 0x16 && ((1 << v48) & 0x403900) != 0 )
            goto LABEL_30;
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Module ID %d context is Null (via %s)",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "__cds_get_context",
          61,
          "cds_should_suspend_target");
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: cds context pointer is null (via %s)",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__cds_get_context",
        "cds_should_suspend_target");
    }
  }
  v49 = ucfg_pmo_psoc_suspend_target(*(_QWORD *)(v8 + 24), 1);
  if ( v49 )
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to suspend target, status = %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "cds_suspend_target",
      v49);
LABEL_30:
  hif_disable_isr(v9);
  v58 = hif_reset_soc(v9);
  v67 = gp_cds_context;
  if ( *(_QWORD *)(gp_cds_context + 40) )
  {
    wma_wmi_stop(v58);
    htc_stop(*(_QWORD *)(gp_cds_context + 40));
    v67 = gp_cds_context;
  }
  if ( v67 )
  {
    v68 = *(__int64 ***)(v67 + 64);
    if ( v68 )
    {
      if ( *v68 )
      {
        v69 = **v68;
        if ( v69 )
        {
          v70 = *(void (**)(void))(v69 + 48);
          if ( v70 )
          {
            if ( *((_DWORD *)v70 - 1) != 632910735 )
              __break(0x8228u);
            v70();
          }
        }
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %d context is Null (via %s)",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "__cds_get_context",
        71,
        "cds_post_disable");
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "__cds_get_context",
      "cds_post_disable");
  }
  qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v59, v60, v61, v62, v63, v64, v65, v66, "cdp_pdev_pre_detach");
  return 0;
}
