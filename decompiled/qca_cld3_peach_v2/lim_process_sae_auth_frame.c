__int64 __fastcall lim_process_sae_auth_frame(
        __int64 a1,
        unsigned int *a2,
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
  unsigned int v14; // w24
  unsigned __int8 *v15; // x20
  unsigned __int16 *v16; // x27
  unsigned int v17; // w23
  unsigned int v18; // w25
  __int64 v19; // x28
  unsigned int v20; // w8
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x7
  int v24; // w8
  int v25; // w9
  int v26; // w10
  int v27; // w8
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int updated; // w0
  __int64 result; // x0
  unsigned int v39; // w26
  int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  const char *v59; // x2
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x4
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x7
  __int64 v73; // x27
  unsigned int v74; // w8
  __int64 sae_auth_retry; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  int v84; // w8
  __int64 v85; // x27
  __int64 v86; // x4
  __int64 v87; // x28
  unsigned int v88; // w27
  __int64 session_by_vdev_id; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x28
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  int v116; // w9
  __int64 v117; // x10
  __int64 v118; // x9
  __int64 v119; // [xsp+0h] [xbp-40h]
  unsigned int v120; // [xsp+1Ch] [xbp-24h]
  int v121[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v122; // [xsp+28h] [xbp-18h] BYREF
  int v123; // [xsp+30h] [xbp-10h] BYREF
  __int16 v124; // [xsp+34h] [xbp-Ch]
  __int64 v125; // [xsp+38h] [xbp-8h]

  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2[10];
  v15 = *((unsigned __int8 **)a2 + 2);
  v16 = *((unsigned __int16 **)a2 + 3);
  if ( v14 < 6 )
  {
    v17 = 0;
    v120 = 0;
  }
  else
  {
    v17 = v16[1];
    v120 = v16[2];
  }
  v18 = *v16;
  v19 = jiffies;
  if ( lim_process_sae_auth_frame___last_ticks - jiffies + 125 < 0 )
  {
    v20 = *(unsigned __int16 *)v15;
    v21 = (v20 >> 2) & 3;
    v22 = (unsigned __int8)v20 >> 4;
    if ( v15 == (unsigned __int8 *)-10LL )
    {
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
    }
    else
    {
      v23 = v15[10];
      v24 = v15[11];
      v25 = v15[12];
      v26 = v15[15];
    }
    qdf_trace_msg(
      0x35u,
      4u,
      "vdev:%d SAE Auth RX type %d subtype %d trans_seq_num:%d from %02x:%02x:%02x:**:**:%02x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      *(unsigned __int8 *)(a3 + 10),
      v21,
      v22,
      v17,
      v23,
      v24,
      v25,
      v26);
    lim_process_sae_auth_frame___last_ticks = v19;
  }
  v27 = *(_DWORD *)(a3 + 88);
  if ( v27 == 2 )
  {
    if ( *(_DWORD *)(a3 + 72) == 29 )
    {
LABEL_17:
      v39 = 0;
      goto LABEL_34;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: SAE auth response for STA in unexpected state %x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_sae_auth_frame");
    v27 = *(_DWORD *)(a3 + 88);
  }
  if ( v27 != 1 )
    goto LABEL_17;
  v124 = 0;
  v123 = 0;
  v28 = lim_search_pre_auth_list(a1, v15 + 10);
  if ( v28 )
  {
    if ( *(_DWORD *)(v28 + 20) == 29 )
    {
      updated = lim_update_link_to_mld_address(a1, *(_QWORD *)(a3 + 16), v15);
      if ( updated )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: SAE address conversion failure with status:%d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "lim_process_sae_auth_frame",
                   updated);
        goto LABEL_48;
      }
      goto LABEL_33;
    }
    if ( v15 == (unsigned __int8 *)-10LL )
      v40 = 0;
    else
      v40 = v15[15];
    LODWORD(v119) = v40;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Delete existing preauth node for SAE peer in state: %u %02x:%02x:%02x:**:**:%02x",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "lim_process_sae_auth_frame",
      v119);
    lim_delete_pre_auth_node(a1, v15 + 10);
  }
  if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3407LL) == (unsigned __int8)pe_get_current_stas_count(a1) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Max Sta count reached : %d",
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               "lim_process_sae_auth_frame",
               *(unsigned __int16 *)(a1 + 3990));
    goto LABEL_48;
  }
  v49 = *(_QWORD *)(a3 + 16);
  v122 = 0;
  *(_QWORD *)v121 = 0;
  if ( (wlan_cm_is_sae_auth_addr_conversion_required(v49, v41, v42, v43, v44, v45, v46, v47, v48) & 1) == 0 )
    goto LABEL_30;
  if ( !v16 )
    goto LABEL_28;
  v58 = v14 - 8;
  if ( v14 < 8 || (unsigned int)v16[2] - 128 < 0xFFFFFFFE )
    goto LABEL_28;
  v116 = v16[3];
  if ( v116 == 21 )
  {
    if ( (unsigned int)v58 >= 0xC6 )
    {
      v117 = -198;
      v118 = 99;
      goto LABEL_59;
    }
LABEL_28:
    v59 = "%s: Failed in skip SAE field";
LABEL_29:
    qdf_trace_msg(0x35u, 8u, v59, v50, v51, v52, v53, v54, v55, v56, v57, "lim_get_sta_mld_address");
    goto LABEL_30;
  }
  if ( v116 == 20 )
  {
    if ( (unsigned int)v58 >= 0x90 )
    {
      v117 = -144;
      v118 = 72;
      goto LABEL_59;
    }
    goto LABEL_28;
  }
  if ( v116 != 19 || (unsigned int)v58 < 0x60 )
    goto LABEL_28;
  v117 = -96;
  v118 = 48;
