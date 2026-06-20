__int64 __fastcall adreno_reset(__int64 a1, char a2)
{
  _QWORD *v3; // x20
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  unsigned int (*v6)(void); // x8
  bool v7; // w8
  int v8; // w2
  _QWORD *v9; // x22
  _DWORD *v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x1
  _QWORD *v13; // x21
  void (__fastcall *v14)(__int64, __int64); // x8
  __int64 (__fastcall *v15)(_QWORD); // x8
  int v16; // w0
  int v17; // w20
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x10
  unsigned __int64 v30; // x10
  unsigned __int64 v33; // x10
  unsigned __int64 v36; // x9

  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 40LL);
  if ( !v3[17] )
  {
    if ( (a2 & 8) == 0 )
    {
      v6 = (unsigned int (*)(void))v3[21];
      if ( !v6 )
        goto LABEL_17;
      if ( *((_DWORD *)v6 - 1) != -83892780 )
        __break(0x8228u);
      if ( !v6() )
      {
LABEL_17:
        kgsl_pwrctrl_change_state(a1, 32);
        adreno_set_active_ctxs_null(a1);
        if ( *(_DWORD *)(a1 + 20888) )
        {
          v9 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 40LL);
          if ( *(_DWORD *)(*v9 + 64LL) <= 0xFFFFFFFD )
            kgsl_regmap_write(a1 + 13200, 0);
          v10 = (_DWORD *)v9[32];
          if ( v10 )
          {
            if ( *(v10 - 1) != 1163613936 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD))v10)(a1, 0);
          }
        }
        *(_DWORD *)(a1 + 24448) = 0;
        __dmb(0xAu);
        _X8 = (unsigned __int64 *)(a1 + 14240);
        __asm { PRFM            #0x11, [X8] }
        do
          v33 = __ldxr(_X8);
        while ( __stxr(v33 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
        adreno_perfcounter_save(a1);
        soft_reset(a1);
        *(_QWORD *)(a1 + 20352) = 0;
        *(_QWORD *)(a1 + 20344) = 0;
        *(_DWORD *)(a1 + 20360) = 0;
        *(_QWORD *)(a1 + 20336) = 0;
        v11 = (void (__fastcall *)(_QWORD))v3[7];
        if ( *((_DWORD *)v11 - 1) != -83892780 )
          __break(0x8228u);
        v11(a1);
        adreno_coresight_start(a1);
        v12 = *(unsigned int *)(a1 + 20888);
        if ( (_DWORD)v12 )
        {
          v13 = *(_QWORD **)(*(_QWORD *)(a1 + 14264) + 40LL);
          if ( *(_DWORD *)(*v13 + 64LL) <= 0xFFFFFFFD )
            kgsl_regmap_write(a1 + 13200, v12);
          v14 = (void (__fastcall *)(__int64, __int64))v13[32];
          if ( v14 )
          {
            if ( *((_DWORD *)v14 - 1) != 1163613936 )
              __break(0x8228u);
            v14(a1, 1);
          }
        }
        adreno_ringbuffer_stop(a1);
        v15 = (__int64 (__fastcall *)(_QWORD))v3[6];
        if ( *((_DWORD *)v15 - 1) != -83892780 )
          __break(0x8228u);
        v16 = v15(a1);
        if ( !v16 )
        {
          ++*(_DWORD *)(a1 + 12968);
          _X8 = (unsigned __int64 *)(a1 + 14240);
          __asm { PRFM            #0x11, [X8] }
          do
            v36 = __ldxr(_X8);
          while ( __stxr(v36 | 0x20, _X8) );
          adreno_perfcounter_restore(a1);
          goto LABEL_38;
        }
        v17 = v16;
        adreno_perfcounter_restore(a1);
        dev_err(*(_QWORD *)a1, "Device soft reset failed: %d\n", v17);
      }
    }
    kgsl_pwrctrl_change_state(a1, 1);
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
    if ( (unsigned int)adreno_start(a1, 0) )
    {
      msleep(20);
      result = adreno_start(a1, 0);
      v7 = (_DWORD)result != 0;
      if ( (_DWORD)result )
      {
        msleep(20);
        result = adreno_start(a1, 0);
        v7 = (_DWORD)result != 0;
        if ( (_DWORD)result )
        {
          msleep(20);
          result = adreno_start(a1, 0);
          v7 = (_DWORD)result != 0;
          if ( (_DWORD)result )
          {
            msleep(20);
            result = adreno_start(a1, 0);
            v8 = 4;
            v7 = (_DWORD)result != 0;
          }
          else
          {
            v8 = 3;
          }
        }
        else
        {
          v8 = 2;
        }
      }
      else
      {
        v8 = 1;
      }
      if ( v7 )
        return result;
      dev_warn(*(_QWORD *)a1, "Device hard reset tried %d tries\n", v8);
      if ( !*(_DWORD *)(a1 + 11128) )
        return 0;
LABEL_39:
      kgsl_pwrctrl_change_state(a1, 2);
      return 0;
    }
LABEL_38:
    if ( !*(_DWORD *)(a1 + 11128) )
      return 0;
    goto LABEL_39;
  }
  _X8 = (unsigned __int64 *)(a1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 | 0x40000, _X8) );
  v4 = (__int64 (*)(void))v3[17];
  if ( *((_DWORD *)v4 - 1) != -83892780 )
    __break(0x8228u);
  result = v4();
  _X8 = (unsigned __int64 *)(a1 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr(_X8);
  while ( __stxr(v27 & 0xFFFFFFFFFFFBFFFFLL, _X8) );
  return result;
}
