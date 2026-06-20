__int64 __fastcall adreno_open(_QWORD *a1)
{
  __int64 v2; // x20
  unsigned int v3; // w0
  __int64 (__fastcall *v4)(_QWORD); // x8
  unsigned int v5; // w20
  unsigned int v13; // w9
  unsigned int v16; // w10
  unsigned __int64 v19; // x9

  _X8 = (unsigned int *)(a1 + 1391);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 + 1, _X8) );
  memset(*(void **)(a1[5] + 8LL), 0, *(_QWORD *)(a1[5] + 40LL));
  v2 = *(_QWORD *)(a1[1783] + 40LL);
  v3 = kgsl_pwrctrl_change_state(a1, 1);
  if ( !v3 )
  {
    if ( (a1[1780] & 4) == 0 )
    {
      v4 = *(__int64 (__fastcall **)(_QWORD))(v2 + 32);
      if ( *((_DWORD *)v4 - 1) != -83892780 )
        __break(0x8228u);
      v3 = v4(a1);
      if ( v3 )
        goto LABEL_9;
      _X8 = a1 + 1780;
      __asm { PRFM            #0x11, [X8] }
      do
        v19 = __ldxr(_X8);
      while ( __stxr(v19 | 4, _X8) );
    }
    v3 = adreno_start((__int64)a1, 0);
    if ( !v3 )
    {
      complete_all(a1 + 1086);
      kgsl_pwrctrl_change_state(a1, 2);
      adreno_active_count_put((__int64)a1);
      return 0;
    }
  }
LABEL_9:
  v5 = v3;
  kgsl_pwrctrl_change_state(a1, 1);
  _X8 = (unsigned int *)(a1 + 1391);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 - 1, _X8) );
  return v5;
}
