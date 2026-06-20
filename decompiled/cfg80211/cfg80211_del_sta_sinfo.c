__int64 __fastcall cfg80211_del_sta_sinfo(__int64 a1, __int64 a2, __int64 *a3, unsigned int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 *v7; // x22
  __int64 *v8; // x25
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x3
  __int64 *v15; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  _BYTE s[264]; // [xsp+10h] [xbp-110h] BYREF
  __int64 v22; // [xsp+118h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = **(_QWORD **)(a1 + 992);
  if ( v9 )
  {
    v7 = a3;
    v5 = a1;
    v6 = a2;
    v4 = a4;
    memset(s, 0, sizeof(s));
    if ( v7 )
      v8 = v7;
    else
      v8 = (__int64 *)s;
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
      v17 = _traceiter_cfg80211_del_sta(0, v5, v6);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v17, v18, v19);
    }
  }
  v10 = _alloc_skb(3712, v4, 0, 0xFFFFFFFFLL);
  if ( v10 )
  {
    v11 = v10;
    result = nl80211_send_station(v10, 0x14u, 0, 0, 0, v9 - 992, v5, v6, v8);
    if ( (result & 0x80000000) != 0 )
    {
      result = sk_skb_reason_drop(0, v11, 2);
    }
    else if ( (unsigned __int8)byte_BF570 <= 3u )
    {
      __break(0x800u);
    }
    else
    {
      v13 = *(_QWORD *)(*(_QWORD *)(v9 + 1352) + 288LL);
      v14 = (unsigned int)(dword_BF5E4 + 3);
      *(_DWORD *)(v11 + 56) = v14;
      result = netlink_broadcast_filtered(v13, v11, 0, v14, v4, 0, 0);
    }
  }
  else
  {
    v15 = (__int64 *)s;
    if ( v7 )
      v15 = v7;
    result = kfree(v15[25]);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
