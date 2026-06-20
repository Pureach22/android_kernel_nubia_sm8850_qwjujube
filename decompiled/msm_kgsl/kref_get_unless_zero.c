bool __fastcall kref_get_unless_zero(unsigned int *_X0)
{
  unsigned int v1; // w8
  unsigned int v2; // w19
  unsigned int v8; // w9

  v1 = *_X0;
  if ( *_X0 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v8 = __ldxr(_X0);
      while ( v8 == v1 && __stxr(v1 + 1, _X0) );
      v2 = v1;
      if ( v8 == v1 )
        break;
      v2 = 0;
      v1 = v8;
    }
    while ( v8 );
  }
  else
  {
    v2 = 0;
  }
  if ( (((v2 + 1) | v2) & 0x80000000) != 0 )
    refcount_warn_saturate(_X0, 0);
  return v2 != 0;
}
