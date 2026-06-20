__int64 __fastcall dp_fisa_rx_fst_update_work(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 *v11; // x22
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int64 StatusReg; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x26
  unsigned __int16 v48; // w10
  __int64 v49; // x5
  unsigned __int64 v50; // x9
  unsigned __int16 v51; // w8
  unsigned __int16 *v52; // x11
  __int64 ref_by_id_3; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int64 v62; // x8
  __int64 v63; // x1
  int v64; // w4
  unsigned __int64 context; // x0
  __int64 v66; // x1
  int v67; // w10
  unsigned int v68; // w21
  unsigned int v69; // w9
  unsigned int v70; // w23
  int v71; // w8
  unsigned int v72; // w27
  __int64 v73; // x4
  int v74; // w24
  __int64 v75; // x28
  unsigned __int64 v76; // x22
  int v77; // w21
  unsigned int v78; // w24
  int v79; // w27
  int v80; // w25
  unsigned __int64 v81; // x28
  unsigned int *v83; // x8
  unsigned int v84; // w8
  unsigned int v86; // w8
  __int64 v87; // x8
  unsigned int v88; // w20
  int v89; // w21
  __int64 v90; // x20
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x1
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x8
  __int64 v97; // x9
  char v98; // w10
  __int64 v99; // x8
  __int64 v100; // x9
  __int16 v101; // w11
  __int64 v102; // x1
  __int64 v103; // x10
  __int64 v104; // x10
  __int64 v105; // x0
  char v106; // w8
  void *v107; // x0
  __int64 v108; // x1
  int v109; // w9
  int v110; // w10
  int v111; // w8
  int v112; // w11
  char v113; // w9
  char v114; // w8
  unsigned __int64 v115; // t2
  __int64 v116; // x8
  __int64 v117; // x0
  __int64 v118; // x8
  __int64 v119; // x20
  unsigned int v120; // w23
  char v121; // w8
  _QWORD *v122; // x20
  __int64 v123; // x0
  unsigned int v124; // w23
  __int64 v125; // x8
  __int64 v126; // x20
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // x22
  unsigned int v140; // w8
  unsigned int v143; // w8
  __int64 v144; // [xsp+8h] [xbp-288h]
  int v145; // [xsp+10h] [xbp-280h]
  int v146; // [xsp+14h] [xbp-27Ch]
  unsigned __int64 v147; // [xsp+18h] [xbp-278h]
  __int64 *v148; // [xsp+20h] [xbp-270h]
  unsigned __int64 v149; // [xsp+28h] [xbp-268h]
  unsigned int v150; // [xsp+30h] [xbp-260h]
  unsigned int v151; // [xsp+34h] [xbp-25Ch]
  __int64 v152; // [xsp+38h] [xbp-258h]
  unsigned int v153; // [xsp+40h] [xbp-250h]
  unsigned int v154; // [xsp+44h] [xbp-24Ch]
  __int64 v155; // [xsp+48h] [xbp-248h] BYREF
  _QWORD v156[2]; // [xsp+50h] [xbp-240h] BYREF
  __int64 v157; // [xsp+60h] [xbp-230h]
  __int64 v158; // [xsp+68h] [xbp-228h]
  __int64 v159; // [xsp+70h] [xbp-220h]
  __int64 v160; // [xsp+78h] [xbp-218h]
  _QWORD v161[32]; // [xsp+80h] [xbp-210h] BYREF
  __int64 v162; // [xsp+180h] [xbp-110h] BYREF
  __int64 v163; // [xsp+188h] [xbp-108h]
  unsigned __int64 v164; // [xsp+190h] [xbp-100h]
  __int64 v165; // [xsp+198h] [xbp-F8h]
  _DWORD v166[6]; // [xsp+1A0h] [xbp-F0h] BYREF
  __int64 v167; // [xsp+1B8h] [xbp-D8h]
  __int64 v168; // [xsp+1C0h] [xbp-D0h]
  __int64 v169; // [xsp+1C8h] [xbp-C8h]
  __int64 v170; // [xsp+1D0h] [xbp-C0h]
  __int64 v171; // [xsp+1D8h] [xbp-B8h]
  __int64 v172; // [xsp+1E0h] [xbp-B0h]
  __int64 v173; // [xsp+1E8h] [xbp-A8h]
  __int64 v174; // [xsp+1F0h] [xbp-A0h]
  __int64 v175; // [xsp+1F8h] [xbp-98h]
  __int64 v176; // [xsp+200h] [xbp-90h]
  __int64 v177; // [xsp+208h] [xbp-88h]
  __int64 v178; // [xsp+210h] [xbp-80h]
  __int64 v179; // [xsp+218h] [xbp-78h]
  __int64 v180; // [xsp+220h] [xbp-70h]
  __int64 v181; // [xsp+228h] [xbp-68h]
  __int64 v182; // [xsp+230h] [xbp-60h]
  __int64 v183; // [xsp+238h] [xbp-58h]
  __int64 v184; // [xsp+240h] [xbp-50h]
  __int64 v185; // [xsp+248h] [xbp-48h]
  __int64 v186; // [xsp+250h] [xbp-40h]
  __int64 v187; // [xsp+258h] [xbp-38h]
  __int64 v188; // [xsp+260h] [xbp-30h]
  __int64 v189; // [xsp+268h] [xbp-28h]
  __int64 v190; // [xsp+270h] [xbp-20h]
  __int64 v191; // [xsp+278h] [xbp-18h]
  __int64 v192; // [xsp+280h] [xbp-10h]

  v9 = result;
  v192 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(result + 8);
  v155 = 0;
  v11 = *(__int64 **)(v10 + 256);
  if ( *(_DWORD *)(result + 612) )
  {
    v12 = jiffies;
    if ( dp_fisa_rx_fst_update_work___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: WQ triggered during suspend stage, deferred update",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "dp_fisa_rx_fst_update_work");
      dp_fisa_rx_fst_update_work___last_ticks = v12;
    }
    if ( v9 )
      ++*(_DWORD *)(v9 + 324);
    goto LABEL_18;
  }
  if ( (unsigned int)hif_force_wake_request(*v11) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Wake up request failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_fisa_rx_fst_update_work");
    goto LABEL_17;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 48);
  }
  else
  {
    raw_spin_lock_bh(v9 + 48);
    *(_QWORD *)(v9 + 56) |= 1uLL;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 408), &v155) )
  {
LABEL_13:
    v38 = *(_QWORD *)(v9 + 56);
    if ( (v38 & 1) != 0 )
    {
      *(_QWORD *)(v9 + 56) = v38 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v9 + 48);
    }
    else
    {
      raw_spin_unlock(v9 + 48);
    }
    result = hif_force_wake_release(*v11);
    if ( !(_DWORD)result )
      goto LABEL_18;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Wake up release failed",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "dp_fisa_rx_fst_update_work");
