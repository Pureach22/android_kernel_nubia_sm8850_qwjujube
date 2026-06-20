__int64 __fastcall scheduler_watchdog_timeout(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _BYTE s[666]; // [xsp+Eh] [xbp-2A2h] BYREF
  __int64 v29; // [xsp+2A8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (qdf_is_recovering() & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x4Au,
               8u,
               "%s: Recovery is in progress ignore timeout",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "scheduler_watchdog_timeout");
  }
  else
  {
    memset(s, 0, sizeof(s));
    v19 = "<null>";
    if ( *(_QWORD *)(a1 + 776) )
    {
      qdf_sprint_symbol();
      if ( *(_QWORD *)(a1 + 776) )
        v19 = s;
    }
    qdf_trace_msg(
      0x4Au,
      1u,
      "%s: Callback %s (type 0x%x) exceeded its allotted time of %ds",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "scheduler_watchdog_notify",
      v19,
      *(unsigned __int16 *)(a1 + 682),
      *(unsigned int *)(a1 + 712) / 0x3E8uLL);
    result = *(_QWORD *)(a1 + 544);
    if ( result )
      result = qdf_print_thread_trace(result);
    if ( (*(_QWORD *)(a1 + 616) & 0x10000) == 0 )
    {
      qdf_trace_msg(
        0x4Au,
        2u,
        "%s: Triggering self recovery on sheduler timeout",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "scheduler_watchdog_timeout");
      result = _qdf_trigger_self_recovery();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
