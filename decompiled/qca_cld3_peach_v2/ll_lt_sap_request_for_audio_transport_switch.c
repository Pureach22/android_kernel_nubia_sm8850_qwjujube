__int64 __fastcall ll_lt_sap_request_for_audio_transport_switch(
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
  _QWORD *comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x9
  const char *v24; // x2
  _QWORD *v25; // x22
  unsigned int trnsprt_switch_rjt_th_cu; // w20
  unsigned int current_state; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x7
  __int64 v37; // x4
  __int64 v38; // x6

  if ( !a1 )
  {
    qdf_trace_msg(0xA1u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "ll_sap_get_vdev_priv_obj");
    goto LABEL_10;
  }
  comp_private_obj = (_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
  {
LABEL_10:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM vdev %d ll_sap obj null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ll_lt_sap_request_for_audio_transport_switch",
      *(unsigned __int8 *)(a1 + 168));
    return 4;
  }
  v21 = *comp_private_obj;
  if ( !*comp_private_obj )
    return 4;
  v22 = *(_QWORD *)(a1 + 216);
  if ( !v22 )
  {
    v24 = "%s: pdev is NULL";
LABEL_15:
    qdf_trace_msg(
      0xA1u,
      8u,
      v24,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ll_lt_sap_request_for_audio_transport_switch");
    return 4;
  }
  if ( !*(_QWORD *)(v22 + 80) )
  {
    v24 = "%s: psoc is NULL";
    goto LABEL_15;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: BS_SM vdev %d WLAN_BS_REQ_TO_NON_WLAN accepted",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "ll_lt_sap_request_for_audio_transport_switch",
        *(unsigned __int8 *)(a1 + 168));
      return 0;
    }
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: BS_SM vdev %d Invalid audio transport type %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ll_lt_sap_request_for_audio_transport_switch",
      *(unsigned __int8 *)(a1 + 168),
      a2);
    return 4;
  }
  v25 = comp_private_obj;
  trnsprt_switch_rjt_th_cu = wlan_dcs_get_trnsprt_switch_rjt_th_cu(
                               *(_QWORD *)(v22 + 80),
                               *(_BYTE *)(v22 + 40),
                               v13,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19,
                               v20);
  current_state = qdf_mc_timer_get_current_state(v21 + 624);
  v36 = *((unsigned int *)v25 + 8);
  v37 = *(unsigned __int8 *)(a1 + 168);
  v38 = *(unsigned int *)(v21 + 244);
  if ( *(_DWORD *)(v21 + 244) || current_state == 21 || (unsigned int)v36 > trnsprt_switch_rjt_th_cu )
  {
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: BS_SM vdev %d WLAN_BS_REQ_TO_WLAN rejected, total ref count %d timer state %d cur_freq_unused_cu %u (threshold %u)",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "ll_lt_sap_request_for_audio_transport_switch",
      v37,
      (unsigned int)v38,
      current_state,
      v36,
      trnsprt_switch_rjt_th_cu);
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: BS_SM vdev %d WLAN_BS_REQ_TO_WLAN accepted, timer state %d ref %d cur_freq_unused_cu %u (threshold %u)",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "ll_lt_sap_request_for_audio_transport_switch",
      v37,
      current_state,
      v38,
      trnsprt_switch_rjt_th_cu);
    return 0;
  }
}
