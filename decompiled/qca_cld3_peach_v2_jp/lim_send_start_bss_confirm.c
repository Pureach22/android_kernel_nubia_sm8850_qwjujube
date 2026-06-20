__int64 __fastcall lim_send_start_bss_confirm(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_session_id; // x0
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v22; // x2
  const char *v23; // x3

  if ( *(_DWORD *)a2 )
  {
    session_by_session_id = pe_find_session_by_session_id(a1, a2[4], a3, a4, a5, a6, a7, a8, a9, a10);
    if ( session_by_session_id )
    {
      v12 = session_by_session_id;
      mlme_set_vdev_start_failed(*(_QWORD *)(session_by_session_id + 16), 1, a3, a4, a5, a6, a7, a8, a9, a10);
      return wlan_vdev_mlme_sm_deliver_evt(
               *(_QWORD *)(v12 + 16),
               5u,
               8u,
               (__int64)a2,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20);
    }
    v22 = "%s: session is NULL";
    v23 = "lim_send_start_bss_confirm";
  }
  else
  {
    if ( a2 )
      return lim_process_mlm_rsp_messages(a1, 1003, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    v22 = "%s: Buffer is Pointing to NULL";
    v23 = "lim_post_sme_message";
  }
  return qdf_trace_msg(0x35u, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, v23);
}
