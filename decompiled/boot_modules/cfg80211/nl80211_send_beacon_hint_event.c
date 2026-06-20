__int64 __fastcall nl80211_send_beacon_hint_event(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x25
  _WORD *v12; // x24
  __int64 v13; // x22
  __int64 v14; // x24
  _WORD *v15; // x22
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, 2080, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v7 = result;
    v8 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 42);
    if ( v8 )
    {
      v9 = v8;
      v16 = ((__int64 (__fastcall *)(__int64))get_wiphy_idx)(a1);
      if ( !(unsigned int)nla_put(v7, 1, 4, &v16) )
      {
        v10 = *(_QWORD *)(v7 + 216);
        v11 = *(unsigned int *)(v7 + 208);
        if ( (nla_put(v7, 58, 0, 0) & 0x80000000) == 0 )
        {
          v12 = (_WORD *)(v10 + v11);
          if ( v12 )
          {
            if ( !(unsigned int)nl80211_msg_put_channel(v7, a1, a2, 0) )
            {
              *v12 = *(_WORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v12;
              v13 = *(_QWORD *)(v7 + 216);
              v14 = *(unsigned int *)(v7 + 208);
              if ( (nla_put(v7, 59, 0, 0) & 0x80000000) == 0 )
              {
                v15 = (_WORD *)(v13 + v14);
                if ( v15 )
                {
                  if ( !(unsigned int)nl80211_msg_put_channel(v7, a1, a3, 0) )
                  {
                    *v15 = *(_DWORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v15;
                    *(_DWORD *)(v9 - 20) = *(_DWORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (v9 - 20);
                    result = genlmsg_multicast_allns(&nl80211_fam, v7, 0, 2);
                    goto LABEL_6;
                  }
                }
              }
            }
          }
        }
      }
      v8 = 0;
    }
    result = sk_skb_reason_drop(v8, v7, 2);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
