__int64 __fastcall wma_unified_bcntx_status_event_handler(
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
  __int64 v10; // x20
  unsigned int v11; // w4
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v31; // x2
  __int64 v32; // x8

  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid bcn tx response event buffer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_unified_bcntx_status_event_handler");
    return 4294967274LL;
  }
  v10 = *a2;
  v11 = *(_DWORD *)(*a2 + 4);
  if ( v11 >= *(unsigned __int16 *)(a1 + 162) )
  {
    v31 = "%s: received invalid vdev_id %d";
LABEL_10:
    qdf_trace_msg(0x36u, 2u, v31, a3, a4, a5, a6, a7, a8, a9, a10, "wma_unified_bcntx_status_event_handler");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * v11) )
  {
    v31 = "%s: vdev is NULL for vdev_%d";
    goto LABEL_10;
  }
  if ( wma_is_vdev_in_ap_mode(a1, v11, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v21 = _qdf_mem_malloc(6u, "wma_unified_bcntx_status_event_handler", 581);
    if ( !v21 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to alloc beacon_tx_complete_ind",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_unified_bcntx_status_event_handler");
      return 4294967284LL;
    }
    *(_DWORD *)v21 = 397523;
    *(_BYTE *)(v21 + 4) = *(_DWORD *)(v10 + 4);
    wma_send_msg(a1, 0x10D3u, v21, 0);
  }
  else
  {
    v32 = *(_QWORD *)(a1 + 520) + 488LL * *(unsigned int *)(v10 + 4);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Beacon Tx Indication does not support type %d and sub_type %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_unified_bcntx_status_event_handler",
      *(unsigned int *)(v32 + 164),
      *(unsigned int *)(v32 + 168));
  }
  return 0;
}
