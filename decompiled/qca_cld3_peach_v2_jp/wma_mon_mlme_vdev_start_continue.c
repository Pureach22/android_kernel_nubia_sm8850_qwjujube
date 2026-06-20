__int64 __fastcall wma_mon_mlme_vdev_start_continue(
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
        _DWORD *a11)
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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int mac_id; // w22
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  unsigned int v42; // w9
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 result; // x0
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _QWORD v64[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v65; // [xsp+18h] [xbp-18h]
  __int64 v66; // [xsp+20h] [xbp-10h]
  __int64 v67; // [xsp+28h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_mon_mlme_vdev_start_continue", a2, a3, a4, a5, a6, a7, a8, a9);
  v65 = 0;
  v66 = 0;
  v64[0] = 0;
  v64[1] = 0;
  if ( context )
  {
    v22 = context;
    if ( (mlme_is_chan_switch_in_progress(*(_QWORD *)(a1 + 504), v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
      mlme_set_chan_switch_in_progress(*(_QWORD *)(a1 + 504), 0, v23, v24, v25, v26, v27, v28, v29, v30);
    mac_id = (unsigned __int8)target_if_mc_cp_get_mac_id(a1);
    v32 = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL), 30, 0, 2);
    if ( v32 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to clear fw stats request = %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wma_mon_mlme_vdev_start_continue",
        v32);
    v41 = *(_QWORD *)(a1 + 504);
    v42 = *(unsigned __int8 *)(v41 + 104);
    v43 = *(_QWORD *)(v41 + 152);
    v65 = __PAIR64__(mac_id, v42);
    if ( v43 )
      v44 = *(_QWORD *)(v43 + 80);
    else
      v44 = 0;
    v46 = tgt_send_mc_cp_stats_req(v44, 1, v64);
    if ( v46 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to send fw stats request = %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "wma_mon_mlme_vdev_start_continue",
        v46);
    v55 = wma_cli_set2_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL), 30, 2000, mac_id, 2);
    if ( v55 )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed to send fw stats request = %d",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "wma_mon_mlme_vdev_start_continue",
        v55);
    lim_process_switch_channel_rsp(v22[2], a11, v56, v57, v58, v59, v60, v61, v62, v63);
    result = 0;
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
