__int64 __fastcall wifi_pos_set_peer_ltf_keyseed_required(
        unsigned __int8 *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BYTE *peer_private_object; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  peer_private_object = (_BYTE *)wifi_pos_get_peer_private_object((__int64)a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( peer_private_object )
  {
    *peer_private_object = a2 & 1;
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: peer_mac:%02x:%02x:%02x:**:**:%02x value:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_set_peer_ltf_keyseed_required",
      a1[48],
      a1[49],
      a1[50],
      a1[53],
      a2 & 1);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: peer private object is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_set_peer_ltf_keyseed_required");
    return 16;
  }
}
