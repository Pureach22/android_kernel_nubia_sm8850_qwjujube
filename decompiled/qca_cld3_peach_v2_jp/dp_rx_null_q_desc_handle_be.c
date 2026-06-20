__int64 __fastcall dp_rx_null_q_desc_handle_be(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 *a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 v13; // x0
  unsigned int v14; // w26
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 (*v20)(void); // x8
  unsigned int v21; // w23
  _DWORD *v22; // x8
  __int64 (__fastcall *v23)(_QWORD); // x8
  unsigned __int16 v24; // w0
  unsigned int v25; // w27
  __int64 result; // x0
  unsigned int v27; // w9
  unsigned int v28; // w8
  int v29; // w9
  int v30; // w9
  int v31; // w10
  unsigned int (__fastcall *v32)(_QWORD); // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x25
  __int64 v42; // x8
  unsigned __int64 v43; // x1
  __int64 v44; // x27
  void (*v45)(void); // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x23
  __int64 v55; // x24
  int v56; // w8
  __int64 v57; // x22
  __int64 v58; // x8
  int v59; // w8
  unsigned __int8 (__fastcall *v60)(_QWORD); // x8
  __int64 (__fastcall *v61)(_QWORD); // x8
  unsigned __int16 v62; // w26
  unsigned __int8 (__fastcall *v63)(_QWORD); // x8
  __int64 (__fastcall *v64)(_QWORD); // x8
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
  __int64 (__fastcall *v81)(_QWORD); // x8
  __int64 ref_by_id; // x0
  __int64 v83; // x26
  __int64 v84; // x28
  __int64 v85; // x2
  __int64 v86; // x1
  __int64 v87; // x0
  unsigned __int8 *v88; // x27
  bool is_ipv4_eapol_pkt; // w26
  __int64 v90; // x20
  __int64 v91; // x22
  int v92; // w8
  __int64 v93; // x1
  __int64 v94; // x2
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x24
  __int64 v104; // x8
  _QWORD *v105; // x0
  _QWORD *v106; // x26
  __int64 v107; // x8
  void (__fastcall *v108)(__int64, __int64); // x9
  unsigned int (__fastcall *v109)(_QWORD); // x8
  unsigned int v110; // w21
  __int64 *v111; // x28
  __int64 v112; // x9
  __int64 v113; // x10
  int v114; // w8
  unsigned __int8 (__fastcall *v115)(_QWORD); // x8
  int v116; // w8
  unsigned int v117; // w8
  __int64 *v118; // x9
  __int64 v119; // x8
  unsigned __int64 *v120; // x8
  __int64 v121; // t1
  unsigned __int64 v122; // x10
  unsigned __int64 v123; // x9
  __int64 v124; // x8
  __int64 v125; // x22
  int v126; // w8
  __int64 v127; // x0
  __int64 v128; // x0
  unsigned __int16 (__fastcall *v129)(_QWORD); // x8
  int v130; // w8
  __int64 v131; // x0
  __int64 v132; // [xsp+8h] [xbp-18h]
  _QWORD v133[2]; // [xsp+10h] [xbp-10h] BYREF

  v133[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 40);
  v133[0] = 0;
  LOWORD(v14) = wlan_cfg_rx_buffer_size(v13);
  v15 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 560LL);
  if ( *((_DWORD *)v15 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xFE | v15(a3) & 1;
  v16 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 576LL);
  if ( *((_DWORD *)v16 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xFB | (4 * (v16(a3) & 1));
  v17 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 496LL);
  if ( *((_DWORD *)v17 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xEF | (16 * (v17(a3) & 1));
  v18 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 568LL);
  if ( *((_DWORD *)v18 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xDF | (32 * (v18(a3) & 1));
  v19 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 512LL);
  if ( *((_DWORD *)v19 - 1) != -1147376687 )
    __break(0x8228u);
  *(_BYTE *)(a2 + 84) = *(_BYTE *)(a2 + 84) & 0xBF | ((v19(a3) & 1) << 6);
  v20 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 680LL);
  if ( *((_DWORD *)v20 - 1) != 1397649485 )
    __break(0x8228u);
  v21 = v20();
  v22 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
  if ( *(v22 - 1) != -177782713 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *))v22)(a3, v133);
  v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
  if ( *((_DWORD *)v23 - 1) != 855462014 )
    __break(0x8228u);
  v24 = v23(a3);
  if ( (*(char *)(a2 + 84) & 0x80000000) == 0 )
  {
    v25 = LOWORD(v133[0]) + v24 + *(unsigned __int16 *)(a1 + 1138);
    if ( (dp_rx_check_pkt_len(a1, v25) & 1) != 0 )
      goto LABEL_19;
    v27 = *(_DWORD *)(a2 + 112);
    if ( v25 >= (unsigned __int16)v14 )
      v14 = (unsigned __int16)v14;
    else
      v14 = v25;
    v28 = v14 - v27;
    if ( v14 < v27 )
    {
      skb_trim(a2, v14);
      goto LABEL_36;
    }
    if ( *(_DWORD *)(a2 + 116) )
    {
      v28 = v14 - v27;
      if ( v14 != v27 )
      {
        v29 = 0;
        goto LABEL_33;
      }
    }
    else
    {
      v31 = *(_DWORD *)(a2 + 208);
      v30 = *(_DWORD *)(a2 + 212);
      if ( v30 - v31 < v28 )
      {
        v29 = v31 - v30;
LABEL_33:
        if ( (unsigned int)pskb_expand_head(a2, 0, v29 + v28, 2080) )
          dev_kfree_skb_any_reason(a2, 1);
      }
    }
    skb_put(a2, v14 - *(_DWORD *)(a2 + 112));
  }
LABEL_36:
  v32 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1264LL);
  if ( *((_DWORD *)v32 - 1) != 855462014 )
    __break(0x8228u);
  if ( v32(a3) )
  {
    if ( a5 )
      goto LABEL_40;
  }
  else
  {
    v44 = jiffies;
    if ( dp_rx_null_q_desc_handle_be___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: MSDU DONE failure",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "dp_rx_null_q_desc_handle_be");
      dp_rx_null_q_desc_handle_be___last_ticks = v44;
    }
    v45 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1240LL);
    if ( *((_DWORD *)v45 - 1) != 343547449 )
      __break(0x8228u);
    v45();
    if ( a5 )
    {
LABEL_40:
      v41 = *a5;
      if ( !*a5 )
      {
        v57 = jiffies;
        if ( dp_rx_null_q_desc_handle_be___last_ticks_36 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Null vdev!",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "dp_rx_null_q_desc_handle_be");
          dp_rx_null_q_desc_handle_be___last_ticks_36 = v57;
        }
        if ( a1 )
          ++*(_DWORD *)(a1 + 13692);
        goto LABEL_19;
      }
      if ( *(char *)(a2 + 84) < 0 )
      {
        v58 = *(_QWORD *)(a2 + 40);
        v43 = *(unsigned __int16 *)(a1 + 1138);
        if ( v58 )
          *(_QWORD *)(a2 + 40) = v58 + v43;
      }
      else
      {
        v42 = *(_QWORD *)(a2 + 40);
        v43 = LOWORD(v133[0]) + (unsigned __int64)*(unsigned __int16 *)(a1 + 1138);
        if ( v42 )
          *(_QWORD *)(a2 + 40) = v43 + v42;
      }
      skb_pull(a2, v43);
      ++*(_QWORD *)(v41 + 2840);
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v59 = *(unsigned __int16 *)(a2 + 66);
      else
        v59 = 0;
      *(_QWORD *)(v41 + 2848) += (unsigned int)(*(_DWORD *)(a2 + 112) + v59);
      if ( (dp_rx_err_drop_3addr_mcast(v41, a3) & 1) != 0 )
      {
        ++LODWORD(a5[407 * (unsigned __int8)a7 + 404]);
LABEL_19:
        if ( a2 )
          _qdf_nbuf_free(a2);
        goto LABEL_21;
      }
      v60 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 512LL);
      if ( *((_DWORD *)v60 - 1) != -1147376687 )
        __break(0x8228u);
      if ( v60(a3) )
      {
        v61 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 520LL);
        if ( *((_DWORD *)v61 - 1) != 646946022 )
          __break(0x8228u);
        v62 = v61(a3);
        if ( (int)wlan_cfg_get_max_ast_idx(*(_QWORD *)(a1 + 40)) <= v62 )
        {
          if ( a1 )
            ++*(_DWORD *)(a1 + 13708);
          goto LABEL_19;
        }
      }
      if ( (a5[11] & 1) != 0 )
      {
        v63 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 496LL);
        if ( *((_DWORD *)v63 - 1) != -1147376687 )
          __break(0x8228u);
        if ( v63(a3) )
        {
          v64 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 584LL);
          if ( *((_DWORD *)v64 - 1) != -1147376687 )
            __break(0x8228u);
          if ( (v64(a3) & 1) == 0 )
          {
            v125 = jiffies;
            if ( dp_rx_null_q_desc_handle_be___last_ticks_38 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: free buffer for multicast packet",
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                "dp_rx_null_q_desc_handle_be");
              dp_rx_null_q_desc_handle_be___last_ticks_38 = v125;
            }
            ++LODWORD(a5[407 * (unsigned __int8)a7 + 382]);
            goto LABEL_19;
          }
        }
      }
      if ( !(unsigned int)dp_wds_rx_policy_check(a3, v41, a5) )
      {
        v91 = jiffies;
        if ( dp_rx_null_q_desc_handle_be___last_ticks_40 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: mcast Policy Check Drop pkt",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "dp_rx_null_q_desc_handle_be");
          dp_rx_null_q_desc_handle_be___last_ticks_40 = v91;
        }
        ++LODWORD(a5[407 * (unsigned __int8)a7 + 399]);
        goto LABEL_19;
      }
      v81 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 672LL);
      if ( *((_DWORD *)v81 - 1) != -1147376687 )
        __break(0x8228u);
      if ( (v81(a3) & 1) != 0 )
      {
        ref_by_id = dp_peer_get_ref_by_id(a1, *((unsigned __int16 *)a5 + 4), 4);
        if ( ref_by_id )
        {
          v83 = ref_by_id;
          v132 = (unsigned __int8)v21;
          v84 = *(_QWORD *)(ref_by_id + 88) + 144 * v132;
          qdf_spin_lock_bh_8(v84 + 88);
          if ( !*(_QWORD *)(*(_QWORD *)(v83 + 88) + 144 * v132 + 32) )
          {
            if ( *(_DWORD *)(v41 + 64) || (a5[11] & 1) != 0 )
            {
              v129 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1160LL);
              if ( *((_DWORD *)v129 - 1) != 769334334 )
                __break(0x8228u);
              v85 = v129(v132);
              v87 = v83;
              v86 = (unsigned int)(1LL << v132);
            }
            else
            {
              v85 = 1;
              v86 = 1LL << v132;
              v87 = v83;
            }
            dp_rx_tid_setup_wifi3(v87, v86, v85, 4096);
          }
          qdf_spin_unlock_bh_6(v84 + 88);
          dp_peer_unref_delete(v83, 4);
        }
      }
      v88 = *(unsigned __int8 **)(a2 + 224);
      if ( (*((_BYTE *)a5 + 10) & 1) != 0 )
      {
        is_ipv4_eapol_pkt = 0;
      }
      else
      {
        is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224));
        if ( !is_ipv4_eapol_pkt && !_qdf_nbuf_is_ipv4_wapi_pkt(a2)
          || !(unsigned int)dp_rx_err_match_dhost(v88, v41, (*((unsigned __int8 *)a5 + 10) >> 3) & 1) )
        {
          goto LABEL_19;
        }
      }
      if ( !*(_DWORD *)(v41 + 44) )
      {
        v124 = *(_QWORD *)(a2 + 72);
        *(_QWORD *)a2 = 0;
        *(_QWORD *)(a2 + 72) = v124 | 0x800000;
        dp_rx_deliver_raw(v41, a2, a5, a7);
        result = 0;
        goto LABEL_22;
      }
      *(_QWORD *)a2 = 0;
      ++a5[4];
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v92 = *(unsigned __int16 *)(a2 + 66);
      else
        v92 = 0;
      v111 = a5 + 278;
      v112 = (__int64)&a5[407 * (unsigned __int8)a7 + 278];
      v113 = *(_QWORD *)(v112 + 992);
      a5[5] += (unsigned int)(*(_DWORD *)(a2 + 112) + v92);
      *(_QWORD *)(v112 + 992) = v113 + 1;
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v114 = *(unsigned __int16 *)(a2 + 66);
      else
        v114 = 0;
      v111[407 * (unsigned __int8)a7 + 125] += (unsigned int)(*(_DWORD *)(a2 + 112) + v114);
      v115 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 496LL);
      if ( *((_DWORD *)v115 - 1) != -1147376687 )
        __break(0x8228u);
      if ( v115(a3) && *(_DWORD *)(v41 + 44) == 2 )
      {
        ++v111[407 * (unsigned __int8)a7 + 98];
        if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
          v126 = *(unsigned __int16 *)(a2 + 66);
        else
          v126 = 0;
        v111[407 * (unsigned __int8)a7 + 99] += (unsigned int)(*(_DWORD *)(a2 + 112) + v126);
        if ( *v88 != 255 || v88[1] != 255 || v88[2] != 255 || v88[3] != 255 || v88[4] != 255 || v88[5] != 255 )
          goto LABEL_147;
        ++v111[407 * (unsigned __int8)a7 + 100];
        if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
          v130 = *(unsigned __int16 *)(a2 + 66);
        else
          v130 = 0;
        v117 = *(_DWORD *)(a2 + 112) + v130;
        v118 = &v111[407 * (unsigned __int8)a7 + 101];
      }
      else
      {
        ++v111[407 * (unsigned __int8)a7 + 96];
        if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
          v116 = *(unsigned __int16 *)(a2 + 66);
        else
          v116 = 0;
        v117 = *(_DWORD *)(a2 + 112) + v116;
        v118 = &v111[407 * (unsigned __int8)a7 + 97];
      }
      *v118 += v117;
