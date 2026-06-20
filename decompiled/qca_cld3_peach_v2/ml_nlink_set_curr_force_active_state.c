__int64 __fastcall ml_nlink_set_curr_force_active_state(
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
        unsigned __int16 a11,
        unsigned int a12)
{
  __int64 v12; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  unsigned __int16 v24; // w8

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
             "ml_nlink_set_curr_force_active_state");
  qdf_mutex_acquire(v12 + 1656);
  v23 = *(_QWORD *)(v12 + 2224);
  if ( a12 == 2 )
  {
    v24 = *(_WORD *)(v23 + 1348) | a11;
    *(_WORD *)(v23 + 1348) = v24;
  }
  else if ( a12 == 1 )
  {
    v24 = *(_WORD *)(v23 + 1348) & ~a11;
    *(_WORD *)(v23 + 1348) = v24;
  }
  else if ( a12 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unknown update ctrl %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ml_nlink_update_link_bitmap",
      a12);
    v24 = *(_WORD *)(v23 + 1348);
  }
  else
  {
    *(_WORD *)(v23 + 1348) = a11;
    v24 = a11;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x:ctrl %d bitmap 0x%x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "ml_nlink_set_curr_force_active_state",
    *(unsigned __int16 *)(v23 + 1350),
    v24,
    *(unsigned __int8 *)(v23 + 1356),
    *(unsigned __int16 *)(v23 + 1358),
    *(unsigned __int8 *)(v23 + 1352),
    *(unsigned __int16 *)(v23 + 1354),
    *(unsigned __int16 *)(v23 + 1360),
    a12,
    a11);
  return qdf_mutex_release(v12 + 1656);
}
