__int64 __fastcall lim_process_disassoc_frame(
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
  unsigned __int8 *v11; // x19
  unsigned __int16 *v12; // x28
  unsigned int v13; // w22
  int v14; // w8
  unsigned int v15; // w23
  int v19; // w8
  __int64 result; // x0
  const char *v21; // x2
  unsigned int v22; // w28
  __int64 v23; // x22
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x0
  __int64 v29; // x5
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
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
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x25
  __int64 v60; // x5
  __int64 v61; // x6
  __int64 v62; // x7
  int v63; // w8
  __int64 v64; // x0
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  const char *v69; // x2
  int v70; // w8
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  int v74; // w9
  int v75; // w9
  int v76; // w10
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w4
  int v86; // w8
  __int64 v87; // x5
  __int64 v88; // x6
  __int64 v89; // x7
  int v90; // w8
  __int64 v91; // x0
  __int64 system_time; // x0
  __int64 v93; // x8
  __int64 v94; // x1
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // [xsp+0h] [xbp-A0h]
  __int64 v104; // [xsp+8h] [xbp-98h]
  __int64 v105; // [xsp+10h] [xbp-90h]
  __int16 v106; // [xsp+54h] [xbp-4Ch] BYREF
  _QWORD v107[2]; // [xsp+58h] [xbp-48h] BYREF
  __int64 v108; // [xsp+68h] [xbp-38h] BYREF
  __int64 v109; // [xsp+70h] [xbp-30h]
  __int64 v110; // [xsp+78h] [xbp-28h]
  __int64 v111; // [xsp+80h] [xbp-20h]
  __int64 v112; // [xsp+88h] [xbp-18h]
  __int64 v113; // [xsp+90h] [xbp-10h]
  __int64 v114; // [xsp+98h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 **)(a2 + 16);
  v106 = 0;
  if ( (v11[10] & 1) != 0 )
  {
    v21 = "%s: received Disassoc frame from a BC/MC address";
LABEL_23:
    result = qdf_trace_msg(0x35u, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_disassoc_frame");
    goto LABEL_24;
  }
  v12 = *(unsigned __int16 **)(a2 + 24);
  v13 = *(_DWORD *)(a2 + 40);
  v14 = v11[4];
  v15 = *(_DWORD *)(a2 + 8);
  if ( (v14 & 1) != 0
    && (v14 != 255 || v11[5] != 255 || v11[6] != 255 || v11[7] != 255 || v11[8] != 255 || v11[9] != 255) )
  {
    v21 = "%s: received Disassoc frame for a MC address";
    goto LABEL_23;
  }
  if ( (lim_validate_received_frame_a1_addr(a1, v11 + 4, a3) & 1) == 0 )
  {
    v21 = "%s: rx frame doesn't have valid a1 address, drop it";
    goto LABEL_23;
  }
  v19 = *(_DWORD *)(a3 + 88);
  if ( v19 == 1 )
  {
    result = lim_mismatch_bssid_da(v11);
    if ( (result & 1) != 0 )
      goto LABEL_24;
    v19 = *(_DWORD *)(a3 + 88);
  }
  if ( v19 == 2 )
  {
    result = lim_is_sb_disconnect_allowed_fl(a3, (__int64)"lim_process_disassoc_frame", 0x73u);
    if ( (result & 1) == 0 )
    {
      if ( (*(_BYTE *)(a1 + 12410) & 0xF) != 0 )
      {
        ++*(_BYTE *)(a1 + 12410);
      }
      else
      {
        v28 = lim_sme_state_str(*(unsigned int *)(a3 + 80));
        v29 = (unsigned __int8)++*(_BYTE *)(a1 + 12410);
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: received Disassoc frame in %salready processing previously received Disassoc frame, dropping this %d",
                   v30,
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   "lim_process_disassoc_frame",
                   v28,
                   v29);
      }
      goto LABEL_24;
    }
  }
  if ( (is_mgmt_protected(*(unsigned __int8 *)(a3 + 10), v11 + 10, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0
    && (*(_BYTE *)(a2 + 46) & 0xF) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received an unprotected disassoc from AP",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_disassoc_frame");
    if ( *(_DWORD *)(a3 + 88) != 2 || *(_BYTE *)(a1 + 21505) != 1 )
    {
      result = (__int64)lim_send_sme_unprotected_mgmt_frame_ind(a1, *v11 >> 4, v11, v13 + 24, *(_BYTE *)(a3 + 10));
      goto LABEL_24;
    }
    v21 = "%s: 11w offload is enable,unprotected disassoc is not expected";
    goto LABEL_23;
  }
  if ( v13 <= 1 )
  {
    v21 = "%s: frame len less than 2";
    goto LABEL_23;
  }
  v22 = *v12;
  v23 = jiffies;
  if ( lim_process_disassoc_frame___last_ticks - jiffies + 125 < 0 )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v27 = 0;
    }
    else
    {
      v24 = v11[10];
      v25 = v11[11];
      v26 = v11[12];
      v27 = v11[15];
    }
    if ( v11 == (unsigned __int8 *)-4LL )
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
    }
    else
    {
      v38 = v11[4];
      v39 = v11[5];
      v40 = v11[6];
      v41 = v11[9];
    }
    qdf_trace_msg(
      0x35u,
      4u,
      "Disassoc RX: vdev %d from %02x:%02x:%02x:**:**:%02x for %02x:%02x:%02x:**:**:%02x RSSI = %d reason %d mlm state = "
      "%d, sme state = %d systemrole = %d ",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      *(unsigned __int8 *)(a3 + 10),
      v24,
      v25,
      v26,
      v27,
      v38,
      v39,
      v40,
      v41,
      v15,
      v22,
      *(_DWORD *)(a3 + 72),
      *(_DWORD *)(a3 + 80),
      *(_DWORD *)(a3 + 88));
    lim_process_disassoc_frame___last_ticks = v23;
  }
  lim_diag_event_report(a1, 77, a3, 0);
  v42 = lim_cp_stats_cstats_log_disassoc_evt(a3, 1, v22);
  v50 = dph_lookup_hash_entry(v42, v43, v44, v45, v46, v47, v48, v49, a1, v11 + 10, &v106, a3 + 360);
  if ( !v50 )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v62 = 0;
      v60 = 0;
      v61 = 0;
      v63 = 0;
    }
    else
    {
      v60 = v11[10];
      v61 = v11[11];
      v62 = v11[12];
      v63 = v11[15];
    }
    v69 = "%s: received Disassoc frame from STA that does not have contextreasonCode=%d, addr %02x:%02x:%02x:**:**:%02x";
    goto LABEL_69;
  }
  v59 = v50;
  if ( (lim_check_disassoc_deauth_ack_pending(a1, v11 + 10) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Ignore the DisAssoc received, while waiting for ack of disassoc/deauth",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "lim_process_disassoc_frame");
    result = lim_clean_up_disassoc_deauth_req(a1, v11 + 10, 1);
    goto LABEL_24;
  }
  v64 = a1;
  if ( *(_BYTE *)(a1 + 12410) )
    *(_BYTE *)(a1 + 12410) = 0;
  v60 = *(unsigned int *)(a3 + 88);
  if ( (_DWORD)v60 == 1 )
  {
    if ( v22 > 0x17 || ((1 << v22) & 0x83C112) == 0 )
    {
      if ( v11 == (unsigned __int8 *)-10LL )
      {
        v89 = 0;
        v87 = 0;
        v88 = 0;
        v90 = 0;
      }
      else
      {
        v87 = v11[10];
        v88 = v11[11];
        v89 = v11[12];
        v90 = v11[15];
      }
      LODWORD(v103) = v90;
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received Disassoc frame with invalid reasonCode: %d from %02x:%02x:%02x:**:**:%02x",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "lim_process_disassoc_frame",
        v22,
        v87,
        v88,
        v89,
        v103);
      v64 = a1;
    }
    goto LABEL_59;
  }
  if ( (_DWORD)v60 != 2 )
  {
    v61 = *(unsigned int *)(a3 + 80);
    goto LABEL_65;
  }
  v61 = *(unsigned int *)(a3 + 80);
  if ( (unsigned int)(v61 - 3) < 4 )
  {
LABEL_65:
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v75 = 0;
      v62 = 0;
      v63 = 0;
      v76 = 0;
    }
    else
    {
      v62 = v11[10];
      v63 = v11[11];
      v75 = v11[12];
      v76 = v11[15];
    }
    v69 = "%s: received Disassoc frame with invalid reasonCode: %d in role:%d in sme state: %d from %02x:%02x:%02x:**:**:%02x";
    LODWORD(v105) = v76;
    LODWORD(v104) = v75;
