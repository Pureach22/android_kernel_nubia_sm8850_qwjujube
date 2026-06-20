__int64 __fastcall cfg80211_cqm_pktloss_notify(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v7; // x20
  __int64 v8; // x8
  unsigned int v9; // w9
  __int64 v10; // x0
  __int64 v11; // x3
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cfg80211_prepare_cqm)(a1, a2, a4);
  if ( result )
  {
    v7 = result;
    v12 = a3;
    result = nla_put(result, 4, 4, &v12);
    if ( (_DWORD)result )
    {
      result = sk_skb_reason_drop(0, v7, 2);
    }
    else
    {
      v8 = *(_QWORD *)(v7 + 56);
      **(_WORD **)(v7 + 48) = *(_DWORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - *(_QWORD *)(v7 + 48);
      *(_DWORD *)(*(_QWORD *)(v7 + 40) - 20LL) = *(_DWORD *)(v7 + 216)
                                               + *(_DWORD *)(v7 + 208)
                                               - (*(_DWORD *)(v7 + 40)
                                                - 20);
      v9 = (unsigned __int8)byte_BF570;
      *(_QWORD *)(v7 + 72) = 0;
      *(_QWORD *)(v7 + 80) = 0;
      *(_QWORD *)(v7 + 56) = 0;
      *(_QWORD *)(v7 + 64) = 0;
      *(_QWORD *)(v7 + 40) = 0;
      *(_QWORD *)(v7 + 48) = 0;
      if ( v9 <= 3 )
      {
        __break(0x800u);
      }
      else
      {
        v10 = *(_QWORD *)(*(_QWORD *)(v8 + 2344) + 288LL);
        v11 = (unsigned int)(dword_BF5E4 + 3);
        *(_DWORD *)(v7 + 56) = v11;
        result = netlink_broadcast_filtered(v10, v7, 0, v11, a4, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
