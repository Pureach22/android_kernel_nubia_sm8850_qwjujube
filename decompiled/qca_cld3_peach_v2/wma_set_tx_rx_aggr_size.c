__int64 __fastcall wma_set_tx_rx_aggr_size(
        unsigned __int8 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 *v26; // x21
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x8
  __int64 v31; // x0
  _DWORD *v32; // x25
  __int64 v33; // x23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  const char *v52; // x2

  context = _cds_get_context(54, (__int64)"wma_set_tx_rx_aggr_size", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
    return 4;
  v25 = context[65];
  v26 = context;
  if ( !v25 )
  {
    v52 = "%s: WMA interface is invalid!";
LABEL_19:
    qdf_trace_msg(0x36u, 2u, v52, v17, v18, v19, v20, v21, v22, v23, v24, "wma_set_tx_rx_aggr_size");
    return 4;
  }
  v27 = v25 + 488LL * a1;
  v28 = 140;
  if ( a4 )
  {
    v29 = 144;
  }
  else
  {
    v28 = 132;
    v29 = 136;
  }
  v30 = v27 + 16;
  *(_DWORD *)(v30 + v28) = a2;
  *(_DWORD *)(v30 + v29) = a3;
  v31 = wmi_buf_alloc_fl(*context, 0x14u, "wma_set_tx_rx_aggr_size", 0x1472u);
  if ( !v31 )
    return 2;
  v32 = *(_DWORD **)(v31 + 224);
  v33 = v31;
  qdf_mem_set(v32, 0x14u, 0);
  *v32 = 34471952;
  if ( (wmi_service_enabled(*v26, 0xF7u, v34, v35, v36, v37, v38, v39, v40, v41) & 1) != 0 )
    v32[4] |= 0x40u;
  if ( a2 >= 0x41 && a2 != 256 && a2 != 512 && a2 != 1024 )
  {
    v52 = "%s: Invalid AMPDU Size";
    goto LABEL_19;
  }
  v42 = v32[4];
  v32[1] = a1;
  v32[2] = a2;
  v32[3] = a3;
  if ( a4 == 1 )
    v32[4] = v42 | 4;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: tx aggr: %d rx aggr: %d vdev: %d enable_bitmap %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wma_set_tx_rx_aggr_size",
    a2,
    a3);
  result = wmi_unified_cmd_send_fl(
             *v26,
             v33,
             0x14u,
             0x5019u,
             "wma_set_tx_rx_aggr_size",
             0x1498u,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
