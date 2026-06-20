__int64 __fastcall mlme_vdev_state_suspend_entry(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  v9 = *(_QWORD *)(result + 520);
  if ( !v9 )
    result = qdf_trace_msg(0x68u, 2u, "%s:  VDEV is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "mlme_vdev_sm_state_update");
  *(_QWORD *)(v9 + 20) = 0x1100000004LL;
  return result;
}
