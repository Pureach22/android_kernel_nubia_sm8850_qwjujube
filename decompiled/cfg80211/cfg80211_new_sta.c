__int64 __fastcall cfg80211_new_sta(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x24
  __int64 result; // x0
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x3
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x8

  v8 = **(_QWORD **)(a1 + 992);
  if ( v8 )
  {
    v4 = a4;
    v5 = a3;
    v6 = a1;
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
      v14 = _traceiter_cfg80211_new_sta(0, v6, v7, v5);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v14, v15, v16);
    }
  }
  result = _alloc_skb(3712, v4, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v10 = result;
    result = nl80211_send_station(result, 19, 0, 0, 0, v8 - 992, v6, v7, v5);
    if ( (result & 0x80000000) != 0 )
    {
      return sk_skb_reason_drop(0, v10, 2);
    }
    else if ( (unsigned __int8)byte_BF570 <= 3u )
    {
      __break(0x800u);
    }
    else
    {
      v11 = *(_QWORD *)(*(_QWORD *)(v8 + 1352) + 288LL);
      v12 = (unsigned int)(dword_BF5E4 + 3);
      *(_DWORD *)(v10 + 56) = v12;
      return netlink_broadcast_filtered(v11, v10, 0, v12, v4, 0, 0);
    }
  }
  return result;
}
