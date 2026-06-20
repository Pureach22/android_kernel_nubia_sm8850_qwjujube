__int64 __fastcall hdd_chip_pwr_save_fail_detected_cb(__int64 a1, unsigned int *a2)
{
  unsigned int gfp_flags; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x21
  const char *v24; // x2
  unsigned int v25; // w1
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  gfp_flags = cds_get_gfp_flags();
  qdf_trace_msg(0x33u, 8u, "%s: enter", v5, v6, v7, v8, v9, v10, v11, v12, "hdd_chip_pwr_save_fail_detected_cb");
  result = _wlan_hdd_validate_context(a1, "hdd_chip_pwr_save_fail_detected_cb");
  if ( !(_DWORD)result )
  {
    if ( a2 )
    {
      v22 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 30, 36, gfp_flags);
      if ( !v22 )
      {
        v24 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        v25 = 4;
LABEL_10:
        result = qdf_trace_msg(
                   0x33u,
                   v25,
                   v24,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "hdd_chip_pwr_save_fail_detected_cb");
        goto LABEL_11;
      }
      v23 = v22;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: failure reason code: %u",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_chip_pwr_save_fail_detected_cb",
        *a2);
      v26 = *a2;
      if ( (unsigned int)nla_put(v23, 1, 4, &v26) )
      {
        result = sk_skb_reason_drop(0, v23, 2);
        goto LABEL_11;
      }
      _cfg80211_send_event_skb(v23, gfp_flags);
      v24 = "%s: exit";
    }
    else
    {
      v24 = "%s: data is null";
    }
    v25 = 8;
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