LABEL_59:
  if ( !(v117 + v58) )
    goto LABEL_28;
  if ( (unsigned int)util_find_mlie(&v16[v118 + 4], v117 + v58, &v122, v121) )
  {
    v59 = "%s: ML IE not found";
    goto LABEL_29;
  }
  util_get_bvmlie_mldmacaddr(v122, v121[0], (int)&v123);
LABEL_30:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: =======> eSIR_AUTH_TYPE_SAE",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "lim_external_auth_add_pre_auth_node");
  v60 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
  v69 = v15[10];
  v70 = v15[11];
  v71 = v15[12];
  v72 = v15[15];
  if ( v60 )
  {
    v73 = v60;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Creating preauth node for SAE peer %02x:%02x:%02x:**:**:%02x",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "lim_external_auth_add_pre_auth_node",
      v69,
      v70,
      v71,
      v72);
    qdf_mem_copy((void *)(v73 + 8), v15 + 10, 6u);
    qdf_mem_copy((void *)(v73 + 601), &v123, 6u);
    *(_QWORD *)(v73 + 16) = 0x1D00000003LL;
    *(_QWORD *)(v73 + 552) = qdf_mc_timer_get_system_ticks();
    v74 = *((unsigned __int16 *)v15 + 11);
    *(_BYTE *)(v73 + 560) = 0;
    *(_WORD *)(v73 + 544) = v74 >> 4;
    lim_add_pre_auth_node(a1, v73);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Max pre-auth nodes reached %02x:%02x:%02x:**:**:%02x",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "lim_external_auth_add_pre_auth_node",
      v69,
      v70,
      v71,
      v72);
  }
LABEL_33:
  v39 = 2;
LABEL_34:
  sae_auth_retry = mlme_get_sae_auth_retry(*(_QWORD *)(a3 + 16), a4, a5, a6, a7, a8, a9, a10, a11);
  v84 = *(_DWORD *)(a3 + 88);
  if ( v84 == 2 && sae_auth_retry )
  {
    v85 = *(_QWORD *)(sae_auth_retry + 16);
    if ( v85 )
    {
      v86 = *((unsigned __int16 *)a2 + 20);
      if ( *(unsigned __int16 *)(sae_auth_retry + 8) < 0x1Cu || (unsigned int)v86 <= 0x1B )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: rxframe_len %d, queued_frame_len %d, min_len %d",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "lim_is_sae_auth_algo_match",
          v86);
      }
      else
      {
        v87 = *((_QWORD *)a2 + 3);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: sae_auth : rx pkt auth seq %d queued pkt auth seq %d",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "lim_is_sae_auth_algo_match",
          *(unsigned __int16 *)(v87 + 2),
          *(unsigned __int16 *)(v85 + 26));
        if ( *(unsigned __int16 *)(v87 + 2) == *(unsigned __int16 *)(v85 + 26) )
        {
          v88 = *(unsigned __int8 *)(a3 + 10);
          session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a3 + 10));
          if ( session_by_vdev_id )
          {
            v98 = session_by_vdev_id;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: sae auth cleanup for vdev_id %d",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "lim_sae_auth_cleanup_retry",
              v88);
            lim_deactivate_and_change_timer(a1, 20);
            mlme_free_sae_auth_retry(*(_QWORD *)(v98 + 16), v99, v100, v101, v102, v103, v104, v105, v106);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: session not found for given vdev_id %d",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "lim_sae_auth_cleanup_retry",
              v88);
          }
        }
      }
    }
    v84 = *(_DWORD *)(a3 + 88);
  }
  if ( v84 == 2
    && (wlan_connectivity_mgmt_event(
          *(_QWORD *)(a1 + 21624),
          (int)v15,
          *(unsigned __int8 *)(a3 + 10),
          v120,
          0,
          a2[2],
          v18,
          v17,
          v17,
          0,
          3),
        lim_cp_stats_cstats_log_auth_evt(a3, 1, v18, v17, v120),
        (v107 = lim_update_link_to_mld_address(a1, *(_QWORD *)(a3 + 16), v15)) != 0) )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: vdev:%d STA SAE address conversion failed status:%d",
               v108,
               v109,
               v110,
               v111,
               v112,
               v113,
               v114,
               v115,
               "lim_process_sae_auth_frame",
               *(unsigned __int8 *)(a3 + 10),
               v107);
  }
  else
  {
    result = lim_send_sme_mgmt_frame_ind(a1, *v15 >> 4, v15, v14 + 24, *(unsigned __int8 *)(a3 + 10), *a2, a2[2], v39);
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
