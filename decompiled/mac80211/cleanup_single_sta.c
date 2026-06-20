__int64 __fastcall cleanup_single_sta(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 i; // x22
  __int64 v6; // x21
  unsigned __int64 v14; // x11
  unsigned __int64 v17; // x11
  unsigned __int64 v20; // x11
  unsigned int v23; // w10

  v1 = *(_QWORD *)(a1 + 80);
  v2 = (_DWORD *)a1;
  v3 = *(_QWORD *)(v1 + 1616);
  if ( (*(_QWORD *)(a1 + 216) & 4) != 0
    || (*(_QWORD *)(a1 + 216) & 0x200) != 0
    || (*(_QWORD *)(a1 + 216) & 0x2000000) != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(v1 + 4720) - 3) > 1 )
      return sta_info_free(a1, (__int64)v2);
    v4 = *(_QWORD *)(v1 + 2032);
    _X9 = (unsigned __int64 *)(a1 + 216);
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr(_X9);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 216);
    __asm { PRFM            #0x11, [X9] }
    do
      v17 = __ldxr(_X9);
    while ( __stxr(v17 & 0xFFFFFFFFFFFFFDFFLL, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 216);
    __asm { PRFM            #0x11, [X9] }
    do
      v20 = __ldxr(_X9);
    while ( __stxr(v20 & 0xFFFFFFFFFDFFFFFFLL, _X9) );
    _X8 = (unsigned int *)(v4 + 296);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 - 1, _X8) );
  }
  ieee80211_purge_sta_txqs(a1);
  *(_DWORD *)(v3 + 5000) -= v2[62];
  ieee80211_purge_tx_queue(v3, v2 + 58);
  ieee80211_purge_tx_queue(v3, v2 + 82);
  *(_DWORD *)(v3 + 5000) -= v2[68];
  ieee80211_purge_tx_queue(v3, v2 + 64);
  ieee80211_purge_tx_queue(v3, v2 + 88);
  *(_DWORD *)(v3 + 5000) -= v2[74];
  ieee80211_purge_tx_queue(v3, v2 + 70);
  ieee80211_purge_tx_queue(v3, v2 + 94);
  *(_DWORD *)(v3 + 5000) -= v2[80];
  ieee80211_purge_tx_queue(v3, v2 + 76);
  ieee80211_purge_tx_queue(v3, v2 + 100);
  cancel_work_sync(v2 + 42);
  for ( i = 0; i != 32; i += 2 )
  {
    a1 = kfree(*(_QWORD *)&v2[i + 258]);
    v6 = *(_QWORD *)&v2[i + 226];
    if ( v6 )
    {
      ieee80211_purge_tx_queue(v3, v6 + 96);
      a1 = kfree(v6);
    }
  }
  return sta_info_free(a1, (__int64)v2);
}
