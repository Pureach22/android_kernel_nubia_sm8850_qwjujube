__int64 __fastcall lim_sta_mlme_vdev_restart_send(
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
        __int64 a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  __int64 v22; // x20
  unsigned int v23; // w21
  __int64 v24; // x0
  int v25; // w9
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  _QWORD *v36; // x20
  unsigned __int8 v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w8
  unsigned __int8 v47; // w9
  int v48; // w10
  const char *v49; // x2
  const char *v50; // x3
  const char *v51; // x2
  unsigned int v52; // w1
  int v53; // w7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w20
  __int64 v63; // x22

  if ( !a11 )
  {
    v35 = "%s: Invalid session";
LABEL_19:
    qdf_trace_msg(0x35u, 2u, v35, a2, a3, a4, a5, a6, a7, a8, a9, "lim_sta_mlme_vdev_restart_send");
    return 4;
  }
  if ( !a1 )
  {
    v35 = "%s: vdev_mlme is NULL";
    goto LABEL_19;
  }
  if ( (mlme_is_chan_switch_in_progress(*(_QWORD *)(a1 + 520), a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
    return 0;
  if ( !*(_DWORD *)(*(_QWORD *)(a1 + 520) + 16LL) )
    lim_check_ap_assist_dfs_p2p_group(0, v13, v14, v15, v16, v17, v18, v19, v20);
  v21 = *(unsigned __int16 *)(a11 + 152);
  if ( !*(_WORD *)(a11 + 152) )
  {
    result = lim_send_switch_chnl_params(*(_QWORD *)(a11 + 8608), a11, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_38;
  }
  if ( v21 == 4 )
  {
    v36 = *(_QWORD **)(a11 + 8608);
    if ( !v36 )
    {
      v49 = "%s: Invalid mac_ctx";
      v50 = "lim_ht_switch_chnl_params";
      goto LABEL_30;
    }
    v37 = wlan_reg_freq_to_chan(v36[2704], *(_DWORD *)(a11 + 284), v13, v14, v15, v16, v17, v18, v19, v20);
    v46 = *(_DWORD *)(a11 + 164);
    if ( *(_BYTE *)(a11 + 161) == 1 )
    {
      if ( v46 == 3 )
      {
        v47 = v37 - 2;
        goto LABEL_36;
      }
      if ( v46 == 1 )
      {
        v47 = v37 + 2;
LABEL_36:
        v48 = 1;
LABEL_37:
        v53 = *(_DWORD *)(a11 + 284);
        *(_BYTE *)(a11 + 7208) = v37;
        *(_BYTE *)(a11 + 7174) = v47;
        *(_DWORD *)(a11 + 288) = v53;
        *(_BYTE *)(a11 + 7209) = v47;
        *(_DWORD *)(a11 + 7204) = v53;
        *(_DWORD *)(a11 + 7176) = v48;
        *(_DWORD *)(a11 + 7212) = v48;
        *(_BYTE *)(a11 + 7211) = v46;
        *(_BYTE *)(a11 + 7210) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: HT IE changed: Primary Channel: %d center chan: %d Channel Width: %d cur op freq %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_ht_switch_chnl_params",
          v37,
          v47);
        *(_WORD *)(a11 + 152) = 4;
        v36[505] = lim_switch_channel_cback;
        v36[506] = 0;
        result = lim_send_switch_chnl_params((__int64)v36, a11, v54, v55, v56, v57, v58, v59, v60, v61);
        if ( !(_DWORD)result )
          return result;
        goto LABEL_38;
      }
    }
    v47 = 0;
    v48 = 0;
    goto LABEL_37;
  }
  if ( v21 != 2 )
    return 0;
  v22 = *(_QWORD *)(a11 + 8608);
  if ( v22 )
  {
    if ( *(_DWORD *)(a11 + 88) == 2 )
    {
      if ( *(_DWORD *)(a11 + 7196) == 1 )
      {
        v23 = *(_DWORD *)(a11 + 7204);
        v24 = *(_QWORD *)(a11 + 8608);
        *(_DWORD *)(a11 + 7220) = 0;
        *(_DWORD *)(a11 + 7196) = 2;
        if ( (lim_is_channel_valid_for_channel_switch(v24, a11, v23, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
        {
          v25 = *(_DWORD *)(a11 + 7200);
          if ( v25 == 2 )
          {
            result = lim_switch_primary_secondary_channel(v22, a11);
            *(_DWORD *)(a11 + 7200) = 0;
            if ( !(_DWORD)result )
              return result;
            goto LABEL_38;
          }
          if ( v25 == 1 )
          {
            result = lim_switch_primary_channel(
                       v22,
                       *(_DWORD *)(a11 + 7204),
                       a11,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20);
            *(_DWORD *)(a11 + 7200) = 0;
            if ( !(_DWORD)result )
              return result;
            goto LABEL_38;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: incorrect state",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "__lim_process_channel_switch_timeout");
          if ( *(_DWORD *)(a11 + 88) == 2 )
          {
            *(_DWORD *)(a11 + 7196) = 0;
            return 0;
          }
          return 0;
        }
        if ( *(_DWORD *)(a11 + 88) == 2 )
          *(_DWORD *)(a11 + 7196) = 0;
        v51 = "%s: Invalid channel freq %u Ignore CSA request";
        v52 = 2;
        goto LABEL_34;
      }
      v51 = "%s: Channel switch timer should not have been running in state: %d";
    }
    else
    {
      v51 = "%s: Channel switch can be done only in STA role, Current Role: %d";
    }
    v52 = 3;
LABEL_34:
    qdf_trace_msg(0x35u, v52, v51, v13, v14, v15, v16, v17, v18, v19, v20, "__lim_process_channel_switch_timeout");
    LODWORD(result) = 4;
    goto LABEL_38;
  }
  v49 = "%s: Invalid mac context";
  v50 = "__lim_process_channel_switch_timeout";
LABEL_30:
  qdf_trace_msg(0x35u, 2u, v49, v13, v14, v15, v16, v17, v18, v19, v20, v50);
  LODWORD(result) = 4;
LABEL_38:
  v62 = result;
  v63 = jiffies;
  if ( lim_sta_mlme_vdev_restart_send___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to send VDEV_RESTART for chan switch vdev %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_sta_mlme_vdev_restart_send",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 520) + 168LL));
    lim_sta_mlme_vdev_restart_send___last_ticks = v63;
  }
  mlme_set_chan_switch_in_progress(*(_QWORD *)(a1 + 520), 0, v27, v28, v29, v30, v31, v32, v33, v34);
  return v62;
}
