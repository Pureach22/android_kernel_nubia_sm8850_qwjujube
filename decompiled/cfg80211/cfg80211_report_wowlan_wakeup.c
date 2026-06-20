__int64 __fastcall cfg80211_report_wowlan_wakeup(_QWORD *a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x21
  _QWORD *v5; // x24
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x8
  __int64 v13; // x24
  __int64 v14; // x25
  _WORD *v15; // x25
  __int64 v16; // x3
  unsigned int v17; // w24
  __int64 v18; // x1
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x8
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  if ( *a1 )
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
      v20 = _traceiter_cfg80211_report_wowlan_wakeup(0, 0, v5, v4);
      v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v23;
      if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v20, v21, v22);
    }
  }
  if ( v4 )
    v7 = *(_DWORD *)(v4 + 16) + 200;
  else
    v7 = 200;
  result = _alloc_skb((v7 + 19) & 0xFFFFFFFC, v3, 0, 0xFFFFFFFFLL);
  if ( !result )
    goto LABEL_12;
  v9 = result;
  v10 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 74);
  if ( !v10 )
    goto LABEL_11;
  v11 = v10;
  LODWORD(v24[0]) = *(_DWORD *)(v6 - 892);
  if ( (unsigned int)nla_put(v9, 1, 4, v24) )
    goto LABEL_11;
  if ( *v5 )
  {
    v24[0] = *((unsigned int *)v5 + 10) | ((unsigned __int64)*(unsigned int *)(*v5 - 892LL) << 32);
    if ( !(unsigned int)nla_put_64bit(v9, 153, 8, v24, 229) )
    {
      v12 = v5[4];
      if ( !v12 || (LODWORD(v24[0]) = *(_DWORD *)(v12 + 224), !(unsigned int)nla_put(v9, 3, 4, v24)) )
      {
        if ( !v4 )
        {
LABEL_54:
          *(_DWORD *)(v11 - 20) = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (v11 - 20);
          result = genlmsg_multicast_netns(*(_QWORD *)(v6 + 1352), v9, 3u, v3);
          goto LABEL_12;
        }
        v13 = *(_QWORD *)(v9 + 216);
        v14 = *(unsigned int *)(v9 + 208);
        if ( (nla_put(v9, 117, 0, 0) & 0x80000000) == 0 )
        {
          v15 = (_WORD *)(v13 + v14);
          if ( v15 )
          {
            if ( (*(_BYTE *)v4 != 1 || !(unsigned int)nla_put(v9, 2, 0, 0))
              && (*(_BYTE *)(v4 + 1) != 1 || !(unsigned int)nla_put(v9, 3, 0, 0))
              && (*(_BYTE *)(v4 + 2) != 1 || !(unsigned int)nla_put(v9, 6, 0, 0))
              && (*(_BYTE *)(v4 + 3) != 1 || !(unsigned int)nla_put(v9, 7, 0, 0))
              && (*(_BYTE *)(v4 + 4) != 1 || !(unsigned int)nla_put(v9, 8, 0, 0))
              && (*(_BYTE *)(v4 + 5) != 1 || !(unsigned int)nla_put(v9, 9, 0, 0)) )
            {
              if ( (*(_DWORD *)(v4 + 12) & 0x80000000) != 0
                || (LODWORD(v24[0]) = *(_DWORD *)(v4 + 12), !(unsigned int)nla_put(v9, 4, 4, v24)) )
              {
                if ( (*(_BYTE *)(v4 + 7) != 1 || !(unsigned int)nla_put(v9, 15, 0, 0))
                  && (*(_BYTE *)(v4 + 8) != 1 || !(unsigned int)nla_put(v9, 16, 0, 0))
                  && (*(_BYTE *)(v4 + 9) != 1 || !(unsigned int)nla_put(v9, 17, 0, 0))
                  && (*(_BYTE *)(v4 + 10) != 1 || !(unsigned int)nla_put(v9, 20, 0, 0)) )
                {
                  v16 = *(_QWORD *)(v4 + 24);
                  if ( !v16 )
                    goto LABEL_62;
                  if ( *(_BYTE *)(v4 + 6) )
                    v17 = 10;
                  else
                    v17 = 12;
                  if ( *(_DWORD *)(v4 + 20) )
                  {
                    if ( *(_BYTE *)(v4 + 6) )
                      v18 = 11;
                    else
                      v18 = 13;
                    LODWORD(v24[0]) = *(_DWORD *)(v4 + 20);
                    if ( (unsigned int)nla_put(v9, v18, 4, v24) )
                      goto LABEL_11;
                    v16 = *(_QWORD *)(v4 + 24);
                  }
                  if ( !(unsigned int)nla_put(v9, v17, *(unsigned int *)(v4 + 16), v16) )
                  {
LABEL_62:
                    if ( !*(_QWORD *)(v4 + 32) || !(unsigned int)cfg80211_net_detect_results(v9, v4) )
                    {
                      *v15 = *(_WORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v15;
                      goto LABEL_54;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_11:
    result = sk_skb_reason_drop(0, v9, 2);
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return ((__int64 (*)(void))cfg80211_net_detect_results)();
}
