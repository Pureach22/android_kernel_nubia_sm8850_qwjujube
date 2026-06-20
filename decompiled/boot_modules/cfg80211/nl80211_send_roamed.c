__int64 __fastcall nl80211_send_roamed(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x23
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w10
  __int64 *v13; // x11
  __int64 v14; // x14
  int v15; // w13
  int v16; // w8
  __int64 result; // x0
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v20; // x25
  __int64 v21; // x3
  __int64 v22; // x3
  __int64 v23; // x3
  __int64 v24; // x3
  __int64 v25; // x23
  __int64 v26; // x24
  unsigned int v27; // w8
  unsigned int v28; // w26
  _QWORD *v29; // x27
  int v30; // w10
  bool v31; // w9
  __int64 v32; // x8
  __int64 v33; // x24
  __int64 v34; // x28
  int v35; // w23
  _WORD *v36; // x24
  __int64 v37; // x3
  bool v38; // cf
  _WORD *v39; // [xsp+0h] [xbp-20h]
  __int64 v40; // [xsp+8h] [xbp-18h]
  int v41; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a3 + 80);
  if ( v8 )
  {
LABEL_4:
    v10 = *(unsigned __int16 *)(a3 + 88);
    if ( *(_WORD *)(a3 + 88) )
      goto LABEL_5;
LABEL_18:
    v16 = 100;
    goto LABEL_19;
  }
  v9 = *(_QWORD *)(a3 + 120);
  if ( v9 )
  {
    v8 = v9 + 72;
    goto LABEL_4;
  }
  v8 = *(_QWORD *)(a3 + 104);
  v10 = *(unsigned __int16 *)(a3 + 88);
  if ( !*(_WORD *)(a3 + 88) )
    goto LABEL_18;
LABEL_5:
  v11 = 0;
  v12 = 0;
  v13 = (__int64 *)(a3 + 120);
  do
  {
    if ( ((v10 >> v11) & 1) != 0 )
    {
      if ( *(v13 - 3) )
        v15 = 12;
      else
        v15 = 0;
      if ( *(v13 - 2) || (v14 = *v13) != 0 )
        LODWORD(v14) = 12;
      v12 += v15 + 12 + v14;
    }
    ++v11;
    v13 += 4;
  }
  while ( v11 != 15 );
  v16 = v12 + 100;
LABEL_19:
  result = _alloc_skb(
             (v16
            + *(_DWORD *)(a3 + 8)
            + *(_DWORD *)(a3 + 24)
            + *(_DWORD *)(a3 + 40)
            + *(_DWORD *)(a3 + 64)
            + 16 * (*(_QWORD *)(a3 + 72) != 0)
            + 19)
           & 0xFFFFFFFC,
             a4,
             0,
             0xFFFFFFFFLL);
  if ( result )
  {
    v18 = result;
    v19 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 47);
    if ( v19 )
    {
      v20 = v19;
      v41 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v18, 1, 4, &v41) )
      {
        v41 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v18, 3, 4, &v41)
          && !(unsigned int)nla_put(v18, 6, 6, v8)
          && (!*(_QWORD *)a3 || !(unsigned int)nla_put(v18, 77, *(unsigned int *)(a3 + 8), *(_QWORD *)a3)) )
        {
          v21 = *(_QWORD *)(a3 + 16);
          if ( !v21 || !(unsigned int)nla_put(v18, 78, *(unsigned int *)(a3 + 24), v21) )
          {
            if ( *(_BYTE *)(a3 + 48) != 1
              || (LOWORD(v41) = *(_WORD *)(a3 + 50), !(unsigned int)nla_put(v18, 251, 2, &v41)) )
            {
              v22 = *(_QWORD *)(a3 + 32);
              if ( !v22 || !(unsigned int)nla_put(v18, 242, *(unsigned int *)(a3 + 40), v22) )
              {
                v23 = *(_QWORD *)(a3 + 56);
                if ( !v23 || !(unsigned int)nla_put(v18, 254, *(unsigned int *)(a3 + 64), v23) )
                {
                  v24 = *(_QWORD *)(a3 + 72);
                  if ( !v24 || !(unsigned int)nla_put(v18, 85, 16, v24) )
                  {
                    if ( !*(_WORD *)(a3 + 88) )
                    {
LABEL_60:
                      *(_DWORD *)(v20 - 20) = *(_DWORD *)(v18 + 216) + *(_DWORD *)(v18 + 208) - (v20 - 20);
                      result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v18, 3u, a4);
                      goto LABEL_26;
                    }
                    v25 = *(_QWORD *)(v18 + 216);
                    v26 = *(unsigned int *)(v18 + 208);
                    if ( (nla_put(v18, 33080, 0, 0) & 0x80000000) == 0 )
                    {
                      v39 = (_WORD *)(v25 + v26);
                      if ( v25 + v26 )
                      {
                        v27 = *(unsigned __int16 *)(a3 + 88);
                        v28 = 0;
                        v29 = (_QWORD *)(a3 + 120);
                        v30 = 1;
                        v31 = *(_WORD *)(a3 + 88) == 0;
                        do
                        {
                          if ( v31 || (((unsigned __int64)v27 >> v28) & 1) != 0 )
                          {
                            if ( *v29 )
                              v32 = *v29 + 72LL;
                            else
                              v32 = *(v29 - 2);
                            v33 = *(_QWORD *)(v18 + 216);
                            v34 = *(unsigned int *)(v18 + 208);
                            v40 = v32;
                            v35 = v30;
                            if ( (nla_put(v18, v30 | 0x8000u, 0, 0) & 0x80000000) != 0 )
                              goto LABEL_24;
                            v36 = (_WORD *)(v33 + v34);
                            if ( !v36 )
                              goto LABEL_24;
                            LOBYTE(v41) = v28;
                            if ( (unsigned int)nla_put(v18, 313, 1, &v41)
                              || v40 && (unsigned int)nla_put(v18, 245, 6, v40) )
                            {
                              goto LABEL_24;
                            }
                            v37 = *(v29 - 3);
                            if ( v37 )
                            {
                              if ( (unsigned int)nla_put(v18, 6, 6, v37) )
                                goto LABEL_24;
                            }
                            v30 = v35 + 1;
                            *v36 = *(_DWORD *)(v18 + 216) + *(_DWORD *)(v18 + 208) - (_WORD)v36;
                            v27 = *(unsigned __int16 *)(a3 + 88);
                          }
                          v31 = v27 == 0;
                          if ( !v27 )
                            break;
                          v38 = v28++ >= 0xE;
                          v29 += 4;
                        }
                        while ( !v38 );
                        *v39 = *(_WORD *)(v18 + 216) + *(_WORD *)(v18 + 208) - (_WORD)v39;
                        goto LABEL_60;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_24:
      v19 = 0;
    }
    result = sk_skb_reason_drop(v19, v18, 2);
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
