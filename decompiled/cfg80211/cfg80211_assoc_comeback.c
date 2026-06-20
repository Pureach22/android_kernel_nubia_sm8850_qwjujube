__int64 __fastcall cfg80211_assoc_comeback(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  __int64 v5; // x22
  __int64 *v6; // x8
  __int64 v7; // x23
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x24
  unsigned __int64 StatusReg; // x21
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x8
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(__int64 **)(a1 + 992);
  v7 = *v6;
  if ( *v6 )
  {
    v3 = a3;
    v5 = a1;
    v4 = a2;
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
      v13 = _traceiter_cfg80211_assoc_comeback(0, v6, v4, v3);
      v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v16;
      if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v13, v14, v15);
    }
  }
  result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v9 = result;
    v10 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 147);
    if ( v10 )
    {
      v11 = v10;
      v17 = *(_DWORD *)(v7 - 892);
      if ( !(unsigned int)nla_put(v9, 1, 4, &v17) )
      {
        v17 = *(_DWORD *)(v5 + 224);
        if ( !(unsigned int)nla_put(v9, 3, 4, &v17) && !(unsigned int)nla_put(v9, 6, 6, v4) )
        {
          v17 = v3;
          if ( !(unsigned int)nla_put(v9, 272, 4, &v17) )
          {
            *(_DWORD *)(v11 - 20) = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (v11 - 20);
            result = genlmsg_multicast_netns(*(_QWORD *)(v7 + 1352), v9, 3u, 0xCC0u);
            goto LABEL_11;
          }
        }
      }
      v10 = 0;
    }
    result = sk_skb_reason_drop(v10, v9, 2);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
