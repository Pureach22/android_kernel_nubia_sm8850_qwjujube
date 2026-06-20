__int64 __fastcall ieee80211_set_csa_beacon(unsigned __int64 *a1, __int64 a2, _QWORD *a3)
{
  unsigned __int64 v3; // x19
  int v4; // w8
  __int64 v7; // x22
  __int64 v8; // x0
  unsigned int v9; // w9
  __int64 result; // x0
  unsigned int v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w11
  __int64 v14; // x12
  __int64 v15; // x13
  unsigned int v16; // w0
  unsigned int v17; // w19
  __int64 v18; // x22
  int chandef_type; // w21
  int v20; // w0
  _QWORD v21[2]; // [xsp+8h] [xbp-28h] BYREF
  int v22; // [xsp+18h] [xbp-18h]
  unsigned int v23; // [xsp+1Ch] [xbp-14h]
  __int64 v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v24 = 0;
  v4 = *(_DWORD *)(v3 + 4720);
  if ( v4 != 1 )
  {
    if ( v4 != 3 )
    {
      result = 4294967201LL;
      goto LABEL_20;
    }
    v7 = a2;
    v8 = cfg80211_beacon_dup(a2 + 232);
    a1[71] = v8;
    if ( !v8 )
    {
      result = 4294967284LL;
      goto LABEL_20;
    }
    v9 = *(unsigned __int8 *)(v7 + 410);
    if ( v9 < 2 )
      goto LABEL_5;
    if ( *(_DWORD *)(v7 + 224) > 2u || (v13 = *(_DWORD *)(v7 + 228), v13 >= 3) )
    {
      kfree(*(_QWORD *)(v8 + 72));
      kfree(*(_QWORD *)(a1[71] + 80));
      kfree(a1[71]);
      a1[71] = 0;
      goto LABEL_19;
    }
    v14 = *(_QWORD *)(v7 + 208);
    v15 = *(_QWORD *)(v7 + 216);
    v22 = *(_DWORD *)(v7 + 224);
    v23 = v13;
    v21[0] = v14;
    v21[1] = v15;
    LOBYTE(v24) = v9;
    v16 = ieee80211_assign_beacon((const void **)v3, a1, v7 + 32, (__int64)v21, 0, a3);
    if ( (v16 & 0x80000000) != 0 )
    {
      v17 = v16;
      ieee80211_free_next_beacon((__int64)a1);
      result = v17;
      goto LABEL_20;
    }
LABEL_5:
    result = 0;
    goto LABEL_20;
  }
  if ( *(_BYTE *)(v3 + 4729) != 1 )
    goto LABEL_19;
  v11 = *(_DWORD *)(a2 + 8);
  if ( v11 != *(_DWORD *)(v3 + 2408) )
    goto LABEL_19;
  result = 4294967274LL;
  if ( v11 > 7 )
    goto LABEL_20;
  if ( ((1 << v11) & 0xC3) == 0 )
  {
    if ( v11 != 2 )
      goto LABEL_20;
    v18 = a2;
    chandef_type = cfg80211_get_chandef_type(a2);
    v20 = cfg80211_get_chandef_type(v3 + 2400);
    a2 = v18;
    if ( chandef_type != v20 )
      goto LABEL_19;
  }
  if ( **(_DWORD **)(v3 + 2400) != **(_DWORD **)a2 )
  {
LABEL_19:
    result = 4294967274LL;
    goto LABEL_20;
  }
  if ( *(unsigned __int8 *)(a2 + 410) < 2u
    || (v12 = a2, result = ieee80211_ibss_csa_beacon(v3), a2 = v12, (result & 0x80000000) == 0) )
  {
    ieee80211_send_action_csa(v3, a2);
    goto LABEL_5;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
