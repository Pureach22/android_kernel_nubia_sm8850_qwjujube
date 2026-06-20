unsigned __int64 __fastcall kgsl_sharedmem_find(unsigned __int64 result, unsigned __int64 a2)
{
  unsigned __int64 v2; // x19
  char v4; // w8
  unsigned __int64 v6; // x8
  unsigned int v7; // w8
  unsigned int v8; // w9
  unsigned int v14; // w10
  unsigned __int64 v15; // x20
  unsigned __int64 v16; // x20
  unsigned int v17; // [xsp+0h] [xbp-10h]
  int i; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v2 = result;
    if ( (kgsl_mmu_gpuaddr_in_range(*(_QWORD *)(result + 64), a2, 0) & 1) != 0
      || (v4 = kgsl_mmu_gpuaddr_in_range(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 64) + 112LL) + 24LL), a2, 0),
          result = 0,
          (v4 & 1) != 0) )
    {
      raw_spin_lock(v2 + 32);
      for ( i = 0; ; ++i )
      {
        _X0 = idr_get_next(v2 + 40, &i);
        if ( !_X0 )
          goto LABEL_23;
        v6 = *(_QWORD *)(_X0 + 32);
        if ( v6 <= a2 && *(_QWORD *)(_X0 + 48) + v6 > a2 )
          break;
      }
      if ( *(_DWORD *)(_X0 + 264) || _X0 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_22;
      v7 = *(_DWORD *)_X0;
      if ( *(_DWORD *)_X0 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v14 = __ldxr((unsigned int *)_X0);
          while ( v14 == v7 && __stxr(v7 + 1, (unsigned int *)_X0) );
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
      if ( (((v8 + 1) | v8) & 0x80000000) == 0 )
      {
        if ( v8 )
          goto LABEL_23;
        goto LABEL_22;
      }
      v16 = _X0;
      v17 = v8;
      refcount_warn_saturate(_X0, 0);
      _X0 = v16;
      if ( !v17 )
LABEL_22:
        _X0 = 0;
LABEL_23:
      v15 = _X0;
      raw_spin_unlock(v2 + 32);
      result = v15;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
