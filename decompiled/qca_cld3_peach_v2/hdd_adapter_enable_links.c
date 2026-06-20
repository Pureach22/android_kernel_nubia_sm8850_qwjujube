__int64 __fastcall hdd_adapter_enable_links(__int64 result, _WORD *a2)
{
  unsigned __int64 v8; // x9
  unsigned __int64 v11; // x9

  if ( (*a2 & 0x1C0) != 0 )
  {
    _X8 = (unsigned __int64 *)(result + 1640);
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr(_X8);
    while ( __stxr(v8 | 1, _X8) );
    _X8 = (unsigned __int64 *)(result + 1640);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 | 2, _X8) );
    *(_BYTE *)(result + 1648) = 2;
  }
  else
  {
    *(_BYTE *)(result + 1648) = 1;
  }
  return result;
}
