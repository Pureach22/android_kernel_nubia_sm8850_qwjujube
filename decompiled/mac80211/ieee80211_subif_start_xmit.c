__int64 __fastcall ieee80211_subif_start_xmit(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 *i; // x0
  __int64 v6; // x8
  _QWORD *v7; // x9
  _QWORD v8[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (**(_BYTE **)(a1 + 224) & 1) == 0 )
  {
LABEL_2:
    _ieee80211_subif_start_xmit(a1, a2, 0, 0xF0000000, 0);
    goto LABEL_3;
  }
  if ( (*(_QWORD *)(a2 + 4320) & 1) == 0 )
  {
    sk_skb_reason_drop(0);
    goto LABEL_3;
  }
  v3 = a1;
  v4 = a2;
  if ( (ieee80211_multicast_to_unicast() & 1) == 0 )
  {
    a2 = v4;
    a1 = v3;
    if ( *(_WORD *)(v4 + 8488)
      && *(_DWORD *)(v4 + 7408) == 3
      && (*(_QWORD *)(*(_QWORD *)(v4 + 4304) + 96LL) & 0x10000000000000LL) == 0 )
    {
      ieee80211_mlo_multicast_tx(v4, v3);
      goto LABEL_3;
    }
    goto LABEL_2;
  }
  v8[0] = v8;
  v8[1] = v8;
  v9 = 0;
  ieee80211_convert_to_unicast(v3, v4, v8);
  for ( i = (__int64 *)v8[0]; (_QWORD *)v8[0] != v8 && v8[0]; i = (__int64 *)v8[0] )
  {
    LODWORD(v9) = v9 - 1;
    v6 = *i;
    v7 = (_QWORD *)i[1];
    *i = 0;
    i[1] = 0;
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    _ieee80211_subif_start_xmit((__int64)i, v4, 0, 0xF0000000, 0);
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return 0;
}
