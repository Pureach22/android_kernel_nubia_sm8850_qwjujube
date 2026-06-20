__int64 __fastcall sde_crtc_atomic_check(__int64 a1, __int64 a2)
{
  __int64 v3; // x28
  int v4; // w5
  __int64 v5; // x23
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x25
  unsigned __int64 v9; // x24
  __int64 i; // x0
  __int64 v11; // x8
  _QWORD *v13; // x8
  __int64 v14; // x0
  char v15; // w20
  bool v16; // w8
  int v17; // w9
  int v18; // w9
  __int64 v19; // x20
  int lm_cnt_from_topology; // w0
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x13
  __int64 *v25; // x10
  unsigned int v26; // w11
  __int64 v27; // x14
  _DWORD *v28; // x14
  unsigned int v29; // w13
  __int64 v30; // x13
  unsigned int v31; // w15
  unsigned int v32; // w13
  __int64 v33; // x13
  unsigned int v34; // w14
  int v35; // w0
  __int64 v36; // x8
  __int64 v37; // x20
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 *v40; // x20
  __int64 *v41; // x9
  int v42; // w21
  __int64 *v43; // x11
  __int64 v44; // x12
  _DWORD *v45; // x12
  int v46; // w12
  __int64 v47; // x9
  __int64 v48; // x25
  __int64 v49; // x26
  int v50; // w5
  unsigned int v51; // w24
  int v52; // w8
  int v53; // w10
  int v54; // w9
  int v55; // w4
  unsigned int v56; // w8
  bool v57; // cf
  unsigned int v58; // w8
  __int64 v59; // x9
  __int64 v60; // x9
  __int64 v61; // x8
  __int64 v62; // x12
  __int64 v63; // x12
  __int64 v64; // x8
  __int64 v65; // x20
  __int64 v66; // x8
  __int64 v67; // x9
  __int64 *v68; // x26
  __int64 v69; // x23
  int v70; // w27
  __int64 v71; // kr00_8
  __int64 j; // x20
  _DWORD *v73; // x25
  unsigned __int64 v74; // x20
  __int64 v75; // x8
  __int64 resolution; // x0
  int v77; // w11
  unsigned int v78; // w8
  unsigned int v79; // w12
  unsigned int v80; // w8
  unsigned int v81; // w12
  unsigned int v82; // w8
  unsigned int v83; // w12
  unsigned int v84; // w8
  unsigned int v85; // w12
  unsigned int v86; // w8
  unsigned int v87; // w12
  unsigned int v88; // w8
  unsigned int v89; // w12
  unsigned int v90; // w8
  unsigned int v91; // w12
  __int64 v92; // x21
  char v93; // w8
  __int64 v94; // x8
  int v95; // w4
  __int64 v96; // x9
  __int64 v97; // x10
  int v98; // w12
  int v99; // w13
  unsigned __int64 v100; // x20
  int v101; // w27
  int v102; // w25
  int v103; // w24
  int v104; // w9
  char v105; // w8
  int v106; // w10
  void *v107; // x0
  __int64 v108; // x8
  __int64 v109; // x26
  int plane_fb_modes; // w0
  int v111; // w4
  int v112; // w24
  int v113; // w21
  int v114; // w25
  __int64 v115; // x20
  int v116; // w28
  _QWORD *v117; // x8
  unsigned int v118; // w5
  int v119; // w7
  __int64 v120; // x9
  int v121; // w8
  _DWORD *v122; // x10
  void *v123; // x0
  void *v124; // x0
  void *v125; // x0
  void *v126; // x0
  void *v127; // x0
  const char *v128; // x1
  void *v129; // x0
  __int64 v130; // x10
  __int64 v131; // x8
  _QWORD *v132; // x10
  char v133; // w9
  char v134; // w11
  __int64 v135; // x12
  __int64 v136; // x8
  __int64 v137; // x27
  __int64 *v138; // x20
  __int64 v139; // x9
  int v140; // w4
  __int64 *v141; // x11
  char v142; // w12
  int v143; // w27
  int v144; // w25
  int v145; // w21
  char v146; // w9
  int v147; // w7
  int v148; // w7
  __int64 v149; // x9
  __int64 v150; // x8
  unsigned __int64 *v151; // x8
  __int64 v152; // t1
  __int64 v153; // x21
  unsigned __int64 v154; // x28
  unsigned __int64 v155; // x9
  __int64 v156; // x23
  unsigned int v157; // w0
  __int64 v158; // x8
  int v159; // w9
  int v160; // w5
  __int64 v161; // x9
  unsigned __int64 v162; // x10
  _QWORD *v163; // x11
  unsigned __int64 v164; // x9
  unsigned int v165; // w4
  unsigned int v166; // w5
  unsigned int v167; // w8
  unsigned int v168; // w9
  unsigned int v169; // w8
  __int64 v170; // x8
  unsigned int v171; // w4
  unsigned int v172; // w7
  unsigned int v173; // w4
  unsigned int v174; // w8
  unsigned int v175; // w8
  void *v176; // x0
  void *v177; // x0
  __int64 v178; // x8
  __int64 v179; // x8
  __int64 v180; // x14
  unsigned __int64 v181; // x15
  __int64 v182; // x9
  __int64 v183; // x8
  unsigned __int16 *v184; // x11
  unsigned __int16 *v185; // x10
  int v186; // w5
  int v187; // w20
  unsigned int v188; // w2
  unsigned int v189; // w4
  int v190; // w6
  int v191; // w7
  int v192; // w0
  int v193; // w11
  int v194; // w1
  int v195; // w8
  int v196; // w10
  unsigned int v197; // w12
  int v198; // w13
  int v199; // w0
  int v200; // w14
  void *v201; // x27
  __int64 v202; // x9
  __int64 v203; // x8
  _QWORD *v204; // x9
  __int64 v205; // x12
  int v206; // w12
  _DWORD *v207; // x26
  __int64 v208; // x23
  void *v209; // x0
  void *v210; // x0
  const char *v211; // x1
  __int64 v212; // x20
  __int64 v213; // x0
  __int64 v214; // x8
  unsigned int v215; // w8
  __int64 v216; // x8
  __int64 v217; // x20
  __int64 v218; // x8
  __int64 v219; // x26
  __int64 v220; // x27
  __int64 v221; // x9
  __int64 v222; // x21
  _QWORD *v223; // x24
  __int64 v224; // x25
  unsigned int v225; // w0
  __int64 v226; // x28
  int v227; // w8
  _DWORD *v228; // x0
  bool v229; // zf
  bool v231; // zf
  int v232; // w5
  int v233; // w6
  int v234; // w7
  __int16 v235; // w8
  __int64 v236; // x9
  __int64 v237; // x8
  _QWORD *v238; // x9
  __int64 v239; // x10
  __int64 v240; // x20
  unsigned __int64 v241; // x26
  unsigned __int64 v242; // x8
  __int64 v243; // x8
  __int64 v244; // x21
  unsigned __int16 *v245; // x24
  int v246; // w5
  __int64 v247; // x8
  __int64 v248; // x9
  __int64 *k; // x20
  __int64 v250; // x9
  __int64 v251; // x9
  _QWORD *v252; // x9
  __int64 v253; // t1
  int v254; // w9
  int v255; // w8
  int v256; // w10
  int v257; // w0
  __int64 v258; // x8
  __int64 v259; // x8
  __int64 v260; // x8
  __int64 v261; // x8
  unsigned int v262; // w23
  unsigned int v263; // w24
  unsigned int v264; // w0
  unsigned int v265; // w4
  void *v266; // x0
  void *v267; // x0
  void *v268; // x0
  const char *v269; // x1
  __int64 v270; // x8
  __int64 v271; // x9
  __int64 v272; // x9
  unsigned int v273; // w8
  void *v274; // x0
  const char *v275; // x1
  __int64 (__fastcall *v276)(__int64, __int64); // x8
  void *v277; // x0
  void *v278; // x0
  unsigned int v279; // [xsp+40h] [xbp-400h]
  int is_dirty; // [xsp+44h] [xbp-3FCh]
  unsigned int dest; // [xsp+48h] [xbp-3F8h]
  void *desta; // [xsp+48h] [xbp-3F8h]
  int v283; // [xsp+50h] [xbp-3F0h]
  _DWORD *v284; // [xsp+50h] [xbp-3F0h]
  __int64 v285; // [xsp+60h] [xbp-3E0h]
  _QWORD *v286; // [xsp+68h] [xbp-3D8h]
  __int64 v287; // [xsp+70h] [xbp-3D0h]
  _QWORD v288[2]; // [xsp+78h] [xbp-3C8h] BYREF
  __int64 v289; // [xsp+88h] [xbp-3B8h] BYREF
  __int64 v290; // [xsp+90h] [xbp-3B0h] BYREF
  __int64 v291; // [xsp+98h] [xbp-3A8h] BYREF
  char v292[8]; // [xsp+A0h] [xbp-3A0h] BYREF
  _QWORD s[115]; // [xsp+A8h] [xbp-398h] BYREF

  v3 = a1;
  s[113] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 8);
  v288[0] = 0;
  v288[1] = 0;
  if ( v4 != 1 || (*(_BYTE *)(a2 + 9) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "crtc%d -> enable %d, active %d, skip atomic_check\n",
        *(_DWORD *)(a1 + 112),
        v4,
        *(unsigned __int8 *)(a2 + 9));
    v8 = 0;
    LODWORD(v9) = 0;
    v6 = 0;
    goto LABEL_19;
  }
  v5 = *(_QWORD *)a1;
  v6 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1152);
  v7 = _kmalloc_cache_noprof(msleep, 3520, 384);
  v8 = v7;
  LODWORD(v9) = -12;
  if ( !v6 || !v7 )
    goto LABEL_19;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s: check", (const char *)(v3 + 2176));
  if ( (*(_BYTE *)(a2 + 10) & 4) != 0 )
    *(_BYTE *)(a2 + 10) |= 2u;
  *(_DWORD *)(a2 + 464) = 0;
  drm_connector_list_iter_begin(v5, v288);
  for ( i = drm_connector_list_iter_next(v288); i; i = drm_connector_list_iter_next(v288) )
  {
    if ( ((*(_DWORD *)(a2 + 16) >> *(_DWORD *)(i + 152)) & 1) != 0 )
    {
      v11 = *(unsigned int *)(a2 + 464);
      if ( (int)v11 <= 15 )
      {
        *(_DWORD *)(a2 + 464) = v11 + 1;
        if ( (unsigned int)v11 >= 0x10 )
          goto LABEL_634;
        *(_QWORD *)(a2 + 336 + 8 * v11) = i;
      }
    }
  }
  drm_connector_list_iter_end(v288);
  if ( a2 && (v13 = *(_QWORD **)a2) != nullptr )
  {
    s[0] = 0;
    s[1] = 0;
    drm_connector_list_iter_begin(*v13, s);
    v14 = drm_connector_list_iter_next(s);
    if ( v14 )
    {
      while ( ((*(_DWORD *)(a2 + 16) >> *(_DWORD *)(v14 + 152)) & 1) == 0 || (*(_BYTE *)(v14 + 5129) & 1) == 0 )
      {
        v14 = drm_connector_list_iter_next(s);
        if ( !v14 )
          goto LABEL_29;
      }
      v15 = 1;
    }
    else
    {
LABEL_29:
      v15 = 0;
    }
    drm_connector_list_iter_end(s);
  }
  else
  {
    v15 = 0;
  }
  *(_BYTE *)(a2 + 6921) = v15;
  v16 = (sde_crtc_in_lb_transition(*(_QWORD **)(v3 + 2008), a2) & 1) != 0 && (*(_BYTE *)(a2 + 10) & 4) == 0;
  v17 = *(unsigned __int8 *)(a2 + 6921);
  *(_BYTE *)(a2 + 6922) = v16;
  if ( v17 == 1 )
  {
    v18 = *(_DWORD *)(a2 + 464);
    if ( v18 < 1 )
      goto LABEL_263;
    v19 = 0;
    lm_cnt_from_topology = 0;
    do
    {
      if ( v19 == 16 )
        goto LABEL_634;
      v21 = *(_QWORD *)(a2 + 336 + 8 * v19);
      if ( v21 && *(_DWORD *)(v21 + 156) == 16 )
      {
        lm_cnt_from_topology = sde_connector_get_lm_cnt_from_topology(*(_QWORD *)(a2 + 336 + 8 * v19), a2 + 24);
        v18 = *(_DWORD *)(a2 + 464);
      }
      ++v19;
    }
    while ( v19 < v18 );
    if ( !lm_cnt_from_topology )
    {
LABEL_263:
      printk(&unk_24FC17, "_sde_crtc_check_loopback_mode");
      v124 = &unk_23F0F3;
LABEL_264:
      LODWORD(v9) = -22;
      printk(v124, "_sde_crtc_atomic_check");
      goto LABEL_19;
    }
    *(_DWORD *)(a2 + 7084) = lm_cnt_from_topology;
    v22 = a2 + 6924;
    *(_DWORD *)(a2 + 6940) = 0;
    *(_QWORD *)(a2 + 6964) = 0;
    *(_QWORD *)(a2 + 6972) = 0;
    *(_QWORD *)(a2 + 6924) = 0;
    *(_QWORD *)(a2 + 6932) = 0;
    *(_QWORD *)(a2 + 7004) = 0;
    *(_QWORD *)(a2 + 7012) = 0;
    *(_QWORD *)(a2 + 6944) = 0;
    *(_QWORD *)(a2 + 7044) = 0;
    *(_QWORD *)(a2 + 7052) = 0;
    v23 = *(_QWORD *)(a2 + 328);
    *(_QWORD *)(a2 + 6952) = 0;
    *(_DWORD *)(a2 + 6960) = 0;
    *(_DWORD *)(a2 + 6980) = 0;
    *(_QWORD *)(a2 + 6984) = 0;
    *(_QWORD *)(a2 + 6992) = 0;
    *(_DWORD *)(a2 + 7000) = 0;
    *(_DWORD *)(a2 + 7020) = 0;
    *(_QWORD *)(a2 + 7024) = 0;
    *(_QWORD *)(a2 + 7032) = 0;
    *(_DWORD *)(a2 + 7040) = 0;
    *(_DWORD *)(a2 + 7060) = 0;
    *(_DWORD *)(a2 + 7080) = 0;
    *(_QWORD *)(a2 + 7072) = 0;
    *(_QWORD *)(a2 + 7064) = 0;
    v24 = *(_QWORD *)(v23 + 8);
    v25 = *(__int64 **)(v24 + 840);
    if ( v25 != (__int64 *)(v24 + 840) )
    {
      v26 = *(_DWORD *)(a2 + 12);
      do
      {
        v27 = *((unsigned int *)v25 + 437);
        if ( ((v26 >> v27) & 1) != 0 )
        {
          v28 = *(_DWORD **)(*(_QWORD *)(v23 + 24) + 32 * v27 + 8);
          if ( v28 )
          {
            if ( v28[412] == 4 )
            {
              v29 = v28[736];
              if ( v29 > 7 )
                goto LABEL_634;
              v30 = v22 + 20LL * v29;
              v31 = *(_DWORD *)(v30 + 4);
              if ( v31 <= v28[10] )
                v31 = v28[10];
              *(_DWORD *)(v30 + 4) = v31;
              v32 = v28[736];
              if ( v32 > 7 )
                goto LABEL_634;
              v33 = v22 + 20LL * v32;
              v34 = v28[11];
              if ( *(_DWORD *)(v33 + 8) > v34 )
                v34 = *(_DWORD *)(v33 + 8);
              *(_DWORD *)(v33 + 8) = v34;
              v24 = *(_QWORD *)(v23 + 8);
            }
          }
        }
        v25 = (__int64 *)*v25;
      }
      while ( v25 != (__int64 *)(v24 + 840) );
    }
  }
  else
  {
    *(_DWORD *)(a2 + 7084) = 0;
  }
  v35 = sde_crtc_check_dest_scaler_data(v3, a2);
  if ( v35 )
  {
    LODWORD(v9) = v35;
    v125 = &unk_248F49;
    goto LABEL_676;
  }
  if ( !v3 || !*(_QWORD *)v3 || (v36 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
  {
    v107 = &unk_25E167;
LABEL_268:
    printk(v107, "_sde_crtc_get_kms");
    goto LABEL_269;
  }
  v37 = *(_QWORD *)(v36 + 8);
  if ( !v37 )
  {
    v107 = &unk_234896;
    goto LABEL_268;
  }
  if ( !*(_QWORD *)(v37 + 152) )
  {
LABEL_269:
    printk(&unk_27D28A, "_sde_crtc_check_plane_layout");
    LODWORD(v9) = -22;
    goto LABEL_270;
  }
  v285 = v8;
  if ( !sde_crtc_get_sde_connector_state((_QWORD *)v3, *(_QWORD *)(a2 + 328)) )
  {
    if ( *(_DWORD *)(v3 + 2192) != 4 )
      goto LABEL_99;
    goto LABEL_68;
  }
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64))sde_rm_topology_is_group)(v37 + 2144, a2, 3) & 1) != 0 )
  {
LABEL_68:
    LODWORD(s[0]) = 0;
    *(_DWORD *)v292 = 0;
    sde_crtc_get_resolution(v3, a2, a2 + 24, s, v292);
    v38 = *(_QWORD *)(a2 + 328);
    v39 = *(_QWORD *)(v38 + 8);
    v40 = *(__int64 **)(v39 + 840);
    v41 = (__int64 *)(v39 + 840);
    if ( v40 == v41 )
      goto LABEL_99;
    v42 = 0x7FFFFFFF;
    v43 = v40;
    do
    {
      v44 = *((unsigned int *)v43 + 437);
      if ( ((*(_DWORD *)(a2 + 12) >> v44) & 1) != 0 )
      {
        v45 = *(_DWORD **)(*(_QWORD *)(v38 + 24) + 32 * v44 + 8);
        if ( v45 )
        {
          if ( v45[412] == 4 )
          {
            if ( v45[449] )
            {
              v46 = v45[8];
              if ( v42 >= v46 )
                v42 = v46;
            }
          }
        }
      }
      v43 = (__int64 *)*v43;
    }
    while ( v43 != v41 );
    do
    {
      v47 = *((unsigned int *)v40 + 437);
      if ( ((*(_DWORD *)(a2 + 12) >> v47) & 1) == 0 )
        goto LABEL_78;
      v48 = *(_QWORD *)(*(_QWORD *)(v38 + 24) + 32 * v47 + 8);
      if ( !v48 )
        goto LABEL_78;
      v49 = *(_QWORD *)(v48 + 1648);
      v50 = *(_DWORD *)(v48 + 32);
      v51 = LODWORD(s[0]) >> 1;
      if ( v49 == 4 )
        v52 = v42;
      else
        v52 = LODWORD(s[0]) >> 1;
      v53 = v50 - v52;
      if ( v50 >= v52 )
      {
        v54 = 2;
        v50 -= v52;
        *(_DWORD *)(v48 + 32) = v53;
        *(_DWORD *)(v48 + 1792) = v52;
        if ( v49 )
          goto LABEL_89;
      }
      else
      {
        v54 = 1;
        *(_DWORD *)(v48 + 1792) = -1;
        if ( v49 )
          goto LABEL_89;
      }
      *(_DWORD *)(v48 + 1796) = v54;
LABEL_89:
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v40 == (__int64 *)&unk_8 )
          v55 = -1;
        else
          v55 = *((_DWORD *)v40 + 24);
        _drm_dev_dbg(0, 0, 0, "plane%d updated: crtc_x=%d layout=%d\n", v55, v50, *(_DWORD *)(v48 + 1796));
      }
      if ( v49 != 4 )
      {
        v56 = *(_DWORD *)(v48 + 40);
        v57 = v51 >= v56;
        v58 = v51 - v56;
        if ( !v57 || *(_DWORD *)(v48 + 32) > v58 )
        {
          printk(&unk_245F2E, "_sde_crtc_check_plane_layout");
          printk(&unk_23F191, "_sde_crtc_check_plane_layout");
          v8 = v285;
          LODWORD(v9) = -7;
LABEL_270:
          v125 = &unk_268C00;
          goto LABEL_676;
        }
      }
