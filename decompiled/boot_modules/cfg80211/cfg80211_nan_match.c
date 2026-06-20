_QWORD *__fastcall cfg80211_nan_match(_QWORD *result, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x12
  __int64 v5; // x24
  __int64 v6; // x21
  _QWORD *v7; // x22
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x8
  __int64 v13; // x25
  __int64 v14; // x26
  _WORD *v15; // x25
  __int64 v16; // x26
  __int64 v17; // x27
  _WORD *v18; // x26
  __int64 v19; // x26
  __int64 v20; // x27
  _WORD *v21; // x26
  __int64 v22; // x3
  __int64 v23; // x2
  __int64 v24; // x0
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *result;
  if ( *result )
  {
    if ( !*(_BYTE *)(a2 + 4) || !*(_BYTE *)(a2 + 5) || !*(_QWORD *)(a2 + 8) )
    {
      __break(0x800u);
      goto LABEL_11;
    }
    v5 = a2;
    v7 = result;
    result = (_QWORD *)_alloc_skb(3712, a3, 0, 0xFFFFFFFFLL);
    if ( !result )
    {
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v9 = (__int64)result;
    v10 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 120);
    if ( !v10 )
    {
LABEL_9:
      result = (_QWORD *)sk_skb_reason_drop(v10, v9, 2);
      goto LABEL_11;
    }
    v11 = v10;
    LODWORD(v25[0]) = *(_DWORD *)(v6 - 892);
    if ( (unsigned int)nla_put(v9, 1, 4, v25)
      || (v12 = v7[4]) != 0 && (LODWORD(v25[0]) = *(_DWORD *)(v12 + 224), (unsigned int)nla_put(v9, 3, 4, v25)) )
    {
LABEL_8:
      v10 = 0;
      goto LABEL_9;
    }
    if ( *v7 )
    {
      v25[0] = *((unsigned int *)v7 + 10) | ((unsigned __int64)*(unsigned int *)(*v7 - 892LL) << 32);
      if ( !(unsigned int)nla_put_64bit(v9, 153, 8, v25, 229) )
      {
        v25[0] = *(_QWORD *)(v5 + 32);
        if ( !(unsigned int)nla_put_64bit(v9, 88, 8, v25, 229) && !(unsigned int)nla_put(v9, 6, 6, *(_QWORD *)(v5 + 8)) )
        {
          v13 = *(_QWORD *)(v9 + 216);
          v14 = *(unsigned int *)(v9 + 208);
          if ( (nla_put(v9, 241, 0, 0) & 0x80000000) == 0 )
          {
            v15 = (_WORD *)(v13 + v14);
            if ( v15 )
            {
              v16 = *(_QWORD *)(v9 + 216);
              v17 = *(unsigned int *)(v9 + 208);
              if ( (nla_put(v9, 1, 0, 0) & 0x80000000) == 0 )
              {
                v18 = (_WORD *)(v16 + v17);
                if ( v18 )
                {
                  LOBYTE(v25[0]) = *(_BYTE *)(v5 + 4);
                  if ( !(unsigned int)nla_put(v9, 15, 1, v25) )
                  {
                    *v18 = *(_WORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v18;
                    v19 = *(_QWORD *)(v9 + 216);
                    v20 = *(unsigned int *)(v9 + 208);
                    if ( (nla_put(v9, 2, 0, 0) & 0x80000000) == 0 )
                    {
                      v21 = (_WORD *)(v19 + v20);
                      if ( v21 )
                      {
                        LOBYTE(v25[0]) = *(_DWORD *)v5;
                        if ( !(unsigned int)nla_put(v9, 1, 1, v25) )
                        {
                          LOBYTE(v25[0]) = *(_BYTE *)(v5 + 5);
                          if ( !(unsigned int)nla_put(v9, 15, 1, v25) )
                          {
                            v22 = *(_QWORD *)(v5 + 24);
                            if ( !v22
                              || !*(_BYTE *)(v5 + 16)
                              || !(unsigned int)nla_put(v9, 11, *(unsigned __int8 *)(v5 + 16), v22) )
                            {
                              *v21 = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v21;
                              *v15 = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v15;
                              *(_DWORD *)(v11 - 20) = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (v11 - 20);
                              v23 = *((unsigned int *)v7 + 44);
                              v24 = *(_QWORD *)(v6 + 1352);
                              if ( (_DWORD)v23 )
                                result = (_QWORD *)netlink_unicast(*(_QWORD *)(v24 + 288), v9, v23, 64);
                              else
                                result = (_QWORD *)genlmsg_multicast_netns(v24, v9, 5u, a3);
                              goto LABEL_11;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto LABEL_8;
    }
  }
  else
  {
    __break(0x800u);
  }
  __break(0x800u);
  *(_QWORD *)v5 = v4;
  *(_QWORD *)(v5 + 8) = a4;
  return (_QWORD *)cfg80211_nan_func_terminated();
}
