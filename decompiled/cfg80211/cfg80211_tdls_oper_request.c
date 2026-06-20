__int64 __fastcall cfg80211_tdls_oper_request(__int64 a1, __int64 a2, char a3, __int16 a4, unsigned int a5)
{
  unsigned int v5; // w19
  unsigned int v6; // w21
  __int64 v7; // x22
  unsigned int v8; // w24
  __int64 v9; // x25
  __int64 v10; // x20
  __int64 result; // x0
  __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x26
  unsigned __int64 StatusReg; // x23
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x8
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = **(_QWORD **)(a1 + 992);
  if ( v10 )
  {
    v5 = a5;
    LOWORD(v6) = a4;
    LOBYTE(v8) = a3;
    v9 = a1;
    v7 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v16 = _traceiter_cfg80211_tdls_oper_request(0, 0, v9, v7, v8, v6);
      v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v19;
      if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v16, v17, v18);
    }
  }
  result = _alloc_skb(3712, v5, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v12 = result;
    v13 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 81);
    if ( v13 )
    {
      v14 = v13;
      v20 = *(_DWORD *)(v10 - 892);
      if ( !(unsigned int)nla_put(v12, 1, 4, &v20) )
      {
        v20 = *(_DWORD *)(v9 + 224);
        if ( !(unsigned int)nla_put(v12, 3, 4, &v20) )
        {
          LOBYTE(v20) = v8;
          if ( !(unsigned int)nla_put(v12, 138, 1, &v20) && !(unsigned int)nla_put(v12, 6, 6, v7) )
          {
            if ( !(_WORD)v6 || (LOWORD(v20) = v6, !(unsigned int)nla_put(v12, 54, 2, &v20)) )
            {
              *(_DWORD *)(v14 - 20) = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (v14 - 20);
              result = genlmsg_multicast_netns(*(_QWORD *)(v10 + 1352), v12, 3u, v5);
              goto LABEL_11;
            }
          }
        }
      }
      v13 = 0;
    }
    result = sk_skb_reason_drop(v13, v12, 2);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
