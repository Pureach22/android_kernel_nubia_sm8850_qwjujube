__int64 __fastcall hdd_notify_thermal_throttle_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *context; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w8
  __int64 v31; // x20
  unsigned int v32; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_notify_thermal_throttle_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (unsigned int)_wlan_hdd_validate_context(
                       (__int64)context,
                       (__int64)"hdd_notify_thermal_throttle_handler",
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19) )
  {
    result = 16;
  }
  else
  {
    if ( (*(_DWORD *)(a10 + 4) & 0xFFFFFFFE) == 2 )
      host_log_device_status(9);
    v21 = _cfg80211_alloc_event_skb(context[3], 0, 103, 197, 0, 47, 24, 3264);
    if ( v21 )
    {
      v30 = *(_DWORD *)(a10 + 4);
      v31 = v21;
      if ( v30 >= 3 )
        v32 = 5;
      else
        v32 = 2 * v30;
      v41 = v32;
      if ( (unsigned int)nla_put(v21, 3, 4, &v41) )
      {
        sk_skb_reason_drop(0, v31, 2);
        result = 4;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: thermal_throttle:level %d vendor level %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "hdd_notify_thermal_throttle_handler",
          *(unsigned int *)(a10 + 4),
          v32);
        _cfg80211_send_event_skb(v31, 3264);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_event_alloc failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_notify_thermal_throttle_handler");
      result = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
