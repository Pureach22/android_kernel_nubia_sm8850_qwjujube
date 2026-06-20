__int64 __fastcall kgsl_pwrctrl_pwrrail(_QWORD *a1, char a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  _DWORD *v9; // x8
  __int64 v10; // x8
  _DWORD *v11; // x8
  unsigned int v12; // w20
  unsigned __int64 v19; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v25; // x10

  if ( gmu_core_gpmu_isenabled((__int64)a1) || (a1[1142] & 1) != 0 || (a1[1142] & 2) != 0 )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    _X9 = a1 + 1141;
    __asm { PRFM            #0x11, [X9] }
    do
      v22 = __ldxr(_X9);
    while ( __stlxr(v22 & 0xFFFFFFFFFFFFFFFELL, _X9) );
    __dmb(0xBu);
    if ( (v22 & 1) != 0 )
    {
      v5 = a1[11];
      if ( v5 )
      {
        v6 = *(_DWORD **)(v5 + 104);
        if ( v6 )
        {
          if ( *(v6 - 1) != -1954538307 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64))v6)(a1 + 7, 1);
        }
      }
      kgsl_regulator_set_voltage(*a1, a1[1130], *((unsigned int *)a1 + 2262));
      kgsl_pwrctrl_disable_gx_gdsc(a1);
      kgsl_regulator_set_voltage(*a1, a1[1130], 0);
      v7 = a1[1125];
      if ( v7 || a1[1128] )
      {
        v8 = a1[11];
        if ( v8 )
        {
          v9 = *(_DWORD **)(v8 + 104);
          if ( v9 )
          {
            if ( *(v9 - 1) != -1954538307 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64))v9)(a1 + 7, 1);
            v7 = a1[1125];
          }
        }
        *((_DWORD *)a1 + 2270) = 0;
        *((_BYTE *)a1 + 9112) = 1;
        if ( v7 )
          regulator_disable(v7);
        else
          _pm_runtime_idle(a1[1128], 4);
      }
    }
    return 0;
  }
  _X9 = a1 + 1141;
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr(_X9);
  while ( __stlxr(v19 | 1, _X9) );
  __dmb(0xBu);
  if ( (v19 & 1) == 0
    && ((result = ((__int64 (__fastcall *)(_QWORD *))kgsl_pwrctrl_enable_cx_gdsc)(a1), (_DWORD)result)
     || (result = kgsl_regulator_set_voltage(*a1, a1[1130], *((unsigned int *)a1 + 2262)), (_DWORD)result)
     || (result = kgsl_pwrctrl_enable_gx_gdsc(a1), (_DWORD)result)) )
  {
    _X8 = a1 + 1141;
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    v10 = a1[11];
    if ( !v10 )
      return result;
  }
  else
  {
    result = 0;
    v10 = a1[11];
    if ( !v10 )
      return result;
  }
  v11 = *(_DWORD **)(v10 + 104);
  if ( v11 )
  {
    v12 = result;
    if ( *(v11 - 1) != -1954538307 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v11)(a1 + 7, 0);
    return v12;
  }
  return result;
}
