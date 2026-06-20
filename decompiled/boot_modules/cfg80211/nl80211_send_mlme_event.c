__int64 __fastcall nl80211_send_mlme_event(__int64 a1, __int64 a2, unsigned int *a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x24
  __int64 v12; // x3
  __int64 v13; // x23
  __int64 v14; // x25
  _WORD *v15; // x23
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb((a3[4] + a3[10] + 119) & 0xFFFFFFFC, a4, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v9 = result;
    v10 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, *a3);
    if ( v10 )
    {
      v11 = v10;
      v16 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v9, 1, 4, &v16) )
      {
        v16 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v9, 3, 4, &v16) && !(unsigned int)nla_put(v9, 51, a3[4], *((_QWORD *)a3 + 1)) )
        {
          v12 = *((_QWORD *)a3 + 4);
          if ( (!v12 || !(unsigned int)nla_put(v9, 77, a3[10], v12))
            && (*((_BYTE *)a3 + 48) != 1 || !(unsigned int)nla_put(v9, 299, 0, 0)) )
          {
            if ( (a3[6] & 0x80000000) != 0 )
            {
LABEL_18:
              *(_DWORD *)(v11 - 20) = *(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (v11 - 20);
              result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v9, 3u, a4);
              goto LABEL_8;
            }
            v13 = *(_QWORD *)(v9 + 216);
            v14 = *(unsigned int *)(v9 + 208);
            if ( (nla_put(v9, 129, 0, 0) & 0x80000000) == 0 )
            {
              v15 = (_WORD *)(v13 + v14);
              if ( v15 )
              {
                LOBYTE(v16) = a3[6];
                if ( !(unsigned int)nla_put(v9, 1, 1, &v16) )
                {
                  *v15 = *(_WORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v15;
                  goto LABEL_18;
                }
              }
            }
          }
        }
      }
      v10 = 0;
    }
    result = sk_skb_reason_drop(v10, v9, 2);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
