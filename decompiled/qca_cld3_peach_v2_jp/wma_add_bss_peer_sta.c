__int64 __fastcall wma_add_bss_peer_sta(
        unsigned int a1,
        unsigned __int8 *a2,
        char a3,
        unsigned __int8 *a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 *context; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 *v27; // x25
  _QWORD *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  unsigned int peer; // w22
  __int64 v39; // x0
  void *v41; // x26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  __int64 v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  context = _cds_get_context(54, (__int64)"wma_add_bss_peer_sta", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !context )
    return 16;
  if ( (a3 & 1) == 0 )
    return wma_create_peer((__int64)context, a2, 0, 0, a1, (__int64)a4, a5 & 1, v19, v20, v21, v22, v23, v24, v25, v26);
  v27 = context;
  v28 = _cds_get_context(53, (__int64)"wma_create_sta_mode_bss_peer", v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !v28 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev%d: Mac context is null",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wma_create_sta_mode_bss_peer",
      (unsigned __int8)a1);
    return 16;
  }
  v37 = (__int64)v28;
  if ( (*(_BYTE *)(v27[3] + 23) & 0x10) != 0 )
  {
    v39 = _qdf_mem_malloc(6u, "wma_create_sta_mode_bss_peer", 2539);
    if ( v39 )
    {
      v41 = (void *)v39;
      wma_acquire_wakelock(v27 + 391, 8000);
      v50 = wma_add_peer(v27, a2, 0, 0, a1, a4, a5 & 1, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( v50 )
      {
        peer = v50;
        wma_release_wakelock(v27 + 391);
      }
      else
      {
        v51 = v27[65] + 488LL * (unsigned __int8)a1;
        ++*(_DWORD *)(v51 + 244);
        qdf_mem_copy(v41, a2, 6u);
        if ( wma_fill_hold_req(v27, a1, 0x11C5u, 8u, nullptr, (__int64)v41, 0x1F40u) )
          return 0;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: vdev:%d failed to fill peer create req",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "wma_create_sta_mode_bss_peer",
          (unsigned __int8)a1);
        wma_remove_peer_req((__int64)v27, a1, 8u, (__int64)a2, v60, v61, v62, v63, v64, v65, v66, v67);
        wma_remove_peer(v27, a2, a1, 0, v68, v69, v70, v71, v72, v73, v74, v75);
        wma_release_wakelock(v27 + 391);
        peer = 16;
      }
      v39 = (__int64)v41;
    }
    else
    {
      peer = 16;
    }
  }
  else
  {
    peer = wma_create_peer((__int64)v27, a2, 0, 0, a1, (__int64)a4, a5 & 1, v29, v30, v31, v32, v33, v34, v35, v36);
    v39 = 0;
  }
  _qdf_mem_free(v39);
  lim_send_peer_create_resp(v37, a1, peer);
  return peer;
}
