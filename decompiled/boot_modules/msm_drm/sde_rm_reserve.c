__int64 __fastcall sde_rm_reserve(__int64 a1, int *a2, __int64 a3, __int64 *a4, char a5)
{
  __int64 v5; // x26
  __int64 *v6; // x27
  __int64 v8; // x8
  _QWORD *v9; // x20
  __int64 *v10; // x8
  __int64 result; // x0
  __int64 j; // x24
  __int64 v14; // x0
  int v15; // w22
  void *v16; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 (__fastcall *v20)(_QWORD); // x8
  char v21; // w22
  int v22; // w25
  int v23; // w24
  int v24; // w28
  char v25; // w0
  __int64 *v26; // x28
  _QWORD *v27; // x23
  __int64 i; // x25
  _QWORD *rsvp_nxt_locked; // x0
  __int64 v30; // x8
  __int64 v31; // x20
  __int64 v32; // x22
  __int64 v33; // x8
  __int64 k; // x12
  _DWORD *v35; // x8
  char v36; // w8
  __int64 v37; // x8
  _QWORD *v38; // x0
  unsigned __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x0
  __int64 v43; // x1
  __int64 v44; // x8
  int num_datapath; // w25
  __int64 *v46; // x20
  __int64 v47; // x8
  int v48; // w11
  __int64 *v49; // x20
  __int64 v50; // t1
  __int64 v51; // x0
  __int64 v52; // x20
  _QWORD *v53; // x20
  __int64 v54; // x8
  int v55; // w8
  int v56; // w9
  _DWORD *v57; // x8
  __int64 v58; // x8
  int *v59; // x9
  unsigned __int8 *v60; // x10
  _BYTE *v61; // x11
  int *v62; // x11
  unsigned __int8 *v63; // x8
  unsigned __int8 *v64; // x9
  unsigned __int8 *v65; // x22
  int *v66; // x10
  __int64 *v67; // x1
  int v68; // w8
  int v69; // w9
  int v70; // w8
  unsigned int v71; // w8
  int v72; // w5
  int v73; // w8
  unsigned int v74; // w8
  unsigned __int64 v75; // x28
  _DWORD *v76; // x8
  __int64 v77; // x3
  int v78; // w4
  int v79; // w6
  __int64 v80; // x28
  char v81; // w8
  __int64 v82; // x3
  __int64 v83; // x7
  int v84; // w6
  char v85; // w8
  __int64 v86; // x20
  int v87; // w8
  __int64 v88; // x8
  __int64 v89; // x9
  __int64 v90; // x11
  __int64 v91; // x10
  int v92; // w4
  int v93; // w6
  __int64 v94; // x9
  __int64 v95; // x9
  unsigned int v96; // w8
  unsigned __int8 *v97; // x26
  int v98; // w0
  int v99; // w8
  int v100; // w0
  unsigned __int8 *v101; // x3
  unsigned int v102; // w8
  unsigned __int8 *v103; // x20
  unsigned __int8 *v104; // x20
  unsigned __int8 *v105; // x20
  __int64 v106; // x9
  int v107; // w20
  unsigned int v108; // w8
  unsigned __int8 *v109; // x20
  int v110; // w26
  __int64 v111; // x8
  __int64 v112; // x10
  __int64 v113; // x10
  int v114; // w6
  __int64 m; // x20
  __int64 v116; // x8
  __int64 v117; // x20
  __int64 v118; // x8
  __int64 v119; // x9
  __int64 v120; // x9
  int v121; // w7
  __int64 v122; // x20
  __int64 **v123; // x26
  __int64 *v124; // x27
  __int64 v125; // x8
  int v126; // w9
  __int64 v127; // x8
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x9
  __int64 v130; // x8
  unsigned __int64 v137; // x10
  __int64 v138; // x8
  __int64 *n; // x10
  __int64 v140; // x12
  __int64 *v141; // x22
  int v142; // w6
  int v143; // w7
  __int64 *v144; // x24
  __int64 v145; // x8
  int v146; // w4
  int v147; // w5
  __int64 v148; // x8
  int v149; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v151; // x23
  char v152; // [xsp+0h] [xbp-280h]
  char v153; // [xsp+0h] [xbp-280h]
  char v154; // [xsp+38h] [xbp-248h]
  unsigned int v155; // [xsp+3Ch] [xbp-244h]
  _QWORD *v156; // [xsp+40h] [xbp-240h]
  __int64 v157; // [xsp+48h] [xbp-238h] BYREF
  __int64 v158; // [xsp+50h] [xbp-230h]
  __int64 v159; // [xsp+58h] [xbp-228h]
  __int64 v160; // [xsp+60h] [xbp-220h] BYREF
  __int64 v161; // [xsp+68h] [xbp-218h]
  __int64 v162; // [xsp+70h] [xbp-210h]
  int v163[2]; // [xsp+78h] [xbp-208h] BYREF
  _DWORD *v164; // [xsp+80h] [xbp-200h]
  __int64 v165; // [xsp+88h] [xbp-1F8h] BYREF
  __int64 v166; // [xsp+90h] [xbp-1F0h]
  __int64 v167; // [xsp+98h] [xbp-1E8h]
  __int64 v168; // [xsp+A0h] [xbp-1E0h]
  __int64 v169; // [xsp+A8h] [xbp-1D8h]
  __int64 v170; // [xsp+B0h] [xbp-1D0h]
  __int64 v171; // [xsp+B8h] [xbp-1C8h]
  __int64 v172; // [xsp+C0h] [xbp-1C0h]
  __int64 v173; // [xsp+C8h] [xbp-1B8h]
  __int128 v174; // [xsp+D0h] [xbp-1B0h]
  _QWORD *v175; // [xsp+E0h] [xbp-1A0h]
  __int64 v176; // [xsp+E8h] [xbp-198h]
  _QWORD v177[12]; // [xsp+F0h] [xbp-190h] BYREF
  _QWORD v178[12]; // [xsp+150h] [xbp-130h] BYREF
  __int64 v179; // [xsp+1B0h] [xbp-D0h] BYREF
  __int64 v180; // [xsp+1B8h] [xbp-C8h]
  __int64 v181; // [xsp+1C0h] [xbp-C0h]
  __int64 v182; // [xsp+1C8h] [xbp-B8h]
  __int64 v183; // [xsp+1D0h] [xbp-B0h]
  __int64 v184; // [xsp+1D8h] [xbp-A8h]
  __int64 v185; // [xsp+1E0h] [xbp-A0h]
  __int64 v186; // [xsp+1E8h] [xbp-98h]
  __int64 v187; // [xsp+1F0h] [xbp-90h]
  __int64 v188; // [xsp+1F8h] [xbp-88h]
  __int64 v189; // [xsp+200h] [xbp-80h]
  __int64 v190; // [xsp+208h] [xbp-78h]
  __int64 v191; // [xsp+210h] [xbp-70h] BYREF
  __int64 v192; // [xsp+218h] [xbp-68h]
  __int64 v193; // [xsp+220h] [xbp-60h]
  __int64 v194; // [xsp+228h] [xbp-58h]
  __int64 v195; // [xsp+230h] [xbp-50h]
  __int64 v196; // [xsp+238h] [xbp-48h]
  __int64 v197; // [xsp+240h] [xbp-40h]
  __int64 v198; // [xsp+248h] [xbp-38h]
  __int64 v199; // [xsp+250h] [xbp-30h]
  __int64 v200; // [xsp+258h] [xbp-28h]
  __int64 v201; // [xsp+260h] [xbp-20h]
  __int64 v202; // [xsp+268h] [xbp-18h]
  __int64 v203; // [xsp+270h] [xbp-10h]

  v203 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v175 = nullptr;
  v176 = 0;
  v174 = 0u;
  v172 = 0;
  v173 = 0;
  v170 = 0;
  v171 = 0;
  v168 = 0;
  v169 = 0;
  v166 = 0;
  v167 = 0;
  v164 = nullptr;
  v165 = 0;
  *(_QWORD *)v163 = 0;
  if ( !a1 || (v5 = (__int64)a2) == 0 || (v6 = (__int64 *)a3) == nullptr || !a4 )
  {
    v16 = &unk_26FEB0;
    goto LABEL_54;
  }
  if ( !*(_QWORD *)a2 || (v8 = *(_QWORD *)(*(_QWORD *)a2 + 56LL)) == 0 )
  {
    v16 = &unk_273DA6;
LABEL_54:
    printk(v16, "sde_rm_reserve");
    result = 4294967274LL;
    goto LABEL_442;
  }
  v9 = *(_QWORD **)(v8 + 8);
  if ( !v9 )
  {
    v16 = &unk_234896;
    goto LABEL_54;
  }
  v10 = (__int64 *)*a4;
  if ( (*(_BYTE *)(*a4 + 5128) & 1) != 0 )
    goto LABEL_9;
  if ( (int *)v9[340] == a2 )
  {
    if ( (v9[339] & 1) != 0 )
      goto LABEL_16;
  }
  else if ( (int *)v9[350] == a2 && (v9[349] & 1) != 0 )
  {
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(a3 + 10) & 0xE) == 0 )
  {
    if ( !v10 )
      goto LABEL_9;
    v17 = *v10;
    if ( !v17 )
      goto LABEL_9;
    v18 = *(_QWORD *)(v17 + 56);
    if ( !v18 )
      goto LABEL_9;
    v19 = *(_QWORD *)(v18 + 8);
    if ( !v19 )
      goto LABEL_9;
    v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v19 + 80LL);
    if ( !v20 )
      goto LABEL_9;
    v21 = a5;
    if ( *((_DWORD *)v20 - 1) != -1440990782 )
      __break(0x8228u);
    result = v20(a4);
    if ( !result )
      goto LABEL_442;
    a5 = v21;
    if ( (*(_WORD *)(result + 8) & 0x1D4) == 0 )
    {
LABEL_9:
      result = 0;
      goto LABEL_442;
    }
  }
