__int64 __fastcall wma_aggr_qos_req(
        _QWORD *a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (wma_is_vdev_valid(*(unsigned __int8 *)(a2 + 253), a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: vdev id:%d is not active ",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "wma_aggr_qos_req",
             *(unsigned __int8 *)(a2 + 253));
  wmi_unified_aggr_qos_cmd(*a1, a2);
  return wma_send_msg_high_priority(a1, 4238, a2, 0);
}
