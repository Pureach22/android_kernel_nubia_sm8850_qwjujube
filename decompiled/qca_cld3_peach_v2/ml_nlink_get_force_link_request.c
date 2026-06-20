__int64 __fastcall ml_nlink_get_force_link_request(
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
  __int64 v11; // x21
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x10
  __int64 v17; // x8

  v11 = *(_QWORD *)(a1 + 1360);
  if ( !v11 || !*(_QWORD *)(v11 + 2224) )
    return qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: mlo_ctx or sta_ctx null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "ml_nlink_get_force_link_request");
  qdf_mutex_acquire(v11 + 1656);
  v14 = *(_QWORD *)(v11 + 2224) + 20LL * a3;
  v15 = *(_DWORD *)(v14 + 1384);
  v16 = *(_QWORD *)(v14 + 1376);
  v17 = *(_QWORD *)(v14 + 1368);
  *(_DWORD *)(a2 + 16) = v15;
  *(_QWORD *)a2 = v17;
  *(_QWORD *)(a2 + 8) = v16;
  return qdf_mutex_release(v11 + 1656);
}
