__int64 __fastcall ml_nlink_get_dynamic_inactive_links(
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
        _WORD *a11,
        _WORD *a12)
{
  __int64 v12; // x21
  __int64 v15; // x8

  v12 = *(_QWORD *)(a10 + 1360);
  if ( !v12 || !*(_QWORD *)(v12 + 2224) )
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
             "ml_nlink_get_dynamic_inactive_links");
  qdf_mutex_acquire(v12 + 1656);
  v15 = *(_QWORD *)(v12 + 2224);
  *a11 = *(_WORD *)(v15 + 1360);
  *a12 = *(_WORD *)(v15 + 1350);
  return qdf_mutex_release(v12 + 1656);
}
