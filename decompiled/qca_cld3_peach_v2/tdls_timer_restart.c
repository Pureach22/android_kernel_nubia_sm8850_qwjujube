__int64 __fastcall tdls_timer_restart(
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0

  if ( !wlan_cm_is_vdev_connected(a1, a4, a5, a6, a7, a8, a9, a10, a11) )
    return qdf_trace_msg(
             0,
             8u,
             "%s: vdev:%d is not connected. Can't restart timer",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "tdls_timer_restart",
             *(unsigned __int8 *)(a1 + 168));
  result = qdf_mc_timer_get_current_state(a2);
  if ( (_DWORD)result != 21 )
    return qdf_mc_timer_start(a2, a3);
  return result;
}
