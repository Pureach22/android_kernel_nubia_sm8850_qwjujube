_QWORD *__fastcall cfg80211_nan_func_terminated(_QWORD *result, char a2, char a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  _QWORD *v10; // x21
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x26
  __int64 v15; // x8
  __int64 v16; // x24
  __int64 v17; // x27
  _WORD *v18; // x24
  __int64 v19; // x2
  __int64 v20; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *result;
  if ( !*result )
  {
    __break(0x800u);
    goto LABEL_23;
  }
  if ( !a2 )
  {
    __break(0x800u);
    goto LABEL_8;
  }
  v10 = result;
  result = (_QWORD *)_alloc_skb(3712, a5, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v12 = (__int64)result;
    v13 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 118);
    if ( !v13 )
    {
LABEL_7:
      result = (_QWORD *)sk_skb_reason_drop(v13, v12, 2);
      goto LABEL_8;
    }
    v14 = v13;
    LODWORD(v21[0]) = *(_DWORD *)(v6 - 892);
    if ( (unsigned int)nla_put(v12, 1, 4, v21)
      || (v15 = v10[4]) != 0 && (LODWORD(v21[0]) = *(_DWORD *)(v15 + 224), (unsigned int)nla_put(v12, 3, 4, v21)) )
    {
LABEL_6:
      v13 = 0;
      goto LABEL_7;
    }
    if ( *v10 )
    {
      v21[0] = *((unsigned int *)v10 + 10) | ((unsigned __int64)*(unsigned int *)(*v10 - 892LL) << 32);
      if ( !(unsigned int)nla_put_64bit(v12, 153, 8, v21, 229) )
      {
        v21[0] = a4;
        if ( !(unsigned int)nla_put_64bit(v12, 88, 8, v21, 229) )
        {
          v16 = *(_QWORD *)(v12 + 216);
          v17 = *(unsigned int *)(v12 + 208);
          if ( (nla_put(v12, 240, 0, 0) & 0x80000000) == 0 )
          {
            v18 = (_WORD *)(v16 + v17);
            if ( v18 )
            {
              LOBYTE(v21[0]) = a2;
              if ( !(unsigned int)nla_put(v12, 15, 1, v21) )
              {
                LOBYTE(v21[0]) = a3;
                if ( !(unsigned int)nla_put(v12, 16, 1, v21) )
                {
                  *v18 = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (_WORD)v18;
                  *(_DWORD *)(v14 - 20) = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (v14 - 20);
                  v19 = *((unsigned int *)v10 + 44);
                  v20 = *(_QWORD *)(v6 + 1352);
                  if ( (_DWORD)v19 )
                    result = (_QWORD *)netlink_unicast(*(_QWORD *)(v20 + 288), v12, v19, 64);
                  else
                    result = (_QWORD *)genlmsg_multicast_netns(v20, v12, 5u, a5);
                  goto LABEL_8;
                }
              }
            }
          }
        }
      }
      goto LABEL_6;
    }
LABEL_23:
    __break(0x800u);
    if ( !v5 )
      JUMPOUT(0x47D1C);
    JUMPOUT(0x430A4);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
