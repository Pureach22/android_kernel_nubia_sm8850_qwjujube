__int64 __fastcall wlan_cfg80211_spectral_scan_get_status(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  unsigned int v16; // w21
  int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x19
  __int64 v37; // [xsp+8h] [xbp-88h] BYREF
  __int64 v38; // [xsp+10h] [xbp-80h]
  __int64 v39; // [xsp+18h] [xbp-78h]
  __int64 v40; // [xsp+20h] [xbp-70h]
  __int64 v41; // [xsp+28h] [xbp-68h]
  __int64 v42; // [xsp+30h] [xbp-60h]
  __int64 v43; // [xsp+38h] [xbp-58h]
  __int64 v44; // [xsp+40h] [xbp-50h]
  __int64 v45; // [xsp+48h] [xbp-48h]
  __int64 v46; // [xsp+50h] [xbp-40h]
  __int64 v47; // [xsp+58h] [xbp-38h]
  __int64 v48; // [xsp+60h] [xbp-30h]
  _QWORD v49[3]; // [xsp+68h] [xbp-28h] BYREF
  __int64 v50; // [xsp+80h] [xbp-10h]
  __int64 v51; // [xsp+88h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  memset(v49, 0, sizeof(v49));
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  if ( (unsigned int)_nla_parse(v49, 3, a4, a5, &spectral_scan_get_status_policy, 31, 0) )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid Spectral Scan config ATTR",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_cfg80211_spectral_scan_get_status");
  }
  else
  {
    if ( v50 )
    {
      v16 = *(_DWORD *)(v50 + 4);
      if ( v16 >= 2 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid spectral mode %u",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "convert_spectral_mode_nl_to_internal",
          v16);
        goto LABEL_3;
      }
    }
    else
    {
      v16 = 0;
    }
    LODWORD(v37) = v16;
    BYTE4(v37) = 38;
    ucfg_spectral_control(a2, (unsigned int *)&v37, v7, v8, v9, v10, v11, v12, v13, v14);
    v17 = (unsigned __int8)v38;
    LODWORD(v37) = v16;
    BYTE4(v37) = 39;
    ucfg_spectral_control(a2, (unsigned int *)&v37, v18, v19, v20, v21, v22, v23, v24, v25);
    v26 = BYTE1(v38);
    v27 = _cfg80211_alloc_reply_skb(a1, 103, 197, 32);
    if ( !v27 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s:  reply skb alloc failed",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_cfg80211_spectral_scan_get_status");
      result = 4294967284LL;
      goto LABEL_4;
    }
    v36 = v27;
    if ( (!v26 || !(unsigned int)nla_put(v27, 1, 0, 0)) && (!v17 || !(unsigned int)nla_put(v36, 2, 0, 0)) )
    {
      cfg80211_vendor_cmd_reply(v36);
      result = 0;
      goto LABEL_4;
    }
    sk_skb_reason_drop(0, v36, 2);
  }
LABEL_3:
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
