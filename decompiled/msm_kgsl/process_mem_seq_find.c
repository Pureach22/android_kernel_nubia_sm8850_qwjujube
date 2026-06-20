unsigned int *__fastcall process_mem_seq_find(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v5; // x22
  __int64 v7; // x23
  unsigned int v8; // w8
  unsigned int v9; // w24
  unsigned int v15; // w9
  unsigned int *v16; // x21
  unsigned int *v17; // x20
  int v19; // w8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  _X19 = a2;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 128);
  v21 = 0;
  if ( a2 != &dword_1 )
    v21 = a2[62] + 1;
  raw_spin_lock(v5 + 32);
  _X0 = (unsigned int *)idr_get_next(v5 + 40, &v21);
  if ( _X0 )
  {
    v7 = 1;
    do
    {
      if ( (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL && v7 == a3 )
      {
        v8 = *_X0;
        if ( *_X0 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v15 = __ldxr(_X0);
            while ( v15 == v8 && __stxr(v8 + 1, _X0) );
            v9 = v8;
            if ( v15 == v8 )
              break;
            v9 = 0;
            v8 = v15;
          }
          while ( v15 );
        }
        else
        {
          v9 = 0;
        }
        if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
        {
          v16 = _X0;
          refcount_warn_saturate(_X0, 0);
          _X0 = v16;
          if ( v9 )
            break;
        }
        else if ( v9 )
        {
          break;
        }
      }
      ++v21;
      _X0 = (unsigned int *)idr_get_next(v5 + 40, &v21);
      ++v7;
    }
    while ( _X0 );
  }
  v17 = _X0;
  raw_spin_unlock(v5 + 32);
  if ( (unsigned __int64)_X19 >= 2 && (unsigned __int64)_X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v19 = __ldxr(_X19);
    while ( __stlxr(v19 - 1, _X19) );
    if ( v19 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy(_X19);
    }
    else if ( v19 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
