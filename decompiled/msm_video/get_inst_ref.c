__int64 *__fastcall get_inst_ref(__int64 a1, __int64 *a2)
{
  __int64 *v4; // x21
  unsigned int v5; // w8
  unsigned int v7; // w20
  unsigned int v13; // w9
  __int64 *v14; // x20

  mutex_lock(a1 + 3856);
  v4 = (__int64 *)(a1 + 3528);
  do
  {
    v4 = (__int64 *)*v4;
    if ( v4 == (__int64 *)(a1 + 3528) )
    {
      v14 = nullptr;
      goto LABEL_19;
    }
  }
  while ( v4 != a2 );
  v5 = *((_DWORD *)v4 + 82);
  _X0 = (unsigned int *)(v4 + 41);
  if ( v5 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( v13 == v5 && __stxr(v5 + 1, _X0) );
      v7 = v5;
      if ( v13 == v5 )
        break;
      v7 = 0;
      v5 = v13;
    }
    while ( v13 );
  }
  else
  {
    v7 = 0;
  }
  if ( (((v7 + 1) | v7) & 0x80000000) != 0 )
    refcount_warn_saturate();
  if ( v7 )
    v14 = v4;
  else
    v14 = nullptr;
LABEL_19:
  mutex_unlock(a1 + 3856);
  return v14;
}