LABEL_17:
    result = qdf_check_state_before_panic(v21, v22, v23, v24, v25, v26, v27, v28);
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v144 = v9 + 440;
  v148 = v11;
  v149 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v47 = v155;
    if ( *(_DWORD *)(v155 + 80) == 2 )
    {
      v48 = *(_WORD *)(v9 + 32);
      v49 = *(unsigned __int16 *)(v155 + 72);
      if ( v48 )
      {
        v50 = 0;
        v51 = 0;
        v52 = (unsigned __int16 *)(*(_QWORD *)v9 + 36LL);
        do
        {
          if ( *((_BYTE *)v52 + 4) && *v52 == (_DWORD)v49 )
          {
            *v52 = -1;
            ++v51;
            v48 = *(_WORD *)(v9 + 32);
          }
          ++v50;
          v52 += 168;
        }
        while ( v50 < v48 );
        v73 = v51;
      }
      else
      {
        v73 = 0;
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Invalidated %d entries for peer %hu",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "_dp_fisa_rx_fst_inv_peer_id",
        v73,
        v49);
      goto LABEL_23;
    }
    ref_by_id_3 = dp_vdev_get_ref_by_id_3(*(_QWORD *)(v9 + 80), *(unsigned __int8 *)(v155 + 74));
    if ( ref_by_id_3 )
      break;
