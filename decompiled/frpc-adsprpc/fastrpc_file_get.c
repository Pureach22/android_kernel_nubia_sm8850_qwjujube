__int64 __fastcall fastrpc_file_get(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v3; // w19
  unsigned int v9; // w9

  v1 = *(_DWORD *)(a1 + 664);
  _X0 = (unsigned int *)(a1 + 664);
  if ( v1 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v9 = __ldxr(_X0);
      while ( v9 == v1 && __stxr(v1 + 1, _X0) );
      v3 = v1;
      if ( v9 == v1 )
        break;
      v3 = 0;
      v1 = v9;
    }
    while ( v9 );
  }
  else
  {
    v3 = 0;
  }
  if ( (((v3 + 1) | v3) & 0x80000000) != 0 )
    refcount_warn_saturate();
  if ( v3 )
    return 0;
  else
    return 4294967294LL;
}
