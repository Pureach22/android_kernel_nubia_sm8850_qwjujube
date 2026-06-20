__int64 __fastcall gmu_core_mark_for_coldboot(__int64 result)
{
  unsigned __int64 v7; // x9

  if ( *(_BYTE *)(result + 8284) == 1 )
  {
    _X8 = (unsigned __int64 *)(result + 1528);
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr(_X8);
    while ( __stxr(v7 | 0x100, _X8) );
  }
  return result;
}
