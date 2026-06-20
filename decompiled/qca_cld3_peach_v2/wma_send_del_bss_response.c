__int64 __fastcall wma_send_del_bss_response(
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 v22; // x23
  _QWORD *v23; // x22
  __int64 v24; // x8
  void (*v25)(void); // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
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
  _QWORD *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  __int64 *v63; // x22
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7

  context = _cds_get_context(71, (__int64)"wma_send_del_bss_response", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !a2 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: req is NULL",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_send_del_bss_response");
  v21 = *(unsigned __int8 *)(a2 + 4);
  v22 = *(_QWORD *)(a1 + 520) + 488LL * *(unsigned __int8 *)(a2 + 4);
  if ( !*(_QWORD *)v22 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id %d iface->vdev is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_send_del_bss_response",
      *(unsigned __int8 *)(a2 + 4));
    return _qdf_mem_free(a2);
  }
  v23 = context;
  if ( context && *context )
  {
    v24 = *(_QWORD *)(*context + 120LL);
    if ( v24 )
    {
      v25 = *(void (**)(void))(v24 + 40);
      if ( v25 )
      {
        if ( *((_DWORD *)v25 - 1) != -251540498 )
          __break(0x8228u);
        v25();
      }
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d, un-pausing tx_ll_queue for VDEV_STOP rsp",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_send_del_bss_response",
      v21);
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v13, v14, v15, v16, v17, v18, v19, v20, "cdp_fc_vdev_flush");
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d, un-pausing tx_ll_queue for VDEV_STOP rsp",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wma_send_del_bss_response",
      v21);
    if ( !v23 )
    {
LABEL_20:
      qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_fc_vdev_unpause");
      goto LABEL_21;
    }
  }
  if ( !*v23 )
    goto LABEL_20;
  v43 = *(_QWORD *)(*v23 + 120LL);
  if ( v43 )
  {
    v44 = *(_DWORD **)(v43 + 56);
    if ( v44 )
    {
      if ( *(v44 - 1) != 875705606 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))v44)(v23, v21, 8, 0);
    }
  }
LABEL_21:
  v45 = _cds_get_context(54, (__int64)"wma_vdev_clear_pause_bit", v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v45 && !(v45[65] + 488LL * v21) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Interface is NULL",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wma_vdev_clear_pause_bit");
  *(_DWORD *)(v22 + 228) = 2;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: (type %d subtype %d) BSS is stopped",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wma_send_del_bss_response",
    *(unsigned int *)(v22 + 164),
    *(unsigned int *)(v22 + 168));
  v62 = *(_QWORD *)(a1 + 520) + 488LL * v21;
  v63 = *(__int64 **)(v62 + 8);
  if ( v63 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Freeing beacon struct %pK, template memory %pK",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wma_send_del_bss_response",
      *(_QWORD *)(v62 + 8),
      *v63);
    if ( *((_BYTE *)v63 + 12) )
      _qdf_nbuf_unmap_single(*(_QWORD *)(a1 + 184), *v63, 1);
    if ( *v63 )
      _qdf_nbuf_free(*v63);
    _qdf_mem_free((__int64)v63);
    *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * v21 + 8) = 0;
  }
  if ( *(_DWORD *)a2 == 36 )
  {
    _qdf_mem_free(a2);
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: DEL BSS from ADD BSS timeout do not send resp to UMAC (vdev id %x)",
               v64,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               v71,
               "wma_send_del_bss_response",
               v21);
    if ( !*(_QWORD *)(v22 + 216) )
      return result;
  }
  else
  {
    *(_DWORD *)a2 = 0;
    result = wma_send_msg_high_priority(a1, 4136, a2, 0);
    if ( !*(_QWORD *)(v22 + 216) )
      return result;
  }
  if ( *(_BYTE *)(v22 + 224) == 1 )
  {
    *(_BYTE *)(v22 + 224) = 0;
    qdf_trace_msg(0x36u, 1u, "scheduling deferred deletion (vdev id %x)", v72, v73, v74, v75, v76, v77, v78, v79, v21);
    return wma_vdev_detach(*(_QWORD *)(v22 + 216), v80, v81, v82, v83, v84, v85, v86, v87);
  }
  return result;
}
