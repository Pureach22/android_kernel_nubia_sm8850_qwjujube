__int64 __fastcall lim_mlo_roam_peer_disconn_del(
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
  __int64 v10; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  const char *v21; // x2
  _QWORD *peer_by_mac; // x0
  __int64 v23; // x19
  __int64 v24; // [xsp+0h] [xbp-10h] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v24) = 0;
  LODWORD(v24) = 0;
  if ( !a1 )
  {
    v21 = "%s: vdev is null";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v21 = "%s: psoc is null";
LABEL_8:
    result = qdf_trace_msg(0x35u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "lim_mlo_roam_peer_disconn_del", v24, v25);
    goto LABEL_9;
  }
  if ( (unsigned int)wlan_vdev_get_bss_peer_mac(a1, &v24, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: vdev id %d : failed to get bssid",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "lim_mlo_roam_peer_disconn_del",
               *(unsigned __int8 *)(a1 + 168),
               v24,
               v25);
    goto LABEL_9;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v10, &v24, 7u);
  if ( !peer_by_mac )
  {
    v21 = "%s: peer is null";
    goto LABEL_8;
  }
  v23 = (__int64)peer_by_mac;
  if ( (peer_by_mac[8] & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev id %d disconn del peer",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "lim_mlo_roam_peer_disconn_del",
      *(unsigned __int8 *)(a1 + 168),
      v24,
      v25);
    wlan_mlo_partner_peer_disconnect_notify(v23);
    a2 = wlan_mlo_link_peer_delete(v23);
  }
  result = wlan_objmgr_peer_release_ref(v23, 7u, a2, a3, a4, a5, a6, a7, a8, a9);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
