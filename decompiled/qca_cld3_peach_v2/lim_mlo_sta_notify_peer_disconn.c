__int64 __fastcall lim_mlo_sta_notify_peer_disconn(
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
  __int64 v9; // x8
  _QWORD *peer_by_mac; // x0
  _QWORD *v11; // x19
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: pe session is null";
    return qdf_trace_msg(0x35u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "lim_mlo_sta_notify_peer_disconn");
  }
  v9 = *(_QWORD *)(a1 + 8608);
  if ( !v9 )
  {
    v13 = "%s: mac context is null";
    return qdf_trace_msg(0x35u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "lim_mlo_sta_notify_peer_disconn");
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(v9 + 21624), (_BYTE *)(a1 + 24), 7u);
  if ( !peer_by_mac )
  {
    v13 = "%s: peer is null";
    return qdf_trace_msg(0x35u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "lim_mlo_sta_notify_peer_disconn");
  }
  if ( (peer_by_mac[8] & 1) != 0 )
  {
    v11 = peer_by_mac;
    wlan_mlo_partner_peer_disconnect_notify();
    peer_by_mac = v11;
  }
  return wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, a2, a3, a4, a5, a6, a7, a8, a9);
}
