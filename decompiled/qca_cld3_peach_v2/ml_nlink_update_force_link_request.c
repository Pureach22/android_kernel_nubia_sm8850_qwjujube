__int64 __fastcall ml_nlink_update_force_link_request(
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
        __int64 *a11,
        unsigned int a12)
{
  __int64 v12; // x20
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x11

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
             "ml_nlink_update_force_link_request");
  if ( a12 >= 4 )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: invalid source %d",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ml_nlink_update_force_link_request",
             a12);
  qdf_mutex_acquire(v12 + 1656);
  v16 = *(_QWORD *)(v12 + 2224) + 20LL * a12;
  v18 = *a11;
  v17 = a11[1];
  *(_DWORD *)(v16 + 1384) = *((_DWORD *)a11 + 4);
  *(_QWORD *)(v16 + 1376) = v17;
  *(_QWORD *)(v16 + 1368) = v18;
  return qdf_mutex_release(v12 + 1656);
}
