__int64 __fastcall hdd_sar_send_response(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int v13; // w8
  int v14; // w0
  unsigned int v15; // w20
  __int64 result; // x0
  __int64 v17; // x21
  __int64 v18; // x22
  int v19; // w8
  _WORD *v20; // x21
  __int64 v21; // x22
  __int64 v22; // x23
  int v23; // w8
  _WORD *v24; // x22
  _DWORD *v25; // x22
  unsigned int v26; // w23
  __int64 v27; // x24
  __int64 v28; // x25
  int v29; // w8
  _WORD *v30; // x24
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = _cfg80211_alloc_reply_skb(a1, 103, 197, (unsigned int)(36 * a2[1] + 36));
  if ( !v3 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_sar_send_response");
    result = 4294967284LL;
    goto LABEL_8;
  }
  v12 = v3;
  v13 = *a2 - 1;
  if ( v13 >= 8 )
    v13 = 5;
  v31 = v13;
  v14 = nla_put(v3, 1, 4, &v31);
  if ( !v14 )
  {
    v31 = a2[1];
    v14 = nla_put(v12, 2, 4, &v31);
    if ( !v14 )
    {
      v17 = *(_QWORD *)(v12 + 216);
      v18 = *(unsigned int *)(v12 + 208);
      v19 = nla_put(v12, 32771, 0, 0);
      v14 = -22;
      if ( (v19 & 0x80000000) == 0 )
      {
        v20 = (_WORD *)(v17 + v18);
        if ( v20 )
        {
          if ( !a2[1] )
            goto LABEL_27;
          v21 = *(_QWORD *)(v12 + 216);
          v22 = *(unsigned int *)(v12 + 208);
          v23 = nla_put(v12, 32771, 0, 0);
          v14 = -22;
          if ( (v23 & 0x80000000) == 0 )
          {
            v24 = (_WORD *)(v21 + v22);
            if ( v24 )
            {
              v31 = a2[2] == 1;
              v14 = nla_put(v12, 4, 4, &v31);
              if ( !v14 )
              {
                v31 = a2[3];
                v14 = nla_put(v12, 5, 4, &v31);
                if ( !v14 )
                {
                  v31 = a2[4] == 1;
                  v14 = nla_put(v12, 6, 4, &v31);
                  if ( !v14 )
                  {
                    v31 = a2[5];
                    v14 = nla_put(v12, 7, 4, &v31);
                    if ( !v14 )
                    {
                      *v24 = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (_WORD)v24;
                      if ( a2[1] >= 2u )
                      {
                        v25 = a2 + 6;
                        v26 = 1;
                        do
                        {
                          v27 = *(_QWORD *)(v12 + 216);
                          v28 = *(unsigned int *)(v12 + 208);
                          v29 = nla_put(v12, 32775, 0, 0);
                          v14 = -22;
                          if ( v29 < 0 )
                            goto LABEL_6;
                          v30 = (_WORD *)(v27 + v28);
                          if ( !v30 )
                            goto LABEL_6;
                          v31 = *v25 == 1;
                          v14 = nla_put(v12, 4, 4, &v31);
                          if ( v14 )
                            goto LABEL_6;
                          v31 = v25[1];
                          v14 = nla_put(v12, 5, 4, &v31);
                          if ( v14 )
                            goto LABEL_6;
                          v31 = v25[2] == 1;
                          v14 = nla_put(v12, 6, 4, &v31);
                          if ( v14 )
                            goto LABEL_6;
                          v31 = v25[3];
                          v14 = nla_put(v12, 7, 4, &v31);
                          if ( v14 )
                            goto LABEL_6;
                          ++v26;
                          v25 += 4;
                          *v30 = *(_DWORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (_WORD)v30;
                        }
                        while ( v26 < a2[1] );
                      }
LABEL_27:
                      *v20 = *(_WORD *)(v12 + 216) + *(_DWORD *)(v12 + 208) - (_WORD)v20;
                      result = cfg80211_vendor_cmd_reply(v12);
                      goto LABEL_8;
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
LABEL_6:
  v15 = v14;
  sk_skb_reason_drop(0, v12, 2);
  result = v15;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
