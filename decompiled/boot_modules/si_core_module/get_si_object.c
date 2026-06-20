bool __fastcall get_si_object(unsigned __int64 a1)
{
  unsigned int v3; // w8
  unsigned int v4; // t1
  unsigned int v5; // w19
  unsigned int v11; // w9

  if ( a1 < 2 )
    return 0;
  v4 = *(_DWORD *)(a1 + 8);
  _X0 = (unsigned int *)(a1 + 8);
  v3 = v4;
  if ( v4 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v11 = __ldxr(_X0);
      while ( v11 == v3 && __stxr(v3 + 1, _X0) );
      v5 = v3;
      if ( v11 == v3 )
        break;
      v5 = 0;
      v3 = v11;
    }
    while ( v11 );
  }
  else
  {
    v5 = 0;
  }
  if ( (((v5 + 1) | v5) & 0x80000000) != 0 )
    refcount_warn_saturate();
  return v5 != 0;
}
