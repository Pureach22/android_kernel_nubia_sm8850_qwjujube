__int64 __fastcall kgsl_pwrctrl_axi(__int64 a1, char a2)
{
  int v2; // w1
  unsigned __int64 v10; // x8
  unsigned __int64 v13; // x8

  if ( (*(_QWORD *)(a1 + 9136) & 4) != 0 )
    return 0;
  if ( (a2 & 1) != 0 )
  {
    _X9 = (unsigned __int64 *)(a1 + 9128);
    __asm { PRFM            #0x11, [X9] }
    do
      v10 = __ldxr(_X9);
    while ( __stlxr(v10 | 4, _X9) );
    __dmb(0xBu);
    if ( (v10 & 4) != 0 )
      return 0;
    v2 = 1;
  }
  else
  {
    _X9 = (unsigned __int64 *)(a1 + 9128);
    __asm { PRFM            #0x11, [X9] }
    do
      v13 = __ldxr(_X9);
    while ( __stlxr(v13 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
    __dmb(0xBu);
    if ( (v13 & 4) == 0 )
      return 0;
    v2 = 0;
  }
  return kgsl_bus_update(a1, v2);
}
