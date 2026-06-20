__int64 *__fastcall dp_tx_send(__int64 a1, unsigned __int8 a2, __int64 *a3)
{
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x0
  char is_opt_wifi_dp_enabled; // w0
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w8
  __int64 v20; // x9
  __int64 v21; // x9
  int v22; // w8
  char v23; // w10
  int v24; // w9
  int v25; // w8
  __int64 is_tid_override; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char v35; // w8
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  int v39; // w9
  int v40; // w3
  unsigned __int64 v41; // x8
  __int64 v42; // x23
  __int64 v43; // x24
  unsigned __int64 StatusReg; // x8
  unsigned int v45; // w0
  __int64 v46; // x8
  unsigned int v47; // w22
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  __int64 v65; // x8
  int v66; // w9
  __int64 v67; // x0
  unsigned __int16 v68; // w22
  __int64 v69; // x21
  unsigned int v70; // w23
  __int64 v71; // x9
  __int64 v72; // x8
  int v73; // w8
  __int64 v74; // x0
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
  __int64 *v91; // x22
  int v92; // w24
  __int64 *v93; // x8
  __int64 *v94; // x20
  int v96; // w8
  __int64 *v97; // [xsp+0h] [xbp-F0h] BYREF
  __int64 v98; // [xsp+8h] [xbp-E8h]
  __int64 v99; // [xsp+10h] [xbp-E0h]
  __int64 v100; // [xsp+18h] [xbp-D8h]
  __int64 v101; // [xsp+20h] [xbp-D0h]
  __int64 v102; // [xsp+28h] [xbp-C8h]
  __int64 v103; // [xsp+30h] [xbp-C0h]
  __int64 v104; // [xsp+38h] [xbp-B8h]
  __int64 v105; // [xsp+40h] [xbp-B0h]
  __int64 v106; // [xsp+48h] [xbp-A8h]
  __int64 v107; // [xsp+50h] [xbp-A0h]
  __int64 v108; // [xsp+58h] [xbp-98h]
  __int64 v109; // [xsp+60h] [xbp-90h]
  __int64 v110; // [xsp+68h] [xbp-88h]
  __int64 v111; // [xsp+70h] [xbp-80h]
  __int64 v112; // [xsp+78h] [xbp-78h] BYREF
  __int64 v113; // [xsp+80h] [xbp-70h]
  __int64 v114; // [xsp+88h] [xbp-68h]
  __int64 v115; // [xsp+90h] [xbp-60h]
  __int64 v116; // [xsp+98h] [xbp-58h]
  __int64 v117; // [xsp+A0h] [xbp-50h]
  __int64 v118; // [xsp+A8h] [xbp-48h]
  __int64 v119; // [xsp+B0h] [xbp-40h]
  __int64 v120; // [xsp+B8h] [xbp-38h]
  __int64 v121; // [xsp+C0h] [xbp-30h]
  __int64 v122; // [xsp+C8h] [xbp-28h]
  __int64 v123; // [xsp+D0h] [xbp-20h]
  __int64 v124; // [xsp+D8h] [xbp-18h]
  __int64 v125; // [xsp+E0h] [xbp-10h]
  __int64 v126; // [xsp+E8h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  v114 = 0;
  v115 = 0;
  v112 = 0;
  v113 = 0;
  if ( a2 > 5u )
    goto LABEL_119;
  v5 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
  if ( !v5 )
    goto LABEL_119;
  v6 = v5 + 45056;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL);
  BYTE4(v112) = *(_BYTE *)(v5 + 59);
  v8 = *(_QWORD *)(v7 + 40);
  if ( *(_BYTE *)(v8 + 540) == 1 )
  {
    is_opt_wifi_dp_enabled = ipa_config_is_opt_wifi_dp_enabled();
    v10 = *(_QWORD *)(v5 + 24);
    if ( (is_opt_wifi_dp_enabled & 1) == 0 )
    {
      LOBYTE(v10) = *(_BYTE *)v10;
      goto LABEL_12;
    }
    v8 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 40LL);
  }
  if ( (wlan_cfg_is_lapb_enabled(v8) & 1) != 0 )
  {
    v10 = *(_QWORD *)(v5 + 24);
    if ( (a3[21] & 0xF000000) == 0xB000000 )
      LOBYTE(v10) = *(_BYTE *)(*(_QWORD *)(v10 + 8) + 7201LL) - 1;
    else
      LODWORD(v10) = *((unsigned __int16 *)a3 + 62) % (*(unsigned __int8 *)(*(_QWORD *)(v10 + 8) + 7201LL) - 1);
  }
  else
  {
    LOWORD(v10) = (unsigned int)*((_WORD *)a3 + 62)
                % *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL) + 7201LL);
  }
