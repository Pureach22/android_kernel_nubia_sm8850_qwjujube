__int64 __fastcall osif_send_policy_id(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = _cfg80211_alloc_reply_skb(a1, 103, 197, 3696);
  if ( v3 )
  {
    v12 = v3;
    v22[0] = a2;
    if ( (unsigned int)nla_put_64bit(v3, 2, 8, v22, 229) )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: fpm: nla_put_u8 failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "osif_send_policy_id");
      sk_skb_reason_drop(0, v12, 2);
      result = 4294967206LL;
    }
    else
    {
      result = cfg80211_vendor_cmd_reply(v12);
    }
  }
  else
  {
    qdf_trace_msg(0x48u, 2u, "%s: alloc failed", v4, v5, v6, v7, v8, v9, v10, v11, "osif_send_policy_id");
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
