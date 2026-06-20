__int64 __fastcall wlan_hdd_pld_uevent(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x20
  char bus_type; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w4
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  size_t v39; // x2
  __int64 result; // x0
  char v41; // w19
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
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w8
  __int64 v68; // x19
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x20
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // [xsp+Ch] [xbp-24h] BYREF
  void *v95; // [xsp+10h] [xbp-20h] BYREF
  __int64 v96; // [xsp+18h] [xbp-18h]
  int v97; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v98; // [xsp+28h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = 0;
  context = _cds_get_context(61, (__int64)"wlan_hdd_pld_uevent", a3, a4, a5, a6, a7, a8, a9, a10);
  v94 = 0;
  bus_type = pld_get_bus_type(a1);
  v22 = *(_DWORD *)a2;
  if ( *(int *)a2 > 3 )
  {
    if ( v22 != 4 )
    {
      if ( v22 == 5 )
      {
        result = qdf_trace_msg(
                   0x33u,
                   8u,
                   "%s: Received smmu fault indication",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "wlan_hdd_pld_uevent");
        goto LABEL_24;
      }
      goto LABEL_12;
    }
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Bus event received",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "wlan_hdd_pld_uevent");
    v67 = *(_DWORD *)(a2 + 8);
    if ( !v67 )
    {
      result = host_log_device_status(8);
      v67 = *(_DWORD *)(a2 + 8);
    }
    if ( v67 == 1 )
      result = cds_set_driver_state(512, v59, v60, v61, v62, v63, v64, v65, v66);
  }
  else
  {
    if ( v22 )
    {
      if ( v22 == 3 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: Received firmware hang event",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_hdd_pld_uevent");
        cds_get_recovery_reason(&v94, v23, v24, v25, v26, v27, v28, v29, v30);
        if ( !v94 && context )
        {
          hif_display_ctrl_traffic_pipes_state(context);
          hif_display_latest_desc_hist((__int64)context);
        }
        qdf_mem_set(&g_fw_host_hang_event, 0x186u, 0);
        v95 = &g_fw_host_hang_event;
        LODWORD(v96) = 0;
        qdf_hang_event_notifier_call(v94, &v95);
        v39 = *(unsigned __int16 *)(a2 + 16);
        LODWORD(v96) = 195;
        if ( (unsigned int)v39 < 0xC3 )
        {
          if ( !(_DWORD)v39 )
            goto LABEL_22;
        }
        else
        {
          *(_WORD *)(a2 + 16) = 195;
          v39 = 195;
        }
        qdf_mem_copy((char *)&unk_C3 + (_QWORD)v95, *(const void **)(a2 + 8), v39);
LABEL_22:
        v68 = (__int64)v95;
        v97 = 0;
        result = (__int64)_cds_get_context(51, (__int64)"hdd_send_hang_data", v31, v32, v33, v34, v35, v36, v37, v38);
        if ( result )
        {
          v77 = result;
          cds_get_recovery_reason(&v97, v69, v70, v71, v72, v73, v74, v75, v76);
          cds_reset_recovery_reason(v78, v79, v80, v81, v82, v83, v84, v85);
          result = wlan_hdd_send_hang_reason_event(v77, v97, v68, 0x186u, v86, v87, v88, v89, v90, v91, v92, v93);
        }
        goto LABEL_24;
      }
LABEL_12:
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Received uevent %d",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "wlan_hdd_pld_uevent");
      goto LABEL_24;
    }
    v41 = bus_type;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received firmware down indication",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_hdd_pld_uevent");
    cds_clear_driver_state(32, v42, v43, v44, v45, v46, v47, v48, v49);
    v58 = cds_set_driver_state(8, v50, v51, v52, v53, v54, v55, v56, v57);
    hdd_init_start_completion(v58);
    result = qdf_complete_wait_events();
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) == 0 && v41 )
    {
      result = hdd_soc_recovery_cleanup(result);
      is_recovery_cleanup_done = 1;
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