LABEL_16:
  LOBYTE(j) = a5;
  v14 = _kmalloc_cache_noprof(_wake_up, 3520, 688);
  if ( !v14 )
  {
LABEL_439:
    result = 4294967284LL;
    goto LABEL_442;
  }
LABEL_17:
  v156 = (_QWORD *)v14;
  v154 = j;
  v15 = j & 1;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "reserving hw for conn %d enc %d crtc %d test_only %d\n",
      *(_DWORD *)(*a4 + 64),
      *(_DWORD *)(v5 + 24),
      *(_DWORD *)(*v6 + 112),
      j & 1);
  v22 = *(_DWORD *)(v5 + 24);
  v23 = sde_dbg_base_evtlog;
  v24 = *(_DWORD *)(*a4 + 64);
  v25 = sde_crtc_state_in_lb_mode(v6);
  sde_evtlog_log(v23, "sde_rm_reserve", 3078, -1, v22, v24, v15, v25 & 1, (*(_DWORD *)(v5 + 644) & 0x80) != 0);
  mutex_lock(a1 + 280);
  sde_rm_print_rsvps(a1, 0);
  v26 = (__int64 *)(a1 + 8);
  j = *(_QWORD *)(a1 + 8);
  if ( j == a1 + 8 )
  {
    v27 = v156;
LABEL_38:
    j = 0;
  }
  else
  {
    v27 = v156;
    while ( (*(_BYTE *)(j + 28) & 1) != 0 || *(_DWORD *)(j + 20) != *(_DWORD *)(v5 + 24) )
    {
      j = *(_QWORD *)j;
      if ( (__int64 *)j == v26 )
        goto LABEL_38;
    }
  }
  for ( i = *v26; (__int64 *)i != v26; i = *(_QWORD *)i )
  {
    if ( *(_BYTE *)(i + 28) && *(_DWORD *)(i + 20) == *(_DWORD *)(v5 + 24) )
    {
      if ( i && (v154 & 1) != 0 )
      {
        rsvp_nxt_locked = sde_rm_poll_get_rsvp_nxt_locked(a1, v5);
        for ( j = *(_QWORD *)(a1 + 8); (__int64 *)j != v26; j = *(_QWORD *)j )
        {
          if ( (*(_BYTE *)(j + 28) & 1) == 0 && *(_DWORD *)(j + 20) == *(_DWORD *)(v5 + 24) )
            goto LABEL_59;
        }
        j = 0;
LABEL_59:
        if ( rsvp_nxt_locked )
        {
          v53 = rsvp_nxt_locked;
          printk(&unk_257266, "sde_rm_reserve");
          if ( j )
            v72 = *(_DWORD *)(j + 16);
          else
            v72 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_rm_reserve",
            3103,
            -1,
            *(_DWORD *)(v5 + 24),
            v72,
            *((_DWORD *)v53 + 4),
            60333,
            239);
          LODWORD(v53) = -11;
          goto LABEL_441;
        }
      }
      else if ( i && (v154 & 1) == 0 )
      {
        goto LABEL_378;
      }
      break;
    }
  }
  v30 = a4[176];
  v31 = v9[19];
  v32 = *v6;
  v175 = v27;
  *(_QWORD *)v163 = v30;
  sde_encoder_get_hw_resources(v5, (__int64)&v165, (__int64)a4);
  v33 = *(_QWORD *)(a1 + 328);
  for ( k = 0; k != 476; k += 28 )
  {
    if ( *(_DWORD *)(v33 + k + 4) == (_DWORD)v174
      && *(_QWORD *)(v33 + k + 8) == *(_QWORD *)((char *)&v174 + 4)
      && *(_DWORD *)(v33 + k + 24) == HIDWORD(v174) )
    {
      v35 = (_DWORD *)(v33 + k);
      v164 = v35;
      goto LABEL_67;
    }
  }
  v35 = v164;
