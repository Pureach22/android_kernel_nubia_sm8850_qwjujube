__int64 __fastcall sde_encoder_cancel_vrr_timers(__int64 result)
{
  char v1; // w29
  __int64 v2; // x8
  __int64 v3; // x19
  int v4; // w6
  int v5; // w7

  if ( result )
  {
    v2 = *(_QWORD *)(result + 328);
    if ( v2 )
    {
      if ( *(_BYTE *)(result + 748) == 1 )
      {
        v3 = result;
        hrtimer_cancel(v2 + 2544);
        return sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "sde_encoder_cancel_vrr_timers",
                 2258,
                 -1,
                 *(_DWORD *)(v3 + 24),
                 -1059143953,
                 v4,
                 v5,
                 v1);
      }
    }
  }
  return result;
}
