__int64 __fastcall sde_encoder_empulse_callback(__int64 result, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x23
  __int64 v7; // x0
  unsigned int v13; // w9
  void (__fastcall *v14)(__int64, __int64); // x8
  char v15; // [xsp+0h] [xbp+0h]

  if ( result && a2 && *(_QWORD *)(a2 + 512) )
  {
    v3 = result;
    _ReadStatusReg(SP_EL0);
    v4 = ((__int64 (__fastcall *)(__int64))sde_encoder_calc_last_empulse_timestamp)(result);
    if ( !v4 )
      v4 = ktime_get(0);
    v5 = raw_spin_lock_irqsave(v3 + 128);
    _X8 = (unsigned int *)(a2 + 988);
    *(_QWORD *)(a2 + 864) = v4;
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 + 1, _X8) );
    v14 = *(void (__fastcall **)(__int64, __int64))(v3 + 504);
    if ( v14 )
    {
      v7 = *(_QWORD *)(v3 + 512);
      if ( *((_DWORD *)v14 - 1) != -1575138099 )
        __break(0x8228u);
      v14(v7, v4);
    }
    raw_spin_unlock_irqrestore(v3 + 128, v5);
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_empulse_callback",
             4813,
             -1,
             *(_DWORD *)(v3 + 24),
             v4 / 1000,
             *(_DWORD *)(a2 + 988),
             -1059143953,
             v15);
  }
  return result;
}
