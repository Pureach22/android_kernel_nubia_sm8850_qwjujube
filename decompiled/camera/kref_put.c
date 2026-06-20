__int64 __fastcall kref_put(unsigned int *_X0, void (*a2)(void))
{
  int v8; // w8

  __asm { PRFM            #0x11, [X0] }
  do
    v8 = __ldxr(_X0);
  while ( __stlxr(v8 - 1, _X0) );
  if ( v8 == 1 )
  {
    __dmb(9u);
    if ( *((_DWORD *)a2 - 1) != -2006492174 )
      __break(0x8221u);
    a2();
    return 1;
  }
  else
  {
    if ( v8 <= 0 )
      refcount_warn_saturate();
    return 0;
  }
}
