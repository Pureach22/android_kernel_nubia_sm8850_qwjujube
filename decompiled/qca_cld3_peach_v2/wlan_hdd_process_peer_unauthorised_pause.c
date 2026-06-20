__int64 __fastcall wlan_hdd_process_peer_unauthorised_pause(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w8
  __int64 v4; // x11
  unsigned __int64 v11; // x12
  unsigned int v12; // w8
  __int64 v13; // x11
  unsigned __int64 v16; // x12
  unsigned int v17; // w8
  __int64 v18; // x11
  unsigned __int64 v21; // x12
  __int64 result; // x0
  unsigned int v23; // w8
  __int64 v24; // x11
  unsigned __int64 v27; // x12
  _BYTE v28[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v29[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 32);
  v29[0] = 0;
  v28[0] = 0;
  netif_tx_wake_queue(*(_QWORD *)(v2 + 24));
  wlan_hdd_get_txq_info_for_ac(a1, 1, v28, v29);
  if ( v29[0] )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 384LL * v28[0]++;
      *(_QWORD *)(v4 + 328) = jiffies;
      __dmb(0xBu);
      _X11 = (unsigned __int64 *)(v4 + 336);
      __asm { PRFM            #0x11, [X11] }
      do
        v11 = __ldxr(_X11);
      while ( __stxr(v11 | 1, _X11) );
      ++v3;
    }
    while ( v3 < v29[0] );
  }
  wlan_hdd_get_txq_info_for_ac(a1, 2, v28, v29);
  if ( v29[0] )
  {
    v12 = 0;
    do
    {
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 384LL * v28[0]++;
      *(_QWORD *)(v13 + 328) = jiffies;
      __dmb(0xBu);
      _X11 = (unsigned __int64 *)(v13 + 336);
      __asm { PRFM            #0x11, [X11] }
      do
        v16 = __ldxr(_X11);
      while ( __stxr(v16 | 1, _X11) );
      ++v12;
    }
    while ( v12 < v29[0] );
  }
  wlan_hdd_get_txq_info_for_ac(a1, 3, v28, v29);
  if ( v29[0] )
  {
    v17 = 0;
    do
    {
      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 384LL * v28[0]++;
      *(_QWORD *)(v18 + 328) = jiffies;
      __dmb(0xBu);
      _X11 = (unsigned __int64 *)(v18 + 336);
      __asm { PRFM            #0x11, [X11] }
      do
        v21 = __ldxr(_X11);
      while ( __stxr(v21 | 1, _X11) );
      ++v17;
    }
    while ( v17 < v29[0] );
  }
  result = wlan_hdd_get_txq_info_for_ac(a1, 4, v28, v29);
  if ( v29[0] )
  {
    v23 = 0;
    do
    {
      v24 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 384LL * v28[0]++;
      *(_QWORD *)(v24 + 328) = jiffies;
      __dmb(0xBu);
      _X11 = (unsigned __int64 *)(v24 + 336);
      __asm { PRFM            #0x11, [X11] }
      do
        v27 = __ldxr(_X11);
      while ( __stxr(v27 | 1, _X11) );
      ++v23;
    }
    while ( v23 < v29[0] );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
