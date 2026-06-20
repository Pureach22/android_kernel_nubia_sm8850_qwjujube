__int64 __fastcall ieee80211_determine_our_sta_mode(__int64 result, __int64 a2, __int64 a3, char a4, __int64 a5)
{
  int v6; // w24
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v12; // x21
  int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  int v19; // w8
  __int64 v20; // x9
  __int64 v21; // x8
  unsigned __int8 *v22; // x9
  int v23; // t1
  int v24; // w9
  unsigned int v25; // w8
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v29[14]; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+28h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a2 + 16);
  v7 = *(_QWORD *)(a2 + 36);
  v8 = *(_QWORD *)(a2 + 42);
  v28 = *(_QWORD *)(a2 + 28);
  *(_QWORD *)v29 = v7;
  *(_QWORD *)&v29[6] = v8;
  if ( v6 == 4 )
  {
    *(_QWORD *)a5 = 0;
LABEL_3:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = result;
  v26 = 0;
  v27 = 0;
  *(_QWORD *)a5 = 1;
  result = ieee80211_apply_htcap_overrides(result, (__int64)&v28);
  if ( !a3 )
  {
    if ( (a4 & 1) == 0 || !((v6 == 3) | BYTE2(v28) & 1) )
      goto LABEL_3;
    goto LABEL_28;
  }
  if ( (*(_BYTE *)(a3 + 156) & 1) != 0 || (a4 & 1) == 0 )
    goto LABEL_3;
  v13 = *(_DWORD *)(a3 + 40);
  if ( !v13 )
    goto LABEL_23;
  v14 = *(_DWORD *)(a3 + 44) - 1027073;
  if ( v14 <= 4 && ((1 << v14) & 0x13) != 0 )
    goto LABEL_51;
  if ( v13 == 1 )
    goto LABEL_23;
  v15 = *(_DWORD *)(a3 + 48) - 1027073;
  if ( v15 <= 4 && ((1 << v15) & 0x13) != 0 )
    goto LABEL_51;
  if ( v13 == 2 )
    goto LABEL_23;
  v16 = *(_DWORD *)(a3 + 52) - 1027073;
  if ( v16 <= 4 && ((1 << v16) & 0x13) != 0 )
    goto LABEL_51;
  if ( v13 == 3 )
    goto LABEL_23;
  v17 = *(_DWORD *)(a3 + 56) - 1027073;
  if ( v17 <= 4 && ((1 << v17) & 0x13) != 0 )
    goto LABEL_51;
  if ( v13 == 4 )
  {
LABEL_23:
    if ( v6 != 3 && (v28 & 0x10000) == 0 )
      goto LABEL_3;
LABEL_28:
    v19 = ((unsigned __int16)v28 >> 1) & 1;
    *(_DWORD *)a5 = 2;
    *(_DWORD *)(a5 + 4) = v19;
    v20 = *(_QWORD *)(a2 + 60);
    v26 = *(_QWORD *)(a2 + 52);
    v27 = v20;
    result = ieee80211_apply_vhtcap_overrides(v12, &v26);
    if ( a3 && (*(_BYTE *)(a3 + 156) & 2) != 0 )
      goto LABEL_3;
    if ( v6 == 1 && (v26 & 1) != 0 )
    {
      if ( !*(_DWORD *)(a5 + 4) )
        goto LABEL_3;
      v21 = *(unsigned int *)(a2 + 20);
      if ( !(_DWORD)v21 )
        goto LABEL_3;
      v22 = (unsigned __int8 *)(*(_QWORD *)a2 + 12LL);
      while ( 1 )
      {
        v23 = *v22;
        v22 += 64;
        if ( (v23 & 0xFFFFFF81) == 0 )
          break;
        if ( !--v21 )
          goto LABEL_3;
      }
    }
    else if ( v6 == 1 )
    {
      goto LABEL_3;
    }
    if ( *(_DWORD *)(a2 + 16) )
      *(_QWORD *)a5 = 0x300000003LL;
    if ( v6 == 1 && (v26 & 0xC00000000LL) == 0 )
      *(_DWORD *)(a5 + 4) = 2;
    if ( a3 && (*(_BYTE *)(a3 + 156) & 0x10) != 0 )
      goto LABEL_3;
    result = (__int64)ieee80211_get_he_iftype_cap_vif(a2, v12 + 4720);
    if ( !result )
    {
      if ( v6 == 3 )
        __break(0x800u);
      goto LABEL_3;
    }
    *(_DWORD *)a5 = 4;
    v24 = *(_DWORD *)(a2 + 16);
    if ( v24 == 1 )
    {
      if ( (*(_BYTE *)(result + 7) & 4) == 0 )
      {
LABEL_55:
        v25 = 0;
LABEL_59:
        *(_DWORD *)(a5 + 4) = v25;
        goto LABEL_60;
      }
    }
    else if ( v24 != 3 )
    {
      if ( (*(_BYTE *)(result + 7) & 2) == 0 )
        goto LABEL_55;
LABEL_60:
      if ( !a3 || (*(_BYTE *)(a3 + 156) & 0x20) == 0 )
      {
        result = ieee80211_get_eht_iftype_cap_vif(a2);
        if ( result )
        {
          *(_DWORD *)a5 = 5;
          if ( v6 == 3 && (*(_BYTE *)(result + 3) & 2) != 0 )
            *(_DWORD *)(a5 + 4) = 4;
        }
      }
      goto LABEL_3;
    }
    if ( (*(_BYTE *)(result + 7) & 8) == 0 )
    {
      v25 = *(_DWORD *)(a5 + 4);
      if ( v25 >= 2 )
        v25 = 2;
      goto LABEL_59;
    }
    goto LABEL_60;
  }
  v18 = *(_DWORD *)(a3 + 60) - 1027073;
  if ( v18 <= 4 && ((1 << v18) & 0x13) != 0 )
  {
LABEL_51:
    result = netdev_info(*(_QWORD *)(v12 + 1608), "WEP/TKIP use, limiting to legacy\n");
    goto LABEL_3;
  }
  if ( v13 == 5 )
    goto LABEL_23;
  __break(0x5512u);
  return ieee80211_get_eht_iftype_cap_vif(result);
}
