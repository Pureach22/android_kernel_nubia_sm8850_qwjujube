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
  unsigned int v11; // w28
  unsigned __int16 *v12; // x8
  unsigned __int8 *v13; // x19
  unsigned int v17; // w23
  unsigned int v18; // w24
  unsigned int v19; // w25
  __int64 v20; // x27
  unsigned int v21; // w8
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x7
  int v25; // w8
  int v26; // w9
  int v27; // w10
  int v28; // w8
  __int64 v29; // x0
  int v30; // w8
  unsigned int v31; // w26
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  __int64 v54; // x27
  unsigned int v55; // w8
  __int64 sae_auth_retry; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w8
  __int64 v66; // x27
  __int64 v67; // x4
  unsigned int v68; // w28
  unsigned int v69; // w23
  unsigned int v70; // w25
  __int64 v71; // x24
  int v72; // w8
  unsigned int v73; // w27
  __int64 session_by_vdev_id; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+0h] [xbp-30h]
  __int64 v92; // [xsp+20h] [xbp-10h]
  unsigned int v93; // [xsp+2Ch] [xbp-4h]

  v11 = a2[10];
  v13 = *((unsigned __int8 **)a2 + 2);
  v12 = *((unsigned __int16 **)a2 + 3);
  if ( v11 < 6 )
  {
    v17 = 0;
    v18 = 0;
  }
  else
  {
    v17 = v12[1];
    v18 = v12[2];
  }
  v19 = *v12;
  v20 = jiffies;
  if ( lim_process_sae_auth_frame___last_ticks - jiffies + 125 < 0 )
  {
    v21 = *(unsigned __int16 *)v13;
    v22 = (v21 >> 2) & 3;
    v23 = (unsigned __int8)v21 >> 4;
    if ( v13 == (unsigned __int8 *)-10LL )
    {
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v27 = 0;
    }
    else
    {
      v24 = v13[10];
      v25 = v13[11];
      v26 = v13[12];
      v27 = v13[15];
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
      v22,
      v23,
      v17,
      v24,
      v25,
      v26,
      v27);
    lim_process_sae_auth_frame___last_ticks = v20;
  }
  v28 = *(_DWORD *)(a3 + 88);
  if ( v28 == 2 )
  {
    if ( *(_DWORD *)(a3 + 72) == 29 )
    {
LABEL_17:
      v31 = 0;
      goto LABEL_26;
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
    v28 = *(_DWORD *)(a3 + 88);
  }
  if ( v28 != 1 )
    goto LABEL_17;
  v29 = lim_search_pre_auth_list(a1, v13 + 10);
  if ( !v29 )
  {
LABEL_20:
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3207LL) == (unsigned __int8)pe_get_current_stas_count(a1) )
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: Max Sta count reached : %d",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "lim_process_sae_auth_frame",
               *(unsigned __int16 *)(a1 + 3990));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: =======> eSIR_AUTH_TYPE_SAE",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_external_auth_add_pre_auth_node");
    v41 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
    v50 = v13[10];
    v51 = v13[11];
    v52 = v13[12];
    v53 = v13[15];
    if ( v41 )
    {
      v54 = v41;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Creating preauth node for SAE peer %02x:%02x:%02x:**:**:%02x",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "lim_external_auth_add_pre_auth_node",
        v50,
        v51,
        v52,
        v53);
      qdf_mem_copy((void *)(v54 + 8), v13 + 10, 6u);
      *(_QWORD *)(v54 + 16) = 0x1D00000003LL;
      *(_QWORD *)(v54 + 552) = qdf_mc_timer_get_system_ticks();
      v55 = *((unsigned __int16 *)v13 + 11);
      *(_BYTE *)(v54 + 560) = 0;
      *(_WORD *)(v54 + 544) = v55 >> 4;
      lim_add_pre_auth_node(a1, v54);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Max pre-auth nodes reached %02x:%02x:%02x:**:**:%02x",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "lim_external_auth_add_pre_auth_node",
        v50,
        v51,
        v52,
        v53);
    }
    goto LABEL_25;
  }
  if ( *(_DWORD *)(v29 + 20) != 29 )
  {
    if ( v13 == (unsigned __int8 *)-10LL )
      v30 = 0;
    else
      v30 = v13[15];
    LODWORD(v91) = v30;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Delete existing preauth node for SAE peer in state: %u %02x:%02x:%02x:**:**:%02x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_sae_auth_frame",
      v91);
    lim_delete_pre_auth_node(a1, v13 + 10);
    goto LABEL_20;
  }
LABEL_25:
  v31 = 2;
LABEL_26:
  sae_auth_retry = mlme_get_sae_auth_retry(*(_QWORD *)(a3 + 16), a4, a5, a6, a7, a8, a9, a10, a11);
  v65 = *(_DWORD *)(a3 + 88);
  if ( v65 == 2 && sae_auth_retry )
  {
    v66 = *(_QWORD *)(sae_auth_retry + 16);
    if ( v66 )
    {
      v67 = *((unsigned __int16 *)a2 + 20);
      if ( *(unsigned __int16 *)(sae_auth_retry + 8) < 0x1Cu || (unsigned int)v67 <= 0x1B )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: rxframe_len %d, queued_frame_len %d, min_len %d",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "lim_is_sae_auth_algo_match",
          v67);
      }
      else
      {
        v93 = v11;
        v68 = v17;
        v69 = v19;
        v70 = v18;
        v71 = *((_QWORD *)a2 + 3);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: sae_auth : rx pkt auth seq %d queued pkt auth seq %d",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "lim_is_sae_auth_algo_match",
          *(unsigned __int16 *)(v71 + 2),
          *(unsigned __int16 *)(v66 + 26));
        v72 = *(unsigned __int16 *)(v71 + 2);
        v18 = v70;
        v19 = v69;
        v17 = v68;
        v11 = v93;
        if ( v72 == *(unsigned __int16 *)(v66 + 26) )
        {
          v73 = *(unsigned __int8 *)(a3 + 10);
          session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a3 + 10));
          if ( session_by_vdev_id )
          {
            v92 = session_by_vdev_id;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: sae auth cleanup for vdev_id %d",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "lim_sae_auth_cleanup_retry",
              v73);
            lim_deactivate_and_change_timer(a1, 20);
            mlme_free_sae_auth_retry(*(_QWORD *)(v92 + 16), v83, v84, v85, v86, v87, v88, v89, v90);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: session not found for given vdev_id %d",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "lim_sae_auth_cleanup_retry",
              v73);
          }
        }
      }
    }
    v65 = *(_DWORD *)(a3 + 88);
  }
  if ( v65 == 2 )
  {
    wlan_connectivity_mgmt_event(
      *(_QWORD *)(a1 + 21552),
      (int)v13,
      *(unsigned __int8 *)(a3 + 10),
      v18,
      0,
      a2[2],
      v19,
      v17,
      v17,
      0,
      3);
    lim_cp_stats_cstats_log_auth_evt(a3, 1, v19, v17, v18);
  }
  return lim_send_sme_mgmt_frame_ind(a1, *v13 >> 4, v13, v11 + 24, *(unsigned __int8 *)(a3 + 10), *a2, a2[2], v31);
}