LABEL_23:
    qdf_list_remove_front((_DWORD *)(v9 + 408), &v155);
    _qdf_mem_free(v47);
    if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 408), &v155) )
      goto LABEL_13;
  }
  v62 = *(_QWORD *)(v47 + 64);
  v63 = ref_by_id_3;
  if ( ref_by_id_3 != v62 )
  {
LABEL_22:
    dp_vdev_unref_delete(*(_QWORD *)(v9 + 80), v63, 2u, (unsigned int *)v62, v54, v55, v56, v57, v58, v59, v60, v61);
    goto LABEL_23;
  }
  v64 = *(_DWORD *)(v47 + 80);
  v152 = ref_by_id_3;
  if ( v64 == 1 )
  {
    v87 = *(_QWORD *)(v9 + 56);
    v88 = *(_DWORD *)(v47 + 76);
    v89 = *(_DWORD *)(v9 + 40);
    if ( (v87 & 1) != 0 )
    {
      *(_QWORD *)(v9 + 56) = v87 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v9 + 48);
    }
    else
    {
      raw_spin_unlock(v9 + 48);
    }
    dp_fisa_rx_delete_flow(v9, 0, v89 & v88, 3);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v149 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v149 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v9 + 48);
    }
    else
    {
      raw_spin_lock_bh(v9 + 48);
      *(_QWORD *)(v9 + 56) |= 1uLL;
    }
    v62 = *(unsigned __int8 *)(v9 + 152);
    v63 = v152;
    if ( (_DWORD)v62 != 1 )
      goto LABEL_22;
    _X9 = (unsigned int *)(v9 + 88);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v140 = __ldxr(_X9);
      v62 = v140 + 1;
    }
    while ( __stlxr(v62, _X9) );
    __dmb(0xBu);
    if ( (_DWORD)v62 != 1 )
      goto LABEL_22;
    v90 = jiffies;
    *(_QWORD *)(v9 + 112) = v90 + 2LL * (unsigned int)qdf_timer_get_multiplier();
    add_timer(v9 + 96);
    goto LABEL_68;
  }
  if ( v64 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: invalid action code:%u",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "dp_fisa_rx_fst_update_work");
LABEL_68:
    v63 = v152;
    goto LABEL_22;
  }
  context = dp_get_context();
  v67 = *(_DWORD *)(v47 + 76);
  v68 = 0;
  v69 = *(unsigned __int16 *)(v9 + 36);
  v147 = context;
  v70 = *(_DWORD *)(v9 + 40) & v67;
  v71 = *(_DWORD *)(v47 + 84);
  v159 = 0;
  v160 = 0;
  v72 = v69 + 1;
  v157 = 0;
  v158 = 0;
  v145 = v67;
  v146 = v71;
  v156[0] = 0;
  v156[1] = 0;
  v150 = v69;
  v151 = 0;
  v153 = -1;
  while ( 1 )
  {
    v75 = *(_QWORD *)v9 + 336LL * v70;
    v74 = *(unsigned __int8 *)(v75 + 40);
    if ( !*(_BYTE *)(v75 + 40) )
      break;
    if ( !(*(_DWORD *)(v47 + 48) ^ *(_DWORD *)(v75 + 120)
         | *(_DWORD *)(v47 + 44) ^ *(_DWORD *)(v75 + 116)
         | *(unsigned __int16 *)(v47 + 52) ^ *(unsigned __int16 *)(v75 + 124)
         | *(unsigned __int16 *)(v47 + 54) ^ *(unsigned __int16 *)(v75 + 126)
         | *(_DWORD *)(v47 + 40) ^ *(_DWORD *)(v75 + 112)
         | *(_DWORD *)(v47 + 36) ^ *(_DWORD *)(v75 + 108)
         | *(_DWORD *)(v47 + 32) ^ *(_DWORD *)(v75 + 104)
         | *(_DWORD *)(v47 + 28) ^ *(_DWORD *)(v75 + 100)
         | *(_DWORD *)(v47 + 24) ^ *(_DWORD *)(v75 + 96)
         | *(_DWORD *)(v47 + 20) ^ *(_DWORD *)(v75 + 92)
         | *(unsigned __int16 *)(v47 + 56) ^ *(unsigned __int16 *)(v75 + 128)) )
      goto LABEL_98;
    ++*(_DWORD *)(v9 + 72);
    v76 = *(_QWORD *)(v75 + 256);
    context = sched_clock(context, v66);
    if ( context > v76 )
    {
      v154 = v68;
      v77 = v74;
      v78 = v72;
      v79 = *(unsigned __int8 *)(v75 + 323);
      v80 = *(unsigned __int8 *)(v75 + 322);
      v81 = *(_QWORD *)(v75 + 328);
      context = sched_clock(context, v66);
      if ( v80 )
        _ZF = 1;
      else
        _ZF = v79 == 2;
      if ( _ZF && context - v76 < v81 )
      {
        v72 = v78;
        v74 = v77;
      }
      else
      {
        v83 = (unsigned int *)(*(_QWORD *)v9 + 336LL * v70);
        v72 = v78;
        if ( *(_BYTE *)(v9 + 609) == 1 )
          context = hal_rx_flow_get_cmem_fse_timestamp(*(_QWORD *)(*(_QWORD *)(v9 + 8) + 256LL), v83[59]);
        else
          context = *(unsigned int *)(*(_QWORD *)v83 + 52LL);
        v84 = v153;
        v74 = v77;
        _CF = (unsigned int)context >= v153;
        if ( (unsigned int)context < v153 )
          v84 = context;
        v153 = v84;
        v86 = v151;
        if ( !_CF )
          v86 = v70;
        v151 = v86;
      }
      v68 = v154;
    }
    ++v68;
    v70 = *(_DWORD *)(v9 + 40) & (v70 + 1);
    if ( v72 == v68 )
    {
      v68 = v72;
LABEL_98:
      v63 = v152;
LABEL_99:
      v62 = v150;
      if ( v68 <= v150 )
        goto LABEL_20;
      v62 = v153;
      if ( v153 == -1 )
        goto LABEL_20;
      v62 = *(unsigned __int8 *)(v147 + 219);
      if ( (_DWORD)v62 != 1 )
        goto LABEL_20;
      v122 = (_QWORD *)(*(_QWORD *)v9 + 336LL * v151);
      v123 = sched_clock(context, v63);
      if ( (unsigned __int64)(v123 - v122[32]) > 0xB2D05E00 )
      {
        v124 = 1;
        v125 = *(_QWORD *)(v9 + 56);
        if ( (v125 & 1) == 0 )
          goto LABEL_104;
LABEL_114:
        *(_QWORD *)(v9 + 56) = v125 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v9 + 48);
        goto LABEL_105;
      }
      v63 = v152;
      v62 = v123 - v122[31];
      if ( v62 <= 0xB2D05E00 || (v62 = v122[35], v62 > 9) )
      {
LABEL_20:
        if ( !v74 )
          goto LABEL_109;
      }
      else
      {
        v124 = 2;
        v125 = *(_QWORD *)(v9 + 56);
        if ( (v125 & 1) != 0 )
          goto LABEL_114;
LABEL_104:
        raw_spin_unlock(v9 + 48);
LABEL_105:
        dp_fisa_rx_delete_flow(v9, v47, v151, v124);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v149 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v149 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v9 + 48);
          v63 = v152;
        }
        else
        {
          raw_spin_lock_bh(v9 + 48);
          v63 = v152;
          *(_QWORD *)(v9 + 56) |= 1uLL;
        }
