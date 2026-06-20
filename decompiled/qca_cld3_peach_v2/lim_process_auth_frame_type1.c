__int64 __fastcall lim_process_auth_frame_type1(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        unsigned __int16 a4,
        _WORD *a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int8 *v29; // x26
  _WORD *v30; // x25
  int v31; // w27
  unsigned __int8 *v32; // x26
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  __int64 v42; // x1
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x25
  __int64 result; // x0
  unsigned __int16 v54; // w24
  _WORD *hash_entry; // x0
  _WORD *v56; // x26
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x4
  __int64 v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x24
  char v92; // w8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned __int16 v110; // w8
  __int64 v111; // x5
  __int64 v112; // x6
  const char *v113; // x2
  __int16 v114; // w8
  __int16 v115; // w9
  __int64 v116; // x0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x24
  char v126; // w8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int16 v143; // w8
  __int16 v144; // w9
  __int64 v145; // x7
  int v146; // w8
  const char *v147; // x3
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  unsigned __int16 v156; // w8
  _QWORD v157[17]; // [xsp+18h] [xbp-88h] BYREF

  v157[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(v157[0]) = 0;
  v20 = dph_lookup_hash_entry(a7, a8, a9, a10, a11, a12, a13, a14, a1, (unsigned __int8 *)(a2 + 10), v157, a6 + 360);
  if ( !v20 )
    goto LABEL_12;
  v29 = *(unsigned __int8 **)(a1 + 12392);
  v30 = (_WORD *)v20;
  if ( !v29 || (unsigned int)qdf_mem_cmp((const void *)(a2 + 10), *(const void **)(a1 + 12392), 6u) )
  {
    v31 = 1;
    v32 = *(unsigned __int8 **)(a1 + 12400);
    if ( !v32 )
      goto LABEL_8;
LABEL_7:
    if ( !(unsigned int)qdf_mem_cmp((const void *)(a2 + 10), v32, 6u) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: TODO:Ack for deauth frame is pending Issue del sta for %02x:%02x:%02x:**:**:%02x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_check_and_trigger_pmf_sta_deletion",
        *v32,
        v32[1],
        v32[2],
        v32[5]);
      lim_process_deauth_ack_timeout(a1, *(unsigned __int8 *)(a6 + 10));
      goto LABEL_12;
    }
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: TODO:Ack pending for disassoc frame Issue del sta for %02x:%02x:%02x:**:**:%02x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "lim_check_and_trigger_pmf_sta_deletion",
    *v29,
    v29[1],
    v29[2],
    v29[5]);
  lim_process_disassoc_ack_timeout(a1);
  v31 = 0;
  v32 = *(unsigned __int8 **)(a1 + 12400);
  if ( v32 )
    goto LABEL_7;
LABEL_8:
  if ( v31 && (*v30 & 0x400) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: STA is already connected but received auth frameSend the Deauth and lim Delete Station Context(associd: %d) st"
      "a mac%02x:%02x:%02x:**:**:%02x",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_check_and_trigger_pmf_sta_deletion",
      LOWORD(v157[0]),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 11),
      *(unsigned __int8 *)(a2 + 12),
      *(unsigned __int8 *)(a2 + 15));
    lim_send_deauth_mgmt_frame(a1, 1, a2 + 10, a6, 0);
    v41 = a1;
    v42 = (__int64)v30;
LABEL_26:
    result = lim_trigger_sta_deletion(v41, v42, a6, v33, v34, v35, v36, v37, v38, v39, v40);
    goto LABEL_52;
  }
LABEL_12:
  v43 = lim_search_pre_auth_list(a1, a2 + 10);
  if ( !v43 )
    goto LABEL_27;
  v52 = v43;
  if ( (*(_WORD *)a2 & 0x800) == 0 || *(unsigned __int16 *)(v43 + 544) != a4 )
  {
    if ( (*(_BYTE *)(v43 + 278) & 1) != 0 )
      lim_deactivate_and_change_per_sta_id_timer(a1, 9, *(unsigned __int8 *)(v43 + 24));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: STA is initiating brand-new Auth",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "lim_process_auth_frame_type1");
    lim_delete_pre_auth_node(a1, a2 + 10);
    if ( *(_WORD *)(a6 + 376) )
    {
      v54 = 0;
      while ( 1 )
      {
        hash_entry = (_WORD *)dph_get_hash_entry(a1, v54, a6 + 360);
        if ( hash_entry )
        {
          if ( (*hash_entry & 1) != 0 )
          {
            v56 = hash_entry;
            if ( !(unsigned int)qdf_mem_cmp(hash_entry + 175, (const void *)(a2 + 10), 6u) )
              break;
          }
        }
        if ( *(unsigned __int16 *)(a6 + 376) <= (unsigned int)++v54 )
          goto LABEL_27;
      }
      if ( (*v56 & 0x400) == 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: lim Del Sta Ctx associd: %d sta mac%02x:%02x:%02x:**:**:%02x",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "lim_process_auth_frame_type1",
          v54,
          *((unsigned __int8 *)v56 + 350),
          *((unsigned __int8 *)v56 + 351),
          *((unsigned __int8 *)v56 + 352),
          *((unsigned __int8 *)v56 + 355));
        lim_send_deauth_mgmt_frame(a1, 1, v52 + 8, a6, 0);
        v41 = a1;
        v42 = (__int64)v56;
        goto LABEL_26;
      }
    }
