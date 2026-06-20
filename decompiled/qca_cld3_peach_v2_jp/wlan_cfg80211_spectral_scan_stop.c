__int64 __fastcall wlan_cfg80211_spectral_scan_stop(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  unsigned int v18; // w4
  const char *v19; // x2
  const char *v20; // x3
  int v21; // w20
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  int v32; // [xsp+Ch] [xbp-184h] BYREF
  __int64 v33; // [xsp+10h] [xbp-180h] BYREF
  __int64 v34; // [xsp+18h] [xbp-178h]
  __int64 v35; // [xsp+20h] [xbp-170h]
  __int64 v36; // [xsp+28h] [xbp-168h]
  __int64 v37; // [xsp+30h] [xbp-160h]
  __int64 v38; // [xsp+38h] [xbp-158h]
  __int64 v39; // [xsp+40h] [xbp-150h]
  __int64 v40; // [xsp+48h] [xbp-148h]
  __int64 v41; // [xsp+50h] [xbp-140h]
  __int64 v42; // [xsp+58h] [xbp-138h]
  __int64 v43; // [xsp+60h] [xbp-130h]
  __int64 v44; // [xsp+68h] [xbp-128h]
  _QWORD s[36]; // [xsp+70h] [xbp-120h] BYREF

  s[35] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x118u);
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( !(unsigned int)_nla_parse(s, 34, a4, a5, &spectral_scan_policy, 31, 0) )
  {
    if ( s[25] )
    {
      v18 = *(_DWORD *)(s[25] + 4LL);
      if ( v18 >= 2 )
      {
        v19 = "%s: Invalid spectral mode %u";
        v20 = "convert_spectral_mode_nl_to_internal";
LABEL_8:
        qdf_trace_msg(0x48u, 2u, v19, v9, v10, v11, v12, v13, v14, v15, v16, v20);
        goto LABEL_3;
      }
    }
    else
    {
      v18 = 0;
    }
    LODWORD(v33) = v18;
    BYTE4(v33) = 36;
    result = ucfg_spectral_control(a2, (unsigned int *)&v33, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( !(_DWORD)result )
      goto LABEL_4;
    if ( (int)v34 <= 1 )
    {
      if ( !(_DWORD)v34 )
      {
        result = qdf_status_to_os_return(result);
        goto LABEL_4;
      }
      if ( (_DWORD)v34 == 1 )
      {
        v21 = 0;
        goto LABEL_21;
      }
    }
    else
    {
      switch ( (_DWORD)v34 )
      {
        case 2:
          v21 = 1;
          goto LABEL_21;
        case 3:
          v21 = 2;
          goto LABEL_21;
        case 4:
          v21 = 3;
LABEL_21:
          v22 = _cfg80211_alloc_reply_skb(a1, 103, 197, 24);
          if ( !v22 )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s:  reply skb alloc failed",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "wlan_cfg80211_spectral_scan_stop");
            result = 4294967284LL;
            goto LABEL_4;
          }
          v31 = v22;
          v32 = v21;
          if ( !(unsigned int)nla_put(v22, 26, 4, &v32) )
          {
            cfg80211_vendor_cmd_reply(v31);
            result = 0;
            goto LABEL_4;
          }
          sk_skb_reason_drop(0, v31, 2);
          goto LABEL_3;
      }
    }
    v19 = "%s: Invalid spectral error code %u";
    v20 = "convert_spectral_err_code_internal_to_nl";
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: Invalid Spectral Scan stop ATTR",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wlan_cfg80211_spectral_scan_stop");
LABEL_3:
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
