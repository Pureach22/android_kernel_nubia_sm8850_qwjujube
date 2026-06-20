__int64 __fastcall nl80211_ch_switch_notify(
        __int64 a1,
        __int64 a2,
        char a3,
        __int64 a4,
        unsigned int a5,
        unsigned __int8 a6,
        char a7)
{
  __int64 v13; // x28
  __int64 result; // x0
  _DWORD *v16; // x19
  __int64 v17; // x0
  __int64 v18; // x27
  __int64 v19; // x0
  __int64 v20; // x3
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 992);
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v16 = (_DWORD *)result;
    v17 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, a5);
    if ( v17 )
    {
      v18 = v17;
      v21 = *(_DWORD *)(a2 + 224);
      if ( !(unsigned int)nla_put(v16, 3, 4, &v21) )
      {
        if ( !*(_WORD *)(v13 + 1472) || (LOBYTE(v21) = a3, !(unsigned int)nla_put(v16, 313, 1, &v21)) )
        {
          result = nl80211_send_chandef((__int64)v16, a4);
          if ( !(_DWORD)result )
          {
            if ( a5 != 110
              || (v21 = a6, result = nla_put(v16, 183, 4, &v21), !(_DWORD)result)
              && ((a7 & 1) == 0 || (result = nla_put(v16, 184, 0, 0), !(_DWORD)result)) )
            {
              *(_DWORD *)(v18 - 20) = v16[54] + v16[52] - (v18 - 20);
              if ( (unsigned __int8)byte_BF570 <= 3u )
              {
                __break(0x800u);
              }
              else
              {
                v19 = *(_QWORD *)(*(_QWORD *)(a1 + 2344) + 288LL);
                v20 = (unsigned int)(dword_BF5E4 + 3);
                v16[14] = v20;
                result = netlink_broadcast_filtered(v19, v16, 0, v20, 3264, 0, 0);
              }
              goto LABEL_6;
            }
          }
        }
      }
      v17 = 0;
    }
    result = sk_skb_reason_drop(v17, v16, 2);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
