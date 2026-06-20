__int64 __fastcall lim_process_deauth_frame(
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
  unsigned int v11; // w24
  __int64 result; // x0
  unsigned __int8 *v13; // x21
  unsigned __int16 *v14; // x27
  unsigned int v15; // w23
  __int64 v18; // x22
  int v19; // w8
  __int64 v20; // x26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  char v30; // w9
  unsigned int v31; // w1
  unsigned int v32; // w24
  __int64 v33; // x27
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  int v38; // w8
  int v39; // w9
  int v40; // w10
  int v41; // w11
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x5
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  int v54; // w8
  __int64 v55; // x0
  __int64 v56; // x6
  __int64 v57; // x7
  int v58; // w8
  int v59; // w9
  const char *v60; // x2
  unsigned int v61; // w1
  __int64 v62; // x4
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w9
  int v84; // w10
  int v85; // w11
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // [xsp+0h] [xbp-90h]
  __int64 v95; // [xsp+8h] [xbp-88h]
  __int64 v96; // [xsp+10h] [xbp-80h]
  __int64 v97; // [xsp+18h] [xbp-78h]
  _BYTE v98[4]; // [xsp+54h] [xbp-3Ch] BYREF
  _QWORD v99[4]; // [xsp+58h] [xbp-38h] BYREF
  __int64 v100; // [xsp+78h] [xbp-18h]
  __int64 v101; // [xsp+80h] [xbp-10h]
  __int64 v102; // [xsp+88h] [xbp-8h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)(a2 + 40);
  v98[0] = 0;
  v100 = 0;
  v101 = 0;
  memset(v99, 0, sizeof(v99));
  if ( v11 <= 1 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Deauth Frame length invalid %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_deauth_frame",
               v11);
    goto LABEL_29;
  }
  v13 = *(unsigned __int8 **)(a2 + 16);
  v14 = *(unsigned __int16 **)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 8);
  if ( *(_DWORD *)(a3 + 88) == 2 )
  {
    v18 = a2;
    result = lim_is_sb_disconnect_allowed_fl(a3, (__int64)"lim_process_deauth_frame", 0x61u);
    a2 = v18;
    if ( (result & 1) == 0 && (*(_DWORD *)(a3 + 72) != 29 || *(_DWORD *)(a3 + 80) != 4) )
    {
      v30 = *(_BYTE *)(a1 + 12409);
      if ( (v30 & 0xF) != 0 )
      {
        *(_BYTE *)(a1 + 12409) = v30 + 1;
      }
      else
      {
        *(_BYTE *)(a1 + 12409) = v30 | 1;
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: received Deauth frame in DEAUTH_WT_STATE(already processing previously received DEAUTH frame)Drop"
                   "ping this.. Deauth Failed %d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "lim_process_deauth_frame");
      }
      goto LABEL_29;
    }
  }
  if ( (v13[10] & 1) != 0 )
  {
    v29 = "%s: received Deauth frame from a BC/MC address";
LABEL_27:
    v31 = 8;
LABEL_28:
    result = qdf_trace_msg(0x35u, v31, v29, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_deauth_frame");
    goto LABEL_29;
  }
  v19 = v13[4];
  if ( (v19 & 1) != 0
    && (v19 != 255 || v13[5] != 255 || v13[6] != 255 || v13[7] != 255 || v13[8] != 255 || v13[9] != 255) )
  {
    v29 = "%s: received Deauth frame for a MC address";
    goto LABEL_27;
  }
  v20 = a2;
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    result = lim_mismatch_bssid_da(v13);
    if ( (result & 1) != 0 )
      goto LABEL_29;
  }
  if ( (lim_validate_received_frame_a1_addr(a1, v13 + 4, a3) & 1) == 0 )
  {
    v29 = "%s: rx frame doesn't have valid a1 address, drop it";
LABEL_31:
    v31 = 2;
    goto LABEL_28;
  }
  if ( (is_mgmt_protected(*(unsigned __int8 *)(a3 + 10), v13 + 10, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0
    && (*(_BYTE *)(v20 + 46) & 0xF) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: received an unprotected deauth from AP",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_process_deauth_frame");
    if ( *(_DWORD *)(a3 + 88) != 2 || *(_BYTE *)(a1 + 21505) != 1 )
    {
      result = (__int64)lim_send_sme_unprotected_mgmt_frame_ind(a1, *v13 >> 4, v13, v11 + 24, *(_BYTE *)(a3 + 10));
      goto LABEL_29;
    }
    v29 = "%s: 11w offload is enable,unprotected deauth is not expected";
    goto LABEL_31;
  }
  v32 = *v14;
  v33 = jiffies;
  if ( lim_process_deauth_frame___last_ticks - jiffies + 125 < 0 )
  {
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v36 = 0;
      v34 = 0;
      v35 = 0;
      v37 = 0;
    }
    else
    {
      v34 = v13[10];
      v35 = v13[11];
      v36 = v13[12];
      v37 = v13[15];
    }
    if ( v13 == (unsigned __int8 *)-4LL )
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
    }
    else
    {
      v38 = v13[4];
      v39 = v13[5];
      v40 = v13[6];
      v41 = v13[9];
    }
    qdf_trace_msg(
      0x35u,
      4u,
      "Deauth RX: vdev %d from %02x:%02x:%02x:**:**:%02x for %02x:%02x:%02x:**:**:%02x RSSI = %d reason %d mlm state = %d"
      ", sme state = %d systemrole = %d ",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      *(unsigned __int8 *)(a3 + 10),
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v15,
      v32,
      *(_DWORD *)(a3 + 72),
      *(_DWORD *)(a3 + 80),
      *(_DWORD *)(a3 + 88));
    lim_process_deauth_frame___last_ticks = v33;
  }
  lim_diag_event_report(a1, 76, a3, 0);
  lim_cp_stats_cstats_log_deauth_evt(a3, 1, v32);
  if ( (lim_check_disassoc_deauth_ack_pending(a1, v13 + 10) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Ignore the Deauth received, while waiting for ack of disassoc/deauth",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_process_deauth_frame");
    lim_clean_up_disassoc_deauth_req(a1, v13 + 10, 1);
    result = wlan_connectivity_mgmt_event(
               *(_QWORD *)(a1 + 21552),
               (int)v13,
               *(unsigned __int8 *)(a3 + 10),
               v32,
               0,
               v15,
               0,
               0,
               0,
               0,
               8);
    goto LABEL_29;
  }
  v50 = *(unsigned int *)(a3 + 88);
  if ( (_DWORD)v50 == 2 )
  {
    if ( v32 <= 0xF )
    {
      if ( ((1 << v32) & 0x2CE) != 0 )
        goto LABEL_59;
      if ( v32 == 15 )
      {
        qdf_mem_set(v99, 0x30u, 0);
        qdf_mem_copy(v99, v13 + 10, 6u);
        v55 = *(_QWORD *)(a1 + 21560);
        LODWORD(v101) = 1;
        v100 = 0x1300000002LL;
        dlm_add_bssid_to_reject_list(v55, v99);
        goto LABEL_59;
      }
    }
    goto LABEL_47;
  }
  if ( (_DWORD)v50 != 1 )
  {
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v58 = 0;
      v56 = 0;
      v57 = 0;
      v59 = 0;
    }
    else
    {
      v56 = v13[10];
      v57 = v13[11];
      v58 = v13[12];
      v59 = v13[15];
    }
    v60 = "%s: received Deauth frame with reasonCode %d in role %d from %02x:%02x:%02x:**:**:%02x";
    v61 = 2;
    v62 = v32;
    LODWORD(v95) = v59;
    goto LABEL_85;
  }
  if ( (v32 | 2) != 3 )
  {
LABEL_47:
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v53 = 0;
      v51 = 0;
      v52 = 0;
      v54 = 0;
    }
    else
    {
      v51 = v13[10];
      v52 = v13[11];
      v53 = v13[12];
      v54 = v13[15];
    }
    LODWORD(v94) = v54;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received Deauth frame with invalid reasonCode %d from %02x:%02x:%02x:**:**:%02x",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_process_deauth_frame",
      v32,
      v51,
      v52,
      v53,
      v94);
  }
