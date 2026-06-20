_QWORD *__fastcall lim_process_p2p_group_chan_switch_req(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  _QWORD *v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  result = _cds_get_context(53, (__int64)"lim_process_p2p_group_chan_switch_req", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v15 = result;
    result = (_QWORD *)pe_find_session_by_vdev_id(result, a1);
    if ( result )
    {
      if ( *((_DWORD *)result + 1759) == 2 )
        return (_QWORD *)lim_send_channel_usage_req_action_frame(v15, result, a2, a3);
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x35u,
                         2u,
                         "%s: Session not found for vdev_id: %d",
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         "lim_process_p2p_group_chan_switch_req",
                         (unsigned __int8)a1);
    }
  }
  return result;
}
