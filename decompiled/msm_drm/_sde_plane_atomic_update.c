__int64 __fastcall sde_plane_atomic_update(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x28
  int v8; // w8
  int v9; // w5
  int v10; // w0
  unsigned int v11; // w0
  char is_crtc_roi_dirty; // w0
  int v13; // w8
  int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned int v17; // w21
  __int64 v18; // x23
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x2
  __int64 (*v23)(void); // x8
  __int64 v24; // x0
  void (*v25)(void); // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 (*v30)(void); // x8
  __int64 v31; // x8
  unsigned int v32; // w21
  __int64 v33; // x8
  __int64 (*v34)(void); // x8
  __int64 v35; // x1
  int v36; // w8
  int wb_usage_type; // w0
  __int64 v38; // x8
  __int64 v39; // x9
  unsigned int v40; // w26
  __int64 v41; // x22
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x23
  int display_id; // w0
  void *v46; // x0
  const char *v47; // x1
  void *v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  int v51; // w8
  __int64 v52; // x25
  __int64 v53; // x10
  void (*v54)(void); // x10
  __int64 v55; // x8
  unsigned int v56; // w21
  __int64 v57; // x26
  __int64 v58; // x8
  _BOOL4 v59; // w24
  __int64 v60; // x0
  __int64 v61; // x25
  unsigned __int64 v62; // x8
  unsigned int v63; // w9
  unsigned __int64 v64; // x11
  unsigned int v65; // w23
  __int64 v66; // x12
  char v67; // w10
  __int64 v68; // x27
  __int64 v69; // x9
  int v70; // w11
  int v71; // w9
  int v72; // w10
  __int16 v73; // w12
  __int16 v74; // w11
  unsigned int disp_op; // w0
  unsigned int v76; // w24
  unsigned int v77; // w23
  __int64 v78; // x9
  int v79; // w10
  int v80; // w8
  unsigned int v81; // w5
  int v82; // w14
  int v83; // w15
  int v84; // w6
  unsigned int v85; // w12
  unsigned int v86; // w11
  unsigned int v87; // w8
  unsigned int v88; // w7
  unsigned int v89; // w10
  unsigned int v90; // w8
  unsigned int v91; // w9
  unsigned int v92; // w11
  unsigned int v93; // w9
  __int64 v94; // x0
  void (*v95)(void); // x8
  void (*v96)(void); // x8
  __int64 v97; // x8
  __int64 v98; // x8
  _DWORD *v99; // x23
  int v100; // w9
  int v101; // w10
  int v102; // w8
  int v103; // w9
  int v104; // w8
  void (*v105)(void); // x8
  __int64 v106; // x0
  void (*v107)(void); // x8
  __int64 v108; // x8
  __int64 v109; // x8
  __int64 v110; // x8
  void (*v111)(void); // x8
  void (*v112)(void); // x8
  void (*v113)(void); // x8
  void (*v114)(void); // x8
  void (*v115)(void); // x8
  int v116; // w9
  void (*v117)(void); // x8
  _BOOL4 v118; // w9
  int v119; // w23
  __int64 v120; // x9
  __int64 v121; // x21
  void (*v122)(void); // x8
  __int64 v123; // x8
  bool v124; // w8
  void (*v125)(void); // x8
  char ***v126; // x8
  char v127; // w9
  __int64 v128; // x0
  void (*v129)(void); // x8
  void (*v130)(void); // x8
  void (*v131)(void); // x8
  void (*v132)(void); // x8
  unsigned int v133; // w10
  __int64 v134; // x8
  __int64 v135; // x8
  __int64 v136; // x23
  __int64 v137; // x8
  __int64 v138; // x24
  __int64 v139; // x9
  __int64 v140; // x25
  void (*v141)(void); // x8
  __int64 v142; // x9
  __int64 v143; // x0
  void (*v144)(void); // x8
  __int64 v145; // x9
  __int64 v146; // x0
  void (*v147)(void); // x8
  __int64 v148; // x8
  __int64 v149; // x0
  void (*v150)(void); // x9
  __int64 v151; // x21
  __int64 blob; // x2
  __int64 v153; // x0
  _DWORD *v154; // x9
  __int64 v155; // x2
  __int64 v156; // x0
  void (__fastcall *v157)(__int64, __int64, __int64); // x9
  __int64 v158; // x2
  __int64 v159; // x0
  void (__fastcall *v160)(__int64, __int64, __int64); // x9
  __int64 v161; // x8
  int v162; // w8
  __int64 v163; // x0
  void (*v164)(void); // x8
  __int64 v165; // x0
  __int64 v166; // x8
  void (__fastcall *v167)(__int64, char *); // x9
  __int64 v168; // x0
  __int64 v169; // x8
  __int64 v170; // x2
  void (__fastcall *v171)(__int64, char *, __int64); // x9
  __int64 v172; // x0
  __int64 v173; // x8
  __int64 v174; // x2
  void (__fastcall *v175)(__int64, char *, __int64); // x9
  __int64 v176; // x0
  __int64 v177; // x8
  void (*v178)(void); // x9
  __int64 v179; // x0
  __int64 v180; // x8
  __int64 v181; // x1
  void (__fastcall *v182)(__int64, __int64, char *); // x9
  __int64 v183; // x0
  __int64 v184; // x8
  __int64 v185; // x1
  void (__fastcall *v186)(__int64, __int64, char *); // x9
  __int64 v187; // x0
  bool v188; // w8
  void (*v189)(void); // x9
  __int64 v190; // x0
  int v191; // w8
  void (*v192)(void); // x9
  __int64 v193; // x0
  int v194; // w8
  void (*v195)(void); // x9
  __int64 v196; // x0
  __int64 v197; // x8
  __int64 v198; // x1
  void (__fastcall *v199)(__int64, __int64, char *); // x9
  __int64 v200; // x0
  bool v201; // w8
  void (*v202)(void); // x9
  __int64 v203; // x0
  bool v204; // w9
  void (*v205)(void); // x8
  __int64 v206; // x0
  __int64 v207; // x9
  unsigned int v208; // w9
  void (*v209)(void); // x8
  __int64 v210; // x8
  __int64 v211; // x0
  __int64 v212; // x21
  __int64 v213; // x24
  int v214; // w9
  void (*v215)(void); // x8
  __int64 v216; // x8
  unsigned int v217; // w27
  unsigned int v218; // w0
  __int64 v219; // x25
  int v220; // w23
  __int64 v221; // x8
  __int64 v222; // x10
  __int64 v223; // x9
  int v224; // w28
  __int64 sde_format_ext; // x0
  char v226; // w8
  __int64 v227; // x24
  int v228; // w26
  __int64 v229; // x8
  int v230; // w8
  unsigned int v231; // w8
  int v232; // w9
  __int64 v233; // x8
  int v234; // w8
  int v235; // w8
  __int64 v236; // x8
  __int64 v237; // x9
  __int64 v238; // x21
  __int64 v239; // x5
  __int64 v240; // x6
  __int64 (*v241)(void); // x8
  __int64 v242; // x8
  int v243; // w7
  __int64 v244; // x8
  _DWORD *v245; // x21
  __int64 v246; // x8
  __int64 *v247; // x0
  int v248; // w0
  int v249; // w0
  int v250; // w22
  _DWORD *payload_addr; // x23
  unsigned int size; // w0
  __int64 v253; // x8
  __int64 (__fastcall *v254)(__int64, __int64, __int64); // x8
  char v255; // [xsp+0h] [xbp-1E0h]
  int v256; // [xsp+58h] [xbp-188h]
  int v257; // [xsp+58h] [xbp-188h]
  int v258; // [xsp+5Ch] [xbp-184h]
  int v259; // [xsp+5Ch] [xbp-184h]
  __int64 v260; // [xsp+60h] [xbp-180h]
  __int16 v261; // [xsp+6Ch] [xbp-174h]
  __int16 v262; // [xsp+70h] [xbp-170h]
  _BOOL4 v263; // [xsp+74h] [xbp-16Ch]
  __int64 v264; // [xsp+78h] [xbp-168h]
  unsigned __int64 v265; // [xsp+80h] [xbp-160h]
  unsigned __int64 v266; // [xsp+88h] [xbp-158h]
  __int64 v267; // [xsp+90h] [xbp-150h]
  int v268; // [xsp+9Ch] [xbp-144h]
  int v269; // [xsp+A0h] [xbp-140h]
  unsigned int v270; // [xsp+A4h] [xbp-13Ch]
  unsigned int v271; // [xsp+A4h] [xbp-13Ch]
  __int64 v272; // [xsp+A8h] [xbp-138h]
  unsigned int v273; // [xsp+B4h] [xbp-12Ch]
  unsigned int v274; // [xsp+B4h] [xbp-12Ch]
  _QWORD *cmd_buf; // [xsp+B8h] [xbp-128h]
  __int64 v276; // [xsp+C0h] [xbp-120h]
  __int64 v277; // [xsp+C8h] [xbp-118h] BYREF
  bool v278; // [xsp+D0h] [xbp-110h] BYREF
  bool v279; // [xsp+D4h] [xbp-10Ch] BYREF
  bool v280; // [xsp+D8h] [xbp-108h] BYREF
  bool v281; // [xsp+DCh] [xbp-104h] BYREF
  __int64 v282; // [xsp+E0h] [xbp-100h] BYREF
  __int16 *v283; // [xsp+E8h] [xbp-F8h] BYREF
  int v284; // [xsp+F0h] [xbp-F0h]
  int v285; // [xsp+F4h] [xbp-ECh]
  __int128 v286; // [xsp+F8h] [xbp-E8h] BYREF
  __int64 v287; // [xsp+108h] [xbp-D8h]
  __int64 v288; // [xsp+110h] [xbp-D0h]
  __int64 v289; // [xsp+118h] [xbp-C8h]
  __int64 v290; // [xsp+120h] [xbp-C0h]
  __int64 v291; // [xsp+128h] [xbp-B8h]
  __int64 v292; // [xsp+130h] [xbp-B0h]
  __int64 v293; // [xsp+138h] [xbp-A8h]
  __int64 v294; // [xsp+140h] [xbp-A0h]
  __int64 v295; // [xsp+148h] [xbp-98h]
  __int64 v296; // [xsp+150h] [xbp-90h]
  __int64 v297; // [xsp+158h] [xbp-88h]
  __int64 v298; // [xsp+160h] [xbp-80h]
  __int64 v299; // [xsp+168h] [xbp-78h]
  __int64 v300; // [xsp+170h] [xbp-70h]
  __int64 v301; // [xsp+178h] [xbp-68h]
  __int64 v302; // [xsp+180h] [xbp-60h]
  __int64 v303; // [xsp+188h] [xbp-58h]
  __int64 v304; // [xsp+190h] [xbp-50h]
  __int64 v305; // [xsp+198h] [xbp-48h]
  __int64 v306; // [xsp+1A0h] [xbp-40h]
  __int64 v307; // [xsp+1A8h] [xbp-38h]
  __int64 v308; // [xsp+1B0h] [xbp-30h]
  __int64 v309; // [xsp+1B8h] [xbp-28h]
  __int64 v310; // [xsp+1C0h] [xbp-20h]
  __int64 v311; // [xsp+1C8h] [xbp-18h]
  __int64 v312; // [xsp+1D0h] [xbp-10h]

  v312 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = printk(&unk_226FC0, "_sde_plane_atomic_update");
    goto LABEL_542;
  }
  v2 = *(_QWORD *)(a1 + 1768);
  if ( !v2 )
  {
    result = printk(&unk_23C088, "_sde_plane_atomic_update");
    goto LABEL_542;
  }
  *(_BYTE *)(a1 + 2380) = 0;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(a1 + 104));
  if ( !*(_QWORD *)(v2 + 16) || !*(_QWORD *)(v2 + 8) )
  {
    if ( *(_QWORD *)a1 && (v16 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
      v17 = *(_DWORD *)(v16 + 5912);
    else
      v17 = 0;
    v18 = *(_QWORD *)(a1 + 1768);
    v287 = 0;
    v288 = 0;
    *((_QWORD *)&v286 + 1) = 0;
    if ( !v18 )
    {
      v46 = &unk_23C088;
      v47 = "_sde_plane_atomic_disable";
      goto LABEL_481;
    }
    if ( !a2 )
    {
      v46 = &unk_24CD82;
      v47 = "_sde_plane_atomic_disable";
      goto LABEL_481;
    }
    v19 = *(unsigned int *)(a2 + 1648);
    if ( *(_DWORD *)(v18 + 1456) == 5 )
    {
      v20 = *(_QWORD *)(a2 + 8);
      if ( v20 )
      {
        BYTE4(v288) = *(_BYTE *)(a1 + 2388);
        sde_cp_set_skip_blend_plane_info(v20, (char *)&v286 + 8);
        sde_crtc_disable_cp_features();
      }
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_plane_atomic_disable",
      4188,
      -1,
      *(_DWORD *)(a1 + 104),
      *(unsigned __int8 *)(a1 + 2388),
      *(_DWORD *)(v18 + 1780),
      -1059143953,
      v255);
    *(_DWORD *)(v18 + 2744) = 0;
    *(_BYTE *)(v18 + 1785) = 1;
    result = *(_QWORD *)(a1 + 2208);
    if ( *(_BYTE *)(a1 + 2388) )
      v22 = 2;
    else
      v22 = 1;
    if ( result )
    {
      if ( v17 > 2 )
        goto LABEL_550;
      v23 = *(__int64 (**)(void))(result + 8LL * v17 + 280);
      if ( v23 )
      {
        if ( *((_DWORD *)v23 - 1) != -567973718 )
          __break(0x8228u);
        result = v23();
      }
    }
    if ( !v19 )
      goto LABEL_534;
    v24 = *(_QWORD *)(a1 + 2208);
    if ( v24 )
    {
      if ( v17 > 2 )
        goto LABEL_550;
      v25 = *(void (**)(void))(v24 + 8LL * v17 + 1312);
      if ( v25 )
      {
        if ( *((_DWORD *)v25 - 1) != 1253086170 )
          __break(0x8228u);
        v25();
      }
    }
    v26 = *(_QWORD *)(a1 + 1768);
    if ( v26 )
    {
      v27 = *(_QWORD *)(v26 + 8);
      if ( v27 || (v27 = *(_QWORD *)(a2 + 8)) != 0 )
      {
        if ( v27 == -2200 )
        {
          _drm_err("invalid mixer %pK\n", 0);
        }
        else
        {
          result = *(_QWORD *)(v27 + 2208);
          if ( result )
          {
            if ( *(_QWORD *)a1 && (v28 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
            {
              v29 = *(unsigned int *)(v28 + 5912);
              if ( (unsigned int)v29 >= 3 )
                goto LABEL_550;
              v30 = *(__int64 (**)(void))(result + 8 * v29 + 1048);
              if ( !v30 )
              {
                if ( (_DWORD)v29 )
                  goto LABEL_534;
                goto LABEL_211;
              }
            }
            else
            {
              v30 = *(__int64 (**)(void))(result + 1048);
              if ( !v30 )
              {
LABEL_211:
                v46 = &unk_253F09;
                v47 = "sde_plane_ctl_flush";
                goto LABEL_481;
              }
            }
            if ( *((_DWORD *)v30 - 1) != -1048210508 )
              __break(0x8228u);
            result = v30();
            goto LABEL_534;
          }
        }
      }
      else
      {
        _drm_err("Invalid drm_crtc %pK\n", 0);
      }
    }
    else
    {
      _drm_err("Invalid plane state %pK\n", 0);
    }
    v46 = &unk_27D28A;
    v47 = "sde_plane_ctl_flush";
    goto LABEL_481;
  }
  v5 = *(_QWORD *)(a1 + 1768);
  if ( !v5 )
  {
    result = printk(&unk_23C088, "sde_plane_sspp_atomic_update");
    __break(0x800u);
    goto LABEL_534;
  }
  if ( !a2 )
  {
    result = printk(&unk_24CD82, "sde_plane_sspp_atomic_update");
    __break(0x800u);
    goto LABEL_534;
  }
  v7 = *(_QWORD *)(v5 + 8);
  v6 = *(_QWORD *)(v5 + 16);
  if ( !v7 || !v6 )
  {
    result = printk(&unk_26CF72, "sde_plane_sspp_atomic_update");
    __break(0x800u);
    goto LABEL_534;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "plane%d sspp:%dx%d/%4.4s/%llx/%dx%d+%d+%d/%x crtc:%dx%d+%d+%d\n",
      *(_DWORD *)(a1 + 104),
      *(_DWORD *)(v6 + 128),
      *(_DWORD *)(v6 + 132),
      *(const char **)(v6 + 72),
      *(_QWORD *)(v6 + 120),
      *(unsigned __int16 *)(v5 + 62),
      *(unsigned __int16 *)(v5 + 58),
      *(unsigned __int16 *)(v5 + 50),
      *(unsigned __int16 *)(v5 + 54),
      *(_DWORD *)(v5 + 2740),
      *(_DWORD *)(v5 + 40),
      *(_DWORD *)(v5 + 44),
      *(_DWORD *)(v5 + 32),
      *(_DWORD *)(v5 + 36));
  if ( *(_DWORD *)(v5 + 1800) )
  {
    v8 = *(_DWORD *)(v5 + 1968);
    if ( v8 )
      *(_DWORD *)(a1 + 2420) = v8;
  }
  if ( *(_BYTE *)(a1 + 2416) == 1 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "plane:%d - reconfigure all the parameters\n", *(_DWORD *)(a1 + 104));
    if ( !*(_DWORD *)(v5 + 1968) && *(_DWORD *)(v5 + 1800) )
    {
      v9 = *(_DWORD *)(a1 + 2420);
      v10 = sde_dbg_base_evtlog;
      *(_DWORD *)(v5 + 1968) = v9;
      sde_evtlog_log(v10, "_sde_plane_check_lut_dirty", 4029, -1, *(_DWORD *)(a1 + 104), v9, 60333, -1059143953, v255);
    }
    *(_DWORD *)(v5 + 1772) = -1;
    *(_BYTE *)(a1 + 2416) = 0;
  }
  mutex_lock(a1 + 3424);
  v11 = msm_property_pop_dirty(a1 + 3344, v5 + 176);
  if ( (v11 & 0x80000000) == 0 )
  {
    while ( v11 < 0x30 )
    {
      *(_DWORD *)(v5 + 1772) |= *((_DWORD *)&plane_prop_array + v11);
      v11 = msm_property_pop_dirty(a1 + 3344, v5 + 176);
      if ( (v11 & 0x80000000) != 0 )
        goto LABEL_26;
    }
    goto LABEL_550;
  }
LABEL_26:
  mutex_unlock(a1 + 3424);
  sde_plane_sspp_atomic_check_mode_changed(a1, v5, a2);
  is_crtc_roi_dirty = sde_crtc_is_crtc_roi_dirty(*(_QWORD **)(v7 + 2008));
  v13 = *(_DWORD *)(v5 + 1772);
  if ( (is_crtc_roi_dirty & 1) != 0 )
  {
    v14 = v13 | 1;
    *(_DWORD *)(v5 + 1772) = v14;
    if ( (v14 & 1) != 0 )
      goto LABEL_28;
LABEL_67:
    v15 = *(_QWORD *)a1;
    if ( !*(_QWORD *)a1 )
      goto LABEL_70;
    goto LABEL_68;
  }
  if ( (v13 & 1) == 0 )
    goto LABEL_67;
LABEL_28:
  *(_QWORD *)(a1 + 2320) = 0;
  *(_QWORD *)(a1 + 2312) = 0;
  *(_QWORD *)(a1 + 2304) = 0;
  *(_QWORD *)(a1 + 2296) = 0;
  *(_QWORD *)(a1 + 2288) = 0;
  *(_QWORD *)(a1 + 2280) = 0;
  *(_QWORD *)(a1 + 2272) = 0;
  *(_QWORD *)(a1 + 2264) = 0;
  *(_QWORD *)(a1 + 2256) = 0;
  *(_QWORD *)(a1 + 2248) = 0;
  *(_QWORD *)(a1 + 2240) = 0;
  *(_QWORD *)(a1 + 2232) = 0;
  *(_QWORD *)(a1 + 2224) = 0;
  *(_QWORD *)(a1 + 2216) = 0;
  v15 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_70;
LABEL_68:
  v31 = *(_QWORD *)(v15 + 56);
  if ( v31 )
  {
    v32 = *(_DWORD *)(v31 + 5912);
    goto LABEL_71;
  }
LABEL_70:
  v32 = 0;
LABEL_71:
  result = sde_plane_get_scanout_info(a1, v5, v6, a1 + 2216);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result == -11 )
    {
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(0, 0, 0, "plane%d not updating same src addrs\n", *(_DWORD *)(a1 + 104));
    }
    else
    {
      result = printk(&unk_2503F1, "_sde_plane_set_scanout");
      *(_BYTE *)(a1 + 2380) = 1;
    }
  }
  else
  {
    if ( v32 >= 3 )
      goto LABEL_550;
    v33 = *(_QWORD *)(a1 + 2208);
    if ( *(_QWORD *)(v33 + 8LL * v32 + 184) )
    {
      if ( v33 )
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_plane_set_scanout",
          964,
          4,
          *(_DWORD *)(v33 + 48),
          *(_DWORD *)(a1 + 2228),
          *(_DWORD *)(a1 + 2232),
          *(_DWORD *)(a1 + 2240),
          *(_DWORD *)(a1 + 2256));
        v34 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * v32 + 184);
        if ( *((_DWORD *)v34 - 1) != -1599035892 )
          __break(0x8228u);
        result = v34();
      }
      else
      {
        result = printk(&unk_243203, "_sde_plane_set_scanout");
      }
    }
  }
  v35 = *(_QWORD *)(v7 + 2008);
  if ( v35 )
  {
    result = sde_crtc_get_intf_mode((__int64 *)v7, v35);
    v36 = result != 4;
  }
  else
  {
    v36 = 1;
  }
  if ( *(unsigned __int8 *)(a1 + 2381) != v36 || (*(_BYTE *)(*(_QWORD *)(v7 + 2008) + 10LL) & 2) != 0 )
  {
    *(_BYTE *)(a1 + 2381) = v36;
    if ( (v36 & 1) != 0 )
      wb_usage_type = 0;
    else
      wb_usage_type = sde_crtc_get_wb_usage_type((__int64 *)v7);
    *(_DWORD *)(a1 + 2384) = wb_usage_type;
    *(_DWORD *)(v5 + 1772) |= 0x200u;
LABEL_96:
    *(_BYTE *)(v5 + 1785) = 1;
    ((void (__fastcall *)(__int64, _QWORD, __int64))sde_plane_set_qos_ctrl)(a1, 0, 4);
    v38 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 && (v39 = *(_QWORD *)(v38 + 56)) != 0 )
    {
      v40 = *(_DWORD *)(v39 + 5912);
      v41 = *(_QWORD *)(a1 + 1768);
      if ( !v41 )
      {
LABEL_99:
        result = printk(&unk_212AA9, "_sde_plane_update_properties");
        goto LABEL_534;
      }
    }
    else
    {
      v40 = 0;
      v41 = *(_QWORD *)(a1 + 1768);
      if ( !v41 )
        goto LABEL_99;
    }
    v276 = v6;
    if ( v40 != 1 )
    {
      cmd_buf = nullptr;
      goto LABEL_119;
    }
    if ( v38
      && (v42 = *(_QWORD *)(v38 + 56)) != 0
      && (v43 = *(_QWORD *)(v42 + 8)) != 0
      && (v44 = *(_QWORD *)(v43 + 6440)) != 0 )
    {
      display_id = hfi_crtc_get_display_id(*(__int64 **)(v41 + 8), *(_QWORD *)(*(_QWORD *)(v41 + 8) + 2008LL));
      if ( display_id != -1 )
      {
        cmd_buf = hfi_kms_get_cmd_buf(v44, display_id, 1);
        if ( cmd_buf )
          goto LABEL_117;
        goto LABEL_116;
      }
      v48 = &unk_231479;
    }
    else
    {
      v48 = &unk_24C638;
    }
    printk(v48, "_sde_plane_get_cmd_buf");
