double __fastcall wlan_hdd_cfg80211_get_he_cap(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  double result; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char is_feature_supported_by_fw; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w21
  unsigned int v38; // w22
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x19
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
  __int64 v65; // [xsp+8h] [xbp-58h] BYREF
  int v66; // [xsp+14h] [xbp-4Ch] BYREF
  __int64 v67; // [xsp+18h] [xbp-48h] BYREF
  __int64 v68; // [xsp+20h] [xbp-40h]
  __int64 v69; // [xsp+28h] [xbp-38h]
  _QWORD v70[4]; // [xsp+30h] [xbp-30h] BYREF
  int v71; // [xsp+50h] [xbp-10h]
  __int64 v72; // [xsp+58h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 488);
  v65 = 0;
  v3 = _osif_psoc_sync_op_start(v2, &v65, (__int64)"wlan_hdd_cfg80211_get_he_cap");
  if ( (_DWORD)v3 )
    goto LABEL_15;
  if ( a1 )
  {
    v71 = 0;
    memset(v70, 0, sizeof(v70));
    v68 = 0;
    v69 = 0;
    v67 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", result, v5, v6, v7, v8, v9, v10, v11, "__wlan_hdd_cfg80211_get_he_cap");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__wlan_hdd_cfg80211_get_he_cap");
    }
    else if ( !(unsigned int)_wlan_hdd_validate_context(
                               a1 + 1536,
                               (__int64)"__wlan_hdd_cfg80211_get_he_cap",
                               v12,
                               v13,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19) )
    {
      is_feature_supported_by_fw = sme_is_feature_supported_by_fw(13);
      if ( (is_feature_supported_by_fw & 1) != 0 )
      {
        if ( (unsigned int)wma_get_he_capabilities(&v67) )
          goto LABEL_14;
        v37 = 1;
        v38 = 105;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: 11AX: HE not supported, send only QCA_WLAN_VENDOR_ATTR_HE_SUPPORTED",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "__wlan_hdd_cfg80211_get_he_cap");
        v37 = 0;
        v38 = 21;
      }
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: 11AX: he_supported: %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "__wlan_hdd_cfg80211_get_he_cap",
        v37);
      v39 = _cfg80211_alloc_reply_skb(a1, 103, 197, v38);
      if ( v39 )
      {
        v48 = v39;
        LOBYTE(v66) = v37;
        if ( (unsigned int)nla_put(v39, 1, 1, &v66)
          || (is_feature_supported_by_fw & 1) != 0
          && ((v66 = HIDWORD(v68), (unsigned int)nla_put(v48, 3, 4, &v66))
           || (v66 = v69, (unsigned int)nla_put(v48, 4, 4, &v66))
           || (v66 = HIDWORD(v69), (unsigned int)nla_put(v48, 5, 4, &v66))
           || (v66 = v70[0], (unsigned int)nla_put(v48, 6, 4, &v66))
           || (unsigned int)nla_put(v48, 2, 12, &v67)
           || (unsigned int)nla_put(v48, 7, 32, (char *)v70 + 4)) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nla put fail",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "__wlan_hdd_cfg80211_get_he_cap");
          sk_skb_reason_drop(0, v48, 2);
        }
        else
        {
          cfg80211_vendor_cmd_reply(v48);
          qdf_trace_msg(0x33u, 8u, "%s: exit", v57, v58, v59, v60, v61, v62, v63, v64, "__wlan_hdd_cfg80211_get_he_cap");
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Allocate reply_skb failed",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "__wlan_hdd_cfg80211_get_he_cap");
      }
    }
LABEL_14:
    _osif_psoc_sync_op_stop(v65, (__int64)"wlan_hdd_cfg80211_get_he_cap");
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return hdd_sr_register_callbacks(v3);
}
