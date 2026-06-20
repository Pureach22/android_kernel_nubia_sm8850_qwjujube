__int64 __fastcall ml_nlink_set_curr_force_active_num_state(
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
        unsigned __int8 a11,
        unsigned __int16 a12)
{
  __int64 v12; // x21
  __int64 v15; // x8
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  int v20; // w9
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

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
             "ml_nlink_set_curr_force_active_num_state");
  qdf_mutex_acquire(v12 + 1656);
  v15 = *(_QWORD *)(v12 + 2224);
  v16 = *(unsigned __int16 *)(v15 + 1350);
  v17 = *(unsigned __int16 *)(v15 + 1348);
  v18 = *(unsigned __int8 *)(v15 + 1356);
  v19 = *(unsigned __int16 *)(v15 + 1358);
  v20 = *(unsigned __int16 *)(v15 + 1360);
  *(_BYTE *)(v15 + 1352) = a11;
  *(_WORD *)(v15 + 1354) = a12;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x:num %d bitmap 0x%x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "ml_nlink_set_curr_force_active_num_state",
    v16,
    v17,
    v18,
    v19,
    a11,
    a12,
    v20,
    a11,
    a12);
  return qdf_mutex_release(v12 + 1656);
}
