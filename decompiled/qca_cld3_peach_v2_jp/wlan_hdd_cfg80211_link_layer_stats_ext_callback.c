__int64 __fastcall wlan_hdd_cfg80211_link_layer_stats_ext_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  unsigned int v30; // w21
  __int64 v31; // x19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  const char *v41; // x3
  unsigned int v42; // w1
  const char *v43; // x2
  unsigned int v44; // w1
  __int64 v45; // x22
  __int64 v46; // x21
  __int64 v47; // x23
  _WORD *v48; // x23
  __int64 v49; // x24
  const char *v50; // x21
  unsigned int *v51; // x25
  __int64 v52; // x26
  __int64 v53; // x27
  _WORD *v54; // x26
  unsigned int v55; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_cfg80211_link_layer_stats_ext_callback");
  if ( !a2 )
  {
    v43 = "%s: Invalid result.";
    goto LABEL_10;
  }
  result = _wlan_hdd_validate_context(
             a1,
             (__int64)"wlan_hdd_cfg80211_link_layer_stats_ext_callback",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  if ( !(_DWORD)result )
  {
    if ( !hdd_get_link_info_by_vdev(a1, *((unsigned __int8 *)a2 + 4)) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: vdev_id %d does not exist with host.",
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 "wlan_hdd_cfg80211_link_layer_stats_ext_callback",
                 *((unsigned __int8 *)a2 + 4));
      goto LABEL_12;
    }
    v29 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 9, 4112, 3264);
    if ( v29 )
    {
      v30 = *a2;
      v31 = v29;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: LL_STATS RESP paramID = 0x%x, ifaceId = %u, result = %pK",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_hdd_cfg80211_link_layer_stats_ext_callback",
        *a2,
        *((unsigned __int8 *)a2 + 4),
        a2 + 7);
      if ( (v30 & 0x100) != 0 )
      {
        v45 = a2[7];
        if ( (_DWORD)v45 )
        {
          v55 = a2[7];
          if ( (unsigned int)nla_put(v31, 17, 4, &v55) )
          {
            v40 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
          }
          else
          {
            v46 = *(_QWORD *)(v31 + 216);
            v47 = *(unsigned int *)(v31 + 208);
            if ( (nla_put(v31, 32771, 0, 0) & 0x80000000) == 0 )
            {
              v48 = (_WORD *)(v46 + v47);
              if ( v48 )
              {
                v49 = 0;
                v50 = "%s: Invalid pointer to peer info.";
                v51 = a2 + 8;
                while ( 1 )
                {
                  v52 = *(_QWORD *)(v31 + 216);
                  v53 = *(unsigned int *)(v31 + 208);
                  if ( (nla_put(v31, (unsigned int)v49 | 0x8000, 0, 0) & 0x80000000) != 0 )
                    break;
                  v54 = (_WORD *)(v52 + v53);
                  if ( !v54 )
                    break;
                  if ( !v51 )
                    goto LABEL_42;
                  v55 = v51[4];
                  if ( (unsigned int)nla_put(v31, 7, 4, &v55) || (unsigned int)nla_put(v31, 8, 6, v51 + 1) )
                  {
                    v50 = "%s: QCA_WLAN_VENDOR_ATTR put fail.";
LABEL_42:
                    v41 = "hdd_populate_per_peer_ps_info";
                    v42 = 2;
                    v40 = v50;
                    goto LABEL_38;
                  }
                  ++v49;
                  v51 += 5;
                  *v54 = *(_WORD *)(v31 + 216) + *(_DWORD *)(v31 + 208) - (_WORD)v54;
                  if ( v45 == v49 )
                  {
                    *v48 = *(_WORD *)(v31 + 216) + *(_DWORD *)(v31 + 208) - (_WORD)v48;
                    goto LABEL_24;
                  }
                }
              }
            }
            v40 = "%s: nla_nest_start failed";
          }
        }
        else
        {
          v40 = "%s: Peer number is zero.";
        }
        v41 = "hdd_populate_wifi_peer_ps_info";
      }
      else
      {
        if ( (v30 & 0x200) == 0 )
        {
          if ( (v30 & 0x400) == 0 )
          {
            v40 = "%s: Unknown link layer stats";
            v41 = "wlan_hdd_cfg80211_link_layer_stats_ext_callback";
            v42 = 4;
LABEL_38:
            qdf_trace_msg(0x33u, v42, v40, v32, v33, v34, v35, v36, v37, v38, v39, v41);
            goto LABEL_39;
          }
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: MAC counters stats",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "wlan_hdd_cfg80211_link_layer_stats_ext_callback");
          if ( (unsigned int)hdd_populate_wifi_ll_ext_stats(a2 + 7, v31) )
          {
LABEL_39:
            sk_skb_reason_drop(0, v31, 2);
            goto LABEL_40;
          }
LABEL_24:
          _cfg80211_send_event_skb(v31, 3264);
LABEL_40:
          v43 = "%s: exit";
          v44 = 8;
          goto LABEL_11;
        }
        v55 = *((unsigned __int8 *)a2 + 28);
        if ( !(unsigned int)nla_put(v31, 4, 4, &v55) )
        {
          v55 = *((unsigned __int16 *)a2 + 15);
          if ( !(unsigned int)nla_put(v31, 5, 4, &v55) )
          {
            v55 = a2[8];
            if ( !(unsigned int)nla_put(v31, 6, 4, &v55) )
              goto LABEL_24;
          }
        }
        v40 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
        v41 = "hdd_populate_tx_failure_info";
      }
      v42 = 2;
      goto LABEL_38;
    }
    v43 = "%s: wlan_cfg80211_vendor_event_alloc failed.";
LABEL_10:
    v44 = 2;
LABEL_11:
    result = qdf_trace_msg(
               0x33u,
               v44,
               v43,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "wlan_hdd_cfg80211_link_layer_stats_ext_callback");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
