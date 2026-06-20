__int64 __fastcall sde_encoder_vblank_callback(__int64 result, _QWORD *a2)
{
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x23
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v13; // w9
  void (__fastcall *v14)(__int64, __int64); // x8
  unsigned int v20; // w9
  char v21; // [xsp+0h] [xbp+0h]

  if ( result && a2 && a2[64] )
  {
    v3 = result;
    _ReadStatusReg(SP_EL0);
    if ( (*(_QWORD *)(*(_QWORD *)(a2[64] + 152LL) + 22008LL) & 0x1000000) == 0
      || (result = sde_encoder_calc_last_vsync_timestamp(result), (v4 = result) == 0) )
    {
      v4 = ktime_get(result);
    }
    v5 = raw_spin_lock_irqsave(v3 + 128);
    v6 = (__int64 (__fastcall *)(_QWORD))a2[4];
    v7 = v5;
    a2[108] = v4;
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != -1375811177 )
        __break(0x8228u);
      if ( (v6(a2) & 1) != 0 )
      {
        _X8 = (unsigned int *)(v3 + 804);
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 + 1, _X8) );
      }
    }
    _X8 = (unsigned int *)a2 + 215;
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    v14 = *(void (__fastcall **)(__int64, __int64))(v3 + 504);
    if ( v14 && (*(_BYTE *)(v3 + 749) & 1) == 0 )
    {
      v10 = *(_QWORD *)(v3 + 512);
      if ( *((_DWORD *)v14 - 1) != -1575138099 )
        __break(0x8228u);
      v14(v10, v4);
    }
    raw_spin_unlock_irqrestore(v3 + 128, v7);
    v11 = a2[64];
    if ( *(_DWORD *)(*(_QWORD *)(v11 + 152) + 21980LL) )
    {
      sde_encoder_perf_uidle_status(v11, *(_QWORD *)(v3 + 1360));
      v11 = a2[64];
    }
    if ( *(_DWORD *)(v11 + 6400) )
      sde_encoder_hw_fence_status(v11, *(_QWORD *)(v3 + 1360), a2[52]);
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_vblank_callback",
             4781,
             -1,
             *(_DWORD *)(v3 + 24),
             v4 / 1000,
             *(_DWORD *)(v3 + 804),
             -1059143953,
             v21);
  }
  return result;
}
