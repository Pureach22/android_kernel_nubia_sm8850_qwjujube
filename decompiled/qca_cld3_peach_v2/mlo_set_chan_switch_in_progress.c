__int64 __fastcall mlo_set_chan_switch_in_progress(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8

  v10 = *(_QWORD *)(a1 + 1360);
  if ( !v10 )
    return 4;
  v11 = *(_QWORD *)(v10 + 2224);
  if ( !v11 )
    return 4;
  *(_BYTE *)(v11 + 1493) = a2 & 1;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Set ml_chan_switch_in_progress: %d vdev %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_set_chan_switch_in_progress",
    a2 & 1,
    *(unsigned __int8 *)(a1 + 168));
  return 0;
}