LABEL_78:
      v38 = *(_QWORD *)(a2 + 328);
      v40 = (__int64 *)*v40;
    }
    while ( v40 != (__int64 *)(*(_QWORD *)(v38 + 8) + 840LL) );
  }
LABEL_99:
  v59 = *(unsigned int *)(a2 + 464);
  v8 = v285;
  *(_BYTE *)(a2 + 483) = 0;
  if ( (int)v59 >= 1 )
  {
    v60 = 8 * v59;
    v61 = 0;
    while ( v61 != 128 )
    {
      v62 = *(_QWORD *)(a2 + 336 + v61);
      if ( v62 )
      {
        v63 = *(_QWORD *)(v62 + 2512);
        if ( v63 )
        {
          if ( *(_QWORD *)(v63 + 1376) == 10 )
            *(_BYTE *)(a2 + 483) = 1;
        }
      }
      v61 += 8;
      if ( v60 == v61 )
        goto LABEL_107;
    }
    goto LABEL_634;
  }
LABEL_107:
  sde_crtc_setup_lm_bounds(v3, a2);
  if ( !*(_QWORD *)v3 || (v64 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
  {
    v123 = &unk_25E167;
LABEL_272:
    printk(v123, "_sde_crtc_get_kms");
    goto LABEL_273;
  }
  v65 = *(_QWORD *)(v64 + 8);
  if ( !v65 )
  {
    v123 = &unk_234896;
    goto LABEL_272;
  }
  if ( !*(_QWORD *)(v65 + 152) )
  {
LABEL_273:
    v127 = &unk_27D28A;
    v128 = "_sde_crtc_atomic_check_pstates";
    goto LABEL_274;
  }
  v291 = 0;
  HIDWORD(v290) = 0;
  *(_DWORD *)v292 = 0;
  memset(s, 0, 120);
  sde_crtc_get_resolution(v3, a2, a2 + 24, v292, (_DWORD *)&v291 + 1);
  sde_crtc_get_loopback_resolution(a2, v3, &v291, (unsigned int *)&v290 + 1);
  v66 = *(_QWORD *)(a2 + 328);
  v287 = v3;
  v67 = *(_QWORD *)(v66 + 8);
  v68 = *(__int64 **)(v67 + 840);
  if ( v68 != (__int64 *)(v67 + 840) )
  {
    LODWORD(v69) = 0;
    v70 = 0;
    LODWORD(v8) = 0;
    v279 = HIDWORD(v290);
    v71 = v291;
    dest = *(_DWORD *)v292;
    while ( 1 )
    {
      v149 = *((unsigned int *)v68 + 437);
      if ( ((*(_DWORD *)(a2 + 12) >> v149) & 1) != 0 )
      {
        v150 = *(_QWORD *)(v66 + 24) + 32 * v149;
        v152 = *(_QWORD *)(v150 + 8);
        v151 = (unsigned __int64 *)(v150 + 8);
        if ( !v152 )
          v151 = (unsigned __int64 *)(v68 + 220);
        v9 = *v151;
        if ( *v151 )
        {
          if ( v9 > 0xFFFFFFFFFFFFF000LL )
          {
            printk(&unk_234C4F, "_sde_crtc_check_get_pstates");
            v8 = v285;
            goto LABEL_675;
          }
          if ( (int)v69 <= 47 )
          {
            v153 = (int)v69;
            v154 = 24LL * (int)v69;
            if ( v154 > 0x480 )
              goto LABEL_682;
            *(_QWORD *)(v6 + 24LL * (int)v69) = v9;
            if ( (unsigned __int64)(24LL * (int)v69 - 1145) < 0xFFFFFFFFFFFFFB7FLL )
              goto LABEL_682;
            v155 = 24LL * (int)v69 - 1137;
            v156 = v6 + 24LL * (int)v69;
            *(_QWORD *)(v156 + 8) = v9;
            if ( v155 < 0xFFFFFFFFFFFFFB7FLL )
              goto LABEL_682;
            *(_DWORD *)(v156 + 16) = *(_QWORD *)(v9 + 752);
            v157 = sde_plane_pipe(v68 - 1);
            if ( (unsigned __int64)(24LL * (int)v153 - 1133) < 0xFFFFFFFFFFFFFB7FLL )
              goto LABEL_682;
            v158 = *(_QWORD *)(v6 + v154);
            *(_DWORD *)(v6 + 24LL * (int)v153 + 20) = v157;
            if ( v158 )
              LODWORD(v158) = *(_DWORD *)(v158 + 1456);
            v3 = v287;
            v159 = *(_DWORD *)(a2 + 1808);
            if ( (*(_QWORD *)(*(_QWORD *)(v65 + 152) + 22008LL) & 0x2000LL) != 0 )
              v8 = (unsigned int)v8;
            else
              v8 = 1;
            if ( !v159 )
              goto LABEL_353;
            v160 = *(_DWORD *)(v156 + 16) + v8;
            if ( *(_DWORD *)(a2 + 1824) == v160 )
              goto LABEL_683;
            if ( v159 == 1 )
              goto LABEL_353;
            if ( *(_DWORD *)(a2 + 1856) == v160 )
              goto LABEL_683;
            if ( v159 == 2 )
              goto LABEL_353;
            if ( *(_DWORD *)(a2 + 1888) == v160 )
              goto LABEL_683;
            if ( v159 == 3 )
              goto LABEL_353;
            if ( *(_DWORD *)(a2 + 1920) == v160 )
              goto LABEL_683;
            if ( v159 == 4 )
              goto LABEL_353;
            if ( *(_DWORD *)(a2 + 1952) == v160 )
              goto LABEL_683;
            if ( v159 == 5 )
              goto LABEL_353;
            if ( *(_DWORD *)(a2 + 1984) == v160 )
              goto LABEL_683;
            if ( v159 == 6 )
            {
LABEL_353:
              if ( v157 > 0xE )
                goto LABEL_634;
            }
            else
            {
              if ( *(_DWORD *)(a2 + 2016) == v160 )
                goto LABEL_683;
              if ( v159 != 7 || v157 >= 0xF )
                goto LABEL_634;
            }
            v161 = s[v157];
            if ( v161 )
            {
              v162 = 16LL * v70;
              if ( v162 > 0x180 )
                goto LABEL_682;
              if ( v70 == 24 )
                goto LABEL_682;
              v163 = (_QWORD *)(v285 + 16LL * v70);
              *v163 = v161;
              if ( (v162 | 8) > 0x180 )
                goto LABEL_682;
              v164 = 0;
              ++v70;
              v163[1] = v9;
            }
            else
            {
              v164 = v9;
            }
            v69 = v153 + 1;
            s[v157] = v164;
            if ( (_DWORD)v158 == 5 )
            {
              v165 = *(_DWORD *)(v9 + 44);
              v166 = *(unsigned __int16 *)(a2 + 38);
              if ( v166 < v165
                || *(_DWORD *)(v9 + 36) > v166 - v165
                || (v167 = *(_DWORD *)(v9 + 40),
                    v168 = *(unsigned __int16 *)(a2 + 28),
                    v57 = v168 >= v167,
                    v169 = v168 - v167,
                    !v57)
                || *(_DWORD *)(v9 + 32) > v169 )
              {
                v176 = &unk_25A991;
                goto LABEL_398;
              }
            }
            else
            {
              if ( (unsigned __int64)(24 * v69) > 0x480 || (_DWORD)v153 == 47 )
                goto LABEL_682;
              v170 = *(_QWORD *)(v6 + 24 * v69);
              if ( v170
                && *(_QWORD *)(v170 + 1648) == 4
                && ((v172 = *(_DWORD *)(v9 + 40), v171 = *(_DWORD *)(v9 + 44), v279 < v171)
                 || *(_DWORD *)(v9 + 36) > v279 - v171
                 || (unsigned int)v71 < v172
                 || *(_DWORD *)(v9 + 32) > (unsigned int)v71 - v172) )
              {
                printk(&unk_2270AD, "_sde_crtc_check_get_pstates");
              }
              else
              {
                v173 = *(_DWORD *)(v9 + 44);
                if ( HIDWORD(v71) < v173
                  || *(_DWORD *)(v9 + 36) > HIDWORD(v71) - v173
                  || (v174 = *(_DWORD *)(v9 + 40), v57 = dest >= v174, v175 = dest - v174, !v57)
                  || *(_DWORD *)(v9 + 32) > v175 )
                {
                  v176 = &unk_220986;
LABEL_398:
                  printk(v176, "_sde_crtc_check_get_pstates");
                  v8 = v285;
LABEL_674:
                  LODWORD(v9) = -7;
LABEL_675:
                  v125 = &unk_231722;
LABEL_676:
                  printk(v125, "_sde_crtc_atomic_check");
                  goto LABEL_19;
                }
              }
            }
          }
        }
      }
      v66 = *(_QWORD *)(a2 + 328);
      v68 = (__int64 *)*v68;
      if ( v68 == (__int64 *)(*(_QWORD *)(v66 + 8) + 840LL) )
        goto LABEL_114;
    }
  }
  LODWORD(v69) = 0;
  v70 = 0;
LABEL_114:
  for ( j = 1; j != 15; ++j )
  {
    v73 = (_DWORD *)s[j];
    if ( v73 )
    {
      sde_plane_clear_multirect(s[j]);
      if ( (is_sde_plane_virtual(*(_QWORD *)v73) & 1) != 0 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "r1 only virt plane:%d staged\n", *(_DWORD *)(*(_QWORD *)v73 + 104LL));
          v73 = (_DWORD *)s[j];
        }
        v73[444] = 2;
      }
    }
  }
  v8 = v285;
  if ( v70 >= 1 )
  {
    v74 = 0;
    while ( !(unsigned int)sde_plane_validate_multirect_v2(v285 + v74) )
    {
      v74 += 16LL;
      if ( 16LL * (unsigned int)v70 == v74 )
        goto LABEL_125;
    }
    if ( v74 <= 0x17F && v74 + 8 <= 0x180 )
    {
      printk(&unk_25E512, "_sde_crtc_check_get_pstates");
      LODWORD(v9) = -22;
      goto LABEL_675;
    }
    goto LABEL_682;
  }