LABEL_59:
  pe_find_session_by_bssid(a1, a3 + 182, v98);
  if ( (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a3 + 10)) == 4 )
  {
    if ( (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a3 + 10)) == 4
      && !(unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 24), 6u) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: LFR3: Drop deauth frame from connected AP",
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 v68,
                 v69,
                 v70,
                 "lim_process_deauth_frame");
      *(_WORD *)(a3 + 10012) = v32;
      *(_BYTE *)(a3 + 10009) = 1;
      goto LABEL_29;
    }
    if ( (unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 182), 6u) )
    {
      if ( v13 == (unsigned __int8 *)-10LL )
      {
        v56 = 0;
        v62 = 0;
        v50 = 0;
        v57 = 0;
      }
      else
      {
        v62 = v13[10];
        v50 = v13[11];
        v56 = v13[12];
        v57 = v13[15];
      }
      v58 = *(unsigned __int8 *)(a3 + 182);
      v83 = *(unsigned __int8 *)(a3 + 183);
      v60 = "%s: Rcv Deauth from unknown/different AP while ReAssoc. Ignore %02x:%02x:%02x:**:**:%02xlimReAssocbssId : %0"
            "2x:%02x:%02x:**:**:%02x";
      v84 = *(unsigned __int8 *)(a3 + 184);
      v85 = *(unsigned __int8 *)(a3 + 187);
LABEL_84:
      LODWORD(v97) = v85;
      LODWORD(v96) = v84;
      LODWORD(v95) = v83;
      v61 = 8;
LABEL_85:
      LODWORD(v94) = v58;
      result = qdf_trace_msg(
                 0x35u,
                 v61,
                 v60,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 "lim_process_deauth_frame",
                 v62,
                 v50,
                 v56,
                 v57,
                 v94,
                 v95,
                 v96,
                 v97);
      goto LABEL_29;
    }
    if ( (unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 24), 6u) )
    {
      if ( v13 == (unsigned __int8 *)-10LL )
      {
        v56 = 0;
        v62 = 0;
        v50 = 0;
        v57 = 0;
      }
      else
      {
        v62 = v13[10];
        v50 = v13[11];
        v56 = v13[12];
        v57 = v13[15];
      }
      v85 = *(unsigned __int8 *)(a3 + 29);
      v58 = *(unsigned __int8 *)(a3 + 24);
      v60 = "%s: received DeAuth from the New AP to which ReAssoc is sent %02x:%02x:%02x:**:**:%02xpe_session->bssId: %02"
            "x:%02x:%02x:**:**:%02x";
      v83 = *(unsigned __int8 *)(a3 + 25);
      v84 = *(unsigned __int8 *)(a3 + 26);
      goto LABEL_84;
    }
  }
  if ( *(_DWORD *)(a3 + 88) == 1 || !(unsigned int)qdf_mem_cmp(v13 + 16, (const void *)(a3 + 24), 6u) )
  {
    lim_extract_ies_from_deauth_disassoc(
      a3,
      (__int64)v13,
      *(_DWORD *)(v20 + 32),
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49);
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21552),
      (int)v13,
      *(unsigned __int8 *)(a3 + 10),
      v32,
      0,
      v15,
      0,
      0,
      0,
      0,
      8);
    lim_perform_deauth(a1, a3, v32, v13 + 10, v15);
    result = lim_update_disconnect_vdev_id(a1, *(unsigned __int8 *)(a3 + 10));
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1057LL) == 1 && (v32 > 8 || ((1 << v32) & 0x10A) == 0) )
      result = cds_flush_logs(1u, 2u, 14, 0, 0, v75, v76, v77, v78, v79, v80, v81, v82);
  }
  else
  {
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v73 = 0;
      v71 = 0;
      v72 = 0;
      v74 = 0;
    }
    else
    {
      v71 = v13[10];
      v72 = v13[11];
      v73 = v13[12];
      v74 = v13[15];
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received DeAuth from an AP other than we're trying to join. Ignore. %02x:%02x:%02x:**:**:%02x",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_process_deauth_frame",
      v71,
      v72,
      v73,
      v74);
    result = lim_search_pre_auth_list(a1, v13 + 10);
    if ( result )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Preauth entry exist. Deleting",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "lim_process_deauth_frame");
      result = lim_delete_pre_auth_node(a1, v13 + 10);
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
