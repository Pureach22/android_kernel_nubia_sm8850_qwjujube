__int64 __fastcall wma_mlme_vdev_notify_down_complete(
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
        __int64 a11)
{
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  _QWORD *context; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x21
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w20
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int v66; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+8h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 504);
  v66 = 0;
  if ( (mlme_is_connection_fail(v13, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0
    || (mlme_get_vdev_start_failed(*(_QWORD *)(a1 + 504), v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Vdev start req failed, no action required",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_mlme_vdev_notify_down_complete");
    mlme_set_connection_fail(*(_QWORD *)(a1 + 504), 0, v22, v23, v24, v25, v26, v27, v28, v29);
    mlme_set_vdev_start_failed(*(_QWORD *)(a1 + 504), 0, v30, v31, v32, v33, v34, v35, v36, v37);
    result = 0;
    goto LABEL_9;
  }
  context = _cds_get_context(54, (__int64)"wma_mlme_vdev_notify_down_complete", v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !context )
    goto LABEL_7;
  v48 = (__int64)context;
  if ( (unsigned int)mlme_get_vdev_stop_type(
                       *(_QWORD *)(context[65] + 488LL * *(unsigned __int8 *)(a11 + 4)),
                       &v66,
                       v40,
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get vdev stop type for vdev_id: %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wma_mlme_vdev_notify_down_complete",
      *(unsigned __int8 *)(a11 + 4));
LABEL_7:
    v57 = 4;
LABEL_8:
    _qdf_mem_free(a11);
    result = v57;
    goto LABEL_9;
  }
  mlme_set_vdev_stop_type(
    *(_QWORD *)(*(_QWORD *)(v48 + 520) + 488LL * *(unsigned __int8 *)(a11 + 4)),
    0,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56);
  if ( v66 == 4173 )
  {
    lim_join_result_callback(*(_QWORD *)(v48 + 16), *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
    v57 = 0;
    goto LABEL_8;
  }
  if ( v66 == 4174 )
  {
    *(_DWORD *)a11 = 0;
    wma_send_msg_high_priority(v48, 0x104Fu, a11, 0);
  }
  else
  {
    wma_send_del_bss_response(v48, a11, v58, v59, v60, v61, v62, v63, v64, v65);
  }
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
