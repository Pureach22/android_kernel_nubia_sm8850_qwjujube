__int64 __fastcall kgsl_pwrctrl_adjust_pwrlevel(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  unsigned int v4; // w22
  __int64 v5; // x0
  unsigned int v7; // w25
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w11
  unsigned int v16; // w8
  __int64 result; // x0
  int v18; // w9
  unsigned int v19; // w9
  __int64 v20; // x20
  int v22; // w8
  int v24; // w8

  if ( !*(_DWORD *)(a1 + 10416) || (__int64)(*(_QWORD *)(a1 + 10424) - jiffies) >= 0 )
    goto LABEL_21;
  v3 = *(unsigned int *)(a1 + 10432);
  v4 = a2;
  raw_read_lock(a1 + 11208);
  v5 = idr_find(a1 + 11184, v3);
  if ( !v5 || (_X21 = (unsigned int *)v5, (*(_QWORD *)(v5 + 32) & 2) != 0) )
  {
    raw_read_unlock(a1 + 11208);
LABEL_19:
    *(_QWORD *)(a1 + 10424) = 0;
    *(_DWORD *)(a1 + 10416) = 0;
    goto LABEL_20;
  }
  v7 = *(_DWORD *)v5;
  if ( *(_DWORD *)v5 )
  {
    do
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v13 = __ldxr((unsigned int *)v5);
      while ( v13 == v7 && __stxr(v7 + 1, (unsigned int *)v5) );
      if ( v13 == v7 )
        break;
      v7 = v13;
    }
    while ( v13 );
  }
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
    refcount_warn_saturate(v5, 0);
  raw_read_unlock(a1 + 11208);
  if ( !v7 )
    goto LABEL_19;
  if ( kgsl_check_timestamp(a1, (__int64)_X21, *(_DWORD *)(a1 + 10436)) )
  {
    __asm { PRFM            #0x11, [X21] }
    do
      v22 = __ldxr(_X21);
    while ( __stlxr(v22 - 1, _X21) );
    if ( v22 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X21);
    }
    else if ( v22 <= 0 )
    {
      refcount_warn_saturate(_X21, 3);
    }
    goto LABEL_19;
  }
  v20 = jiffies;
  *(_QWORD *)(a1 + 10424) = _msecs_to_jiffies(*(_QWORD *)(a1 + 10080)) + v20;
  __asm { PRFM            #0x11, [X21] }
  do
    v24 = __ldxr(_X21);
  while ( __stlxr(v24 - 1, _X21) );
  if ( v24 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy((__int64)_X21);
  }
  else
  {
    a2 = v4;
    if ( v24 > 0 )
      goto LABEL_21;
    refcount_warn_saturate(_X21, 3);
  }
LABEL_20:
  a2 = v4;
LABEL_21:
  v14 = *(_DWORD *)(a1 + 10552);
  v15 = *(_DWORD *)(a1 + 10060);
  if ( *(_DWORD *)(a1 + 10048) > v14 )
    v14 = *(_DWORD *)(a1 + 10048);
  if ( *(_DWORD *)(a1 + 10056) <= v14 )
    v16 = v14;
  else
    v16 = *(_DWORD *)(a1 + 10056);
  if ( v15 <= v14 )
    result = v14;
  else
    result = v15;
  if ( *(_DWORD *)(a1 + 10416) != 1 )
    goto LABEL_32;
  v18 = *(_DWORD *)(a1 + 10420);
  if ( v18 == 1 )
    return v16;
  if ( v18 )
  {
LABEL_32:
    if ( (unsigned int)result >= a2 )
      v19 = a2;
    else
      v19 = result;
    if ( v16 <= a2 )
      return v19;
    else
      return v16;
  }
  return result;
}
