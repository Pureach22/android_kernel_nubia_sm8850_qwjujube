__int64 __fastcall cfg80211_ft_event(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x3
  unsigned __int64 StatusReg; // x21
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = **(_QWORD **)(result + 992);
  if ( v4 )
  {
    v3 = result;
    v2 = a2;
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
      result = _traceiter_cfg80211_ft_event(0, 0, v3, v2);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
        result = preempt_schedule_notrace(result, v10, v11);
    }
  }
  if ( *(_QWORD *)(v2 + 16) )
  {
    result = _alloc_skb((*(_DWORD *)(v2 + 8) + *(_DWORD *)(v2 + 32) + 119) & 0xFFFFFFFC, 3264, 0, 0xFFFFFFFFLL);
    if ( result )
    {
      v5 = result;
      v6 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 97);
      if ( !v6
        || (v7 = v6, v13 = *(_DWORD *)(v4 - 892), (unsigned int)nla_put(v5, 1, 4, &v13))
        || (v13 = *(_DWORD *)(v3 + 224), (unsigned int)nla_put(v5, 3, 4, &v13))
        || (unsigned int)nla_put(v5, 6, 6, *(_QWORD *)(v2 + 16))
        || *(_QWORD *)v2 && (unsigned int)nla_put(v5, 42, *(unsigned int *)(v2 + 8), *(_QWORD *)v2)
        || (v8 = *(_QWORD *)(v2 + 24)) != 0 && (unsigned int)nla_put(v5, 178, *(unsigned int *)(v2 + 32), v8) )
      {
        result = sk_skb_reason_drop(0, v5, 2);
      }
      else
      {
        *(_DWORD *)(v7 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v7 - 20);
        result = genlmsg_multicast_netns(*(_QWORD *)(v4 + 1352), v5, 3u, 0xCC0u);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