LABEL_67:
  if ( !v35 )
  {
    printk(&unk_242F02, "_sde_rm_populate_requirements");
    printk(&unk_25AF92, "sde_rm_reserve");
    LODWORD(v53) = -22;
    goto LABEL_441;
  }
  if ( *(_DWORD *)(*a4 + 156) == 16 )
  {
    v36 = v163[0];
    if ( (v163[0] & 4) == 0 )
    {
      v36 = LOBYTE(v163[0]) | 4;
      *(_QWORD *)v163 |= 4uLL;
    }
    if ( (v36 & 8) == 0
      && *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 264) + 40LL) + 60LL) == 1
      && sde_encoder_is_primary_display(v5) )
    {
      *(_QWORD *)v163 |= 8uLL;
    }
  }
  v37 = v6[41];
  if ( v37 && *v6 )
    v38 = *(_QWORD **)(*(_QWORD *)(v37 + 32) + 56LL * *(unsigned int *)(*v6 + 160) + 16);
  else
    v38 = nullptr;
  BYTE4(v176) = sde_crtc_in_lb_transition(v38, (__int64)v6) & 1;
  if ( (sde_crtc_state_in_lb_mode(v6) & 1) != 0 )
  {
    if ( (*(_BYTE *)(v5 + 644) & 0x80) != 0 )
    {
      v40 = *(_QWORD *)v163 | 4LL;
      if ( (v163[0] & 8) == 0 && *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 264) + 40LL) + 60LL) )
        v40 = *(_QWORD *)v163 | 0xCLL;
      v39 = v40 | 0x200;
    }
    else
    {
      v39 = *(_QWORD *)v163 & 0xFFFFFFFFFFFFFEF3LL | 0x100;
    }
    *(_QWORD *)v163 = v39;
  }
  else
  {
    LODWORD(v39) = v163[0];
  }
  if ( (~(_DWORD)v39 & 0x30LL) != 0
    && ((((__int64 (__fastcall *)(__int64))sde_encoder_in_clone_mode)(v5) & 1) != 0
     || ((*((_DWORD *)v6 + 453) >> *(_DWORD *)(v5 + 68)) & 1) != 0) )
  {
    v41 = 32;
    v42 = *v6;
    v43 = *a4;
    if ( (*(_QWORD *)(v31 + 22008) & 0x40LL) == 0 )
      v41 = 16;
    v44 = *(_QWORD *)(a1 + 328) + 168LL;
    *(_QWORD *)v163 |= v41;
    v164 = (_DWORD *)v44;
    num_datapath = sde_crtc_get_num_datapath(v42, v43, (__int64)v6);
    if ( num_datapath == 1 )
    {
      v164 = (_DWORD *)(*(_QWORD *)(a1 + 328) + 28LL);
    }
    else if ( !num_datapath )
    {
      printk(&unk_238768, "_sde_rm_populate_requirements");
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_rm_populate_requirements",
      2672,
      -1,
      num_datapath,
      v164[1],
      *v164,
      v164[4],
      239);
  }
  if ( (v163[0] & 0x20) != 0 )
  {
    v46 = *(__int64 **)(*(_QWORD *)v5 + 816LL);
    v47 = *(_QWORD *)v5 + 816LL;
    if ( v46 != (__int64 *)v47 )
    {
      while ( 1 )
      {
        v48 = 1 << *((_DWORD *)v46 + 15);
        if ( (v48 & *((_DWORD *)v6 + 5)) != 0 && v48 != 1 << *(_DWORD *)(v5 + 68) )
          break;
        v46 = (__int64 *)*v46;
        if ( v46 == (__int64 *)v47 )
          goto LABEL_110;
      }
      v191 = 0;
      v192 = 0;
      v50 = *(v46 - 1);
      v49 = v46 - 1;
      drm_connector_list_iter_begin(v50, &v191);
      while ( 1 )
      {
        v51 = drm_connector_list_iter_next(&v191);
        if ( !v51 )
          break;
        if ( *(__int64 **)(v51 + 2744) == v49 )
        {
          v52 = v51;
          drm_connector_list_iter_end(&v191);
          LODWORD(v176) = *(_DWORD *)(v52 + 4668);
          goto LABEL_110;
        }
      }
      drm_connector_list_iter_end(&v191);
    }
LABEL_110:
    if ( v32 )
    {
      if ( *(_DWORD *)(*a4 + 156) == 15 && v164[1] == 1 )
      {
        v54 = *(_QWORD *)(v32 + 2200);
        if ( v54 )
        {
          v55 = *(_DWORD *)(v54 + 32);
          v56 = 1 << (v55 - 1);
          if ( !v55 )
            v56 = 0;
          LODWORD(v176) = v56 | v176;
        }
      }
    }
  }
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "top_ctrl: 0x%llX num_h_tiles: %d\n", *(_QWORD *)v163, v173);
    v57 = v164;
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_121;
    _drm_dev_dbg(
      0,
      0,
      0,
      "num_lm: %d num_ctl: %d topology: %d split_display: %d mask: 0x%X\n",
      v164[1],
      v164[4],
      *v164,
      *((unsigned __int8 *)v164 + 20),
      v176);
  }
  v57 = v164;
