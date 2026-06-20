__int64 __fastcall wlan_cfg80211_spectral_scan_get_diag_stats(
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
  __int64 result; // x0
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 v22; // [xsp+0h] [xbp-70h] BYREF
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
  v23 = 0x2E00000000LL;
  v24 = 0;
  if ( (unsigned int)ucfg_spectral_control(a2, (unsigned int *)&v23, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    result = 4294967274LL;
  }
  else
  {
    v12 = _cfg80211_alloc_reply_skb(a1, 103, 197, 76);
    if ( v12 )
    {
      v21 = v12;
      v22 = v24;
      if ( (unsigned int)nla_put_64bit(v12, 1, 8, &v22, 229)
        || (v22 = v25, (unsigned int)nla_put_64bit(v21, 2, 8, &v22, 229))
        || (v22 = v26, (unsigned int)nla_put_64bit(v21, 3, 8, &v22, 229))
        || (v22 = v27, (unsigned int)nla_put_64bit(v21, 4, 8, &v22, 229))
        || (v22 = v28, (unsigned int)nla_put_64bit(v21, 5, 8, &v22, 229)) )
      {
        sk_skb_reason_drop(0, v21, 2);
        result = 4294967274LL;
      }
      else
      {
        cfg80211_vendor_cmd_reply(v21);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s:  reply skb alloc failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_cfg80211_spectral_scan_get_diag_stats");
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
