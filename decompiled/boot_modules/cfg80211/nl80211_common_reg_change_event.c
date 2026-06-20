__int64 __fastcall nl80211_common_reg_change_event(unsigned int a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x20
  int v8; // w8
  char v9; // w8
  int v10; // w8
  __int64 v11; // x0
  _UNKNOWN **v12; // x0
  _UNKNOWN **v13; // x22
  int v14; // w0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v5 = result;
    v6 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, a1);
    if ( !v6 )
      goto LABEL_22;
    v7 = v6;
    LOBYTE(v15) = *(_DWORD *)(a2 + 20);
    if ( (unsigned int)nla_put(v5, 48, 1, &v15) )
      goto LABEL_22;
    v8 = *(unsigned __int8 *)(a2 + 28);
    if ( v8 == 57 )
    {
      v10 = *(unsigned __int8 *)(a2 + 29);
      if ( v10 == 56 )
      {
LABEL_12:
        v9 = 3;
LABEL_13:
        LOBYTE(v15) = v9;
        if ( (unsigned int)nla_put(v5, 49, 1, &v15) )
          goto LABEL_22;
        goto LABEL_14;
      }
      if ( v10 == 57 )
      {
        v9 = 2;
        goto LABEL_13;
      }
    }
    else if ( v8 == 48 && *(_BYTE *)(a2 + 29) == 48 )
    {
      v9 = 1;
      goto LABEL_13;
    }
    if ( *(_BYTE *)(a2 + 36) != 1 )
    {
      LOBYTE(v15) = 0;
      if ( (unsigned int)nla_put(v5, 49, 1, &v15) )
        goto LABEL_22;
      v14 = strlen((const char *)(a2 + 28));
      if ( (unsigned int)nla_put(v5, 33, (unsigned int)(v14 + 1), a2 + 28) )
        goto LABEL_22;
LABEL_14:
      v11 = *(unsigned int *)(a2 + 16);
      if ( (_DWORD)v11 == -1
        || (v12 = wiphy_idx_to_wiphy(v11)) == nullptr
        || (v13 = v12, v15 = *(_DWORD *)(a2 + 16), !(unsigned int)nla_put(v5, 1, 4, &v15))
        && (((_BYTE)v13[13] & 0x80) == 0 || !(unsigned int)nla_put(v5, 216, 0, 0)) )
      {
        *(_DWORD *)(v7 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v7 - 20);
        result = genlmsg_multicast_allns(&nl80211_fam, v5, 0, 2);
        goto LABEL_23;
      }
LABEL_22:
      result = sk_skb_reason_drop(0, v5, 2);
      goto LABEL_23;
    }
    goto LABEL_12;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
