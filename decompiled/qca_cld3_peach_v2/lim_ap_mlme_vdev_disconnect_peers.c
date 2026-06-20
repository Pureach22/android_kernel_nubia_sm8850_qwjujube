__int64 __fastcall lim_ap_mlme_vdev_disconnect_peers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 session_by_vdev_id)
{
  _QWORD *context; // x0
  const char *v14; // x2

  if ( session_by_vdev_id )
    goto LABEL_2;
  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_disconnect_peers", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(
                           (__int64)context,
                           *(_BYTE *)(*(_QWORD *)(a1 + 520) + 168LL),
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9);
    if ( session_by_vdev_id )
    {
LABEL_2:
      lim_delete_all_peers(session_by_vdev_id, a2, a3, a4, a5, a6, a7, a8, a9);
      return 0;
    }
    v14 = "%s: session is NULL";
  }
  else
  {
    v14 = "%s: mac ctx is null";
  }
  qdf_trace_msg(0x35u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "lim_ap_mlme_vdev_disconnect_peers");
  return 4;
}
