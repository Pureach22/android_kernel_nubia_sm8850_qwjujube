__int64 __fastcall wlan_cfg80211_spectral_scan_get_config(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  __int64 result; // x0
  unsigned int v19; // w21
  __int64 comp_private_obj; // x0
  __int64 v21; // x23
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  char nl80211_chwidth; // w22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+Ch] [xbp-184h] BYREF
  __int64 v50; // [xsp+10h] [xbp-180h] BYREF
  __int64 v51; // [xsp+18h] [xbp-178h]
  __int64 v52; // [xsp+20h] [xbp-170h]
  __int64 v53; // [xsp+28h] [xbp-168h]
  __int64 v54; // [xsp+30h] [xbp-160h]
  __int64 v55; // [xsp+38h] [xbp-158h]
  __int64 v56; // [xsp+40h] [xbp-150h]
  __int64 v57; // [xsp+48h] [xbp-148h]
  __int64 v58; // [xsp+50h] [xbp-140h]
  __int64 v59; // [xsp+58h] [xbp-138h]
  __int64 v60; // [xsp+60h] [xbp-130h]
  __int64 v61; // [xsp+68h] [xbp-128h]
  _QWORD s[36]; // [xsp+70h] [xbp-120h] BYREF

  s[35] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x118u);
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  if ( (unsigned int)_nla_parse(s, 34, a4, a5, &spectral_scan_policy, 31, 0) )
  {
    v17 = "%s: Invalid Spectral Scan config ATTR";
LABEL_3:
    qdf_trace_msg(0x48u, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "wlan_cfg80211_spectral_scan_get_config");
    goto LABEL_4;
  }
  if ( s[25] )
  {
    v19 = *(_DWORD *)(s[25] + 4LL);
    if ( v19 >= 2 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid spectral mode %u",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "convert_spectral_mode_nl_to_internal",
        v19);
      goto LABEL_4;
    }
  }
  else
  {
    v19 = 0;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a2, 0x13u);
  if ( !comp_private_obj )
  {
    v17 = "%s: PDEV SPECTRAL object is NULL!";
    goto LABEL_3;
  }
  v21 = comp_private_obj;
  v22 = _cfg80211_alloc_reply_skb(a1, 103, 197, 288);
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
      "wlan_cfg80211_spectral_scan_get_config");
    result = 4294967284LL;
    goto LABEL_5;
  }
  v31 = v22;
  LODWORD(v50) = v19;
  BYTE4(v50) = 31;
  ucfg_spectral_control(a2, (unsigned int *)&v50, v23, v24, v25, v26, v27, v28, v29, v30);
  nl80211_chwidth = wlan_cfg80211_get_nl80211_chwidth(WORD2(v59));
  v49 = HIWORD(v51);
  if ( !(unsigned int)nla_put(v31, 1, 4, &v49) )
  {
    v49 = WORD1(v51);
    if ( !(unsigned int)nla_put(v31, 2, 4, &v49) )
    {
      v49 = WORD2(v52);
      if ( !(unsigned int)nla_put(v31, 3, 4, &v49) )
      {
        v49 = HIWORD(v52);
        if ( !(unsigned int)nla_put(v31, 4, 4, &v49) )
        {
          v49 = (unsigned __int16)v53;
          if ( !(unsigned int)nla_put(v31, 5, 4, &v49) )
          {
            v49 = WORD1(v53);
            if ( !(unsigned int)nla_put(v31, 6, 4, &v49) )
            {
              v49 = WORD2(v53);
              if ( !(unsigned int)nla_put(v31, 7, 4, &v49) )
              {
                v49 = HIWORD(v53);
                if ( !(unsigned int)nla_put(v31, 8, 4, &v49) )
                {
                  v49 = (unsigned __int16)v54;
                  if ( !(unsigned int)nla_put(v31, 9, 4, &v49) )
                  {
                    v49 = WORD1(v54);
                    if ( !(unsigned int)nla_put(v31, 10, 4, &v49) )
                    {
                      v49 = WORD2(v54);
                      if ( !(unsigned int)nla_put(v31, 11, 4, &v49) )
                      {
                        v49 = HIWORD(v54);
                        if ( !(unsigned int)nla_put(v31, 12, 4, &v49) )
                        {
                          v49 = (unsigned __int16)v55;
                          if ( !(unsigned int)nla_put(v31, 13, 4, &v49) )
                          {
                            v49 = WORD1(v55);
                            if ( !(unsigned int)nla_put(v31, 14, 4, &v49) )
                            {
                              v49 = WORD2(v55);
                              if ( !(unsigned int)nla_put(v31, 15, 4, &v49) )
                              {
                                v49 = HIWORD(v55);
                                if ( !(unsigned int)nla_put(v31, 16, 4, &v49) )
                                {
                                  v49 = (unsigned __int16)v56;
                                  if ( !(unsigned int)nla_put(v31, 17, 4, &v49) )
                                  {
                                    v49 = WORD1(v56);
                                    if ( !(unsigned int)nla_put(v31, 18, 4, &v49) )
                                    {
                                      v49 = (unsigned __int16)v51;
                                      if ( !(unsigned int)nla_put(v31, 20, 4, &v49) )
                                      {
                                        v49 = (unsigned __int16)v52;
                                        if ( !(unsigned int)nla_put(v31, 21, 4, &v49) )
                                        {
                                          v49 = HIDWORD(v58);
                                          if ( !(unsigned int)nla_put(v31, 24, 4, &v49) )
                                          {
                                            v49 = v59;
                                            if ( !(unsigned int)nla_put(v31, 29, 4, &v49) )
                                            {
                                              LOBYTE(v49) = nl80211_chwidth;
                                              if ( !(unsigned int)nla_put(v31, 30, 1, &v49) )
                                              {
                                                v49 = WORD2(v51);
                                                if ( !(unsigned int)nla_put(v31, 31, 4, &v49) )
                                                {
                                                  if ( *(_DWORD *)(v21 + 52) >= 2u )
                                                  {
                                                    qdf_trace_msg(
                                                      0x48u,
                                                      2u,
                                                      "%s: Invalid Spectral transport mode %u",
                                                      v33,
                                                      v34,
                                                      v35,
                                                      v36,
                                                      v37,
                                                      v38,
                                                      v39,
                                                      v40,
                                                      "convert_to_spectral_data_transport_mode_internal_to_nl");
                                                  }
                                                  else
                                                  {
                                                    v49 = *(_DWORD *)(v21 + 52);
                                                    if ( !(unsigned int)nla_put(v31, 33, 4, &v49) )
                                                    {
                                                      v49 = HIDWORD(v60);
                                                      if ( !(unsigned int)nla_put(v31, 34, 4, &v49) )
                                                      {
                                                        LODWORD(v50) = v19;
                                                        BYTE4(v50) = 52;
                                                        ucfg_spectral_control(
                                                          a2,
                                                          (unsigned int *)&v50,
                                                          v41,
                                                          v42,
                                                          v43,
                                                          v44,
                                                          v45,
                                                          v46,
                                                          v47,
                                                          v48);
                                                        v49 = v51;
                                                        if ( !(unsigned int)nla_put(v31, 22, 4, &v49) )
                                                        {
                                                          cfg80211_vendor_cmd_reply(v31);
                                                          result = 0;
                                                          goto LABEL_5;
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
                }
              }
            }
          }
        }
      }
    }
  }
  sk_skb_reason_drop(0, v31, 2);
LABEL_4:
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
