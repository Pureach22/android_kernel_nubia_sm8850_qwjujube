__int64 __fastcall wma_update_tx_fail_cnt_th(
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
  __int64 v10; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__wma_validate_handle",
             "wma_update_tx_fail_cnt_th");
  v10 = *a1;
  result = _wmi_validate_handle(*a1, (__int64)"wma_update_tx_fail_cnt_th", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v21 = *a2;
    v22 = *((_DWORD *)a2 + 1);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Set TX pkt fail count threshold  vdevId %d count %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_update_tx_fail_cnt_th",
      v21,
      v22);
    result = wma_vdev_set_param(v10, v21, 0x4Cu, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to send TX pkt fail count threshold command",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "wma_update_tx_fail_cnt_th");
  }
  return result;
}
