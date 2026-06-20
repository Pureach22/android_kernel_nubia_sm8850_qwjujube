__int64 __fastcall wma_send_vdev_stop(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  _DWORD *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  _QWORD *v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x21
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
  _BYTE v82[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v83; // [xsp+8h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_send_vdev_stop", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = _cds_get_context(54, (__int64)"wma_send_vdev_stop", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !v19 )
    goto LABEL_12;
  v28 = v19;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id: %d, pausing tx_ll_queue for VDEV_STOP",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wma_send_vdev_stop",
    (unsigned __int8)a1);
  if ( context && *context )
  {
    v37 = *(_QWORD *)(*context + 120LL);
    if ( v37 )
    {
      v38 = *(_DWORD **)(v37 + 48);
      if ( v38 )
      {
        if ( *(v38 - 1) != 875705606 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))v38)(context, a1, 8, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v29, v30, v31, v32, v33, v34, v35, v36, "cdp_fc_vdev_pause");
  }
  if ( (unsigned int)mlme_set_vdev_stop_type(
                       *(_QWORD *)(v28[65] + 488LL * (unsigned __int8)a1),
                       4173,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36) )
  {
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: Failed to set wma req msg_type for vdev_id %d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wma_send_vdev_stop",
      (unsigned __int8)a1);
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  v48 = _cds_get_context(54, (__int64)"wma_vdev_set_pause_bit", v39, v40, v41, v42, v43, v44, v45, v46);
  if ( v48 && !(v48[65] + 488LL * (unsigned __int8)a1) )
    qdf_trace_msg(0x36u, 2u, "%s: Interface is NULL", v49, v50, v51, v52, v53, v54, v55, v56, "wma_vdev_set_pause_bit");
  result = wma_send_vdev_stop_to_fw(v28, a1);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      4u,
      "%s: vdev %d Failed to send vdev stop",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "wma_send_vdev_stop",
      (unsigned __int8)a1);
    v82[0] = a1;
    v65 = 488LL * (unsigned __int8)a1;
    mlme_set_connection_fail(*(_QWORD *)(v28[65] + v65), 0, v66, v67, v68, v69, v70, v71, v72, v73);
    wlan_vdev_mlme_sm_deliver_evt(
      *(_QWORD *)(v28[65] + v65),
      0xEu,
      1u,
      (__int64)v82,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81);
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