LABEL_12:
  BYTE5(v112) = v10;
  dp_tx_update_proto_stats();
  if ( *(_DWORD *)(v5 + 46176) )
  {
    v19 = *((_BYTE *)a3 + 61);
    if ( (v19 & 0x10) != 0 )
      v20 = a3[10];
    else
      v20 = 0;
    a3[10] = 0;
    *((_BYTE *)a3 + 61) = v19 & 0xEF;
    v124 = v20;
  }
  if ( *(_BYTE *)(v5 + 46168) == 1 )
    *(_WORD *)((char *)a3 + 69) |= 0x800u;
  v21 = *(_QWORD *)(v5 + 408);
  v22 = 0;
  BYTE6(v123) = 0;
  *(_QWORD *)(v5 + 408) = v21 + 1;
  v23 = *((_BYTE *)a3 + 68);
  BYTE4(v113) = 31;
  if ( (v23 & 4) != 0 )
    v22 = *((unsigned __int16 *)a3 + 33);
  v24 = *(_DWORD *)(v5 + 64);
  *(_QWORD *)(v5 + 416) += (unsigned int)(*((_DWORD *)a3 + 28) + v22);
  if ( v24 && !a3 )
  {
    if ( is_dp_verbose_debug_enabled == 1 )
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: Extracting mesh metadata failed",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "dp_tx_send");
    a3 = nullptr;
    goto LABEL_119;
  }
  if ( BYTE4(v112) > 4uLL )
    goto LABEL_130;
  ++*(_DWORD *)(v5 + 4LL * BYTE4(v112) + 432);
  v25 = *((_DWORD *)a3 + 36);
  LOBYTE(v97) = 0;
  BYTE4(v113) = v25;
  is_tid_override = wlan_dp_fpm_is_tid_override();
  if ( (is_tid_override & 1) != 0 )
  {
    BYTE4(v113) = (_BYTE)v97;
    v35 = *(_BYTE *)(v5 + 74);
    if ( v35 )
      goto LABEL_25;
LABEL_71:
    is_tid_override = ((__int64 (__fastcall *)(__int64, __int64 *, __int64 *))dp_tx_get_tid)(v5, a3, &v112);
    goto LABEL_26;
  }
  v35 = *(_BYTE *)(v5 + 74);
  if ( !v35 )
    goto LABEL_71;
LABEL_25:
  if ( (v35 & 2) != 0 && *((_DWORD *)a3 + 36) != 15 )
    BYTE4(v113) = *((_DWORD *)a3 + 36);
