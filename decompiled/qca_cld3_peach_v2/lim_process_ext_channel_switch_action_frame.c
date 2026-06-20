__int64 __fastcall lim_process_ext_channel_switch_action_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x23
  unsigned int v14; // w21
  __int64 result; // x0
  __int64 v16; // x22
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  bool is_vdev_ll_lt_sap; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w22
  unsigned int v53; // w20
  char is_chan_switch_in_progress; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x20
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char v72; // w8
  __int64 v73; // [xsp+8h] [xbp-38h] BYREF
  __int64 v74; // [xsp+10h] [xbp-30h]
  __int64 v75; // [xsp+18h] [xbp-28h]
  __int64 v76; // [xsp+20h] [xbp-20h]
  __int64 v77; // [xsp+28h] [xbp-18h]
  __int64 v78; // [xsp+30h] [xbp-10h]
  __int64 v79; // [xsp+38h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 24);
  v14 = *(_DWORD *)(a2 + 40);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev: %d Received EXT Channel switch action frame",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_process_ext_channel_switch_action_frame",
    *(unsigned __int8 *)(a3 + 10));
  result = _qdf_mem_malloc(0x40u, "lim_process_ext_channel_switch_action_frame", 191);
  if ( result )
  {
    v16 = result;
    v17 = dot11f_unpack_ext_channel_switch_action_frame(a1, v13, v14, result, 0);
    if ( (v17 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse CHANSW action frame (0x%08x, len %d):",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_process_ext_channel_switch_action_frame",
        v17,
        v14);
      goto LABEL_9;
    }
    if ( v17 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: There were warnings while unpacking CHANSW Request (0x%08x, %d bytes):",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_process_ext_channel_switch_action_frame",
        v17,
        v14);
    if ( (wlan_reg_is_6ghz_supported(*(_QWORD *)(a1 + 21624), v18, v19, v20, v21, v22, v23, v24, v25) & 1) == 0
      && wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21632), BYTE1(*(_DWORD *)(v16 + 4))) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: channel belongs to 6 ghz spectrum, abort",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_process_ext_channel_switch_action_frame");
LABEL_9:
      result = _qdf_mem_free(v16);
      goto LABEL_10;
    }
    v34 = (unsigned __int16)wlan_reg_chan_opclass_to_freq(
                              BYTE2(*(_DWORD *)(v16 + 4)),
                              BYTE1(*(_DWORD *)(v16 + 4)),
                              0,
                              v26,
                              v27,
                              v28,
                              v29,
                              v30,
                              v31,
                              v32,
                              v33);
    if ( !v34 )
    {
      v63 = jiffies;
      if ( lim_process_ext_channel_switch_action_frame___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid op_class %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "lim_process_ext_channel_switch_action_frame",
          *(unsigned __int8 *)(v16 + 5));
        lim_process_ext_channel_switch_action_frame___last_ticks = v63;
      }
      goto LABEL_9;
    }
    _qdf_mem_free(v16);
    is_vdev_ll_lt_sap = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a3 + 10));
    v52 = *(_DWORD *)(a3 + 284);
    if ( is_vdev_ll_lt_sap )
    {
      if ( v52 == v34 )
      {
        if ( (mlme_is_chan_switch_in_progress(*(_QWORD *)(a3 + 16), v44, v45, v46, v47, v48, v49, v50, v51) & 1) == 0 )
        {
          result = wlan_dcs_start_dcs(
                     *(_QWORD *)(a1 + 21624),
                     *(unsigned __int8 *)(*(_QWORD *)(a1 + 21632) + 40LL),
                     *(unsigned __int8 *)(a3 + 10),
                     2);
          goto LABEL_10;
        }
        v52 = *(_DWORD *)(a3 + 284);
      }
      v53 = *(unsigned __int8 *)(a3 + 10);
      is_chan_switch_in_progress = mlme_is_chan_switch_in_progress(
                                     *(_QWORD *)(a3 + 16),
                                     v44,
                                     v45,
                                     v46,
                                     v47,
                                     v48,
                                     v49,
                                     v50,
                                     v51);
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: vdev: %d current freq: %d rcv_freq: %d / chan_switch_in_progress: %d",
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 v62,
                 "lim_process_ecsa_frame_for_ll_lt_sap",
                 v53,
                 v52,
                 v34,
                 is_chan_switch_in_progress & 1);
    }
    else if ( v52 == v34
           || (result = wlan_reg_get_channel_state_for_pwrmode(
                          *(_QWORD *)(a1 + 21632),
                          v34,
                          0,
                          v44,
                          v45,
                          v46,
                          v47,
                          v48,
                          v49,
                          v50,
                          v51),
               (_DWORD)result != 3)
           && ((wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v34, v64, v65, v66, v67, v68, v69, v70, v71) & 1) == 0
            || (result = policy_mgr_concurrent_open_sessions_running(*(_QWORD *)(a1 + 21624)), (result & 1) != 0)) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Channel freq: %d is not valid",
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 "lim_process_ext_channel_switch_action_frame",
                 v34);
    }
    else if ( *(_DWORD *)(a3 + 7036) == 3 )
    {
      v77 = 0;
      v78 = 0;
      v75 = 0;
      v76 = 0;
      v73 = 0;
      v74 = 0;
      result = _qdf_mem_malloc(8u, "lim_process_ext_channel_switch_action_frame", 261);
      if ( result )
      {
        v72 = *(_BYTE *)(a3 + 10);
        *(_DWORD *)(result + 4) = v34;
        *(_BYTE *)result = v72;
        v74 = result;
        LOWORD(v73) = 5240;
        HIDWORD(v73) = 0;
        result = sys_process_mmh_msg(a1, &v73);
      }
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