LABEL_116:
    printk(&unk_2389B5, "_sde_plane_update_properties");
    cmd_buf = nullptr;
LABEL_117:
    v49 = *(_QWORD *)(a1 + 4272);
    v6 = v276;
    if ( v49 )
      hfi_util_u32_prop_helper_reset(*(unsigned int **)(v49 + 72));
LABEL_119:
    v50 = msm_framebuffer_format(v6);
    if ( !v50 )
    {
      result = printk(&unk_219E1C, "_sde_plane_update_properties");
      goto LABEL_534;
    }
    v51 = *(_DWORD *)(v41 + 1772);
    v52 = v50;
    if ( (v51 & 0x10) != 0 )
    {
      v53 = *(_QWORD *)a1;
      if ( *(_QWORD *)a1 )
      {
        v53 = *(_QWORD *)(v53 + 56);
        if ( v53 )
        {
          LODWORD(v53) = *(_DWORD *)(v53 + 5912);
          if ( (unsigned int)v53 >= 3 )
            goto LABEL_550;
        }
      }
      v54 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * (unsigned int)v53 + 832);
      if ( v54 )
      {
        if ( *((_DWORD *)v54 - 1) != 1128212908 )
          __break(0x822Au);
        v54();
        v51 = *(_DWORD *)(v41 + 1772);
      }
    }
    if ( (v51 & 1) == 0 )
    {
LABEL_247:
      if ( (v51 & 3) != 0 )
      {
        if ( v40 >= 3 )
          goto LABEL_550;
        if ( *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8LL * v40 + 64) )
        {
          v119 = *(_DWORD *)(v41 + 1648);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "plane%d rotation 0x%X\n", *(_DWORD *)(a1 + 104), *(_DWORD *)(v41 + 2740));
          if ( *(_QWORD *)a1 && (v120 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
          {
            v121 = *(unsigned int *)(v120 + 5912);
            if ( (unsigned int)v121 > 2 )
              goto LABEL_550;
          }
          else
          {
            v121 = 0;
          }
          v122 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v121 + 64);
          if ( *((_DWORD *)v122 - 1) != 563136525 )
            __break(0x8228u);
          v122();
          if ( *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v121 + 808) )
          {
            *(_QWORD *)(v41 + 2752) = 0;
            *(_BYTE *)(v41 + 2752) = *(_BYTE *)(*(_QWORD *)(a1 + 2408) + 21840LL);
            if ( *(_DWORD *)(v52 + 28) == 2 )
              v123 = (*(_QWORD *)(v52 + 32) >> 2) & 1LL;
            else
              LOBYTE(v123) = 0;
            *(_BYTE *)(v41 + 2753) = v123;
            v124 = *(_DWORD *)(v52 + 28) == 2
                && ((*(_QWORD *)(v52 + 32) & 4) != 0 || (*(_QWORD *)(v52 + 32) & 4LL) == 0);
            *(_BYTE *)(v41 + 2754) = v124;
            *(_DWORD *)(v41 + 2756) = 1;
            v125 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v121 + 808);
            if ( *((_DWORD *)v125 - 1) != 883781891 )
              __break(0x8228u);
            v125();
          }
          ((void (__fastcall *)(__int64, __int64))sde_plane_sspp_setup_sys_cache)(a1, v41);
          if ( (*(_QWORD *)(v52 + 32) & 1) != 0 )
          {
            v126 = *(char ****)(v41 + 2904);
            if ( !v126 )
            {
              if ( (*(_BYTE *)(a1 + 1936) & 0x20) != 0 )
                v126 = (char ***)&sde_plane_setup_csc_sde_csc10_YUV2RGB_601L;
              else
                v126 = &sde_plane_setup_csc_sde_csc_YUV2RGB_601L;
            }
            v127 = _drm_debug;
            *(_QWORD *)(v41 + 2912) = v126;
            if ( (v127 & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "plane%d using 0x%X 0x%X 0x%X...\n",
                *(_DWORD *)(a1 + 104),
                *(_DWORD *)v126,
                *((_DWORD *)v126 + 1),
                *((_DWORD *)v126 + 2));
          }
          else
          {
            *(_QWORD *)(v41 + 2912) = 0;
          }
          v128 = *(_QWORD *)(a1 + 2208);
          v129 = *(void (**)(void))(v128 + 8 * v121 + 880);
          if ( v129 )
          {
            if ( *((_DWORD *)v129 - 1) != 131456006 )
              __break(0x8228u);
            v129();
            v128 = *(_QWORD *)(a1 + 2208);
          }
          v130 = *(void (**)(void))(v128 + 8 * v121 + 904);
          if ( v130 )
          {
            if ( *((_DWORD *)v130 - 1) != 1467308540 )
              __break(0x8228u);
            v130();
            v128 = *(_QWORD *)(a1 + 2208);
          }
          v131 = *(void (**)(void))(v128 + 8 * v121 + 1048);
          if ( v131 )
          {
            if ( *((_DWORD *)v131 - 1) != -784115885 )
              __break(0x8228u);
            v131();
          }
          v132 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v121 + 1312);
          if ( v132 )
          {
            if ( v119 == 8 && (unsigned int)(*(_DWORD *)(a1 + 1928) - 1) < 8 )
            {
              v133 = *(_DWORD *)(*(_QWORD *)(a1 + 3320) + 4LL * *(unsigned __int8 *)(a1 + 2388) + 1316);
              if ( v133 > 0xC || *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 6960LL + 96LL * v133 + 88) > 0xCu )
                goto LABEL_550;
            }
            if ( *((_DWORD *)v132 - 1) != 1253086170 )
              __break(0x8228u);
            v132();
          }
        }
      }
      v134 = *(_QWORD *)(a1 + 1768);
      v286 = 0u;
      v285 = 0;
      v284 = 0;
      v282 = 0;
      v283 = nullptr;
      v310 = 0;
      v311 = 0;
      v308 = 0;
      v309 = 0;
      v306 = 0;
      v307 = 0;
      v304 = 0;
      v305 = 0;
      v302 = 0;
      v303 = 0;
      v300 = 0;
      v301 = 0;
      v298 = 0;
      v299 = 0;
      v296 = 0;
      v297 = 0;
      v294 = 0;
      v295 = 0;
      v292 = 0;
      v293 = 0;
      v290 = 0;
      v291 = 0;
      v288 = 0;
      v289 = 0;
      v287 = 0;
      if ( v134 )
      {
        v135 = *(_QWORD *)(v134 + 8);
        if ( v135 )
        {
          v136 = *(_QWORD *)(v135 + 2208);
LABEL_305:
          v137 = *(_QWORD *)a1;
          v281 = 0;
          v280 = 0;
          v279 = 0;
          v278 = 0;
          v277 = 0;
          if ( v137 )
          {
            v137 = *(_QWORD *)(v137 + 56);
            if ( v137 )
              LODWORD(v137) = *(_DWORD *)(v137 + 5912);
          }
          v138 = *(_QWORD *)(a1 + 1768);
          *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 28LL) = v137;
          if ( v138 )
            v139 = *(_QWORD *)(v138 + 944);
          else
            LODWORD(v139) = 0;
          DWORD1(v286) = v139;
          if ( (unsigned int)v137 > 2 )
            goto LABEL_550;
          v140 = (unsigned int)v137;
          v141 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * (unsigned int)v137 + 328);
          if ( v141 )
          {
            if ( *((_DWORD *)v141 - 1) != 1832876744 )
              __break(0x8228u);
            v141();
          }
          if ( v138 )
            v142 = *(_QWORD *)(v138 + 976);
          else
            LODWORD(v142) = 0;
          v143 = *(_QWORD *)(a1 + 2208);
          LODWORD(v286) = v142;
          v144 = *(void (**)(void))(v143 + 8 * v140 + 352);
          if ( v144 )
          {
            if ( *((_DWORD *)v144 - 1) != 1832876744 )
              __break(0x8228u);
            v144();
          }
          if ( v138 )
            v145 = *(_QWORD *)(v138 + 1008);
          else
            LODWORD(v145) = 0;
          v146 = *(_QWORD *)(a1 + 2208);
          v285 = v145;
          v147 = *(void (**)(void))(v146 + 8 * v140 + 376);
          if ( v147 )
          {
            if ( *((_DWORD *)v147 - 1) != 1832876744 )
              __break(0x8228u);
            v147();
          }
          if ( v138 )
            v148 = *(_QWORD *)(v138 + 1040);
          else
            LODWORD(v148) = 0;
          v149 = *(_QWORD *)(a1 + 2208);
          v284 = v148;
          v150 = *(void (**)(void))(v149 + 8 * v140 + 400);
          if ( v150 )
          {
            if ( *((_DWORD *)v150 - 1) != 1832876744 )
              __break(0x8229u);
            v150();
            v149 = *(_QWORD *)(a1 + 2208);
          }
          if ( *(_QWORD *)(v149 + 8 * v140 + 424) )
          {
            v151 = 8 * v140;
            blob = msm_property_get_blob(a1 + 3344, v138 + 176, &v283);
            v153 = *(_QWORD *)(a1 + 2208);
            v154 = *(_DWORD **)(v153 + 8 * v140 + 424);
            if ( *(v154 - 1) != -1985177877 )
              __break(0x8229u);
            ((void (__fastcall *)(__int64, _QWORD, __int64))v154)(v153, 0, blob);
            v155 = msm_property_get_blob(a1 + 3344, v138 + 176, &v283);
            v156 = *(_QWORD *)(a1 + 2208);
            v157 = *(void (__fastcall **)(__int64, __int64, __int64))(v156 + v151 + 424);
            if ( *((_DWORD *)v157 - 1) != -1985177877 )
              __break(0x8229u);
            v157(v156, 1, v155);
            v158 = msm_property_get_blob(a1 + 3344, v138 + 176, &v283);
            v159 = *(_QWORD *)(a1 + 2208);
            v160 = *(void (__fastcall **)(__int64, __int64, __int64))(v159 + v151 + 424);
            if ( *((_DWORD *)v160 - 1) != -1985177877 )
              __break(0x8229u);
            v160(v159, 2, v158);
          }
          v161 = *(_QWORD *)(a1 + 4272);
          if ( v161 )
          {
            v305 = *(_QWORD *)(v161 + 72);
            HIDWORD(v306) = *(_DWORD *)(v161 + 8);
          }
          v162 = *(_DWORD *)(v138 + 1772);
          if ( (v162 & 0x20) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 448) )
          {
            *((_QWORD *)&v286 + 1) = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v163 = *(_QWORD *)(a1 + 2208);
            v288 = v136;
            LODWORD(v287) = v282;
            LODWORD(v289) = 0;
            LODWORD(v306) = 196865;
            v310 = a1 + 4496;
            v164 = *(void (**)(void))(v163 + 8 * v140 + 448);
            if ( *((_DWORD *)v164 - 1) != 1832876744 )
              __break(0x8228u);
            v164();
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x40) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 472) )
          {
            v165 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v166 = *(_QWORD *)(a1 + 2208);
            LODWORD(v289) = 0;
            LODWORD(v287) = v282;
            v288 = v136;
            *((_QWORD *)&v286 + 1) = v165;
            v167 = *(void (__fastcall **)(__int64, char *))(v166 + 8 * v140 + 472);
            if ( *((_DWORD *)v167 - 1) != 1832876744 )
              __break(0x8229u);
            v167(v166, (char *)&v286 + 8);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x80) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 496) )
          {
            v168 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v169 = *(_QWORD *)(a1 + 2208);
            LODWORD(v289) = 0;
            v170 = *(unsigned int *)(v138 + 1776);
            LODWORD(v287) = v282;
            v288 = v136;
            *((_QWORD *)&v286 + 1) = v168;
            v171 = *(void (__fastcall **)(__int64, char *, __int64))(v169 + 8 * v140 + 496);
            if ( *((_DWORD *)v171 - 1) != 1508531544 )
              __break(0x8229u);
            v171(v169, (char *)&v286 + 8, v170);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x100) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 520) )
          {
            v172 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v173 = *(_QWORD *)(a1 + 2208);
            LODWORD(v289) = 0;
            v174 = *(unsigned int *)(v138 + 1776);
            LODWORD(v287) = v282;
            v288 = v136;
            *((_QWORD *)&v286 + 1) = v172;
            v175 = *(void (__fastcall **)(__int64, char *, __int64))(v173 + 8 * v140 + 520);
            if ( *((_DWORD *)v175 - 1) != 1508531544 )
              __break(0x8229u);
            v175(v173, (char *)&v286 + 8, v174);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x400) != 0 )
          {
            v176 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v176 + 1120 + 8 * v140) )
            {
              if ( v138 )
                v177 = *(_QWORD *)(v138 + 1264);
              else
                v177 = 0;
              LODWORD(v289) = 0;
              v288 = v136;
              LODWORD(v287) = 1;
              *((_QWORD *)&v286 + 1) = &v281;
              v178 = *(void (**)(void))(v176 + 1120 + 8 * v140);
              v281 = v177 != 0;
              if ( *((_DWORD *)v178 - 1) != -775547049 )
                __break(0x8229u);
              v178();
              v162 = *(_DWORD *)(v138 + 1772);
            }
          }
          if ( (v162 & 0x800) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 1096) )
          {
            v179 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v180 = *(_QWORD *)(a1 + 2208);
            LODWORD(v289) = 0;
            v181 = *(unsigned int *)(v138 + 1776);
            LODWORD(v287) = v282;
            v288 = v136;
            *((_QWORD *)&v286 + 1) = v179;
            v182 = *(void (__fastcall **)(__int64, __int64, char *))(v180 + 8 * v140 + 1096);
            if ( *((_DWORD *)v182 - 1) != -775547049 )
              __break(0x8229u);
            v182(v180, v181, (char *)&v286 + 8);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x1000) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 1072) )
          {
            v183 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v184 = *(_QWORD *)(a1 + 2208);
            LODWORD(v289) = 0;
            v185 = *(unsigned int *)(v138 + 1776);
            LODWORD(v287) = v282;
            v288 = v136;
            *((_QWORD *)&v286 + 1) = v183;
            v186 = *(void (__fastcall **)(__int64, __int64, char *))(v184 + 8 * v140 + 1072);
            if ( *((_DWORD *)v186 - 1) != -775547049 )
              __break(0x8229u);
            v186(v184, v185, (char *)&v286 + 8);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x2000) != 0 )
          {
            v187 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v187 + 1144 + 8 * v140) )
            {
              if ( v138 )
                v188 = *(_QWORD *)(v138 + 1296) != 0;
              else
                v188 = 0;
              LODWORD(v289) = 0;
              v288 = v136;
              LODWORD(v287) = 1;
              *((_QWORD *)&v286 + 1) = &v280;
              v189 = *(void (**)(void))(v187 + 1144 + 8 * v140);
              v280 = v188;
              if ( *((_DWORD *)v189 - 1) != -775547049 )
                __break(0x8229u);
              v189();
              v162 = *(_DWORD *)(v138 + 1772);
            }
          }
          if ( (v162 & 0x4000) != 0 )
          {
            v190 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v190 + 1240 + 8 * v140) )
            {
              if ( v138 )
                v191 = *(_DWORD *)(v138 + 1584);
              else
                v191 = 0;
              v288 = v136;
              LODWORD(v287) = 4;
              *((_QWORD *)&v286 + 1) = &v277;
              LODWORD(v289) = 0;
              LODWORD(v306) = 196866;
              v192 = *(void (**)(void))(v190 + 1240 + 8 * v140);
              LODWORD(v277) = v191;
              if ( *((_DWORD *)v192 - 1) != -775547049 )
                __break(0x8229u);
              v192();
              v162 = *(_DWORD *)(v138 + 1772);
            }
          }
          if ( (v162 & 0x8000) != 0 )
          {
            v193 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v193 + 1216 + 8 * v140) )
            {
              if ( v138 )
                v194 = *(_DWORD *)(v138 + 1616);
              else
                v194 = 0;
              v288 = v136;
              LODWORD(v287) = 4;
              *((_QWORD *)&v286 + 1) = (char *)&v277 + 4;
              LODWORD(v289) = 0;
              LODWORD(v306) = 196868;
              v195 = *(void (**)(void))(v193 + 1216 + 8 * v140);
              HIDWORD(v277) = v194;
              if ( *((_DWORD *)v195 - 1) != -775547049 )
                __break(0x8229u);
              v195();
              v162 = *(_DWORD *)(v138 + 1772);
            }
          }
          if ( (v162 & 0x10000) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8 * v140 + 1192) )
          {
            v196 = msm_property_get_blob(a1 + 3344, v138 + 176, &v282);
            v197 = *(_QWORD *)(a1 + 2208);
            v288 = v136;
            v198 = *(unsigned int *)(v138 + 1776);
            LODWORD(v287) = v282;
            *((_QWORD *)&v286 + 1) = v196;
            LODWORD(v289) = 0;
            LODWORD(v306) = 196870;
            v199 = *(void (__fastcall **)(__int64, __int64, char *))(v197 + 8 * v140 + 1192);
            if ( *((_DWORD *)v199 - 1) != -775547049 )
              __break(0x8229u);
            v199(v197, v198, (char *)&v286 + 8);
            v162 = *(_DWORD *)(v138 + 1772);
          }
          if ( (v162 & 0x20000) != 0 )
          {
            v200 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v200 + 1264 + 8 * v140) )
            {
              if ( v138 )
                v201 = *(_QWORD *)(v138 + 1328) != 0;
              else
                v201 = 0;
              v288 = v136;
              LODWORD(v287) = 1;
              *((_QWORD *)&v286 + 1) = &v279;
              LODWORD(v289) = 0;
              LODWORD(v306) = 196867;
              v202 = *(void (**)(void))(v200 + 1264 + 8 * v140);
              v279 = v201;
              if ( *((_DWORD *)v202 - 1) != -775547049 )
                __break(0x8229u);
              v202();
              v162 = *(_DWORD *)(v138 + 1772);
            }
          }
          if ( (v162 & 0x40000) != 0 )
          {
            v203 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v203 + 1288 + 8 * v140) )
            {
              if ( v138 )
                v204 = *(_QWORD *)(v138 + 1360) != 0;
              else
                v204 = 0;
              v288 = v136;
              LODWORD(v287) = 1;
              *((_QWORD *)&v286 + 1) = &v278;
              LODWORD(v289) = 0;
              LODWORD(v306) = 196869;
              v205 = *(void (**)(void))(v203 + 1288 + 8 * v140);
              v278 = v204;
              if ( *((_DWORD *)v205 - 1) != -775547049 )
                __break(0x8228u);
              v205();
            }
          }
          if ( (*(_BYTE *)(v41 + 1772) & 4) != 0 )
          {
            if ( v40 > 2 )
              goto LABEL_550;
            v206 = *(_QWORD *)(a1 + 2208);
            if ( *(_QWORD *)(v206 + 304 + 8LL * v40) )
            {
              if ( *(_QWORD *)a1 && (v207 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
              {
                v208 = *(_DWORD *)(v207 + 5912);
                *(_QWORD *)(a1 + 2328) = 0x7000000020LL;
                *(_QWORD *)(a1 + 2336) = 0x200000008LL;
                if ( v208 >= 3 )
                  goto LABEL_550;
              }
              else
              {
                v208 = 0;
                *(_QWORD *)(a1 + 2328) = 0x7000000020LL;
                *(_QWORD *)(a1 + 2336) = 0x200000008LL;
              }
              v209 = *(void (**)(void))(v206 + 304 + 8LL * v208);
              if ( v209 )
              {
                if ( *((_DWORD *)v209 - 1) != 1379560407 )
                  __break(0x8228u);
                v209();
              }
            }
          }
          if ( (*(_WORD *)(v41 + 1772) & 0x203) != 0 )
          {
            v210 = *(_QWORD *)a1;
            if ( *(_QWORD *)a1 )
            {
              v210 = *(_QWORD *)(v210 + 56);
              if ( v210 )
                LODWORD(v210) = *(_DWORD *)(v210 + 5912);
            }
            v211 = *(_QWORD *)(a1 + 2208);
            if ( v211 && *(_QWORD *)(a1 + 3320) && *(_QWORD *)(a1 + 2408) )
            {
              if ( (unsigned int)v210 >= 3 )
                goto LABEL_550;
              v212 = (unsigned int)v210;
              if ( *(_QWORD *)(v211 + 544 + 8LL * (unsigned int)v210) )
              {
                v213 = *(_QWORD *)(a1 + 1768);
                if ( v213 && ((v214 = *(_DWORD *)(v213 + 1648), v214 == 8) || v214 == 2) )
                {
                  *(_QWORD *)(a1 + 2368) = 0;
                  *(_QWORD *)(a1 + 2360) = 0;
                  *(_QWORD *)(a1 + 2352) = 0;
                  *(_QWORD *)(a1 + 2344) = 0;
                  v215 = *(void (**)(void))(v211 + 544 + 8LL * (unsigned int)v210);
                }
                else
                {
                  v216 = *(_QWORD *)(v7 + 2008);
                  v217 = *(unsigned __int16 *)(v216 + 38);
                  v274 = *(unsigned __int16 *)(v216 + 28);
                  v218 = drm_mode_vrefresh(v7 + 176);
                  v219 = *(_QWORD *)(a1 + 2408);
                  v220 = v218;
                  v260 = v7;
                  v221 = *(unsigned int *)(v219 + 21824);
                  if ( (_DWORD)v221 )
                  {
                    v222 = *(_QWORD *)(v219 + 21832);
                    if ( v222 )
                    {
                      v223 = 0;
                      while ( (_DWORD)v221 - 1 != v223 && v218 > *(_DWORD *)(v222 + 4 * v223) )
                      {
                        if ( v221 == ++v223 )
                        {
                          LODWORD(v223) = *(_DWORD *)(v219 + 21824);
                          break;
                        }
                      }
                    }
                    else
                    {
                      LODWORD(v223) = 0;
                    }
                    v224 = 18 * v223;
                  }
                  else
                  {
                    v224 = 0;
                  }
                  v271 = v40;
                  if ( *(_BYTE *)(a1 + 2381) == 1 )
                  {
                    sde_format_ext = sde_get_sde_format_ext(**(unsigned int **)(v276 + 72), *(_QWORD *)(v276 + 120));
                    v226 = *(_BYTE *)(v213 + 2740);
                    v227 = sde_format_ext;
                    if ( (v226 & 2) != 0 )
                    {
                      v229 = *(_QWORD *)(a1 + 2408);
                      v228 = 10;
                      if ( v229 )
                      {
                        if ( (unsigned int)sde_format_validate_fmt(0, sde_format_ext, *(_QWORD *)(v229 + 22080)) )
                          v228 = 10;
                        else
                          v228 = 12;
                      }
                    }
                    else if ( sde_format_ext && !*(_DWORD *)(sde_format_ext + 28) )
                    {
                      v228 = 0;
                    }
                    else
                    {
                      v228 = 2;
                    }
                  }
                  else
                  {
                    v227 = 0;
                    if ( (*(_DWORD *)(a1 + 2384) & 0xFFFFFFFE) == 2 )
                      v228 = 14;
                    else
                      v228 = 4;
                  }
                  if ( *(_DWORD *)(a1 + 2424) )
                    v230 = v228 + 1;
                  else
                    v230 = v228;
                  *(_QWORD *)(a1 + 2352) = *(_QWORD *)(*(_QWORD *)(v219 + 21816) + 8LL * (unsigned int)(v230 + v224));
                  if ( v274 > v217 )
                  {
                    v231 = *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21596LL);
                    if ( !v231 || (v232 = *(_DWORD *)(v260 + 7876)) == 0 || v231 / (2 * v232) <= 4 )
                      v228 |= 1u;
                  }
                  v233 = 8LL * (unsigned int)(v228 + v224);
                  *(_DWORD *)(a1 + 2344) = *(_DWORD *)(*(_QWORD *)(v219 + 21800) + v233);
                  *(_DWORD *)(a1 + 2348) = *(_DWORD *)(*(_QWORD *)(v219 + 21808) + v233);
                  v7 = v260;
                  v40 = v271;
                  if ( (_drm_debug & 4) != 0 )
                  {
                    if ( v227 )
                      v234 = *(_DWORD *)(v227 + 28);
                    else
                      v234 = -1;
                    _drm_dev_dbg(
                      0,
                      0,
                      0,
                      "plane%u: pnum:%d fmt:%4.4s fps:%d mode:%d lut[0x%x,0x%x 0x%llx] rt:%d type:%d\n",
                      *(_DWORD *)(a1 + 104),
                      *(_DWORD *)(a1 + 1928) - 1,
                      (const char *)v227,
                      v220,
                      v234,
                      *(_DWORD *)(a1 + 2344),
                      *(_DWORD *)(a1 + 2348),
                      *(_QWORD *)(a1 + 2352),
                      *(unsigned __int8 *)(a1 + 2381),
                      *(_DWORD *)(a1 + 2384));
                  }
                  v215 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v212 + 544);
                }
                if ( *((_DWORD *)v215 - 1) != 1653619127 )
                  __break(0x8228u);
                v215();
              }
            }
            else
            {
              printk(&unk_26FEB0, "_sde_plane_set_qos_lut");
            }
          }
          ((void (__fastcall *)(__int64, __int64, __int64))sde_plane_set_qos_ctrl)(a1, 1, 4);
          result = sde_plane_set_ot_limit(a1, v7);
          v235 = *(_DWORD *)(v41 + 1772);
          if ( (v235 & 8) != 0 )
          {
            if ( *(_QWORD *)a1 )
            {
              v236 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
              if ( v236 && *(_QWORD *)(v236 + 8) )
              {
                v237 = *(_QWORD *)(a1 + 2208);
                if ( v237 )
                {
                  v238 = *(unsigned int *)(v236 + 5912);
                  if ( (unsigned int)v238 >= 3 )
                    goto LABEL_550;
                  if ( *(_QWORD *)(v237 + 8 * v238 + 784) )
                  {
                    ((void (__fastcall *)(__int64, _QWORD, __int64))sde_plane_set_qos_ctrl)(a1, 0, 2);
                    v239 = *(_QWORD *)(v41 + 1104);
                    *((_QWORD *)&v286 + 1) = v239;
                    v240 = *(_QWORD *)(v41 + 1136);
                    v287 = v240;
                    if ( (_drm_debug & 4) != 0 )
                    {
                      _drm_dev_dbg(0, 0, 0, "plane%d size:%llu time:%llu\n", *(_DWORD *)(a1 + 104), v239, v240);
                      LODWORD(v239) = DWORD2(v286);
                      LODWORD(v240) = v287;
                    }
                    sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "_sde_plane_set_ts_prefill",
                      649,
                      4,
                      *(_DWORD *)(a1 + 104),
                      v239,
                      v240,
                      -1059143953,
                      v255);
                    v241 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 2208) + 8 * v238 + 784);
                    if ( *((_DWORD *)v241 - 1) != -514320500 )
                      __break(0x8228u);
                    result = v241();
                  }
                }
                else
                {
                  result = printk(&unk_262833, "_sde_plane_set_ts_prefill");
                }
              }
              else
              {
                result = printk(&unk_25EA03, "_sde_plane_set_ts_prefill");
              }
            }
            else
            {
              result = printk(&unk_227A8D, "_sde_plane_set_ts_prefill");
            }
            v235 = *(_DWORD *)(v41 + 1772);
          }
          if ( (v235 & 0x200) != 0 )
            result = sde_plane_set_qos_remap(a1);
          if ( *(_QWORD *)a1 )
          {
            v242 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
            if ( v242 )
            {
              if ( *(_QWORD *)(v41 + 1456) == 5 )
              {
                result = *(_QWORD *)(v242 + 8);
                if ( result )
                {
                  ((void (__fastcall *)(__int64, _QWORD, __int64))sde_vbif_setup_clk_force_ctrl)(
                    result,
                    *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 56LL) + 60LL),
                    1);
                  result = sde_evtlog_log(
                             sde_dbg_base_evtlog,
                             "_sde_plane_update_properties",
                             3972,
                             -1,
                             *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 56LL) + 60LL),
                             1,
                             -1059143953,
                             v243,
                             v255);
                }
              }
            }
          }
          *(_DWORD *)(v41 + 1772) = 0;
          if ( v40 != 1 )
            goto LABEL_534;
          v244 = *(_QWORD *)(a1 + 4272);
          if ( !v244 )
            goto LABEL_534;
          v245 = *(_DWORD **)(v244 + 72);
          result = hfi_util_u32_prop_helper_prop_count((__int64)v245);
          if ( !cmd_buf || !(_DWORD)result )
          {
            if ( (_drm_debug & 4) != 0 )
            {
              v248 = hfi_util_u32_prop_helper_prop_count((__int64)v245);
              result = _drm_dev_dbg(0, 0, 0, "prop_helper_prop_count = %d cmd_buf = %pK\n", v248, cmd_buf);
            }
            goto LABEL_534;
          }
          v246 = *(_QWORD *)(a1 + 1768);
          if ( v246 )
            v247 = *(__int64 **)(v246 + 8);
          else
            v247 = nullptr;
          v249 = hfi_crtc_get_display_id(v247, v247[251]);
          if ( v249 == -1 )
          {
            v46 = &unk_231479;
            v47 = "_sde_plane_update_properties";
          }
          else
          {
            v250 = v249;
            payload_addr = hfi_util_u32_prop_helper_get_payload_addr(v245);
            size = hfi_util_u32_prop_helper_get_size((__int64)v245);
            result = hfi_adapter_add_set_property((__int64)cmd_buf, 33554433, v250, 2u, (__int64)payload_addr, size, 0);
            if ( !(_DWORD)result )
              goto LABEL_534;
            v46 = &unk_25EDC6;
            v47 = "_sde_plane_update_properties";
          }
