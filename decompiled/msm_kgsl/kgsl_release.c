__int64 __fastcall kgsl_release(__int64 a1, __int64 a2)
{
  __int64 *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x22
  __int64 next; // x0
  unsigned int v7; // w8
  unsigned int v8; // w27
  unsigned int v14; // w9
  int v16; // w8
  unsigned int *v17; // x21
  int v18; // w8
  __int64 i; // x0
  unsigned int *v20; // x24
  int v23; // w8
  void (__fastcall *v24)(_QWORD); // x8
  int v25; // w8
  __int64 (__fastcall *v26)(_QWORD); // x8
  unsigned int v27; // w20
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a2 + 32);
  v29 = 0;
  v3 = *v2;
  *(_QWORD *)(a2 + 32) = 0;
  v4 = *v2;
  raw_read_lock(*v2 + 11208);
  next = idr_get_next(v4 + 11184, &v29);
  if ( next )
  {
    _X21 = next;
    do
    {
      if ( *(__int64 **)(_X21 + 16) == v2 )
      {
        v7 = *(_DWORD *)_X21;
        if ( *(_DWORD *)_X21 )
        {
          do
          {
            __asm { PRFM            #0x11, [X21] }
            do
              v14 = __ldxr((unsigned int *)_X21);
            while ( v14 == v7 && __stxr(v7 + 1, (unsigned int *)_X21) );
            v8 = v7;
            if ( v14 == v7 )
              break;
            v8 = 0;
            v7 = v14;
          }
          while ( v14 );
        }
        else
        {
          v8 = 0;
        }
        if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
          refcount_warn_saturate(_X21, 0);
        raw_read_unlock(v4 + 11208);
        if ( v8 )
        {
          kgsl_context_detach(_X21);
          __asm { PRFM            #0x11, [X21] }
          do
            v16 = __ldxr((unsigned int *)_X21);
          while ( __stlxr(v16 - 1, (unsigned int *)_X21) );
          if ( v16 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy(_X21);
          }
          else if ( v16 <= 0 )
          {
            refcount_warn_saturate(_X21, 3);
          }
        }
      }
      else
      {
        raw_read_unlock(v4 + 11208);
      }
      ++v29;
      raw_read_lock(v4 + 11208);
      _X21 = idr_get_next(v4 + 11184, &v29);
    }
    while ( _X21 );
  }
  raw_read_unlock(v4 + 11208);
  v17 = (unsigned int *)v2[1];
  mutex_lock(v17 + 150);
  v18 = v17[93] - 1;
  _ZF = v17[93] == 1;
  v17[93] = v18;
  if ( v18 < 0 || _ZF )
  {
    v29 = 0;
    raw_spin_lock(v17 + 8);
    for ( i = idr_get_next(v17 + 10, &v29); i; i = idr_get_next(v17 + 10, &v29) )
    {
      if ( *(_DWORD *)(i + 264) )
      {
        raw_spin_unlock(v17 + 8);
      }
      else
      {
        *(_DWORD *)(i + 264) = 1;
        v20 = (unsigned int *)i;
        raw_spin_unlock(v17 + 8);
        if ( (unsigned __int64)v20 <= 0xFFFFFFFFFFFFF000LL )
        {
          _X0 = v20;
          __asm { PRFM            #0x11, [X0] }
          do
            v23 = __ldxr(v20);
          while ( __stlxr(v23 - 1, v20) );
          if ( v23 == 1 )
          {
            __dmb(9u);
            kgsl_mem_entry_destroy(v20);
          }
          else if ( v23 <= 0 )
          {
            refcount_warn_saturate(v20, 3);
          }
        }
      }
      ++v29;
      raw_spin_lock(v17 + 8);
    }
    raw_spin_unlock(v17 + 8);
    kgsl_syncsource_process_release_syncsources(v17);
  }
  mutex_unlock(v17 + 150);
  kgsl_process_private_put(v17);
  v24 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 8752) + 112LL);
  if ( *((_DWORD *)v24 - 1) != -1048095058 )
    __break(0x8228u);
  v24(v2);
  mutex_lock(v3 + 14184);
  v25 = *(_DWORD *)(v3 + 11072);
  if ( v25 == 1 )
  {
    rt_mutex_lock(v3 + 11088);
    v26 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 8752) + 16LL);
    if ( *((_DWORD *)v26 - 1) != -1357770785 )
      __break(0x8228u);
    v27 = v26(v3);
    rt_mutex_unlock(v3 + 11088);
    v25 = *(_DWORD *)(v3 + 11072);
  }
  else
  {
    v27 = 0;
  }
  *(_DWORD *)(v3 + 11072) = v25 - 1;
  mutex_unlock(v3 + 14184);
  _pm_runtime_idle(*(_QWORD *)(v3 + 11168) + 16LL, 5);
  _ReadStatusReg(SP_EL0);
  return v27;
}
