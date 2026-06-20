__int64 __fastcall wma_delete_sta_req_ndi_mode(
        __int64 *a1,
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
  unsigned int v10; // w21
  unsigned int v13; // w22
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

  v10 = *(unsigned __int8 *)(a2 + 10);
  v13 = wma_remove_peer(a1, (const void *)(a2 + 12), v10, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  *(_DWORD *)(a2 + 4) = 0;
  if ( v13 )
  {
LABEL_6:
    if ( !*(_BYTE *)(a2 + 8) )
    {
LABEL_9:
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: NDI Del Sta resp not needed",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_delete_sta_req_ndi_mode");
      _qdf_mem_free(a2);
      return v13;
    }
LABEL_7:
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending del rsp to umac (status: %d)",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_delete_sta_req_ndi_mode",
      *(unsigned int *)(a2 + 4));
    wma_send_msg_high_priority((__int64)a1, 0x1024u, a2, 0);
    return v13;
  }
  if ( (wmi_service_enabled(*a1, 0x6Eu, v14, v15, v16, v17, v18, v19, v20, v21) & 1) == 0 )
  {
    v13 = 0;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Wait for the peer delete. vdev_id %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wma_delete_sta_req_ndi_mode",
    v10);
  if ( !wma_fill_hold_req(a1, v10, 0x1023u, 0xEu, (const void *)(a2 + 12), a2, 0x1F40u) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request for vdev_id %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_delete_sta_req_ndi_mode",
      v10);
    v13 = 29;
    if ( !*(_BYTE *)(a2 + 8) )
      goto LABEL_9;
    goto LABEL_7;
  }
  return 0;
}
