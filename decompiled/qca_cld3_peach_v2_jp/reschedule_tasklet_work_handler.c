__int64 __fastcall reschedule_tasklet_work_handler(
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
  const char *v9; // x2
  unsigned __int64 v16; // x8

  if ( !result )
  {
    v9 = "%s: hif_softc is NULL";
    return qdf_trace_msg(0x3Du, 2u, v9, a2, a3, a4, a5, a6, a7, a8, a9, "reschedule_tasklet_work_handler");
  }
  if ( (*(_BYTE *)(result + 584) & 1) == 0 )
  {
    v9 = "%s: wlan driver is unloaded";
    return qdf_trace_msg(0x3Du, 2u, v9, a2, a3, a4, a5, a6, a7, a8, a9, "reschedule_tasklet_work_handler");
  }
  _X9 = (unsigned __int64 *)(result + 30792);
  __asm { PRFM            #0x11, [X9] }
  do
    v16 = __ldxr(_X9);
  while ( __stlxr(v16 | 1, _X9) );
  __dmb(0xBu);
  if ( (v16 & 1) == 0 )
    return _tasklet_schedule(result + 30784);
  return result;
}
