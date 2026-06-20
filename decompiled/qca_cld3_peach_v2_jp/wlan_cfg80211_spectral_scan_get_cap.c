__int64 __fastcall wlan_cfg80211_spectral_scan_get_cap(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 result; // x0
  int v22; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-68h] BYREF
  __int64 v24; // [xsp+10h] [xbp-60h]
  __int64 v25; // [xsp+18h] [xbp-58h]
  __int64 v26; // [xsp+20h] [xbp-50h]
  __int64 v27; // [xsp+28h] [xbp-48h]
  __int64 v28; // [xsp+30h] [xbp-40h]
  __int64 v29; // [xsp+38h] [xbp-38h]
  __int64 v30; // [xsp+40h] [xbp-30h]
  __int64 v31; // [xsp+48h] [xbp-28h]
  __int64 v32; // [xsp+50h] [xbp-20h]
  __int64 v33; // [xsp+58h] [xbp-18h]
  __int64 v34; // [xsp+60h] [xbp-10h]
  __int64 v35; // [xsp+68h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0x2D00000000LL;
  v24 = 0;
  if ( !(unsigned int)ucfg_spectral_control(a2, (unsigned int *)&v23, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v11 = _cfg80211_alloc_reply_skb(a1, 103, 197, 176);
    if ( !v11 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s:  reply skb alloc failed",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_cfg80211_spectral_scan_get_cap");
      result = 4294967284LL;
      goto LABEL_14;
    }
    v20 = v11;
    if ( (!(_BYTE)v24 || !(unsigned int)nla_put(v11, 1, 0, 0))
      && (!BYTE1(v24) || !(unsigned int)nla_put(v20, 2, 0, 0))
      && (!BYTE2(v24) || !(unsigned int)nla_put(v20, 3, 0, 0))
      && (!BYTE3(v24) || !(unsigned int)nla_put(v20, 4, 0, 0)) )
    {
      v22 = HIDWORD(v24);
      if ( !(unsigned int)nla_put(v20, 5, 4, &v22) )
      {
        if ( (unsigned __int8)v25 != 1
          || (LOWORD(v22) = WORD1(v25), !(unsigned int)nla_put(v20, 6, 2, &v22))
          && (LOWORD(v22) = WORD2(v25), !(unsigned int)nla_put(v20, 7, 2, &v22))
          && (LOWORD(v22) = HIWORD(v25), !(unsigned int)nla_put(v20, 8, 2, &v22))
          && (LOWORD(v22) = v26, !(unsigned int)nla_put(v20, 9, 2, &v22))
          && (LOBYTE(v22) = BYTE2(v26), !(unsigned int)nla_put(v20, 10, 1, &v22)) )
        {
          if ( (BYTE3(v26) != 1 || !(unsigned int)nla_put(v20, 11, 0, 0))
            && (BYTE4(v26) != 1 || !(unsigned int)nla_put(v20, 12, 0, 0))
            && (BYTE5(v26) != 1 || !(unsigned int)nla_put(v20, 13, 0, 0))
            && (BYTE6(v26) != 1 || !(unsigned int)nla_put(v20, 19, 0, 0)) )
          {
            v22 = v27;
            if ( !(unsigned int)nla_put(v20, 14, 4, &v22) )
            {
              v22 = HIDWORD(v27);
              if ( !(unsigned int)nla_put(v20, 15, 4, &v22) )
              {
                v22 = v28;
                if ( !(unsigned int)nla_put(v20, 16, 4, &v22) )
                {
                  v22 = HIDWORD(v28);
                  if ( !(unsigned int)nla_put(v20, 17, 4, &v22) )
                  {
                    v22 = v29;
                    if ( !(unsigned int)nla_put(v20, 18, 4, &v22) )
                    {
                      v22 = HIDWORD(v29);
                      if ( !(unsigned int)nla_put(v20, 20, 4, &v22) )
                      {
                        cfg80211_vendor_cmd_reply(v20);
                        result = 0;
                        goto LABEL_14;
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
    sk_skb_reason_drop(0, v20, 2);
  }
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
