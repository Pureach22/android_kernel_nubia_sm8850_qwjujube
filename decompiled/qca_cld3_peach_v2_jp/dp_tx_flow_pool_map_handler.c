__int64 __fastcall dp_tx_flow_pool_map_handler(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v15; // x22
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x10
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 flow_pool; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  const char *v46; // x3
  __int64 v47; // x4
  __int64 result; // x0
  __int64 v49; // x21
  __int64 v50; // x23
  __int64 ref_by_id_5; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char v60; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  unsigned __int64 v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x24
  __int64 v74; // x23
  unsigned int v75; // w8
  unsigned int v82; // w10
  char v84; // w8
  unsigned int v86; // w9
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x8
  double (__fastcall *v90)(__int64, __int64, __int64); // x8
  __int64 v91; // x1
  double v92; // d0
  unsigned int *v93; // x8
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  _QWORD *v101; // x20
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x0
  __int64 v111; // x21
  unsigned __int64 v112; // x8
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _QWORD *v121; // x0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 (__fastcall *v130)(__int64, __int64); // x8
  __int64 v131; // x0
  __int64 v132; // x8
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x8
  unsigned int *v142; // x8
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  __int64 v151; // x0
  unsigned int v154; // w9
  _QWORD v155[2]; // [xsp+0h] [xbp-10h] BYREF

  v15 = a3;
  v155[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 8);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: flow_id %d flow_type %d flow_pool_id %d flow_pool_size %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_tx_flow_pool_map_handler",
    (unsigned __int8)a2,
    (unsigned __int8)a3,
    (unsigned __int8)a4,
    a5);
  if ( v18 )
  {
    v27 = *(_DWORD **)(v18 + 1832);
    ++*(_WORD *)(v18 + 12880);
    if ( *(v27 - 1) != 219348464 )
      __break(0x822Au);
    if ( (((__int64 (__fastcall *)(__int64, _QWORD, __int64))v27)(v18, a2, 30) & 1) != 0 )
      goto LABEL_84;
    flow_pool = dp_tx_create_flow_pool(v18, a4, a5, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( flow_pool )
    {
      if ( (_BYTE)v15 )
      {
        v45 = "%s: flow type %d not supported";
        v46 = "dp_tx_flow_pool_map_handler";
        v47 = (unsigned __int8)v15;
LABEL_8:
        qdf_trace_msg(0x45u, 2u, v45, v37, v38, v39, v40, v41, v42, v43, v44, v46, v47, v155[0]);
LABEL_84:
        result = 0;
        goto LABEL_85;
      }
      v49 = *(_QWORD *)(a1 + 8);
      v50 = flow_pool;
      ref_by_id_5 = dp_vdev_get_ref_by_id_5(v49, a2, 7u);
      if ( !ref_by_id_5 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid vdev_id %d",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "dp_tx_flow_pool_vdev_map",
          (unsigned __int8)a2);
        goto LABEL_59;
      }
      v15 = ref_by_id_5;
      if ( *(_DWORD *)(ref_by_id_5 + 32) == 6 )
        v60 = *(_BYTE *)(*(_QWORD *)(v49 + 40) + 834LL);
      else
        v60 = 0;
      *(_QWORD *)(ref_by_id_5 + 42432) = v50;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v50 + 256);
      }
      else
      {
        raw_spin_lock_bh(v50 + 256);
        *(_QWORD *)(v50 + 264) |= 1uLL;
      }
      *(_QWORD *)(v50 + 280) = v49;
      *(_BYTE *)(v50 + 58) = a2;
      if ( (v60 & 1) != 0 )
      {
        *(_DWORD *)(v50 + 244) = *(_DWORD *)(v15 + 32);
        qdf_mem_set((void *)(v50 + 152), 0xAu, 0);
        qdf_mem_set((void *)(v50 + 164), 0x14u, 0);
        qdf_mem_set((void *)(v50 + 184), 0x14u, 0);
        qdf_mem_set((void *)(v50 + 204), 0x14u, 0);
        v62 = *(_QWORD *)(v50 + 264);
        *(_BYTE *)(v50 + 248) = 0;
        *(_DWORD *)(v50 + 240) = -1;
        *(_QWORD *)(v50 + 224) = -1;
        *(_QWORD *)(v50 + 232) = -1;
        if ( (v62 & 1) != 0 )
        {
          *(_QWORD *)(v50 + 264) = v62 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v50 + 256);
          v63 = *(_QWORD *)(v15 + 24);
          if ( !v63 )
            goto LABEL_56;
        }
        else
        {
          raw_spin_unlock(v50 + 256);
          v63 = *(_QWORD *)(v15 + 24);
          if ( !v63 )
            goto LABEL_56;
        }
        if ( *(_QWORD *)(v63 + 8) )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v64 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v64 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v64 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v15 + 136);
            v73 = *(_QWORD *)(v15 + 120);
            while ( v73 )
            {
LABEL_27:
              v74 = v73;
              v73 = *(_QWORD *)(v73 + 56);
              v75 = *(_DWORD *)(v74 + 40);
              while ( v75 )
              {
                _X12 = (unsigned int *)(v74 + 40);
                __asm { PRFM            #0x11, [X12] }
                while ( 1 )
                {
                  v82 = __ldxr(_X12);
                  if ( v82 != v75 )
                    break;
                  if ( !__stlxr(v75 + 1, _X12) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v82 == v75;
                v75 = v82;
                if ( _ZF )
                {
                  _X8 = (unsigned int *)(v74 + 284);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v86 = __ldxr(_X8);
                  while ( __stxr(v86 + 1, _X8) );
                  v84 = *(_BYTE *)(v74 + 120);
                  WORD2(v155[0]) = -1;
                  LODWORD(v155[0]) = -1;
                  if ( (v84 & 1) == 0 && (unsigned int)qdf_mem_cmp((const void *)(v74 + 44), v155, 6u) )
                    dp_tx_ndp_update_bw_thresholds(
                      *(__int64 **)v74,
                      5u,
                      *(_DWORD *)(*(_QWORD *)v74 + 2216LL),
                      v65,
                      v66,
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72);
                  dp_peer_unref_delete(v74, 7u, v65, v66, v67, v68, v69, v70, v71, v72);
                  break;
                }
              }
            }
          }
          else
          {
            raw_spin_lock_bh(v15 + 136);
            *(_QWORD *)(v15 + 144) |= 1uLL;
            v73 = *(_QWORD *)(v15 + 120);
            if ( v73 )
              goto LABEL_27;
          }
          v89 = *(_QWORD *)(v15 + 144);
          if ( (v89 & 1) != 0 )
          {
            *(_QWORD *)(v15 + 144) = v89 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v15 + 136);
            goto LABEL_56;
          }
          v88 = v15 + 136;
          goto LABEL_55;
        }
      }
      else
      {
        v87 = *(_QWORD *)(v50 + 264);
        if ( (v87 & 1) == 0 )
        {
          v88 = v50 + 256;
LABEL_55:
          raw_spin_unlock(v88);
          goto LABEL_56;
        }
        *(_QWORD *)(v50 + 264) = v87 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v50 + 256);
      }
