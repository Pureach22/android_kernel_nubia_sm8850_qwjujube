__int64 __fastcall wma_ap_mlme_vdev_start_continue(
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
  __int64 v11; // x21
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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  v11 = *(_QWORD *)(a1 + 520);
  context = _cds_get_context(54, (__int64)"wma_ap_mlme_vdev_start_continue", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v22 = context;
  if ( (mlme_is_chan_switch_in_progress(v11, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
  {
    mlme_set_chan_switch_in_progress(v11, 0, v23, v24, v25, v26, v27, v28, v29, v30);
    lim_process_switch_channel_rsp(v22[2], a11, v31, v32, v33, v34, v35, v36, v37, v38);
  }
  else if ( (ap_mlme_is_hidden_ssid_restart_in_progress(v11, v23, v24, v25, v26, v27, v28, v29, v30) & 1) != 0 )
  {
    lim_process_mlm_update_hidden_ssid_rsp(
      v22[2],
      *(unsigned __int8 *)(v11 + 168),
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47);
    ap_mlme_set_hidden_ssid_restart_in_progress(v11, 0, v48, v49, v50, v51, v52, v53, v54, v55);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending add bss rsp to umac(vdev %d status %d)",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wma_vdev_send_start_resp",
      *a11,
      *((unsigned int *)a11 + 1));
    lim_handle_add_bss_rsp(v22[2], a11, v56, v57, v58, v59, v60, v61, v62, v63);
  }
  return 0;
}