LABEL_147:
      *(_DWORD *)(a2 + 48) |= 0x80u;
      if ( *(_BYTE *)(v41 + 80) != 1 || (dp_rx_multipass_process(a5, a2, v21) & 1) != 0 )
      {
        dp_rx_deliver_to_osif_stack(a1, v41, a5, a2, 0, is_ipv4_eapol_pkt);
        result = 0;
        goto LABEL_22;
      }
      ++LODWORD(v111[407 * (unsigned __int8)a7 + 120]);
      goto LABEL_19;
    }
  }
  if ( (dp_rx_null_q_handle_invalid_peer_id_exception(a1, a4, a3, a2) & 1) != 0 )
    goto LABEL_21;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), (unsigned __int8)a4)
    || (v54 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    v90 = jiffies;
    if ( dp_rx_null_q_desc_handle_be___last_ticks_32 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: pdev is null for pool_id = %d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "dp_rx_null_q_desc_handle_be",
        (unsigned __int8)a4);
      dp_rx_null_q_desc_handle_be___last_ticks_32 = v90;
    }
    goto LABEL_21;
  }
  v55 = jiffies;
  if ( dp_rx_null_q_desc_handle_be___last_ticks_34 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: txrx_peer is NULL",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "dp_rx_null_q_desc_handle_be");
    dp_rx_null_q_desc_handle_be___last_ticks_34 = v55;
  }
  if ( a1 )
  {
    ++*(_QWORD *)(a1 + 13720);
    if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
      v56 = *(unsigned __int16 *)(a2 + 66);
    else
      v56 = 0;
    *(_QWORD *)(a1 + 13728) += (unsigned int)(*(_DWORD *)(a2 + 112) + v56);
  }
  if ( *(_BYTE *)(a1 + 18718) == 1 )
  {
    *(_QWORD *)a2 = 0;
    dp_rx_process_invalid_peer_wrapper(a1, a2, 1, a4);
LABEL_167:
    *(_QWORD *)(v54 + 368) = 0;
    *(_QWORD *)(v54 + 376) = 0;
    goto LABEL_21;
  }
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), (unsigned __int8)a4)
    || (v103 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x7Eu,
      8u,
      "%s: %pK: pdev is null for mac_id = %d",
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      "dp_rx_chain_msdus_be",
      a1,
      (unsigned __int8)a4);
    dp_rx_process_invalid_peer_wrapper(a1, *(_QWORD *)(v54 + 368), 0, a4);
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v103 + 95060) == 1 )
  {
    v104 = *(_QWORD *)(v103 + 368);
    if ( !v104 || *(_DWORD *)(v104 + 72) >> 25 < 5u )
      goto LABEL_126;
  }
  *(_BYTE *)(a2 + 84) |= 1u;
  v105 = *(_QWORD **)(v103 + 368);
  *(_BYTE *)(v103 + 95060) = 1;
  if ( v105 )
  {
    do
    {
      v106 = (_QWORD *)*v105;
      _qdf_nbuf_free((__int64)v105);
      v105 = v106;
    }
    while ( v106 );
  }
  v107 = *(_QWORD *)(v103 + 95560);
  *(_QWORD *)(v103 + 368) = 0;
  *(_QWORD *)(v103 + 376) = 0;
  if ( !v107 )
  {
LABEL_126:
    if ( (*(_BYTE *)(a2 + 84) & 4) == 0 )
      goto LABEL_149;
    v109 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1264LL);
    if ( *((_DWORD *)v109 - 1) != 855462014 )
      __break(0x8228u);
    if ( v109(a3) )
    {
      if ( (*(_BYTE *)(v103 + 95060) & 1) == 0 )
      {
        v131 = printk(
                 &unk_9BB309,
                 "dp_pdev->first_nbuf",
                 "dp_rx_chain_msdus_be",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c");
        dump_stack(v131);
      }
      *(_BYTE *)(v103 + 95060) = 0;
      v110 = 1;
    }
    else
    {
LABEL_149:
      v110 = 0;
    }
    if ( *(_QWORD *)(v103 + 368) )
    {
      v127 = printk(
               &unk_9BB309,
               "!(dp_pdev->invalid_peer_head_msdu)",
               "dp_rx_chain_msdus_be",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c");
      dump_stack(v127);
      if ( !*(_QWORD *)(v103 + 376) )
      {
LABEL_152:
        if ( *(_QWORD *)(v103 + 368) )
        {
LABEL_153:
          **(_QWORD **)(v103 + 376) = a2;
          v119 = *(_QWORD *)(v103 + 368);
          v121 = *(_QWORD *)(v119 + 72);
          v120 = (unsigned __int64 *)(v119 + 72);
          v122 = v121 & 0xFFFFFFFF00FFFFFFLL;
          v123 = ((_DWORD)v121 + 0x1000000) & 0xFF000000;
          goto LABEL_166;
        }
LABEL_165:
        *(_QWORD *)(v103 + 368) = a2;
        v122 = 0x1000000;
        v120 = (unsigned __int64 *)(a2 + 72);
        v123 = *(_QWORD *)(a2 + 72) & 0xFFFFFFFF00FFFFFFLL;
LABEL_166:
        *v120 = v123 | v122;
        *(_QWORD *)(v103 + 376) = a2;
        *(_QWORD *)a2 = 0;
        dp_rx_process_invalid_peer_wrapper(a1, *(_QWORD *)(v54 + 368), v110, a4);
        if ( v110 )
          goto LABEL_167;
LABEL_21:
        result = 16;
LABEL_22:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
    else if ( !*(_QWORD *)(v103 + 376) )
    {
      goto LABEL_152;
    }
    v128 = printk(
             &unk_9BB309,
             "!(dp_pdev->invalid_peer_tail_msdu)",
             "dp_rx_chain_msdus_be",
             "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c");
    dump_stack(v128);
    if ( *(_QWORD *)(v103 + 368) )
      goto LABEL_153;
    goto LABEL_165;
  }
  if ( (unsigned __int8)a4 < 3u )
  {
    v108 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 288LL);
    if ( *((_DWORD *)v108 - 1) != -70876208 )
      __break(0x8229u);
    v108(a3, v107 + 18528LL * (unsigned __int8)a4 + 3344);
    goto LABEL_126;
  }
  __break(0x5512u);
  return dp_peer_get_ref_by_id(v105, v93, v94);
}
