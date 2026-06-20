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
  const char *v19; // x2
  __int64 v20; // x4
  int v21; // w8
  __int64 v22; // x26
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned int v32; // w1
  int v33; // w9
  unsigned int v34; // w24
  __int64 v35; // x27
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 v39; // x7
  int v40; // w8
  int v41; // w9
  int v42; // w10
  int v43; // w11
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x5
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  int v56; // w8
  __int64 v57; // x0
  __int64 v58; // x6
  __int64 v59; // x7
  int v60; // w8
  int v61; // w9
  const char *v62; // x2
  unsigned int v63; // w1
  __int64 v64; // x4
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x4
  __int64 v74; // x5
  __int64 v75; // x6
  __int64 v76; // x7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w9
  int v86; // w10
  int v87; // w11
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // [xsp+0h] [xbp-D0h]
  __int64 v97; // [xsp+8h] [xbp-C8h]
  __int64 v98; // [xsp+10h] [xbp-C0h]
  __int64 v99; // [xsp+18h] [xbp-B8h]
  _BYTE v100[4]; // [xsp+54h] [xbp-7Ch] BYREF
  _QWORD v101[11]; // [xsp+58h] [xbp-78h] BYREF
  __int64 v102; // [xsp+B0h] [xbp-20h]
  __int64 v103; // [xsp+B8h] [xbp-18h]
  __int64 v104; // [xsp+C0h] [xbp-10h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)(a2 + 40);
  v100[0] = 0;
  v102 = 0;
  v103 = 0;
  memset(v101, 0, sizeof(v101));
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
    if ( (wlan_drop_mgmt_frame_on_link_removal(*(_QWORD *)(a3 + 16)) & 1) != 0 )
    {
      v19 = "%s: Received deauth Frame when link removed on vdev %d";
      v20 = *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 168LL);
