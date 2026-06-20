__int64 __fastcall adreno_drawctxt_invalidate(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x22
  __int64 v7; // x12
  char v8; // w15
  __int64 v9; // x13
  __int64 v10; // x23
  __int64 v11; // x21
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 result; // x0
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  _QWORD s[128]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v27; // [xsp+408h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  raw_spin_lock(a2 + 404);
  _X8 = (unsigned __int64 *)(a2 + 32);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 4, _X8) );
  if ( *(_QWORD *)(a2 + 2056) != a2 + 2056 )
  {
    _X8 = (unsigned __int64 *)(a2 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 | 0x20000, _X8) );
  }
  kgsl_sharedmem_writel(*(_QWORD *)(a1 + 40), 40LL * *(unsigned int *)(a2 + 4), *(unsigned int *)(a2 + 392));
  kgsl_sharedmem_writel(*(_QWORD *)(a1 + 40), 40LL * *(unsigned int *)(a2 + 4) + 8, *(unsigned int *)(a2 + 392));
  v4 = *(unsigned int *)(a2 + 1432);
  v5 = *(unsigned int *)(a2 + 1436);
  if ( v4 == v5 )
  {
    raw_spin_unlock(a2 + 404);
  }
  else
  {
    v6 = 0;
    do
    {
      if ( v4 >= 0x80 )
        goto LABEL_17;
      v7 = (int)v6;
      v8 = v4 + 1;
      v9 = *(_QWORD *)(a2 + 408 + 8 * v4);
      v4 = ((_BYTE)v4 + 1) & 0x7F;
      *(_DWORD *)(a2 + 1432) = v8 & 0x7F;
      if ( (unsigned __int64)(8LL * (int)v6) > 0x400 || (_DWORD)v6 == 128 )
      {
        __break(1u);
        goto LABEL_17;
      }
      ++v6;
      s[v7] = v9;
    }
    while ( v4 != v5 );
    raw_spin_unlock(a2 + 404);
    if ( (unsigned int)(v6 - 1) <= 0x7FFFFFFE )
    {
      v10 = 0;
      while ( v10 != 128 )
      {
        v11 = s[v10];
        kgsl_cancel_events_timestamp(a1, a2 + 64, *(unsigned int *)(v11 + 20));
        kgsl_drawobj_destroy(v11, v12, v13, v14);
        --v6;
        ++v10;
        if ( !v6 )
          goto LABEL_15;
      }
LABEL_17:
      __break(0x5512u);
    }
  }
LABEL_15:
  kgsl_flush_event_group(a1, a2 + 64);
  _wake_up(a2 + 1464, 3, 0, 0);
  _wake_up(a2 + 1440, 3, 0, 0);
  result = _wake_up(a2 + 1488, 3, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
