__int64 __fastcall cfg80211_external_auth_request(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x15
  __int64 *v9; // x22
  __int64 v10; // x23
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 v15; // x0
  int v16; // w8
  __int64 v17; // x21
  __int64 result; // x0
  __int64 v19; // x20
  int v20; // t1
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(__int64 **)(a1 + 992);
  v10 = *v9;
  if ( *v9 )
  {
    if ( *((_DWORD *)v9 + 25) )
    {
      v13 = _alloc_skb(3712, a3, 0, 0xFFFFFFFFLL);
      if ( v13 )
      {
        v14 = v13;
        v15 = genlmsg_put(v13, 0, 0, &nl80211_fam, 0, 127);
        if ( !v15 )
          goto LABEL_13;
        v16 = *(_DWORD *)(a2 + 44);
        v17 = v15;
        if ( v16 == 1027080 )
          v16 = 145493760;
        v21 = v16;
        if ( (unsigned int)nla_put(v14, 76, 4, &v21)
          || (v21 = *(_DWORD *)(v10 - 892), (unsigned int)nla_put(v14, 1, 4, &v21))
          || (v21 = *(_DWORD *)(a1 + 224), (unsigned int)nla_put(v14, 3, 4, &v21))
          || (v21 = *(_DWORD *)a2, (unsigned int)nla_put(v14, 260, 4, &v21))
          || (unsigned int)nla_put(v14, 245, 6, a2 + 4)
          || (unsigned int)nla_put(v14, 52, *(unsigned __int8 *)(a2 + 42), a2 + 10)
          || (v20 = *(_DWORD *)(a2 + 64), v19 = a2 + 64, v20 | *(unsigned __int16 *)(v19 + 4))
          && (unsigned int)nla_put(v14, 314, 6, v19) )
        {
LABEL_13:
          sk_skb_reason_drop(0, v14, 2);
          result = 4294967191LL;
        }
        else
        {
          *(_DWORD *)(v17 - 20) = *(_DWORD *)(v14 + 216) + *(_DWORD *)(v14 + 208) - (v17 - 20);
          netlink_unicast(*(_QWORD *)(*(_QWORD *)(v10 + 1352) + 288LL), v14, *((unsigned int *)v9 + 25), 64);
          result = 0;
        }
      }
      else
      {
        result = 4294967284LL;
      }
    }
    else
    {
      result = 4294967274LL;
    }
    _ReadStatusReg(SP_EL0);
  }
  else
  {
    __break(0x800u);
    *(double *)(v8 - 104) = a5;
    *(double *)(v8 - 96) = a8;
    return cfg80211_update_owe_info_event();
  }
  return result;
}
