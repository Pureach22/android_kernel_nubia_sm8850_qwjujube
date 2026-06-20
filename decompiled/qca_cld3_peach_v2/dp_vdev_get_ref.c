__int64 __fastcall dp_vdev_get_ref(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w9
  unsigned int v9; // w11
  unsigned int v13; // w9

  _X8 = (unsigned int *)(a1 + 43384);
  v3 = *(_DWORD *)(a1 + 43384);
  do
  {
    if ( !v3 )
      return 4;
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v9 = __ldxr(_X8);
      if ( v9 != v3 )
        break;
      if ( !__stlxr(v3 + 1, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v9 == v3;
    v3 = v9;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(a1 + 4LL * a2 + 43388);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 + 1, _X8) );
  return 0;
}
