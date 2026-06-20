__int64 __fastcall ml_nlink_init_concurrency_link_request(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x19
  __int64 v11; // x8
  int v12; // w10
  char v13; // w9
  char v14; // w11

  v10 = *(_QWORD *)(a10 + 1360);
  if ( !v10 || !*(_QWORD *)(v10 + 2224) )
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
             "ml_nlink_init_concurrency_link_request");
  qdf_mutex_acquire(v10 + 1656);
  v11 = *(_QWORD *)(v10 + 2224);
  v12 = *(_DWORD *)(v11 + 1348);
  *(_DWORD *)(v11 + 1372) = 1;
  v13 = *(_BYTE *)(v11 + 1352);
  v14 = *(_BYTE *)(v11 + 1356);
  *(_DWORD *)(v11 + 1376) = v12;
  LOWORD(v12) = *(_WORD *)(v11 + 1358);
  *(_BYTE *)(v11 + 1380) = v13;
  *(_BYTE *)(v11 + 1384) = v14;
  *(_WORD *)(v11 + 1386) = v12;
  return qdf_mutex_release(v10 + 1656);
}
