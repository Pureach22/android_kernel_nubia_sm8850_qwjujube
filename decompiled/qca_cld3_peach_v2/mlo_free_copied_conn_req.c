__int64 __fastcall mlo_free_copied_conn_req(
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
  void *v10; // x0

  if ( result )
  {
    v9 = result;
    qdf_trace_msg(0x8Fu, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_free_copied_conn_req");
    qdf_mutex_acquire(v9 + 40);
    v10 = *(void **)(v9 + 32);
    if ( v10 )
    {
      wlan_cm_free_connect_req(v10);
      *(_QWORD *)(v9 + 32) = 0;
    }
    return qdf_mutex_release(v9 + 40);
  }
  return result;
}
