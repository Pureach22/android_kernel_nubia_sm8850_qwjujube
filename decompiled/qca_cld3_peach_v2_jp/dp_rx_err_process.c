__int64 __fastcall dp_rx_err_process(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x22
  unsigned int v8; // w25
  unsigned int v9; // w19
  __int64 v10; // x9
  __int64 v11; // x10
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  signed int v20; // w27
  unsigned int v21; // w23
  __int64 v22; // x8
  __int64 v23; // x28
  __int64 (__fastcall *v24)(_QWORD); // x8
  unsigned int v25; // w19
  __int64 (__fastcall *v26)(_QWORD); // x8
  char v27; // w22
  __int64 (__fastcall *v28)(_QWORD); // x8
  char v29; // w27
  void (__fastcall *v30)(__int64, __int64 *); // x8
  void (__fastcall *v31)(__int64, __int64 *); // x8
  void (__fastcall *v32)(__int64, __int64 *); // x8
  unsigned int v33; // w26
  unsigned int v34; // w8
  _QWORD *v35; // x8
  __int64 v36; // x22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w25
  unsigned int v46; // w24
  int v47; // w8
  __int64 (__fastcall *v48)(__int64, __int64); // x8
  __int64 v49; // x1
  __int64 v50; // x24
  __int64 v51; // x19
  int v52; // w8
  unsigned int v53; // w19
  __int64 v54; // x8
  __int64 v55; // x1
  __int64 (__fastcall *v56)(__int64, __int64); // x8
  unsigned __int16 v57; // w0
  _QWORD *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x19
  _QWORD *v68; // x22
  __int64 v69; // x19
  char v70; // w8
  __int64 v71; // x10
  int v72; // w0
  __int64 v73; // x1
  __int64 (__fastcall *v74)(__int64, __int64); // x8
  unsigned __int16 v75; // w0
  __int64 **ref_by_id_2; // x0
  __int64 v77; // x8
  __int64 v78; // x1
  __int64 (__fastcall *v79)(__int64, __int64); // x8
  unsigned __int16 v80; // w0
  __int64 **v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x8
  __int64 v91; // x0
  unsigned int *v92; // x1
  char v93; // w4
  unsigned int v94; // w19
  __int64 v95; // x8
  int v96; // w0
  int v97; // w9
  char v98; // w12
  int v99; // w11
  __int64 v100; // x9
  unsigned int v101; // w10
  __int64 v103; // x0
  __int64 v104; // x9
  unsigned __int64 v105; // x13
  __int64 v106; // x10
  __int64 v107; // x9
  __int64 v108; // x1
  __int64 v114; // x0
  int v115; // w0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x19
  int v129; // w8
  __int64 v130; // x9
  __int64 v132; // [xsp+18h] [xbp-108h]
  __int64 *v133; // [xsp+20h] [xbp-100h]
  unsigned int v134; // [xsp+28h] [xbp-F8h]
  unsigned int v135; // [xsp+2Ch] [xbp-F4h]
  __int64 v137; // [xsp+38h] [xbp-E8h]
  int v138; // [xsp+40h] [xbp-E0h]
  signed int v139; // [xsp+44h] [xbp-DCh]
  __int64 v140; // [xsp+48h] [xbp-D8h]
  signed int v141; // [xsp+54h] [xbp-CCh]
  __int64 v142; // [xsp+58h] [xbp-C8h]
  char v143[4]; // [xsp+60h] [xbp-C0h] BYREF
  unsigned __int16 v144; // [xsp+64h] [xbp-BCh] BYREF
  __int64 v145; // [xsp+68h] [xbp-B8h] BYREF
  __int64 v146; // [xsp+70h] [xbp-B0h]
  __int64 v147; // [xsp+78h] [xbp-A8h] BYREF
  __int64 v148; // [xsp+80h] [xbp-A0h]
  _BYTE v149[4]; // [xsp+8Ch] [xbp-94h] BYREF
  _QWORD v150[6]; // [xsp+90h] [xbp-90h] BYREF
  __int64 v151; // [xsp+C0h] [xbp-60h]
  __int64 v152; // [xsp+C8h] [xbp-58h]
  __int64 v153; // [xsp+D0h] [xbp-50h]
  __int64 v154; // [xsp+D8h] [xbp-48h]
  __int64 v155; // [xsp+E0h] [xbp-40h]
  __int64 v156; // [xsp+E8h] [xbp-38h]
  __int64 v157; // [xsp+F0h] [xbp-30h]
  __int64 v158; // [xsp+F8h] [xbp-28h]
  __int64 v159; // [xsp+100h] [xbp-20h]
  __int64 v160; // [xsp+108h] [xbp-18h]
  __int64 v161; // [xsp+110h] [xbp-10h]

  v7 = a1;
  v8 = 0;
  v161 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = *(_QWORD *)(a2 + 40);
  v140 = a2 + 0x4000;
  v11 = *(_QWORD *)(a2 + 1128);
  v149[0] = 0;
  v142 = v11;
  LODWORD(v11) = *(_DWORD *)(a3 + 32);
  v137 = a2 + 13908;
  v139 = *(_DWORD *)(v10 + 676);
  v147 = 0;
  v148 = 0;
  v145 = 0;
  v146 = 0;
  v159 = 0;
  v160 = 0;
  v134 = v11;
  v157 = 0;
  v158 = 0;
  v132 = a2 + 12368;
  v133 = (__int64 *)(a2 + 80);
  v155 = 0;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  memset(v150, 0, sizeof(v150));
  v144 = 0;
  v143[0] = 0;
  while ( 2 )
  {
    v135 = v9;
    if ( (unsigned int)dp_srng_access_start(v7, a2, (char *)a3) )
    {
      if ( a2 )
        ++*(_DWORD *)(a2 + 13768);
      qdf_trace_msg(
        0x82u,
        2u,
        "%s: %pK: HAL RING Access Failed -- %pK",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_err_process",
        a2,
        a3);
      v20 = 0;
      goto LABEL_159;
    }
    v20 = 0;
    if ( !a4 )
    {
      a4 = -1;
      goto LABEL_159;
    }
    v21 = a4 - 1;
    while ( 1 )
    {
      v22 = *(unsigned int *)(a3 + 120);
      if ( (_DWORD)v22 == *(_DWORD *)(a3 + 136) )
        break;
      --a4;
      v23 = *(_QWORD *)(a3 + 16) + 4 * v22;
      if ( !v23 )
        goto LABEL_158;
      v141 = v20;
      if ( a2 )
        ++*(_DWORD *)(a2 + 13600);
      v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v142 + 74392) + 1512LL);
      if ( *((_DWORD *)v24 - 1) != 1690911915 )
        __break(0x8228u);
      v25 = v24(v23);
      v26 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v142 + 74392) + 1520LL);
      if ( *((_DWORD *)v26 - 1) != 1690911915 )
        __break(0x8228u);
      v27 = v26(v23);
      if ( !(_BYTE)v25 )
      {
        v28 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v142 + 74392) + 1488LL);
        if ( *((_DWORD *)v28 - 1) != 1914255918 )
          __break(0x8228u);
        v8 = v28(v23);
      }
      qdf_mem_set(&v147, 0x10u, 0);
      if ( !(_BYTE)v25 && (*(_BYTE *)(v140 + 3656) & 1) != 0 && v8 - 5 < 8 && ((0x8Fu >> (v8 - 5)) & 1) != 0 )
      {
        v29 = 1;
        if ( !*(_BYTE *)(v23 + 8) )
          goto LABEL_22;
      }
      else
      {
        v30 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v142 + 74392) + 1504LL);
        if ( *((_DWORD *)v30 - 1) != -72220 )
          __break(0x8228u);
        v30(v23, &v147);
        v29 = 0;
        if ( !*(_BYTE *)(v23 + 8) )
        {
LABEL_22:
          v20 = v141;
          goto LABEL_120;
        }
      }
      if ( v27 == 1 )
      {
        v31 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v142 + 74392) + 1456LL);
        if ( *((_DWORD *)v31 - 1) != -621572614 )
          __break(0x8228u);
        v31(v23, &v145);
        if ( (*(_DWORD *)(v140 + 3628) & ((unsigned int)v146 >> 5)) == 0 )
        {
          v116 = printk(
                   &unk_9BB309,
                   "(hbi.sw_cookie >> 5) & soc->link_desc_id_start",
                   "dp_rx_err_process",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v116);
        }
        v32 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1464LL);
        if ( v32 )
        {
          if ( *((_DWORD *)v32 - 1) != 1721787685 )
            __break(0x8228u);
          v32(v23, &v145);
        }
        v138 = a4;
        v33 = v8;
        v34 = ((unsigned int)v146 >> 5) & 0x3FF;
        if ( v34 >= *(unsigned __int16 *)(a2 + 1866) )
        {
          v36 = 0;
        }
        else
        {
          v35 = (_QWORD *)(*(_QWORD *)(a2 + 1872) + 24LL * v34);
          v36 = *v35 + v145 - v35[2];
        }
        hal_rx_msdu_list_get(*(_QWORD *)(a2 + 1128), v36, (__int64)v150, (__int16 *)&v144);
        v45 = v144;
        if ( !v144 )
        {
          v69 = jiffies;
          if ( dp_rx_err_process___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x82u,
              5u,
              "%s: Invalid MSDU info num_msdus %u cookie: 0x%x",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "dp_rx_err_process",
              0,
              (unsigned int)v151);
            dp_rx_err_process___last_ticks = v69;
          }
          dp_rx_link_desc_return_by_addr(a2, (unsigned int *)v23, 0, v37, v38, v39, v40, v41, v42, v43, v44);
          v8 = v33;
          a4 = v138;
          v20 = v141;
          goto LABEL_120;
        }
        v46 = (unsigned __int8)v154;
        v47 = *(_DWORD *)(v140 + 3620);
        if ( (unsigned __int8)v154 != (unsigned __int8)(v47 + 1)
          && (unsigned __int8)v154 != (unsigned __int8)(v47 + 3)
          && (unsigned __int8)v154 != *(unsigned __int8 *)(v140 + 3688) )
        {
          v8 = v33;
          a4 = v138;
          v20 = v141;
          if ( !(unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a2 + 40)) )
          {
            if ( a2 )
              ++*(_DWORD *)(a2 + 13688);
            qdf_trace_msg(
              0x82u,
              2u,
              "%s: %pK: Invalid RBM %d",
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              "dp_rx_err_process",
              a2,
              v46);
          }
          dp_rx_link_desc_return_by_addr(a2, (unsigned int *)v23, 1u, v120, v121, v122, v123, v124, v125, v126, v127);
          goto LABEL_120;
        }
        v48 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1408);
        v49 = (unsigned int)v151;
        if ( *((_DWORD *)v48 - 1) != 207937137 )
          __break(0x8228u);
        v50 = v48(a2, v49);
        if ( !v50 )
        {
          v117 = printk(
                   &unk_9BB309,
                   "rx_desc",
                   "dp_rx_err_process",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v117);
        }
        v149[0] = *(_BYTE *)(v50 + 28);
        if ( (v29 & 1) == 0 )
        {
          if ( WORD2(v148) )
          {
            if ( (unsigned __int16)v147 != 1 )
            {
              v119 = printk(
                       &unk_9BB309,
                       "mpdu_desc_info.msdu_count == 1",
                       "dp_rx_err_process",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
              dump_stack(v119);
            }
            v8 = v33;
            dp_rx_bar_frame_handle(a2, (unsigned int *)v23, (__int64 *)v50, (__int64)&v147, v25, v33);
            a4 = v138;
            v20 = v141;
            if ( v149[0] )
              goto LABEL_189;
            goto LABEL_75;
          }
          if ( (v147 & 0x10000000000000LL) != 0 )
          {
            if ( v45 == 1 )
            {
              v70 = *(_BYTE *)(v50 + 30);
              v20 = v141;
              if ( (v70 & 1) != 0 )
              {
                v8 = v33;
                v71 = 80;
                if ( (*(_BYTE *)(*(_QWORD *)v50 + 68LL) & 4) == 0 )
                  v71 = 40;
                if ( *(_QWORD *)(*(_QWORD *)v50 + v71) == v155 )
                {
                  v72 = dp_rx_frag_handle(a2, v23, &v147, v50, v149, v21);
                  a4 = v138;
                  if ( v149[0] )
                    goto LABEL_189;
                  if ( a2 )
                    ++*(_DWORD *)(a2 + 13604);
                  v73 = (unsigned int)v148;
                  v74 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
                  v20 = v72 + v141;
                  if ( *((_DWORD *)v74 - 1) != 1020823628 )
                    __break(0x8228u);
                  v75 = v74(a2, v73);
                  ref_by_id_2 = (__int64 **)dp_peer_get_ref_by_id_2(a2, v75);
                  if ( ref_by_id_2 )
                  {
                    if ( *ref_by_id_2 )
                    {
                      v77 = **ref_by_id_2;
                      if ( v77 )
                        ++*(_DWORD *)(v77 + 6572);
                      dp_txrx_peer_unref_delete((__int64)ref_by_id_2, 4u, v12, v13, v14, v15, v16, v17, v18, v19);
                    }
                    else
                    {
                      dp_peer_unref_delete((__int64)ref_by_id_2, 4u, v12, v13, v14, v15, v16, v17, v18, v19);
                    }
                  }
                }
                else
                {
                  a4 = v138;
                  if ( a2 )
                  {
                    ++*(_DWORD *)(a2 + 14108);
                    v70 = *(_BYTE *)(v50 + 30);
                  }
                  *(_BYTE *)(v50 + 30) = v70 | 4;
                }
              }
              else
              {
                if ( a2 )
                  ++*(_DWORD *)(a2 + 14000);
                v8 = v33;
                v128 = jiffies;
                if ( dp_rx_err_process___last_ticks_49 - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x45u,
                    5u,
                    "%s: Reaping rx_desc not in use!",
                    v12,
                    v13,
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    "dp_rx_err_process");
                  dp_rx_err_process___last_ticks_49 = v128;
                }
                dp_rx_dump_info_and_assert(a2, a3, v23, v50);
                a4 = v138;
              }
              goto LABEL_120;
            }
            v96 = dp_rx_msdus_drop(a2, (unsigned int *)v23, (unsigned __int16 *)&v147, v149, 0);
            v8 = v33;
            a4 = v138;
            v20 = v141;
            if ( v149[0] )
              goto LABEL_189;
            goto LABEL_119;
          }
        }
        v8 = v33;
        if ( (_BYTE)v25 )
        {
          v118 = printk(
                   &unk_9BB309,
                   "err_status == HAL_REO_ERROR_DETECTED",
                   "dp_rx_err_process",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v118);
        }
        v51 = jiffies;
        a4 = v138;
        if ( dp_rx_err_process___last_ticks_51 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Got pkt with REO ERROR: %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "dp_rx_err_process",
            v8);
          dp_rx_err_process___last_ticks_51 = v51;
        }
        v20 = v141;
        if ( (int)v8 <= 3 )
        {
          if ( v8 - 1 < 2 )
            goto LABEL_102;
          if ( !v8 )
          {
LABEL_105:
            if ( a2 )
              ++*(_DWORD *)(v137 + 4LL * v8);
            v94 = v149[0];
            if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
              || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), v94) )
            {
              v95 = *(_QWORD *)(a2 + 72);
              if ( v95 )
                ++*(_DWORD *)(v95 + 508);
            }
            v96 = dp_rx_reo_err_entry_process(a2, v23, (unsigned __int16 *)&v147, v36, v8);
            if ( v149[0] )
              goto LABEL_189;
            goto LABEL_119;
          }
          if ( v8 == 3 )
          {
            v78 = (unsigned int)v148;
            v79 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
            if ( *((_DWORD *)v79 - 1) != 1020823628 )
              __break(0x8228u);
            v80 = v79(a2, v78);
            v81 = (__int64 **)dp_peer_get_ref_by_id_2(a2, v80);
            if ( v81 )
            {
              if ( *v81 )
              {
                v90 = **v81;
                if ( v90 )
                  ++*(_DWORD *)(v90 + 6568);
                dp_txrx_peer_unref_delete((__int64)v81, 4u, v82, v83, v84, v85, v86, v87, v88, v89);
                goto LABEL_102;
              }
              dp_peer_unref_delete((__int64)v81, 4u, v82, v83, v84, v85, v86, v87, v88, v89);
              if ( !a2 )
              {
LABEL_104:
                v91 = a2;
                v92 = (unsigned int *)v23;
                v93 = 0;
LABEL_118:
                v96 = dp_rx_msdus_drop(v91, v92, (unsigned __int16 *)&v147, v149, v93);
                if ( v149[0] )
                  goto LABEL_189;
LABEL_119:
                v20 += v96;
                goto LABEL_120;
              }
            }
            else
            {
LABEL_102:
              if ( !a2 )
                goto LABEL_104;
            }
            ++*(_DWORD *)(v137 + 4LL * v8);
            goto LABEL_104;
          }
        }
        else if ( v8 <= 0xE )
        {
          v52 = 1 << v8;
          if ( ((1 << v8) & 0x11E0) != 0 )
            goto LABEL_105;
          if ( (v52 & 0x4610) != 0 )
            goto LABEL_102;
          if ( (v52 & 0x2800) != 0 )
          {
            if ( a2 )
              ++*(_DWORD *)(v137 + 4LL * v8);
            v53 = v149[0];
            if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
              || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), v53) )
            {
              v54 = *(_QWORD *)(a2 + 72);
              if ( v54 )
                ++*(_DWORD *)(v54 + 508);
            }
            v55 = (unsigned int)v148;
            v56 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
            if ( *((_DWORD *)v56 - 1) != 1020823628 )
              __break(0x8228u);
            v57 = v56(a2, v55);
            v58 = (_QWORD *)dp_peer_get_ref_by_id_2(a2, v57);
            if ( v58 )
            {
              if ( *v58 )
              {
                v67 = jiffies;
                if ( dp_rx_pn_error_handle___last_ticks - jiffies + 125 < 0 )
                {
                  v68 = v58;
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: discard rx due to PN error for peer  %pK",
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    "dp_rx_pn_error_handle");
                  v58 = v68;
                  dp_rx_pn_error_handle___last_ticks = v67;
                }
                dp_txrx_peer_unref_delete((__int64)v58, 4u, v59, v60, v61, v62, v63, v64, v65, v66);
              }
              else
              {
                dp_peer_unref_delete((__int64)v58, 4u, v59, v60, v61, v62, v63, v64, v65, v66);
              }
            }
            qdf_trace_msg(
              0x82u,
              2u,
              "%s: %pK: Packet received with PN error",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "dp_rx_pn_error_handle",
              a2);
            v91 = a2;
            v92 = (unsigned int *)v23;
            v93 = 1;
            goto LABEL_118;
          }
        }
        v114 = printk(
                 &unk_9BB309,
                 "0",
                 "dp_rx_err_process",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
        dump_stack(v114);
      }
      else
      {
        v115 = dp_rx_err_exception(a2, v23, v12, v13, v14, v15, v16, v17, v18, v19);
        v20 = v141;
        if ( (v115 & 0x80000000) == 0 )
        {
          if ( v115 )
            goto LABEL_189;
LABEL_75:
          ++v20;
        }
      }
