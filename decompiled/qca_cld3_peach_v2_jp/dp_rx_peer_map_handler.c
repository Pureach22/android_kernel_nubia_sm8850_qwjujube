__int64 __fastcall dp_rx_peer_map_handler(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned __int16 *a5,
        unsigned __int16 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v21; // w27
  unsigned int v22; // w24
  __int64 v23; // x7
  int v24; // w8
  int v25; // w9
  int v26; // w10
  unsigned int v27; // w26
  unsigned __int64 v28; // x8
  __int64 v29; // x20
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  int v57; // w9
  int v58; // w10
  int v59; // w11
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int64 v68; // x8
  __int64 v69; // x8
  int v70; // w27
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x5
  __int64 v88; // x6
  __int64 v89; // x7
  int v90; // w8
  unsigned int v91; // w8
  unsigned int v98; // w10
  __int64 v100; // x0
  __int64 v101; // x8
  __int64 v102; // x8
  unsigned __int16 v103; // w27
  _DWORD *v104; // x8
  _DWORD *v105; // x8
  unsigned __int64 StatusReg; // x8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w26
  __int64 v116; // x8
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // x26
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x8
  __int64 v143; // x4
  __int64 v144; // x5
  __int64 v145; // x6
  __int64 v146; // x7
  __int64 v147; // x10
  __int64 v148; // x11
  __int64 v149; // x10
  __int64 v150; // x11
  __int64 v151; // x10
  __int64 v152; // x8
  __int64 v153; // x8
  _DWORD *v154; // x8
  __int64 v155; // x2
  __int64 v156; // x3
  unsigned int v159; // w9
  __int64 v160; // [xsp+0h] [xbp-30h]
  __int64 v161; // [xsp+0h] [xbp-30h]
  __int64 v162; // [xsp+8h] [xbp-28h]
  __int64 v163; // [xsp+8h] [xbp-28h]
  __int64 v164; // [xsp+10h] [xbp-20h]
  __int64 v165; // [xsp+18h] [xbp-18h]

  v21 = (unsigned __int16)a2;
  v22 = a3;
  if ( a5 )
  {
    v23 = *(unsigned __int8 *)a5;
    v24 = *((unsigned __int8 *)a5 + 1);
    v25 = *((unsigned __int8 *)a5 + 2);
    v26 = *((unsigned __int8 *)a5 + 5);
  }
  else
  {
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  v27 = a4;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer_map_event (soc:%pK): peer_id %d, hw_peer_id %d, peer_mac %02x:%02x:%02x:**:**:%02x, vdev_id %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "dp_rx_peer_map_handler",
    a1,
    (unsigned __int16)a2,
    a3,
    v23,
    v24,
    v25,
    v26,
    a4);
  if ( a1 )
    ++*(_DWORD *)(a1 + 17504);
  if ( !a7 )
  {
    if ( (*(_BYTE *)(a1 + 17650) & 1) == 0 && (int)wlan_cfg_get_max_ast_idx(*(_QWORD *)(a1 + 40)) <= (int)v22 )
    {
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: invalid hw_peer_id: %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "dp_rx_peer_map_handler",
        a1,
        v22);
      v100 = printk(
               &unk_9BB309,
               "0",
               "dp_rx_peer_map_handler",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_peer.c");
      dump_stack(v100);
    }
    v47 = dp_peer_find_hash_find(a1, a5, 0, a4, 0xCu);
    if ( a5 )
    {
      v56 = *(unsigned __int8 *)a5;
      v57 = *((unsigned __int8 *)a5 + 1);
      v58 = *((unsigned __int8 *)a5 + 2);
      v59 = *((unsigned __int8 *)a5 + 5);
    }
    else
    {
      v58 = 0;
      v56 = 0;
      v57 = 0;
      v59 = 0;
    }
    LODWORD(v165) = v59;
    LODWORD(v164) = v58;
    LODWORD(v162) = v57;
    LODWORD(v160) = v56;
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: peer %pK ID %d vid %d mac %02x:%02x:%02x:**:**:%02x",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "dp_peer_find_add_id",
      a1,
      v47,
      v21,
      v27,
      v160,
      v162,
      v164,
      v165);
    if ( !v47 )
      return 0;
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: %pK: ref_cnt: %d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_peer_find_add_id",
      a1,
      *(unsigned int *)(v47 + 40));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v68 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v68 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v68 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v47 + 384);
      v69 = *(_QWORD *)(v47 + 392);
      v70 = *(unsigned __int8 *)(v47 + 380);
      if ( (v69 & 1) == 0 )
        goto LABEL_30;
    }
    else
    {
      raw_spin_lock_bh(v47 + 384);
      v69 = *(_QWORD *)(v47 + 392) | 1LL;
      *(_QWORD *)(v47 + 392) = v69;
      v70 = *(unsigned __int8 *)(v47 + 380);
      if ( (v69 & 1) == 0 )
      {
LABEL_30:
        raw_spin_unlock(v47 + 384);
        if ( v70 == 3 )
        {
LABEL_31:
          dp_peer_unref_delete(v47, 0xCu, v71, v72, v73, v74, v75, v76, v77, v78);
          if ( a5 )
          {
            v87 = *(unsigned __int8 *)a5;
            v88 = *((unsigned __int8 *)a5 + 1);
            v89 = *((unsigned __int8 *)a5 + 2);
            v90 = *((unsigned __int8 *)a5 + 5);
          }
          else
          {
            v89 = 0;
            v87 = 0;
            v88 = 0;
            v90 = 0;
          }
          LODWORD(v163) = v27;
          LODWORD(v161) = v90;
          qdf_trace_msg(
            0x45u,
            1u,
            "%s: Peer %pK[%02x:%02x:%02x:**:**:%02x] logical delete state vid %d",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "dp_peer_find_add_id",
            v47,
            v87,
            v88,
            v89,
            v161,
            v163);
          return 0;
        }
LABEL_50:
        if ( *(__int16 *)(v47 + 16) == -1 )
        {
          v101 = *(_QWORD *)(a1 + 20056);
          if ( v101 )
          {
            v102 = *(_QWORD *)(v101 + 416);
            v103 = a6;
            if ( v102 && (v104 = *(_DWORD **)(v102 + 304)) != nullptr )
            {
              if ( *(v104 - 1) != -42562643 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD))v104)(v47, a2);
            }
            else
            {
              qdf_trace_msg(
                0x92u,
                8u,
                "%s: callback not registered",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "dp_monitor_peer_tid_peer_id_update");
            }
          }
          else
          {
            qdf_trace_msg(
              0x92u,
              8u,
              "%s: monitor soc is NULL",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "dp_monitor_peer_tid_peer_id_update");
            v103 = a6;
          }
          dp_peer_find_id_to_obj_add(a1, v47, a2);
          v105 = *(_DWORD **)(a1 + 1608);
          if ( v105 )
          {
            if ( *(v105 - 1) != -1301406113 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD))v105)(a1, v47, a2);
          }
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v47 + 384);
          }
          else
          {
            raw_spin_lock_bh(v47 + 384);
            *(_QWORD *)(v47 + 392) |= 1uLL;
          }
          v115 = *(unsigned __int8 *)(v47 + 380);
          if ( v115 != 1 )
          {
            LODWORD(v163) = *(unsigned __int8 *)(v47 + 49);
            LODWORD(v161) = *(unsigned __int8 *)(v47 + 46);
            qdf_trace_msg(
              0x45u,
              1u,
              "%s: Invalid state shift from %u to %u peer %02x:%02x:%02x:**:**:%02x",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              "dp_peer_update_state",
              *(unsigned __int8 *)(v47 + 380),
              2,
              *(unsigned __int8 *)(v47 + 44),
              *(unsigned __int8 *)(v47 + 45),
              v161,
              v163);
          }
          v116 = *(_QWORD *)(v47 + 392);
          *(_BYTE *)(v47 + 380) = 2;
          if ( (v116 & 1) != 0 )
          {
            *(_QWORD *)(v47 + 392) = v116 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v47 + 384);
          }
          else
          {
            raw_spin_unlock(v47 + 384);
          }
          LODWORD(v163) = *(unsigned __int8 *)(v47 + 49);
          LODWORD(v161) = *(unsigned __int8 *)(v47 + 46);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Updating peer state from %u to %u mac %02x:%02x:%02x:**:**:%02x\n",
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            "dp_peer_update_state",
            v115,
            2,
            *(unsigned __int8 *)(v47 + 44),
            *(unsigned __int8 *)(v47 + 45),
            v161,
            v163);
          v133 = *(_QWORD *)(v47 + 24);
          *(_WORD *)(v47 + 402) = v103;
          *(_WORD *)(v47 + 400) = a3;
          if ( *(_DWORD *)(v133 + 32) == 3 && (*(_BYTE *)(v47 + 120) & 0x20) == 0 )
          {
            if ( (unsigned int)qdf_mem_cmp((const void *)(v47 + 44), (const void *)(v133 + 96), 6u) )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: %pK: STA vdev bss_peer",
                v134,
                v135,
                v136,
                v137,
                v138,
                v139,
                v140,
                v141,
                "dp_rx_peer_map_handler",
                a1);
              v142 = *(_QWORD *)v47;
              *(_BYTE *)(v47 + 120) |= 1u;
              if ( v142 )
                *(_BYTE *)(v142 + 88) |= 2u;
            }
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: bss ast_hash 0x%x, ast_index 0x%x",
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              v140,
              v141,
              "dp_rx_peer_map_handler",
              v103,
              v22);
            *(_WORD *)(v133 + 76) = v103;
            *(_WORD *)(v133 + 78) = a3;
            dp_tx_cfg_astidx_cache_mapping_wrapper(a1);
          }
          if ( (*(_BYTE *)(a1 + 17650) & 1) == 0 && !*(_QWORD *)(v47 + 32) )
          {
            if ( a5 )
            {
              v143 = *(unsigned __int8 *)a5;
              v144 = *((unsigned __int8 *)a5 + 1);
              v145 = *((unsigned __int8 *)a5 + 2);
              v146 = *((unsigned __int8 *)a5 + 5);
            }
            else
            {
              v145 = 0;
              v143 = 0;
              v144 = 0;
              v146 = 0;
            }
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Add self ast from map %02x:%02x:%02x:**:**:%02x",
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              "dp_rx_peer_map_handler",
              v143,
              v144,
              v145,
              v146);
          }
          if ( *(_BYTE *)(*(_QWORD *)(a1 + 1128) + 74576LL) )
          {
            if ( *(_QWORD *)(*(_QWORD *)(v47 + 88) + 32LL) )
            {
              v147 = *(unsigned int *)(*(_QWORD *)(a1 + 40) + 132LL);
              if ( (_DWORD)v147 )
              {
                *(_QWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192)) = 1000 * (jiffies / 0xFAuLL)
                                                                                      + 4 * (jiffies % 0xFAuLL);
                *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 8) = *(unsigned __int16 *)(v47 + 16);
                *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 12) = *(_QWORD *)(*(_QWORD *)(v47 + 88) + 56LL);
                *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 16) = 0;
                v148 = *(_QWORD *)(a1 + 20192);
                v149 = v148 + 1 == v147 ? 0LL : v148 + 1;
                v150 = *(_QWORD *)(a1 + 40);
                *(_QWORD *)(a1 + 20192) = v149;
                v151 = *(unsigned int *)(v150 + 132);
                if ( (_DWORD)v151 )
                {
                  *(_QWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192)) = 1000 * (jiffies / 0xFAuLL)
                                                                                        + 4 * (jiffies % 0xFAuLL);
                  *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 8) = *(unsigned __int16 *)(v47 + 16);
                  *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 12) = *(_QWORD *)(*(_QWORD *)(v47 + 88) + 2360LL);
                  *(_DWORD *)(*(_QWORD *)(a1 + 20144) + 24LL * *(_QWORD *)(a1 + 20192) + 16) = 16;
                  v152 = *(_QWORD *)(a1 + 20192);
                  if ( v152 + 1 == v151 )
                    v153 = 0;
                  else
                    v153 = v152 + 1;
                  *(_QWORD *)(a1 + 20192) = v153;
                }
              }
            }
          }
          v154 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 360LL);
          if ( v154 )
          {
            v155 = *(unsigned __int16 *)(v47 + 16);
            v156 = *(unsigned __int8 *)(*(_QWORD *)(v47 + 24) + 59LL);
            if ( *(v154 - 1) != -1684742716 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v154)(a1, 0, v155, v156, v47 + 44);
          }
        }
        else
        {
          dp_peer_unref_delete(v47, 0xCu, v71, v72, v73, v74, v75, v76, v77, v78);
        }
        return 0;
      }
    }
    *(_QWORD *)(v47 + 392) = v69 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v47 + 384);
    if ( v70 == 3 )
      goto LABEL_31;
    goto LABEL_50;
  }
  if ( (*(_BYTE *)(a1 + 17650) & 1) != 0 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v28 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v28 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v28 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13276) <= v21 )
    goto LABEL_15;
  v29 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * (unsigned __int16)a2);
  if ( v29 )
  {
    if ( *(unsigned __int8 *)(v29 + 380) <= 2u )
    {
      v91 = *(_DWORD *)(v29 + 40);
      while ( v91 )
      {
        _X12 = (unsigned int *)(v29 + 40);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v98 = __ldxr(_X12);
          if ( v98 != v91 )
            break;
          if ( !__stlxr(v91 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v98 == v91;
        v91 = v98;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v29 + 308);
          __asm { PRFM            #0x11, [X8] }
          do
            v159 = __ldxr(_X8);
          while ( __stxr(v159 + 1, _X8) );
          goto LABEL_16;
        }
      }
    }
LABEL_15:
    v29 = 0;
  }
LABEL_16:
  v30 = *(_QWORD *)(a1 + 13264);
  if ( (v30 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v30 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
    if ( !v29 )
      return 0;
    goto LABEL_18;
  }
  raw_spin_unlock(a1 + 13256);
  if ( v29 )
LABEL_18:
    dp_peer_unref_delete(v29, 0xDu, v31, v32, v33, v34, v35, v36, v37, v38);
  return 0;
}
