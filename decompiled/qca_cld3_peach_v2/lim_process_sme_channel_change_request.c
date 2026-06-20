__int64 __fastcall lim_process_sme_channel_change_request(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w22
  char channel_reg_power_for_freq; // w0
  const char *v14; // x2
  __int64 result; // x0
  char v16; // w24
  __int64 session_by_bssid; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  __int64 v27; // x5
  unsigned int v28; // w8
  __int64 v29; // x3
  __int64 v30; // x5
  __int16 v31; // w8
  int v32; // w9
  unsigned int v33; // w8
  bool v34; // cf
  unsigned int v35; // w8
  char v36; // w9
  unsigned int v37; // w8
  unsigned int v38; // w8
  char v39; // w9
  bool v40; // zf
  char v41; // w8
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  _BOOL4 is_24ghz_ch_freq; // w23
  unsigned int v61; // w8
  _BOOL4 v62; // w23
  unsigned int v63; // w9
  unsigned int v64; // w8
  __int64 v65; // x4
  int v66; // w8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w8
  __int64 v76; // x0
  int v77; // w8
  int v78; // w8
  int v79; // w8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x0
  int v89; // w8
  unsigned int v90; // w1
  _BYTE v91[4]; // [xsp+1Ch] [xbp-14h] BYREF
  int v92; // [xsp+20h] [xbp-10h] BYREF
  __int16 v93; // [xsp+24h] [xbp-Ch]
  __int64 v94; // [xsp+28h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v93 = 0;
  v92 = 0;
  v91[0] = 0;
  if ( !a2 )
  {
    v14 = "%s: msg_buf is NULL";
    goto LABEL_5;
  }
  v10 = *((_DWORD *)a2 + 1);
  channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(a1[2704], v10, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( channel_reg_power_for_freq != 127 )
  {
    v16 = channel_reg_power_for_freq;
    wlan_mlme_get_mac_vdev_id(a1[2704], *a2, &v92);
    session_by_bssid = pe_find_session_by_bssid(a1, &v92, v91);
    if ( !session_by_bssid )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "lim_process_sme_channel_change_request",
                 (unsigned __int8)v92,
                 BYTE1(v92),
                 BYTE2(v92),
                 HIBYTE(v93));
      goto LABEL_6;
    }
    v26 = session_by_bssid;
    if ( *(_DWORD *)(session_by_bssid + 88) != 1
      || (policy_mgr_is_sap_allowed_on_dfs_freq(a1[2704], *a2, v10, v18, v19, v20, v21, v22, v23, v24, v25) & 1) != 0 )
    {
      if ( *(_DWORD *)(v26 + 284) != v10 )
        goto LABEL_16;
      v27 = *(unsigned int *)(v26 + 7176);
      if ( (_DWORD)v27 != *((_DWORD *)a2 + 3) || *(unsigned __int8 *)(v26 + 7186) != a2[17] )
        goto LABEL_16;
      v28 = *(unsigned __int8 *)(v26 + 154);
      if ( v28 <= 0xD && ((1 << v28) & 0x3001) != 0 )
      {
        if ( (lim_is_puncture_bitmap_changed(v26, a2) & 1) != 0 )
        {
LABEL_16:
          v29 = *(unsigned int *)(v26 + 284);
          v30 = *(unsigned int *)(v26 + 7176);
          if ( *(_DWORD *)(v26 + 88) == 1 )
            v31 = 3;
          else
            v31 = 5;
          v32 = *(unsigned __int8 *)(v26 + 154);
          *(_WORD *)(v26 + 152) = v31;
          qdf_trace_msg(
            0x35u,
            8u,
            "SAP CSA: %d --> %d, ch_bw %d --> %d, nw_type %d, dot11mode %d, old dot11mode %d",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v29,
            v10,
            v30,
            *((unsigned int *)a2 + 3),
            *((unsigned int *)a2 + 6),
            *((_DWORD *)a2 + 5),
            v32);
          v33 = *((_DWORD *)a2 + 5);
          if ( v33 != *(unsigned __int8 *)(v26 + 154) )
          {
            v34 = v33 >= 0xE;
            v35 = 0x3FA1u >> v33;
            v36 = !v34;
            *(_BYTE *)(v26 + 155) = v36 & v35;
            v37 = *((_DWORD *)a2 + 5);
            v34 = v37 >= 0xE;
            v38 = 0x3F01u >> v37;
            v39 = !v34;
            *(_BYTE *)(v26 + 7170) = v39 & v38;
            *(_BYTE *)(v26 + 8676) = ((unsigned __int8)*((_DWORD *)a2 + 5) < 0xEu) & (0x3C01u >> *((_DWORD *)a2 + 5));
            if ( (unsigned __int8)*((_DWORD *)a2 + 5) )
              v40 = (*((_DWORD *)a2 + 5) & 0xFE) == 12;
            else
              v40 = 1;
            v41 = v40;
            *(_BYTE *)(v26 + 10071) = v41;
          }
          if ( wlan_reg_is_6ghz_chan_freq(v10)
            && ((v42 = *(unsigned __int8 *)(v26 + 154), (unsigned int)(v42 - 7) < 7)
             || v42 == 5
             || !*(_BYTE *)(v26 + 154))
            && policy_mgr_is_vdev_ll_lt_sap(a1[2703], *(unsigned __int8 *)(v26 + 10)) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: For LL LT vdev %d allow 6 Ghz freq %d for dot11mode %d",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "lim_process_sme_channel_change_request",
              *(unsigned __int8 *)(v26 + 10),
              v10,
              *(unsigned __int8 *)(v26 + 154));
          }
          else
          {
            v59 = *((_DWORD *)a2 + 5);
            if ( ((unsigned int)(v59 - 10) < 4 || !v59) && (*(_DWORD *)(v26 + 7036) == 6 || *(_BYTE *)(v26 + 8676) == 1) )
            {
              lim_update_session_he_capable_chan_switch(a1, v26, v10);
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v10);
              if ( ((is_24ghz_ch_freq ^ wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v26 + 284))) & 1) != 0
                || *(_DWORD *)(v26 + 7176) != *((_DWORD *)a2 + 3) )
              {
                *(_DWORD *)(v26 + 284) = v10;
                *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
                lim_copy_bss_he_cap(v26);
                lim_update_he_bw_cap_mcs(v26, 0);
              }
            }
            else if ( wlan_reg_is_6ghz_chan_freq(v10) )
            {
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: Invalid target_freq %d for dot11mode %d cur HE %d",
                         v51,
                         v52,
                         v53,
                         v54,
                         v55,
                         v56,
                         v57,
                         v58,
                         "lim_process_sme_channel_change_request",
                         v10,
                         *((unsigned int *)a2 + 5),
                         *(unsigned __int8 *)(v26 + 8676));
              goto LABEL_6;
            }
          }
          v61 = *((_DWORD *)a2 + 5);
          if ( v61 <= 0xD
            && ((1 << v61) & 0x3001) != 0
            && (*(_DWORD *)(v26 + 7036) == 6 || *(_BYTE *)(v26 + 10071) == 1) )
          {
            lim_update_session_eht_capable_chan_switch(a1, v26, v10);
            v62 = wlan_reg_is_24ghz_ch_freq(v10);
            if ( ((v62 ^ wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v26 + 284))) & 1) != 0
              || (v63 = *(_DWORD *)(v26 + 7176), v64 = *((_DWORD *)a2 + 3), v63 != v64) && (v63 > 2 || v64 >= 3) )
            {
              *(_DWORD *)(v26 + 284) = v10;
              *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
              lim_copy_bss_eht_cap(v26);
              lim_update_eht_bw_cap_mcs(v26, 0);
            }
          }
          v65 = *(unsigned __int16 *)(v26 + 7184);
          *(_DWORD *)(v26 + 7176) = *((_DWORD *)a2 + 3);
          *(_BYTE *)(v26 + 7174) = a2[16];
          *(_BYTE *)(v26 + 7186) = a2[17];
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: punct 0x%x --> 0x%x",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "lim_change_puncture_bitmap",
            v65,
            *((unsigned __int16 *)a2 + 9));
          *(_WORD *)(v26 + 7184) = *((_WORD *)a2 + 9);
          *(_DWORD *)(v26 + 164) = a2[8];
          v66 = *((_DWORD *)a2 + 3);
          *(_DWORD *)(v26 + 284) = v10;
          LOBYTE(v66) = v66 != 0;
          *(_BYTE *)(v26 + 160) = v66;
          *(_BYTE *)(v26 + 161) = v66;
          if ( wlan_reg_is_6ghz_chan_freq(v10) )
          {
            v75 = 2;
          }
          else if ( wlan_reg_is_5ghz_ch_freq(v10) )
          {
            v75 = 1;
          }
          else if ( wlan_reg_is_24ghz_ch_freq(v10) )
          {
            v75 = 0;
          }
          else
          {
            v75 = 3;
          }
          v76 = *(_QWORD *)(v26 + 16);
          *(_DWORD *)(v26 + 168) = v75;
          if ( (mlme_get_cac_required(v76, v67, v68, v69, v70, v71, v72, v73, v74) & 1) != 0 )
            v77 = *((_DWORD *)a2 + 7);
          else
            v77 = 0;
          *(_DWORD *)(v26 + 10048) = v77;
          v78 = *((_DWORD *)a2 + 8);
          *(_BYTE *)(v26 + 7032) = v16;
          *(_DWORD *)(v26 + 10064) = v78;
          lim_update_bcn_probe_filter(a1, v26);
          v79 = *(_DWORD *)(v26 + 168);
          if ( v79 )
            v79 = *(unsigned __int8 *)(a1[1] + 1061LL);
          *(_DWORD *)(v26 + 7028) = v79;
          *(_BYTE *)(v26 + 154) = *((_DWORD *)a2 + 5);
          *(_DWORD *)(v26 + 96) = *((_DWORD *)a2 + 6);
          qdf_mem_copy((void *)(v26 + 252), a2 + 36, 0xDu);
          qdf_mem_copy((void *)(v26 + 265), a2 + 49, 0xDu);
          v88 = *(_QWORD *)(v26 + 16);
          if ( *(_DWORD *)(v26 + 92) == 3 )
          {
            v89 = *(_DWORD *)(v88 + 20);
            if ( v89 == 3 )
            {
              mlme_set_chan_switch_in_progress(v88, 1, v80, v81, v82, v83, v84, v85, v86, v87);
              v88 = *(_QWORD *)(v26 + 16);
              v90 = 21;
            }
            else
            {
              if ( v89 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Invalid vdev state to change channel",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "lim_mon_change_channel");
                goto LABEL_79;
              }
              v90 = 0;
            }
          }
          else
          {
            mlme_set_chan_switch_in_progress(v88, 1, v80, v81, v82, v83, v84, v85, v86, v87);
            v88 = *(_QWORD *)(v26 + 16);
            if ( *(_DWORD *)(v88 + 20) == 2 )
              v90 = 23;
            else
              v90 = 25;
          }
          wlan_vdev_mlme_sm_deliver_evt(v88, v90, 0x36B0u, v26, v80, v81, v82, v83, v84, v85, v86, v87);
LABEL_79:
          lim_check_conc_power_for_csa(a1, v26);
          lim_dump_session_info(a1, v26);
          lim_dump_he_info(a1, v26);
          result = lim_dump_eht_info(v26);
          goto LABEL_6;
        }
        v10 = *(_DWORD *)(v26 + 284);
        v27 = *(unsigned int *)(v26 + 7176);
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Target channel and mode is same as current channel and mode channel freq %d and mode %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_process_sme_channel_change_request",
        v10,
        v27);
    }
    result = lim_abort_channel_change(a1, *a2);
    goto LABEL_6;
  }
  v14 = "%s: Invalid max tx power";
LABEL_5:
  result = qdf_trace_msg(0x35u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_sme_channel_change_request");
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