LABEL_6:
      result = qdf_trace_msg(0x35u, 8u, v19, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_deauth_frame", v20);
      goto LABEL_29;
    }
    a2 = v18;
    if ( *(_DWORD *)(a3 + 88) == 2 )
    {
      result = lim_is_sb_disconnect_allowed_fl(a3, (__int64)"lim_process_deauth_frame", 0x61u);
      a2 = v18;
      if ( (result & 1) == 0 && (*(_DWORD *)(a3 + 72) != 29 || *(_DWORD *)(a3 + 80) != 4) )
      {
        v33 = *(unsigned __int8 *)(a1 + 12409);
        if ( (v33 & 0xF) != 0 )
        {
          *(_BYTE *)(a1 + 12409) = v33 + 1;
          goto LABEL_29;
        }
        v20 = v33 | 1u;
        v19 = "%s: received Deauth frame in DEAUTH_WT_STATE(already processing previously received DEAUTH frame)Dropping "
              "this.. Deauth Failed %d";
        *(_BYTE *)(a1 + 12409) = v33 | 1;
        goto LABEL_6;
      }
    }
  }
  if ( (v13[10] & 1) != 0 )
  {
    v31 = "%s: received Deauth frame from a BC/MC address";
LABEL_27:
    v32 = 8;
LABEL_28:
    result = qdf_trace_msg(0x35u, v32, v31, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_deauth_frame");
    goto LABEL_29;
  }
  v21 = v13[4];
  if ( (v21 & 1) != 0
    && (v21 != 255 || v13[5] != 255 || v13[6] != 255 || v13[7] != 255 || v13[8] != 255 || v13[9] != 255) )
  {
    v31 = "%s: received Deauth frame for a MC address";
    goto LABEL_27;
  }
  v22 = a2;
  if ( *(_DWORD *)(a3 + 88) == 1 )
  {
    result = lim_mismatch_bssid_da(v13);
    if ( (result & 1) != 0 )
      goto LABEL_29;
  }
  if ( (lim_validate_received_frame_a1_addr(a1, v13 + 4, a3) & 1) == 0 )
  {
    v31 = "%s: rx frame doesn't have valid a1 address, drop it";
LABEL_31:
    v32 = 2;
    goto LABEL_28;
  }
  if ( (is_mgmt_protected(*(unsigned __int8 *)(a3 + 10), v13 + 10, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0
    && (*(_BYTE *)(v22 + 46) & 0xF) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: received an unprotected deauth from AP",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_process_deauth_frame");
    if ( *(_DWORD *)(a3 + 88) != 2 || *(_BYTE *)(a1 + 21577) != 1 )
    {
      result = (__int64)lim_send_sme_unprotected_mgmt_frame_ind(a1, *v13 >> 4, v13, v11 + 24, *(_BYTE *)(a3 + 10));
      goto LABEL_29;
    }
    v31 = "%s: 11w offload is enable,unprotected deauth is not expected";
    goto LABEL_31;
  }
  v34 = *v14;
  v35 = jiffies;
  if ( lim_process_deauth_frame___last_ticks - jiffies + 125 < 0 )
  {
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v38 = 0;
      v36 = 0;
      v37 = 0;
      v39 = 0;
    }
    else
    {
      v36 = v13[10];
      v37 = v13[11];
      v38 = v13[12];
      v39 = v13[15];
    }
    if ( v13 == (unsigned __int8 *)-4LL )
    {
      v42 = 0;
      v40 = 0;
      v41 = 0;
      v43 = 0;
    }
    else
    {
      v40 = v13[4];
      v41 = v13[5];
      v42 = v13[6];
      v43 = v13[9];
    }
    qdf_trace_msg(
      0x35u,
      4u,
      "Deauth RX: vdev %d from %02x:%02x:%02x:**:**:%02x for %02x:%02x:%02x:**:**:%02x RSSI = %d reason %d mlm state = %d"
      ", sme state = %d systemrole = %d ",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      *(unsigned __int8 *)(a3 + 10),
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v15,
      v34,
      *(_DWORD *)(a3 + 72),
      *(_DWORD *)(a3 + 80),
      *(_DWORD *)(a3 + 88));
    lim_process_deauth_frame___last_ticks = v35;
  }
  lim_diag_event_report(a1, 76, a3, 0);
  lim_cp_stats_cstats_log_deauth_evt(a3, 1, v34);
  if ( (lim_check_disassoc_deauth_ack_pending(a1, v13 + 10) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Ignore the Deauth received, while waiting for ack of disassoc/deauth",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "lim_process_deauth_frame");
    lim_clean_up_disassoc_deauth_req(a1, v13 + 10, 1);
    result = wlan_connectivity_mgmt_event(
               *(_QWORD *)(a1 + 21624),
               (int)v13,
               *(unsigned __int8 *)(a3 + 10),
               v34,
               0,
               v15,
               0,
               0,
               0,
               0,
               8);
    goto LABEL_29;
  }
  v52 = *(unsigned int *)(a3 + 88);
  if ( (_DWORD)v52 != 2 )
  {
    if ( (_DWORD)v52 != 1 )
    {
      if ( v13 == (unsigned __int8 *)-10LL )
      {
        v60 = 0;
        v58 = 0;
        v59 = 0;
        v61 = 0;
      }
      else
      {
        v58 = v13[10];
        v59 = v13[11];
        v60 = v13[12];
        v61 = v13[15];
      }
      v62 = "%s: received Deauth frame with reasonCode %d in role %d from %02x:%02x:%02x:**:**:%02x";
      v63 = 2;
      v64 = v34;
      LODWORD(v97) = v61;
      goto LABEL_89;
    }
    if ( (v34 | 2) == 3 )
      goto LABEL_63;
    goto LABEL_51;
  }
  if ( v34 > 0xF )
    goto LABEL_51;
  if ( ((1 << v34) & 0x2CE) == 0 )
  {
    if ( v34 == 15 )
    {
      qdf_mem_set(v101, 0x68u, 0);
      qdf_mem_copy(v101, v13 + 10, 6u);
      v57 = *(_QWORD *)(a1 + 21632);
      LODWORD(v103) = 1;
      v102 = 0x1300000002LL;
      dlm_add_bssid_to_reject_list(v57, v101);
      goto LABEL_63;
    }
LABEL_51:
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v55 = 0;
      v53 = 0;
      v54 = 0;
      v56 = 0;
    }
    else
    {
      v53 = v13[10];
      v54 = v13[11];
      v55 = v13[12];
      v56 = v13[15];
    }
    LODWORD(v96) = v56;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received Deauth frame with invalid reasonCode %d from %02x:%02x:%02x:**:**:%02x",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "lim_process_deauth_frame",
      v34,
      v53,
      v54,
      v55,
      v96);
  }