LABEL_125:
  if ( !*(_QWORD *)v3 || (v75 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
  {
    v126 = &unk_25E167;
LABEL_277:
    printk(v126, "_sde_crtc_get_kms");
    goto LABEL_278;
  }
  v3 = *(_QWORD *)(v75 + 8);
  if ( !v3 )
  {
    v126 = &unk_234896;
    goto LABEL_277;
  }
  if ( !*(_QWORD *)(v3 + 152) )
  {
LABEL_278:
    printk(&unk_27D36D, "_sde_crtc_check_zpos");
    goto LABEL_464;
  }
  sort(v6, (int)v69, 24, pstate_cmp, 0);
  LODWORD(s[0]) = 0;
  *(_DWORD *)v292 = 0;
  resolution = sde_crtc_get_resolution(v287, a2, a2 + 24, s, v292);
  v77 = *(_DWORD *)(a2 + 1808);
  if ( !v77 )
    goto LABEL_186;
  v78 = *(unsigned __int16 *)(a2 + 1850);
  if ( *(_DWORD *)v292 < v78 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v78 < *(unsigned __int16 *)(a2 + 1846) )
    goto LABEL_673;
  v79 = *(unsigned __int16 *)(a2 + 1848);
  if ( LODWORD(s[0]) < v79
    || LODWORD(s[0]) - v79 < *(unsigned __int16 *)(a2 + 1844)
    || !*(_WORD *)(a2 + 1850)
    || !*(_WORD *)(a2 + 1848)
    || *(_DWORD *)(a2 + 1824) >= 0xCu )
  {
    goto LABEL_673;
  }
  if ( v77 == 1 )
    goto LABEL_186;
  v80 = *(unsigned __int16 *)(a2 + 1882);
  if ( *(_DWORD *)v292 < v80 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v80 < *(unsigned __int16 *)(a2 + 1878) )
    goto LABEL_673;
  v81 = *(unsigned __int16 *)(a2 + 1880);
  if ( LODWORD(s[0]) < v81
    || LODWORD(s[0]) - v81 < *(unsigned __int16 *)(a2 + 1876)
    || !*(_WORD *)(a2 + 1882)
    || !*(_WORD *)(a2 + 1880)
    || *(_DWORD *)(a2 + 1856) > 0xBu )
  {
    goto LABEL_673;
  }
  if ( v77 == 2 )
    goto LABEL_186;
  v82 = *(unsigned __int16 *)(a2 + 1914);
  if ( *(_DWORD *)v292 < v82 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v82 < *(unsigned __int16 *)(a2 + 1910) )
    goto LABEL_673;
  v83 = *(unsigned __int16 *)(a2 + 1912);
  if ( LODWORD(s[0]) < v83
    || LODWORD(s[0]) - v83 < *(unsigned __int16 *)(a2 + 1908)
    || !*(_WORD *)(a2 + 1914)
    || !*(_WORD *)(a2 + 1912)
    || *(_DWORD *)(a2 + 1888) > 0xBu )
  {
    goto LABEL_673;
  }
  if ( v77 == 3 )
    goto LABEL_186;
  v84 = *(unsigned __int16 *)(a2 + 1946);
  if ( *(_DWORD *)v292 < v84 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v84 < *(unsigned __int16 *)(a2 + 1942) )
    goto LABEL_673;
  v85 = *(unsigned __int16 *)(a2 + 1944);
  if ( LODWORD(s[0]) < v85
    || LODWORD(s[0]) - v85 < *(unsigned __int16 *)(a2 + 1940)
    || !*(_WORD *)(a2 + 1946)
    || !*(_WORD *)(a2 + 1944)
    || *(_DWORD *)(a2 + 1920) > 0xBu )
  {
    goto LABEL_673;
  }
  if ( v77 == 4 )
    goto LABEL_186;
  v86 = *(unsigned __int16 *)(a2 + 1978);
  if ( *(_DWORD *)v292 < v86 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v86 < *(unsigned __int16 *)(a2 + 1974) )
    goto LABEL_673;
  v87 = *(unsigned __int16 *)(a2 + 1976);
  if ( LODWORD(s[0]) < v87
    || LODWORD(s[0]) - v87 < *(unsigned __int16 *)(a2 + 1972)
    || !*(_WORD *)(a2 + 1978)
    || !*(_WORD *)(a2 + 1976)
    || *(_DWORD *)(a2 + 1952) > 0xBu )
  {
    goto LABEL_673;
  }
  if ( v77 == 5 )
    goto LABEL_186;
  v88 = *(unsigned __int16 *)(a2 + 2010);
  if ( *(_DWORD *)v292 < v88 )
    goto LABEL_673;
  if ( *(_DWORD *)v292 - v88 < *(unsigned __int16 *)(a2 + 2006) )
    goto LABEL_673;
  v89 = *(unsigned __int16 *)(a2 + 2008);
  if ( LODWORD(s[0]) < v89
    || LODWORD(s[0]) - v89 < *(unsigned __int16 *)(a2 + 2004)
    || !*(_WORD *)(a2 + 2010)
    || !*(_WORD *)(a2 + 2008)
    || *(_DWORD *)(a2 + 1984) > 0xBu )
  {
    goto LABEL_673;
  }
  if ( v77 == 6 )
    goto LABEL_186;
  v90 = *(unsigned __int16 *)(a2 + 2042);
  if ( *(_DWORD *)v292 < v90
    || *(_DWORD *)v292 - v90 < *(unsigned __int16 *)(a2 + 2038)
    || (v91 = *(unsigned __int16 *)(a2 + 2040), LODWORD(s[0]) < v91)
    || LODWORD(s[0]) - v91 < *(unsigned __int16 *)(a2 + 2036)
    || !*(_WORD *)(a2 + 2042)
    || !*(_WORD *)(a2 + 2040) )
  {
    v8 = v285;
    goto LABEL_673;
  }
  v8 = v285;
  if ( *(_DWORD *)(a2 + 2016) > 0xBu )
  {
LABEL_673:
    printk(&unk_24C5CF, "_sde_crtc_excl_dim_layer_check");
    goto LABEL_674;
  }
  if ( v77 != 7 )
    goto LABEL_634;
LABEL_186:
  if ( (int)v69 >= 1 )
  {
    v92 = 0;
    v93 = _drm_debug;
    do
    {
      if ( (unsigned __int64)(v92 - 1144) < 0xFFFFFFFFFFFFFB80LL )
        goto LABEL_682;
      if ( (v93 & 4) != 0 )
      {
        v94 = *(_QWORD *)(v6 + v92 + 8);
        if ( *(_QWORD *)v94 )
          v95 = *(_DWORD *)(*(_QWORD *)v94 + 104LL);
        else
          v95 = -1;
        if ( (unsigned __int64)(v92 - 1136) < 0xFFFFFFFFFFFFFB80LL )
          goto LABEL_682;
        resolution = _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "p %d z %d src{%d,%d,%d,%d} excl_rect{%d,%d,%d,%d}\n",
                       v95,
                       *(_DWORD *)(v6 + v92 + 16),
                       *(_DWORD *)(v94 + 32),
                       *(_DWORD *)(v94 + 36),
                       *(_DWORD *)(v94 + 40),
                       *(_DWORD *)(v94 + 44),
                       *(unsigned __int16 *)(v94 + 1764),
                       *(unsigned __int16 *)(v94 + 1766),
                       *(unsigned __int16 *)(v94 + 1768),
                       *(unsigned __int16 *)(v94 + 1770));
        v93 = _drm_debug;
      }
      v92 += 24;
    }
    while ( 24LL * (unsigned int)v69 != v92 );
    if ( (sde_is_custom_client(resolution) & 1) == 0 )
    {
      v96 = 0;
      v97 = v6 + 16;
      v98 = *(_DWORD *)(v6 + 16);
      v99 = 0;
      while ( (unsigned __int64)(v96 - 1136) >= 0xFFFFFFFFFFFFFB80LL )
      {
        v229 = v98 == *(_DWORD *)(v97 + v96);
        v98 = *(_DWORD *)(v97 + v96);
        if ( !v229 )
          ++v99;
        *(_DWORD *)(v97 + v96) = v99;
        v96 += 24;
        if ( 24LL * (unsigned int)v69 == v96 )
          goto LABEL_202;
      }
LABEL_682:
      __break(1u);
LABEL_683:
      printk(&unk_268CC3, "_sde_crtc_check_get_pstates");
      goto LABEL_389;
    }
LABEL_202:
    v100 = 0;
    v101 = 0;
    v102 = 0;
    v103 = -1;
    while ( 1 )
    {
      if ( v100 - 1136 < 0xFFFFFFFFFFFFFB80LL || v100 > 0x47F )
        goto LABEL_682;
      v104 = *(_DWORD *)(v6 + v100 + 16);
      if ( v104 == v103 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(v6 + v100) + 1796LL) == v101 )
        {
          if ( v102 == 2 )
          {
            v177 = &unk_25A9E0;
            goto LABEL_461;
          }
          if ( (*(_QWORD *)(a2 + 1792) & 4) == 0 )
            goto LABEL_219;
        }
        else
        {
          v102 = 0;
          v101 = *(_DWORD *)(*(_QWORD *)(v6 + v100) + 1796LL);
          if ( (*(_QWORD *)(a2 + 1792) & 4) == 0 )
            goto LABEL_219;
        }
      }
      else
      {
        if ( v104 >= 11 )
        {
          v177 = &unk_276C8C;
LABEL_461:
          printk(v177, "_sde_crtc_check_zpos");
          goto LABEL_463;
        }
        v102 = 0;
        v101 = *(_DWORD *)(*(_QWORD *)(v6 + v100) + 1796LL);
        v103 = *(_DWORD *)(v6 + v100 + 16);
        if ( (*(_QWORD *)(a2 + 1792) & 4) == 0 )
        {
LABEL_219:
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "noise layer not enabled %d\n", *(unsigned __int8 *)(a2 + 4568));
          goto LABEL_221;
        }
      }
      if ( (*(_BYTE *)(a2 + 4568) & 1) == 0 )
        goto LABEL_219;
      if ( *(_DWORD *)(a2 + 4584) == v103 || *(_DWORD *)(a2 + 4588) == v103 )
      {
        printk(&unk_215AE6, "_sde_crtc_noise_layer_check_zpos");
LABEL_463:
        v8 = v285;
LABEL_464:
        LODWORD(v9) = -22;
        goto LABEL_675;
      }
