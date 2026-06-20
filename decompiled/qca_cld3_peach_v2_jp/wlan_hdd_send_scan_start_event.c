__int64 __fastcall wlan_hdd_send_scan_start_event(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x1
  __int64 result; // x0
  const char *v26; // x2
  unsigned int v27; // w20
  __int64 v28; // x0
  __int64 v29; // x21
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _cfg80211_alloc_reply_skb(a1, 103, 197, 28);
  if ( !v6 )
  {
    v26 = "%s:  reply skb alloc failed";
    goto LABEL_6;
  }
  v15 = v6;
  v30[0] = a3;
  if ( !(unsigned int)nla_put_64bit(v6, 7, 8, v30, 229) )
  {
    v27 = cfg80211_vendor_cmd_reply(v15);
    v28 = _cfg80211_alloc_event_skb(a1, a2, 103, 197, 0, 21, 28, 3264);
    if ( v28 )
    {
      v29 = v28;
      v30[0] = a3;
      if ( !(unsigned int)nla_put_64bit(v28, 7, 8, v30, 229) )
      {
        _cfg80211_send_event_skb(v29, 3264);
        result = v27;
        goto LABEL_7;
      }
      v24 = v29;
      goto LABEL_4;
    }
    v26 = "%s: skb alloc failed";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v26, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_hdd_send_scan_start_event");
    result = 4294967284LL;
    goto LABEL_7;
  }
  qdf_trace_msg(0x33u, 2u, "%s: nla put fail", v16, v17, v18, v19, v20, v21, v22, v23, "wlan_hdd_send_scan_start_event");
  v24 = v15;
LABEL_4:
  sk_skb_reason_drop(0, v24, 2);
  result = 4294967274LL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
