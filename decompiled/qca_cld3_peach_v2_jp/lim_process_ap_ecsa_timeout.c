__int64 __fastcall lim_process_ap_ecsa_timeout(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  const char *v20; // x2
  const char *v21; // x3
  unsigned int v22; // w1
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
  unsigned int v39; // w22
  unsigned int v40; // w21
  __int16 v41; // w8
  unsigned int v42; // w1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  if ( !a1 || !*(_BYTE *)(a1 + 70) )
  {
    v20 = "%s: Session is not valid";
    v21 = "lim_process_ap_ecsa_timeout";
LABEL_12:
    v22 = 2;
    return qdf_trace_msg(0x35u, v22, v20, a2, a3, a4, a5, a6, a7, a8, a9, v21);
  }
  v10 = *(_QWORD *)(a1 + 8608);
  if ( !*(_BYTE *)(a1 + 7282) )
  {
    if ( !*(_BYTE *)(a1 + 7284) )
    {
      v20 = "%s: session->dfsIncludeChanSwIe/chWidthUpdateIncludeChanSwIe not set";
      v21 = "lim_process_ap_ecsa_timeout";
      v22 = 8;
      return qdf_trace_msg(0x35u, v22, v20, a2, a3, a4, a5, a6, a7, a8, a9, v21);
    }
    goto LABEL_10;
  }
  if ( *(_BYTE *)(a1 + 7284) )
  {
LABEL_10:
    qdf_mc_timer_stop(a1 + 8232);
    lim_nss_or_ch_width_update_rsp(v10, *(_BYTE *)(a1 + 10), 0, 8);
    *(_BYTE *)(a1 + 7216) = 0;
    *(_BYTE *)(a1 + 7284) = 0;
    if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(v10, a1) )
    {
      lim_send_beacon_ind(v10, a1, 5u, a2, a3, a4, a5, a6, a7, a8, a9);
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: Updated CSA IE, IE COUNT: %d",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "lim_send_dfs_chan_sw_ie_update",
               (unsigned int)*(char *)(a1 + 7216));
    }
    v20 = "%s: Unable to set CSA IE in beacon";
    v21 = "lim_send_dfs_chan_sw_ie_update";
    goto LABEL_12;
  }
  if ( lim_is_csa_tx_pending(*(_BYTE *)(a1 + 10), a2, a3, a4, a5, a6, a7, a8, a9) )
    return (__int64)lim_send_csa_tx_complete(*(_BYTE *)(a1 + 10), v11, v12, v13, v14, v15, v16, v17, v18);
  result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(v10 + 21552), *(unsigned __int8 *)(a1 + 10));
  if ( (result & 1) != 0 )
    return (__int64)lim_send_csa_tx_complete(*(_BYTE *)(a1 + 10), v11, v12, v13, v14, v15, v16, v17, v18);
  if ( (*(_BYTE *)(*(_QWORD *)(v10 + 21552) + 23LL) & 2) == 0 )
  {
    qdf_mc_timer_stop(a1 + 8232);
    if ( *(_BYTE *)(a1 + 7216) )
      --*(_BYTE *)(a1 + 7216);
    lim_update_ap_csa_info(a1);
    if ( *(char *)(a1 + 7216) < 1 )
    {
      lim_send_csa_tx_complete(*(_BYTE *)(a1 + 10), v31, v32, v33, v34, v35, v36, v37, v38);
      return lim_send_dfs_chan_sw_ie_update(v10, a1);
    }
    else
    {
      lim_send_dfs_chan_sw_ie_update(v10, a1);
      if ( *(_BYTE *)(*(_QWORD *)(v10 + 8) + 3172LL) == 1 )
      {
        v39 = *(_DWORD *)(a1 + 7204);
        v40 = *(unsigned __int8 *)(a1 + 7212);
        if ( wlan_reg_is_6ghz_chan_freq(v39) )
          send_extended_chan_switch_action_frame(v10, v39, v40, a1);
        else
          lim_send_chan_switch_action_frame(v10, v39, v40, a1);
      }
      v41 = *(_WORD *)(a1 + 7158);
      if ( v41 )
        v42 = (unsigned __int8)((4294968 * (unsigned __int64)((unsigned __int8)v41 << 10)) >> 32);
      else
        v42 = 102;
      result = qdf_mc_timer_start(a1 + 8232, v42);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: cannot start ap_ecsa_timer",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "lim_process_ap_ecsa_timeout");
        return lim_process_ap_ecsa_timeout(a1);
      }
    }
  }
  return result;
}