LABEL_120:
      v97 = *(_DWORD *)(a3 + 120);
      if ( v97 != *(_DWORD *)(a3 + 136) )
      {
        v98 = *(_BYTE *)(a3 + 78);
        v99 = *(_DWORD *)(a3 + 44) + v97;
        v100 = *(_QWORD *)(a3 + 16);
        v101 = v99 == *(_DWORD *)(a3 + 36) ? 0 : v99;
        *(_DWORD *)(a3 + 120) = v101;
        if ( (v98 & 4) != 0 )
        {
          _X19 = v100 + 4LL * v101;
          v103 = *(_QWORD *)(*(_QWORD *)(v142 + 8) + 40LL);
          if ( (*(_BYTE *)(v103 + 844) & 0x40) == 0 )
          {
            v104 = _X19 << 8 >> 8;
            v105 = (unsigned __int64)(v104 + 0x8000000000LL) >> 38;
            v106 = memstart_addr + v104 + 0x8000000000LL;
            v107 = v104 - kimage_voffset;
            if ( v105 )
              v108 = v107;
            else
              v108 = v106;
            _dma_sync_single_for_cpu(v103, v108);
          }
          __asm { PRFM            #0, [X19] }
        }
      }
      if ( a2 && v20 >= v139 )
        ++*(_DWORD *)(a2 + 13632);
      if ( v20 >= v139 )
        goto LABEL_158;
      if ( --v21 == -1 )
      {
        a4 = -1;
        goto LABEL_158;
      }
    }
    a4 = v21;