LABEL_26:
  v36 = a3[27] + *((unsigned int *)a3 + 53);
  if ( !*(_WORD *)(v36 + 4) || (*(_BYTE *)(v36 + 24) & 0x11) == 0 )
  {
    if ( *((_DWORD *)a3 + 29) )
    {
      if ( *(unsigned __int8 *)(v36 + 2) > 5u )
        goto LABEL_77;
      is_tid_override = wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(a1 + 40));
      if ( (is_tid_override & 1) == 0 )
      {
        v110 = 0;
        v111 = 0;
        v108 = 0;
        v109 = 0;
        v106 = 0;
        v107 = 0;
        v104 = 0;
        v105 = 0;
        v102 = 0;
        v103 = 0;
        v100 = 0;
        v101 = 0;
        v98 = 0;
        v99 = 0;
        v97 = nullptr;
        a3 = (__int64 *)((__int64 (__fastcall *)(__int64, __int64 *, __int64 **, __int64 *))dp_tx_prepare_sg)(
                          v5,
                          a3,
                          &v97,
                          &v112);
        if ( !a3 )
          goto LABEL_119;
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(0x45u, 8u, "%s: non-TSO SG frame %pK", v56, v57, v58, v59, v60, v61, v62, v63, "dp_tx_send", v5);
        ++*(_QWORD *)(v5 + 568);
        if ( (*((_BYTE *)a3 + 68) & 4) != 0 )
          v73 = *((unsigned __int16 *)a3 + 33);
        else
          v73 = 0;
        *(_QWORD *)(v5 + 576) += (unsigned int)(*((_DWORD *)a3 + 28) + v73);
        goto LABEL_61;
      }
      if ( *((_DWORD *)a3 + 29) )
      {
LABEL_77:
        is_tid_override = _pskb_pull_tail(a3);
        if ( !is_tid_override )
          goto LABEL_119;
      }
    }
    if ( *(_DWORD *)(v5 + 40) )
    {
      if ( *(_BYTE *)(v5 + 56) == 1 )
      {
        if ( (*(_BYTE *)a3[28] & 1) != 0 )
        {
          if ( (*(_BYTE *)(a1 + 17706) & 1) != 0 )
          {
            v68 = -2;
          }
          else
          {
            qdf_spin_lock_bh_9(a1 + 17632);
            v74 = dp_peer_ast_hash_find_by_pdevid();
            if ( v74 )
              v68 = *(_WORD *)(v74 + 2);
            else
              v68 = -2;
            is_tid_override = qdf_spin_unlock_bh_10(a1 + 17632);
          }
          dp_tx_nawds_handler(is_tid_override, v5, (__int64)&v112, (__int64)a3, v68);
          v6 = v5 + 45056;
        }
        ++*(_QWORD *)(v5 + 504);
        if ( (*((_BYTE *)a3 + 68) & 4) != 0 )
          v96 = *((unsigned __int16 *)a3 + 33);
        else
          v96 = 0;
        v40 = 65534;
        *(_QWORD *)(v5 + 512) += (unsigned int)(*((_DWORD *)a3 + 28) + v96);
      }
      else
      {
        v40 = 0xFFFF;
      }
      if ( *(_BYTE *)(v6 + 1086) != 1 || (*((_BYTE *)a3 + 71) & 0x78) != 0x40 )
        goto LABEL_39;
      v69 = *(_QWORD *)(v6 + 1088);
      v70 = v40;
      if ( v69 )
      {
        v71 = *(_QWORD *)(v6 + 1096);
        --*(_DWORD *)(v6 + 1104);
        if ( v69 == v71 )
        {
          v72 = 0;
          *(_QWORD *)(v6 + 1096) = 0;
        }
        else
        {
          v72 = *(_QWORD *)v69;
        }
        *(_QWORD *)(v6 + 1088) = v72;
        *(_QWORD *)v69 = 0;
        qdf_nbuf_reset(v69);
      }
      else
      {
        v69 = _qdf_nbuf_alloc(0, 104, 40, 8, 0, "dp_tx_get_traffic_end_indication_pkt", 1231);
        if ( !v69 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Packet allocation failed",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "dp_tx_get_traffic_end_indication_pkt");
          v40 = v70;
LABEL_39:
          a3 = dp_tx_send_msdu_single(v5, (__int64)a3, (__int64)&v112, v40, 0, v27, v28, v29, v30, v31, v32, v33, v34);
          goto LABEL_119;
        }
      }
      qdf_mem_copy(*(void **)(v69 + 224), (const void *)a3[28], 0x40u);
      qdf_nbuf_set_pktlen_0(v69, 64);
      a3 = dp_tx_send_msdu_single(v5, (__int64)a3, (__int64)&v112, v70, 0, v83, v84, v85, v86, v87, v88, v89, v90);
      dp_tx_send_traffic_end_indication_pkt(v5, v69, &v112, v70);
      goto LABEL_119;
    }
    v110 = 0;
    v111 = 0;
    v108 = 0;
    v109 = 0;
    v106 = 0;
    v107 = 0;
    v104 = 0;
    v105 = 0;
    v102 = 0;
    v103 = 0;
    v100 = 0;
    v101 = 0;
    v98 = 0;
    v99 = 0;
    v97 = nullptr;
    a3 = (__int64 *)dp_tx_prepare_raw(v5, a3, &v97, &v112);
    if ( !a3 )
      goto LABEL_119;
    if ( is_dp_verbose_debug_enabled == 1 )
      qdf_trace_msg(0x45u, 8u, "%s: Raw frame %pK", v56, v57, v58, v59, v60, v61, v62, v63, "dp_tx_send", v5);
