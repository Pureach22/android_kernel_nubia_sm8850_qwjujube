__int64 __fastcall cm_roam_stats_print_trigger_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        unsigned int a5,
        char a6)
{
  __int64 result; // x0
  char *v13; // x22
  const char *roam_trigger_str; // x0
  unsigned __int16 v15; // w8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w0
  unsigned __int16 v25; // w27
  char *v26; // x25
  const char *sub_reason_str; // x0
  unsigned __int16 v28; // w0
  int v29; // w8
  unsigned __int16 v30; // w0
  const char *v31; // x2
  size_t v32; // x1
  __int64 v33; // x3
  __int64 v34; // x4
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x24
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // [xsp+8h] [xbp-38h]
  int v53; // [xsp+10h] [xbp-30h]
  int v54; // [xsp+18h] [xbp-28h]
  char s[8]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v56; // [xsp+28h] [xbp-18h]
  __int64 v57; // [xsp+30h] [xbp-10h]
  __int64 v58; // [xsp+38h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = 0;
  *(_QWORD *)s = 0;
  result = _qdf_mem_malloc(0xFAu, "cm_roam_stats_print_trigger_info", 3563);
  if ( result )
  {
    v13 = (char *)result;
    roam_trigger_str = mlme_get_roam_trigger_str(*(_DWORD *)(a3 + 4));
    v15 = snprintf(v13, 0xFAu, "Reason: \"%s\" ", roam_trigger_str);
    v24 = *(_DWORD *)(a3 + 8);
    v25 = 250 - v15;
    v26 = &v13[v15];
    if ( v24 )
    {
      sub_reason_str = mlme_get_sub_reason_str(v24);
      v28 = snprintf(v26, v25, "Sub-Reason: %s", sub_reason_str);
      v25 -= v28;
      v26 += v28;
    }
    v29 = *(_DWORD *)(a3 + 4);
    if ( v29 > 11 )
    {
      switch ( v29 )
      {
        case 12:
          snprintf(v26, v25, "CU: %d %% ", *(_DWORD *)(a3 + 20));
          break;
        case 13:
          snprintf(v26, v25, "Type: %d Reason: %d ", *(unsigned int *)(a3 + 20), *(unsigned int *)(a3 + 24));
          break;
        case 17:
          cm_roam_btm_resp_event((_DWORD *)a3, 0, a5, 1, v16, v17, v18, v19, v20, v21, v22, v23);
          if ( *(_DWORD *)(a3 + 48) )
          {
            v31 = "Roaming Mode: %d, Trigger Reason: %d, Sub code:%d, wtc mode:%d, wtc scan mode:%d, wtc rssi th:%d, wtc "
                  "candi rssi th_2g:%d, wtc_candi_rssi_th_5g:%d, wtc_candi_rssi_th_6g:%d";
            v32 = v25;
            v52 = *(_DWORD *)(a3 + 44);
            v54 = *(_DWORD *)(a3 + 56);
            v53 = *(_DWORD *)(a3 + 52);
          }
          else
          {
            v31 = "Roaming Mode: %d, Trigger Reason: %d, Sub code:%d, wtc mode:%d, wtc scan mode:%d, wtc rssi th:%d, wtc "
                  "candi rssi th:%d";
            v32 = v25;
            v52 = *(_DWORD *)(a3 + 44);
          }
          snprintf(
            v26,
            v32,
            v31,
            *(unsigned int *)(a3 + 20),
            *(unsigned int *)(a3 + 24),
            *(unsigned int *)(a3 + 28),
            *(unsigned int *)(a3 + 32),
            *(unsigned int *)(a3 + 36),
            *(_DWORD *)(a3 + 40),
            v52,
            v53,
            v54,
            *(_QWORD *)s,
            v56,
            v57,
            v58);
          break;
      }
    }
    else if ( v29 == 3 || v29 == 5 )
    {
      if ( *(_BYTE *)(a3 + 1) == 1 )
      {
        v33 = *(unsigned __int8 *)(a3 + 21);
        v34 = *(unsigned __int8 *)(a3 + 20);
      }
      else
      {
        v33 = *(unsigned int *)(a3 + 20);
        v34 = *(unsigned int *)(a3 + 12);
      }
      snprintf(v26, v25, "Cur_Rssi threshold:%d Current AP RSSI: %d", v33, v34);
    }
    else if ( v29 == 10 )
    {
      cm_roam_btm_req_event(a2, a3 + 20, a3, a5, 0);
      v30 = snprintf(v26, v25, "Req_mode: %d Disassoc_timer: %d", *(_DWORD *)(a3 + 24), *(_DWORD *)(a3 + 28) / 0x3E8u);
      snprintf(
        &v26[v30],
        (unsigned __int16)(v25 - v30),
        "validity_interval: %d candidate_list_cnt: %d resp_status: %d, bss_termination_timeout: %d, mbo_assoc_retry_timeout: %d",
        *(unsigned int *)(a3 + 32) / 0x3E8uLL,
        *(unsigned int *)(a3 + 36),
        *(unsigned int *)(a3 + 40),
        *(unsigned int *)(a3 + 44),
        *(unsigned int *)(a3 + 48));
    }
    mlme_get_converted_timestamp(*(_DWORD *)(a3 + 16), s);
    cm_roam_trigger_info_event(a3, a4, a5, a6 & 1);
    v43 = jiffies;
    if ( cm_roam_stats_print_trigger_info___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x68u,
        4u,
        "%s [ROAM_TRIGGER]: VDEV[%d] %s",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        s,
        (unsigned __int8)a5,
        v13);
      cm_roam_stats_print_trigger_info___last_ticks = v43;
    }
    _qdf_mem_free((__int64)v13);
    result = wlan_cm_update_roam_states(a1, a5, *(_DWORD *)(a3 + 4), 0);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x68u,
                 2u,
                 "%s: failed to update rt stats trigger reason",
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 "cm_roam_stats_print_trigger_info");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
