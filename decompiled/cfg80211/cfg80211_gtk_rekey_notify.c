__int64 __fastcall cfg80211_gtk_rekey_notify(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x25
  __int64 v13; // x22
  __int64 v14; // x23
  _WORD *v15; // x22
  unsigned __int64 StatusReg; // x21
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = **(_QWORD **)(a1 + 992);
  if ( v8 )
  {
    v4 = a4;
    v5 = a3;
    v7 = a1;
    v6 = a2;
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
      v17 = _traceiter_cfg80211_gtk_rekey_notify(0, v7, v6);
      v20 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v20;
      if ( !v20 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v17, v18, v19);
    }
  }
  result = _alloc_skb(3712, v4, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v10 = result;
    v11 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 79);
    if ( v11 )
    {
      v12 = v11;
      v21 = *(_DWORD *)(v8 - 892);
      if ( !(unsigned int)nla_put(v10, 1, 4, &v21) )
      {
        v21 = *(_DWORD *)(v7 + 224);
        if ( !(unsigned int)nla_put(v10, 3, 4, &v21) && !(unsigned int)nla_put(v10, 6, 6, v6) )
        {
          v13 = *(_QWORD *)(v10 + 216);
          v14 = *(unsigned int *)(v10 + 208);
          if ( (nla_put(v10, 122, 0, 0) & 0x80000000) == 0 )
          {
            v15 = (_WORD *)(v13 + v14);
            if ( v15 )
            {
              if ( !(unsigned int)nla_put(v10, 3, 8, v5) )
              {
                *v15 = *(_DWORD *)(v10 + 216) + *(_DWORD *)(v10 + 208) - (_WORD)v15;
                *(_DWORD *)(v12 - 20) = *(_DWORD *)(v10 + 216) + *(_DWORD *)(v10 + 208) - (v12 - 20);
                result = genlmsg_multicast_netns(*(_QWORD *)(v8 + 1352), v10, 3u, v4);
                goto LABEL_10;
              }
            }
          }
        }
      }
      v11 = 0;
    }
    result = sk_skb_reason_drop(v11, v10, 2);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
