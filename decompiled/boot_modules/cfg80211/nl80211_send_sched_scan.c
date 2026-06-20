__int64 __fastcall nl80211_send_sched_scan(_QWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x21
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
  __int64 v12; // x3
  __int64 v13; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( !result )
    goto LABEL_12;
  v5 = result;
  v6 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, a2);
  if ( !v6 )
    goto LABEL_11;
  v8 = a1[14];
  if ( v8 )
  {
    v9 = v6;
    LODWORD(v14[0]) = *(_DWORD *)(v8 - 892);
    if ( !(unsigned int)nla_put(v5, 1, 4, v14) )
    {
      LODWORD(v14[0]) = *(_DWORD *)(a1[15] + 224LL);
      if ( !(unsigned int)nla_put(v5, 3, 4, v14) )
      {
        v14[0] = *a1;
        result = nla_put_64bit(v5, 88, 8, v14, 229);
        if ( !(_DWORD)result )
        {
          *(_DWORD *)(v9 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v9 - 20);
          if ( (unsigned __int8)byte_BF570 <= 1u )
          {
            __break(0x800u);
          }
          else
          {
            v12 = (unsigned int)(dword_BF5E4 + 1);
            v13 = *(_QWORD *)(*(_QWORD *)(a1[14] + 1352LL) + 288LL);
            *(_DWORD *)(v5 + 56) = v12;
            result = netlink_broadcast_filtered(v13, v5, 0, v12, 3264, 0, 0);
          }
          goto LABEL_12;
        }
      }
    }
    v10 = v9 - 20;
    if ( v9 != 20 )
    {
      v11 = *(_QWORD *)(v5 + 224);
      if ( v11 > v10 )
      {
        __break(0x800u);
        v11 = *(_QWORD *)(v5 + 224);
      }
      skb_trim(v5, (unsigned int)(v10 - v11));
    }
LABEL_11:
    result = sk_skb_reason_drop(0, v5, 2);
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return nl80211_common_reg_change_event(v6, v7);
}
