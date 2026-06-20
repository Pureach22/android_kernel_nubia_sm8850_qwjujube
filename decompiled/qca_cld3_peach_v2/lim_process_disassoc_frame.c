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
  unsigned int v13; // w23
  int v14; // w8
  unsigned int v15; // w22
  int v19; // w8
  __int64 result; // x0
  const char *v21; // x2
  unsigned int v22; // w28
  __int64 v23; // x23
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w9
  int v30; // w10
  int v31; // w11
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x25
  __int64 v50; // x5
  __int64 v51; // x6
  __int64 v52; // x7
  int v53; // w8
  __int64 v54; // x0
  __int64 v55; // x4
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  const char *v59; // x2
  int v60; // w8
  __int64 v61; // x5
  __int64 v62; // x6
  __int64 v63; // x7
  int v64; // w9
  int v65; // w9
  int v66; // w10
  __int64 v67; // x0
  __int64 v68; // x5
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
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
  __int64 v103; // [xsp+0h] [xbp-E0h]
  __int64 v104; // [xsp+8h] [xbp-D8h]
  __int64 v105; // [xsp+10h] [xbp-D0h]
  __int16 v106; // [xsp+54h] [xbp-8Ch] BYREF
  _QWORD v107[2]; // [xsp+58h] [xbp-88h] BYREF
  __int64 v108; // [xsp+68h] [xbp-78h] BYREF
  __int64 v109; // [xsp+70h] [xbp-70h]
  __int64 v110; // [xsp+78h] [xbp-68h]
  __int64 v111; // [xsp+80h] [xbp-60h]
  __int64 v112; // [xsp+88h] [xbp-58h]
  __int64 v113; // [xsp+90h] [xbp-50h]
  __int64 v114; // [xsp+98h] [xbp-48h]
  __int64 v115; // [xsp+A0h] [xbp-40h]
  __int64 v116; // [xsp+A8h] [xbp-38h]
  __int64 v117; // [xsp+B0h] [xbp-30h]
  __int64 v118; // [xsp+B8h] [xbp-28h]
  __int64 v119; // [xsp+C0h] [xbp-20h]
  __int64 v120; // [xsp+C8h] [xbp-18h]
  __int64 v121; // [xsp+D0h] [xbp-10h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 **)(a2 + 16);
  v106 = 0;
  if ( (v11[10] & 1) != 0 )
  {
    v21 = "%s: received Disassoc frame from a BC/MC address";
LABEL_19:
    result = qdf_trace_msg(0x35u, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_disassoc_frame");
    goto LABEL_20;
  }
  v12 = *(unsigned __int16 **)(a2 + 24);
  v13 = *(_DWORD *)(a2 + 40);
  v14 = v11[4];
  v15 = *(_DWORD *)(a2 + 8);
  if ( (v14 & 1) != 0
    && (v14 != 255 || v11[5] != 255 || v11[6] != 255 || v11[7] != 255 || v11[8] != 255 || v11[9] != 255) )
  {
    v21 = "%s: received Disassoc frame for a MC address";
    goto LABEL_19;
  }
  if ( (lim_validate_received_frame_a1_addr(a1, v11 + 4, a3) & 1) == 0 )
  {
    v21 = "%s: rx frame doesn't have valid a1 address, drop it";
    goto LABEL_19;
  }
  v19 = *(_DWORD *)(a3 + 88);
  if ( v19 == 1 )
  {
    result = lim_mismatch_bssid_da(v11);
    if ( (result & 1) != 0 )
      goto LABEL_20;
    v19 = *(_DWORD *)(a3 + 88);
  }
  if ( v19 == 2 )
  {
    if ( (wlan_drop_mgmt_frame_on_link_removal(*(_QWORD *)(a3 + 16)) & 1) != 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Received Disassoc Frame when link removed on vdev %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_process_disassoc_frame",
                 *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 168LL));
      goto LABEL_20;
    }
    if ( *(_DWORD *)(a3 + 88) == 2 )
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
          v67 = lim_sme_state_str(*(unsigned int *)(a3 + 80));
          v68 = (unsigned __int8)++*(_BYTE *)(a1 + 12410);
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: received Disassoc frame in %salready processing previously received Disassoc frame, dropping this %d",
                     v69,
                     v70,
                     v71,
                     v72,
                     v73,
                     v74,
                     v75,
                     v76,
                     "lim_process_disassoc_frame",
                     v67,
                     v68);
        }
        goto LABEL_20;
      }
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
    if ( *(_DWORD *)(a3 + 88) != 2 || *(_BYTE *)(a1 + 21577) != 1 )
    {
      result = (__int64)lim_send_sme_unprotected_mgmt_frame_ind(a1, *v11 >> 4, v11, v13 + 24, *(_BYTE *)(a3 + 10));
      goto LABEL_20;
    }
    v21 = "%s: 11w offload is enable,unprotected disassoc is not expected";
    goto LABEL_19;
  }
  if ( v13 <= 1 )
  {
    v21 = "%s: frame len less than 2";
    goto LABEL_19;
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
      v30 = 0;
      v28 = 0;
      v29 = 0;
      v31 = 0;
    }
    else
    {
      v28 = v11[4];
      v29 = v11[5];
      v30 = v11[6];
      v31 = v11[9];
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
      v28,
      v29,
      v30,
      v31,
      v15,
      v22,
      *(_DWORD *)(a3 + 72),
      *(_DWORD *)(a3 + 80),
      *(_DWORD *)(a3 + 88));
    lim_process_disassoc_frame___last_ticks = v23;
  }
  lim_diag_event_report(a1, 77, a3, 0);
  v32 = lim_cp_stats_cstats_log_disassoc_evt(a3, 1, v22);
  v40 = dph_lookup_hash_entry(v32, v33, v34, v35, v36, v37, v38, v39, a1, v11 + 10, &v106, a3 + 360);
  if ( !v40 )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v52 = 0;
      v50 = 0;
      v51 = 0;
      v53 = 0;
    }
    else
    {
      v50 = v11[10];
      v51 = v11[11];
      v52 = v11[12];
      v53 = v11[15];
    }
    v59 = "%s: received Disassoc frame from STA that does not have contextreasonCode=%d, addr %02x:%02x:%02x:**:**:%02x";
    goto LABEL_72;
  }
  v49 = v40;
  if ( (lim_check_disassoc_deauth_ack_pending(a1, v11 + 10) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Ignore the DisAssoc received, while waiting for ack of disassoc/deauth",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "lim_process_disassoc_frame");
    result = lim_clean_up_disassoc_deauth_req(a1, v11 + 10, 1);
    goto LABEL_20;
  }
  v54 = a1;
  if ( *(_BYTE *)(a1 + 12410) )
    *(_BYTE *)(a1 + 12410) = 0;
  v50 = *(unsigned int *)(a3 + 88);
  if ( (_DWORD)v50 == 1 )
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
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "lim_process_disassoc_frame",
        v22,
        v87,
        v88,
        v89,
        v103);
      v54 = a1;
    }
    goto LABEL_61;
  }
  if ( (_DWORD)v50 != 2 )
  {
    v51 = *(unsigned int *)(a3 + 80);
    goto LABEL_67;
  }
  v51 = *(unsigned int *)(a3 + 80);
  if ( (unsigned int)(v51 - 3) < 4 )
  {
LABEL_67:
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v65 = 0;
      v52 = 0;
      v53 = 0;
      v66 = 0;
    }
    else
    {
      v52 = v11[10];
      v53 = v11[11];
      v65 = v11[12];
      v66 = v11[15];
    }
    v59 = "%s: received Disassoc frame with invalid reasonCode: %d in role:%d in sme state: %d from %02x:%02x:%02x:**:**:%02x";
    LODWORD(v105) = v66;
    LODWORD(v104) = v65;
