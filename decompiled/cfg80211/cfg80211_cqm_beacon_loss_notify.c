__int64 __fastcall cfg80211_cqm_beacon_loss_notify(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x8
  unsigned int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x3

  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))cfg80211_prepare_cqm)(a1, 0, a2);
  if ( result )
  {
    v4 = result;
    result = nla_put(result, 8, 0, 0);
    if ( (_DWORD)result )
    {
      return sk_skb_reason_drop(0, v4, 2);
    }
    else
    {
      v5 = *(_QWORD *)(v4 + 56);
      **(_WORD **)(v4 + 48) = *(_DWORD *)(v4 + 216) + *(_DWORD *)(v4 + 208) - *(_QWORD *)(v4 + 48);
      *(_DWORD *)(*(_QWORD *)(v4 + 40) - 20LL) = *(_DWORD *)(v4 + 216)
                                               + *(_DWORD *)(v4 + 208)
                                               - (*(_DWORD *)(v4 + 40)
                                                - 20);
      v6 = (unsigned __int8)byte_BF570;
      *(_QWORD *)(v4 + 72) = 0;
      *(_QWORD *)(v4 + 80) = 0;
      *(_QWORD *)(v4 + 56) = 0;
      *(_QWORD *)(v4 + 64) = 0;
      *(_QWORD *)(v4 + 40) = 0;
      *(_QWORD *)(v4 + 48) = 0;
      if ( v6 <= 3 )
      {
        __break(0x800u);
      }
      else
      {
        v7 = *(_QWORD *)(*(_QWORD *)(v5 + 2344) + 288LL);
        v8 = (unsigned int)(dword_BF5E4 + 3);
        *(_DWORD *)(v4 + 56) = v8;
        return netlink_broadcast_filtered(v7, v4, 0, v8, a2, 0, 0);
      }
    }
  }
  return result;
}