LABEL_121:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_rm_populate_requirements",
    2704,
    -1,
    *((unsigned __int16 *)v6 + 74),
    *(_DWORD *)(a1 + 272),
    v57[1],
    v163[0],
    *v57);
  i = _kmalloc_cache_noprof(wake_up_process, 3520, 32);
  if ( !i )
  {
    LODWORD(v53) = -12;
    goto LABEL_441;
  }
  if ( j && (v154 & 1) != 0 && (v163[0] & 2) != 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "test_only & CLEAR: clear rsvp[s%de%d]\n", *(_DWORD *)(j + 16), *(_DWORD *)(j + 20));
    sde_rm_release_rsvp(a1, j);
    sde_rm_print_rsvps(a1, 1);
    j = 0;
  }
  v58 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v5 + 56LL) + 8LL);
  v59 = *(int **)(v58 + 2720);
  v60 = (unsigned __int8 *)(v58 + 2712);
  if ( v59 == (int *)v5 )
  {
    v61 = (_BYTE *)(v58 + 2712);
  }
  else
  {
    if ( *(_QWORD *)(v58 + 2800) != v5 )
    {
LABEL_141:
      v65 = nullptr;
      goto LABEL_142;
    }
    v61 = (_BYTE *)(v58 + 2792);
  }
  if ( *v61 != 1 )
    goto LABEL_141;
  v62 = *(int **)(v58 + 2800);
  v63 = (unsigned __int8 *)(v58 + 2792);
  if ( v59 == (int *)v5 )
    v64 = v60;
  else
    v64 = nullptr;
  if ( v62 == (int *)v5 )
    v65 = v63;
  else
    v65 = v64;
  if ( !v65 )
  {
    printk(&unk_220E9D, "_sde_rm_make_next_rsvp");
LABEL_433:
    v100 = -22;
    goto LABEL_434;
  }
LABEL_142:
  v66 = v164;
  v67 = *(__int64 **)(a1 + 16);
  v68 = *(_DWORD *)(a1 + 276) + 1;
  *(_DWORD *)(a1 + 276) = v68;
  v69 = *(_DWORD *)(v5 + 24);
  *(_DWORD *)(i + 16) = v68;
  *(_DWORD *)(i + 20) = v69;
  v70 = *v66;
  *(_BYTE *)(i + 28) = 1;
  *(_DWORD *)(i + 24) = v70;
  if ( v26 != (__int64 *)i && v67 != (__int64 *)i && (__int64 *)*v67 == v26 )
  {
    *(_QWORD *)(a1 + 16) = i;
    *(_QWORD *)i = v26;
    *(_QWORD *)(i + 8) = v67;
    *v67 = i;
    if ( v65 )
      goto LABEL_146;
LABEL_168:
    v6 = nullptr;
    goto LABEL_169;
  }
  _list_add_valid_or_report(i, v67);
  if ( !v65 )
    goto LABEL_168;