LABEL_69:
    LODWORD(v103) = v63;
    result = qdf_trace_msg(
               0x35u,
               2u,
               v69,
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               "lim_process_disassoc_frame",
               v22,
               v60,
               v61,
               v62,
               v103,
               v104,
               v105);
    goto LABEL_24;
  }
  if ( (v22 == 3 || v22 == 71 || v22 == 8) && *(_DWORD *)(a3 + 7200) )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v67 = 0;
      v65 = 0;
      v66 = 0;
      v68 = 0;
    }
    else
    {
      v65 = v11[10];
      v66 = v11[11];
      v67 = v11[12];
      v68 = v11[15];
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Ignoring disassoc frame due to upcoming channel switch, from %02x:%02x:%02x:**:**:%02x",
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               "lim_process_disassoc_frame",
               v65,
               v66,
               v67,
               v68);
    goto LABEL_24;
  }
LABEL_59:
  v70 = *(_DWORD *)(v59 + 8);
  if ( v70 == 17 || v70 == 22 || *(_BYTE *)(v59 + 645) == 1 )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v73 = 0;
      v71 = 0;
      v72 = 0;
      v74 = 0;
    }
    else
    {
      v71 = v11[10];
      v72 = v11[11];
      v73 = v11[12];
      v74 = v11[15];
    }
    LODWORD(v104) = *(_DWORD *)(v59 + 8);
    LODWORD(v103) = v74;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Deletion is in progress (%d) for peer:%02x:%02x:%02x:**:**:%02x in mlmState %d",
               v51,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               "lim_process_disassoc_frame",
               *(unsigned __int8 *)(v59 + 645),
               v71,
               v72,
               v73,
               v103,
               v104);
  }
  else
  {
    *(_BYTE *)(v59 + 645) = 1;
    lim_disassoc_tdls_peers(v64, a3, v11 + 10);
    v85 = *(_DWORD *)(v59 + 8);
    if ( v85 != 14 )
    {
      if ( v85 == 15 )
        *(_BYTE *)(v59 + 32) |= 2u;
      if ( v11 == (unsigned __int8 *)-10LL )
        v86 = 0;
      else
        v86 = v11[15];
      LODWORD(v103) = v86;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received Disassoc frame from peer that is in state: %X, addr %02x:%02x:%02x:**:**:%02x",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "lim_process_disassoc_frame",
        v103);
    }
    if ( v22 == 71 )
    {
      v91 = *(_QWORD *)(a1 + 21560);
      v112 = 0;
      v113 = 0;
      v110 = 0;
      v111 = 0;
      v108 = 0;
      v109 = 0;
      v107[0] = 0;
      v107[1] = 0;
      BYTE4(v109) = dlm_get_rssi_denylist_threshold(v91) + v15;
      qdf_mem_copy(&v108, v11 + 10, 6u);
      v111 = 0x100000004LL;
      LODWORD(v112) = v109;
      system_time = qdf_mc_timer_get_system_time();
      v93 = *(_QWORD *)(a1 + 21560);
      v94 = *(unsigned __int8 *)(a3 + 10);
      v113 = system_time;
      lim_add_bssid_to_reject_list(v93, v94, v107);
    }
    lim_extract_ies_from_deauth_disassoc(a3, (__int64)v11, *(_DWORD *)(a2 + 32), v77, v78, v79, v80, v81, v82, v83, v84);
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21552),
      (int)v11,
      *(unsigned __int8 *)(a3 + 10),
      v22,
      0,
      v15,
      0,
      0,
      0,
      0,
      10);
    lim_perform_disassoc(a1, v15, v22, a3, v11 + 10);
    result = lim_update_disconnect_vdev_id(a1, *(unsigned __int8 *)(a3 + 10));
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1057LL) == 1 && (v22 > 8 || ((1 << v22) & 0x10A) == 0) )
      result = cds_flush_logs(1u, 2u, 14, 0, 0, v95, v96, v97, v98, v99, v100, v101, v102);
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