LABEL_481:
          result = printk(v46, v47);
          goto LABEL_534;
        }
        _drm_err("Invalid drm_crtc %pK\n", 0);
      }
      else
      {
        _drm_err("Invalid plane state %pK\n", 0);
      }
      v136 = 0;
      goto LABEL_305;
    }
    v270 = v40;
    if ( *(_QWORD *)a1 && (v55 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
      v56 = *(_DWORD *)(v55 + 5912);
    else
      v56 = 0;
    v57 = *(_QWORD *)(a1 + 1768);
    *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 28LL) = v56;
    v58 = *(_QWORD *)(a1 + 4272);
    if ( v58 )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 1400LL) = *(_QWORD *)(v58 + 72);
      *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 1408LL) = *(_DWORD *)(*(_QWORD *)(a1 + 4272) + 8LL);
    }
    v283 = nullptr;
    v264 = v52;
    if ( v57 )
      v59 = *(_QWORD *)(v57 + 1648) != 0;
    else
      v59 = 0;
    v60 = msm_framebuffer_format(v6);
    if ( !v60 )
    {
      printk(&unk_219E1C, "_sde_plane_update_roi_config");
LABEL_246:
      v51 = *(_DWORD *)(v41 + 1772);
      v40 = v270;
      goto LABEL_247;
    }
    v61 = v60;
    v268 = *(unsigned __int16 *)(v57 + 36);
    v269 = *(unsigned __int16 *)(v57 + 32);
    v62 = *(unsigned int *)(v57 + 48);
    v63 = *(_DWORD *)(v57 + 52);
    v65 = *(_DWORD *)(v57 + 56);
    v64 = *(unsigned int *)(v57 + 60);
    v267 = *(unsigned __int16 *)(v57 + 40);
    v66 = *(unsigned __int16 *)(v57 + 44);
    *(_WORD *)(a1 + 2304) = *(_WORD *)(v57 + 2928);
    v272 = v66;
    v266 = v62 >> 16;
    *(_WORD *)(a1 + 2306) = *(_WORD *)(v57 + 2930);
    v273 = HIWORD(v63);
    *(_WORD *)(a1 + 2308) = *(_WORD *)(v57 + 2932);
    v265 = v64 >> 16;
    *(_WORD *)(a1 + 2310) = *(_WORD *)(v57 + 2934);
    *(_WORD *)(a1 + 2312) = *(_WORD *)(v57 + 2936);
    *(_WORD *)(a1 + 2314) = *(_WORD *)(v57 + 2938);
    *(_WORD *)(a1 + 2316) = *(_WORD *)(v57 + 2940);
    v67 = _drm_debug;
    v68 = HIWORD(v65);
    *(_WORD *)(a1 + 2318) = *(_WORD *)(v57 + 2942);
    if ( (v67 & 4) != 0 )
    {
      if ( *(_DWORD *)(v60 + 28) == 2 )
        v69 = (*(_QWORD *)(v60 + 32) >> 2) & 1LL;
      else
        LODWORD(v69) = 0;
      _drm_dev_dbg(
        0,
        0,
        0,
        "plane%d FB[%u] %u,%u,%ux%u->crtc%u %d,%d,%ux%u, %4.4s ubwc %d\n",
        *(_DWORD *)(a1 + 104),
        *(_DWORD *)(v276 + 24),
        v266,
        v273,
        v265,
        v68,
        *(_DWORD *)(v7 + 112),
        v269,
        v268,
        v267,
        v66,
        (const char *)v60,
        v69);
    }
    if ( v57 && (*(_BYTE *)(v57 + 1488) & 1) != 0 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "plane%d deinterlace\n", *(_DWORD *)(a1 + 104));
      v68 = v65 >> 17;
      v70 = *(_DWORD *)(a1 + 2284);
      v71 = 2 * *(_DWORD *)(a1 + 2276);
      v72 = 2 * *(_DWORD *)(a1 + 2280);
      *(_DWORD *)(a1 + 2272) *= 2;
      *(_DWORD *)(a1 + 2276) = v71;
      *(_DWORD *)(a1 + 2280) = v72;
      *(_DWORD *)(a1 + 2284) = 2 * v70;
      v273 = ((v273 + 1) >> 1) & 0xFFFE;
    }
    sde_crtc_get_crtc_roi(*(_QWORD *)(v7 + 2008), &v283);
    if ( v56 > 2 )
      goto LABEL_550;
    v73 = *v283;
    v74 = v283[1];
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8LL * v56 + 736) )
    {
      v261 = v283[1];
      v262 = *v283;
      v263 = v59;
      disp_op = sde_crtc_get_disp_op(v7);
      v76 = *(_DWORD *)(v7 + 7876);
      v77 = disp_op;
      v78 = *(_QWORD *)(a1 + 2408) + 20480LL;
      v79 = *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21952LL);
      v80 = *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21948LL);
      v81 = *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21956LL);
      v82 = 1000 * v79;
      v83 = 1000 * v80;
      if ( v76 && v81 && v83 && v82 )
      {
        v84 = v81 + 2;
        v85 = *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21964LL);
        LODWORD(v287) = v81 + 2;
        HIDWORD(v287) = v81;
        DWORD2(v286) = 1000 * (int)v68 / (unsigned int)v272 <= v85;
        v86 = 2 * (1000000 * v79 / v76) / 0x3E8;
        v87 = 2 * (1000000 * v80 / v76);
        if ( v86 + 1 < *(_DWORD *)(v78 + 1480) )
          v88 = v86 + 1;
        else
          v88 = *(_DWORD *)(v78 + 1480);
        v288 = v88;
        v89 = v87 / 0x3E8;
        v90 = v87 / 0x3E8 + v81;
        HIDWORD(v286) = v89 + v81;
        if ( disp_op >= 3 )
          goto LABEL_550;
        if ( !*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8LL * disp_op + 760) )
          goto LABEL_163;
        v91 = 2 * (*(_DWORD *)(v78 + 1116) / v76);
        if ( 1000 * v81 > v91 )
          v91 = 1000 * v81;
        v92 = v91 / v81;
        if ( v91 / v81 >= 2 )
        {
          v93 = 0x20 / v92;
          HIDWORD(v288) = 0x20 / v92;
          if ( v92 <= 0x20 )
          {
            v90 = 32 * v81 / v93 + v89;
            HIDWORD(v286) = v90;
          }
        }
        else
        {
LABEL_163:
          v93 = 0;
        }
      }
      else
      {
        v257 = 1000 * v80;
        v259 = 1000 * v79;
        printk(&unk_269411, "_sde_plane_setup_uidle");
        v83 = v257;
        v82 = v259;
        v93 = 0;
        v90 = 0;
        v88 = 0;
        v84 = 0;
        v81 = 0;
        *((_QWORD *)&v286 + 1) = 0;
        v287 = 0;
        v288 = 0;
      }
      if ( (_drm_debug & 4) != 0 )
      {
        v256 = v83;
        v258 = v82;
        _drm_dev_dbg(
          0,
          0,
          0,
          "plane%d tholds: fal10=%d fal10_exit=%d fal1=%d fal_allowed=%d fill_scale=%d\n",
          *(_DWORD *)(a1 + 104),
          v81,
          v84,
          v88,
          v90,
          v93);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "plane%d times: line:%d fal1_idle:%d fal10_idle:%d dwnscale:%d\n",
            *(_DWORD *)(a1 + 104),
            v76,
            v258,
            v256,
            *(_DWORD *)(*(_QWORD *)(a1 + 2408) + 21964LL));
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_plane_setup_uidle",
        3550,
        4,
        SDWORD2(v286),
        SHIDWORD(v287),
        v287,
        v288,
        SBYTE12(v286));
      if ( v77 > 2 )
