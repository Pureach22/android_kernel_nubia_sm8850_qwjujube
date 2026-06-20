__int64 __fastcall wma_peer_assoc_conf_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  __int64 req; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w4
  unsigned __int8 *v31; // x21
  int v32; // w8
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w9
  int v38; // w10
  int v39; // w11
  int v41; // w21
  int v42; // w22
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w20
  __int64 v53; // [xsp+0h] [xbp-20h]

  if ( !a2 || (v10 = *a2) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid peer assoc conf event buffer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_peer_assoc_conf_handler");
    return 4294967274LL;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: peer assoc conf for vdev:%d mac=%02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_peer_assoc_conf_handler",
    *(unsigned int *)(v10 + 4),
    (unsigned __int8)*(_DWORD *)(v10 + 8),
    (unsigned __int8)BYTE1(*(_DWORD *)(v10 + 8)),
    (unsigned __int8)BYTE2(*(_DWORD *)(v10 + 8)),
    *(unsigned __int8 *)(v10 + 13));
  req = wma_find_req(a1, *(unsigned int *)(v10 + 4), 1, 0);
  if ( !req )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to lookup request message for vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_peer_assoc_conf_handler",
      *(unsigned int *)(v10 + 4));
    return 4294967274LL;
  }
  v21 = req;
  qdf_mc_timer_stop(req);
  v30 = *(_DWORD *)(v21 + 200);
  if ( v30 == 4133 )
  {
    v41 = *(_DWORD *)(v10 + 4);
    v42 = *(_DWORD *)(v10 + 16);
    v43 = _qdf_mem_malloc(0x10u, "wma_send_add_bss_resp", 4863);
    if ( v43 )
    {
      *(_BYTE *)v43 = v41;
      *(_DWORD *)(v43 + 4) = v42;
      lim_handle_add_bss_rsp(*(_QWORD *)(a1 + 16), (unsigned __int8 *)v43, v44, v45, v46, v47, v48, v49, v50, v51);
    }
  }
  else if ( v30 == 4129 )
  {
    v31 = *(unsigned __int8 **)(v21 + 184);
    if ( !v31 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: add STA params is NULL for vdev %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_peer_assoc_conf_handler",
        *(unsigned int *)(v10 + 4));
      v52 = -22;
      goto LABEL_14;
    }
    v32 = *(_DWORD *)(v10 + 16);
    v33 = v31[8];
    v34 = v31[131];
    v35 = *((unsigned __int16 *)v31 + 3);
    v36 = *v31;
    v37 = v31[1];
    v38 = v31[2];
    v39 = v31[5];
    *((_DWORD *)v31 + 25) = v32;
    LODWORD(v53) = v37;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Send ADD_STA_RSP: statype %d vdev_id %d aid %d bssid %02x:%02x:%02x:**:**:%02x status %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_peer_assoc_conf_handler",
      v33,
      v34,
      v35,
      v36,
      v53,
      v38,
      v39,
      v32);
    wma_send_msg_high_priority(a1, 4130, v31, 0);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Unhandled request message type: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_peer_assoc_conf_handler");
  }
  v52 = 0;
LABEL_14:
  qdf_mc_timer_destroy(v21);
  _qdf_mem_free(v21);
  return v52;
}
