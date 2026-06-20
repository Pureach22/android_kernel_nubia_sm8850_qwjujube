__int64 __fastcall wlan_mlo_peer_get_primary_peer_link_id(
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
  if ( *(_QWORD *)(a1 + 784) )
    return wlan_mlo_peer_get_primary_peer_link_id_by_ml_peer();
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: ml_peer is null",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_mlo_peer_get_primary_peer_link_id");
  return 255;
}