LABEL_550:
        __break(0x5512u);
      v94 = *(_QWORD *)(a1 + 2208);
      v95 = *(void (**)(void))(v94 + 8LL * v77 + 760);
      if ( v95 )
      {
        if ( *((_DWORD *)v95 - 1) != 1219442784 )
          __break(0x8228u);
        v95();
        v94 = *(_QWORD *)(a1 + 2208);
      }
      v59 = v263;
      v96 = *(void (**)(void))(v94 + 8LL * v77 + 736);
      if ( v96 )
      {
        if ( *((_DWORD *)v96 - 1) != 1264730553 )
          __break(0x8228u);
        v96();
      }
      v74 = v261;
      v73 = v262;
    }
    *(_QWORD *)(a1 + 2288) = (v265 << 32) | (v68 << 48) | ((unsigned __int64)v273 << 16) | v266;
    *(_QWORD *)(a1 + 2296) = (v267 << 32)
                           | (v272 << 48)
                           | ((unsigned __int64)(unsigned __int16)(v268 - v74) << 16)
                           | (unsigned __int16)(v269 - v73);
    sde_plane_setup_scaler(a1, v57, v61, 0);
    v97 = *(_QWORD *)(a1 + 1768);
    *(_QWORD *)((char *)&v286 + 4) = 0;
    LODWORD(v282) = 0;
    if ( v97 && (v98 = *(_QWORD *)(v97 + 8)) != 0 )
    {
      v99 = *(_DWORD **)(v98 + 2008);
      v52 = v264;
      if ( (*(_QWORD *)(a1 + 1936) & 0x400000000LL) != 0 )
      {
        *(_DWORD *)(v57 + 2784) = 0;
        *(_QWORD *)(v57 + 2776) = 0;
        *(_QWORD *)(v57 + 2768) = 0;
        if ( v99[1727] )
        {
          if ( (unsigned int)sde_crtc_calc_vpadding_param(
                               *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1768) + 8LL) + 2008LL),
                               *(_DWORD *)(v57 + 36),
                               *(_DWORD *)(v57 + 44),
                               (int *)&v286 + 1,
                               (_DWORD *)&v286 + 2,
                               &v282) )
          {
            printk(&unk_27DDDA, "_sde_plane_setup_panel_stacking");
            if ( !v57 )
              goto LABEL_183;
          }
          else
          {
            v100 = DWORD2(v286);
            v101 = v282;
            *(_BYTE *)(v57 + 2768) = 1;
            *(_DWORD *)(v57 + 2772) = v99[1729];
            v102 = v99[1728];
            *(_DWORD *)(v57 + 2776) = v100;
            v103 = *(_DWORD *)(v57 + 36);
            *(_DWORD *)(v57 + 2784) = v101;
            *(_DWORD *)(v57 + 2780) = v102;
            *(_WORD *)(a1 + 2298) += WORD2(v286) - v103;
            if ( !v57 )
            {
LABEL_183:
              *(_DWORD *)(a1 + 2376) = 0;
              goto LABEL_195;
            }
          }
