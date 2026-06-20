__int64 __fastcall adreno_start(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x19
  int v5; // w25
  unsigned int v6; // w22
  __int64 v7; // x26
  char is_enabled; // w23
  unsigned int v9; // w24
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x1
  _QWORD *v12; // x23
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x8
  void (__fastcall *v15)(_QWORD); // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 v18; // x8
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_DWORD *)(StatusReg + 152) - 120;
  if ( a2 && adreno_wake_nice < v5 )
    set_user_nice(StatusReg, adreno_wake_nice);
  v6 = *(_DWORD *)(a1 + 11120);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  if ( (*(_QWORD *)(a1 + 14240) & 0x20) != 0 )
    __break(0x800u);
  if ( (gmu_core_gpmu_isenabled(a1) & 1) == 0 )
  {
    if ( *(_QWORD *)(a1 + 9000) || *(_QWORD *)(a1 + 9008) )
    {
      is_enabled = (unsigned int)regulator_is_enabled() != 0;
      goto LABEL_11;
    }
    if ( *(_QWORD *)(a1 + 9024) || *(_QWORD *)(a1 + 9032) )
    {
      is_enabled = kgsl_genpd_is_enabled();
      goto LABEL_11;
    }
  }
  is_enabled = 0;
LABEL_11:
  *(_DWORD *)(a1 + 24448) = 0;
  __dmb(0xAu);
  v9 = kgsl_pwrctrl_change_state(a1, 32);
  if ( v9 )
    goto LABEL_33;
  adreno_set_active_ctxs_null(a1);
  _X8 = (unsigned __int64 *)(a1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 1, _X8) );
  *(_QWORD *)(a1 + 20376) = 0;
  *(_QWORD *)(a1 + 20368) = 0;
  *(_QWORD *)(a1 + 20360) = 0;
  *(_QWORD *)(a1 + 20352) = 0;
  *(_QWORD *)(a1 + 20344) = 0;
  *(_QWORD *)(a1 + 20336) = 0;
  *(_DWORD *)(a1 + 20384) = 0;
  if ( (is_enabled & 1) != 0 )
    soft_reset(a1);
  v10 = *(__int64 (__fastcall **)(_QWORD))(v7 + 56);
  if ( *((_DWORD *)v10 - 1) != -83892780 )
    __break(0x8228u);
  v9 = v10(a1);
  if ( v9 )
    goto LABEL_33;
  adreno_coresight_start(a1);
  v11 = *(unsigned int *)(a1 + 20888);
  if ( (_DWORD)v11 )
  {
    v12 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 40LL);
    if ( *(_DWORD *)(*v12 + 64LL) <= 0xFFFFFFFD )
      kgsl_regmap_write(a1 + 13200, v11);
    v13 = (void (__fastcall *)(__int64, __int64))v12[32];
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != 1163613936 )
        __break(0x8228u);
      v13(a1, 1);
    }
  }
  adreno_perfcounter_start(a1);
  v14 = *(_QWORD *)(a1 + 88);
  if ( v14 )
  {
    v15 = *(void (__fastcall **)(_QWORD))(v14 + 40);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != -919125270 )
        __break(0x8228u);
      v15(a1 + 56);
    }
  }
  v16 = *(__int64 (__fastcall **)(_QWORD))(v7 + 48);
  if ( *((_DWORD *)v16 - 1) != -83892780 )
    __break(0x8228u);
  v9 = v16(a1);
  if ( v9 )
  {
LABEL_33:
    kgsl_pwrctrl_change_state(a1, v6);
    if ( a2 )
LABEL_34:
      set_user_nice(StatusReg, v5);
  }
  else
  {
    v18 = *(_QWORD *)(a1 + 11240);
    if ( v18 )
      *(_BYTE *)(v18 + 245) = 1;
    adreno_dispatcher_start(a1);
    ++*(_DWORD *)(a1 + 12968);
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 | 0x20, _X8) );
    v9 = 0;
    *(_BYTE *)(a1 + 12960) = 1;
    if ( a2 )
      goto LABEL_34;
  }
  return v9;
}