LABEL_63:
  pe_find_session_by_bssid(a1, a3 + 182, v100);
  if ( (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a3 + 10)) == 4 )
  {
    if ( (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a3 + 10)) == 4
      && !(unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 24), 6u) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: LFR3: Drop deauth frame from connected AP",
                 v65,
                 v66,
                 v67,
                 v68,
                 v69,
                 v70,
                 v71,
                 v72,
                 "lim_process_deauth_frame");
      *(_WORD *)(a3 + 10012) = v34;
      *(_BYTE *)(a3 + 10009) = 1;
      goto LABEL_29;
    }
    if ( (unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 182), 6u) )
    {
      if ( v13 == (unsigned __int8 *)-10LL )
      {
        v58 = 0;
        v64 = 0;
        v52 = 0;
        v59 = 0;
      }
      else
      {
        v64 = v13[10];
        v52 = v13[11];
        v58 = v13[12];
        v59 = v13[15];
      }
      v60 = *(unsigned __int8 *)(a3 + 182);
      v85 = *(unsigned __int8 *)(a3 + 183);
      v62 = "%s: Rcv Deauth from unknown/different AP while ReAssoc. Ignore %02x:%02x:%02x:**:**:%02xlimReAssocbssId : %0"
            "2x:%02x:%02x:**:**:%02x";
      v86 = *(unsigned __int8 *)(a3 + 184);
      v87 = *(unsigned __int8 *)(a3 + 187);
LABEL_88:
      LODWORD(v99) = v87;
      LODWORD(v98) = v86;
      LODWORD(v97) = v85;
      v63 = 8;
LABEL_89:
      LODWORD(v96) = v60;
      result = qdf_trace_msg(
                 0x35u,
                 v63,
                 v62,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 "lim_process_deauth_frame",
                 v64,
                 v52,
                 v58,
                 v59,
                 v96,
                 v97,
                 v98,
                 v99);
      goto LABEL_29;
    }
    if ( (unsigned int)qdf_mem_cmp(v13 + 10, (const void *)(a3 + 24), 6u) )
    {
      if ( v13 == (unsigned __int8 *)-10LL )
      {
        v58 = 0;
        v64 = 0;
        v52 = 0;
        v59 = 0;
      }
      else
      {
        v64 = v13[10];
        v52 = v13[11];
        v58 = v13[12];
        v59 = v13[15];
      }
      v87 = *(unsigned __int8 *)(a3 + 29);
      v60 = *(unsigned __int8 *)(a3 + 24);
      v62 = "%s: received DeAuth from the New AP to which ReAssoc is sent %02x:%02x:%02x:**:**:%02xpe_session->bssId: %02"
            "x:%02x:%02x:**:**:%02x";
      v85 = *(unsigned __int8 *)(a3 + 25);
      v86 = *(unsigned __int8 *)(a3 + 26);
      goto LABEL_88;
    }
  }
  if ( *(_DWORD *)(a3 + 88) == 1 || !(unsigned int)qdf_mem_cmp(v13 + 16, (const void *)(a3 + 24), 6u) )
  {
    lim_extract_ies_from_deauth_disassoc(
      a3,
      (__int64)v13,
      *(_DWORD *)(v22 + 32),
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51);
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21624),
      (int)v13,
      *(unsigned __int8 *)(a3 + 10),
      v34,
      0,
      v15,
      0,
      0,
      0,
      0,
      8);
    lim_perform_deauth(a1, a3, v34, v13 + 10, v15);
    result = lim_update_disconnect_vdev_id(a1, *(unsigned __int8 *)(a3 + 10));
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1057LL) == 1 && (v34 > 8 || ((1 << v34) & 0x10A) == 0) )
      result = cds_flush_logs(1u, 2u, 14, 0, 0, v77, v78, v79, v80, v81, v82, v83, v84);
  }
  else
  {
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v75 = 0;
      v73 = 0;
      v74 = 0;
      v76 = 0;
    }
    else
    {
      v73 = v13[10];
      v74 = v13[11];
      v75 = v13[12];
      v76 = v13[15];
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received DeAuth from an AP other than we're trying to join. Ignore. %02x:%02x:%02x:**:**:%02x",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "lim_process_deauth_frame",
      v73,
      v74,
      v75,
      v76);
    result = lim_search_pre_auth_list(a1, v13 + 10);
    if ( result )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Preauth entry exist. Deleting",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "lim_process_deauth_frame");
      result = lim_delete_pre_auth_node(a1, v13 + 10);
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
