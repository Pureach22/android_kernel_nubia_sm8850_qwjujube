__int64 __fastcall synx_util_acquire_handle(unsigned __int64 a1, int a2)
{
  __int64 v2; // x21
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v8; // x8
  unsigned int v15; // w9

  v2 = -22;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    raw_spin_lock_bh(a1 + 264920);
    v2 = -2;
    v5 = *(_QWORD *)(a1 + 8LL * ((unsigned int)(1640531527 * a2) >> 24) + 262872);
    v6 = v5 - 72;
    if ( v5 )
      _ZF = v5 == 72;
    else
      _ZF = 1;
    if ( !_ZF )
    {
      while ( *(_DWORD *)(v6 + 28) != a2 || !*(_DWORD *)(v6 + 32) )
      {
        v8 = *(_QWORD *)(v6 + 72);
        if ( v8 )
        {
          v6 = v8 - 72;
          if ( v6 )
            continue;
        }
        goto LABEL_15;
      }
      _X0 = (unsigned int *)(v6 + 24);
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr(_X0);
      while ( __stxr(v15 + 1, _X0) );
      if ( v15 )
      {
        v2 = v6;
        if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
          refcount_warn_saturate(_X0, 1);
      }
      else
      {
        v2 = v6;
        refcount_warn_saturate(_X0, 2);
      }
    }
LABEL_15:
    raw_spin_unlock_bh(a1 + 264920);
  }
  return v2;
}
