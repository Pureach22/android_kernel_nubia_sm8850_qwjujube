__int64 __fastcall wlan_t2lm_is_peer_neg_in_progress(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 )
  {
    if ( (unsigned int)ttlm_get_state(a1) == 1
      && ((unsigned int)ttlm_get_sub_state(a1) == 7 || (unsigned int)ttlm_get_sub_state(a1) == 4) )
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: TTLM negotiation is ongoing",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_t2lm_is_peer_neg_in_progress");
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(0x99u, 2u, "%s: peer is null", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_t2lm_is_peer_neg_in_progress");
  }
  return 0;
}
