__int64 __fastcall lim_pasn_peer_del_all_resp_vdev_delete_resume(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 (__fastcall *v21)(__int64, __int64); // x8

  if ( !a1 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Mac ctx is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_pasn_peer_del_all_resp_vdev_delete_resume");
  if ( (unsigned __int8)wifi_pos_get_pasn_peer_count(a2) )
    wifi_pos_cleanup_pasn_peers(*(_QWORD *)(a1 + 21624), a2);
  wifi_pos_set_delete_all_peer_in_progress(a2, 0);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Resume vdev delete",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "lim_pasn_peer_del_all_resp_vdev_delete_resume");
  v21 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 14696);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -239556225 )
      __break(0x8228u);
    return v21(a1, a2);
  }
  return result;
}
