__int64 __fastcall cfg80211_notify_new_peer_candidate(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        int a5,
        unsigned int a6)
{
  unsigned int v6; // w19
  int v7; // w20
  __int64 v8; // x21
  unsigned __int8 v9; // w22
  __int64 v10; // x24
  __int64 v11; // x25
  __int64 *v12; // x8
  __int64 v13; // x27
  __int64 v14; // x23
  __int64 v15; // x0
  __int64 v16; // x28
  unsigned __int64 StatusReg; // x23
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(__int64 **)(result + 992);
  v13 = *v12;
  if ( *v12 )
  {
    if ( *((_DWORD *)v12 + 2) != 7 )
    {
      __break(0x800u);
      goto LABEL_11;
    }
    v6 = a6;
    v7 = a5;
    v9 = a4;
    v11 = result;
    v8 = a3;
    v10 = a2;
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
      v18 = _traceiter_cfg80211_notify_new_peer_candidate(0, v11, v10);
      v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v21;
      if ( !v21 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v18, v19, v20);
    }
  }
  result = _alloc_skb((v9 + 119) & 0x1FC, v6, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v14 = result;
    v15 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 72);
    if ( v15 )
    {
      v16 = v15;
      v22 = *(_DWORD *)(v13 - 892);
      if ( !(unsigned int)nla_put(v14, 1, 4, &v22) )
      {
        v22 = *(_DWORD *)(v11 + 224);
        if ( !(unsigned int)nla_put(v14, 3, 4, &v22)
          && !(unsigned int)nla_put(v14, 6, 6, v10)
          && (!v8 || !v9 || !(unsigned int)nla_put(v14, 42, v9, v8)) )
        {
          if ( !v7 || (v22 = v7, !(unsigned int)nla_put(v14, 151, 4, &v22)) )
          {
            *(_DWORD *)(v16 - 20) = *(_DWORD *)(v14 + 216) + *(_DWORD *)(v14 + 208) - (v16 - 20);
            result = genlmsg_multicast_netns(*(_QWORD *)(v13 + 1352), v14, 3u, v6);
            goto LABEL_11;
          }
        }
      }
      v15 = 0;
    }
    result = sk_skb_reason_drop(v15, v14, 2);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
