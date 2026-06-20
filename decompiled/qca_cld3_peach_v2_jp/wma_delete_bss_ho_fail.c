__int64 __fastcall wma_delete_bss_ho_fail(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  _QWORD *v22; // x21
  __int64 cmpt_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  _DWORD *v44; // x8
  int v45; // w21
  const char *v46; // x2
  _QWORD *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  _DWORD *v57; // x8
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
  __int64 v82; // x8
  _DWORD *v83; // x8
  _QWORD *v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  int v101; // w0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  const char *v110; // x2
  __int64 v111; // x9
  __int64 result; // x0
  _BYTE v113[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v114; // [xsp+8h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_delete_bss_ho_fail", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)a2;
  v113[0] = 0;
  if ( !v21 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: iface for vdev_id %d is already deleted",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_delete_bss_ho_fail",
      (unsigned __int8)a2);
    v45 = 0;
    goto LABEL_49;
  }
  v22 = context;
  if ( !*(_QWORD *)v21 )
  {
    v46 = "%s: vdev is NULL";
LABEL_30:
    qdf_trace_msg(0x36u, 2u, v46, v13, v14, v15, v16, v17, v18, v19, v20, "wma_get_vdev_bssid");
    qdf_trace_msg(0x36u, 2u, "%s: Invalid bssid", v58, v59, v60, v61, v62, v63, v64, v65, "wma_delete_bss_ho_fail");
    v45 = 16;
    goto LABEL_49;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v21, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !cmpt_obj )
  {
    v46 = "%s: Failed to get mlme_obj";
    goto LABEL_30;
  }
  qdf_mem_set((void *)(cmpt_obj + 168), 6u, 0);
  v32 = *(_QWORD *)(v21 + 256);
  if ( v32 )
  {
    _qdf_mem_free(v32);
    *(_QWORD *)(v21 + 256) = 0;
  }
  v33 = *(_QWORD *)(v21 + 272);
  if ( v33 )
  {
    *(_QWORD *)(v21 + 272) = 0;
    _qdf_mem_free(v33);
  }
  v34 = *(_QWORD *)(v21 + 440);
  if ( v34 )
  {
    *(_QWORD *)(v21 + 440) = 0;
    _qdf_mem_free(v34);
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id: %d, pausing tx_ll_queue for VDEV_STOP (del_bss)",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wma_delete_bss_ho_fail",
    (unsigned __int8)a2);
  if ( v22 && *v22 )
  {
    v43 = *(_QWORD *)(*v22 + 120LL);
    if ( v43 )
    {
      v44 = *(_DWORD **)(v43 + 48);
      if ( v44 )
      {
        if ( *(v44 - 1) != 875705606 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))v44)(v22, a2, 8, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v35, v36, v37, v38, v39, v40, v41, v42, "cdp_fc_vdev_pause");
  }
  v47 = _cds_get_context(54, (__int64)"wma_vdev_set_pause_bit", v35, v36, v37, v38, v39, v40, v41, v42);
  if ( !v47 || v47[65] + 488LL * (unsigned __int8)a2 )
  {
    if ( v22 )
      goto LABEL_23;
LABEL_32:
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v48, v49, v50, v51, v52, v53, v54, v55, "cdp_fc_vdev_flush");
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d, un-pausing tx_ll_queue for VDEV_STOP rsp",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "wma_delete_bss_ho_fail",
      (unsigned __int8)a2);
    goto LABEL_40;
  }
  qdf_trace_msg(0x36u, 2u, "%s: Interface is NULL", v48, v49, v50, v51, v52, v53, v54, v55, "wma_vdev_set_pause_bit");
  if ( !v22 )
    goto LABEL_32;
LABEL_23:
  if ( *v22 )
  {
    v56 = *(_QWORD *)(*v22 + 120LL);
    if ( v56 )
    {
      v57 = *(_DWORD **)(v56 + 40);
      if ( v57 )
      {
        if ( *(v57 - 1) != -251540498 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD))v57)(v22, a2);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v48, v49, v50, v51, v52, v53, v54, v55, "cdp_fc_vdev_flush");
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id: %d, un-pausing tx_ll_queue for VDEV_STOP rsp",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "wma_delete_bss_ho_fail",
    (unsigned __int8)a2);
  if ( *v22 )
  {
    v82 = *(_QWORD *)(*v22 + 120LL);
    if ( v82 )
    {
      v83 = *(_DWORD **)(v82 + 56);
      if ( v83 )
      {
        if ( *(v83 - 1) != 875705606 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))v83)(v22, a2, 8, 0);
      }
    }
    goto LABEL_41;
  }
LABEL_40:
  qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v74, v75, v76, v77, v78, v79, v80, v81, "cdp_fc_vdev_unpause");
LABEL_41:
  v84 = _cds_get_context(54, (__int64)"wma_vdev_clear_pause_bit", v74, v75, v76, v77, v78, v79, v80, v81);
  if ( v84 && !(v84[65] + 488LL * (unsigned __int8)a2) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Interface is NULL",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "wma_vdev_clear_pause_bit");
  *(_DWORD *)(v21 + 228) = 2;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: (type %d subtype %d) BSS is stopped",
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    "wma_delete_bss_ho_fail",
    *(unsigned int *)(v21 + 164),
    *(unsigned int *)(v21 + 168));
  v101 = mlme_set_vdev_stop_type(*(_QWORD *)v21, 4174, v93, v94, v95, v96, v97, v98, v99, v100);
  if ( v101 )
  {
    v45 = v101;
    v110 = "%s: Failed to set wma req msg_type for vdev_id: %d";
  }
  else
  {
    v111 = *(_QWORD *)(a1 + 520);
    v113[0] = a2;
    result = wlan_vdev_mlme_sm_deliver_evt(
               *(_QWORD *)(v111 + 488LL * (unsigned __int8)a2),
               0xEu,
               1u,
               (__int64)v113,
               v102,
               v103,
               v104,
               v105,
               v106,
               v107,
               v108,
               v109);
    if ( !(_DWORD)result )
      goto LABEL_51;
    v45 = result;
    v110 = "%s: Failed to handle vdev stop rsp for vdev_id %d";
  }
  qdf_trace_msg(
    0x36u,
    2u,
    v110,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    "wma_delete_bss_ho_fail",
    (unsigned __int8)a2);
LABEL_49:
  result = _qdf_mem_malloc(8u, "wma_delete_bss_ho_fail", 6556);
  if ( result )
  {
    *(_BYTE *)(result + 4) = a2;
    *(_DWORD *)result = v45;
    result = wma_send_msg_high_priority(a1, 4175, result, 0);
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
