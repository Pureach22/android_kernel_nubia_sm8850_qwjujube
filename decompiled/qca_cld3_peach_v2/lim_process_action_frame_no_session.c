__int64 __fastcall lim_process_action_frame_no_session(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *v10; // x23
  unsigned int v11; // w19
  unsigned __int8 *v14; // x22
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  int v25; // w4
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 vdev_id_from_bssid; // w0
  unsigned __int8 v44; // w8

  v10 = *((unsigned __int8 **)a2 + 3);
  v11 = a2[10];
  v14 = *((unsigned __int8 **)a2 + 2);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Received an action frame category: %d action_id: %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_action_frame_no_session");
  if ( v11 <= 1 )
  {
    v24 = "%s: frame_len %d less than action frame header len";
    return qdf_trace_msg(
             0x35u,
             8u,
             v24,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "lim_process_action_frame_no_session",
             v11);
  }
  v25 = *v10;
  if ( v25 == 9 || v25 == 4 )
  {
    if ( v10[1] != 9 )
      goto LABEL_13;
    if ( v11 <= 7 )
    {
      v24 = "%s: Received vendor specific public action frame of invalid len %d";
      return qdf_trace_msg(
               0x35u,
               8u,
               v24,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_process_action_frame_no_session",
               v11);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: public action frame (Vendor specific) OUI: %x %x %x %x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_process_action_frame_no_session",
      v10[2],
      v10[3],
      v10[4],
      v10[5]);
    if ( wlan_p2p_is_action_frame_of_p2p_type(v14, a2[8], v27, v28, v29, v30, v31, v32, v33, v34) )
    {
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: Drop P2P public action frame as already handled in p2p module",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "lim_process_action_frame_no_session");
    }
    else
    {
LABEL_13:
      vdev_id_from_bssid = wlan_nan_get_vdev_id_from_bssid(*(_QWORD *)(a1 + 21632), v14 + 16, 43);
      if ( vdev_id_from_bssid == 0xFF )
        v44 = 0;
      else
        v44 = vdev_id_from_bssid;
      return lim_send_sme_mgmt_frame_ind(a1, *v14 >> 4, v14, v11 + 24, v44, *a2, a2[2], 0);
    }
  }
  else
  {
    v26 = jiffies;
    if ( lim_process_action_frame_no_session___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 4u,
                 "%s: Unhandled action frame without session: %x",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "lim_process_action_frame_no_session");
      lim_process_action_frame_no_session___last_ticks = v26;
    }
  }
  return result;
}