LABEL_146:
  v71 = v65[73];
  if ( v65[73] )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "splash_display->lm_ids[%d] = %d\n", 0, v65[36]);
      v71 = v65[73];
    }
    if ( v71 >= 2 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "splash_display->lm_ids[%d] = %d\n", 1, v65[37]);
        v71 = v65[73];
      }
      if ( v71 >= 3 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "splash_display->lm_ids[%d] = %d\n", 2, v65[38]);
          v71 = v65[73];
        }
        if ( v71 >= 4 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "splash_display->lm_ids[%d] = %d\n", 3, v65[39]);
            v71 = v65[73];
          }
          if ( v71 >= 5 && (_drm_debug & 4) != 0 )
            goto LABEL_337;
        }
      }
    }
  }
  v6 = (__int64 *)(v65 + 36);
  if ( v164[1] != v71 && (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "Configured splash LMs != needed LM cnt\n");
LABEL_169:
  v201 = 0;
  v202 = 0;
  v199 = 0;
  v200 = 0;
  v197 = 0;
  v198 = 0;
  v195 = 0;
  v196 = 0;
  v193 = 0;
  v194 = 0;
  v191 = 0;
  v192 = 0;
  v189 = 0;
  v190 = 0;
  v187 = 0;
  v188 = 0;
  v185 = 0;
  v186 = 0;
  v183 = 0;
  v184 = 0;
  v181 = 0;
  v182 = 0;
  v179 = 0;
  v180 = 0;
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v157 = 0;
  v158 = 0;
  v73 = v164[1];
  memset(v178, 0, sizeof(v178));
  memset(v177, 0, sizeof(v177));
  if ( !v73 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid number of lm: %d\n", 0);
    goto LABEL_241;
  }
  v27 = nullptr;
  v5 = 0;
  v9 = v178;
  if ( (v163[0] & 0x20) != 0 )
    v74 = v176;
  else
    v74 = 0;
  v160 = 0;
  v161 = 0;
  v162 = 0x200000000LL;
  v155 = v74;
  while ( 1 )
  {
    v75 = (int)v5;
    while ( 1 )
    {
      if ( (sde_rm_get_hw_locked(a1, (__int64)&v160, 1) & 1) == 0 )
      {
        v76 = v164;
        goto LABEL_219;
      }
      v77 = v161;
      v78 = *(_DWORD *)(v161 + 36);
      if ( (((unsigned int)v27 >> v78) & 1) == 0 )
      {
        if ( (unsigned int)v5 >= 0xC )
          goto LABEL_337;
        if ( v75 > 12 )
        {
LABEL_438:
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v151 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &sde_rm_reserve__alloc_tag;
          v14 = _kmalloc_cache_noprof(_wake_up, 3520, 688);
          *(_QWORD *)(StatusReg + 80) = v151;
          if ( !v14 )
            goto LABEL_439;
          goto LABEL_17;
        }
        *(&v191 + (int)v5) = v161;
        *(&v179 + (int)v5) = 0;
        v178[(int)v5] = 0;
        v177[(int)v5] = 0;
        if ( (_drm_debug & 4) != 0 )
        {
          if ( v6 )
            v79 = *((unsigned __int8 *)v6 + (int)v5);
          else
            v79 = -1;
          _drm_dev_dbg(0, 0, 0, "blk id = %d, _lm_ids[%d] = %d\n", v78, v5, v79);
          v77 = *(&v191 + (int)v5);
        }
        if ( !v6 || *(_DWORD *)(v77 + 36) == *((unsigned __int8 *)v6 + (int)v5) )
        {
          v152 = v155;
          if ( (sde_rm_check_lm_and_get_connected_blks(
                  a1,
                  i,
                  v163,
                  v77,
                  (char *)&v179 + v75 * 8,
                  &v178[v75],
                  &v177[v75],
                  0)
              & 1) != 0 )
            break;
        }
      }
      v76 = v164;
      if ( (_DWORD)v5 == v164[1] )
        goto LABEL_219;
    }
    v76 = v164;
    v80 = (unsigned int)v5 + 1LL;
    if ( (_DWORD)v80 == v164[1] )
      break;
    if ( (v163[0] & 0x20) != 0 )
    {
      v81 = __clz(__rbit32(v155));
      if ( !v155 )
        v81 = -1;
      v155 &= ~(unsigned int)(1LL << v81);
    }
    v157 = 0;
    v158 = 0;
    v27 = (_QWORD *)((1 << *(_DWORD *)(v161 + 36)) | (unsigned int)v27);
    v159 = 0x200000000LL;
    if ( (sde_rm_get_hw_locked(a1, (__int64)&v157, 1) & 1) != 0 )
    {
      while ( 1 )
      {
        v82 = v158;
        if ( (((unsigned int)v27 >> *(_DWORD *)(v158 + 36)) & 1) == 0 )
        {
          if ( (_DWORD)v5 == 11 )
            goto LABEL_337;
          *(&v191 + v80) = v158;
          v83 = v161;
          *(&v179 + v80) = 0;
          v178[v80] = 0;
          v9 = v178;
          v177[v80] = 0;
          v152 = v155;
          if ( (sde_rm_check_lm_and_get_connected_blks(a1, i, v163, v82, &v179 + v80, &v178[v80], &v177[v80], v83) & 1) != 0 )
          {
            if ( (_drm_debug & 4) != 0 )
            {
              if ( v6 )
                v84 = *((unsigned __int8 *)v6 + v80);
              else
                v84 = -1;
              _drm_dev_dbg(0, 0, 0, "blk id = %d, _lm_ids[%d] = %d\n", *(_DWORD *)(v158 + 36), v80, v84);
            }
            if ( !v6 || *(_DWORD *)(*(&v191 + v80) + 36) == *((unsigned __int8 *)v6 + v80) )
              break;
          }
        }
        if ( (sde_rm_get_hw_locked(a1, (__int64)&v157, 1) & 1) == 0 )
          goto LABEL_211;
      }
      LODWORD(v80) = v5 + 2;
      v27 = (_QWORD *)((1 << *(_DWORD *)(v158 + 36)) | (unsigned int)v27);
      if ( (v163[0] & 0x20) != 0 )
      {
        v85 = __clz(__rbit32(v155));
        if ( !v155 )
          v85 = -1;
        v155 &= ~(unsigned int)(1LL << v85);
      }
    }
LABEL_211:
    if ( v157 )
    {
      v5 = (unsigned int)v80;
    }
    else
    {
      v5 = (unsigned int)(v80 - 1);
      v27 = (_QWORD *)((unsigned int)v27 & ~(1 << *(_DWORD *)(v161 + 36)));
    }
    v76 = v164;
    if ( (_DWORD)v5 == v164[1] )
      goto LABEL_219;
  }
  LODWORD(v5) = v5 + 1;
LABEL_219:
  if ( (_DWORD)v5 != v76[1] )
  {
    v27 = v156;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "unable to find appropriate mixers\n");
LABEL_414:
    printk(&unk_25B022, "_sde_rm_make_next_rsvp");
    v141 = *(__int64 **)(a1 + 56);
    if ( v141 == (__int64 *)(a1 + 56) )
      goto LABEL_415;
    while ( !v141[2] )
    {
      v144 = v141 + 3;
      if ( v141[3] )
        goto LABEL_424;
LABEL_419:
      v141 = (__int64 *)*v141;
      if ( v141 == (__int64 *)(a1 + 56) )
      {
        v27 = v156;
        v100 = -119;
        goto LABEL_434;
      }
    }
    v144 = v141 + 3;
LABEL_424:
    printk(&unk_24965C, "_sde_rm_print_rsvps_by_type");
    v145 = v141[2];
    if ( v145 )
    {
      v146 = *(_DWORD *)(v145 + 16);
      v147 = *(_DWORD *)(v145 + 20);
    }
    else
    {
      v146 = 0;
      v147 = 0;
    }
    v148 = *v144;
    if ( *v144 )
    {
      v142 = *(_DWORD *)(v148 + 16);
      v143 = *(_DWORD *)(v148 + 20);
    }
    else
    {
      v142 = 0;
      v143 = 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_rm_print_rsvps_by_type",
      444,
      -1,
      v146,
      v147,
      v142,
      v143,
      *((_DWORD *)v141 + 8));
    goto LABEL_419;
  }
  if ( (int)v5 >= 1 )
  {
    v86 = 0;
    v6 = v177;
    v27 = v178;
    do
    {
      if ( v86 == 12 )
        goto LABEL_337;
      v88 = *(__int64 *)((char *)&v191 + v86 * 8);
      *(_QWORD *)(v88 + 24) = i;
      v89 = v177[v86];
      *(_QWORD *)(v89 + 24) = i;
      v90 = *(__int64 *)((char *)&v179 + v86 * 8);
      if ( v90 )
        *(_QWORD *)(v90 + 24) = i;
      v91 = v178[v86];
      if ( v91 )
        *(_QWORD *)(v91 + 24) = i;
      v92 = *(_DWORD *)(v88 + 32);
      v93 = *(_DWORD *)(v88 + 36);
      if ( v90 )
        v87 = *(_DWORD *)(v90 + 36);
      else
        LOBYTE(v87) = 0;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_rm_reserve_lms",
        1528,
        -1,
        v92,
        *(_DWORD *)(i + 20),
        v93,
        *(_DWORD *)(v89 + 36),
        v87);
      ++v86;
    }
    while ( (unsigned int)v5 != v86 );
    v76 = v164;
  }
  v27 = v156;
  if ( *v76 == 10 )
  {
    v160 = 0;
    v161 = 0;
    v162 = 0x700000000LL;
    while ( 1 )
    {
      if ( (sde_rm_get_hw_locked(a1, (__int64)&v160, 1) & 1) == 0 )
        goto LABEL_414;
      if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v161 + 40) + 40LL) + 32LL) & 0x10) != 0 )
      {
        v94 = *(_QWORD *)(v161 + 16);
        if ( !v94 || *(_DWORD *)(v94 + 20) == *(_DWORD *)(i + 20) )
        {
          v95 = *(_QWORD *)(v161 + 24);
          if ( !v95 || *(_DWORD *)(v95 + 20) == *(_DWORD *)(i + 20) )
            break;
        }
      }
    }
    *(_QWORD *)(v161 + 24) = i;
  }
