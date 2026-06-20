__int64 __fastcall lim_pmf_comeback_timer_callback(__int64 *a1)
{
  __int64 v1; // x19
  __int64 session_by_vdev_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  __int64 v13; // x21

  v1 = *a1;
  session_by_vdev_id = pe_find_session_by_vdev_id(*a1, *((unsigned __int8 *)a1 + 8));
  if ( !session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: no session found for vdev %d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "lim_pmf_comeback_timer_callback",
             *((unsigned __int8 *)a1 + 8));
  v12 = *(unsigned int *)(session_by_vdev_id + 72);
  if ( (_DWORD)v12 != 10 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Don't send assoc req, timer expire when limMlmState %d vdev id %d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "lim_pmf_comeback_timer_callback",
             v12,
             *(unsigned __int8 *)(session_by_vdev_id + 10));
  v13 = session_by_vdev_id;
  qdf_trace_msg(
    0x35u,
    4u,
    "%s: comeback later timer expired. sending MLM ASSOC req for vdev %d, session limMlmState %d, info lim_mlm_state %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "lim_pmf_comeback_timer_callback",
    *(unsigned __int8 *)(session_by_vdev_id + 10),
    10,
    *((unsigned int *)a1 + 4));
  *(_DWORD *)(v13 + 76) = *((_DWORD *)a1 + 3);
  *(_DWORD *)(v13 + 72) = *((_DWORD *)a1 + 4);
  return lim_send_mlm_assoc_req(v1, v13);
}
