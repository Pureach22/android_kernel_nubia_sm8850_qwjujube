__int64 __fastcall wma_self_peer_remove(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x0
  __int64 v26; // x22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v10 = a2[6];
  if ( a2 )
  {
    v13 = *a2;
    v14 = a2[1];
    v15 = a2[2];
    v16 = a2[5];
  }
  else
  {
    v15 = 0;
    v13 = 0;
    v14 = 0;
    v16 = 0;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: P2P Device: removing self peer %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_self_peer_remove",
    v13,
    v14,
    v15,
    v16);
  if ( (wmi_service_enabled(*a1, 0x6Eu, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0 )
  {
    v25 = (_QWORD *)_qdf_mem_malloc(8u, "wma_self_peer_remove", 549);
    if ( !v25 )
      return 2;
    v26 = (__int64)v25;
    *v25 = a2;
    if ( !wma_fill_hold_req(a1, v10, 4131, 3, 0, v25, 8000) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to allocate request for vdev_id %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wma_self_peer_remove",
        v10);
      wma_remove_req(a1, v10, 3);
      v35 = 16;
LABEL_11:
      _qdf_mem_free(v26);
      return v35;
    }
  }
  else
  {
    v26 = 0;
  }
  v35 = wma_remove_peer(a1, a2, v10, 0);
  if ( v35 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma_remove_peer is failed",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wma_self_peer_remove");
    wma_remove_req(a1, v10, 3);
    if ( v26 )
      goto LABEL_11;
  }
  return v35;
}
