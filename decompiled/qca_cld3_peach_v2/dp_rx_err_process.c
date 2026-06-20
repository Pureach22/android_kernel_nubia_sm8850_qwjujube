__int64 __fastcall dp_rx_err_process(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v7; // x9
  unsigned int v8; // w27
  __int64 v9; // x8
  unsigned int v10; // w10
  __int64 v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  signed int v20; // w24
  __int64 v21; // x8
  __int64 v22; // x26
  __int64 (__fastcall *v23)(_QWORD); // x8
  unsigned int v24; // w28
  __int64 (__fastcall *v25)(_QWORD); // x8
  char v26; // w19
  __int64 (__fastcall *v27)(_QWORD); // x8
  char v28; // w24
  void (__fastcall *v29)(__int64, __int64 *); // x8
  void (__fastcall *v30)(__int64, __int64 *); // x8
  void (__fastcall *v31)(__int64, __int64 *); // x8
  __int64 v32; // x23
  unsigned int v33; // w25
  unsigned int v34; // w8
  _QWORD *v35; // x8
  __int64 v36; // x19
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w27
  unsigned int v46; // w22
  int v47; // w8
  __int64 (__fastcall *v48)(__int64, __int64); // x8
  __int64 v49; // x1
  __int64 v50; // x22
  __int64 v51; // x22
  int v52; // w8
  unsigned int v53; // w19
  __int64 v54; // x8
  __int64 v55; // x1
  __int64 (__fastcall *v56)(__int64, __int64); // x8
  unsigned __int16 v57; // w19
  __int64 v58; // x19
  __int64 v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  _QWORD *v68; // x8
  __int64 v69; // x22
  __int64 v70; // x19
  char v71; // w8
  __int64 v72; // x10
  int v73; // w0
  int v74; // w19
  __int64 v75; // x1
  __int64 (__fastcall *v76)(__int64, __int64); // x8
  unsigned __int16 v77; // w22
  __int64 v78; // x22
  __int64 v79; // x8
  __int64 **v80; // x8
  __int64 *v81; // x8
  __int64 v82; // x8
  __int64 v83; // x1
  __int64 (__fastcall *v84)(__int64, __int64); // x8
  unsigned __int16 v85; // w19
  __int64 v86; // x19
  __int64 v87; // x8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 **v96; // x8
  __int64 *v97; // x8
  __int64 v98; // x8
  unsigned int v99; // w22
  __int64 v100; // x8
  int v101; // w0
  __int64 v102; // x0
  unsigned int *v103; // x1
  char v104; // w4
  unsigned int v105; // w8
  unsigned int v112; // w10
  int v113; // w9
  char v114; // w12
  int v115; // w11
  __int64 v116; // x9
  unsigned int v117; // w10
  __int64 v119; // x0
  __int64 v120; // x9
  unsigned __int64 v121; // x13
  __int64 v122; // x10
  __int64 v123; // x9
  __int64 v124; // x1
  unsigned int v126; // w8
  unsigned int v129; // w10
  unsigned int v130; // w8
  unsigned int v133; // w10
  __int64 v134; // x0
  int v135; // w0
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  __int64 v148; // x19
  unsigned int v151; // w9
  unsigned int v154; // w9
  unsigned int v157; // w9
  int v158; // w8
  __int64 v159; // x9
  char v160; // w0
  __int64 v162; // [xsp+10h] [xbp-110h]
  __int64 *v163; // [xsp+18h] [xbp-108h]
  unsigned __int64 StatusReg; // [xsp+20h] [xbp-100h]
  unsigned int v165; // [xsp+2Ch] [xbp-F4h]
  unsigned int v167; // [xsp+3Ch] [xbp-E4h]
  __int64 v168; // [xsp+40h] [xbp-E0h]
  unsigned int v169; // [xsp+48h] [xbp-D8h]
  signed int v170; // [xsp+4Ch] [xbp-D4h]
  __int64 v171; // [xsp+50h] [xbp-D0h]
  signed int v172; // [xsp+5Ch] [xbp-C4h]
  char v173[4]; // [xsp+60h] [xbp-C0h] BYREF
  unsigned __int16 v174; // [xsp+64h] [xbp-BCh] BYREF
  __int64 v175; // [xsp+68h] [xbp-B8h] BYREF
  __int64 v176; // [xsp+70h] [xbp-B0h]
  __int64 v177; // [xsp+78h] [xbp-A8h] BYREF
  __int64 v178; // [xsp+80h] [xbp-A0h]
  _BYTE v179[4]; // [xsp+8Ch] [xbp-94h] BYREF
  _QWORD v180[6]; // [xsp+90h] [xbp-90h] BYREF
  __int64 v181; // [xsp+C0h] [xbp-60h]
  __int64 v182; // [xsp+C8h] [xbp-58h]
  __int64 v183; // [xsp+D0h] [xbp-50h]
  __int64 v184; // [xsp+D8h] [xbp-48h]
  __int64 v185; // [xsp+E0h] [xbp-40h]
  __int64 v186; // [xsp+E8h] [xbp-38h]
  __int64 v187; // [xsp+F0h] [xbp-30h]
  __int64 v188; // [xsp+F8h] [xbp-28h]
  __int64 v189; // [xsp+100h] [xbp-20h]
  __int64 v190; // [xsp+108h] [xbp-18h]
  __int64 v191; // [xsp+110h] [xbp-10h]

  v167 = 0;
  v7 = a1;
  v191 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = *(_QWORD *)(a2 + 40);
  v171 = a2 + 0x4000;
  v10 = *(_DWORD *)(a3 + 32);
  v11 = *(_QWORD *)(a2 + 1128);
  v179[0] = 0;
  LODWORD(v9) = *(_DWORD *)(v9 + 676);
  v165 = v10;
  v177 = 0;
  v178 = 0;
  v170 = v9;
  v175 = 0;
  v176 = 0;
  v168 = a2 + 13964;
  v189 = 0;
  v190 = 0;
  v187 = 0;
  v188 = 0;
  v185 = 0;
  v186 = 0;
  v162 = a2 + 12416;
  v163 = (__int64 *)(a2 + 80);
  v183 = 0;
  v184 = 0;
  v181 = 0;
  v182 = 0;
  memset(v180, 0, sizeof(v180));
  StatusReg = _ReadStatusReg(SP_EL0);
  v174 = 0;
  v173[0] = 0;
  while ( 1 )
  {
    if ( (unsigned int)dp_srng_access_start(v7, a2, (char *)a3) )
    {
      if ( a2 )
        ++*(_DWORD *)(a2 + 13824);
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
    }
    else
    {
      v20 = 0;
      if ( a4 )
      {
        while ( 1 )
        {
          v21 = *(unsigned int *)(a3 + 120);
          --a4;
          if ( (_DWORD)v21 == *(_DWORD *)(a3 + 136) )
            goto LABEL_239;
          v22 = *(_QWORD *)(a3 + 16) + 4 * v21;
          if ( !v22 )
            goto LABEL_239;
          v172 = v20;
          if ( a2 )
            ++*(_DWORD *)(a2 + 13656);
          v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v11 + 74392) + 1512LL);
          if ( *((_DWORD *)v23 - 1) != 1690911915 )
            __break(0x8228u);
          v24 = v23(v22);
          v25 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v11 + 74392) + 1520LL);
          if ( *((_DWORD *)v25 - 1) != 1690911915 )
            __break(0x8228u);
          v26 = v25(v22);
          if ( !(_BYTE)v24 )
          {
            v27 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v11 + 74392) + 1488LL);
            if ( *((_DWORD *)v27 - 1) != 1914255918 )
              __break(0x8228u);
            v8 = v27(v22);
          }
          qdf_mem_set(&v177, 0x10u, 0);
          if ( !(_BYTE)v24 && (*(_BYTE *)(v171 + 3712) & 1) != 0 && v8 - 5 < 8 && ((0x8Fu >> (v8 - 5)) & 1) != 0 )
          {
            v28 = 1;
            if ( !*(_BYTE *)(v22 + 8) )
              goto LABEL_21;
          }
          else
          {
            v29 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v11 + 74392) + 1504LL);
            if ( *((_DWORD *)v29 - 1) != -72220 )
              __break(0x8228u);
            v29(v22, &v177);
            v28 = 0;
            if ( !*(_BYTE *)(v22 + 8) )
            {
LABEL_21:
              v20 = v172;
              goto LABEL_169;
            }
          }
          if ( v26 != 1 )
          {
            v135 = dp_rx_err_exception(a2, v22, v12, v13, v14, v15, v16, v17, v18, v19);
            v20 = v172;
            if ( v135 < 0 )
              goto LABEL_169;
            if ( v135 )
              goto LABEL_268;
            goto LABEL_85;
          }
          v30 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v11 + 74392) + 1456LL);
          if ( *((_DWORD *)v30 - 1) != -621572614 )
            __break(0x8228u);
          v30(v22, &v175);
          if ( (*(_DWORD *)(v171 + 3684) & ((unsigned int)v176 >> 5)) == 0 )
          {
            v136 = printk(
                     &unk_AAA255,
                     "(hbi.sw_cookie >> 5) & soc->link_desc_id_start",
                     "dp_rx_err_process",
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
            dump_stack(v136);
          }
          v169 = a4;
          v31 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1464LL);
          if ( v31 )
          {
            if ( *((_DWORD *)v31 - 1) != 1721787685 )
              __break(0x8228u);
            v31(v22, &v175);
          }
          v32 = v11;
          v33 = v8;
          v34 = ((unsigned int)v176 >> 5) & 0x3FF;
          if ( v34 >= *(unsigned __int16 *)(a2 + 1914) )
          {
            v36 = 0;
          }
          else
          {
            v35 = (_QWORD *)(*(_QWORD *)(a2 + 1920) + 24LL * v34);
            v36 = *v35 + v175 - v35[2];
          }
          hal_rx_msdu_list_get(*(_QWORD *)(a2 + 1128), v36, (__int64)v180, (__int16 *)&v174);
          v45 = v174;
          if ( !v174 )
          {
            v70 = jiffies;
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
                (unsigned int)v181);
              dp_rx_err_process___last_ticks = v70;
            }
            dp_rx_link_desc_return_by_addr(a2, (unsigned int *)v22, 0, v37, v38, v39, v40, v41, v42, v43, v44);
            v8 = v33;
            v11 = v32;
            a4 = v169;
            v20 = v172;
            goto LABEL_169;
          }
          v46 = (unsigned __int8)v184;
          v47 = *(_DWORD *)(v171 + 3676);
          if ( (unsigned __int8)v184 != (unsigned __int8)(v47 + 1)
            && (unsigned __int8)v184 != (unsigned __int8)(v47 + 3)
            && (unsigned __int8)v184 != *(unsigned __int8 *)(v171 + 3744) )
          {
            v8 = v33;
            v11 = v32;
            a4 = v169;
            v20 = v172;
            if ( !(unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a2 + 40)) )
            {
              if ( a2 )
                ++*(_DWORD *)(a2 + 13744);
              qdf_trace_msg(
                0x82u,
                2u,
                "%s: %pK: Invalid RBM %d",
                v140,
                v141,
                v142,
                v143,
                v144,
                v145,
                v146,
                v147,
                "dp_rx_err_process",
                a2,
                v46);
            }
            dp_rx_link_desc_return_by_addr(a2, (unsigned int *)v22, 1u, v140, v141, v142, v143, v144, v145, v146, v147);
            goto LABEL_169;
          }
          v48 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1408);
          v49 = (unsigned int)v181;
          if ( *((_DWORD *)v48 - 1) != 207937137 )
            __break(0x8228u);
          v50 = v48(a2, v49);
          if ( !v50 )
          {
            v137 = printk(
                     &unk_AAA255,
                     "rx_desc",
                     "dp_rx_err_process",
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
            dump_stack(v137);
          }
          v179[0] = *(_BYTE *)(v50 + 28);
          if ( (v28 & 1) != 0 )
          {
LABEL_45:
            v8 = v33;
            if ( (_BYTE)v24 )
            {
              v138 = printk(
                       &unk_AAA255,
                       "err_status == HAL_REO_ERROR_DETECTED",
                       "dp_rx_err_process",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
              dump_stack(v138);
            }
            v11 = v32;
            v51 = jiffies;
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
            a4 = v169;
            v20 = v172;
            if ( (int)v8 > 3 )
            {
              if ( v8 > 0xE )
                goto LABEL_206;
              v52 = 1 << v8;
              if ( ((1 << v8) & 0x11E0) == 0 )
              {
                if ( (v52 & 0x4610) == 0 )
                {
                  if ( (v52 & 0x2800) == 0 )
                    goto LABEL_206;
                  if ( a2 )
                    ++*(_DWORD *)(v168 + 4LL * v8);
                  v53 = v179[0];
                  if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
                    || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), v53) )
                  {
                    v54 = *(_QWORD *)(a2 + 72);
                    if ( v54 )
                      ++*(_DWORD *)(v54 + 508);
                  }
                  v55 = (unsigned int)v178;
                  v56 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
                  if ( *((_DWORD *)v56 - 1) != 1020823628 )
                    __break(0x8228u);
                  v57 = v56(a2, v55);
                  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                    || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                  {
                    raw_spin_lock(a2 + 13304);
                  }
                  else
                  {
                    raw_spin_lock_bh(a2 + 13304);
                    *(_QWORD *)(a2 + 13312) |= 1uLL;
                  }
                  if ( *(_DWORD *)(a2 + 13324) <= (unsigned int)v57 )
                  {
LABEL_69:
                    v58 = 0;
                  }
                  else
                  {
                    v58 = *(_QWORD *)(*(_QWORD *)(a2 + 13136) + 8LL * v57);
                    if ( v58 )
                    {
                      if ( *(unsigned __int8 *)(v58 + 388) <= 2u )
                      {
                        v105 = *(_DWORD *)(v58 + 40);
                        while ( v105 )
                        {
                          _X12 = (unsigned int *)(v58 + 40);
                          __asm { PRFM            #0x11, [X12] }
                          while ( 1 )
                          {
                            v112 = __ldxr(_X12);
                            if ( v112 != v105 )
                              break;
                            if ( !__stlxr(v105 + 1, _X12) )
                            {
                              __dmb(0xBu);
                              break;
                            }
                          }
                          _ZF = v112 == v105;
                          v105 = v112;
                          if ( _ZF )
                          {
                            _X8 = (unsigned int *)(v58 + 280);
                            __asm { PRFM            #0x11, [X8] }
                            do
                              v151 = __ldxr(_X8);
                            while ( __stxr(v151 + 1, _X8) );
                            goto LABEL_70;
                          }
                        }
                      }
                      goto LABEL_69;
                    }
                  }
LABEL_70:
                  v59 = *(_QWORD *)(a2 + 13312);
                  if ( (v59 & 1) != 0 )
                  {
                    *(_QWORD *)(a2 + 13312) = v59 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(a2 + 13304);
                    if ( v58 )
                      goto LABEL_72;
                  }
                  else
                  {
                    raw_spin_unlock(a2 + 13304);
                    if ( v58 )
                    {
LABEL_72:
                      if ( *(_DWORD *)(v58 + 408) == 1 && (v68 = *(_QWORD **)(v58 + 416)) != nullptr )
                      {
                        if ( *v68 )
                          goto LABEL_75;
LABEL_150:
                        dp_peer_unref_delete(v58, 4u, v60, v61, v62, v63, v64, v65, v66, v67);
                      }
                      else
                      {
                        if ( !*(_QWORD *)v58 )
                          goto LABEL_150;
LABEL_75:
                        v69 = jiffies;
                        if ( dp_rx_pn_error_handle___last_ticks - jiffies + 125 < 0 )
                        {
                          qdf_trace_msg(
                            0x45u,
                            2u,
                            "%s: discard rx due to PN error for peer  %pK",
                            v60,
                            v61,
                            v62,
                            v63,
                            v64,
                            v65,
                            v66,
                            v67,
                            "dp_rx_pn_error_handle");
                          dp_rx_pn_error_handle___last_ticks = v69;
                        }
                        dp_txrx_peer_unref_delete(v58, 4u, v60, v61, v62, v63, v64, v65, v66, v67);
                      }
                    }
                  }
                  qdf_trace_msg(
                    0x82u,
                    2u,
                    "%s: %pK: Packet received with PN error",
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    "dp_rx_pn_error_handle",
                    a2);
                  v102 = a2;
                  v103 = (unsigned int *)v22;
                  v104 = 1;
LABEL_167:
                  v101 = dp_rx_msdus_drop(v102, v103, (unsigned __int16 *)&v177, v179, v104);
                  if ( v179[0] )
                    goto LABEL_268;
LABEL_168:
                  v20 += v101;
                  goto LABEL_169;
                }
LABEL_164:
                if ( a2 )
                  ++*(_DWORD *)(v168 + 4LL * v8);
                v102 = a2;
                v103 = (unsigned int *)v22;
                v104 = 0;
                goto LABEL_167;
              }
LABEL_136:
              if ( a2 )
                ++*(_DWORD *)(v168 + 4LL * v8);
              v99 = v179[0];
              if ( !(unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
                || !(unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), v99) )
              {
                v100 = *(_QWORD *)(a2 + 72);
                if ( v100 )
                  ++*(_DWORD *)(v100 + 508);
              }
              v101 = dp_rx_reo_err_entry_process(a2, v22, (unsigned __int16 *)&v177, v36, v8);
              if ( v179[0] )
                goto LABEL_268;
              goto LABEL_168;
            }
            if ( v8 - 1 < 2 )
              goto LABEL_164;
            if ( !v8 )
              goto LABEL_136;
            if ( v8 != 3 )
            {
LABEL_206:
              v134 = printk(
                       &unk_AAA255,
                       "0",
                       "dp_rx_err_process",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
              dump_stack(v134);
              goto LABEL_169;
            }
            v83 = (unsigned int)v178;
            v84 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
            if ( *((_DWORD *)v84 - 1) != 1020823628 )
              __break(0x8228u);
            v85 = v84(a2, v83);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a2 + 13304);
            }
            else
            {
              raw_spin_lock_bh(a2 + 13304);
              *(_QWORD *)(a2 + 13312) |= 1uLL;
            }
            if ( *(_DWORD *)(a2 + 13324) <= (unsigned int)v85 )
            {
LABEL_126:
              v86 = 0;
            }
            else
            {
              v86 = *(_QWORD *)(*(_QWORD *)(a2 + 13136) + 8LL * v85);
              if ( v86 )
              {
                if ( *(unsigned __int8 *)(v86 + 388) <= 2u )
                {
                  v130 = *(_DWORD *)(v86 + 40);
                  while ( v130 )
                  {
                    _X12 = (unsigned int *)(v86 + 40);
                    __asm { PRFM            #0x11, [X12] }
                    while ( 1 )
                    {
                      v133 = __ldxr(_X12);
                      if ( v133 != v130 )
                        break;
                      if ( !__stlxr(v130 + 1, _X12) )
                      {
                        __dmb(0xBu);
                        break;
                      }
                    }
                    _ZF = v133 == v130;
                    v130 = v133;
                    if ( _ZF )
                    {
                      _X8 = (unsigned int *)(v86 + 280);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v157 = __ldxr(_X8);
                      while ( __stxr(v157 + 1, _X8) );
                      goto LABEL_127;
                    }
                  }
                }
                goto LABEL_126;
              }
            }
LABEL_127:
            v87 = *(_QWORD *)(a2 + 13312);
            if ( (v87 & 1) != 0 )
            {
              *(_QWORD *)(a2 + 13312) = v87 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a2 + 13304);
              if ( !v86 )
                goto LABEL_164;
            }
            else
            {
              raw_spin_unlock(a2 + 13304);
              if ( !v86 )
                goto LABEL_164;
            }
            if ( *(_DWORD *)(v86 + 408) != 1 || (v96 = *(__int64 ***)(v86 + 416)) == nullptr )
              v96 = (__int64 **)v86;
            v97 = *v96;
            if ( v97 )
            {
              v98 = *v97;
              if ( v98 )
                ++*(_DWORD *)(v98 + 7392);
              dp_txrx_peer_unref_delete(v86, 4u, v88, v89, v90, v91, v92, v93, v94, v95);
            }
            else
            {
              dp_peer_unref_delete(v86, 4u, v88, v89, v90, v91, v92, v93, v94, v95);
            }
            goto LABEL_164;
          }
          if ( WORD2(v178) )
          {
            if ( (unsigned __int16)v177 != 1 )
            {
              v139 = printk(
                       &unk_AAA255,
                       "mpdu_desc_info.msdu_count == 1",
                       "dp_rx_err_process",
                       "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
              dump_stack(v139);
            }
            v8 = v33;
            dp_rx_bar_frame_handle(a2, (unsigned int *)v22, (__int64 *)v50, (__int64)&v177, v24, v33);
            v11 = v32;
            a4 = v169;
            v20 = v172;
            if ( v179[0] )
              goto LABEL_268;
LABEL_85:
            ++v20;
            goto LABEL_169;
          }
          if ( (v177 & 0x10000000000000LL) == 0 )
            goto LABEL_45;
          if ( v45 != 1 )
          {
            v101 = dp_rx_msdus_drop(a2, (unsigned int *)v22, (unsigned __int16 *)&v177, v179, 0);
            v8 = v33;
            v11 = v32;
            a4 = v169;
            v20 = v172;
            if ( v179[0] )
              goto LABEL_268;
            goto LABEL_168;
          }
          v71 = *(_BYTE *)(v50 + 30);
          v20 = v172;
          if ( (v71 & 1) == 0 )
          {
            if ( a2 )
              ++*(_DWORD *)(a2 + 14056);
            v8 = v33;
            v148 = jiffies;
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
              dp_rx_err_process___last_ticks_49 = v148;
            }
            dp_rx_dump_info_and_assert(a2, a3, v22, v50);
            v11 = v32;
            goto LABEL_147;
          }
          v8 = v33;
          v72 = 80;
          if ( (*(_BYTE *)(*(_QWORD *)v50 + 68LL) & 4) == 0 )
            v72 = 40;
          if ( *(_QWORD *)(*(_QWORD *)v50 + v72) != v185 )
          {
            if ( a2 )
            {
              ++*(_DWORD *)(a2 + 14164);
              v71 = *(_BYTE *)(v50 + 30);
            }
            v11 = v32;
            *(_BYTE *)(v50 + 30) = v71 | 4;
LABEL_147:
            a4 = v169;
            goto LABEL_169;
          }
          v73 = dp_rx_frag_handle(a2, v22, &v177, v50, v179, v169);
          if ( v179[0] )
            goto LABEL_268;
          v74 = v73;
          v11 = v32;
          a4 = v169;
          if ( a2 )
            ++*(_DWORD *)(a2 + 13660);
          v75 = (unsigned int)v178;
          v76 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1432);
          if ( *((_DWORD *)v76 - 1) != 1020823628 )
            __break(0x8228u);
          v77 = v76(a2, v75);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a2 + 13304);
          }
          else
          {
            raw_spin_lock_bh(a2 + 13304);
            *(_QWORD *)(a2 + 13312) |= 1uLL;
          }
          if ( *(_DWORD *)(a2 + 13324) <= (unsigned int)v77 )
            goto LABEL_104;
          v78 = *(_QWORD *)(*(_QWORD *)(a2 + 13136) + 8LL * v77);
          if ( v78 )
            break;
