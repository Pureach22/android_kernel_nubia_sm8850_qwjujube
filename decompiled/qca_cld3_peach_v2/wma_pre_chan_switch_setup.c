__int64 __fastcall wma_pre_chan_switch_setup(
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
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x23
  __int64 *v20; // x20
  __int64 v21; // x22
  __int64 cmpt_obj; // x0
  __int64 v23; // x24
  char channel_switch_in_progress; // w21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 sap_ch_sw_info; // x0
  unsigned int v42; // w22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int16 v51; // w2
  const char *v52; // x2

  context = _cds_get_context(54, (__int64)"wma_pre_chan_switch_setup", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context[65] + 488LL * (unsigned __int8)a1;
    v20 = context;
    if ( v19 )
    {
      v21 = *(_QWORD *)v19;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v19, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( cmpt_obj )
      {
        v23 = cmpt_obj;
        channel_switch_in_progress = wma_get_channel_switch_in_progress(v19);
        if ( (channel_switch_in_progress & 1) != 0 && *(_BYTE *)(v19 + 352) == 1 )
          wma_remove_beacon_filter(v20, (_DWORD *)(v19 + 284));
        if ( !wma_is_vdev_in_ap_mode((__int64)v20, a1, v25, v26, v27, v28, v29, v30, v31, v32) )
        {
          wma_is_vdev_in_ap_mode((__int64)v20, a1, v33, v34, v35, v36, v37, v38, v39, v40);
          return wma_vdev_pre_start(a1, channel_switch_in_progress & 1, v43, v44, v45, v46, v47, v48, v49, v50);
        }
        sap_ch_sw_info = wlan_get_sap_ch_sw_info(v21, v33, v34, v35, v36, v37, v38, v39, v40);
        if ( sap_ch_sw_info )
        {
          v42 = *(unsigned __int16 *)(sap_ch_sw_info + 48);
          if ( wma_is_vdev_in_ap_mode((__int64)v20, a1, v11, v12, v13, v14, v15, v16, v17, v18) && v42 )
          {
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Changing beacon interval to %d",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "wma_pre_chan_switch_setup",
              v42);
            v51 = *(_WORD *)(v23 + 20);
            *(_WORD *)(v23 + 20) = v42;
            if ( (unsigned int)wma_fill_beacon_interval_reset_req((__int64)v20, a1, v51, 0xC8u) )
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: Failed to fill beacon interval reset req",
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                "wma_pre_chan_switch_setup");
          }
          return wma_vdev_pre_start(a1, channel_switch_in_progress & 1, v43, v44, v45, v46, v47, v48, v49, v50);
        }
        v52 = "%s: Invalid channel info";
      }
      else
      {
        v52 = "%s: vdev component object is NULL";
      }
    }
    else
    {
      v52 = "%s: wma txrx node is NULL";
    }
  }
  else
  {
    v52 = "%s: wma is NULL";
  }
  qdf_trace_msg(0x35u, 2u, v52, v11, v12, v13, v14, v15, v16, v17, v18, "wma_pre_chan_switch_setup");
  return 16;
}
