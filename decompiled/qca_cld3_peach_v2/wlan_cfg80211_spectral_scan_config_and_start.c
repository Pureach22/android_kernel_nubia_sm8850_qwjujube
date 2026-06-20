__int64 __fastcall wlan_cfg80211_spectral_scan_config_and_start(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  unsigned int v19; // w22
  int v20; // w8
  unsigned int v21; // w23
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  char v32; // w8
  unsigned int v33; // w0
  unsigned int v34; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  __int64 v44; // [xsp+8h] [xbp-1D8h] BYREF
  _QWORD v45[7]; // [xsp+10h] [xbp-1D0h] BYREF
  __int128 v46; // [xsp+48h] [xbp-198h]
  __int64 v47; // [xsp+58h] [xbp-188h]
  __int64 v48; // [xsp+60h] [xbp-180h] BYREF
  _QWORD v49[10]; // [xsp+68h] [xbp-178h] BYREF
  __int64 v50; // [xsp+B8h] [xbp-128h]
  _QWORD s[36]; // [xsp+C0h] [xbp-120h] BYREF

  s[35] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x118u);
  v47 = 0;
  v46 = 0u;
  memset(v45, 0, sizeof(v45));
  v50 = 0;
  memset(v49, 0, sizeof(v49));
  v48 = 0;
  if ( !(unsigned int)_nla_parse(s, 34, a4, a5, &spectral_scan_policy, 31, 0) )
  {
    v45[0] = -1;
    LOWORD(v45[1]) = -1;
    memset((char *)&v45[1] + 4, 255, 32);
    *(_QWORD *)((char *)&v46 + 4) = 0xFFFF0000FFFFLL;
    WORD6(v46) = -1;
    HIDWORD(v47) = 0xFFFF;
    if ( s[1] )
      HIWORD(v45[0]) = *(_DWORD *)(s[1] + 4LL);
    if ( s[2] )
      WORD1(v45[0]) = *(_DWORD *)(s[2] + 4LL);
    if ( s[31] )
      WORD2(v45[0]) = *(_DWORD *)(s[31] + 4LL);
    if ( s[3] )
      WORD2(v45[1]) = *(_DWORD *)(s[3] + 4LL);
    if ( s[4] )
      HIWORD(v45[1]) = *(_DWORD *)(s[4] + 4LL);
    if ( s[5] )
      LOWORD(v45[2]) = *(_DWORD *)(s[5] + 4LL);
    if ( s[6] )
      WORD1(v45[2]) = *(_DWORD *)(s[6] + 4LL);
    if ( s[7] )
      WORD2(v45[2]) = *(_DWORD *)(s[7] + 4LL);
    if ( s[8] )
      HIWORD(v45[2]) = *(_DWORD *)(s[8] + 4LL);
    if ( s[9] )
      LOWORD(v45[3]) = *(_DWORD *)(s[9] + 4LL);
    if ( s[10] )
      WORD1(v45[3]) = *(_DWORD *)(s[10] + 4LL);
    if ( s[11] )
      WORD2(v45[3]) = *(_DWORD *)(s[11] + 4LL);
    if ( s[12] )
      HIWORD(v45[3]) = *(_DWORD *)(s[12] + 4LL);
    if ( s[13] )
      LOWORD(v45[4]) = *(_DWORD *)(s[13] + 4LL);
    if ( s[14] )
      WORD1(v45[4]) = *(_DWORD *)(s[14] + 4LL);
    if ( s[15] )
      WORD2(v45[4]) = *(_DWORD *)(s[15] + 4LL);
    if ( s[16] )
      HIWORD(v45[4]) = *(_DWORD *)(s[16] + 4LL);
    if ( s[17] )
      LOWORD(v45[5]) = *(_DWORD *)(s[17] + 4LL);
    if ( s[18] )
      WORD1(v45[5]) = *(_DWORD *)(s[18] + 4LL);
    if ( s[20] )
      LOWORD(v45[0]) = *(_DWORD *)(s[20] + 4LL);
    if ( s[21] )
      LOWORD(v45[1]) = *(_DWORD *)(s[21] + 4LL);
    if ( s[24] )
      DWORD1(v46) = *(_DWORD *)(s[24] + 4LL);
    DWORD2(v46) = 0;
    if ( s[29] )
      DWORD2(v46) = *(_DWORD *)(s[29] + 4LL);
    if ( s[30] )
      WORD6(v46) = wlan_cfg80211_get_phy_ch_width(*(unsigned __int8 *)(s[30] + 4LL));
    if ( s[25] )
    {
      v19 = *(_DWORD *)(s[25] + 4LL);
      if ( v19 >= 2 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid spectral mode %u",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "convert_spectral_mode_nl_to_internal",
          v19);
        goto LABEL_3;
      }
    }
    else
    {
      v19 = 0;
    }
    if ( s[34] )
      HIDWORD(v47) = *(_DWORD *)(s[34] + 4LL);
    if ( s[22] )
    {
      v20 = *(_DWORD *)(s[22] + 4LL);
      LODWORD(v48) = v19;
      LODWORD(v49[0]) = v20;
      BYTE4(v48) = 37;
      if ( (unsigned int)ucfg_spectral_control(a2, (unsigned int *)&v48, v10, v11, v12, v13, v14, v15, v16, v17) )
        goto LABEL_3;
    }
    if ( s[23] )
      v21 = *(_DWORD *)(s[23] + 4LL);
    else
      v21 = 0;
    v22 = _cfg80211_alloc_reply_skb(a1, 103, 197, 36);
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
        "wlan_cfg80211_spectral_scan_config_and_start");
      result = 4294967284LL;
      goto LABEL_4;
    }
    v31 = v22;
    if ( a3 )
      v32 = *(_BYTE *)(a3 + 168);
    else
      v32 = -1;
    BYTE5(v48) = v32;
    if ( (v21 & 0xFFFFFFFD) == 0 )
    {
      BYTE4(v48) = 30;
      LODWORD(v48) = v19;
      qdf_mem_copy(v49, v45, 0x50u);
      v43 = ucfg_spectral_control(a2, (unsigned int *)&v48, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( v43 )
      {
        v34 = v43;
        if ( !(_DWORD)v50 )
          goto LABEL_81;
        if ( (unsigned int)convert_spectral_err_code_internal_to_nl() )
          goto LABEL_80;
        v34 = 4;
        LODWORD(v44) = 0;
        if ( (unsigned int)nla_put(v31, 26, 4, &v44) )
          goto LABEL_81;
      }
    }
    if ( v21 > 1 )
      goto LABEL_75;
    LODWORD(v48) = v19;
    BYTE4(v48) = 35;
    v33 = ucfg_spectral_control(a2, (unsigned int *)&v48, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( !v33 )
      goto LABEL_75;
    v34 = v33;
    if ( LODWORD(v49[0]) )
    {
      if ( (unsigned int)convert_spectral_err_code_internal_to_nl() )
      {
LABEL_80:
        v34 = 4;
        goto LABEL_81;
      }
      v34 = 4;
      LODWORD(v44) = 0;
      if ( !(unsigned int)nla_put(v31, 26, 4, &v44) )
      {
LABEL_75:
        v44 = 0;
        if ( !(unsigned int)nla_put_64bit(v31, 19, 8, &v44, 229) )
        {
          cfg80211_vendor_cmd_reply(v31);
          result = 0;
          goto LABEL_4;
        }
        goto LABEL_80;
      }
    }
LABEL_81:
    sk_skb_reason_drop(0, v31, 2);
    result = qdf_status_to_os_return(v34);
    goto LABEL_4;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: Invalid Spectral Scan config ATTR",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_cfg80211_spectral_scan_config_and_start");
LABEL_3:
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
