__int64 __fastcall _ieee80211_rx_h_amsdu(_QWORD *a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x25
  int v6; // w24
  int v7; // w8
  _BYTE *v8; // x21
  _BYTE *v9; // x22
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x3
  __int64 result; // x0
  char is_valid_amsdu; // w23
  char v15; // w0
  char v16; // w8
  char v17; // w23
  __int64 *v18; // x0
  __int64 v19; // x8
  _QWORD *v20; // x9
  __int64 v21; // x20
  __int64 v22; // x8
  _QWORD v23[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v24; // [xsp+10h] [xbp-20h]
  _BYTE v25[14]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[1];
  v4 = a1[3];
  v5 = *(_QWORD *)(v4 + 1608);
  v6 = **(unsigned __int16 **)(v3 + 224);
  if ( (~v6 & 0x300) == 0 )
    goto LABEL_5;
  v7 = *(_DWORD *)(v4 + 4720);
  v8 = &v25[6];
  if ( (unsigned int)(v7 - 3) < 2 )
  {
    v9 = nullptr;
  }
  else
  {
    if ( v7 == 2 )
    {
      v10 = a1[5];
      if ( !v10 || (*(_QWORD *)(v10 + 216) & 0x800) == 0 )
        v8 = nullptr;
    }
    else if ( v7 == 7 )
    {
LABEL_5:
      v9 = nullptr;
      v8 = nullptr;
      goto LABEL_11;
    }
    v9 = v25;
  }
LABEL_11:
  v24 = 0;
  *(_QWORD *)v25 = 0;
  *(_QWORD *)(v3 + 16) = v5;
  v11 = a1[3];
  v23[0] = v23;
  v23[1] = v23;
  *(_QWORD *)&v25[6] = 0;
  v12 = *(unsigned int *)(v11 + 4720);
  LODWORD(v24) = 0;
  if ( !(unsigned int)ieee80211_data_to_8023_exthdr(v3, v25, v11 + 5842, v12, a2, 1) )
  {
    if ( (*(char *)(a1[5] + 1333LL) & 0x80000000) == 0 )
      goto LABEL_27;
    is_valid_amsdu = ieee80211_is_valid_amsdu(v3, 0);
    v15 = ieee80211_is_valid_amsdu(v3, 1);
    if ( (is_valid_amsdu & 1) != 0 )
    {
      if ( (v15 & 1) != 0 )
      {
        v16 = -1;
LABEL_26:
        *(_BYTE *)(a1[5] + 1333LL) = v16;
LABEL_27:
        ieee80211_amsdu_to_8023s(
          v3,
          v23,
          *(_QWORD *)(v5 + 1008),
          *(unsigned int *)(a1[3] + 4720LL),
          *(unsigned int *)(a1[2] + 104LL),
          v9,
          v8);
        v18 = (__int64 *)v23[0];
        if ( (_QWORD *)v23[0] == v23 )
        {
LABEL_45:
          result = 0;
          goto LABEL_46;
        }
        while ( 1 )
        {
          if ( v18 )
          {
            LODWORD(v24) = v24 - 1;
            v19 = *v18;
            v20 = (_QWORD *)v18[1];
            *v18 = 0;
            v18[1] = 0;
            *(_QWORD *)(v19 + 8) = v20;
            *v20 = v19;
          }
          a1[1] = v18;
          v21 = v18[28];
          if ( *(unsigned __int16 *)(v21 + 12) == *(unsigned __int16 *)(a1[3] + 1940LL) )
          {
            if ( (ieee80211_is_our_addr(a1[3], v21, nullptr) & 1) == 0
              && *(_DWORD *)v21 ^ 0xC28001 | *(unsigned __int16 *)(v21 + 4) ^ 0x300 )
            {
              v18 = (__int64 *)a1[1];
LABEL_44:
              consume_skb(v18);
              goto LABEL_39;
            }
          }
          else
          {
            v22 = a1[5];
            if ( !v22
              || (*(_QWORD *)(v22 + 216) & 8) == 0
              || (v6 & 0xC) == 8 && (v6 & 0x7C) != 0x48 && (v6 & 0x4000) == 0 && (v18[8] & 2) == 0 && a1[7] )
            {
              goto LABEL_44;
            }
          }
          ieee80211_deliver_skb(a1);
LABEL_39:
          v18 = (__int64 *)v23[0];
          if ( (_QWORD *)v23[0] == v23 )
            goto LABEL_45;
        }
      }
      v17 = 0;
    }
    else
    {
      if ( (v15 & 1) == 0 )
      {
        if ( (ieee80211_is_valid_amsdu(v3, 2) & 1) != 0 )
          v16 = 2;
        else
          v16 = -1;
        goto LABEL_26;
      }
      v17 = 1;
    }
    if ( (ieee80211_is_valid_amsdu(v3, 2) & 1) != 0 )
      v16 = -1;
    else
      v16 = v17;
    goto LABEL_26;
  }
  result = 65549;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
