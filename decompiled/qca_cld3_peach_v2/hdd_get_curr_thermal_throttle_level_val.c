__int64 __fastcall hdd_get_curr_thermal_throttle_level_val(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  unsigned int v12; // w20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v31 = 0;
  if ( (unsigned int)ucfg_fwol_thermal_get_target_level(v2, &v31) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_thermal level: fail get target level",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_get_curr_thermal_throttle_level_val");
  }
  else
  {
    if ( v31 >= 3 )
      v12 = 5;
    else
      v12 = 2 * v31;
    v13 = _cfg80211_alloc_reply_skb(a1[3], 103, 197, 24);
    if ( !v13 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: get_thermal level: buffer alloc fail",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_get_curr_thermal_throttle_level_val");
      result = 4294967284LL;
      goto LABEL_4;
    }
    v22 = v13;
    v32 = v12;
    if ( !(unsigned int)nla_put(v13, 2, 4, &v32) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: get_thermal level: %d vendor level %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "hdd_get_curr_thermal_throttle_level_val",
        v31,
        v12);
      result = cfg80211_vendor_cmd_reply(v22);
      goto LABEL_4;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_thermal level: nla put fail",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_get_curr_thermal_throttle_level_val");
    sk_skb_reason_drop(0, v22, 2);
  }
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
