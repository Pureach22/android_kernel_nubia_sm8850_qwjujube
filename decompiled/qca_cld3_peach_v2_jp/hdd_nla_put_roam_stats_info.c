__int64 __fastcall hdd_nla_put_roam_stats_info(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x22
  __int64 v15; // x4
  int v16; // w23
  const char *v17; // x2
  __int64 result; // x0
  char v19; // w0
  __int64 v20; // x23
  __int64 v21; // x24
  _WORD *v22; // x24
  unsigned int v23; // w23
  unsigned __int64 v24; // x20
  _DWORD *v25; // x25
  __int64 v26; // x26
  __int64 v27; // x27
  __int64 v28; // x0
  _WORD *v29; // x26
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  __int64 v39; // x24
  _WORD *v40; // x24
  __int64 v41; // x20
  __int64 v42; // x21
  __int64 v43; // x23
  __int64 v44; // x25
  _WORD *v45; // x23
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
  unsigned int v56; // w0
  const char *v57; // x2
  __int64 v58; // x5
  const char *v59; // x2
  _QWORD v60[2]; // [xsp+0h] [xbp-10h] BYREF

  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v17 = "%s: invalid param";
    goto LABEL_11;
  }
  v13 = a2 + 1840LL * a3;
  v15 = *(unsigned int *)(v13 + 8);
  if ( (unsigned int)v15 < 0x10 && ((0xB7BFu >> v15) & 1) != 0 )
  {
    v16 = dword_A08E38[v15];
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid invoke reason received: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_convert_roam_trigger_reason");
    v16 = 0;
  }
  v60[0] = *(_QWORD *)v13;
  if ( (unsigned int)nla_put_64bit(a1, 1, 8, v60, 229) )
  {
    v17 = "%s: timestamp put fail";
    goto LABEL_11;
  }
  LODWORD(v60[0]) = v16;
  if ( (unsigned int)nla_put(a1, 2, 4, v60) )
  {
    v17 = "%s:  put fail";
    goto LABEL_11;
  }
  if ( v16 > 6 )
  {
    if ( v16 > 11 )
    {
      switch ( v16 )
      {
        case 12:
          LODWORD(v60[0]) = *(_DWORD *)(v13 + 12);
          if ( (unsigned int)nla_put(a1, 28, 4, v60) )
          {
            v17 = "%s: roam_periodic.periodic_timer_ms put fail";
            goto LABEL_11;
          }
          break;
        case 13:
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
          if ( (unsigned int)nla_put(a1, 29, 1, v60) )
          {
            v17 = "%s: roam_background.current_rssi put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 13);
          if ( (unsigned int)nla_put(a1, 30, 1, v60) )
          {
            v17 = "%s: roam_background.data_rssi put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 14);
          if ( (unsigned int)nla_put(a1, 31, 1, v60) )
          {
            v17 = "%s: roam_background.data_rssi_threshold put fail";
            goto LABEL_11;
          }
          break;
        case 15:
          LODWORD(v60[0]) = hdd_convert_roam_tx_failures_reason(*(unsigned int *)(v13 + 12));
          if ( (unsigned int)nla_put(a1, 32, 4, v60) )
          {
            v17 = "%s: roam_tx_failures.kickout_threshold put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_DWORD *)(v13 + 16);
          if ( (unsigned int)nla_put(a1, 33, 1, v60) )
          {
            v17 = "%s: roam_tx_failures.kickout_reason put fail";
            goto LABEL_11;
          }
          break;
      }
    }
    else
    {
      switch ( v16 )
      {
        case 7:
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
          if ( (unsigned int)nla_put(a1, 17, 1, v60) )
          {
            v17 = "%s: roam_btm.btm_request_mode put fail";
            goto LABEL_11;
          }
          LODWORD(v60[0]) = *(_DWORD *)(v13 + 16);
          if ( (unsigned int)nla_put(a1, 18, 4, v60) )
          {
            v17 = "%s: roam_btm.disassoc_imminent_timer put fail";
            goto LABEL_11;
          }
          LODWORD(v60[0]) = *(_DWORD *)(v13 + 20);
          if ( (unsigned int)nla_put(a1, 19, 4, v60) )
          {
            v17 = "%s: roam_btm.validity_internal put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 24);
          if ( (unsigned int)nla_put(a1, 20, 1, v60) )
          {
            v17 = "%s: roam_btm.candidate_list_count put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 25);
          if ( (unsigned int)nla_put(a1, 21, 1, v60) )
          {
            v17 = "%s: roam_btm.btm_response_status_code put fail";
            goto LABEL_11;
          }
          LODWORD(v60[0]) = *(_DWORD *)(v13 + 28);
          if ( (unsigned int)nla_put(a1, 22, 4, v60) )
          {
            v17 = "%s: roam btm_bss_termination_timeout put fail";
            goto LABEL_11;
          }
          LODWORD(v60[0]) = *(_DWORD *)(v13 + 32);
          if ( (unsigned int)nla_put(a1, 23, 4, v60) )
          {
            v17 = "%s: roam btm_mbo_assoc_retry_timeout put fail";
            goto LABEL_11;
          }
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 36);
          if ( (unsigned int)nla_put(a1, 24, 1, v60) )
          {
            v17 = "%s: roam_btm.btm_req_dialog_token put fail";
            goto LABEL_11;
          }
          break;
        case 8:
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
          if ( (unsigned int)nla_put(a1, 25, 1, v60) )
          {
            v17 = "%s: roam_bss_load.cu_load put fail";
            goto LABEL_11;
          }
          break;
        case 11:
          LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
          if ( (unsigned int)nla_put(a1, 26, 1, v60) )
          {
            v17 = "%s: roam_disconnection.deauth_type put fail";
            goto LABEL_11;
          }
          LOWORD(v60[0]) = *(_WORD *)(v13 + 14);
          if ( (unsigned int)nla_put(a1, 27, 2, v60) )
          {
            v17 = "%s: roam_disconnection.deauth_reason put fail";
            goto LABEL_11;
          }
          break;
      }
    }
  }
  else if ( v16 > 3 )
  {
    if ( v16 == 4 )
    {
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
      if ( (unsigned int)nla_put(a1, 11, 1, v60) )
      {
        v17 = "%s: roam_better_rssi.current_rssi put fail";
        goto LABEL_11;
      }
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 13);
      if ( (unsigned int)nla_put(a1, 12, 1, v60) )
      {
        v17 = "%s: roam_better_rssi.hi_rssi_threshold put fail";
        goto LABEL_11;
      }
    }
    else if ( v16 == 5 )
    {
      LODWORD(v60[0]) = *(_DWORD *)(v13 + 12);
      if ( (unsigned int)nla_put(a1, 13, 4, v60) )
      {
        v17 = "%s: roam_congestion.rx_tput put fail";
        goto LABEL_11;
      }
      LODWORD(v60[0]) = *(_DWORD *)(v13 + 16);
      if ( (unsigned int)nla_put(a1, 14, 4, v60) )
      {
        v17 = "%s: roam_congestion.tx_tput put fail";
        goto LABEL_11;
      }
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 20);
      if ( (unsigned int)nla_put(a1, 15, 1, v60) )
      {
        v17 = "%s: roam_congestion.roamable_count put fail";
        goto LABEL_11;
      }
    }
    else
    {
      LOBYTE(v60[0]) = hdd_convert_roam_invoke_reason(*(unsigned int *)(v13 + 12));
      if ( (unsigned int)nla_put(a1, 16, 1, v60) )
      {
        v17 = "%s: roam_user_trigger.invoke_reason put fail";
        goto LABEL_11;
      }
    }
  }
  else
  {
    switch ( v16 )
    {
      case 1:
        LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
        if ( (unsigned int)nla_put(a1, 3, 1, v60)
          || (LOBYTE(v60[0]) = *(_BYTE *)(v13 + 13), (unsigned int)nla_put(a1, 4, 1, v60)) )
        {
          v17 = "%s: roam_per.rx_rate_thresh_percent put fail";
          goto LABEL_11;
        }
        break;
      case 2:
        LODWORD(v60[0]) = *(_DWORD *)(v13 + 12);
        if ( (unsigned int)nla_put(a1, 5, 4, v60) )
        {
          v17 = "%s: roam_bmiss.final_bmiss_cnt put fail";
          goto LABEL_11;
        }
        LODWORD(v60[0]) = *(_DWORD *)(v13 + 16);
        if ( (unsigned int)nla_put(a1, 6, 4, v60) )
        {
          v17 = "%s: roam_bmiss.consecutive_bmiss_cnt put fail";
          goto LABEL_11;
        }
        LOBYTE(v60[0]) = *(_BYTE *)(v13 + 20);
        if ( (unsigned int)nla_put(a1, 7, 1, v60) )
        {
          v17 = "%s: roam_bmiss.qos_null_success put fail";
          goto LABEL_11;
        }
        break;
      case 3:
        LOBYTE(v60[0]) = *(_BYTE *)(v13 + 12);
        if ( (unsigned int)nla_put(a1, 8, 1, v60) )
        {
          v17 = "%s: roam_poor_rssi.current_rssi put fail";
          goto LABEL_11;
        }
        LOBYTE(v60[0]) = *(_BYTE *)(v13 + 13);
        if ( (unsigned int)nla_put(a1, 9, 1, v60) )
        {
          v17 = "%s: roam_poor_rssi.roam_rssi_threshold put fail";
          goto LABEL_11;
        }
        LOBYTE(v60[0]) = *(_BYTE *)(v13 + 14);
        if ( (unsigned int)nla_put(a1, 10, 1, v60) )
        {
          v17 = "%s: roam_poor_rssi.rx_linkspeed_status put fail";
          goto LABEL_11;
        }
        break;
    }
  }
  LOBYTE(v60[0]) = hdd_convert_roam_scan_type(*(unsigned int *)(v13 + 48));
  if ( (unsigned int)nla_put(a1, 38, 1, v60) )
  {
    v17 = "%s: roam_scan_type put fail";
    goto LABEL_11;
  }
  LOBYTE(v60[0]) = *(_BYTE *)(v13 + 52);
  if ( (unsigned int)nla_put(a1, 39, 1, v60) )
  {
    v17 = "%s: roam_status put fail";
    goto LABEL_11;
  }
  if ( *(_BYTE *)(v13 + 52) )
  {
    LOBYTE(v60[0]) = hdd_convert_roam_failures_reason(*(unsigned int *)(v13 + 56));
    if ( (unsigned int)nla_put(a1, 40, 1, v60) )
    {
      v17 = "%s: roam_fail_reason put fail";
      goto LABEL_11;
    }
    v19 = hdd_convert_roam_abort_reason(*(unsigned int *)(v13 + 40));
    if ( *(_DWORD *)(v13 + 40) )
    {
      LOBYTE(v60[0]) = v19;
      if ( (unsigned int)nla_put(a1, 34, 1, v60) )
      {
        v17 = "%s: abort.abort_reason_code put fail";
        goto LABEL_11;
      }
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 44);
      if ( (unsigned int)nla_put(a1, 35, 1, v60) )
      {
        v17 = "%s: abort.data_rssi put fail";
        goto LABEL_11;
      }
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 45);
      if ( (unsigned int)nla_put(a1, 36, 1, v60) )
      {
        v17 = "%s: abort.data_rssi_threshold put fail";
        goto LABEL_11;
      }
      LOBYTE(v60[0]) = *(_BYTE *)(v13 + 46);
      if ( (unsigned int)nla_put(a1, 37, 1, v60) )
      {
        v17 = "%s: abort.rx_linkspeed_status put fail";
        goto LABEL_11;
      }
    }
  }
  v20 = *(_QWORD *)(a1 + 216);
  v21 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, 32809, 0, 0) & 0x80000000) != 0 )
    goto LABEL_131;
  v22 = (_WORD *)(v20 + v21);
  if ( !v22 )
    goto LABEL_131;
  v23 = a3;
  if ( !*(_BYTE *)(v13 + 64) )
  {
LABEL_116:
    *v22 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v22;
    LODWORD(v60[0]) = *(_DWORD *)(v13 + 524);
    if ( (unsigned int)nla_put(a1, 42, 4, v60) )
    {
      v17 = "%s: roam_scan total_scan_time put fail";
      goto LABEL_11;
    }
    v38 = *(_QWORD *)(a1 + 216);
    v39 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 32811, 0, 0) & 0x80000000) == 0 )
    {
      v40 = (_WORD *)(v38 + v39);
      if ( v40 )
      {
        v41 = 0;
        v42 = a2 + 1840LL * v23 + 560;
        while ( *(_DWORD *)(v42 - 16) )
        {
          v43 = *(_QWORD *)(a1 + 216);
          v44 = *(unsigned int *)(a1 + 208);
          if ( (nla_put(a1, (unsigned int)v41 | 0x8000, 0, 0) & 0x80000000) != 0 )
            goto LABEL_131;
          v45 = (_WORD *)(v43 + v44);
          if ( !v45 )
            goto LABEL_131;
          LOBYTE(v60[0]) = hdd_convert_roam_frame_type(*(unsigned int *)(v42 - 16));
          v46 = nla_put(a1, 1, 1, v60);
          if ( v46 )
          {
            v58 = v46;
            v59 = "%s: roam_frame[%u].type put fail %d";
LABEL_139:
            qdf_trace_msg(
              0x33u,
              2u,
              v59,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "hdd_nla_put_roam_stats_info",
              (unsigned int)v41,
              v58);
            goto LABEL_12;
          }
          LOBYTE(v60[0]) = hdd_convert_roam_frame_status(*(unsigned int *)(v42 - 12));
          v55 = nla_put(a1, 2, 1, v60);
          if ( v55 )
          {
            v58 = v55;
            v59 = "%s: frame[%u].status put fail %d";
            goto LABEL_139;
          }
          v60[0] = *(_QWORD *)(v42 - 8);
          v56 = nla_put_64bit(a1, 3, 8, v60, 229);
          if ( v56 )
          {
            v58 = v56;
            v59 = "%s: frame[%u].timestamp put fail %d";
            goto LABEL_139;
          }
          if ( (unsigned int)nla_put(a1, 5, 6, v42) )
          {
            v17 = "%s: roam candidate AP bssid put fail";
            goto LABEL_11;
          }
          ++v41;
          v42 += 24;
          *v45 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v45;
          if ( v41 == 54 )
            break;
        }
        *v40 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v40;
        if ( (unsigned int)nla_put(a1, 45, 6, v13 + 528) )
        {
          v17 = "%s: roam original AP bssid put fail";
          goto LABEL_11;
        }
        if ( *(_BYTE *)(v13 + 52) )
        {
          result = 0;
        }
        else
        {
          result = nla_put(a1, 47, 6, v13 + 534);
          if ( (_DWORD)result )
          {
            v17 = "%s: roam roamed AP bssid put fail";
LABEL_11:
            qdf_trace_msg(0x33u, 2u, v17, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_nla_put_roam_stats_info");
LABEL_12:
            result = 4294967274LL;
          }
        }
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
LABEL_131:
    v17 = "%s: nla_nest_start fail";
    goto LABEL_11;
  }
  v24 = 0;
  v25 = (_DWORD *)(a2 + 1840LL * v23 + 76);
  while ( 1 )
  {
    v26 = *(_QWORD *)(a1 + 216);
    v27 = *(unsigned int *)(a1 + 208);
    v28 = nla_put(a1, (unsigned int)v24 | 0x8000, 0, 0);
    if ( (v28 & 0x80000000) != 0 )
      goto LABEL_131;
    v29 = (_WORD *)(v26 + v27);
    if ( !v29 )
      goto LABEL_131;
    if ( v24 == 38 )
      break;
    LODWORD(v60[0]) = *((unsigned __int16 *)v25 - 4);
    if ( (unsigned int)nla_put(a1, 1, 4, v60) )
    {
      v57 = "%s: roam_chn[%u].chan_freq put fail";
LABEL_135:
      qdf_trace_msg(
        0x33u,
        2u,
        v57,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_nla_put_roam_stats_info",
        (unsigned int)v24);
      goto LABEL_12;
    }
    LODWORD(v60[0]) = hdd_convert_roam_chn_dwell_type((unsigned int)*(v25 - 1));
    if ( (unsigned int)nla_put(a1, 2, 4, v60) )
    {
      v57 = "%s: roam_chn[%u].dwell_type put fail";
      goto LABEL_135;
    }
    LODWORD(v60[0]) = *v25;
    if ( (unsigned int)nla_put(a1, 3, 4, v60) )
    {
      v57 = "%s: roam_chn[%u].max_dwell_time put fail";
      goto LABEL_135;
    }
    ++v24;
    v25 += 3;
    *v29 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v29;
    if ( v24 >= *(unsigned __int8 *)(v13 + 64) )
      goto LABEL_116;
  }
  __break(0x5512u);
  return hdd_convert_roam_invoke_reason(v28);
}
