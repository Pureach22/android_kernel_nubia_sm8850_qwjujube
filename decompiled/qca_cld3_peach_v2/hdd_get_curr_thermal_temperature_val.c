__int64 __fastcall hdd_get_curr_thermal_temperature_val(
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
  __int64 result; // x0
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
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  result = wlan_hdd_get_temperature(a2, &v30, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v12 = _cfg80211_alloc_reply_skb(*(_QWORD *)(a1 + 24), 103, 197, 24);
    if ( v12 )
    {
      v21 = v12;
      v31 = v30;
      if ( (unsigned int)nla_put(v12, 1, 4, &v31) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: get_thermal temperature: nla put fail",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_get_curr_thermal_temperature_val");
        sk_skb_reason_drop(0, v21, 2);
        result = 4294967274LL;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: get_thermal temperature: %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_get_curr_thermal_temperature_val",
          v30);
        result = cfg80211_vendor_cmd_reply(v21);
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: get_thermal temperature: buffer alloc fail",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_get_curr_thermal_temperature_val");
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