LABEL_61:
    v67 = dp_tx_send_msdu_multiple(v5, (__int64)a3, (int *)&v112, v56, v57, v58, v59, v60, v61, v62, v63);
    a3 = (__int64 *)v67;
    if ( v67 && (_DWORD)v112 == 5 )
      dp_tx_raw_prepare_unset(*(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL), v67);
    goto LABEL_119;
  }
  if ( is_dp_verbose_debug_enabled == 1 )
  {
    qdf_trace_msg(0x45u, 8u, "%s: TSO frame %pK", v27, v28, v29, v30, v31, v32, v33, v34, "dp_tx_send", v5);
    v37 = *(_QWORD *)(v5 + 24);
    if ( !v37 )
      goto LABEL_42;
  }
  else
  {
    v37 = *(_QWORD *)(v5 + 24);
    if ( !v37 )
      goto LABEL_42;
  }
  ++*(_QWORD *)(v37 + 92216);
  v38 = *(_QWORD *)(v5 + 24);
  if ( v38 )
  {
    if ( (*((_BYTE *)a3 + 68) & 4) != 0 )
      v39 = *((unsigned __int16 *)a3 + 33);
    else
      v39 = 0;
    *(_QWORD *)(v38 + 92224) += (unsigned int)(*((_DWORD *)a3 + 28) + v39);
  }
LABEL_42:
  if ( (wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0 )
  {
LABEL_55:
    if ( (unsigned int)dp_tx_prepare_tso(v5, (__int64)a3, (__int64)&v112) )
    {
      v64 = *(_QWORD *)(v5 + 24);
      if ( v64 )
      {
        ++*(_QWORD *)(v64 + 92240);
        v65 = *(_QWORD *)(v5 + 24);
        if ( v65 )
        {
          if ( (*((_BYTE *)a3 + 68) & 4) != 0 )
            v66 = *((unsigned __int16 *)a3 + 33);
          else
            v66 = 0;
          *(_QWORD *)(v65 + 92248) += (unsigned int)(*((_DWORD *)a3 + 28) + v66);
        }
      }
      goto LABEL_119;
    }
    *(_QWORD *)(v5 + 408) += (unsigned int)(v113 - 1);
    goto LABEL_61;
  }
  v41 = *(unsigned __int8 *)(v5 + 59);
  if ( v41 >= 6 )
LABEL_130:
    __break(0x5512u);
  v42 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL);
  v43 = *(_QWORD *)(v42 + 8 * v41 + 22456);
  v97 = nullptr;
  if ( !v43 || *(_BYTE *)(v43 + 56) != 1 )
  {
    v47 = _qdf_nbuf_sw_tso_prepare_nbuf_list(*(_QWORD *)(v42 + 24), (__int64)a3, (__int64 *)&v97, 0);
    if ( !v47 )
      goto LABEL_103;
LABEL_54:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: sw tso: failed to prepare sw tso nbuf list status %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "dp_tx_sw_tso_handler",
      v47,
      v97);
    if ( v47 != 2 )
    {
LABEL_117:
      if ( a1 )
        ++*(_DWORD *)(a1 + 13636);
      goto LABEL_119;
    }
    goto LABEL_55;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v43 + 40);
  }
  else
  {
    raw_spin_lock_bh(v43 + 40);
    *(_QWORD *)(v43 + 48) |= 1uLL;
  }
  v45 = _qdf_nbuf_sw_tso_prepare_nbuf_list(*(_QWORD *)(v42 + 24), (__int64)a3, (__int64 *)&v97, *(_QWORD *)v43);
  v46 = *(_QWORD *)(v43 + 48);
  v47 = v45;
  if ( (v46 & 1) == 0 )
  {
    raw_spin_unlock(v43 + 40);
    if ( !v47 )
      goto LABEL_103;
    goto LABEL_54;
  }
  *(_QWORD *)(v43 + 48) = v46 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v43 + 40);
  if ( v47 )
    goto LABEL_54;
LABEL_103:
  v91 = v97;
  if ( v97 )
  {
    v92 = 0;
    while ( 1 )
    {
      v93 = v91;
      v91 = (__int64 *)*v91;
      *v93 = 0;
      v97 = dp_tx_send_msdu_single(v5, (__int64)v97, (__int64)&v112, 0xFFFF, 0, v48, v49, v50, v51, v52, v53, v54, v55);
      if ( v97 )
        break;
      ++v92;
      v97 = v91;
      if ( !v91 )
        goto LABEL_109;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: sw tso: failed to send msdu",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "dp_tx_sw_tso_handler");
    if ( v97 )
      _qdf_nbuf_free((__int64)v97);
    if ( v91 )
    {
      do
      {
        v94 = (__int64 *)*v91;
        _qdf_nbuf_free((__int64)v91);
        v91 = v94;
      }
      while ( v94 );
    }
    goto LABEL_117;
  }
  v92 = 0;
LABEL_109:
  if ( v42 )
    *(_DWORD *)(v42 + 13632) += v92;
  if ( a3 )
  {
    _qdf_nbuf_free((__int64)a3);
    a3 = nullptr;
  }
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return a3;
}