LABEL_194:
          v104 = *(_DWORD *)(v57 + 816);
          *(_DWORD *)(a1 + 2376) = v104;
          if ( v104 < 0 )
          {
            *(_DWORD *)(v57 + 1772) = 0;
            goto LABEL_200;
          }
LABEL_195:
          v105 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * v56 + 88);
          if ( v105 )
          {
            if ( *((_DWORD *)v105 - 1) != -1599035892 )
              __break(0x8228u);
            v105();
          }
LABEL_200:
          v106 = *(_QWORD *)(a1 + 2208);
          v107 = *(void (**)(void))(v106 + 8LL * v56 + 136);
          if ( v107 && *(_DWORD *)(v57 + 1776) != 2 )
          {
            if ( *((_DWORD *)v107 - 1) != -839651807 )
              __break(0x8228u);
            v107();
            v106 = *(_QWORD *)(a1 + 2208);
          }
          if ( !*(_QWORD *)(v106 + 8LL * v56 + 616) || *(_DWORD *)(v57 + 1776) == 2 )
            goto LABEL_218;
          v108 = *(_QWORD *)(a1 + 1768);
          if ( v108 )
          {
            v109 = *(_QWORD *)(v108 + 8);
            if ( v109 )
            {
              v110 = *(_QWORD *)(v109 + 2208);
LABEL_215:
              *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 1384LL) = v110;
              v111 = *(void (**)(void))(*(_QWORD *)(a1 + 2208) + 8LL * v56 + 616);
              if ( *((_DWORD *)v111 - 1) != -1904157959 )
                __break(0x8228u);
              v111();
              v106 = *(_QWORD *)(a1 + 2208);
LABEL_218:
              v112 = *(void (**)(void))(v106 + 8LL * v56 + 160);
              if ( v112 )
              {
                if ( *((_DWORD *)v112 - 1) != -685981120 )
                  __break(0x8228u);
                v112();
                v106 = *(_QWORD *)(a1 + 2208);
              }
              v113 = *(void (**)(void))(v106 + 8LL * v56 + 280);
              if ( v113 )
              {
                if ( *((_DWORD *)v113 - 1) != -567973718 )
                  __break(0x8228u);
                v113();
                v106 = *(_QWORD *)(a1 + 2208);
              }
              v114 = *(void (**)(void))(v106 + 8LL * v56 + 1168);
              if ( v114 )
              {
                if ( *((_DWORD *)v114 - 1) != 241108792 )
                  __break(0x8228u);
                v114();
                v106 = *(_QWORD *)(a1 + 2208);
              }
              v115 = *(void (**)(void))(v106 + 8LL * v56 + 1336);
              if ( v115 && (*(_BYTE *)(a1 + 2388) & 1) == 0 )
              {
                if ( v57 && ((v116 = *(_DWORD *)(v57 + 1648), v116 == 2) || v116 == 8) || *(_DWORD *)(a1 + 2736) )
                {
                  if ( *((_DWORD *)v115 - 1) != -2004904540 )
                    __break(0x8228u);
                  v115();
                  v106 = *(_QWORD *)(a1 + 2208);
                }
              }
              v117 = *(void (**)(void))(v106 + 8LL * v56 + 1360);
              if ( v117 )
                v118 = v59;
              else
                v118 = 0;
              if ( v118 )
              {
                if ( *((_DWORD *)v117 - 1) != -1639686971 )
                  __break(0x8228u);
                v117();
              }
              goto LABEL_246;
            }
            _drm_err("Invalid drm_crtc %pK\n", 0);
          }
          else
          {
            _drm_err("Invalid plane state %pK\n", 0);
          }
          v110 = 0;
          goto LABEL_215;
        }
      }
    }
    else
    {
      printk(&unk_23559B, "_sde_plane_setup_panel_stacking");
      v52 = v264;
    }
    if ( !v57 )
      goto LABEL_183;
    goto LABEL_194;
  }
  if ( *(_DWORD *)(v5 + 1772) )
    goto LABEL_96;
LABEL_534:
  v253 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
    v253 = *(_QWORD *)(v253 + 56);
    if ( v253 )
    {
      LODWORD(v253) = *(_DWORD *)(v253 + 5912);
      if ( (unsigned int)v253 >= 3 )
        goto LABEL_550;
    }
  }
  v254 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 8LL * (unsigned int)v253 + 4448);
  if ( v254 )
  {
    if ( *((_DWORD *)v254 - 1) != 2143177644 )
      __break(0x8228u);
    result = v254(a1, a2, v22);
    if ( (_DWORD)result )
      result = printk(&unk_26289B, "_sde_plane_atomic_update");
  }
LABEL_542:
  _ReadStatusReg(SP_EL0);
  return result;
}
