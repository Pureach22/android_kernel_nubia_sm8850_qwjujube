__int64 __fastcall sde_encoder_phys_cmd_autorefresh_done_irq(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w8
  unsigned int v4; // w21
  unsigned int v5; // w9
  _DWORD *v12; // x8
  int v13; // w4

  if ( result )
  {
    v1 = result;
    v2 = raw_spin_lock_irqsave(*(_QWORD *)(result + 824));
    v3 = *(_DWORD *)(v1 + 2696);
    do
    {
      v4 = v3;
      if ( !v3 )
        break;
      v5 = v3 - 1;
      _X11 = (unsigned int *)(v1 + 2696);
      __asm { PRFM            #0x11, [X11] }
      while ( 1 )
      {
        v3 = __ldxr(_X11);
        if ( v3 != v4 )
          break;
        if ( !__stlxr(v5, _X11) )
        {
          __dmb(0xBu);
          break;
        }
      }
    }
    while ( v3 != v4 );
    raw_spin_unlock_irqrestore(*(_QWORD *)(v1 + 824), v2);
    v12 = *(_DWORD **)v1;
    if ( *(_QWORD *)v1 )
      v13 = v12[6];
    else
      v13 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_cmd_autorefresh_done_irq",
      528,
      2,
      v13,
      *(_DWORD *)(*(_QWORD *)(v1 + 496) + 32LL) - 1,
      *(_DWORD *)(*(_QWORD *)(v1 + 424) + 32LL) - 1,
      v4 != 0,
      **(_DWORD **)(*(_QWORD *)v12 + 64LL));
    if ( v4 )
      sde_encoder_phys_signal_frame_done(v1);
    return _wake_up(v1 + 2704, 3, 0, 0);
  }
  return result;
}
