__int64 __fastcall ce_tasklet(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x1
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x8
  int v8; // w4
  unsigned int v11; // w10
  unsigned int v14; // w10
  unsigned __int64 v21; // x8
  unsigned __int64 v24; // x8

  v2 = *(unsigned int *)(result + 40);
  if ( (unsigned int)v2 >= 0xC )
  {
    __break(0x5512u);
LABEL_18:
    _X8 = (unsigned int *)(v1 + 672);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 - 1, _X8) );
    return result;
  }
  v1 = *(_QWORD *)(result + 48);
  v3 = result;
  v4 = v1 + 8 * v2;
  v5 = *(_QWORD *)(v4 + 480);
  hif_record_ce_desc_event(v1, v2, 17, 0, 0, -1, v4);
  if ( *(_DWORD *)(v1 + 684) )
    qdf_trace_msg(61, 2, "%s: ce %d tasklet fired after link suspend", "ce_tasklet", *(_DWORD *)(v3 + 40));
  ce_per_engine_service(v1, *(_DWORD *)(v3 + 40));
  if ( !ce_check_rx_pending(v5) || (v6 = *(unsigned __int8 *)(v3 + 44), (_DWORD)v6 != 1) )
  {
    result = hif_record_ce_desc_event(v1, *(_DWORD *)(v3 + 40), 20, 0, 0, -1, v6);
    if ( *(_DWORD *)(v1 + 600) != 1 && (*(_BYTE *)(v1 + 587) & 1) == 0 )
      result = hif_irq_enable(v1, *(unsigned int *)(v3 + 40));
    goto LABEL_18;
  }
  v7 = *(_QWORD *)(v3 + 8);
  v8 = *(_DWORD *)(v3 + 40);
  if ( (v7 & 1) != 0 )
  {
    result = qdf_trace_msg(61, 5, "%s: ce_id%d tasklet was scheduled, return", "ce_tasklet", v8);
    _X8 = (unsigned int *)(v1 + 672);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 - 1, _X8) );
  }
  else
  {
    result = hif_record_ce_desc_event(v1, v8, 18, 0, 0, -1, v7);
    if ( *(_BYTE *)(v3 + 45) == 1 )
    {
      _X9 = (unsigned __int64 *)(v3 + 8);
      __asm { PRFM            #0x11, [X9] }
      do
        v21 = __ldxr(_X9);
      while ( __stlxr(v21 | 1, _X9) );
      __dmb(0xBu);
      if ( (v21 & 1) == 0 )
        return _tasklet_hi_schedule(v3);
    }
    else
    {
      _X9 = (unsigned __int64 *)(v3 + 8);
      __asm { PRFM            #0x11, [X9] }
      do
        v24 = __ldxr(_X9);
      while ( __stlxr(v24 | 1, _X9) );
      __dmb(0xBu);
      if ( (v24 & 1) == 0 )
        return _tasklet_schedule(v3);
    }
  }
  return result;
}
