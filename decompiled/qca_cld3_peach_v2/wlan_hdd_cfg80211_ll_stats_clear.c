double __fastcall wlan_hdd_cfg80211_ll_stats_clear(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 v9; // x0
  double result; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  const char *v44; // x2
  unsigned int v45; // w1
  __int64 v46; // x4
  unsigned int v47; // w21
  unsigned int v48; // w20
  unsigned int v49; // w0
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x19
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // [xsp+0h] [xbp-50h] BYREF
  __int64 v69; // [xsp+8h] [xbp-48h] BYREF
  __int64 v70; // [xsp+10h] [xbp-40h]
  unsigned int v71; // [xsp+1Ch] [xbp-34h] BYREF
  __int64 v72; // [xsp+20h] [xbp-30h] BYREF
  __int64 v73; // [xsp+28h] [xbp-28h]
  __int64 v74; // [xsp+30h] [xbp-20h]
  __int64 v75; // [xsp+38h] [xbp-18h]
  __int64 v76; // [xsp+40h] [xbp-10h]
  __int64 v77; // [xsp+48h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v68 = 0;
  v9 = _osif_vdev_sync_op_start(v8, &v68, "wlan_hdd_cfg80211_ll_stats_clear");
  if ( (_DWORD)v9 )
    goto LABEL_18;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v75 = 0;
    v76 = 0;
    v73 = 0;
    v74 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      result,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_ll_stats_clear",
      v18 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_ll_stats_clear");
LABEL_17:
      _osif_vdev_sync_op_stop(v68, "wlan_hdd_cfg80211_ll_stats_clear");
LABEL_18:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (unsigned int)_wlan_hdd_validate_context(
                         a1 + 1536,
                         (__int64)"__wlan_hdd_cfg80211_ll_stats_clear",
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26) )
      goto LABEL_17;
    if ( (*(_BYTE *)(v18 + 44768) & 1) != 0 )
    {
      if ( (unsigned int)_nla_parse(&v72, 4, a3, a4, &qca_wlan_vendor_ll_clr_policy, 31, 0) )
      {
        v43 = "%s: STATS_CLR_MAX is not present";
LABEL_16:
        qdf_trace_msg(0x33u, 2u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "__wlan_hdd_cfg80211_ll_stats_clear");
        goto LABEL_17;
      }
      if ( !v73 || !v74 )
      {
        v43 = "%s: Error in LL_STATS CLR CONFIG PARA";
        goto LABEL_16;
      }
      v47 = *(_DWORD *)(v73 + 4);
      LODWORD(v70) = v47;
      v48 = *(unsigned __int8 *)(v74 + 4);
      LODWORD(v69) = 1;
      BYTE4(v70) = v48;
      BYTE4(v69) = *(_BYTE *)(*(_QWORD *)(v18 + 55520) + 8LL);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: LL_STATS_CLEAR reqId = %d, staId = %d, statsClearReqMask = 0x%X, stopReq = %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "__wlan_hdd_cfg80211_ll_stats_clear",
        1,
        BYTE4(v69),
        v47,
        v48);
      v49 = sme_ll_stats_clear_req(*(_QWORD *)(a1 + 1552), &v69);
      if ( !v49 )
      {
        v50 = _cfg80211_alloc_reply_skb(a1, 103, 197, 40);
        if ( v50 )
        {
          v59 = v50;
          v71 = v47;
          if ( (unsigned int)nla_put(v50, 3, 4, &v71) || (v71 = v48, (unsigned int)nla_put(v59, 4, 4, &v71)) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: LL_STATS_CLR put fail",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "__wlan_hdd_cfg80211_ll_stats_clear");
            sk_skb_reason_drop(0, v59, 2);
          }
          else
          {
            if ( v48 == 1 )
              *(_BYTE *)(v18 + 44768) = 0;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "__wlan_hdd_cfg80211_ll_stats_clear");
            cfg80211_vendor_cmd_reply(v59);
          }
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: skb allocation failed",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "__wlan_hdd_cfg80211_ll_stats_clear");
        }
        goto LABEL_17;
      }
      v46 = v49;
      v44 = "%s: stats clear request failed, %d";
      v45 = 2;
    }
    else
    {
      v44 = "%s: is_link_layer_stats_set : %d";
      v45 = 3;
      v46 = 0;
    }
    qdf_trace_msg(0x33u, v45, v44, v27, v28, v29, v30, v31, v32, v33, v34, "__wlan_hdd_cfg80211_ll_stats_clear", v46);
    goto LABEL_17;
  }
  __break(0x800u);
  return wlan_hdd_clear_link_layer_stats(v9);
}
