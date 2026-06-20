__int64 __fastcall nl_srv_ucast(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20

  if ( (unsigned int)send_msg_to_cld80211(a5, a2, a4, *(_QWORD *)(a1 + 224) + 16LL, **(_DWORD **)(a1 + 224) - 16) )
  {
    qdf_trace_msg(0x33u, 2u, "send msg to cld80211 fails for app id %d", v7, v8, v9, v10, v11, v12, v13, v14, a4);
    v15 = -1;
  }
  else
  {
    v15 = 0;
  }
  consume_skb(a1);
  return v15;
}
