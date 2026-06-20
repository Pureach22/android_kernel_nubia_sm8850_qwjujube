__int64 __fastcall wlan_hdd_cfg80211_acs_ch_select_evt(__int64 *a1, __int64 a2)
{
  char v3; // w21
  __int64 v4; // x23
  __int64 *v5; // x24
  unsigned int v6; // w19
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  char v36; // w22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  char v45; // w21
  int v46; // w22
  char v47; // w8
  int v48; // w26
  __int64 vdev_by_user; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x21
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x27
  unsigned int v68; // w21
  unsigned int v69; // w23
  unsigned int v70; // w24
  int v71; // w28
  int v72; // w25
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // [xsp+18h] [xbp-28h]
  int v82; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v83; // [xsp+38h] [xbp-8h]

  v3 = a2;
  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *(__int64 **)(*a1 + 24);
  *((_DWORD *)a1 + 654) = 0;
  qdf_event_set((__int64)(a1 + 331), a2);
  if ( (sap_acs_is_puncture_applicable(a1 + 178) & 1) != 0 )
    v6 = 104;
  else
    v6 = 96;
  if ( (v3 & 1) != 0 && policy_mgr_is_vdev_ll_lt_sap(*v5, *((unsigned __int8 *)a1 + 8)) )
  {
    *((_DWORD *)a1 + 603) = *((_DWORD *)a1 + 497);
    a1[302] = qdf_get_time_of_the_day_ms();
  }
  v7 = _cfg80211_alloc_event_skb(v5[3], v4 + 112, 103, 197, 0, 11, v6, 3264);
  if ( v7 )
  {
    v16 = v7;
    v82 = *((_DWORD *)a1 + 497);
    if ( (unsigned int)nla_put(v7, 12, 4, &v82) )
    {
      v25 = "%s: VENDOR_ATTR_ACS_PRIMARY_FREQUENCY put fail";
    }
    else
    {
      v82 = *((_DWORD *)a1 + 498);
      if ( (unsigned int)nla_put(v16, 13, 4, &v82) )
      {
        v25 = "%s: VENDOR_ATTR_ACS_SECONDARY_FREQUENCY put fail";
      }
      else
      {
        v82 = *((_DWORD *)a1 + 499);
        if ( (unsigned int)nla_put(v16, 14, 4, &v82) )
        {
          v25 = "%s: VENDOR_ATTR_ACS_VHT_SEG0_CENTER_FREQUENCY put fail";
        }
        else
        {
          v82 = *((_DWORD *)a1 + 500);
          if ( !(unsigned int)nla_put(v16, 15, 4, &v82) )
          {
            v36 = wlan_reg_freq_to_chan(v5[1], *((_DWORD *)a1 + 497), v17, v18, v19, v20, v21, v22, v23, v24);
            v45 = wlan_reg_freq_to_chan(v5[1], *((_DWORD *)a1 + 498), v37, v38, v39, v40, v41, v42, v43, v44);
            LOBYTE(v82) = v36;
            if ( (unsigned int)nla_put(v16, 1, 1, &v82) )
            {
              v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_PRIMARY_CHANNEL put fail";
            }
            else
            {
              LOBYTE(v82) = v45;
              if ( (unsigned int)nla_put(v16, 2, 1, &v82) )
              {
                v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_SECONDARY_CHANNEL put fail";
              }
              else
              {
                LOBYTE(v82) = wlan_reg_freq_to_chan(
                                v5[1],
                                *((_DWORD *)a1 + 499),
                                v27,
                                v28,
                                v29,
                                v30,
                                v31,
                                v32,
                                v33,
                                v34);
                if ( (unsigned int)nla_put(v16, 9, 1, &v82) )
                {
                  v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG0_CENTER_CHANNEL put fail";
                }
                else
                {
                  LOBYTE(v82) = wlan_reg_freq_to_chan(
                                  v5[1],
                                  *((_DWORD *)a1 + 500),
                                  v27,
                                  v28,
                                  v29,
                                  v30,
                                  v31,
                                  v32,
                                  v33,
                                  v34);
                  if ( (unsigned int)nla_put(v16, 10, 1, &v82) )
                  {
                    v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG1_CENTER_CHANNEL put fail";
                  }
                  else
                  {
                    if ( (unsigned int)*((unsigned __int16 *)a1 + 733) - 1 > 6 )
                      v46 = 20;
                    else
                      v46 = word_AF7464[(unsigned __int16)(*((_WORD *)a1 + 733) - 1)];
                    LOWORD(v82) = v46;
                    if ( (unsigned int)nla_put(v16, 7, 2, &v82) )
                    {
                      v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_CHWIDTH put fail";
                    }
                    else
                    {
                      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a1 + 497)) )
                        v47 = 1;
                      else
                        v47 = 2;
                      LOBYTE(v82) = v47;
                      if ( (unsigned int)nla_put(v16, 3, 1, &v82) )
                      {
                        v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_HW_MODE put fail";
                      }
                      else
                      {
                        if ( (sap_acs_is_puncture_applicable(a1 + 178) & 1) != 0 )
                          v48 = *((unsigned __int16 *)a1 + 1005);
                        else
                          v48 = 0;
                        if ( (sap_acs_is_puncture_applicable(a1 + 178) & 1) == 0
                          || (LOWORD(v82) = v48, !(unsigned int)nla_put(v16, 18, 2, &v82)) )
                        {
                          vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_cfg80211_acs_ch_select_evt");
                          if ( vdev_by_user )
                          {
                            v58 = vdev_by_user;
                            if ( *(_DWORD *)(vdev_by_user + 16) != 1
                              || (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0
                              || (LOBYTE(v82) = *(_BYTE *)(v58 + 93), !(unsigned int)nla_put(v16, 21, 1, &v82)) )
                            {
                              _hdd_objmgr_put_vdev_by_user(v58, 6, "wlan_hdd_cfg80211_acs_ch_select_evt");
                              v67 = *(_QWORD *)(v4 + 32);
                              v68 = *((unsigned __int8 *)a1 + 8);
                              v69 = *((_DWORD *)a1 + 497);
                              v70 = *((_DWORD *)a1 + 498);
                              v71 = *((_DWORD *)a1 + 499);
                              v72 = *((_DWORD *)a1 + 500);
                              v81 = sap_acs_is_puncture_applicable(a1 + 178) & 1;
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: ACS result for %s: vdev_id: %d PRI_CH_FREQ: %d SEC_CH_FREQ: %d VHT_SEG0: %d VHT_SEG1"
                                ": %d ACS_BW: %d punc support: %d punc bitmap: %d",
                                v73,
                                v74,
                                v75,
                                v76,
                                v77,
                                v78,
                                v79,
                                v80,
                                "wlan_hdd_cfg80211_acs_ch_select_evt",
                                v67 + 296,
                                v68,
                                v69,
                                v70,
                                v71,
                                v72,
                                v46,
                                v81,
                                v48);
                              result = _cfg80211_send_event_skb(v16, 3264);
                              goto LABEL_20;
                            }
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: QCA_WLAN_VENDOR_ATTR_ACS_LINK_ID put fail",
                              v59,
                              v60,
                              v61,
                              v62,
                              v63,
                              v64,
                              v65,
                              v66,
                              "wlan_hdd_cfg80211_acs_ch_select_evt");
                            _hdd_objmgr_put_vdev_by_user(v58, 6, "wlan_hdd_cfg80211_acs_ch_select_evt");
                          }
                          else
                          {
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: Null vdev[%u]. QCA_WLAN_VENDOR_ATTR_ACS_LINK_ID put fail",
                              v50,
                              v51,
                              v52,
                              v53,
                              v54,
                              v55,
                              v56,
                              v57,
                              "wlan_hdd_cfg80211_acs_ch_select_evt",
                              *((unsigned __int8 *)a1 + 8));
                          }
                          goto LABEL_19;
                        }
                        v35 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_PUNCTURE_BITMAP put fail";
                      }
                    }
                  }
                }
              }
            }
LABEL_18:
            qdf_trace_msg(0x33u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "wlan_hdd_cfg80211_acs_ch_select_evt");
LABEL_19:
            result = sk_skb_reason_drop(0, v16, 2);
            goto LABEL_20;
          }
          v25 = "%s: VENDOR_ATTR_ACS_VHT_SEG1_CENTER_FREQUENCY put fail";
        }
      }
    }
    qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_fill_acs_chan_freq");
    v35 = "%s: failed to put frequencies";
    goto LABEL_18;
  }
  result = qdf_trace_msg(
             0x33u,
             2u,
             "%s: wlan_cfg80211_vendor_event_alloc failed",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "wlan_hdd_cfg80211_acs_ch_select_evt");
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