LABEL_221:
      v105 = _drm_debug;
      if ( (*(_QWORD *)(*(_QWORD *)(v3 + 152) + 22008LL) & 0x2000LL) != 0 )
        v106 = v103;
      else
        v106 = v103 + 1;
      *(_DWORD *)(*(_QWORD *)(v6 + v100) + 1760LL) = v106;
      if ( (v105 & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "%s: layout %d, zpos %d", (const char *)(v287 + 2176), v101, v103);
      v100 += 24LL;
      ++v102;
      if ( 24LL * (unsigned int)v69 == v100 )
        goto LABEL_228;
    }
  }
  sde_is_custom_client(resolution);
LABEL_228:
  LODWORD(s[0]) = 0;
  HIDWORD(v291) = 0;
  *(_DWORD *)v292 = 0;
  if ( !a2 )
  {
    printk(&unk_26FEB0, "_sde_crtc_check_secure_state");
    goto LABEL_463;
  }
  v3 = v287;
  if ( !*(_QWORD *)v287 || (v108 = *(_QWORD *)(*(_QWORD *)v287 + 56LL)) == 0 )
  {
    v129 = &unk_25E167;
LABEL_387:
    printk(v129, "_sde_crtc_get_kms");
    goto LABEL_388;
  }
  v109 = *(_QWORD *)(v108 + 8);
  if ( !v109 )
  {
    v129 = &unk_234896;
    goto LABEL_387;
  }
  if ( !*(_QWORD *)(v109 + 152) )
  {
LABEL_388:
    printk(&unk_234896, "_sde_crtc_check_secure_state");
    goto LABEL_389;
  }
  LODWORD(v8) = *(_DWORD *)(a2 + 1408);
  plane_fb_modes = sde_crtc_state_find_plane_fb_modes(a2, s, v292, (_DWORD *)&v291 + 1);
  if ( plane_fb_modes )
  {
    v8 = v285;
    LODWORD(v9) = plane_fb_modes;
    goto LABEL_675;
  }
  v112 = HIDWORD(v291);
  v111 = *(_DWORD *)v292;
  v113 = s[0];
  if ( (_DWORD)v8 != 1 )
    goto LABEL_285;
  if ( *(_DWORD *)v292 | LODWORD(s[0]) )
  {
    printk(&unk_25AA10, "_sde_crtc_check_secure_blend_config");
    goto LABEL_389;
  }
  v114 = s[0];
  v283 = *(_DWORD *)v292;
  if ( (int)v69 >= 2 )
  {
    v115 = 0;
    v116 = 1;
    while ( 1 )
    {
      if ( (unsigned __int64)(v115 - 1120) < 0xFFFFFFFFFFFFFB80LL )
        goto LABEL_682;
      v117 = *(_QWORD **)(v6 + v115 + 32);
      if ( !v117 || !*v117 )
        break;
      if ( (sde_plane_is_sec_ui_allowed(*v117) & 1) == 0 )
      {
        printk(&unk_27375A, "_sde_crtc_check_secure_blend_config");
        goto LABEL_389;
      }
      if ( (unsigned __int64)(v115 - 1112) < 0xFFFFFFFFFFFFFB80LL
        || (unsigned __int64)(v115 - 1136) < 0xFFFFFFFFFFFFFB80LL )
      {
        goto LABEL_682;
      }
      if ( *(_DWORD *)(v6 + v115 + 40) != *(_DWORD *)(v6 + v115 + 16) )
      {
        v210 = &unk_265725;
        v211 = "_sde_crtc_check_secure_blend_config";
        goto LABEL_681;
      }
      v115 += 24;
      ++v116;
      if ( 24LL * (unsigned int)v69 - 24 == v115 )
        goto LABEL_246;
    }
    printk(&unk_22AB14, "_sde_crtc_check_secure_blend_config");
LABEL_389:
    v8 = v285;
    LODWORD(v9) = -22;
    goto LABEL_675;
  }