LABEL_72:
    LODWORD(v103) = v53;
    result = qdf_trace_msg(
               0x35u,
               2u,
               v59,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               "lim_process_disassoc_frame",
               v22,
               v50,
               v51,
               v52,
               v103,
               v104,
               v105);
    goto LABEL_20;
  }
  if ( (v22 == 3 || v22 == 71 || v22 == 8) && *(_DWORD *)(a3 + 7200) )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v57 = 0;
      v55 = 0;
      v56 = 0;
      v58 = 0;
    }
    else
    {
      v55 = v11[10];
      v56 = v11[11];
      v57 = v11[12];
      v58 = v11[15];
    }
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Ignoring disassoc frame due to upcoming channel switch, from %02x:%02x:%02x:**:**:%02x",
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               "lim_process_disassoc_frame",
               v55,
               v56,
               v57,
               v58);
    goto LABEL_20;
  }
LABEL_61:
  v60 = *(_DWORD *)(v49 + 8);
  if ( v60 == 17 || v60 == 22 || *(_BYTE *)(v49 + 661) == 1 )
  {
    if ( v11 == (unsigned __int8 *)-10LL )
    {
      v63 = 0;
      v61 = 0;
      v62 = 0;
      v64 = 0;
    }
    else
    {
      v61 = v11[10];
      v62 = v11[11];
      v63 = v11[12];
      v64 = v11[15];
    }
    LODWORD(v104) = *(_DWORD *)(v49 + 8);
    LODWORD(v103) = v64;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Deletion is in progress (%d) for peer:%02x:%02x:%02x:**:**:%02x in mlmState %d",
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               "lim_process_disassoc_frame",
               *(unsigned __int8 *)(v49 + 661),
               v61,
               v62,
               v63,
               v103,
               v104);
  }
  else
  {
    *(_BYTE *)(v49 + 661) = 1;
    lim_disassoc_tdls_peers(v54, a3, v11 + 10);
    v85 = *(_DWORD *)(v49 + 8);
    if ( v85 != 14 )
    {
      if ( v85 == 15 )
        *(_BYTE *)(v49 + 32) |= 2u;
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
      v91 = *(_QWORD *)(a1 + 21632);
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      v115 = 0;
      v116 = 0;
      v113 = 0;
      v114 = 0;
      v111 = 0;
      v112 = 0;
      v109 = 0;
      v110 = 0;
      v107[1] = 0;
      v108 = 0;
      v107[0] = 0;
      BYTE4(v109) = dlm_get_rssi_denylist_threshold(v91) + v15;
      qdf_mem_copy(&v108, v11 + 10, 6u);
      v111 = 0x100000004LL;
      LODWORD(v112) = v109;
      system_time = qdf_mc_timer_get_system_time();
      v93 = *(_QWORD *)(a1 + 21632);
      v94 = *(unsigned __int8 *)(a3 + 10);
      v113 = system_time;
      lim_add_bssid_to_reject_list(v93, v94, v107);
    }
    lim_extract_ies_from_deauth_disassoc(a3, (__int64)v11, *(_DWORD *)(a2 + 32), v77, v78, v79, v80, v81, v82, v83, v84);
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21624),
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
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
