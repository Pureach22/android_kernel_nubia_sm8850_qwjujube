__int64 __fastcall wma_vdev_detach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  __int64 v20; // x8
  __int64 v21; // x23
  unsigned int v22; // w21
  __int64 v23; // x22
  __int64 *v24; // x24
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  const char *v34; // x2
  __int64 v35; // x4
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 *v44; // x20
  unsigned int v45; // w21
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w22
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w8
  int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w20
  int v84; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+8h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_vdev_detach", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 168LL);
    v20 = context[65];
    v21 = v20 + 488LL * *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 168LL);
    if ( *(_QWORD *)v21 )
    {
      v22 = *(unsigned __int8 *)(a1 + 6);
      v84 = 0;
      v23 = v20 + 488LL * v22;
      if ( *(_DWORD *)(v23 + 228) == 1 )
      {
        v24 = context;
        if ( (unsigned int)mlme_get_vdev_stop_type(*(_QWORD *)v23, &v84, v11, v12, v13, v14, v15, v16, v17, v18) )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to get wma req msg_type for vdev_id: %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wma_check_for_deferred_peer_delete",
            v22);
LABEL_13:
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: rcvd del_self_sta without del_bss; vdev_id:%d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wma_vdev_detach",
            v19);
          _cds_trigger_recovery(32, (__int64)"wma_vdev_detach", 755, v36, v37, v38, v39, v40, v41, v42, v43);
          result = 16;
          goto LABEL_25;
        }
        if ( v84 != 4135 )
          goto LABEL_13;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: BSS is not yet stopped. Deferring vdev(vdev id %x) deletion",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wma_check_for_deferred_peer_delete",
          v22);
        context = v24;
        *(_QWORD *)(v23 + 216) = a1;
        *(_BYTE *)(v23 + 224) = 1;
      }
      if ( (*(_BYTE *)(v21 + 224) & 1) != 0 )
        goto LABEL_12;
      *(_BYTE *)(v21 + 224) = 0;
      v44 = context;
      *(_QWORD *)(v21 + 216) = 0;
      v45 = *(unsigned __int8 *)(a1 + 6);
      v46 = context[65] + 488LL * *(unsigned __int8 *)(a1 + 6);
      if ( mlme_vdev_uses_self_peer(*(_DWORD *)(v46 + 164), *(_DWORD *)(v46 + 168)) )
      {
        v55 = wma_self_peer_remove(v44, (unsigned __int8 *)a1, v47, v48, v49, v50, v51, v52, v53, v54);
        if ( v55 )
        {
          v64 = v55;
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: can't remove selfpeer, send rsp session: %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "wma_vdev_self_peer_delete",
            v45);
          wma_handle_vdev_detach(v44, a1);
          mlme_vdev_self_peer_delete_resp(a1);
          _cds_trigger_recovery(31, (__int64)"wma_vdev_self_peer_delete", 692, v65, v66, v67, v68, v69, v70, v71, v72);
          v34 = "%s: Failed to send self peer delete:%d";
          v35 = v64;
          goto LABEL_8;
        }
      }
      else
      {
        v73 = *(_DWORD *)(v46 + 164);
        if ( v73 == 5 || v73 == 2 )
          wma_remove_objmgr_peer(
            (__int64)v44,
            *(_QWORD *)v46,
            (unsigned __int8 *)a1,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54);
      }
      v74 = *(_DWORD *)(v21 + 164);
      if ( v74 != 4 )
        *(_BYTE *)(v21 + 184) = 0;
      if ( !mlme_vdev_uses_self_peer(v74, *(_DWORD *)(v21 + 168))
        || (wmi_service_enabled(*v44, 0x6Eu, v75, v76, v77, v78, v79, v80, v81, v82) & 1) == 0 )
      {
        v83 = wma_handle_vdev_detach(v44, a1);
        *(_DWORD *)(a1 + 8) = v83;
        mlme_vdev_self_peer_delete_resp(a1);
        result = v83;
        goto LABEL_25;
      }
LABEL_12:
      result = 0;
      goto LABEL_25;
    }
    v34 = "%s: vdev %d is NULL";
    v35 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 168LL);
LABEL_8:
    qdf_trace_msg(0x36u, 2u, v34, v11, v12, v13, v14, v15, v16, v17, v18, "wma_vdev_detach", v35);
    result = 4;
    goto LABEL_25;
  }
  result = 4;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