LABEL_246:
  v118 = *(_DWORD *)(a2 + 1808);
  v3 = v287;
  v111 = v283;
  v113 = v114;
  v8 = 1;
  if ( v118 >= 2 )
  {
    v119 = *(_DWORD *)(a2 + 1856);
    if ( v119 != *(_DWORD *)(a2 + 1824) )
      goto LABEL_680;
    if ( v118 != 2 )
    {
      if ( *(_DWORD *)(a2 + 1888) != v119 )
        goto LABEL_680;
      if ( v118 != 3 )
      {
        if ( *(_DWORD *)(a2 + 1920) != v119 )
          goto LABEL_680;
        if ( v118 != 4 )
        {
          if ( *(_DWORD *)(a2 + 1952) != v119 )
            goto LABEL_680;
          if ( v118 != 5 )
          {
            if ( *(_DWORD *)(a2 + 1984) != v119 )
              goto LABEL_680;
            if ( v118 != 6 )
            {
              if ( *(_DWORD *)(a2 + 2016) == v119 )
              {
                if ( v118 != 7 )
                  goto LABEL_634;
                goto LABEL_259;
              }
LABEL_680:
              v210 = &unk_25AA5D;
              v211 = "_sde_crtc_check_secure_blend_config";
              goto LABEL_681;
            }
          }
        }
      }
    }
  }
LABEL_259:
  v120 = *(_QWORD *)(v109 + 152);
  v121 = *(_DWORD *)(v120 + 21532);
  if ( v121 )
  {
    v122 = (_DWORD *)((_DWORD)v69 ? *(_QWORD *)v6 + 1760LL : a2 + 1824);
    if ( !(v118 | (unsigned int)v69) || v121 != (((unsigned int)*(_QWORD *)(v120 + 22008) >> 13) & 1) + *v122 - 1 )
    {
      printk(&unk_215B25, "_sde_crtc_check_secure_blend_config");
      goto LABEL_389;
    }
  }
