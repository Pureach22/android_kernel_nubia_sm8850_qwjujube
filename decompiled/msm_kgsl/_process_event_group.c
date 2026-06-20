__int64 __fastcall process_event_group(__int64 result, __int64 a2, char a3)
{
  __int64 v6; // x22
  unsigned int v7; // w8
  unsigned int v8; // w23
  unsigned int v13; // w9
  __int64 v14; // x1
  void (__fastcall *v15)(__int64, __int64, __int64, unsigned int *); // x8
  __int64 *v16; // x9
  int v17; // w8
  unsigned int v18; // w8
  __int64 *v19; // x26
  __int64 **v20; // x10
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v25; // w8
  int v27; // w8
  unsigned int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_51;
  _X19 = *(unsigned int **)a2;
  v6 = result;
  v28 = 0;
  if ( _X19 )
  {
    v7 = *_X19;
    if ( *_X19 )
    {
      do
      {
        __asm { PRFM            #0x11, [X19] }
        do
          v13 = __ldxr(_X19);
        while ( v13 == v7 && __stxr(v7 + 1, _X19) );
        v8 = v7;
        if ( v13 == v7 )
          break;
        v8 = 0;
        v7 = v13;
      }
      while ( v13 );
    }
    else
    {
      v8 = 0;
    }
    if ( (((v8 + 1) | v8) & 0x80000000) == 0 )
    {
      if ( v8 )
        goto LABEL_14;
LABEL_46:
      __break(0x800u);
      goto LABEL_51;
    }
    result = refcount_warn_saturate(_X19, 0);
    if ( !v8 )
      goto LABEL_46;
  }
LABEL_14:
  raw_spin_lock(a2 + 8);
  v15 = *(void (__fastcall **)(__int64, __int64, __int64, unsigned int *))(a2 + 120);
  v14 = *(_QWORD *)(a2 + 128);
  if ( *((_DWORD *)v15 - 1) != -362688460 )
    __break(0x8228u);
  v15(v6, v14, 2, &v28);
  if ( (a3 & 1) == 0 )
  {
    v23 = *(_DWORD *)(a2 + 48);
    _CF = v23 >= v28;
    v25 = v23 - v28;
    if ( !v25 || v25 != 0 && _CF && (v25 & 0x80000000) == 0 )
      goto LABEL_42;
  }
  v16 = *(__int64 **)(a2 + 16);
  if ( v16 != (__int64 *)(a2 + 16) )
  {
    do
    {
      v18 = *((_DWORD *)v16 - 6);
      v19 = (__int64 *)*v16;
      if ( v18 == v28
        || (v18 <= v28 || ((v18 - v28) & 0x80000000) != 0)
        && ((v21 = v18 ^ 0x80000000, _CF = v21 >= (v28 ^ 0x80000000), v22 = v21 - (v28 ^ 0x80000000), v22 == 0 || !_CF)
         || v22 >= 0x80000001) )
      {
        v20 = (__int64 **)v16[1];
        if ( *v20 != v16 || (__int64 *)v19[1] != v16 )
        {
          _list_del_entry_valid_or_report(v16);
          v17 = 1;
          goto LABEL_21;
        }
        v19[1] = (__int64)v20;
        v17 = 1;
      }
      else
      {
        if ( (a3 & 1) == 0 )
          goto LABEL_22;
        v20 = (__int64 **)v16[1];
        if ( *v20 != v16 || (__int64 *)v19[1] != v16 )
        {
          _list_del_entry_valid_or_report(v16);
          v17 = 2;
          goto LABEL_21;
        }
        v17 = 2;
        v19[1] = (__int64)v20;
      }
      *v20 = v19;
LABEL_21:
      *((_DWORD *)v16 + 16) = v17;
      *v16 = 0xDEAD000000000100LL;
      v16[1] = 0xDEAD000000000122LL;
      kthread_queue_work(*(_QWORD *)(v6 + 12976), v16 + 3);
LABEL_22:
      v16 = v19;
    }
    while ( v19 != (__int64 *)(a2 + 16) );
  }
  *(_DWORD *)(a2 + 48) = v28;
LABEL_42:
  result = raw_spin_unlock(a2 + 8);
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v27 = __ldxr(_X19);
    while ( __stlxr(v27 - 1, _X19) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      result = kgsl_context_destroy((__int64)_X19);
    }
    else if ( v27 <= 0 )
    {
      result = refcount_warn_saturate(_X19, 3);
    }
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
