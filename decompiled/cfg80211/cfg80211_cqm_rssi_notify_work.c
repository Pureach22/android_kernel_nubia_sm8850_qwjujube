__int64 __fastcall cfg80211_cqm_rssi_notify_work(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w20
  int v5; // w21
  __int64 v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w9
  __int64 v9; // x0
  __int64 v10; // x3
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v2 = *(_QWORD *)(a2 + 24);
    if ( v2 )
    {
      if ( *(_BYTE *)(v2 + 28) == 1 )
      {
        v3 = a2;
        cfg80211_cqm_rssi_update(result - 992, *(_QWORD *)(a2 - 152), *(_QWORD *)(a2 + 24));
        a2 = v3;
      }
      v4 = *(_DWORD *)(v2 + 20);
      v5 = *(_DWORD *)(v2 + 24);
      result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))cfg80211_prepare_cqm)(*(_QWORD *)(a2 - 152), 0, 3264);
      if ( result )
      {
        v6 = result;
        v11 = v5;
        result = nla_put(result, 3, 4, &v11);
        if ( (_DWORD)result || v4 && (v11 = v4, result = nla_put(v6, 9, 4, &v11), (_DWORD)result) )
        {
          result = sk_skb_reason_drop(0, v6, 2);
        }
        else
        {
          v7 = *(_QWORD *)(v6 + 56);
          **(_WORD **)(v6 + 48) = *(_DWORD *)(v6 + 216) + *(_DWORD *)(v6 + 208) - *(_QWORD *)(v6 + 48);
          *(_DWORD *)(*(_QWORD *)(v6 + 40) - 20LL) = *(_DWORD *)(v6 + 216)
                                                   + *(_DWORD *)(v6 + 208)
                                                   - (*(_DWORD *)(v6 + 40)
                                                    - 20);
          v8 = (unsigned __int8)byte_BF570;
          *(_QWORD *)(v6 + 72) = 0;
          *(_QWORD *)(v6 + 80) = 0;
          *(_QWORD *)(v6 + 56) = 0;
          *(_QWORD *)(v6 + 64) = 0;
          *(_QWORD *)(v6 + 40) = 0;
          *(_QWORD *)(v6 + 48) = 0;
          if ( v8 <= 3 )
          {
            __break(0x800u);
          }
          else
          {
            v9 = *(_QWORD *)(*(_QWORD *)(v7 + 2344) + 288LL);
            v10 = (unsigned int)(dword_BF5E4 + 3);
            *(_DWORD *)(v6 + 56) = v10;
            result = netlink_broadcast_filtered(v9, v6, 0, v10, 3264, 0, 0);
          }
        }
      }
    }
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    __break(0x800u);
    return ((__int64 (*)(void))cfg80211_cqm_rssi_update)();
  }
  return result;
}