LABEL_285:
  v130 = *(_QWORD *)(a2 + 328);
  v131 = *(unsigned int *)(v130 + 40);
  if ( (int)v131 >= 1 )
  {
    v132 = *(_QWORD **)(v130 + 48);
    v133 = 0;
    v134 = 0;
    do
    {
      if ( *v132 )
      {
        v135 = v132[3];
        if ( v135 )
        {
          if ( *(_QWORD *)(v135 + 8) == v3 )
          {
            v134 |= *(_DWORD *)(*v132 + 156LL) == 15;
            v133 |= *(_QWORD *)(v135 + 1504) == 1;
          }
        }
      }
      --v131;
      v132 += 5;
    }
    while ( v131 );
    if ( !((v111 == 0 || (v134 & 1) == 0) | v133 & 1) )
    {
      printk(&unk_24FC47, "_sde_crtc_check_secure_conn");
      goto LABEL_389;
    }
  }
  v136 = *(_QWORD *)v3;
  v137 = a2 + 4096;
  v138 = *(__int64 **)(*(_QWORD *)v3 + 816LL);
  v139 = *(_QWORD *)v3 + 816LL;
  if ( v112 )
  {
    if ( v138 != (__int64 *)v139 )
    {
      v140 = 0;
      v141 = *(__int64 **)(*(_QWORD *)v3 + 816LL);
      do
      {
        v142 = *((_DWORD *)v141 + 15);
        v141 = (__int64 *)*v141;
        v140 += (*(_DWORD *)(a2 + 20) >> v142) & 1;
      }
      while ( v141 != (__int64 *)v139 );
      if ( v140 >= 2 )
      {
        printk(&unk_23F1E8, "_sde_crtc_check_secure_single_encoder");
        goto LABEL_389;
      }
    }
  }
  if ( v138 == (__int64 *)v139 )
  {
    v146 = 1;
  }
  else
  {
    v143 = v8;
    v144 = v113;
    v145 = 0;
    do
    {
      if ( ((*(_DWORD *)(a2 + 20) >> *((_DWORD *)v138 + 15)) & 1) != 0
        && (sde_encoder_is_dsi_display(v138 - 1) & 1) != 0 )
      {
        v145 |= sde_encoder_check_curr_mode(v138 - 1, 1) & 1;
      }
      v136 = *(_QWORD *)v3;
      v138 = (__int64 *)*v138;
    }
    while ( v138 != (__int64 *)(*(_QWORD *)v3 + 816LL) );
    v229 = v145 == 0;
    v113 = v144;
    LODWORD(v8) = v143;
    v137 = a2 + 4096;
    v146 = v229;
  }
  if ( !(_DWORD)v8 )
  {
    if ( v112 )
    {
      v147 = *(_DWORD *)(v109 + 3656);
      if ( v147 )
      {
        if ( *(_DWORD *)(v109 + 3664) == 1 )
        {
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_crtc_check_secure_state_smmu_translation",
            6656,
            -1,
            *(_DWORD *)(v3 + 112),
            v113,
            v112,
            v147,
            1);
LABEL_473:
          v210 = &unk_23F228;
          v211 = "_sde_crtc_check_secure_state_smmu_translation";
LABEL_681:
          printk(v210, v211);
          goto LABEL_389;
        }
      }
    }
  }
  if ( (v146 & 1) != 0 || !*(_DWORD *)(a2 + 12) || !*(_DWORD *)(*(_QWORD *)(v3 + 2008) + 12LL) )
    goto LABEL_404;
  if ( v112 && (_DWORD)v8 == 1 && !*(_DWORD *)(v109 + 3656) )
  {
    v148 = 0;
    goto LABEL_472;
  }
  if ( !v113 )
    goto LABEL_404;
  v148 = *(_DWORD *)(v109 + 3656);
  if ( v148 > 3 )
  {
    if ( v148 == 5 )
    {
LABEL_392:
      if ( *(_DWORD *)(v109 + 3664) == 1 )
        goto LABEL_472;
      goto LABEL_404;
    }
    if ( v148 != 4 )
      goto LABEL_404;
LABEL_472:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_crtc_check_secure_state_smmu_translation",
      6676,
      -1,
      *(_DWORD *)(v3 + 112),
      v113,
      v112,
      v148,
      *(_DWORD *)(v109 + 3664));
    goto LABEL_473;
  }
  if ( v148 == 2 )
    goto LABEL_392;
  if ( v148 == 1 )
    goto LABEL_472;
LABEL_404:
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "crtc:%d Secure validation successful\n", *(_DWORD *)(v3 + 112));
    v136 = *(_QWORD *)v3;
  }
  v8 = v285;
  if ( !v136 || (v178 = *(_QWORD *)(v136 + 56)) == 0 )
  {
    v209 = &unk_25E167;
LABEL_455:
    printk(v209, "_sde_crtc_get_kms");
    goto LABEL_456;
  }
  v179 = *(_QWORD *)(v178 + 8);
  if ( !v179 )
  {
    v209 = &unk_234896;
    goto LABEL_455;
  }
  v180 = *(_QWORD *)(v179 + 152);
  if ( !v180 )
  {
LABEL_456:
    v127 = &unk_27D28A;
    v128 = "_sde_crtc_validate_src_split_order";
    goto LABEL_274;
  }
  if ( (int)v69 >= 2 )
  {
    v181 = 0;
    while ( 1 )
    {
      if ( v181 >= 0x480 || v181 - 1136 < 0xFFFFFFFFFFFFFB80LL || v181 + 24 > 0x46F )
        goto LABEL_682;
      if ( *(_DWORD *)(v6 + v181 + 16) == *(_DWORD *)(v6 + v181 + 40) )
      {
        v182 = *(_QWORD *)(v6 + v181);
        v183 = *(_QWORD *)(v6 + v181 + 24);
        if ( *(_DWORD *)(v182 + 1796) == *(_DWORD *)(v183 + 1796)
          && (!v182 || !*(_QWORD *)(v182 + 1648))
          && (!v183 || !*(_QWORD *)(v183 + 1648)) )
        {
          v184 = *(unsigned __int16 **)(v6 + v181 + 8);
          v185 = *(unsigned __int16 **)(v6 + v181 + 32);
          v186 = *(_DWORD *)(*(_QWORD *)v182 + 104LL);
          v187 = *(_DWORD *)(*(_QWORD *)v183 + 104LL);
          v188 = v184[16];
          v189 = v185[16];
          v190 = v184[18];
          v191 = v184[20];
          v192 = v184[22];
          v193 = v185[18];
          v194 = v185[22];
          if ( v189 >= v188 )
          {
            v195 = v190;
            v196 = v191;
            v197 = v189;
            v190 = v193;
            v198 = *(_DWORD *)(*(_QWORD *)v182 + 104LL);
            v186 = v187;
            v189 = v188;
          }
          else
          {
            v195 = v185[18];
            v196 = v185[20];
            v197 = v188;
            v198 = v187;
          }
          if ( v186 < v198 && !*(_DWORD *)(v180 + 21604) )
          {
            printk(&unk_253556, "_sde_crtc_validate_src_split_order");
            LODWORD(v9) = -22;
            goto LABEL_675;
          }
          if ( v197 != v189 + v196 )
          {
            v127 = &unk_24FC8E;
            v128 = "_sde_crtc_validate_src_split_order";
            goto LABEL_274;
          }
          if ( v195 != v190 || v194 != v192 )
            break;
        }
      }
      v181 += 24LL;
      if ( 24LL * (unsigned int)v69 - 24 == v181 )
        goto LABEL_431;
    }
    v127 = &unk_2317D3;
    v128 = "_sde_crtc_validate_src_split_order";
LABEL_274:
    printk(v127, v128);
    LODWORD(v9) = -22;
    goto LABEL_675;
  }
