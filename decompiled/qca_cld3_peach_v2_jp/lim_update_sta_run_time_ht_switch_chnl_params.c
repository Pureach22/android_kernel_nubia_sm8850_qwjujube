__int64 __fastcall lim_update_sta_run_time_ht_switch_chnl_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  int v5; // w23
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 v27; // x21
  __int64 v28; // x20
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w22
  unsigned int v39; // w9
  int v40; // w8
  __int64 v41; // x0
  double (*v42)(void); // x8
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  const char *v68; // x3
  unsigned int v69; // w1

  v4 = a1 + 0x4000;
  v5 = *(unsigned __int8 *)(a1 + 17124);
  result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
  if ( (result & 1) != 0 )
  {
    result = wlan_cm_get_force_20mhz_in_24ghz(*(_QWORD *)(a3 + 16), v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (result & 1) != 0 )
    {
      v17 = jiffies;
      if ( lim_get_cb_mode_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: vdev %d force 20 Mhz in 2.4 GHz",
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   "lim_get_cb_mode_for_freq",
                   *(unsigned __int8 *)(a3 + 10));
        lim_get_cb_mode_for_freq___last_ticks = v17;
      }
      goto LABEL_10;
    }
    v5 = *(unsigned __int8 *)(v4 + 736);
  }
  if ( !v5 )
  {
LABEL_10:
    v27 = jiffies;
    if ( lim_update_sta_run_time_ht_switch_chnl_params___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: self_cb_mode 0 for freq %d",
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 "lim_update_sta_run_time_ht_switch_chnl_params",
                 *(unsigned int *)(a3 + 284));
      lim_update_sta_run_time_ht_switch_chnl_params___last_ticks = v27;
    }
    return result;
  }
  result = wlan_cm_is_vdev_connected(*(_QWORD *)(a3 + 16), v9, v10, v11, v12, v13, v14, v15, v16);
  if ( (result & 1) != 0 )
  {
    if ( *(_BYTE *)(a3 + 9794) == 1 )
    {
      v26 = "%s: ch switch is in progress, ignore HT IE BW update";
LABEL_27:
      v68 = "lim_update_sta_run_time_ht_switch_chnl_params";
      v69 = 8;
      return qdf_trace_msg(0x35u, v69, v26, v18, v19, v20, v21, v22, v23, v24, v25, v68);
    }
    v29 = wlan_reg_legacy_chan_to_freq(
            *(_QWORD *)(a1 + 21560),
            *(unsigned __int8 *)(a2 + 1),
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( (unsigned int)wlan_reg_get_chan_enum_for_freq(v29, v30, v31, v32, v33, v34, v35, v36, v37) >= 0x66 )
    {
      v26 = "%s: Ignore Invalid channel in HT info";
      goto LABEL_27;
    }
    v38 = *(unsigned __int8 *)(a2 + 1);
    result = wlan_reg_freq_to_chan(
               *(_QWORD *)(a1 + 21560),
               *(_DWORD *)(a3 + 284),
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25);
    if ( v38 != (unsigned __int8)result )
    {
      v26 = "%s: Current channel doesn't match HT info ignore";
      goto LABEL_27;
    }
    v39 = *(_DWORD *)(a2 + 2);
    if ( *(_DWORD *)(a3 + 164) != (v39 & 3) || ((v39 >> 2) & 1) != *(_BYTE *)(a3 + 161) )
    {
      *(_DWORD *)(a3 + 164) = v39 & 3;
      v40 = (*(unsigned __int8 *)(a2 + 2) >> 2) & 1;
      *(_BYTE *)(a3 + 161) = (*(_BYTE *)(a2 + 2) & 4) != 0;
      *(_BYTE *)(a3 + 160) = v40;
      lim_update_tdls_set_state_for_fw(a3, 0);
      lim_delete_tdls_peers(a1, a3, 0);
      v41 = *(_QWORD *)(a3 + 8608);
      if ( !v41 )
      {
        v26 = "%s: Invalid mac context";
        v68 = "lim_ht_switch_chnl_req";
        v69 = 2;
        return qdf_trace_msg(0x35u, v69, v26, v18, v19, v20, v21, v22, v23, v24, v25, v68);
      }
      v42 = *(double (**)(void))(v41 + 12424);
      if ( v42 )
      {
        if ( *((_DWORD *)v42 - 1) != 491867520 )
          __break(0x8228u);
        v18 = v42();
      }
      v43 = *(_QWORD *)(a3 + 16);
      *(_WORD *)(a3 + 152) = 4;
      mlme_set_chan_switch_in_progress(v43, 1, v18, v19, v20, v21, v22, v23, v24, v25);
      result = wlan_vdev_mlme_sm_deliver_evt(
                 *(_QWORD *)(a3 + 16),
                 0x15u,
                 0x2A28u,
                 a3,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post WLAN_VDEV_SM_EV_FW_VDEV_RESTART for vdevid %d",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "lim_ht_switch_chnl_req",
          *(unsigned __int8 *)(a3 + 10));
        return mlme_set_chan_switch_in_progress(*(_QWORD *)(a3 + 16), 0, v60, v61, v62, v63, v64, v65, v66, v67);
      }
    }
  }
  else
  {
    v28 = jiffies;
    if ( lim_update_sta_run_time_ht_switch_chnl_params___last_ticks_192 - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: vdev not connected, ignore HT IE BW update",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "lim_update_sta_run_time_ht_switch_chnl_params");
      lim_update_sta_run_time_ht_switch_chnl_params___last_ticks_192 = v28;
    }
  }
  return result;
}
