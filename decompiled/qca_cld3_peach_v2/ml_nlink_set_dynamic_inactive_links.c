__int64 __fastcall ml_nlink_set_dynamic_inactive_links(
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
        unsigned __int16 a11)
{
  __int64 v11; // x20
  __int64 v13; // x8
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  int v18; // w9
  int v19; // w10
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

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
             "ml_nlink_set_dynamic_inactive_links");
  qdf_mutex_acquire(v11 + 1656);
  v13 = *(_QWORD *)(v11 + 2224);
  v14 = *(unsigned __int16 *)(v13 + 1350);
  v15 = *(unsigned __int16 *)(v13 + 1348);
  v16 = *(unsigned __int8 *)(v13 + 1356);
  v17 = *(unsigned __int16 *)(v13 + 1358);
  v18 = *(unsigned __int8 *)(v13 + 1352);
  v19 = *(unsigned __int16 *)(v13 + 1354);
  *(_WORD *)(v13 + 1360) = a11;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x:dynamic bitmap 0x%x",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "ml_nlink_set_dynamic_inactive_links",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    a11,
    a11);
  return qdf_mutex_release(v11 + 1656);
}
