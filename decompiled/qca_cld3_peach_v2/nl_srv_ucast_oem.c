__int64 __fastcall nl_srv_ucast_oem(__int64 a1, unsigned int a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( (unsigned int)send_msg_to_cld80211(6u, a2, 0x19u, *(_QWORD *)(a1 + 224) + 16LL, **(_DWORD **)(a1 + 224) - 16) )
    qdf_trace_msg(0x33u, 2u, "send msg to cld80211 fails for app id %d", v3, v4, v5, v6, v7, v8, v9, v10, 25);
  return consume_skb(a1);
}
