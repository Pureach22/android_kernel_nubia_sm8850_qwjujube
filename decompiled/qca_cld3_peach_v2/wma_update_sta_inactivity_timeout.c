__int64 __fastcall wma_update_sta_inactivity_timeout(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    result = _wmi_validate_handle(*a1, (__int64)"wma_update_sta_inactivity_timeout", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( !(_DWORD)result )
    {
      result = wma_send_multi_pdev_vdev_set_params(1, v10, v11, v12, v13, v14, v15, v16, v17);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: Failed to send idle_inactive,unresponsive time vdev set params",
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   v25,
                   "wma_update_sta_inactivity_timeout");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Invalid WMA handle (via %s)",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "__wma_validate_handle",
               "wma_update_sta_inactivity_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
