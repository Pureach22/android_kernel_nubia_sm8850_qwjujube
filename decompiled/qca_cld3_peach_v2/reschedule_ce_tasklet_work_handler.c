__int64 __fastcall reschedule_ce_tasklet_work_handler(__int64 result)
{
  __int64 v1; // x8
  unsigned int v2; // w9
  __int64 v3; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v13; // x8

  v1 = *(_QWORD *)(result - 8);
  if ( !v1 )
    return qdf_trace_msg(61, 2, "%s: tasklet scn is null", "reschedule_ce_tasklet_work_handler");
  if ( (*(_BYTE *)(v1 + 584) & 1) == 0 )
    return qdf_trace_msg(61, 2, "%s: wlan driver is unloaded", "reschedule_ce_tasklet_work_handler");
  v2 = *(_DWORD *)(result - 16);
  if ( v2 >= 0xC )
  {
    __break(0x5512u);
LABEL_13:
    _X9 = (unsigned __int64 *)(result + 8);
    __asm { PRFM            #0x11, [X9] }
    do
      v6 = __ldxr(_X9);
    while ( __stlxr(v6 | 1, _X9) );
    __dmb(0xBu);
    if ( (v6 & 1) == 0 )
      return _tasklet_hi_schedule();
    return result;
  }
  v3 = v1 + 56LL * v2;
  result = v3 + 26448;
  if ( *(_BYTE *)(v3 + 26492) != 1 )
    return result;
  if ( *(_BYTE *)(v3 + 26493) == 1 )
    goto LABEL_13;
  _X9 = (unsigned __int64 *)(v3 + 26456);
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stlxr(v13 | 1, _X9) );
  __dmb(0xBu);
  if ( (v13 & 1) == 0 )
    return _tasklet_schedule();
  return result;
}
