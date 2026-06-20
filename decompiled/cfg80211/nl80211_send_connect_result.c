__int64 __fastcall nl80211_send_connect_result(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x8
  __int64 v9; // x11
  __int64 *v10; // x12
  __int64 v11; // x15
  int v12; // w14
  int v13; // w10
  __int64 v14; // x24
  __int64 result; // x0
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x25
  int v19; // w8
  __int64 v20; // x3
  __int64 v21; // x3
  __int64 v22; // x23
  __int64 v23; // x24
  unsigned int v24; // w8
  unsigned int v25; // w26
  _WORD *v26; // x27
  int v27; // w10
  bool v28; // w9
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x24
  __int64 v32; // x28
  int v33; // w23
  _WORD *v34; // x24
  __int64 v35; // x3
  bool v36; // cf
  __int64 v37; // x3
  __int64 v38; // x3
  __int64 v39; // x3
  _WORD *v40; // [xsp+0h] [xbp-20h]
  __int64 v41; // [xsp+8h] [xbp-18h]
  int v42; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 96;
  if ( *(_WORD *)(a3 + 104) )
  {
    v9 = 0;
    v13 = 0;
    v10 = (__int64 *)(a3 + 128);
    do
    {
      if ( (((unsigned __int64)*(unsigned __int16 *)(a3 + 104) >> v9) & 1) != 0 )
      {
        if ( *(v10 - 2) )
          v12 = 12;
        else
          v12 = 0;
        if ( *(v10 - 1) || (v11 = *v10) != 0 )
          LODWORD(v11) = 12;
        v13 += v12 + v11 + 20;
      }
      ++v9;
      v10 += 4;
    }
    while ( v9 != 15 );
  }
  else
  {
    v8 = 120;
    v13 = 0;
  }
  v14 = *(_QWORD *)(a3 + v8);
  result = _alloc_skb(
             (v13
            + *(_DWORD *)(a3 + 16)
            + *(_DWORD *)(a3 + 32)
            + *(_DWORD *)(a3 + 48)
            + *(_DWORD *)(a3 + 72)
            + 16 * (*(_QWORD *)(a3 + 80) != 0)
            + 119)
           & 0xFFFFFFFC,
             a4,
             0,
             0xFFFFFFFFLL);
  if ( result )
  {
    v16 = result;
    v17 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 46);
    if ( v17 )
    {
      v18 = v17;
      v42 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v16, 1, 4, &v42) )
      {
        v42 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v16, 3, 4, &v42) && (!v14 || !(unsigned int)nla_put(v16, 6, 6, v14)) )
        {
          v19 = *(_DWORD *)a3;
          if ( *(int *)a3 < 0 )
            LOWORD(v19) = 1;
          LOWORD(v42) = v19;
          if ( !(unsigned int)nla_put(v16, 72, 2, &v42) )
          {
            if ( (*(_DWORD *)a3 & 0x80000000) == 0
              || !(unsigned int)nla_put(v16, 65, 0, 0)
              && (v42 = *(_DWORD *)(a3 + 88), !(unsigned int)nla_put(v16, 248, 4, &v42)) )
            {
              v20 = *(_QWORD *)(a3 + 8);
              if ( !v20 || !(unsigned int)nla_put(v16, 77, *(unsigned int *)(a3 + 16), v20) )
              {
                v21 = *(_QWORD *)(a3 + 24);
                if ( !v21 || !(unsigned int)nla_put(v16, 78, *(unsigned int *)(a3 + 32), v21) )
                {
                  if ( *(_BYTE *)(a3 + 56) != 1
                    || (LOWORD(v42) = *(_WORD *)(a3 + 58), !(unsigned int)nla_put(v16, 251, 2, &v42)) )
                  {
                    if ( *(_DWORD *)a3
                      || ((v37 = *(_QWORD *)(a3 + 40)) == 0
                       || !(unsigned int)nla_put(v16, 242, *(unsigned int *)(a3 + 48), v37))
                      && ((v38 = *(_QWORD *)(a3 + 64)) == 0
                       || !(unsigned int)nla_put(v16, 254, *(unsigned int *)(a3 + 72), v38))
                      && ((v39 = *(_QWORD *)(a3 + 80)) == 0 || !(unsigned int)nla_put(v16, 85, 16, v39)) )
                    {
                      if ( !*(_WORD *)(a3 + 104) )
                      {
LABEL_56:
                        *(_DWORD *)(v18 - 20) = *(_DWORD *)(v16 + 216) + *(_DWORD *)(v16 + 208) - (v18 - 20);
                        result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v16, 3u, a4);
                        goto LABEL_20;
                      }
                      v22 = *(_QWORD *)(v16 + 216);
                      v23 = *(unsigned int *)(v16 + 208);
                      if ( (nla_put(v16, 33080, 0, 0) & 0x80000000) == 0 )
                      {
                        v40 = (_WORD *)(v22 + v23);
                        if ( v22 + v23 )
                        {
                          v24 = *(unsigned __int16 *)(a3 + 104);
                          v25 = 0;
                          v26 = (_WORD *)(a3 + 136);
                          v27 = 1;
                          v28 = *(_WORD *)(a3 + 104) == 0;
                          do
                          {
                            if ( v28 || (((unsigned __int64)v24 >> v25) & 1) != 0 )
                            {
                              v29 = *((_QWORD *)v26 - 1);
                              if ( v29 )
                                v30 = v29 + 72;
                              else
                                v30 = *((_QWORD *)v26 - 2);
                              v31 = *(_QWORD *)(v16 + 216);
                              v32 = *(unsigned int *)(v16 + 208);
                              v41 = v30;
                              v33 = v27;
                              if ( (nla_put(v16, v27 | 0x8000u, 0, 0) & 0x80000000) != 0 )
                                goto LABEL_18;
                              v34 = (_WORD *)(v31 + v32);
                              if ( !v34 )
                                goto LABEL_18;
                              LOBYTE(v42) = v25;
                              if ( (unsigned int)nla_put(v16, 313, 1, &v42)
                                || v41 && (unsigned int)nla_put(v16, 245, 6, v41) )
                              {
                                goto LABEL_18;
                              }
                              v35 = *((_QWORD *)v26 - 3);
                              if ( v35 )
                              {
                                if ( (unsigned int)nla_put(v16, 6, 6, v35) )
                                  goto LABEL_18;
                              }
                              LOWORD(v42) = *v26;
                              if ( (unsigned int)nla_put(v16, 72, 2, &v42) )
                                goto LABEL_18;
                              v27 = v33 + 1;
                              *v34 = *(_DWORD *)(v16 + 216) + *(_DWORD *)(v16 + 208) - (_WORD)v34;
                              v24 = *(unsigned __int16 *)(a3 + 104);
                            }
                            v28 = v24 == 0;
                            if ( !v24 )
                              break;
                            v36 = v25++ >= 0xE;
                            v26 += 16;
                          }
                          while ( !v36 );
                          *v40 = *(_WORD *)(v16 + 216) + *(_WORD *)(v16 + 208) - (_WORD)v40;
                          goto LABEL_56;
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
LABEL_18:
      v17 = 0;
    }
    result = sk_skb_reason_drop(v17, v16, 2);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
