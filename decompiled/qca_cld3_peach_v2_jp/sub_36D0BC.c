// positive sp value has been detected, the output may be wrong!
__int64 sub_36D0BC()
{
  __int64 v0; // x10
  __int64 v1; // x11
  __int64 v2; // x19
  __int64 v3; // x20
  char v4; // w21
  unsigned int v5; // w22
  __int64 v6; // x23
  __int64 result; // x0
  bool v8; // cc
  __int64 v9; // x8
  _QWORD *v10; // x10
  __int64 v12; // x8
  _QWORD *v13; // x10
  __int64 v15; // x8
  _QWORD *v16; // x10
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v30; // x9

  v5 = *(unsigned __int8 *)(v0 + v1);
  *(_BYTE *)(v0 + 52037) = v5;
  if ( v5 )
  {
    v6 = 6864;
    do
    {
      if ( (v5 & 1) != 0 )
      {
        v9 = *(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6;
        if ( (v4 & 1) != 0 )
        {
          v10 = (_QWORD *)(v9 - 1160);
          _X8 = (unsigned __int64 *)(v9 - 1152);
          *v10 = *(_QWORD *)(v3 + 3584);
          __dmb(0xBu);
          __asm { PRFM            #0x11, [X8] }
          do
            v24 = __ldxr(_X8);
          while ( __stxr(v24 | 1, _X8) );
          v12 = *(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6;
          v13 = (_QWORD *)(v12 - 776);
          _X8 = (unsigned __int64 *)(v12 - 768);
          *v13 = *(_QWORD *)(v3 + 3584);
          __dmb(0xBu);
          __asm { PRFM            #0x11, [X8] }
          do
            v26 = __ldxr(_X8);
          while ( __stxr(v26 | 1, _X8) );
          v15 = *(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6;
          v16 = (_QWORD *)(v15 - 392);
          _X8 = (unsigned __int64 *)(v15 - 384);
          *v16 = *(_QWORD *)(v3 + 3584);
          __dmb(0xBu);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 | 1, _X8) );
          _X8 = (unsigned __int64 *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6);
          *(_X8 - 1) = *(_QWORD *)(v3 + 3584);
          __dmb(0xBu);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 | 1, _X8) );
        }
        else
        {
          netif_tx_wake_queue(v9 - 1488);
          netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6 - 1104);
          netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6 - 720);
          result = netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 24LL) + v6 - 336);
        }
      }
      v8 = v5 > 1;
      v6 += 1536;
      v5 >>= 1;
    }
    while ( v8 );
  }
  return result;
}
