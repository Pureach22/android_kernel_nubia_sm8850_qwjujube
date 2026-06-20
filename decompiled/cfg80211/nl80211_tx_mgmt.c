__int64 __fastcall nl80211_tx_mgmt(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x19
  __int64 *v4; // x20
  unsigned int v5; // w9
  __int64 result; // x0
  __int64 v7; // x9
  unsigned int v8; // w9
  __int64 v9; // x22
  __int64 v10; // x9
  _QWORD *v11; // x21
  char v12; // w0
  _QWORD *v13; // x9
  __int64 v14; // x8
  int v15; // w8
  unsigned __int64 v16; // x10
  _WORD *v17; // x8
  unsigned __int16 v18; // w8
  _WORD *v19; // x9
  unsigned int v20; // w10
  unsigned int v21; // w11
  int v22; // w11
  _WORD *v23; // x9
  unsigned int *v24; // x23
  __int64 v25; // x22
  __int64 v26; // x21
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w0
  unsigned int v30; // w19
  int v31; // w0
  __int64 v32; // [xsp+0h] [xbp-70h] BYREF
  __int64 v33; // [xsp+8h] [xbp-68h]
  _WORD *v34; // [xsp+10h] [xbp-60h]
  __int64 v35; // [xsp+18h] [xbp-58h]
  __int64 v36; // [xsp+20h] [xbp-50h]
  _WORD *v37; // [xsp+28h] [xbp-48h]
  __int64 v38; // [xsp+30h] [xbp-40h]
  __int64 v39; // [xsp+38h] [xbp-38h]
  _QWORD v40[4]; // [xsp+40h] [xbp-30h] BYREF
  _QWORD v41[2]; // [xsp+60h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a2[4];
  memset(&v40[1], 0, 24);
  v3 = a2[6];
  v4 = (__int64 *)a2[7];
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = nullptr;
  v34 = nullptr;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  BYTE1(v36) = v2[142] != 0;
  if ( !v2[51] )
    goto LABEL_27;
  if ( !*(_QWORD *)(*(_QWORD *)v3 + 520LL) )
  {
    result = 4294967201LL;
    goto LABEL_28;
  }
  v5 = *((_DWORD *)v4 + 2);
  result = 4294967201LL;
  if ( v5 <= 0xC )
  {
    if ( ((1 << v5) & 0x39E) == 0 )
    {
      if ( v5 == 10 )
      {
        if ( !v2[38] )
          goto LABEL_27;
      }
      else if ( v5 != 12 || (*(char *)(*v4 + 119) & 0x80000000) == 0 )
      {
        goto LABEL_28;
      }
    }
    v7 = v2[87];
    if ( v7 )
    {
      if ( (*(_BYTE *)(v3 + 1094) & 0x10) == 0 )
        goto LABEL_27;
      v8 = *(_DWORD *)(v7 + 4);
      HIDWORD(v33) = v8;
      if ( v8 < 0xA || v8 > *(unsigned __int16 *)(v3 + 1256) )
        goto LABEL_27;
    }
    v9 = v2[108];
    LOBYTE(v33) = v9 != 0;
    if ( v9 )
    {
      if ( (*(_BYTE *)(v3 + 1094) & 0x10) == 0 )
        goto LABEL_27;
    }
    v10 = v2[135];
    v40[0] = 0;
    LOBYTE(v36) = v10 != 0;
    if ( v2[38] )
    {
      v11 = a2;
      result = nl80211_parse_chandef(v3, (__int64)a2, 0, (__int64)v40);
      if ( (_DWORD)result )
        goto LABEL_28;
      a2 = v11;
      if ( v40[0] )
      {
        if ( v9 )
        {
          v12 = cfg80211_off_channel_oper_allowed(v4, v40[0]);
          a2 = v11;
          if ( (v12 & 1) == 0 )
          {
            result = 4294967280LL;
            goto LABEL_28;
          }
        }
LABEL_23:
        v13 = (_QWORD *)a2[4];
        v14 = v13[313];
        if ( v14 )
        {
          v15 = *(unsigned __int8 *)(v14 + 4);
          v16 = (unsigned __int64)*((unsigned __int16 *)v4 + 736) >> v15;
          LODWORD(v38) = v15;
          if ( (v16 & 1) == 0 )
            goto LABEL_27;
        }
        else
        {
          LODWORD(v38) = -1;
        }
        v17 = (_WORD *)v13[51];
        v34 = v17 + 2;
        v18 = *v17 - 4;
        v35 = v18;
        v19 = (_WORD *)v13[205];
        HIDWORD(v36) = 0;
        if ( v19 )
        {
          result = 4294967274LL;
          if ( *v19 != 4 && (*v19 & 1) == 0 )
          {
            v20 = (unsigned __int16)(*v19 - 4) >> 1;
            v21 = *(unsigned __int8 *)(v3 + 2386);
            HIDWORD(v36) = v20;
            if ( !v21 || v20 <= v21 )
            {
              v22 = 0;
              v23 = v19 + 2;
              v37 = v23;
              while ( (unsigned __int16)v23[v22] < (unsigned int)v18 )
              {
                if ( v20 == ++v22 )
                  goto LABEL_38;
              }
              goto LABEL_27;
            }
          }
          goto LABEL_28;
        }
LABEL_38:
        v24 = (unsigned int *)a2;
        if ( (v36 & 0x100) != 0 )
        {
          v25 = 0;
          v26 = 0;
        }
        else
        {
          v27 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
          if ( !v27 )
          {
            result = 4294967284LL;
            goto LABEL_28;
          }
          v26 = v27;
          v28 = genlmsg_put(v27, v24[1], *v24, &nl80211_fam, 0, 59);
          if ( !v28 )
            goto LABEL_47;
          v25 = v28;
        }
        v32 = v40[0];
        v29 = cfg80211_mlme_mgmt_tx(v3, v4, (__int64)&v32);
        if ( v29 )
        {
          v30 = v29;
LABEL_48:
          sk_skb_reason_drop(0, v26, 2);
          result = v30;
          goto LABEL_28;
        }
        if ( !v26 )
        {
          result = 0;
          goto LABEL_28;
        }
        v41[0] = v39;
        if ( !(unsigned int)nla_put_64bit(v26, 88, 8, v41, 229) )
        {
          *(_DWORD *)(v25 - 20) = *(_DWORD *)(v26 + 216) + *(_DWORD *)(v26 + 208) - (v25 - 20);
          v31 = netlink_unicast(*(_QWORD *)(*((_QWORD *)v24 + 5) + 288LL), v26, v24[1], 64);
          result = v31 & (unsigned int)(v31 >> 31);
          goto LABEL_28;
        }
LABEL_47:
        v30 = -105;
        goto LABEL_48;
      }
    }
    if ( !v9 )
      goto LABEL_23;
LABEL_27:
    result = 4294967274LL;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