LABEL_109:
        v62 = *(unsigned __int8 *)(v9 + 152);
        if ( (_DWORD)v62 == 1 )
        {
          _X9 = (unsigned int *)(v9 + 88);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v143 = __ldxr(_X9);
            v62 = v143 + 1;
          }
          while ( __stlxr(v62, _X9) );
          __dmb(0xBu);
          if ( (_DWORD)v62 == 1 )
          {
            v126 = jiffies;
            *(_QWORD *)(v9 + 112) = v126 + 2LL * (unsigned int)qdf_timer_get_multiplier();
            add_timer(v9 + 96);
            v63 = v152;
          }
        }
      }
      v11 = v148;
      goto LABEL_22;
    }
  }
  v91 = *(_QWORD *)(v9 + 56);
  if ( (v91 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 56) = v91 & 0xFFFFFFFFFFFFFFFELL;
    v92 = raw_spin_unlock_bh(v9 + 48);
  }
  else
  {
    v92 = raw_spin_unlock(v9 + 48);
  }
  if ( *(_BYTE *)(v9 + 608) != 1 )
  {
LABEL_77:
    v96 = *(_QWORD *)(v47 + 64);
    v97 = *(_QWORD *)(v9 + 8);
    *(_DWORD *)(v75 + 16) = v70;
    *(_DWORD *)(v75 + 8) = v145;
    v98 = *(_BYTE *)(v96 + 59);
    *(_QWORD *)(v75 + 152) = v96;
    *(_BYTE *)(v75 + 160) = v98;
    v99 = *(_QWORD *)(*(_QWORD *)(v96 + 88) + 32LL);
    *(_QWORD *)(v75 + 200) = v97;
    *(_QWORD *)(v75 + 168) = v99;
    v100 = *(_QWORD *)v9;
    LODWORD(v99) = *(_DWORD *)(v9 + 432);
    *(_QWORD *)&v166[3] = 0;
    *(_QWORD *)&v166[1] = 0;
    LODWORD(v99) = v99 + 1;
    *(_DWORD *)(v9 + 432) = v99;
    *(_DWORD *)(v100 + 336LL * v70 + 240) = v99;
    BYTE1(v166[2]) = v146;
    v101 = *(_WORD *)(v47 + 56);
    v102 = *(unsigned int *)(v9 + 436);
    v166[3] = v99;
    LODWORD(v100) = *(_DWORD *)(v47 + 24);
    v103 = *(_QWORD *)(v47 + 28);
    LODWORD(v162) = *(_DWORD *)(v47 + 20);
    HIDWORD(v162) = v100;
    LODWORD(v99) = *(_DWORD *)(v47 + 36);
    LODWORD(v100) = *(_DWORD *)(v47 + 40);
    v163 = v103;
    LOWORD(v166[1]) = v101;
    v164 = __PAIR64__(v100, v99);
    LODWORD(v99) = *(_DWORD *)(v47 + 44);
    LOWORD(v100) = *(_WORD *)(v47 + 52);
    HIDWORD(v165) = *(_DWORD *)(v47 + 48);
    v104 = *(_QWORD *)(v9 + 8);
    LODWORD(v165) = v99;
    LOWORD(v99) = *(_WORD *)(v47 + 54);
    v105 = *(_QWORD *)(v104 + 256);
    LOWORD(v166[0]) = v100;
    HIWORD(v166[0]) = v99;
    *(_DWORD *)(v75 + 236) = hal_rx_flow_setup_cmem_fse(v105, v102, v70, &v162);
    *(_BYTE *)(v75 + 40) = 1;
    v106 = *(_BYTE *)(v47 + 90);
    *(_DWORD *)(v75 + 244) = v146;
    *(_BYTE *)(v75 + 144) = v106;
    v107 = qdf_mem_copy((void *)(v75 + 88), (const void *)(v47 + 16), 0x2Cu);
    v109 = *(_DWORD *)(v75 + 120);
    v110 = *(_DWORD *)(v75 + 124);
    v111 = *(unsigned __int8 *)(v75 + 128);
    v112 = *(_DWORD *)(v75 + 104);
    LODWORD(v160) = 0;
    LODWORD(v156[0]) = v109;
    if ( v111 == 17 )
      v113 = 0;
    else
      v113 = -22;
    LODWORD(v157) = v112;
    if ( v111 == 6 )
      v114 = 1;
    else
      v114 = v113;
    HIDWORD(v115) = v110;
    LODWORD(v115) = v110;
    BYTE4(v159) = v114;
    LODWORD(v159) = v115 >> 16;
    *(_QWORD *)(v75 + 136) = v156[0] ^ v157 ^ v159 ^ 0x574C414E5F44505FLL;
    v92 = sched_clock(v107, v108);
    *(_QWORD *)(v75 + 248) = v92;
    *(_QWORD *)(v75 + 256) = v92;
    *(_BYTE *)(v75 + 42) = *(_BYTE *)(v47 + 88);
    *(_BYTE *)(v75 + 41) = *(_BYTE *)(v47 + 89);
    *(_WORD *)(v75 + 36) = *(_WORD *)(v47 + 72);
    __isb(0xFu);
    *(_QWORD *)(v75 + 272) = _ReadStatusReg(CNTVCT_EL0);
    if ( *(_BYTE *)(v9 + 608) == 1 )
    {
      v116 = *(unsigned __int8 *)(v47 + 90);
      if ( (unsigned int)v116 >= 9 )
        goto LABEL_131;
      v117 = v144 + 16 * v116;
      v118 = *(_QWORD *)(v117 + 8);
      if ( (v118 & 1) != 0 )
      {
        *(_QWORD *)(v117 + 8) = v118 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v117);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
          goto LABEL_90;
LABEL_88:
        if ( (*(_DWORD *)(v149 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v149 + 16) & 0xFF00) == 0 )
        {
          context = raw_spin_lock_bh(v9 + 48);
          *(_QWORD *)(v9 + 56) |= 1uLL;
          goto LABEL_91;
        }
LABEL_90:
        context = raw_spin_lock(v9 + 48);
LABEL_91:
        v63 = v152;
        v119 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 2936LL);
        if ( v119 )
        {
          v120 = *(_DWORD *)(v75 + 16);
          v191 = 0;
          v190 = 0;
          v189 = 0;
          v188 = 0;
          v187 = 0;
          v186 = 0;
          v185 = 0;
          v184 = 0;
          v183 = 0;
          v182 = 0;
          v181 = 0;
          v180 = 0;
          v179 = 0;
          v178 = 0;
          v162 = 0;
          v121 = *(_BYTE *)(v119 + 148);
          v177 = 0;
          v175 = 0;
          v176 = 0;
          v173 = 0;
          v174 = 0;
          v171 = 0;
          v172 = 0;
          v169 = 0;
          v170 = 0;
          v167 = 0;
          v168 = 0;
          v165 = 0;
          memset(v166, 0, sizeof(v166));
          v163 = 0;
          v164 = 0;
          memset(v161, 0, sizeof(v161));
          if ( (v121 & 8) != 0 )
          {
            dp_print_tuple_to_str(v156, &v162);
            dp_print_rx_flow_info_to_str(v120, v161);
            context = qdf_trace_msg(
                        0x45u,
                        5u,
                        "%s: STC: Add RX flow [%u] %s [%s]",
                        v127,
                        v128,
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        "wlan_dp_indicate_flow_add",
                        v120,
                        &v162,
                        v161);
            v63 = v152;
          }
          if ( *(_DWORD *)(v119 + 152) <= 1u )
          {
            context = qdf_periodic_work_start(v119 + 16, *(_DWORD *)(v119 + 144));
            v63 = v152;
            *(_DWORD *)(v119 + 152) = 2;
          }
        }
        ++*(_DWORD *)(v9 + 64);
        goto LABEL_99;
      }
      raw_spin_unlock(v117);
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_90;
    goto LABEL_88;
  }
  v94 = *(unsigned __int8 *)(v47 + 90);
  if ( (unsigned int)v94 < 9 )
  {
    v95 = v144 + 16 * v94;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v149 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v149 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v95);
    }
    else
    {
      v135 = v144 + 16 * v94;
      raw_spin_lock_bh(v95);
      *(_QWORD *)(v135 + 8) |= 1uLL;
    }
    goto LABEL_77;
  }
LABEL_131:
  __break(0x5512u);
  return dp_vdev_get_ref_by_id_3(v92, v93);
}
