__int64 __fastcall wlan_hdd_cfg80211_acs_ch_select_evt(__int64 *a1, __int64 a2)
{
  char v3; // w19
  __int64 v4; // x23
  __int64 *v5; // x24
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  char v35; // w22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w21
  unsigned __int64 v45; // x8
  unsigned __int16 v46; // w22
  char v47; // w8
  __int64 vdev_by_user; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v66; // [xsp+38h] [xbp-8h]

  v3 = a2;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *(__int64 **)(*a1 + 24);
  *((_DWORD *)a1 + 586) = 0;
  qdf_event_set((__int64)(a1 + 297), a2);
  if ( (v3 & 1) != 0 && policy_mgr_is_vdev_ll_lt_sap(*v5, *((unsigned __int8 *)a1 + 8)) )
  {
    *((_DWORD *)a1 + 534) = *((_DWORD *)a1 + 495);
    a1[268] = qdf_get_time_of_the_day_ms();
  }
  v6 = _cfg80211_alloc_event_skb(v5[3], v4 + 112, 103, 197, 0, 11, 96, 3264);
  if ( v6 )
  {
    v15 = v6;
    v65 = *((_DWORD *)a1 + 495);
    if ( (unsigned int)nla_put(v6, 12, 4, &v65) )
    {
      v24 = "%s: VENDOR_ATTR_ACS_PRIMARY_FREQUENCY put fail";
    }
    else
    {
      v65 = *((_DWORD *)a1 + 496);
      if ( (unsigned int)nla_put(v15, 13, 4, &v65) )
      {
        v24 = "%s: VENDOR_ATTR_ACS_SECONDARY_FREQUENCY put fail";
      }
      else
      {
        v65 = *((_DWORD *)a1 + 497);
        if ( (unsigned int)nla_put(v15, 14, 4, &v65) )
        {
          v24 = "%s: VENDOR_ATTR_ACS_VHT_SEG0_CENTER_FREQUENCY put fail";
        }
        else
        {
          v65 = *((_DWORD *)a1 + 498);
          if ( !(unsigned int)nla_put(v15, 15, 4, &v65) )
          {
            v35 = wlan_reg_freq_to_chan(v5[1], *((_DWORD *)a1 + 495), v16, v17, v18, v19, v20, v21, v22, v23);
            v44 = wlan_reg_freq_to_chan(v5[1], *((_DWORD *)a1 + 496), v36, v37, v38, v39, v40, v41, v42, v43);
            LOBYTE(v65) = v35;
            if ( (unsigned int)nla_put(v15, 1, 1, &v65) )
            {
              v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_PRIMARY_CHANNEL put fail";
            }
            else
            {
              LOBYTE(v65) = v44;
              if ( (unsigned int)nla_put(v15, 2, 1, &v65) )
              {
                v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_SECONDARY_CHANNEL put fail";
              }
              else
              {
                LOBYTE(v65) = wlan_reg_freq_to_chan(
                                v5[1],
                                *((_DWORD *)a1 + 497),
                                v26,
                                v27,
                                v28,
                                v29,
                                v30,
                                v31,
                                v32,
                                v33);
                if ( (unsigned int)nla_put(v15, 9, 1, &v65) )
                {
                  v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG0_CENTER_CHANNEL put fail";
                }
                else
                {
                  LOBYTE(v65) = wlan_reg_freq_to_chan(
                                  v5[1],
                                  *((_DWORD *)a1 + 498),
                                  v26,
                                  v27,
                                  v28,
                                  v29,
                                  v30,
                                  v31,
                                  v32,
                                  v33);
                  if ( (unsigned int)nla_put(v15, 10, 1, &v65) )
                  {
                    v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_VHT_SEG1_CENTER_CHANNEL put fail";
                  }
                  else
                  {
                    v45 = *((unsigned __int16 *)a1 + 729);
                    if ( v45 >= 4 )
                      v46 = 20;
                    else
                      v46 = 0xA0005000280014uLL >> (16 * (unsigned __int8)v45);
                    LOWORD(v65) = v46;
                    if ( (unsigned int)nla_put(v15, 7, 2, &v65) )
                    {
                      v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_CHWIDTH put fail";
                    }
                    else
                    {
                      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a1 + 495)) )
                        v47 = 1;
                      else
                        v47 = 2;
                      LOBYTE(v65) = v47;
                      if ( !(unsigned int)nla_put(v15, 3, 1, &v65) )
                      {
                        vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_cfg80211_acs_ch_select_evt");
                        if ( vdev_by_user )
                        {
                          _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "wlan_hdd_cfg80211_acs_ch_select_evt");
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: ACS result for %s: vdev_id: %d PRI_CH_FREQ: %d SEC_CH_FREQ: %d VHT_SEG0: %d VHT_SEG1: %d"
                            " ACS_BW: %d punc support: %d punc bitmap: %d",
                            v57,
                            v58,
                            v59,
                            v60,
                            v61,
                            v62,
                            v63,
                            v64,
                            "wlan_hdd_cfg80211_acs_ch_select_evt",
                            *(_QWORD *)(v4 + 32) + 296LL,
                            *((unsigned __int8 *)a1 + 8),
                            *((unsigned int *)a1 + 495),
                            *((unsigned int *)a1 + 496),
                            *((_DWORD *)a1 + 497),
                            *((_DWORD *)a1 + 498),
                            v46,
                            0,
                            0);
                          result = _cfg80211_send_event_skb(v15, 3264);
                          goto LABEL_17;
                        }
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Null vdev[%u]. QCA_WLAN_VENDOR_ATTR_ACS_LINK_ID put fail",
                          v49,
                          v50,
                          v51,
                          v52,
                          v53,
                          v54,
                          v55,
                          v56,
                          "wlan_hdd_cfg80211_acs_ch_select_evt",
                          *((unsigned __int8 *)a1 + 8));
                        goto LABEL_16;
                      }
                      v34 = "%s: QCA_WLAN_VENDOR_ATTR_ACS_HW_MODE put fail";
                    }
                  }
                }
              }
            }
LABEL_15:
            qdf_trace_msg(0x33u, 2u, v34, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_hdd_cfg80211_acs_ch_select_evt");
LABEL_16:
            result = sk_skb_reason_drop(0, v15, 2);
            goto LABEL_17;
          }
          v24 = "%s: VENDOR_ATTR_ACS_VHT_SEG1_CENTER_FREQUENCY put fail";
        }
      }
    }
    qdf_trace_msg(0x33u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, "hdd_fill_acs_chan_freq");
    v34 = "%s: failed to put frequencies";
    goto LABEL_15;
  }
  result = qdf_trace_msg(
             0x33u,
             2u,
             "%s: wlan_cfg80211_vendor_event_alloc failed",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "wlan_hdd_cfg80211_acs_ch_select_evt");
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
