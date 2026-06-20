__int64 __fastcall cfg80211_report_obss_beacon_khz(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  unsigned int v5; // w19
  signed int v6; // w20
  __int64 v7; // x22
  __int64 *i; // x25
  __int64 v9; // x0
  __int64 v10; // x26
  __int64 v11; // x0
  __int64 v12; // x27
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x8
  __int64 v19; // [xsp+0h] [xbp-30h]
  int v22; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = a5;
    v6 = a4;
    v7 = a1;
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
      v15 = _traceiter_cfg80211_report_obss_beacon(0, v7, a2, a3, (unsigned int)v6, v5);
      v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v18;
      if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v15, v16, v17);
    }
  }
  v19 = v7 - 832;
  raw_spin_lock_bh(v7 - 832);
  for ( i = *(__int64 **)(v7 - 848); i != (__int64 *)(v7 - 848); i = (__int64 *)*i )
  {
    v9 = _alloc_skb(((_DWORD)a3 + 119) & 0xFFFFFFFC, 2080, 0, 0xFFFFFFFFLL);
    if ( !v9 )
      break;
    v10 = v9;
    v11 = genlmsg_put(v9, 0, 0, &nl80211_fam, 0, 59);
    if ( !v11
      || (v12 = v11, v22 = *(_DWORD *)(v7 - 892), (unsigned int)nla_put(v10, 1, 4, &v22))
      || v6
      && ((v22 = v6 / 1000, (unsigned int)nla_put(v10, 38, 4, &v22))
       || (v22 = v6 % 1000, (unsigned int)nla_put(v10, 290, 4, &v22)))
      || v5 && (v22 = v5, (unsigned int)nla_put(v10, 151, 4, &v22))
      || (unsigned int)nla_put(v10, 51, a3, a2) )
    {
      raw_spin_unlock_bh(v19);
      result = sk_skb_reason_drop(0, v10, 2);
      goto LABEL_16;
    }
    *(_DWORD *)(v12 - 20) = *(_DWORD *)(v10 + 216) + *(_DWORD *)(v10 + 208) - (v12 - 20);
    netlink_unicast(*(_QWORD *)(*(_QWORD *)(v7 + 1352) + 288LL), v10, *((unsigned int *)i + 4), 64);
  }
  result = raw_spin_unlock_bh(v19);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
