__int64 __fastcall wlan_hdd_stop_non_priority_queue(__int64 result)
{
  __int64 v1; // x9
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x10
  _QWORD *v15; // x12
  unsigned __int64 v18; // x13
  unsigned __int64 v25; // x10
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v58; // x10

  v1 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v1 + 712) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v1 + 720);
  __asm { PRFM            #0x11, [X9] }
  do
    v25 = __ldxr(_X9);
  while ( __stxr(v25 | 1, _X9) );
  v2 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v2 + 1096) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v2 + 1104);
  __asm { PRFM            #0x11, [X9] }
  do
    v28 = __ldxr(_X9);
  while ( __stxr(v28 | 1, _X9) );
  v3 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v3 + 1480) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v3 + 1488);
  __asm { PRFM            #0x11, [X9] }
  do
    v31 = __ldxr(_X9);
  while ( __stxr(v31 | 1, _X9) );
  v4 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v4 + 1864) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v4 + 1872);
  __asm { PRFM            #0x11, [X9] }
  do
    v34 = __ldxr(_X9);
  while ( __stxr(v34 | 1, _X9) );
  v5 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v5 + 2248) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v5 + 2256);
  __asm { PRFM            #0x11, [X9] }
  do
    v37 = __ldxr(_X9);
  while ( __stxr(v37 | 1, _X9) );
  v6 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v6 + 2632) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v6 + 2640);
  __asm { PRFM            #0x11, [X9] }
  do
    v40 = __ldxr(_X9);
  while ( __stxr(v40 | 1, _X9) );
  v7 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v7 + 3016) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v7 + 3024);
  __asm { PRFM            #0x11, [X9] }
  do
    v43 = __ldxr(_X9);
  while ( __stxr(v43 | 1, _X9) );
  v8 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v8 + 3400) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v8 + 3408);
  __asm { PRFM            #0x11, [X9] }
  do
    v46 = __ldxr(_X9);
  while ( __stxr(v46 | 1, _X9) );
  v9 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v9 + 3784) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v9 + 3792);
  __asm { PRFM            #0x11, [X9] }
  do
    v49 = __ldxr(_X9);
  while ( __stxr(v49 | 1, _X9) );
  v10 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v10 + 4168) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v10 + 4176);
  __asm { PRFM            #0x11, [X9] }
  do
    v52 = __ldxr(_X9);
  while ( __stxr(v52 | 1, _X9) );
  v11 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v11 + 4552) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v11 + 4560);
  __asm { PRFM            #0x11, [X9] }
  do
    v55 = __ldxr(_X9);
  while ( __stxr(v55 | 1, _X9) );
  v12 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  *(_QWORD *)(v12 + 4936) = jiffies;
  __dmb(0xBu);
  _X9 = (unsigned __int64 *)(v12 + 4944);
  __asm { PRFM            #0x11, [X9] }
  do
    v58 = __ldxr(_X9);
  while ( __stxr(v58 | 1, _X9) );
  v13 = 4;
  if ( *(_DWORD *)(result + 40) == 11 )
    v13 = 33;
  v14 = 5320;
  do
  {
    v15 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 32) + 24LL) + v14);
    *v15 = jiffies;
    __dmb(0xBu);
    _X12 = v15 + 1;
    __asm { PRFM            #0x11, [X12] }
    do
      v18 = __ldxr(_X12);
    while ( __stxr(v18 | 1, _X12) );
    --v13;
    v14 += 384;
  }
  while ( v13 );
  return result;
}
