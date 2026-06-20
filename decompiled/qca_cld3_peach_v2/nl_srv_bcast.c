__int64 __fastcall nl_srv_bcast(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v4; // w20
  unsigned int v5; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x23

  v4 = a3;
  v5 = send_msg_to_cld80211(a2, 0, a3, *(_QWORD *)(a1 + 224) + 16LL, (unsigned int)(**(_DWORD **)(a1 + 224) - 16));
  if ( v5 )
  {
    v14 = jiffies;
    if ( nl_srv_bcast___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: send msg to cld80211 fails for app id %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "nl_srv_bcast",
        v4);
      nl_srv_bcast___last_ticks = v14;
    }
  }
  consume_skb(a1);
  return v5;
}
