__int64 __fastcall kgsl_sync_timeline_value_str(__int64 result, char *a2, int a3)
{
  unsigned int v6; // w8
  unsigned int v7; // w22
  unsigned int v13; // w9
  __int64 v14; // x0
  __int64 v16; // x1
  unsigned int v17; // w9
  unsigned int v18; // w22
  unsigned int v20; // w10
  int v23; // w8
  int v25; // w8
  __int64 v26; // [xsp+8h] [xbp-18h]
  int v27; // [xsp+10h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  _X19 = *(_QWORD *)(result + 72);
  v6 = *(_DWORD *)_X19;
  if ( *(_DWORD *)_X19 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v13 = __ldxr((unsigned int *)_X19);
      while ( v13 == v6 && __stxr(v6 + 1, (unsigned int *)_X19) );
      v7 = v6;
      if ( v13 == v6 )
        break;
      v7 = 0;
      v6 = v13;
    }
    while ( v13 );
  }
  else
  {
    v7 = 0;
  }
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
  {
    result = refcount_warn_saturate(_X19, 0);
    if ( !v7 )
      goto LABEL_45;
  }
  else if ( !v7 )
  {
    goto LABEL_45;
  }
  if ( *(_QWORD *)(_X19 + 72) )
  {
    v14 = raw_spin_lock_irqsave(_X19 + 64);
    _X8 = *(unsigned int **)(_X19 + 80);
    v16 = v14;
    if ( _X8 )
    {
      v17 = *_X8;
      if ( *_X8 )
      {
        do
        {
          __asm { PRFM            #0x11, [X8] }
          do
            v20 = __ldxr(_X8);
          while ( v20 == v17 && __stxr(v17 + 1, _X8) );
          v18 = v17;
          if ( v20 == v17 )
            break;
          v18 = 0;
          v17 = v20;
        }
        while ( v20 );
      }
      else
      {
        v18 = 0;
      }
      if ( (((v18 + 1) | v18) & 0x80000000) != 0 )
      {
        v26 = v14;
        refcount_warn_saturate(_X8, 0);
        v16 = v26;
        if ( v18 )
          goto LABEL_25;
      }
      else if ( v18 )
      {
LABEL_25:
        _X22 = *(unsigned int **)(_X19 + 80);
LABEL_30:
        raw_spin_unlock_irqrestore(_X19 + 64, v16);
        v27 = *(_DWORD *)(_X19 + 68);
        if ( _X22 )
        {
          kgsl_readtimestamp(*(_QWORD *)(_X19 + 72));
          kgsl_readtimestamp(*(_QWORD *)(_X19 + 72));
          __asm { PRFM            #0x11, [X22] }
          do
            v23 = __ldxr(_X22);
          while ( __stlxr(v23 - 1, _X22) );
          if ( v23 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy((__int64)_X22);
          }
          else if ( v23 <= 0 )
          {
            refcount_warn_saturate(_X22, 3);
          }
        }
        result = snprintf(a2, a3, "%u queued:%u retired:%u", *(_DWORD *)(_X19 + 68), v27, v27);
        goto LABEL_38;
      }
    }
    _X22 = nullptr;
    goto LABEL_30;
  }
LABEL_38:
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v25 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v25 - 1, (unsigned int *)_X19) );
    if ( v25 == 1 )
    {
      __dmb(9u);
      result = kfree(_X19);
    }
    else if ( v25 <= 0 )
    {
      result = refcount_warn_saturate(_X19, 3);
    }
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
