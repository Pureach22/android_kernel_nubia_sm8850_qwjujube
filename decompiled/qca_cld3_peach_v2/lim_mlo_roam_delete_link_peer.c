__int64 __fastcall lim_mlo_roam_delete_link_peer(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *peer_by_mac; // x0
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2
  unsigned int v33; // w0

  context = _cds_get_context(53, (__int64)"lim_mlo_roam_delete_link_peer", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v32 = "%s: mac ctx is null";
LABEL_9:
    v33 = 53;
    return qdf_trace_msg(v33, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "lim_mlo_roam_delete_link_peer");
  }
  if ( !a1 )
  {
    v32 = "%s: pe session is null";
    goto LABEL_9;
  }
  if ( !a2 )
  {
    v32 = "%s: sta ds is null";
    goto LABEL_9;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(context[2703], (_BYTE *)(a2 + 350), 7u);
  if ( peer_by_mac )
  {
    v22 = (__int64)peer_by_mac;
    v23 = wlan_mlo_link_peer_delete();
    return wlan_objmgr_peer_release_ref(v22, 7u, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  v32 = "%s: Peer is null";
  v33 = 143;
  return qdf_trace_msg(v33, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "lim_mlo_roam_delete_link_peer");
}
