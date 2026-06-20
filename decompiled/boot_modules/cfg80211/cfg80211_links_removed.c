__int64 __fastcall cfg80211_links_removed(__int64 result, unsigned int a2)
{
  unsigned int v2; // w19
  __int64 v3; // x21
  __int64 *v4; // x20
  __int64 v5; // x22
  int v6; // w8
  int v7; // w8
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x21
  __int64 v12; // x24
  _WORD *v13; // x21
  __int64 v14; // x27
  __int64 v15; // x28
  __int16 v16; // w26
  _WORD *v17; // x27
  unsigned __int64 StatusReg; // x23
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(result + 992);
  v5 = *v4;
  if ( *v4 )
  {
    v3 = result;
    v2 = a2;
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
      result = _traceiter_cfg80211_links_removed(0, v3, v2);
      v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v21;
      if ( !v21 || !*(_QWORD *)(StatusReg + 16) )
        result = preempt_schedule_notrace(result, v19, v20);
    }
  }
  v6 = *((_DWORD *)v4 + 2);
  if ( (v6 == 2 || v6 == 8)
    && (v7 = *((unsigned __int16 *)v4 + 736), v7 != (unsigned __int16)v2)
    && (_WORD)v2
    && *((_WORD *)v4 + 736)
    && (v7 & v2) == (unsigned __int16)v2 )
  {
    cfg80211_wdev_release_link_bsses(v4, v2);
    *((_WORD *)v4 + 736) &= ~(_WORD)v2;
    result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( result )
    {
      v8 = result;
      v9 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 154);
      if ( v9 )
      {
        v10 = v9;
        v22 = *(_DWORD *)(v5 - 892);
        if ( !(unsigned int)nla_put(v8, 1, 4, &v22) )
        {
          v22 = *(_DWORD *)(v3 + 224);
          if ( !(unsigned int)nla_put(v8, 3, 4, &v22) )
          {
            v11 = *(_QWORD *)(v8 + 216);
            v12 = *(unsigned int *)(v8 + 208);
            if ( (nla_put(v8, 33080, 0, 0) & 0x80000000) == 0 )
            {
              v13 = (_WORD *)(v11 + v12);
              if ( v13 )
              {
                while ( 1 )
                {
                  v14 = *(_QWORD *)(v8 + 216);
                  v15 = *(unsigned int *)(v8 + 208);
                  v16 = __clz(__rbit32(v2));
                  if ( (nla_put(v8, (unsigned __int16)(v16 - 0x7FFF), 0, 0) & 0x80000000) != 0 )
                    break;
                  v17 = (_WORD *)(v14 + v15);
                  if ( !v17 )
                    break;
                  LOBYTE(v22) = v16;
                  if ( (unsigned int)nla_put(v8, 313, 1, &v22) )
                    break;
                  v2 &= ~(1 << v16);
                  *v17 = *(_WORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (_WORD)v17;
                  if ( !(_WORD)v2 )
                  {
                    *v13 = *(_DWORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (_WORD)v13;
                    *(_DWORD *)(v10 - 20) = *(_DWORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (v10 - 20);
                    result = genlmsg_multicast_netns(*(_QWORD *)(v5 + 1352), v8, 3u, 0xCC0u);
                    goto LABEL_16;
                  }
                }
              }
            }
          }
        }
        v9 = 0;
      }
      result = sk_skb_reason_drop(v9, v8, 2);
    }
  }
  else
  {
    __break(0x800u);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