LABEL_105:
          v79 = *(_QWORD *)(a2 + 13312);
          if ( (v79 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 13312) = v79 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 13304);
            v20 = v74 + v172;
            if ( !v78 )
              goto LABEL_169;
          }
          else
          {
            raw_spin_unlock(a2 + 13304);
            v20 = v74 + v172;
            if ( !v78 )
              goto LABEL_169;
          }
          if ( *(_DWORD *)(v78 + 408) != 1 || (v80 = *(__int64 ***)(v78 + 416)) == nullptr )
            v80 = (__int64 **)v78;
          v81 = *v80;
          if ( v81 )
          {
            v82 = *v81;
            if ( v82 )
              ++*(_DWORD *)(v82 + 7396);
            dp_txrx_peer_unref_delete(v78, 4u, v12, v13, v14, v15, v16, v17, v18, v19);
          }
          else
          {
            dp_peer_unref_delete(v78, 4u, v12, v13, v14, v15, v16, v17, v18, v19);
          }
LABEL_169:
          v113 = *(_DWORD *)(a3 + 120);
          if ( v113 != *(_DWORD *)(a3 + 136) )
          {
            v114 = *(_BYTE *)(a3 + 78);
            v115 = *(_DWORD *)(a3 + 44) + v113;
            v116 = *(_QWORD *)(a3 + 16);
            v117 = v115 == *(_DWORD *)(a3 + 36) ? 0 : v115;
            *(_DWORD *)(a3 + 120) = v117;
            if ( (v114 & 4) != 0 )
            {
              _X19 = v116 + 4LL * v117;
              v119 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL);
              if ( (*(_BYTE *)(v119 + 844) & 0x40) == 0 )
              {
                v120 = _X19 << 8 >> 8;
                v121 = (unsigned __int64)(v120 + 0x8000000000LL) >> 38;
                v122 = memstart_addr + v120 + 0x8000000000LL;
                v123 = v120 - kimage_voffset;
                if ( v121 )
                  v124 = v123;
                else
                  v124 = v122;
                _dma_sync_single_for_cpu(v119, v124);
              }
              __asm { PRFM            #0, [X19] }
            }
          }
          if ( a2 && v20 >= v170 )
            ++*(_DWORD *)(a2 + 13688);
          if ( v20 >= v170 )
            goto LABEL_239;
          if ( !a4 )
            goto LABEL_238;
        }
        if ( *(unsigned __int8 *)(v78 + 388) <= 2u )
        {
          v126 = *(_DWORD *)(v78 + 40);
          while ( v126 )
          {
            _X12 = (unsigned int *)(v78 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v129 = __ldxr(_X12);
              if ( v129 != v126 )
                break;
              if ( !__stlxr(v126 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v129 == v126;
            v126 = v129;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v78 + 280);
              __asm { PRFM            #0x11, [X8] }
              do
                v154 = __ldxr(_X8);
              while ( __stxr(v154 + 1, _X8) );
              goto LABEL_105;
            }
          }
        }
LABEL_104:
        v78 = 0;
        goto LABEL_105;
      }
LABEL_238:
      a4 = -1;
    }
