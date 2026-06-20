__int64 __fastcall ieee80211_xmit_fast_finish(__int64 a1, __int64 a2, unsigned __int8 a3, __int64 a4, _QWORD *a5)
{
  __int64 v5; // x23
  _WORD *v10; // x24
  __int64 result; // x0
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x8
  __int16 v15; // w8
  __int64 v16; // x8
  unsigned __int64 v23; // x11
  unsigned __int64 v26; // x9
  __int64 v27; // x9
  __int16 v28; // w10
  __int64 v29; // x10
  unsigned int v30; // w9
  __int64 v31; // x9
  unsigned __int64 v32; // x8
  __int64 v33; // x9
  unsigned int v34; // w8
  char v35; // w12
  unsigned __int64 v38; // x9
  unsigned __int64 v39; // x9

  v5 = *a5;
  v10 = *(_WORD **)(*a5 + 224LL);
  if ( (*(_QWORD *)(a5[4] + 96LL) & 1) == 0 && (unsigned int)ieee80211_tx_h_rate_ctrl(a5) )
    return 1;
  if ( a4 )
    *(_QWORD *)(v5 + 72) = a4 + 536;
  v12 = *(unsigned int *)(v5 + 112);
  v13 = *(_QWORD *)(*(_QWORD *)(v5 + 16) + 160LL);
  v14 = _ReadStatusReg(TPIDR_EL1) + v13;
  _X10 = (unsigned __int64 *)(v14 + 24);
  __asm { PRFM            #0x11, [X10] }
  do
    v23 = __ldxr(_X10);
  while ( __stxr(v23 + v12, _X10) );
  _X8 = (unsigned __int64 *)(v14 + 16);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 + 1, _X8) );
  if ( (*v10 & 0x80) != 0 )
  {
    v16 = *(_DWORD *)(v5 + 144) & 7;
    v27 = a2 + 2 * v16;
    v28 = *(_WORD *)(v27 + 490);
    *(_WORD *)(v27 + 490) = (v28 & 0xFFF0) + 16;
    v10[11] = v28;
  }
  else
  {
    *(_DWORD *)(v5 + 40) |= 2u;
    v15 = *(_WORD *)(a1 + 1936);
    v10[11] = v15;
    *(_WORD *)(a1 + 1936) = v15 + 16;
    v16 = 16;
  }
  v29 = *(unsigned int *)(v5 + 212);
  if ( *(_WORD *)(*(_QWORD *)(v5 + 216) + v29 + 4) )
  {
    v30 = *(unsigned __int16 *)(*(_QWORD *)(v5 + 216) + v29 + 4);
    v31 = (v30 + *(_DWORD *)(v5 + 112) - 1) / v30;
  }
  else
  {
    v31 = 1;
  }
  *(_QWORD *)(a2 + 8 * v16 + 2416) += v31;
  v32 = *(unsigned __int16 *)(v5 + 124);
  if ( v32 > 3
    || (v33 = *(unsigned int *)(v5 + 112),
        *(_DWORD *)(v5 + 44) = *(_DWORD *)(v5 + 44) & 0xFFE1FFFF | ((*(_BYTE *)(a1 + v32 + 5850) & 0xF) << 17),
        *(_QWORD *)(a2 + 8 * v32 + 2360) += v33,
        v32 = *(unsigned __int16 *)(v5 + 124),
        v32 > 4) )
  {
    __break(0x5512u);
LABEL_25:
    _X10 = (unsigned __int64 *)(a4 + 536);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v38 = __ldxr(_X10);
      v39 = v38 + 1;
    }
    while ( __stlxr(v39, _X10) );
    __dmb(0xBu);
    *(_WORD *)v32 = v39;
    v35 = *(_BYTE *)(a4 + 551);
    *(_BYTE *)(v32 + 4) = BYTE2(v39);
    *(_BYTE *)(v32 + 5) = BYTE3(v39);
    *(_BYTE *)(v32 + 6) = BYTE4(v39);
    *(_BYTE *)(v32 + 3) = (v35 << 6) | 0x20;
    *(_BYTE *)(v32 + 7) = BYTE5(v39);
    return 0;
  }
  ++*(_QWORD *)(a2 + 8 * v32 + 2328);
  if ( !a3 )
    return 0;
  result = 0;
  v34 = *(_DWORD *)(a4 + 544) - 1027076;
  if ( v34 <= 6 && ((1 << v34) & 0x71) != 0 )
  {
    v32 = *(_QWORD *)(v5 + 224) + a3;
    goto LABEL_25;
  }
  return result;
}
