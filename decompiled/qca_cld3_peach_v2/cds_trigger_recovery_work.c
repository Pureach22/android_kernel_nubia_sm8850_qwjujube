__int64 __fastcall cds_trigger_recovery_work(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x8
  __int64 v9; // x9
  char v10; // w21
  int v11; // w9
  __int64 v12; // x8
  __int64 result; // x0
  const char *v14; // x2
  __int64 v15; // x8
  __int64 v16; // x19
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double (__fastcall *v44)(__int64); // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x0
  __int64 v62; // [xsp+0h] [xbp-10h] BYREF
  __int64 v63; // [xsp+8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = gp_cds_context;
  v62 = 0;
  if ( gp_cds_context )
  {
    v9 = *(_QWORD *)(gp_cds_context + 152);
    if ( v9 )
    {
      v10 = *(_BYTE *)(v9 + 37);
      v11 = *(_DWORD *)(gp_cds_context + 16);
      if ( (v11 & 8) == 0 )
        goto LABEL_4;
      goto LABEL_10;
    }
LABEL_9:
    v10 = 0;
    v11 = *(_DWORD *)(v8 + 16);
    if ( (v11 & 8) == 0 )
    {
LABEL_4:
      if ( (v11 & 0x10) == 0 )
        goto LABEL_5;
      goto LABEL_13;
    }
LABEL_10:
    v14 = "%s: WLAN recovery already in progress";
    goto LABEL_14;
  }
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
    "cds_is_self_recovery_enabled",
    v62,
    v63);
  v8 = gp_cds_context;
  if ( gp_cds_context )
    goto LABEL_9;
  qdf_trace_msg(0x38u, 2u, "%s: global cds context is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "cds_get_driver_state");
  v8 = gp_cds_context;
  if ( gp_cds_context )
  {
    v10 = 0;
    if ( (*(_DWORD *)(gp_cds_context + 16) & 0x10) == 0 )
    {
LABEL_5:
      v12 = *(_QWORD *)(v8 + 56);
      if ( v12 )
        goto LABEL_6;
      goto LABEL_18;
    }
LABEL_13:
    v14 = "%s: WLAN has already failed recovery";
    goto LABEL_14;
  }
  qdf_trace_msg(0x38u, 2u, "%s: global cds context is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "cds_get_driver_state");
  if ( gp_cds_context )
  {
    v10 = 0;
    v12 = *(_QWORD *)(gp_cds_context + 56);
    if ( v12 )
    {
LABEL_6:
      result = pld_is_fw_down(*(_QWORD *)(v12 + 40));
      if ( (_DWORD)result )
      {
        v14 = "%s: Firmware has already initiated recovery";
LABEL_14:
        result = qdf_trace_msg(0x38u, 4u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "cds_trigger_recovery_handler", v62, v63);
        goto LABEL_15;
      }
LABEL_19:
      v15 = gp_cds_context;
      if ( gp_cds_context )
        goto LABEL_20;
LABEL_28:
      result = qdf_trace_msg(
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
                 "cds_trigger_recovery_handler",
                 v62,
                 v63);
      goto LABEL_15;
    }
LABEL_18:
    result = qdf_trace_msg(
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
               64,
               "cds_is_fw_down",
               v62,
               v63);
    goto LABEL_19;
  }
  result = qdf_trace_msg(
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
             "cds_is_fw_down");
  v10 = 0;
  v15 = gp_cds_context;
  if ( !gp_cds_context )
    goto LABEL_28;
LABEL_20:
  v16 = *(_QWORD *)(v15 + 56);
  if ( !v16 )
  {
    result = qdf_trace_msg(
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
               64,
               "cds_trigger_recovery_handler");
    goto LABEL_15;
  }
  if ( ((*(_DWORD *)(v16 + 592) | 4) != 6 || (v10 & 1) != 0) && (*(_BYTE *)(v15 + 16) & 4) == 0 )
  {
    v17 = _qdf_runtime_lock_init(&v62, "&rtl");
    if ( v17 )
    {
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: qdf_runtime_lock_init failed, status: %d",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "cds_trigger_recovery_handler",
                 v17);
      goto LABEL_15;
    }
    if ( (unsigned int)qdf_runtime_pm_prevent_suspend(&v62) )
    {
      v34 = "%s: Failed to acquire runtime pm lock";
    }
    else
    {
      v35 = qdf_trace_msg(
              0x38u,
              2u,
              "%s: critical host timeout trigger fw recovery for reason code %d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "cds_trigger_recovery_handler",
              *(unsigned int *)(gp_cds_context + 296));
      v44 = (double (__fastcall *)(__int64))cds_scan_flush_recovery_callback;
      if ( cds_scan_flush_recovery_callback )
      {
        if ( *((_DWORD *)cds_scan_flush_recovery_callback - 1) != -440107680 )
          __break(0x8228u);
        v36 = v44(v35);
      }
      cds_set_driver_state(8, v36, v37, v38, v39, v40, v41, v42, v43);
      cds_set_driver_state(128, v45, v46, v47, v48, v49, v50, v51, v52);
      if ( (unsigned int)pld_force_collect_target_dump(*(_QWORD *)(v16 + 40)) )
        v53 = cds_force_assert_target(v16);
      v61 = cds_clear_driver_state(128, v53, v54, v55, v56, v57, v58, v59, v60);
      wma_wmi_stop(v61);
      if ( !(unsigned int)qdf_runtime_pm_allow_suspend(&v62) )
        goto LABEL_40;
      v34 = "%s: Failed to release runtime pm lock";
    }
    qdf_trace_msg(0x38u, 2u, v34, v26, v27, v28, v29, v30, v31, v32, v33, "cds_trigger_recovery_handler", v62, v63);
LABEL_40:
    result = qdf_runtime_lock_deinit(&v62);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
