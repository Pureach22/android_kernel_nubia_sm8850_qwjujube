__int64 __fastcall cfg80211_rx_control_port(__int64 result, __int64 a2, char a3, int a4)
{
  __int64 *v4; // x23
  __int64 v5; // x21
  __int64 v6; // x27
  __int64 v7; // x28
  unsigned int v8; // w26
  unsigned int v9; // w19
  __int64 v10; // x22
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned __int64 StatusReg; // x20
  unsigned int v17; // w19
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  __int64 v21; // [xsp+0h] [xbp-20h]
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(result + 992);
  v5 = *v4;
  if ( !*v4 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v17 = result;
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_cfg80211_return_bool(0, (unsigned int)result);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || (result = v17, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(result, v18, v19);
        result = v17;
      }
    }
    goto LABEL_14;
  }
  v6 = *(_QWORD *)(a2 + 216);
  v7 = *(unsigned __int16 *)(a2 + 186);
  v8 = *(unsigned __int16 *)(a2 + 180);
  v9 = *((_DWORD *)v4 + 25);
  if ( !v9 )
    goto LABEL_13;
  v10 = result;
  result = _alloc_skb((*(_DWORD *)(a2 + 112) + 119) & 0xFFFFFFFC, 2080, 0, 0xFFFFFFFFLL);
  if ( !result )
  {
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = result;
  v14 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 129);
  if ( !v14 )
  {
LABEL_12:
    sk_skb_reason_drop(v14, v13, 2);
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  v21 = v14;
  LODWORD(v23[0]) = *(_DWORD *)(v5 - 892);
  if ( (unsigned int)nla_put(v13, 1, 4, v23)
    || (LODWORD(v23[0]) = *(_DWORD *)(v10 + 224), (unsigned int)nla_put(v13, 3, 4, v23)) )
  {
LABEL_11:
    v14 = 0;
    goto LABEL_12;
  }
  if ( *v4 )
  {
    v23[0] = *((unsigned int *)v4 + 10) | ((unsigned __int64)*(unsigned int *)(*v4 - 892) << 32);
    if ( !(unsigned int)nla_put_64bit(v13, 153, 8, v23, 229) && !(unsigned int)nla_put(v13, 6, 6, v6 + v7 + 6) )
    {
      LOWORD(v23[0]) = bswap32(v8) >> 16;
      if ( !(unsigned int)nla_put(v13, 102, 2, v23) )
      {
        if ( a4 < 0 || (LOBYTE(v23[0]) = a4, !(unsigned int)nla_put(v13, 313, 1, v23)) )
        {
          if ( (a3 & 1) == 0 || !(unsigned int)nla_put(v13, 103, 0, 0) )
          {
            v15 = nla_reserve(v13, 51, *(unsigned int *)(a2 + 112));
            if ( v15 )
            {
              skb_copy_bits(a2, 0, v15 + 4, *(unsigned int *)(a2 + 112));
              *(_DWORD *)(v21 - 20) = *(_DWORD *)(v13 + 216) + *(_DWORD *)(v13 + 208) - (v21 - 20);
              result = (int)netlink_unicast(*(_QWORD *)(*(_QWORD *)(v5 + 1352) + 288LL), v13, v9, 64) >= 0;
              goto LABEL_14;
            }
          }
        }
      }
    }
    goto LABEL_11;
  }
  __break(0x800u);
  return cfg80211_cqm_rssi_notify();
}