LABEL_241:
  LODWORD(v194) = 0;
  v192 = 0;
  v193 = 0;
  v191 = 0;
  if ( v65 )
  {
    v96 = v65[72];
    v97 = v65 + 32;
    if ( v65[72] )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "splash_display->ctl_ids[%d] = %d\n", 0, v65[32]);
        v96 = v65[72];
      }
      if ( v96 >= 2 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "splash_display->ctl_ids[%d] = %d\n", 1, v65[33]);
          v96 = v65[72];
        }
        if ( v96 >= 3 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            _drm_dev_dbg(0, 0, 0, "splash_display->ctl_ids[%d] = %d\n", 2, v65[34]);
            v96 = v65[72];
          }
          if ( v96 >= 4 )
          {
            if ( (_drm_debug & 4) != 0 )
            {
              _drm_dev_dbg(0, 0, 0, "splash_display->ctl_ids[%d] = %d\n", 3, v65[35]);
              v96 = v65[72];
            }
            if ( v96 >= 5 && (_drm_debug & 4) != 0 )
              goto LABEL_337;
          }
        }
      }
    }
  }
  else
  {
    v97 = nullptr;
  }
  v98 = sde_rm_reserve_ctls(a1, i, v163, v164, v97);
  if ( v98 )
  {
    if ( (v164[5] & 1) != 0
      || (int)v164[4] <= 1
      || (v193 = *((_QWORD *)v164 + 2),
          v191 = *(_QWORD *)v164,
          v192 = *((_QWORD *)v164 + 1),
          v99 = v164[6],
          BYTE4(v193) = 1,
          LODWORD(v194) = v99,
          (v98 = sde_rm_reserve_ctls(a1, i, v163, &v191, v97)) != 0) )
    {
      v107 = v98;
      printk(&unk_22780E, "_sde_rm_make_next_rsvp");
      v100 = v107;
LABEL_434:
      v149 = v100;
      sde_rm_print_rsvps(a1, 2);
      LODWORD(v53) = v149;
      printk(&unk_242EB7, "sde_rm_reserve");
      sde_rm_release_rsvp(a1, i);
      goto LABEL_441;
    }
  }
  if ( (_DWORD)v165 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 1, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v165) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 2, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v166 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 3, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v166) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 4, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v167 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 5, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v167) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 6, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v168 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 7, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v168) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 8, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v169 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 9, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v169) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 10, 8, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v170 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 1, 9, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v170) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 2, 9, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v171 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 3, 9, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( HIDWORD(v171) )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 4, 9, v163);
    if ( v100 )
      goto LABEL_434;
  }
  if ( (_DWORD)v172 )
  {
    v100 = sde_rm_reserve_intf_or_wb(a1, i, 5, 9, v163);
    if ( v100 )
      goto LABEL_434;
  }
  LODWORD(v179) = 0;
  if ( v65 )
  {
    v101 = v65 + 40;
    if ( v65[74] )
    {
      *((_DWORD *)v175 + 1) = 1;
      v102 = v65[74];
      if ( v65[74] )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "splash_data.dsc_ids[%d] = %d\n", 0, v65[40]);
          v102 = v65[74];
          v101 = v65 + 40;
        }
        if ( v102 >= 2 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            v103 = v101;
            _drm_dev_dbg(0, 0, 0, "splash_data.dsc_ids[%d] = %d\n", 1, v65[41]);
            v102 = v65[74];
            v101 = v103;
          }
          if ( v102 >= 3 )
          {
            if ( (_drm_debug & 4) != 0 )
            {
              v104 = v101;
              _drm_dev_dbg(0, 0, 0, "splash_data.dsc_ids[%d] = %d\n", 2, v65[42]);
              v102 = v65[74];
              v101 = v104;
            }
            if ( v102 >= 4 )
            {
              if ( (_drm_debug & 4) != 0 )
              {
                v105 = v101;
                _drm_dev_dbg(0, 0, 0, "splash_data.dsc_ids[%d] = %d\n", 3, v65[43]);
                v102 = v65[74];
                v101 = v105;
              }
              if ( v102 >= 5 && (_drm_debug & 4) != 0 )
              {
LABEL_337:
                __break(0x5512u);
                goto LABEL_338;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v5 = 0;
    v9 = nullptr;
    v192 = 0;
    v193 = 0xA00000000LL;
    v191 = 0;
    while ( (sde_rm_get_hw_locked(a1, (__int64)&v191, 1) & 1) != 0 )
    {
      v106 = *(_QWORD *)(v192 + 16);
      if ( v106 && *(_DWORD *)(v106 + 20) == *(_DWORD *)(i + 20) )
      {
        if ( (unsigned __int64)v9 > 3 )
          goto LABEL_438;
        *((_BYTE *)&v179 + (_QWORD)v9) = *(_DWORD *)(v192 + 36);
        v9 = (_QWORD *)((char *)v9 + 1);
      }
      if ( (int)v9 >= 4 )
        goto LABEL_319;
    }
    if ( v9 )
    {
      v100 = sde_rm_reserve_dsc(a1, i, v163, &v179);
      v65 = nullptr;
      goto LABEL_321;
    }
LABEL_319:
    v101 = nullptr;
    v65 = nullptr;
  }
  v100 = sde_rm_reserve_dsc(a1, i, v163, v101);
LABEL_321:
  if ( v100 )
    goto LABEL_434;
  if ( v65 )
  {
    v108 = v65[75];
    v109 = v65 + 44;
    if ( !v65[75] )
      goto LABEL_339;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "splash_data.vdc_ids[%d] = %d\n", 0, v65[44]);
      v108 = v65[75];
    }
    if ( v108 < 2 )
      goto LABEL_339;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "splash_data.vdc_ids[%d] = %d\n", 1, v65[45]);
      v108 = v65[75];
    }
    if ( v108 < 3 )
      goto LABEL_339;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "splash_data.vdc_ids[%d] = %d\n", 2, v65[46]);
      v108 = v65[75];
    }
    if ( v108 < 4 )
      goto LABEL_339;
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "splash_data.vdc_ids[%d] = %d\n", 3, v65[47]);
      v108 = v65[75];
    }
    if ( v108 < 5 || (_drm_debug & 4) == 0 )
      goto LABEL_339;
    goto LABEL_337;
  }
