__int64 __fastcall cfg80211_pmksa_candidate_notify(__int64 a1, unsigned int a2, __int64 a3, char a4, unsigned int a5)
{
  unsigned int v5; // w19
  char v6; // w20
  __int64 v7; // x21
  unsigned int v8; // w23
  __int64 v9; // x24
  __int64 v10; // x25
  __int64 result; // x0
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x26
  __int64 v15; // x24
  __int64 v16; // x27
  _WORD *v17; // x24
  unsigned __int64 StatusReg; // x22
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x8
  unsigned int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = **(_QWORD **)(a1 + 992);
  if ( v10 )
  {
    v5 = a5;
    v6 = a4;
    v7 = a3;
    v9 = a1;
    v8 = a2;
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
      v19 = _traceiter_cfg80211_pmksa_candidate_notify(0, v9, v8, v7, v6 & 1);
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      if ( !v22 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v19, v20, v21);
    }
  }
  result = _alloc_skb(3712, v5, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v12 = result;
    v13 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 80);
    if ( v13 )
    {
      v14 = v13;
      v23 = *(_DWORD *)(v10 - 892);
      if ( !(unsigned int)nla_put(v12, 1, 4, &v23) )
      {
        v23 = *(_DWORD *)(v9 + 224);
        if ( !(unsigned int)nla_put(v12, 3, 4, &v23) )
        {
          v15 = *(_QWORD *)(v12 + 216);
          v16 = *(unsigned int *)(v12 + 208);
          if ( (nla_put(v12, 134, 0, 0) & 0x80000000) == 0 )
          {
            v17 = (_WORD *)(v15 + v16);
            if ( v17 )
            {
              v23 = v8;
              if ( !(unsigned int)nla_put(v12, 1, 4, &v23)
                && !(unsigned int)nla_put(v12, 2, 6, v7)
                && ((v6 & 1) == 0 || !(unsigned int)nla_put(v12, 3, 0, 0)) )
              {
                *v17 = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (_WORD)v17;
                *(_DWORD *)(v14 - 20) = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (v14 - 20);
                result = genlmsg_multicast_netns(*(_QWORD *)(v10 + 1352), v12, 3u, v5);
                goto LABEL_9;
              }
            }
          }
        }
      }
      v13 = 0;
    }
    result = sk_skb_reason_drop(v13, v12, 2);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
