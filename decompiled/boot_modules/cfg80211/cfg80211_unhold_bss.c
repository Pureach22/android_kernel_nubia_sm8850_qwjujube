__int64 __fastcall cfg80211_unhold_bss(__int64 result)
{
  __int64 v1; // x8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8

  _X9 = (unsigned int *)(result + 80);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v8 = __ldxr(_X9);
    v9 = v8 - 1;
  }
  while ( __stlxr(v9, _X9) );
  __dmb(0xBu);
  if ( (v9 & 0x80000000) != 0 )
  {
    __break(0x800u);
    v1 = *(_QWORD *)(result + 152);
    if ( !v1 )
      return result;
  }
  else
  {
    v1 = *(_QWORD *)(result + 152);
    if ( !v1 )
      return result;
  }
  _X9 = (unsigned int *)(v1 - 32);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v12 = __ldxr(_X9);
    v13 = v12 - 1;
  }
  while ( __stlxr(v13, _X9) );
  __dmb(0xBu);
  if ( (v13 & 0x80000000) != 0 )
    __break(0x800u);
  return result;
}
