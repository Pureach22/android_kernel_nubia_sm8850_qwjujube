__int64 __fastcall wlan_cfg80211_spectral_scan_complete_event(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x8
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  unsigned int v22; // w20
  const char *v23; // x2
  __int64 result; // x0
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD **)(a1 + 24);
  if ( !v10 )
  {
    v23 = "%s: PDEV OS private structure is NULL";
LABEL_10:
    qdf_trace_msg(0x38u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_spectral_scan_complete_event");
    result = 29;
    goto LABEL_14;
  }
  if ( !a2 )
  {
    v23 = "%s: Spectral event is NULL";
    goto LABEL_10;
  }
  v12 = _cfg80211_alloc_event_skb(*v10, 0, 103, 197, 0, 70, 32, 2080);
  if ( v12 )
  {
    v21 = v12;
    if ( *(_DWORD *)(a2 + 4) >= 2u )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid Spectral scan completion status %u",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "convert_spectral_scan_completion_status_internal_to_nl");
      v22 = 4;
    }
    else
    {
      v25 = *(_DWORD *)(a2 + 4);
      if ( !(unsigned int)nla_put(v12, 1, 4, &v25) )
      {
        v25 = *(_DWORD *)(a2 + 8);
        if ( !(unsigned int)nla_put(v21, 2, 4, &v25) )
        {
          _cfg80211_send_event_skb(v21, 2080);
          result = 0;
          goto LABEL_14;
        }
      }
      v22 = 0;
    }
    sk_skb_reason_drop(0, v21, 2);
    result = v22;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cfg80211_vendor_event_alloc failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_cfg80211_spectral_scan_complete_event");
    result = 2;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
