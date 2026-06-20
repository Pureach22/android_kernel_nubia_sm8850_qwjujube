__int64 __fastcall wlan_hdd_cfg80211_stats_ext2_callback(
        __int64 a1,
        int *a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  __int64 v22; // x0
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x4
  const char *v33; // x2
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _wlan_hdd_validate_context(
             a1,
             (__int64)"wlan_hdd_cfg80211_stats_ext2_callback",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( (_DWORD)result )
    goto LABEL_12;
  if ( !a2 )
  {
    v33 = "%s: msg received here is null";
LABEL_8:
    result = qdf_trace_msg(
               0x33u,
               2u,
               v33,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wlan_hdd_cfg80211_stats_ext2_callback");
    goto LABEL_12;
  }
  v21 = 4 * *a2;
  v22 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 2, v21 + 36, 3264);
  if ( !v22 )
  {
    v33 = "%s: vendor_event_alloc failed for STATS_EXT2";
    goto LABEL_8;
  }
  v23 = v22;
  v34 = *a2;
  if ( (unsigned int)nla_put(v22, 34, 4, &v34) )
  {
    v32 = "QCA_WLAN_VENDOR_ATTR_RX_AGGREGATION_STATS_HOLES_NUM";
  }
  else
  {
    if ( !(unsigned int)nla_put(v23, 35, v21, a2 + 1) )
    {
      result = _cfg80211_send_event_skb(v23, 3264);
      goto LABEL_12;
    }
    v32 = "QCA_WLAN_VENDOR_ATTR_RX_AGGREGATION_STATS_HOLES_INFO";
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: %s put fail",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wlan_hdd_cfg80211_stats_ext2_callback",
    v32);
  result = sk_skb_reason_drop(0, v23, 2);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
