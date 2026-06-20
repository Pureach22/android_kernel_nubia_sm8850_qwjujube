__int64 __fastcall _ieee80211_vht_handle_opmode(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v5; // w8
  unsigned int v7; // w21
  __int64 v8; // x8
  unsigned int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x3
  int v12; // w8
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x8
  int v16; // w9
  int v17; // w8
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  __int64 v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  if ( (a3 & 0x80) == 0 )
  {
    v5 = a3 >> 4;
    v7 = v5 + 1;
    if ( *(unsigned __int8 *)(a2 + 7) != v5 + 1 )
    {
      if ( v5 >= *(unsigned __int8 *)(a2 + 8) )
      {
        if ( (unsigned int)__ratelimit(&_ieee80211_vht_handle_opmode__rs, "__ieee80211_vht_handle_opmode") )
          printk(&unk_B94E3, *(_QWORD *)(a2 + 920) + 8LL, v7, v11);
      }
      else
      {
        v8 = *(_QWORD *)(a2 + 920);
        *(_BYTE *)(a2 + 7) = v7;
        if ( v7 != *(unsigned __int8 *)(v8 + 230) )
        {
          *(_BYTE *)(v8 + 230) = v7;
          v9 = 8;
          v10 = *(_QWORD *)(a2 + 920);
          LODWORD(v19) = 4;
          BYTE4(v20) = *(_BYTE *)(v10 + 230);
          goto LABEL_10;
        }
      }
    }
    v9 = 0;
LABEL_10:
    if ( (a3 & 3u) > 1 )
    {
      if ( (a3 & 3) != 2 || (a3 & 4) != 0 )
        v12 = 3;
      else
        v12 = 2;
    }
    else
    {
      if ( (a3 & 3) == 0 )
      {
        *(_DWORD *)(a2 + 912) = 0;
        goto LABEL_19;
      }
      v12 = 1;
    }
    *(_DWORD *)(a2 + 912) = v12;
LABEL_19:
    v13 = ieee80211_sta_cur_vht_bw(a2, 0);
    v14 = *(_QWORD *)(a2 + 920);
    if ( v13 == *(_DWORD *)(v14 + 232) )
    {
      if ( !(_DWORD)v19 )
        goto LABEL_36;
      goto LABEL_35;
    }
    *(_DWORD *)(v14 + 232) = v13;
    v15 = *(_QWORD *)(a2 + 920);
    v16 = *(_DWORD *)(v15 + 232);
    if ( v16 > 1 )
    {
      if ( v16 == 2 )
      {
        v17 = 3;
        goto LABEL_34;
      }
      if ( v16 == 3 )
      {
        if ( (*(_DWORD *)(v15 + 72) & 0xC) == 4 )
          v17 = 5;
        else
          v17 = 4;
        goto LABEL_34;
      }
    }
    else
    {
      if ( !v16 )
      {
        v17 = *(unsigned __int8 *)(v15 + 46);
        goto LABEL_34;
      }
      if ( v16 == 1 )
      {
        v17 = 2;
LABEL_34:
        LODWORD(v20) = v17;
        v9 |= 1u;
        LODWORD(v19) = v19 | 1;
LABEL_35:
        cfg80211_sta_opmode_change_notify(*(_QWORD *)(a1 + 1608), a2, &v19, 3264);
        goto LABEL_36;
      }
    }
    v17 = 1;
    goto LABEL_34;
  }
  v9 = 0;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v9;
}
