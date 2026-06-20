__int64 __fastcall sme_sap_ser_callback(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v12; // x8
  __int64 result; // x0
  const char *v14; // x2
  const char *v15; // x3
  unsigned int v16; // w1
  _QWORD *context; // x0
  unsigned __int8 *v18; // x19
  _QWORD *v19; // x22
  unsigned int opmode_from_vdev_id; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  __int64 v30; // x8
  _QWORD *v31; // x20
  unsigned int v32; // w22
  unsigned __int8 connection_count; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  void *v42; // x0
  __int64 v43; // x21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  unsigned __int8 *v53; // x19
  _QWORD *v54; // x20
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  void *v63; // x0
  __int64 v64; // x20
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // [xsp+8h] [xbp-48h] BYREF
  int v74; // [xsp+10h] [xbp-40h]
  __int64 v75; // [xsp+18h] [xbp-38h] BYREF
  __int64 v76; // [xsp+20h] [xbp-30h]
  __int64 v77; // [xsp+28h] [xbp-28h]
  __int64 v78; // [xsp+30h] [xbp-20h]
  __int64 v79; // [xsp+38h] [xbp-18h]
  __int64 v80; // [xsp+40h] [xbp-10h]
  __int64 v81; // [xsp+48h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v14 = "%s: Invalid Serialization command";
    v15 = "sme_sap_ser_callback";
    goto LABEL_8;
  }
  if ( !_cds_get_context(52, (__int64)"sme_sap_ser_callback", a3, a4, a5, a6, a7, a8, a9, a10) )
  {
LABEL_10:
    result = 16;
    goto LABEL_11;
  }
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        result = 0;
        goto LABEL_11;
      }
      goto LABEL_15;
    }
    context = _cds_get_context(52, (__int64)"sme_sap_activate_cmd", a3, a4, a5, a6, a7, a8, a9, a10);
    if ( !context )
    {
      result = 4;
      goto LABEL_11;
    }
    if ( *(_DWORD *)a1 == 22 )
    {
      v53 = *(unsigned __int8 **)(a1 + 40);
      v79 = 0;
      v80 = 0;
      v77 = 0;
      v78 = 0;
      v54 = context;
      v75 = 0;
      v76 = 0;
      ((void (*)(void))csr_roam_state_change)();
      csr_roam_substate_change(v54, 3, *v53);
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Stop bss request received for vdev : %d cmd_id : %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "sme_send_stop_bss_msg",
        *v53,
        *((unsigned int *)v53 + 1));
      v63 = (void *)_qdf_mem_malloc(8u, "sme_send_stop_bss_msg", 17556);
      if ( v63 )
      {
        v64 = (__int64)v63;
        qdf_mem_copy(v63, v53, 8u);
        LODWORD(v75) = 5144;
        v76 = v64;
        result = scheduler_post_message_debug(
                   0x34u,
                   0x35u,
                   53,
                   (unsigned __int16 *)&v75,
                   0x44A1u,
                   (__int64)"sme_send_stop_bss_msg");
        if ( !(_DWORD)result )
          goto LABEL_11;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Failed to post stop bss request for vdev id : %d",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "sme_send_stop_bss_msg",
          *v53);
        _qdf_mem_free(v64);
        goto LABEL_10;
      }
      goto LABEL_38;
    }
    if ( *(_DWORD *)a1 != 21 )
      goto LABEL_10;
    v18 = *(unsigned __int8 **)(a1 + 40);
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v75 = 0;
    v76 = 0;
    v74 = 0;
    v73 = 0;
    if ( v18 && context[2695] && context[2694] )
    {
      v19 = context;
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(context[2695], *v18);
      v29 = policy_mgr_qdf_opmode_to_pm_con_mode(
              v19[2694],
              opmode_from_vdev_id,
              *v18,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28);
      v30 = v19[2694];
      v31 = v19;
      v32 = v29;
      connection_count = policy_mgr_get_connection_count(v30);
      if ( (v32 & 0xFFFFFFFD) == 1
        && (connection_count & 0xFE) != 0
        && v18[680] != connection_count
        && (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
              v31[2694],
              v32,
              *((unsigned int *)v18 + 92),
              3,
              0,
              *v18)
          & 1) == 0 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: reject start bss due to conc, freq %d vdev %d op mode %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "sme_send_start_bss_msg",
          *((unsigned int *)v18 + 92),
          *v18,
          opmode_from_vdev_id);
        v43 = 0;
LABEL_40:
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Failed to post start bss request to PE for vdev : %d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "sme_send_start_bss_msg",
          *v18);
        csr_process_sap_response(v31, 1, &v73, *v18);
        _qdf_mem_free(v43);
        goto LABEL_10;
      }
      ((void (__fastcall *)(_QWORD *, __int64, _QWORD))csr_roam_state_change)(v31, 2, *v18);
      csr_roam_substate_change(v31, 1, *v18);
      v42 = (void *)_qdf_mem_malloc(0x2B0u, "sme_send_start_bss_msg", 17518);
      if ( v42 )
      {
        v43 = (__int64)v42;
        qdf_mem_copy(v42, v18, 0x2B0u);
        LODWORD(v75) = 5139;
        v76 = v43;
        result = scheduler_post_message_debug(
                   0x34u,
                   0x35u,
                   53,
                   (unsigned __int16 *)&v75,
                   0x447Au,
                   (__int64)"sme_send_start_bss_msg");
        if ( !(_DWORD)result )
          goto LABEL_11;
        goto LABEL_40;
      }
LABEL_38:
      result = 2;
      goto LABEL_11;
    }
    v14 = "%s: invalid parameter";
    v15 = "sme_send_start_bss_msg";
LABEL_8:
    v16 = 2;
LABEL_9:
    qdf_trace_msg(0x34u, v16, v14, a3, a4, a5, a6, a7, a8, a9, a10, v15);
    goto LABEL_10;
  }
  if ( a2 != 2 )
  {
    if ( a2 == 3 )
    {
      _qdf_trigger_self_recovery();
      result = 0;
      goto LABEL_11;
    }
LABEL_15:
    v14 = "%s: unknown reason code";
    v15 = "sme_sap_ser_callback";
    v16 = 8;
    goto LABEL_9;
  }
  v52 = *(_QWORD *)(a1 + 32);
  if ( v52 )
    wlan_objmgr_vdev_release_ref(v52, 7u, v12, a3, a4, a5, a6, a7, a8, a9, a10);
  result = *(_QWORD *)(a1 + 40);
  if ( result )
  {
    _qdf_mem_free(result);
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
