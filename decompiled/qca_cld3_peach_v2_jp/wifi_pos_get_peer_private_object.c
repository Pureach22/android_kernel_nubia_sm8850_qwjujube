__int64 __fastcall wifi_pos_get_peer_private_object(
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
  if ( a1 )
    return wlan_objmgr_peer_get_comp_private_obj(a1, 9u);
  qdf_trace_msg(0x25u, 2u, "%s: Peer is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wifi_pos_get_peer_private_object");
  return 0;
}
