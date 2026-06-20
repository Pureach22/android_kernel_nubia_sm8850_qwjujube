__int64 __fastcall lim_process_channel_switch(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_vdev_id; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  unsigned int v40; // w19

  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( session_by_vdev_id )
  {
    v20 = session_by_vdev_id;
    v21 = *(_QWORD *)(session_by_vdev_id + 16);
    *(_WORD *)(v20 + 152) = 2;
    mlme_set_chan_switch_in_progress(v21, 1, v12, v13, v14, v15, v16, v17, v18, v19);
    result = wlan_vdev_mlme_sm_deliver_evt(
               *(_QWORD *)(v20 + 16),
               0x15u,
               0x36B0u,
               v20,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29);
    if ( (_DWORD)result )
    {
      v39 = *(_QWORD *)(v20 + 16);
      v40 = result;
      mlme_set_chan_switch_in_progress(v39, 0, v31, v32, v33, v34, v35, v36, v37, v38);
      return v40;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session does not exist for given vdev_id %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_process_channel_switch",
      a2);
    return 4;
  }
  return result;
}