LABEL_338:
  v109 = nullptr;
LABEL_339:
  v110 = v164[2];
  if ( !v110 || *((_DWORD *)v175 + 1) != 2 )
    goto LABEL_360;
  v179 = 0;
  v180 = 0;
  v181 = 0xB00000000LL;
  do
  {
    while ( 1 )
    {
      do
      {
        if ( (sde_rm_get_hw_locked(a1, (__int64)&v179, 1) & 1) == 0 )
        {
          printk(&unk_2387B5, "_sde_rm_reserve_vdc");
          goto LABEL_433;
        }
        v111 = v180;
        v201 = 0;
        v202 = 0;
        v199 = 0;
        v200 = 0;
        v197 = 0;
        v198 = 0;
        v195 = 0;
        v196 = 0;
        v193 = 0;
        v194 = 0;
        v191 = 0;
        v192 = 0;
      }
      while ( v109 && *(_DWORD *)(v180 + 36) != *v109 );
      v112 = *(_QWORD *)(v180 + 16);
      if ( !v112 || *(_DWORD *)(v112 + 20) == *(_DWORD *)(i + 20) )
      {
        v113 = *(_QWORD *)(v180 + 24);
        if ( !v113 || *(_DWORD *)(v113 + 20) == *(_DWORD *)(i + 20) )
          break;
      }
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "vdc %d already reserved\n",
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v180 + 40) + 40LL) + 16LL));
    }
    if ( (_drm_debug & 4) != 0 )
    {
      if ( v109 )
        v114 = *v109;
      else
        v114 = -1;
      _drm_dev_dbg(0, 0, 0, "blk id = %d, _vdc_ids[%d] = %d\n", *(_DWORD *)(v180 + 36), 0, v114);
      v111 = v180;
    }
    v191 = v111;
  }
  while ( v110 != 1 );
  for ( m = 0; m != 96; m += 8 )
  {
    v116 = *(__int64 *)((char *)&v191 + m);
    if ( !v116 )
      break;
    *(_QWORD *)(v116 + 24) = i;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_rm_reserve_vdc",
      1946,
      -1,
      *(_DWORD *)(v116 + 32),
      *(_DWORD *)(i + 20),
      *(_DWORD *)(v116 + 36),
      -1059143953,
      v152);
  }
