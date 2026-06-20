__int64 __fastcall bind_range_create(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w20
  unsigned int v14; // w9
  __int64 v16; // x21
  unsigned int v18; // w9

  _X19 = a3;
  result = _kmalloc_cache_noprof(raw_read_unlock, 3520, 56);
  if ( !result )
    return -12;
  *(_QWORD *)(result + 32) = a1;
  *(_QWORD *)(result + 40) = a2;
  if ( !_X19 || (unsigned __int64)_X19 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_17;
  v7 = *_X19;
  if ( *_X19 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v14 = __ldxr(_X19);
      while ( v14 == v7 && __stxr(v7 + 1, _X19) );
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
      goto LABEL_15;
LABEL_17:
    *(_QWORD *)result = 0;
    kfree(result);
    return -22;
  }
  v16 = result;
  refcount_warn_saturate(_X19, 0);
  result = v16;
  if ( !v8 )
    goto LABEL_17;
LABEL_15:
  _X8 = _X19 + 93;
  *(_QWORD *)result = _X19;
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 + 1, _X8) );
  return result;
}
