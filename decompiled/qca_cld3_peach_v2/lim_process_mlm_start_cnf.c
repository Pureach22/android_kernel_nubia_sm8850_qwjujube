__int64 __fastcall lim_process_mlm_start_cnf(
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
  __int64 session_by_session_id; // x0
  __int64 v13; // x20
  unsigned int v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  const char *v24; // x2
  __int16 v25; // w2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  const char *v35; // x9
  const char *v36; // x2
  unsigned int v37; // w21
  char v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  unsigned int v48; // w9
  __int64 v49; // x0
  int _5g_bonded_channel_state_for_pwrmode; // w0
  unsigned int v51; // w22
  int channel_state_for_pwrmode; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w21
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  _QWORD v70[4]; // [xsp+0h] [xbp-20h] BYREF

  v70[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v24 = "%s: Buffer is Pointing to NULL";
LABEL_8:
    result = qdf_trace_msg(0x35u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_start_cnf");
    goto LABEL_10;
  }
  session_by_session_id = pe_find_session_by_session_id(a1, *((unsigned __int8 *)a2 + 4));
  if ( !session_by_session_id )
  {
    v24 = "%s: Session does Not exist with given sessionId";
    goto LABEL_8;
  }
  v13 = session_by_session_id;
  if ( *(_DWORD *)(session_by_session_id + 80) != 14 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: received unexpected MLM_START_CNF in state %X",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_mlm_start_cnf");
    goto LABEL_10;
  }
  v14 = *(unsigned __int8 *)(session_by_session_id + 10);
  if ( *a2 )
  {
    pe_delete_session(a1);
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Start BSS Failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_process_mlm_start_cnf");
    result = lim_send_sme_start_bss_rsp(a1, *a2, 0, v14);
    goto LABEL_10;
  }
  v25 = *(_WORD *)(session_by_session_id + 8);
  *(_DWORD *)(session_by_session_id + 80) = 16;
  qdf_trace(53, 1u, v25, 16);
  v34 = *(_DWORD *)(v13 + 92);
  v35 = "%s: *** Started BSS ***";
  if ( v34 == 4 )
    v35 = "%s: *** Started BSS in NDI mode ***";
  if ( v34 == 1 )
    v36 = "%s: *** Started BSS in INFRA AP SIDE***";
  else
    v36 = v35;
  qdf_trace_msg(0x35u, 8u, v36, v26, v27, v28, v29, v30, v31, v32, v33, "lim_process_mlm_start_cnf");
  result = lim_send_sme_start_bss_rsp(a1, *a2, v13, v14);
  if ( !*a2 )
  {
    lim_ndi_mlme_vdev_up_transition(v13);
    v37 = *(_DWORD *)(v13 + 284);
    v38 = wlan_reg_freq_to_band(v37);
    result = *(_BYTE *)(v13 + 7186)
           ? wlan_reg_chan_band_to_freq(
               *(_QWORD *)(a1 + 21632),
               *(unsigned __int8 *)(v13 + 7186),
               1LL << v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46)
           : 0LL;
    if ( *(_DWORD *)(v13 + 88) == 1 )
    {
      v47 = *(_DWORD *)(v13 + 7176);
      if ( v47 == 4 )
      {
        v51 = result;
        channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                      *(_QWORD *)(a1 + 21632),
                                      v37,
                                      0,
                                      v39,
                                      v40,
                                      v41,
                                      v42,
                                      v43,
                                      v44,
                                      v45,
                                      v46);
        v61 = 0;
        if ( channel_state_for_pwrmode == 2 )
        {
LABEL_31:
          if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v13 + 284))
            || ((*(unsigned __int8 *)(v13 + 13288) | v61) & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Start Beacon with ssid %.*s Ch freq %d",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "lim_process_mlm_start_cnf",
              *(unsigned __int8 *)(v13 + 36),
              v13 + 37,
              *(unsigned int *)(v13 + 284));
            lim_send_beacon(a1, v13);
            lim_enable_obss_detection_config(a1, v13);
            result = lim_send_obss_color_collision_cfg(a1, v13, 1);
          }
          else
          {
            result = lim_sap_move_to_cac_wait_state(v13);
          }
          goto LABEL_10;
        }
        _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                                 *(_QWORD *)(a1 + 21632),
                                                 v51,
                                                 0,
                                                 v53,
                                                 v54,
                                                 v55,
                                                 v56,
                                                 v57,
                                                 v58,
                                                 v59,
                                                 v60);
      }
      else
      {
        if ( v47 != 3 )
        {
          v61 = wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v37, v39, v40, v41, v42, v43, v44, v45, v46) ^ 1;
          goto LABEL_31;
        }
        v48 = *(unsigned __int8 *)(v13 + 154);
        memset(v70, 0, 24);
        if ( v48 <= 0xD && ((1 << v48) & 0x3001) != 0 )
        {
          wlan_reg_set_create_punc_bitmap((__int64)v70, 1);
          v47 = *(_DWORD *)(v13 + 7176);
        }
        v49 = *(_QWORD *)(a1 + 21632);
        LODWORD(v70[0]) = v47;
        _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                 v49,
                                                 v37,
                                                 (int *)v70,
                                                 0,
                                                 v39,
                                                 v40,
                                                 v41,
                                                 v42,
                                                 v43,
                                                 v44,
                                                 v45,
                                                 v46);
      }
      v61 = _5g_bonded_channel_state_for_pwrmode != 2;
      goto LABEL_31;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
