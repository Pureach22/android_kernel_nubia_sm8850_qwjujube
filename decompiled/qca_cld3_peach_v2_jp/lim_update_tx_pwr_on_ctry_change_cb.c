void __fastcall lim_update_tx_pwr_on_ctry_change_cb(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 session_by_vdev_id; // x0
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  int v55; // w1
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x2
  int v59; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 9;
  context = _cds_get_context(53, (__int64)"lim_update_tx_pwr_on_ctry_change_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v54 = "%s: mac ctx is null";
LABEL_9:
    qdf_trace_msg(0x35u, 2u, v54, v11, v12, v13, v14, v15, v16, v17, v18, "lim_update_tx_pwr_on_ctry_change_cb");
    goto LABEL_15;
  }
  v19 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !session_by_vdev_id )
  {
    v54 = "%s: Unable to find session";
    goto LABEL_9;
  }
  v21 = session_by_vdev_id;
  if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(session_by_vdev_id + 284)) )
  {
    if ( (unsigned int)wlan_reg_get_best_6g_power_type(
                         *(_QWORD *)(v19 + 21552),
                         *(_QWORD *)(v19 + 21560),
                         (unsigned int *)&v59,
                         *(unsigned __int8 *)(v21 + 10068),
                         *(_DWORD *)(v21 + 284),
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28,
                         v29) )
    {
      if ( (lim_is_sb_disconnect_allowed_fl(v21, (__int64)"lim_update_tx_pwr_on_ctry_change_cb", 0x2F8Bu) & 1) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: No power type found for connection frequency, trigger DISCONNECT",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_update_tx_pwr_on_ctry_change_cb");
        lim_send_deauth_mgmt_frame(v19, 0xAu, (void *)(v21 + 24), v21, 0, v46, v47, v48, v49, v50, v51, v52, v53);
        lim_tear_down_link_with_ap(v19, *(unsigned __int8 *)(v21 + 8), 0xAu, 0);
      }
      goto LABEL_15;
    }
    v55 = v59;
    v56 = *(_QWORD *)(v21 + 16);
    *(_BYTE *)(v21 + 10069) = v59;
    mlme_set_best_6g_power_type(v56, v55, v30, v31, v32, v33, v34, v35, v36, v37);
  }
  v57 = *(_QWORD *)(v21 + 112);
  if ( v57 )
    v58 = v57 + 4364;
  else
    v58 = 0;
  lim_set_tpc_power(v19, v21, v58, 0, v22, v23, v24, v25, v26, v27, v28, v29);
LABEL_15:
  _ReadStatusReg(SP_EL0);
}