LABEL_27:
    if ( *(_DWORD *)(a1 + 11404) == *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1896LL)
      && !(unsigned __int8)lim_delete_open_auth_pre_auth_node(a1) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Max no of preauth context reached",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_process_auth_frame_type1");
      v114 = *a3;
      v115 = 1;
LABEL_50:
      *a5 = v114;
      a5[1] = a3[1] + 1;
      a5[2] = v115;
LABEL_51:
      result = lim_send_auth_mgmt_frame(a1, a5, a2 + 10, 0, a6);
      goto LABEL_52;
    }
    result = lim_is_auth_algo_supported(a1, *a3, a6);
    v81 = *a3;
    if ( !(_BYTE)result )
    {
      v111 = *(unsigned __int8 *)(a2 + 10);
      v112 = *(unsigned __int8 *)(a2 + 11);
      v113 = "%s: received Authentication frame for unsupported auth algorithm %d %02x:%02x:%02x:**:**:%02x";
LABEL_48:
      v145 = *(unsigned __int8 *)(a2 + 12);
      v146 = *(unsigned __int8 *)(a2 + 15);
      v147 = "lim_process_auth_frame_type1";
LABEL_49:
      qdf_trace_msg(0x35u, 2u, v113, v73, v74, v75, v76, v77, v78, v79, v80, v147, v81, v111, v112, v145, v146);
      v114 = *a3;
      v115 = 13;
      goto LABEL_50;
    }
    if ( (_DWORD)v81 == 4 )
      goto LABEL_52;
    if ( (_DWORD)v81 != 1 )
    {
      if ( !*a3 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: =======> eSIR_OPEN_SYSTEM",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "lim_process_auth_open_system_algo");
        v82 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
        if ( !v82 )
        {
          result = qdf_trace_msg(
                     0x35u,
                     3u,
                     "%s: Max pre-auth nodes reached SA: %02x:%02x:%02x:**:**:%02x",
                     v83,
                     v84,
                     v85,
                     v86,
                     v87,
                     v88,
                     v89,
                     v90,
                     "lim_process_auth_open_system_algo",
                     *(unsigned __int8 *)(a2 + 10),
                     *(unsigned __int8 *)(a2 + 11),
                     *(unsigned __int8 *)(a2 + 12),
                     *(unsigned __int8 *)(a2 + 15));
          goto LABEL_52;
        }
        v91 = v82;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Alloc new data: %pK peer %02x:%02x:%02x:**:**:%02x",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "lim_process_auth_open_system_algo",
          v82,
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned __int8 *)(a2 + 11),
          *(unsigned __int8 *)(a2 + 12),
          *(unsigned __int8 *)(a2 + 15));
        qdf_mem_copy((void *)(v91 + 8), (const void *)(a2 + 10), 6u);
        *(_DWORD *)(v91 + 20) = 9;
        v92 = *(_BYTE *)(v91 + 278) & 0xFC;
        *(_DWORD *)(v91 + 16) = *a3;
        *(_BYTE *)(v91 + 278) = v92;
        *(_WORD *)(v91 + 544) = *(_WORD *)(a2 + 22) >> 4;
        *(_QWORD *)(v91 + 552) = qdf_mc_timer_get_system_ticks();
        v101 = *(_QWORD *)(a6 + 16);
        if ( *(_DWORD *)(v101 + 16) == 1
          && (wlan_vdev_mlme_is_mlo_vdev(v101, v93, v94, v95, v96, v97, v98, v99, v100) & 1) != 0
          && *((_BYTE *)a3 + 1016) == 1 )
        {
          *(_BYTE *)(v91 + 600) = 1;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: MLO IE is present in auth req",
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            "lim_process_auth_open_system_algo");
        }
        lim_add_pre_auth_node(a1, v91);
        *a5 = *a3;
        v110 = a3[1];
        a5[2] = 0;
        a5[1] = v110 + 1;
        goto LABEL_51;
      }
      v111 = *(unsigned __int8 *)(a2 + 10);
      v112 = *(unsigned __int8 *)(a2 + 11);
      v113 = "%s: rx Auth frm for unsupported auth algo %d %02x:%02x:%02x:**:**:%02x";
      goto LABEL_48;
    }
    memset(v157, 0, 128);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: =======> eSIR_SHARED_KEY",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "lim_process_auth_shared_system_algo");
    if ( *(_DWORD *)(a6 + 88) == 1 )
    {
      if ( *(_BYTE *)(a6 + 1620) )
        goto LABEL_43;
    }
    else if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5652LL) )
    {
LABEL_43:
      v116 = lim_acquire_free_pre_auth_node(a1, (unsigned int *)(a1 + 11408));
      if ( !v116 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   3u,
                   "%s: Max preauth-nodes reached SA: %02x:%02x:%02x:**:**:%02x",
                   v117,
                   v118,
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   "lim_process_auth_shared_system_algo",
                   *(unsigned __int8 *)(a2 + 10),
                   *(unsigned __int8 *)(a2 + 11),
                   *(unsigned __int8 *)(a2 + 12),
                   *(unsigned __int8 *)(a2 + 15));
        goto LABEL_52;
      }
      v125 = v116;
      qdf_mem_copy((void *)(v116 + 8), (const void *)(a2 + 10), 6u);
      *(_DWORD *)(v125 + 20) = 6;
      v126 = *(_BYTE *)(v125 + 278) & 0xFC;
      *(_DWORD *)(v125 + 16) = *a3;
      *(_BYTE *)(v125 + 278) = v126;
      *(_WORD *)(v125 + 544) = *(_WORD *)(a2 + 22) >> 4;
      *(_QWORD *)(v125 + 552) = qdf_mc_timer_get_system_ticks();
      lim_add_pre_auth_node(a1, v125);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Alloc new data: %pK id: %d peer %02x:%02x:%02x:**:**:%02x",
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        "lim_process_auth_shared_system_algo",
        v125,
        *(unsigned __int8 *)(v125 + 24),
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a2 + 11),
        *(unsigned __int8 *)(a2 + 12),
        *(unsigned __int8 *)(a2 + 15));
      if ( (unsigned int)tx_timer_change_context(v125 + 280, *(unsigned __int8 *)(v125 + 24)) )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Unable to chg context auth response timer for peer %02x:%02x:%02x:**:**:%02x",
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          "lim_process_auth_shared_system_algo",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned __int8 *)(a2 + 11),
          *(unsigned __int8 *)(a2 + 12),
          *(unsigned __int8 *)(a2 + 15));
        v143 = *a3;
        v144 = 1;
      }
      else
      {
        get_random_bytes(v157, 128);
        qdf_mem_set((void *)(v125 + 25), 0x80u, 0);
        if ( (unsigned int)qdf_mem_cmp(v157, (const void *)(v125 + 25), 0x80u) )
        {
          lim_activate_auth_rsp_timer(a1, v125);
          *(_BYTE *)(v125 + 278) |= 1u;
          qdf_mem_copy((void *)(v125 + 25), v157, 0x80u);
          *a5 = *a3;
          v156 = a3[1];
          *((_DWORD *)a5 + 1) = -2146435072;
          a5[1] = v156 + 1;
          qdf_mem_copy(a5 + 4, (const void *)(v125 + 25), 0x80u);
          goto LABEL_51;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Challenge text preparation failed SA: %02x:%02x:%02x:**:**:%02x",
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          "lim_process_auth_shared_system_algo",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned __int8 *)(a2 + 11),
          *(unsigned __int8 *)(a2 + 12),
          *(unsigned __int8 *)(a2 + 15));
        v143 = *a3;
        v144 = 30;
      }
      *a5 = v143;
      a5[1] = a3[1] + 1;
      a5[2] = v144;
      lim_send_auth_mgmt_frame(a1, a5, a2 + 10, 0, a6);
      result = lim_delete_pre_auth_node(a1, a2 + 10);
      goto LABEL_52;
    }
    v81 = *a3;
    v111 = *(unsigned __int8 *)(a2 + 10);
    v113 = "%s: rx Auth frame for unsupported auth algorithm %d %02x:%02x:%02x:**:**:%02x";
    v112 = *(unsigned __int8 *)(a2 + 11);
    v145 = *(unsigned __int8 *)(a2 + 12);
    v146 = *(unsigned __int8 *)(a2 + 15);
    v147 = "lim_process_auth_shared_system_algo";
    goto LABEL_49;
  }
  result = qdf_trace_msg(
             0x35u,
             3u,
             "%s: STA is initiating Auth after ACK lost",
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             "lim_process_auth_frame_type1");
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
