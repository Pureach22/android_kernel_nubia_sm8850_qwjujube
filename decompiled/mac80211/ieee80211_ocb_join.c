__int64 __fastcall ieee80211_ocb_join(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v6; // x20
  unsigned __int64 v14; // x9
  __int64 v15[9]; // [xsp+8h] [xbp-48h] BYREF

  v15[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v3 = a2[1];
  memset(&v15[4], 0, 32);
  v15[0] = v2;
  v15[1] = v3;
  v4 = a2[3];
  v15[2] = a2[2];
  v15[3] = v4;
  if ( (*(_BYTE *)(a1 + 2336) & 1) != 0 )
  {
    result = 4294967274LL;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 1616);
    *(_BYTE *)(a1 + 3752) = 1;
    *(_DWORD *)(a1 + 4060) = 1;
    *(_BYTE *)(a1 + 4058) = *(_BYTE *)(v6 + 1504);
    result = ieee80211_link_use_channel(a1 + 3616, v15, 0, 0);
    if ( !(_DWORD)result )
    {
      ieee80211_bss_info_change_notify(a1, 4194432);
      *(_BYTE *)(a1 + 2336) = 1;
      _X8 = (unsigned __int64 *)(a1 + 2304);
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 | 1, _X8) );
      wiphy_work_queue(*(_QWORD *)(v6 + 72), a1 + 1960);
      netif_carrier_on(*(_QWORD *)(a1 + 1608));
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
