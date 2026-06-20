bool __fastcall drawobj_sync_fence_func(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  unsigned __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x9
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x1
  __int64 v14; // x19
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x21
  int v24; // w9
  int v26; // w9
  void (*v27)(void); // x8

  v1 = a1[6];
  if ( v1 && *(int *)(v1 + 8) >= 1 )
  {
    v3 = 0;
    v4 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      log_kgsl_syncpoint_fence_expire_event(*(unsigned int *)(*(_QWORD *)(a1[1] + 8LL) + 4LL), *(_QWORD *)v1 + v3);
      ++v4;
      v3 += 74;
    }
    while ( v4 < *(int *)(v1 + 8) );
  }
  v5 = *(unsigned int *)a1;
  v6 = a1[1];
  v7 = a1[5];
  v8 = 1LL << v5;
  _X11 = (unsigned __int64 *)(v6 + 72 + 8 * (v5 >> 6));
  __asm { PRFM            #0x11, [X11] }
  do
    v21 = __ldxr(_X11);
  while ( __stlxr(v21 & ~v8, _X11) );
  __dmb(0xBu);
  v22 = v21 & v8;
  if ( (v21 & v8) != 0 )
  {
    v9 = a1[1];
    if ( !*(_DWORD *)(v9 + 72) )
    {
      timer_delete((timer_t)(v6 + 80));
      v10 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v7 + 8752) + 184LL);
      if ( v10 )
      {
        v11 = *(_QWORD *)(a1[1] + 8LL);
        if ( *((_DWORD *)v10 - 1) != 2043251089 )
          __break(0x8228u);
        v10(v7, v11);
      }
      v9 = a1[1];
    }
    if ( v9 )
    {
      _X8 = (unsigned int *)(v9 + 32);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stlxr(v24 - 1, _X8) );
      if ( v24 != 1 )
      {
        if ( v24 <= 0 )
          refcount_warn_saturate(v9 + 32, 3);
        return v22 != 0;
      }
      __dmb(9u);
      _X8 = *(unsigned int **)(v9 + 8);
      if ( !_X8 )
        goto LABEL_28;
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stlxr(v26 - 1, _X8) );
      if ( v26 == 1 )
      {
        __dmb(9u);
        v14 = v9;
        kgsl_context_destroy((__int64)_X8);
      }
      else
      {
        if ( v26 > 0 )
          goto LABEL_28;
        v14 = v9;
        refcount_warn_saturate(_X8, 3);
      }
      v9 = v14;
LABEL_28:
      v27 = *(void (**)(void))(v9 + 48);
      if ( *((_DWORD *)v27 - 1) != 287870130 )
        __break(0x8228u);
      v27();
    }
  }
  return v22 != 0;
}
