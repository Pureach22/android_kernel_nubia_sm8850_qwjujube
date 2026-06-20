__int64 __fastcall cfg80211_cqm_txe_notify(__int64 a1, __int64 a2, int a3, int a4, int a5, unsigned int a6)
{
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned int v13; // w9
  __int64 v14; // x0
  __int64 v15; // x3
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cfg80211_prepare_cqm)(a1, a2, a6);
  if ( result )
  {
    v11 = result;
    v16 = a3;
    if ( (unsigned int)nla_put(result, 6, 4, &v16)
      || (v16 = a4, (unsigned int)nla_put(v11, 5, 4, &v16))
      || (v16 = a5, result = nla_put(v11, 7, 4, &v16), (_DWORD)result) )
    {
      result = sk_skb_reason_drop(0, v11, 2);
    }
    else
    {
      v12 = *(_QWORD *)(v11 + 56);
      **(_WORD **)(v11 + 48) = *(_DWORD *)(v11 + 216) + *(_DWORD *)(v11 + 208) - *(_QWORD *)(v11 + 48);
      *(_DWORD *)(*(_QWORD *)(v11 + 40) - 20LL) = *(_DWORD *)(v11 + 216)
                                                + *(_DWORD *)(v11 + 208)
                                                - (*(_DWORD *)(v11 + 40)
                                                 - 20);
      v13 = (unsigned __int8)byte_BF570;
      *(_QWORD *)(v11 + 72) = 0;
      *(_QWORD *)(v11 + 80) = 0;
      *(_QWORD *)(v11 + 56) = 0;
      *(_QWORD *)(v11 + 64) = 0;
      *(_QWORD *)(v11 + 40) = 0;
      *(_QWORD *)(v11 + 48) = 0;
      if ( v13 <= 3 )
      {
        __break(0x800u);
      }
      else
      {
        v14 = *(_QWORD *)(*(_QWORD *)(v12 + 2344) + 288LL);
        v15 = (unsigned int)(dword_BF5E4 + 3);
        *(_DWORD *)(v11 + 56) = v15;
        result = netlink_broadcast_filtered(v14, v11, 0, v15, a6, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