LABEL_56:
      v90 = *(double (__fastcall **)(__int64, __int64, __int64))(v49 + 1832);
      v91 = *(unsigned __int8 *)(v15 + 59);
      if ( *((_DWORD *)v90 - 1) != 219348464 )
        __break(0x8228u);
      v92 = v90(v49, v91, 30);
      dp_vdev_unref_delete(v49, v15, 7u, v93, v92, v94, v95, v96, v97, v98, v99, v100);
LABEL_59:
      v101 = *(_QWORD **)(a1 + 8);
      if ( (wlan_cfg_get_dp_tx_page_pool_enabled(v101[5]) & 1) == 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Tx page pool disabled from INI",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "dp_tx_page_pool_vdev_attach");
        goto LABEL_84;
      }
      v110 = dp_vdev_get_ref_by_id_5((__int64)v101, a2, 7u);
      if ( !v110 )
      {
        v45 = "%s: invalid vdev_id %d";
        v46 = "dp_tx_page_pool_vdev_attach";
        v47 = (unsigned __int8)a2;
        goto LABEL_8;
      }
      v111 = v110;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v112 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v112 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v112 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v101 + 2806);
      }
      else
      {
        raw_spin_lock_bh(v101 + 2806);
        v101[2807] |= 1uLL;
      }
      if ( (unsigned __int8)a2 >= 6u )
      {
        __break(0x5512u);
      }
      else
      {
        if ( v101[(unsigned __int8)a2 + 2800] )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Not expected to have tx_pp attached for a new vdev",
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            v120,
            "dp_tx_page_pool_vdev_attach");
          v151 = printk(
                   &unk_9BB309,
                   "0",
                   "dp_tx_page_pool_vdev_attach",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx_flow_control.c");
          dump_stack(v151);
          goto LABEL_81;
        }
        v121 = (_QWORD *)_qdf_mem_malloc(0x40u, "dp_tx_page_pool_vdev_attach", 840);
        if ( !v121 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Failed to allocated memory for tx page pool",
            v122,
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            "dp_tx_page_pool_vdev_attach");
          goto LABEL_81;
        }
        v121[6] = 0;
        v121[7] = 0;
        v15 = (__int64)v121;
        v121[4] = 0;
        v121[5] = 0;
        v121[2] = 0;
        v121[3] = 0;
        *v121 = 0;
        v121[1] = 0;
        v130 = *(__int64 (__fastcall **)(__int64, __int64))(v101[1] + 264LL);
        if ( !v130 )
          goto LABEL_76;
        if ( *((_DWORD *)v130 - 1) != 1104720864 )
          __break(0x8228u);
        v131 = v130(1, 10240);
        if ( v131 && (v132 = *(_QWORD *)(v131 + 8)) != 0 )
        {
          *(_QWORD *)v15 = v132;
          *(_QWORD *)(v15 + 8) = *(unsigned int *)(v131 + 16);
          *(_QWORD *)(v15 + 16) = *(_QWORD *)(v131 + 24);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Tx pp init success pool_size %d pp_size %lu",
            v122,
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            "dp_tx_page_pool_init",
            *(unsigned int *)(v131 + 16));
          *(_DWORD *)(v15 + 40) = 0;
          *(_QWORD *)(v15 + 48) = 0;
          *(_DWORD *)(v15 + 60) = 0;
          *(_BYTE *)(v15 + 56) = 1;
          *(_BYTE *)(v101[3] + 624LL) = 1;
        }
        else
        {
LABEL_76:
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: failed to get tx page pool",
            v122,
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            "dp_tx_page_pool_init",
            v155[0]);
        }
        if ( (*(_BYTE *)(v15 + 56) & 1) == 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Unable to init tx page pool for vdev %d",
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            "dp_tx_page_pool_vdev_attach",
            (unsigned __int8)a2);
          _qdf_mem_free(v15);
          goto LABEL_81;
        }
        v101[(unsigned __int8)a2 + 2800] = v15;
      }
      _X8 = (unsigned int *)(v15 + 60);
      __asm { PRFM            #0x11, [X8] }
      do
        v154 = __ldxr(_X8);
      while ( __stxr(v154 + 1, _X8) );
LABEL_81:
      v141 = v101[2807];
      if ( (v141 & 1) != 0 )
      {
        v101[2807] = v141 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v101 + 2806);
      }
      else
      {
        raw_spin_unlock(v101 + 2806);
      }
      dp_vdev_unref_delete((__int64)v101, v111, 7u, v142, v143, v144, v145, v146, v147, v148, v149, v150);
      goto LABEL_84;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: creation of flow_pool %d size %d failed",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "dp_tx_flow_pool_map_handler",
      (unsigned __int8)a4,
      a5);
    result = 1;
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: soc is NULL", v19, v20, v21, v22, v23, v24, v25, v26, "dp_tx_flow_pool_map_handler");
    result = 5;
  }
LABEL_85:
  _ReadStatusReg(SP_EL0);
  return result;
}
