_QWORD *__fastcall lim_process_ap_assist_dfs_group_p2p_bmiss_notify(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  _QWORD *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = _cds_get_context(
             53,
             (__int64)"lim_process_ap_assist_dfs_group_p2p_bmiss_notify",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( result )
  {
    v11 = result;
    result = (_QWORD *)pe_find_session_by_vdev_id(result, a1);
    if ( result )
    {
      if ( *((_DWORD *)result + 1759) == 2 && (result[1260] & 4) != 0 )
        return (_QWORD *)lim_send_channel_usage_req_action_frame(v11, result, 0, 0);
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x35u,
                         2u,
                         "%s: Session not found for vdev_id: %d",
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         "lim_process_ap_assist_dfs_group_p2p_bmiss_notify",
                         (unsigned __int8)a1);
    }
  }
  return result;
}
