_DWORD *__fastcall sde_encoder_underrun_callback(_DWORD *result, __int64 a2)
{
  _DWORD *v3; // x20
  int v4; // w4
  __int64 v5; // x3
  __int64 v6; // x0
  void (*v7)(void); // x8
  __int64 v8; // x0
  __int64 v9; // x3
  unsigned int v16; // w9
  char v17; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    v3 = result;
    _ReadStatusReg(SP_EL0);
    _X8 = (unsigned int *)(a2 + 872);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 + 1, _X8) );
    if ( result )
      v4 = result[6];
    else
      v4 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_underrun_callback",
      4826,
      -1,
      v4,
      *(_DWORD *)(a2 + 872),
      **(_DWORD **)(*(_QWORD *)result + 64LL),
      -1059143953,
      v17);
    v6 = *((_QWORD *)v3 + 41);
    if ( v6 )
    {
      v7 = *(void (**)(void))(v6 + 304);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != 836880908 )
          __break(0x8228u);
        v7();
      }
    }
    v8 = *(_QWORD *)(a2 + 512);
    if ( v8 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v8 + 152) + 21980LL) )
        sde_encoder_perf_uidle_status(v8, *((_QWORD *)v3 + 170));
    }
    sde_dbg_ctrl("sde_encoder_underrun_callback", "stop_ftrace", 0, v5);
    return (_DWORD *)sde_dbg_ctrl("sde_encoder_underrun_callback", "panic_underrun", 0, v9);
  }
  return result;
}
