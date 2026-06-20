__int64 __fastcall ml_nlink_get_curr_force_state(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        void *a11)
{
  __int64 v11; // x20

  v11 = *(_QWORD *)(a10 + 1360);
  if ( !v11 || !*(_QWORD *)(v11 + 2224) )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ml_nlink_get_curr_force_state");
  qdf_mutex_acquire(v11 + 1656);
  qdf_mem_copy(a11, (const void *)(*(_QWORD *)(v11 + 2224) + 1348LL), 0x12u);
  return qdf_mutex_release(v11 + 1656);
}
