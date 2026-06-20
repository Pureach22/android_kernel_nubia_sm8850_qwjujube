__int64 __fastcall wma_sta_mlme_vdev_start_continue(
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
        unsigned __int8 *a11)
{
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x20
  char is_chan_switch_in_progress; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int assoc_type; // w0

  context = _cds_get_context(54, (__int64)"wma_sta_mlme_vdev_start_continue", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  v22 = context;
  is_chan_switch_in_progress = mlme_is_chan_switch_in_progress(
                                 *(_QWORD *)(a1 + 520),
                                 v14,
                                 v15,
                                 v16,
                                 v17,
                                 v18,
                                 v19,
                                 v20,
                                 v21);
  v32 = *(_QWORD *)(a1 + 520);
  if ( (is_chan_switch_in_progress & 1) != 0 )
  {
    mlme_set_chan_switch_in_progress(v32, 0, v24, v25, v26, v27, v28, v29, v30, v31);
  }
  else
  {
    assoc_type = mlme_get_assoc_type(v32, v24, v25, v26, v27, v28, v29, v30, v31);
    if ( assoc_type >= 2 )
    {
      if ( assoc_type == 2 )
        lim_handle_add_bss_rsp(v22[2], a11, v33, v34, v35, v36, v37, v38, v39, v40);
      else
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: assoc_type %d is invalid",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wma_sta_mlme_vdev_start_continue",
          assoc_type);
      return 0;
    }
  }
  lim_process_switch_channel_rsp(v22[2], a11, v33, v34, v35, v36, v37, v38, v39, v40);
  return 0;
}
