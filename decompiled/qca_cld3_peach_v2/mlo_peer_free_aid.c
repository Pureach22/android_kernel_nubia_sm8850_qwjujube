__int64 __fastcall mlo_peer_free_aid(
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
  __int64 v10; // x8
  __int64 v11; // x8
  const char *v12; // x2

  v10 = *(_QWORD *)(a1 + 2232);
  if ( !v10 )
  {
    v12 = "%s: ml_dev->ap_ctx is null";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_peer_free_aid");
    return 4;
  }
  if ( !a2 )
  {
    v12 = "%s: ml_peer is null";
    goto LABEL_9;
  }
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 )
  {
    v12 = "%s:  Free failed, ml_aid_mgr is NULL";
    goto LABEL_9;
  }
  if ( *(_WORD *)(a2 + 184) )
    wlan_mlo_peer_free_aid(v11, 0xFFu, *(_WORD *)(a2 + 184));
  else
    qdf_trace_msg(
      0x8Fu,
      4u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x ML assoc id is 0",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_peer_free_aid",
      *(unsigned __int8 *)(a1 + 16),
      *(unsigned __int8 *)(a2 + 104),
      *(unsigned __int8 *)(a2 + 105),
      *(unsigned __int8 *)(a2 + 106),
      *(unsigned __int8 *)(a2 + 109));
  return 0;
}