LABEL_360:
  v117 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 56LL) + 8LL);
  if ( !v117 )
  {
    printk(&unk_234896, "_sde_rm_reserve_qdss");
    goto LABEL_433;
  }
  v191 = 0;
  v192 = 0;
  v193 = 0xD00000000LL;
  while ( (sde_rm_get_hw_locked(a1, (__int64)&v191, 1) & 1) != 0 )
  {
    v118 = v192;
    v119 = *(_QWORD *)(v192 + 16);
    if ( !v119 || *(_DWORD *)(v119 + 20) == *(_DWORD *)(i + 20) )
    {
      v120 = *(_QWORD *)(v192 + 24);
      if ( !v120 || *(_DWORD *)(v120 + 20) == *(_DWORD *)(i + 20) )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "blk id = %d\n", *(_DWORD *)(v192 + 36));
          v118 = v192;
        }
        *(_QWORD *)(v118 + 24) = i;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_rm_reserve_qdss",
          1977,
          -1,
          *(_DWORD *)(v118 + 32),
          *(_DWORD *)(i + 20),
          *(_DWORD *)(v118 + 36),
          -1059143953,
          v152);
        goto LABEL_372;
      }
    }
  }
  if ( !v191 && *(_DWORD *)(*(_QWORD *)(v117 + 152) + 19288LL) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "couldn't reserve qdss for type %d id %d\n", 13, *(_DWORD *)(v192 + 36));
LABEL_415:
    v100 = -119;
    goto LABEL_434;
  }
LABEL_372:
  sde_rm_print_rsvps(a1, 2);
  if ( (v154 & 1) != 0 )
  {
    if ( (v163[0] & 1) == 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "test_only: rsvp[s%de%d]\n", *(_DWORD *)(i + 16), *(_DWORD *)(i + 20));
      goto LABEL_411;
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "test_only & LOCK: lock rsvp[s%de%d]\n", *(_DWORD *)(i + 16), *(_DWORD *)(i + 20));
  }
LABEL_378:
  sde_rm_release_rsvp(a1, j);
  v122 = 0;
  while ( 2 )
  {
    v123 = (__int64 **)(a1 + 24 + 16 * v122);
    v124 = *v123;
    while ( v124 != (__int64 *)v123 )
    {
      v125 = v124[3];
      if ( !v125 || *(_DWORD *)(a4[2] + 24) != *(_DWORD *)(v125 + 20) )
        goto LABEL_382;
      v126 = *((_DWORD *)v124 + 8);
      v124[2] = v125;
      v124[3] = 0;
      if ( v126 > 9 )
      {
        if ( v126 == 10 )
        {
          --*(_DWORD *)(a1 + 344);
LABEL_382:
          v124 = (__int64 *)*v124;
          continue;
        }
        if ( v126 != 11 )
          goto LABEL_382;
        --*(_DWORD *)(a1 + 348);
        v124 = (__int64 *)*v124;
      }
      else if ( v126 == 2 )
      {
        v127 = *(_QWORD *)(v124[5] + 40);
        if ( (*(_BYTE *)(v127 + 72) & 1) != 0 )
          goto LABEL_382;
        --*(_DWORD *)(a1 + 340);
        v128 = *(unsigned int *)(v127 + 68);
        v129 = v128 >> 6;
        v130 = 1LL << v128;
        _X9 = (unsigned __int64 *)(a1 + 368 + 8 * v129);
        __asm { PRFM            #0x11, [X9] }
        do
          v137 = __ldxr(_X9);
        while ( __stxr(v137 & ~v130, _X9) );
        *(_DWORD *)(a1 + 356) = _sw_hweight64(*(_QWORD *)(a1 + 368));
        v124 = (__int64 *)*v124;
      }
      else
      {
        if ( v126 != 5 )
          goto LABEL_382;
        --*(_DWORD *)(a1 + 352);
        v124 = (__int64 *)*v124;
      }
    }
    if ( ++v122 != 15 )
      continue;
    break;
  }
  *(_BYTE *)(i + 28) = 0;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "rsrv enc %d topology %d\n", *(_DWORD *)(i + 20), *(_DWORD *)(i + 24));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_rm_commit_rsvp",
    2972,
    -1,
    *(_DWORD *)(i + 20),
    *(_DWORD *)(i + 24),
    -1059143953,
    v121,
    v152);
  v53 = (_QWORD *)*a4;
  if ( *a4 )
  {
    if ( *((_DWORD *)v53 + 39) == 10 )
    {
      v138 = v53[343];
      if ( v138 )
      {
        for ( n = *(__int64 **)(a1 + 56); n != (__int64 *)(a1 + 56); n = (__int64 *)*n )
        {
          v140 = n[2];
          if ( v140 && *(_DWORD *)(v140 + 20) == *(_DWORD *)(v138 + 24) )
            *((_DWORD *)v53 + 1167) |= 1LL << ((unsigned __int8)*((_DWORD *)n + 9) - 1);
        }
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(
            0,
            0,
            0,
            "conn lm_mask %d for conn %d enc %d\n",
            *((_DWORD *)v53 + 1167),
            *((_DWORD *)v53 + 16),
            *(_DWORD *)(v138 + 24));
          v138 = v53[343];
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_rm_populate_dp_lm_mask",
          3001,
          -1,
          *(_DWORD *)(v138 + 24),
          *((_DWORD *)v53 + 16),
          *((_DWORD *)v53 + 1167),
          -1059143953,
          v153);
      }
    }
LABEL_411:
    LODWORD(v53) = 0;
  }
  else
  {
    printk(&unk_26FEB0, "_sde_rm_populate_dp_lm_mask");
  }
LABEL_441:
  kfree(v27);
  sde_rm_print_rsvps(a1, 3);
  mutex_unlock(a1 + 280);
  result = (unsigned int)v53;
LABEL_442:
  _ReadStatusReg(SP_EL0);
  return result;
}
