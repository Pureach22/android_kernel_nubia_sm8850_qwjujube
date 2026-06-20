__int64 __fastcall smp2p_set_irq_type(__int64 a1, char a2)
{
  __int64 v2; // x10
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x11
  __int64 v6; // x12
  __int64 v8; // x9
  __int64 v9; // x10
  unsigned __int64 v16; // x13
  unsigned __int64 v19; // x13
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9

  if ( (a2 & 3) == 0 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(a1 + 48);
  v4 = (unsigned int)v2 >> 6;
  v5 = 1LL << v2;
  v6 = v3 + 72;
  if ( (a2 & 1) != 0 )
  {
    _X12 = (unsigned __int64 *)(v6 + 8 * v4);
    __asm { PRFM            #0x11, [X12] }
    do
      v19 = __ldxr(_X12);
    while ( __stxr(v19 | v5, _X12) );
  }
  else
  {
    _X12 = (unsigned __int64 *)(v6 + 8 * v4);
    __asm { PRFM            #0x11, [X12] }
    do
      v16 = __ldxr(_X12);
    while ( __stxr(v16 & ~v5, _X12) );
  }
  v8 = v3 + 80;
  v9 = 1LL << v2;
  if ( (a2 & 2) != 0 )
  {
    _X8 = (unsigned __int64 *)(v8 + 8 * v4);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 | v9, _X8) );
    return 0;
  }
  else
  {
    _X8 = (unsigned __int64 *)(v8 + 8 * v4);
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 & ~v9, _X8) );
    return 0;
  }
}
