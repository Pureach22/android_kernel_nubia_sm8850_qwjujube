__int64 __fastcall pm_runtime_put_noidle(__int64 result)
{
  unsigned int v1; // w8
  unsigned int v8; // w10

  v1 = *(_DWORD *)(result + 480);
  do
  {
    if ( !v1 )
      break;
    _X12 = (unsigned int *)(result + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v8 = __ldxr(_X12);
      if ( v8 != v1 )
        break;
      if ( !__stlxr(v1 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v8 == v1;
    v1 = v8;
  }
  while ( !_ZF );
  return result;
}
