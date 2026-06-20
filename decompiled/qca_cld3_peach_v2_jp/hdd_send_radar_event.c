__int64 __fastcall hdd_send_radar_event(_QWORD *a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 *v4; // x20
  __int64 v5; // x21
  int v6; // w19
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 *)(*a1 + 112LL);
  v5 = *v4;
  v6 = cds_chan_to_freq(a3);
  if ( a2 == 14 )
  {
    a2 = 13;
  }
  else if ( a2 != 17 )
  {
    if ( a2 != 16 )
    {
LABEL_10:
      result = 16;
      goto LABEL_12;
    }
    a2 = 14;
  }
  v7 = _cfg80211_alloc_event_skb(v5, v4, 103, 197, 0, a2, 20, 3264);
  if ( !v7 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_cfg80211_vendor_event_alloc failed for %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_send_radar_event",
      a2);
    goto LABEL_10;
  }
  v16 = v7;
  v26 = v6;
  if ( (unsigned int)nla_put(v7, 38, 4, &v26) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NL80211_ATTR_WIPHY_FREQ put fail",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_send_radar_event");
    sk_skb_reason_drop(0, v16, 2);
    result = 16;
  }
  else
  {
    _cfg80211_send_event_skb(v16, 3264);
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
