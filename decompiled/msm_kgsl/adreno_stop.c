__int64 __fastcall adreno_stop(_QWORD *a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x20
  _QWORD *v4; // x22
  _DWORD *v5; // x8
  void (__fastcall *v6)(_QWORD); // x8
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v17; // x10

  v1 = *(_QWORD *)(a1[1783] + 40LL);
  if ( (a1[1780] & 0x20) != 0 )
  {
    v3 = a1 + 2560;
    kgsl_pwrscale_update_stats(a1);
    if ( *((_DWORD *)v3 + 102) )
    {
      v4 = *(_QWORD **)(a1[1783] + 40LL);
      if ( *(_DWORD *)(*v4 + 64LL) <= 0xFFFFFFFD )
        kgsl_regmap_write(a1 + 1650, 0);
      v5 = (_DWORD *)v4[32];
      if ( v5 )
      {
        if ( *(v5 - 1) != 1163613936 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD))v5)(a1, 0);
      }
    }
    adreno_coresight_stop(a1);
    adreno_perfcounter_save(a1);
    v6 = *(void (__fastcall **)(_QWORD))(v1 + 168);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != -83892780 )
        __break(0x8228u);
      v6(a1);
    }
    adreno_dispatcher_stop(a1);
    adreno_ringbuffer_stop(a1);
    if ( *((_BYTE *)v3 + 352) == 1 )
    {
      v7 = a1[2603];
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *((_BYTE *)v3 + 368) == 1 )
    {
      v8 = a1[2605];
      if ( v8 )
      {
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *((_BYTE *)v3 + 384) == 1 )
    {
      v9 = a1[2607];
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    adreno_set_active_ctxs_null((__int64)a1);
    _X8 = a1 + 1780;
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
  }
  return 0;
}
