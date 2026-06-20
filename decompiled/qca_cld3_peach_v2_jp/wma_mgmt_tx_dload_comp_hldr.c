__int64 __fastcall wma_mgmt_tx_dload_comp_hldr(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x8
  __int64 v23; // x1
  __int64 result; // x0
  const char *v25; // x2
  unsigned int v26; // w1

  v12 = *(_QWORD *)(a1 + 16);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Tx Complete Status %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_mgmt_tx_dload_comp_hldr",
    a3);
  v22 = *(_DWORD **)(a1 + 336);
  if ( !v22 )
  {
    v25 = "%s: Tx Complete Cb not registered by umac";
    v26 = 2;
    return qdf_trace_msg(0x36u, v26, v25, v14, v15, v16, v17, v18, v19, v20, v21, "wma_mgmt_tx_dload_comp_hldr");
  }
  if ( *(v22 - 1) != 1402114878 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v22)(v12, a2, 0);
  *(_QWORD *)(a1 + 336) = 0;
  result = qdf_event_set(a1 + 344, v23);
  if ( (_DWORD)result )
  {
    v25 = "%s: Event Set failed - tx_frm_comp_event";
    v26 = 1;
    return qdf_trace_msg(0x36u, v26, v25, v14, v15, v16, v17, v18, v19, v20, v21, "wma_mgmt_tx_dload_comp_hldr");
  }
  return result;
}
