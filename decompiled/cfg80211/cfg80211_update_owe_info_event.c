__int64 __fastcall cfg80211_update_owe_info_event(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 v6; // x20
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x23
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  __int64 v13; // x2
  __int64 v14; // x21
  int v15; // t1
  unsigned __int64 StatusReg; // x22
  __int64 updated; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = **(_QWORD **)(a1 + 992);
  if ( v6 )
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
      updated = _traceiter_cfg80211_update_owe_info_event(0, 0, v5, v4);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(updated, v18, v19);
    }
  }
  result = _alloc_skb(3712, v3, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v8 = result;
    v9 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 135);
    if ( v9 )
    {
      v10 = v9;
      v21 = *(_DWORD *)(v6 - 892);
      if ( !(unsigned int)nla_put(v8, 1, 4, &v21) )
      {
        v21 = *(_DWORD *)(v5 + 224);
        if ( !(unsigned int)nla_put(v8, 3, 4, &v21) && !(unsigned int)nla_put(v8, 6, 6, v4) )
        {
          v13 = *(_QWORD *)(v4 + 16);
          if ( v13 )
          {
            if ( !(unsigned int)nla_put(v8, 42, v13, *(_QWORD *)(v4 + 8)) )
            {
              if ( *(_DWORD *)(v4 + 24) == -1
                || (LOBYTE(v21) = *(_DWORD *)(v4 + 24), !(unsigned int)nla_put(v8, 313, 1, &v21))
                && ((v15 = *(_DWORD *)(v4 + 28), v14 = v4 + 28, !(v15 | *(unsigned __int16 *)(v14 + 4)))
                 || !(unsigned int)nla_put(v8, 314, 6, v14)) )
              {
                *(_DWORD *)(v10 - 20) = *(_DWORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (v10 - 20);
                result = genlmsg_multicast_netns(*(_QWORD *)(v6 + 1352), v8, 3u, v3);
                goto LABEL_13;
              }
            }
          }
        }
      }
      v11 = v10 - 20;
      if ( v10 != 20 )
      {
        v12 = *(_QWORD *)(v8 + 224);
        if ( v12 > v11 )
        {
          __break(0x800u);
          v12 = *(_QWORD *)(v8 + 224);
        }
        skb_trim(v8, (unsigned int)(v11 - v12));
      }
    }
    result = sk_skb_reason_drop(0, v8, 2);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