LABEL_431:
  v199 = sde_core_perf_crtc_check(v3, a2);
  if ( v199 )
  {
    LODWORD(v9) = v199;
    v125 = &unk_268C3E;
    goto LABEL_676;
  }
  desta = (void *)_kmalloc_cache_noprof(_wake_up, 3520, 904);
  if ( !desta )
  {
    LODWORD(v207) = -12;
    goto LABEL_626;
  }
  v289 = 0;
  v290 = 0;
  sde_crtc_get_resolution(v3, a2, a2 + 24, (_DWORD *)&v290 + 1, &v290);
  sde_crtc_get_mixer_resolution((_QWORD *)v3, a2, a2 + 24, (_DWORD *)&v289 + 1, &v289);
  v200 = *(_DWORD *)(v3 + 2192);
  if ( !v200 || *(_BYTE *)(v137 + 2825) == 1 || (*(_BYTE *)(v137 + 2826) & 1) != 0 )
  {
    v201 = desta;
  }
  else
  {
    v201 = desta;
    if ( __PAIR64__(HIDWORD(v289) * v200, v289) != v290 )
    {
      printk(&unk_276CC1, "_sde_crtc_check_rois");
      goto LABEL_624;
    }
  }
  v202 = *(_QWORD *)(a2 + 328);
  if ( v202 )
  {
    v203 = *(unsigned int *)(v202 + 40);
    if ( (int)v203 >= 1 )
    {
      v204 = *(_QWORD **)(v202 + 48);
      do
      {
        if ( *v204 )
        {
          v205 = v204[3];
          if ( v205 )
          {
            if ( *(_QWORD *)(v205 + 8) == v3 )
            {
              if ( (v206 = *(_DWORD *)(v205 + 1376), (unsigned int)(v206 - 9) >= 0xFFFFFFFD)
                && (v290 & 0x300000000LL) != 0
                || (unsigned int)(v206 - 13) >= 0xFFFFFFFE && (v290 & 0x700000000LL) != 0 )
              {
                printk(&unk_256D2D, "_sde_crtc_check_rois");
                LODWORD(v207) = -22;
                goto LABEL_626;
              }
            }
          }
        }
        --v203;
        v204 += 5;
      }
      while ( v203 );
    }
  }
  if ( *(int *)(a2 + 464) < 1 )
  {
LABEL_602:
    kfree(v201);
    v257 = sde_cp_crtc_check_properties(v3, a2);
    if ( v257 )
    {
      LODWORD(v9) = v257;
      printk(&unk_22AAB4, "_sde_crtc_atomic_check");
      v8 = v285;
      goto LABEL_19;
    }
    memset(s, 0, 0x388u);
    v258 = *(_QWORD *)v3;
    v8 = v285;
    *(_QWORD *)v292 = 0;
    if ( v258 && (v259 = *(_QWORD *)(v258 + 56)) != 0 )
    {
      v260 = *(_QWORD *)(v259 + 8);
      if ( v260 )
      {
        v261 = *(_QWORD *)(v260 + 152);
        if ( v261 )
        {
          if ( *(_DWORD *)(a2 + 464) != 1 )
            goto LABEL_628;
          if ( (*(_BYTE *)(v261 + 22016) & 1) == 0 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "no line insertion support mode change %d\n",
                (*(unsigned __int8 *)(a2 + 10) >> 1) & 1);
            goto LABEL_628;
          }
          if ( (unsigned int)sde_connector_get_mode_info(*(_QWORD *)(a2 + 336), a2 + 24, v292, s) )
          {
            printk(&unk_27A06A, "_sde_crtc_check_panel_stacking");
          }
          else
          {
            v262 = s[112];
            if ( !LODWORD(s[112]) )
            {
              *(_DWORD *)(a2 + 6908) = 0;
LABEL_628:
              if ( !*(_QWORD *)v3 )
                goto LABEL_635;
              v270 = *(_QWORD *)(*(_QWORD *)v3 + 56LL);
              if ( !v270 )
                goto LABEL_635;
              v271 = *(_QWORD *)(v270 + 8);
              if ( !v271 )
              {
                v274 = &unk_234896;
                v275 = "_sde_crtc_get_kms";
                goto LABEL_643;
              }
              v272 = *(_QWORD *)(v271 + 152);
              if ( !v272 || (*(_QWORD *)(v272 + 22008) & 0x8000000000000LL) == 0 )
                goto LABEL_644;
              v273 = *(_DWORD *)(v270 + 5912);
              if ( v273 <= 2 )
                goto LABEL_645;
LABEL_634:
              __break(0x5512u);
LABEL_635:
              v274 = &unk_25E167;
              v275 = "sde_crtc_get_disp_op";
LABEL_643:
              printk(v274, v275);
LABEL_644:
              v273 = 0;
LABEL_645:
              v276 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 8LL * v273 + 8232);
              if ( v276 )
              {
                if ( *((_DWORD *)v276 - 1) != -1493870922 )
                  __break(0x8228u);
                LODWORD(v9) = v276(v3, a2);
                if ( (_DWORD)v9 )
                  printk(&unk_21D530, "_sde_crtc_atomic_check");
              }
              else
              {
                LODWORD(v9) = 0;
              }
              goto LABEL_19;
            }
            v263 = *(unsigned __int16 *)(a2 + 158);
            if ( LODWORD(s[112]) < v263 )
            {
              v278 = &unk_261F8F;
            }
            else
            {
              if ( LODWORD(s[112]) == *(_DWORD *)(a2 + 6908) )
                goto LABEL_628;
              v264 = sde_crtc_calc_gcd(LODWORD(s[112]), *(unsigned __int16 *)(a2 + 158));
              v265 = v262 / v264 - v263 / v264;
              if ( v263 / v264 <= 0x3F && v265 < 0x10 )
              {
                *(_DWORD *)(a2 + 6912) = v263 / v264;
                *(_DWORD *)(a2 + 6916) = v265;
                *(_DWORD *)(a2 + 6908) = v262;
                goto LABEL_628;
              }
              v278 = &unk_23B8B3;
            }
            printk(v278, "_sde_crtc_check_panel_stacking");
          }
          goto LABEL_641;
        }
LABEL_640:
        printk(&unk_234896, "_sde_crtc_check_panel_stacking");
LABEL_641:
        v124 = &unk_2534F9;
        goto LABEL_264;
      }
      v267 = &unk_234896;
    }
    else
    {
      v267 = &unk_25E167;
    }
    printk(v267, "_sde_crtc_get_kms");
    goto LABEL_640;
  }
  v208 = 0;
  v286 = (_QWORD *)(a2 + 484);
  v284 = (_DWORD *)(a2 + 620);
  while ( 1 )
  {
    if ( v208 == 16 )
      goto LABEL_634;
    v212 = *(_QWORD *)(a2 + 336 + 8 * v208);
    if ( v212 )
    {
      v213 = *(_QWORD *)(v212 + 2512);
      if ( v213 )
      {
        if ( (unsigned int)sde_connector_state_get_mode_info(v213, v201) )
        {
          v268 = &unk_22711D;
          v269 = "_sde_crtc_check_rois";
          goto LABEL_623;
        }
        v214 = *(_QWORD *)(v212 + 2512);
        if ( v214 )
        {
          v215 = *(_DWORD *)(v214 + 1376);
          if ( v215 <= 0xC && ((1 << v215) & 0x19C0) != 0 && (v289 & 0x100000000LL) != 0 )
          {
            printk(&unk_215B68, "_sde_crtc_check_rois");
            goto LABEL_624;
          }
        }
        if ( *((_BYTE *)v201 + 744) == 1 )
          break;
      }
    }
LABEL_475:
    if ( ++v208 >= *(int *)(a2 + 464) )
      goto LABEL_602;
  }
  if ( *v284 > *((_DWORD *)v201 + 187) )
  {
    printk(&unk_223FA0, "_sde_crtc_check_rois");
    LODWORD(v207) = -7;
    goto LABEL_625;
  }
  memset(s, 0, 0x388u);
  if ( !*(_QWORD *)v3 || (v216 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
  {
    v277 = &unk_25E167;
LABEL_664:
    printk(v277, "_sde_crtc_get_kms");
LABEL_665:
    v268 = &unk_27D28A;
    v269 = "_sde_crtc_set_crtc_roi";
LABEL_623:
    printk(v268, v269);
    goto LABEL_624;
  }
  v217 = *(_QWORD *)(v216 + 8);
  if ( !v217 )
  {
    v277 = &unk_234896;
    goto LABEL_664;
  }
  if ( !*(_QWORD *)(v217 + 152) )
    goto LABEL_665;
  if ( *(_QWORD *)a2 )
    is_dirty = msm_property_is_dirty(*(_QWORD *)a2 + 2600LL, a2 + 768, 18);
  else
    is_dirty = 0;
  v218 = *(_QWORD *)(a2 + 328);
  v291 = 0;
  if ( *(int *)(v218 + 40) >= 1 )
  {
    v219 = 0;
    v220 = 0;
    while ( 2 )
    {
      v221 = *(_QWORD *)(v218 + 48);
      v222 = *(_QWORD *)(v221 + v219);
      if ( !v222 )
        goto LABEL_497;
      v223 = *(_QWORD **)(v221 + v219 + 24);
      *(_QWORD *)v292 = 0;
      if ( v223 && v223[1] == v3 )
      {
        if ( (unsigned int)sde_connector_state_get_mode_info((int)v223, s) )
        {
          printk(&unk_22711D, "_sde_crtc_set_crtc_roi");
          v201 = desta;
          goto LABEL_624;
        }
        v224 = *v223;
        v225 = msm_property_is_dirty(*v223 + 3312LL, v223 + 56, 18);
        v226 = *(_QWORD *)(v224 + 2744);
        v8 = v225;
        if ( v226 )
        {
          if ( (((__int64 (__fastcall *)(__int64))sde_encoder_in_clone_mode)(v226) & 1) == 0 )
          {
            v227 = (*(_DWORD *)(a2 + 1812) >> *(_DWORD *)(v226 + 68)) & 1;
            goto LABEL_506;
          }
        }
        else
        {
          v227 = 0;
LABEL_506:
          if ( !v227 && ((is_dirty ^ (unsigned int)v8) & 1) != 0 )
          {
            printk(&unk_27D500, "_sde_crtc_set_crtc_roi");
            v201 = desta;
            goto LABEL_624;
          }
        }
        v3 = v287;
        if ( LOBYTE(s[93]) == 1 )
        {
          if ( (v8 & 1) != 0
            && (*(_QWORD *)(a2 + 1792) & 1) != 0
            && (*(_QWORD *)(*(_QWORD *)(v217 + 152) + 22008LL) & 0x1000000000000LL) != 0
            && (*(_BYTE *)(a2 + 656) & 1) == 0 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "%s: crtc -> conn roi scaling DS + PU enabled case\n", (const char *)(v287 + 2176));
          }
          else
          {
            v228 = v223 + 256;
            v229 = *(_QWORD *)((char *)v223 + 2052) == *(_QWORD *)(a2 + 660)
                && *(_QWORD *)((char *)v223 + 2060) == *(_QWORD *)(a2 + 668);
            v231 = v229
                && *(_QWORD *)((char *)v223 + 2068) == *(_QWORD *)(a2 + 676)
                && *(_QWORD *)((char *)v223 + 2076) == *(_QWORD *)(a2 + 684);
            if ( !v231 && *v228 != *v284 )
            {
              printk(&unk_2381A7, "_sde_crtc_set_crtc_roi");
              v201 = desta;
              goto LABEL_624;
            }
            sde_kms_rect_merge_rectangles(v228, v292);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "conn_roi x:%u, y:%u, w:%u, h:%u\n",
                *(unsigned __int16 *)v292,
                *(unsigned __int16 *)&v292[2],
                *(unsigned __int16 *)&v292[4],
                *(unsigned __int16 *)&v292[6]);
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_crtc_set_crtc_roi",
              1459,
              4,
              *(_DWORD *)(v287 + 112),
              *(_DWORD *)(v222 + 64),
              *(unsigned __int16 *)v292,
              *(unsigned __int16 *)&v292[2],
              v292[4]);
          }
        }
      }
      v218 = *(_QWORD *)(a2 + 328);
LABEL_497:
      ++v220;
      v219 += 40;
      if ( v220 >= *(int *)(v218 + 40) )
        break;
      continue;
    }
  }
  sde_kms_rect_merge_rectangles(v284, v286);
  sde_crtc_get_resolution(v3, a2, a2 + 24, (_DWORD *)&v291 + 1, &v291);
  v232 = *(unsigned __int16 *)(a2 + 484);
  v233 = *(unsigned __int16 *)(a2 + 486);
  if ( *(_WORD *)(a2 + 484) )
  {
    v234 = *(unsigned __int16 *)(a2 + 488);
    v201 = desta;
  }
  else
  {
    v234 = *(unsigned __int16 *)(a2 + 488);
    if ( *(_WORD *)(a2 + 486) )
    {
      v201 = desta;
    }
    else
    {
      v201 = desta;
      if ( v291 == __PAIR64__(v234, *(unsigned __int16 *)(a2 + 490)) )
      {
        v234 = 0;
        v233 = 0;
        *v286 = 0;
      }
      else
      {
        v233 = 0;
      }
    }
  }
  v235 = *(_WORD *)(a2 + 490);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "%s: crtc roi (%d,%d,%d,%d)\n",
      (const char *)(v3 + 2176),
      v232,
      v233,
      v234,
      *(unsigned __int16 *)(a2 + 490));
    v232 = *(unsigned __int16 *)(a2 + 484);
    v233 = *(unsigned __int16 *)(a2 + 486);
    v234 = *(unsigned __int16 *)(a2 + 488);
    v235 = *(_WORD *)(a2 + 490);
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_crtc_set_crtc_roi", 1473, 4, *(_DWORD *)(v3 + 112), v232, v233, v234, v235);
  if ( *(_WORD *)(a2 + 488) )
  {
    if ( *(_WORD *)(a2 + 490) )
    {
      v236 = *(_QWORD *)(a2 + 328);
      v237 = *(unsigned int *)(v236 + 40);
      if ( (int)v237 >= 1 )
      {
        v238 = *(_QWORD **)(v236 + 48);
        do
        {
          if ( *v238 )
          {
            v239 = v238[3];
            if ( v239 )
            {
              if ( *(_QWORD *)(v239 + 8) == v3 && *(_QWORD *)(v239 + 1440) )
              {
                printk(&unk_220A0A, "_sde_crtc_check_autorefresh");
                goto LABEL_624;
              }
            }
          }
          --v237;
          v238 += 5;
        }
        while ( v237 );
      }
    }
  }
  if ( !*(_DWORD *)(v3 + 2192) )
  {
    if ( *(_BYTE *)(a2 + 483) == 1 )
    {
LABEL_581:
      if ( *(_WORD *)(a2 + 560)
        && *(_WORD *)(a2 + 562)
        && (unsigned int)sde_crtc_get_displays_affected(v3, a2) == 3
        && *(unsigned __int16 *)(a2 + 556) + (*(unsigned __int16 *)(a2 + 560) >> 1) != *(unsigned __int16 *)(a2 + 496) >> 1 )
      {
        printk(&unk_24FCD6, "_sde_crtc_check_rois_centered_and_symmetric");
        goto LABEL_624;
      }
    }
LABEL_585:
    if ( *(_WORD *)(a2 + 488) && *(_WORD *)(a2 + 490) )
    {
      v247 = *(_QWORD *)(a2 + 328);
      v248 = *(_QWORD *)(v247 + 8);
      for ( k = *(__int64 **)(v248 + 840); k != (__int64 *)(v248 + 840); k = (__int64 *)*k )
      {
        v250 = *((unsigned int *)k + 437);
        if ( ((*(_DWORD *)(a2 + 12) >> v250) & 1) != 0 )
        {
          v251 = *(_QWORD *)(v247 + 24) + 32 * v250;
          v253 = *(_QWORD *)(v251 + 8);
          v252 = (_QWORD *)(v251 + 8);
          if ( !v253 )
            v252 = k + 220;
          v207 = (_DWORD *)*v252;
          if ( *v252 )
          {
            *(_QWORD *)v292 = 0;
            s[0] = 0;
            if ( (unsigned __int64)v207 > 0xFFFFFFFFFFFFF000LL )
            {
              printk(&unk_234C4F, "_sde_crtc_check_planes_within_crtc_roi");
              goto LABEL_625;
            }
            if ( v207[364] != 5 )
            {
              v254 = v207[9];
              LOWORD(s[0]) = v207[8];
              v255 = v207[10];
              v256 = v207[11];
              WORD1(s[0]) = v254;
              WORD2(s[0]) = v255;
              HIWORD(s[0]) = v256;
              sde_kms_rect_intersect(v286, s, v292);
              if ( LOWORD(s[0]) != *(unsigned __int16 *)v292
                || WORD1(s[0]) != *(unsigned __int16 *)&v292[2]
                || WORD2(s[0]) != *(unsigned __int16 *)&v292[4]
                || HIWORD(s[0]) != *(unsigned __int16 *)&v292[6] )
              {
                printk(&unk_234CE2, "_sde_crtc_check_planes_within_crtc_roi");
                LODWORD(v207) = -7;
                goto LABEL_625;
              }
              v247 = *(_QWORD *)(a2 + 328);
            }
          }
        }
        v248 = *(_QWORD *)(v247 + 8);
      }
    }
    goto LABEL_475;
  }
  v240 = 0;
  v241 = 0;
  do
  {
    if ( v241 == 8 )
      goto LABEL_624;
    if ( !*(_QWORD *)v3 || (v243 = *(_QWORD *)(*(_QWORD *)v3 + 56LL)) == 0 )
    {
      v266 = &unk_25E167;
LABEL_621:
      printk(v266, "_sde_crtc_get_kms");
LABEL_622:
      v268 = &unk_27D28A;
      v269 = "_sde_crtc_set_lm_roi";
      goto LABEL_623;
    }
    v244 = *(_QWORD *)(v243 + 8);
    if ( !v244 )
    {
      v266 = &unk_234896;
      goto LABEL_621;
    }
    if ( !*(_QWORD *)(v244 + 152) )
      goto LABEL_622;
    v8 = a2 + v240 + 492;
    v245 = (unsigned __int16 *)(a2 + v240 + 556);
    if ( *(_WORD *)(a2 + 488) && *(_WORD *)(a2 + 490) )
      sde_kms_rect_intersect(v286, a2 + v240 + 492, a2 + v240 + 556);
    else
      *(_QWORD *)v245 = *(_QWORD *)v8;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "%s: lm%d roi (%d,%d,%d,%d)\n",
        (const char *)(v3 + 2176),
        v241,
        *v245,
        *(unsigned __int16 *)(a2 + v240 + 558),
        *(unsigned __int16 *)(a2 + v240 + 560),
        *(unsigned __int16 *)(a2 + v240 + 562));
    if ( (*(_DWORD *)(a2 + 2048) && (*(_BYTE *)(a2 + 2060) & 8) == 0
       || (((__int64 (__fastcall *)(__int64, __int64, __int64))sde_rm_topology_is_group)(v244 + 2144, a2, 5) & 1) != 0)
      && *(_QWORD *)v245 != *(_QWORD *)v8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64))sde_rm_topology_is_group)(v244 + 2144, a2, 5);
      printk(&unk_234C8D, "_sde_crtc_set_lm_roi");
      goto LABEL_624;
    }
    if ( a2 + v240 == -556 || !*(_WORD *)(a2 + v240 + 560) || !*(_WORD *)(a2 + v240 + 562) )
      *(_QWORD *)v245 = 0;
    v242 = *(unsigned int *)(v3 + 2192);
    ++v241;
    v240 += 8;
  }
  while ( v241 < v242 );
  if ( (*(_BYTE *)(a2 + 483) & 1) != 0 )
    goto LABEL_581;
  if ( (unsigned int)v242 < 2 )
    goto LABEL_585;
  v246 = *(unsigned __int16 *)(a2 + 560);
  if ( !*(_WORD *)(a2 + 560)
    || a2 == -564
    || !*(_WORD *)(a2 + 562)
    || !*(_WORD *)(a2 + 568)
    || !*(_WORD *)(a2 + 570)
    || v246 == *(unsigned __int16 *)(a2 + 568)
    && *(unsigned __int16 *)(a2 + 556) + v246 == *(unsigned __int16 *)(a2 + 564) )
  {
    goto LABEL_585;
  }
  printk(&unk_249027, "_sde_crtc_check_rois_centered_and_symmetric");
LABEL_624:
  LODWORD(v207) = -22;
LABEL_625:
  kfree(v201);
LABEL_626:
  printk(&unk_279FBD, "_sde_crtc_atomic_check");
  v8 = v285;
  LODWORD(v9) = (_DWORD)v207;
LABEL_19:
  kfree(v6);
  kfree(v8);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