LABEL_239:
    dp_srng_access_end(a1, a2, (char *)a3, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( *(_DWORD *)(a2 + 13200) && (unsigned int)jiffies_to_msecs(jiffies) >= *(_DWORD *)(a2 + 13180) )
      dp_rx_defrag_waitlist_flush(a2);
    v179[0] = 0;
    if ( !v20 )
      goto LABEL_253;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), 0) )
    {
      v158 = v179[0];
      if ( v179[0] >= 2u )
        goto LABEL_268;
LABEL_252:
      if ( v158 )
        goto LABEL_268;
      goto LABEL_253;
    }
    v158 = v179[0];
    if ( v179[0] >= 2u )
      goto LABEL_268;
    v159 = *(_QWORD *)(a2 + 72);
    if ( !v159 )
      goto LABEL_252;
    if ( v179[0]
      || (_dp_rx_buffers_replenish(a2, 0, v163, v162, v20, (unsigned int **)(v159 + 96120), v159 + 96128, 0, 0), v179[0]) )
    {
LABEL_268:
      __break(0x5512u);
    }
    v167 += v20;
LABEL_253:
    _ZF = *(_BYTE *)(*(_QWORD *)(a2 + 40) + 684LL) == 1;
    v179[0] = 1;
    if ( !_ZF || !v167 || !a4 || !(unsigned int)dp_rx_srng_get_num_pending(v11, a3, v165, v173) )
      break;
    if ( a2 )
      ++*(_DWORD *)(a2 + 14216);
    v160 = ((__int64 (__fastcall *)(_QWORD, _QWORD))hif_exec_should_yield)(
             *(_QWORD *)(a2 + 64),
             *(unsigned __int8 *)(a1 + 32));
    v7 = a1;
    if ( (v160 & 1) != 0 )
    {
      if ( v173[0] != 1 )
        break;
      v7 = a1;
      if ( a2 )
        ++*(_DWORD *)(a2 + 14220);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v167;
}