LABEL_158:
    v7 = a1;
LABEL_159:
    dp_srng_access_end(v7, a2, (char *)a3, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( *(_DWORD *)(a2 + 13152) && (unsigned int)jiffies_to_msecs(jiffies) >= *(_DWORD *)(a2 + 13132) )
      dp_rx_defrag_waitlist_flush(a2);
    v149[0] = 0;
    if ( v20 )
    {
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
        && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), 0) )
      {
        v129 = v149[0];
        if ( v149[0] >= 2u )
          goto LABEL_189;
LABEL_172:
        if ( v129 )
          goto LABEL_189;
      }
      else
      {
        v129 = v149[0];
        if ( v149[0] >= 2u )
          goto LABEL_189;
        v130 = *(_QWORD *)(a2 + 72);
        if ( !v130 )
          goto LABEL_172;
        if ( v149[0]
          || (_dp_rx_buffers_replenish(a2, 0, v133, v132, v20, (unsigned int **)(v130 + 95224), v130 + 95232, 0, 0),
              v149[0]) )
        {
LABEL_189:
          __break(0x5512u);
        }
        v135 += v20;
      }
    }
    v9 = v135;
    v7 = a1;
    _ZF = *(_BYTE *)(*(_QWORD *)(a2 + 40) + 684LL) == 1;
    v149[0] = 1;
    if ( _ZF && v135 && a4 && (unsigned int)dp_rx_srng_get_num_pending(v142, a3, v134, v143) )
    {
      if ( a2 )
        ++*(_DWORD *)(a2 + 14160);
      if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))hif_exec_should_yield)(
              *(_QWORD *)(a2 + 64),
              *(unsigned __int8 *)(a1 + 32))
          & 1) != 0 )
      {
        if ( v143[0] == 1 )
        {
          if ( a2 )
            ++*(_DWORD *)(a2 + 14164);
          continue;
        }
        break;
      }
      continue;
    }
    break;
  }
  _ReadStatusReg(SP_EL0);
  return v135;
}
