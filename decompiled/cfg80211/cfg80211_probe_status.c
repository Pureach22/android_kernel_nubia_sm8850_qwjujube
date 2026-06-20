__int64 __fastcall cfg80211_probe_status(__int64 a1, __int64 a2, __int64 a3, char a4, int a5, char a6, unsigned int a7)
{
  unsigned int v7; // w19
  int v8; // w20
  char v9; // w21
  char v10; // w22
  __int64 v11; // x24
  __int64 v12; // x25
  __int64 v13; // x26
  __int64 v14; // x27
  __int64 result; // x0
  __int64 v16; // x23
  __int64 v17; // x0
  __int64 v18; // x28
  unsigned __int64 StatusReg; // x23
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x8
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = **(_QWORD **)(a1 + 992);
  if ( v14 )
  {
    v7 = a7;
    v9 = a6;
    v8 = a5;
    v13 = a1;
    v10 = a4;
    v11 = a3;
    v12 = a2;
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
      v20 = _traceiter_cfg80211_probe_status(0, v13, v12, v11, v10 & 1);
      v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v23;
      if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v20, v21, v22);
    }
  }
  result = _alloc_skb(3712, v7, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v16 = result;
    v17 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 84);
    if ( v17 )
    {
      v18 = v17;
      LODWORD(v24[0]) = *(_DWORD *)(v14 - 892);
      if ( !(unsigned int)nla_put(v16, 1, 4, v24) )
      {
        LODWORD(v24[0]) = *(_DWORD *)(v13 + 224);
        if ( !(unsigned int)nla_put(v16, 3, 4, v24) && !(unsigned int)nla_put(v16, 6, 6, v12) )
        {
          v24[0] = v11;
          if ( !(unsigned int)nla_put_64bit(v16, 88, 8, v24, 229)
            && ((v10 & 1) == 0 || !(unsigned int)nla_put(v16, 92, 0, 0)) )
          {
            if ( (v9 & 1) == 0 || (LODWORD(v24[0]) = v8, !(unsigned int)nla_put(v16, 263, 4, v24)) )
            {
              *(_DWORD *)(v18 - 20) = *(_DWORD *)(v16 + 216) + *(_DWORD *)(v16 + 208) - (v18 - 20);
              result = genlmsg_multicast_netns(*(_QWORD *)(v14 + 1352), v16, 3u, v7);
              goto LABEL_11;
            }
          }
        }
      }
      v17 = 0;
    }
    result = sk_skb_reason_drop(v17, v16, 2);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
