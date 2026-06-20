__int64 __fastcall wcd_correct_swch_plug(__int64 a1)
{
  __int64 *v1; // x22
  _QWORD *v2; // x26
  _QWORD *v4; // x20
  __int64 v5; // x8
  __int64 v6; // x9
  void (__fastcall *v7)(__int64, int *); // x8
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x8
  _DWORD *v11; // x8
  int v12; // w8
  signed int v13; // w19
  unsigned int v14; // w9
  unsigned int v15; // w21
  int v16; // w0
  unsigned int v17; // w23
  int v18; // w28
  __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // x1
  unsigned int v22; // w21
  __int64 v23; // x1
  __int64 v24; // x1
  int v25; // w0
  __int64 v26; // x2
  __int64 v27; // x1
  _DWORD *v28; // x8
  __int64 v29; // x8
  __int64 v30; // x1
  _DWORD *v31; // x8
  __int64 v32; // x8
  __int64 v33; // x1
  __int64 v34; // x8
  int v35; // w23
  __int64 v36; // x1
  char v37; // w0
  __int64 v38; // x8
  _DWORD *v39; // x8
  int v40; // w8
  __int64 v41; // x9
  _DWORD *v42; // x8
  unsigned __int64 v43; // x23
  __int64 v44; // x24
  int v45; // w8
  unsigned int v46; // w21
  unsigned int v47; // w9
  __int64 v48; // x8
  _DWORD *v49; // x8
  __int64 v50; // x24
  int v51; // w8
  __int64 v52; // x10
  unsigned int v53; // w24
  unsigned int v54; // w9
  int v55; // w25
  __int64 v56; // x8
  __int64 v57; // x1
  __int64 v58; // x1
  __int64 v59; // x1
  _DWORD *v60; // x8
  int v61; // w26
  int v62; // w27
  unsigned int v63; // w12
  bool v64; // w24
  int v65; // w21
  int v66; // w8
  int v67; // w25
  __int64 v68; // x24
  _QWORD *v69; // x26
  __int64 v70; // x8
  _DWORD *v71; // x8
  int v72; // w8
  unsigned int v73; // w21
  __int64 v74; // x8
  _DWORD *v75; // x8
  int v76; // w8
  unsigned int v77; // w9
  bool v78; // cf
  int v79; // w8
  void (__fastcall *v80)(__int64, __int64, __int64); // x8
  __int64 v81; // x0
  __int64 v82; // x1
  signed int v83; // w0
  __int64 v84; // x8
  signed int v85; // w21
  _DWORD *v86; // x8
  int v87; // w8
  signed int v88; // w23
  unsigned int v89; // w9
  __int64 v90; // x8
  _DWORD *v91; // x8
  int v92; // w8
  signed int v93; // w26
  unsigned int v94; // w0
  __int64 v95; // x8
  _DWORD *v96; // x8
  int v97; // w8
  __int64 v98; // x0
  _DWORD *v99; // x8
  __int64 v100; // x1
  __int64 (__fastcall *v101)(_QWORD); // x8
  __int64 v102; // x0
  int v103; // w0
  unsigned int v104; // w8
  __int64 (__fastcall *v105)(__int64, __int64); // x8
  __int64 v106; // x8
  _DWORD *v107; // x8
  int v108; // w8
  unsigned int *v109; // x27
  unsigned int v110; // w25
  __int64 v111; // x8
  _DWORD *v112; // x8
  int v113; // w9
  unsigned int v114; // w8
  int v115; // w10
  unsigned int v116; // w9
  __int64 v117; // x8
  _DWORD *v118; // x8
  int v119; // w8
  unsigned int v120; // w25
  __int64 v121; // x8
  _DWORD *v122; // x8
  int v123; // w8
  unsigned int v124; // w9
  int v125; // w8
  bool v126; // w0
  __int64 v127; // x0
  _DWORD *v128; // x8
  _BYTE *v129; // x21
  void (__fastcall *v130)(_QWORD); // x8
  __int64 v131; // x0
  __int64 v132; // x8
  unsigned int (__fastcall *v133)(__int64, __int64, __int64); // x9
  __int64 v134; // x8
  __int64 v135; // x1
  __int64 v136; // x1
  __int64 v137; // x0
  _DWORD *v138; // x8
  int v139; // w8
  signed int v140; // w21
  unsigned int v141; // w9
  bool v142; // w8
  int v143; // w19
  signed int v144; // w0
  signed int v145; // w19
  char v146; // w19
  _DWORD *v147; // x8
  __int64 v148; // x0
  __int64 v149; // x8
  __int64 v150; // x1
  __int64 v151; // x8
  _DWORD *v152; // x8
  int v153; // w8
  unsigned int v154; // w19
  __int64 v155; // x8
  _DWORD *v156; // x8
  int v157; // w8
  unsigned int v158; // w9
  int v159; // w8
  __int64 v160; // x8
  __int64 v161; // x1
  __int64 v162; // x1
  __int64 v163; // x1
  __int64 v164; // x0
  __int64 v165; // x2
  __int64 v166; // x3
  __int64 v167; // x8
  _DWORD *v168; // x9
  void (__fastcall *v169)(__int64, __int64, __int64); // x8
  __int64 v170; // x8
  void (__fastcall *v171)(__int64, __int64, __int64); // x9
  _DWORD *v172; // x9
  void (__fastcall *v173)(_QWORD); // x8
  __int64 v174; // x8
  __int64 v175; // x1
  __int64 v176; // x8
  void (__fastcall *v177)(__int64, __int64); // x9
  _DWORD *v178; // x8
  __int64 result; // x0
  _DWORD *v180; // x8
  int v181; // w0
  __int64 v182; // x8
  __int64 v183; // x1
  __int64 v184; // x8
  __int64 v185; // x1
  __int64 v186; // x8
  __int64 v187; // x1
  _BYTE *v188; // [xsp+0h] [xbp-A0h]
  __int64 v189; // [xsp+8h] [xbp-98h]
  __int64 v190; // [xsp+10h] [xbp-90h]
  unsigned int *v191; // [xsp+18h] [xbp-88h]
  bool v192; // [xsp+20h] [xbp-80h]
  int v193; // [xsp+24h] [xbp-7Ch]
  _BYTE *v194; // [xsp+28h] [xbp-78h]
  int v195; // [xsp+30h] [xbp-70h]
  int v196; // [xsp+34h] [xbp-6Ch]
  unsigned int v197; // [xsp+38h] [xbp-68h]
  unsigned int v198; // [xsp+38h] [xbp-68h]
  int v199; // [xsp+3Ch] [xbp-64h]
  __int64 v200; // [xsp+40h] [xbp-60h]
  __int64 v201; // [xsp+50h] [xbp-50h]
  _BYTE *v202; // [xsp+58h] [xbp-48h]
  __int64 v203; // [xsp+60h] [xbp-40h]
  int v204; // [xsp+6Ch] [xbp-34h]
  _QWORD *v205; // [xsp+70h] [xbp-30h]
  unsigned int *v206; // [xsp+78h] [xbp-28h]
  unsigned int *v207; // [xsp+80h] [xbp-20h]
  unsigned int *v208; // [xsp+88h] [xbp-18h]
  int v209; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v210; // [xsp+98h] [xbp-8h]

  v1 = (__int64 *)(a1 - 680);
  v2 = (_QWORD *)(a1 - 584);
  v4 = (_QWORD *)(a1 - 800);
  v210 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 680);
  v6 = *(_QWORD *)(a1 - 584);
  v209 = 0;
  v7 = *(void (__fastcall **)(__int64, int *))(v5 + 24);
  v189 = v6;
  if ( v7 )
  {
    v9 = a1 - 800;
    if ( *((_DWORD *)v7 - 1) != -2034283555 )
      __break(0x8228u);
    v7(v9, &v209);
    v8 = v209;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(a1 + 56) + 728LL) )
  {
    v8 = 50
       * ((unsigned __int8)(snd_soc_component_read(v6) & *(_BYTE *)(*(_QWORD *)(a1 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 56) + 733LL))
       + 1000;
  }
  else
  {
    v8 = 12700;
  }
  v193 = v8;
  v10 = *v1;
  v209 = 0;
  v11 = *(_DWORD **)(v10 + 24);
  if ( v11 )
  {
    if ( *(v11 - 1) != -2034283555 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, int *))v11)(v4, &v209);
    v12 = v209;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(a1 + 56) + 728LL) )
  {
    v12 = 50
        * ((unsigned __int8)(snd_soc_component_read(*v2) & *(_BYTE *)(*(_QWORD *)(a1 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 56) + 733LL))
        + 1000;
  }
  else
  {
    v12 = 12700;
  }
  v13 = *(_DWORD *)(a1 - 632);
  v207 = (unsigned int *)(a1 - 632);
  if ( v13 )
  {
    v14 = *(_DWORD *)(a1 - 624);
    if ( v14 != v12 )
      v13 = v13 * v12 / v14;
  }
  else
  {
    v13 = 1700 * v12 / 1800;
  }
  mutex_lock(a1 - 56);
  wcd_mbhc_hs_elec_irq(v4, 0, 0);
  v190 = a1 - 56;
  mutex_unlock(a1 - 56);
  v15 = 0;
  do
  {
    v16 = wcd_check_cross_conn(v4);
    ++v15;
  }
  while ( v15 < *(_DWORD *)(a1 - 620) );
  v203 = a1;
  v191 = (unsigned int *)(a1 - 620);
  if ( v16 > 0 )
  {
    v17 = 0;
    v18 = 4;
    goto LABEL_102;
  }
  v19 = *(_QWORD *)(a1 + 56);
  v20 = *(unsigned int *)(v19 + 168);
  if ( (_DWORD)v20 )
  {
    snd_soc_component_update_bits(*v2, v20, *(unsigned __int8 *)(v19 + 172), 0);
    v19 = *(_QWORD *)(a1 + 56);
    v21 = *(unsigned int *)(v19 + 744);
    if ( !(_DWORD)v21 )
    {
LABEL_25:
      if ( !*(_DWORD *)(v19 + 664) )
        goto LABEL_26;
      goto LABEL_31;
    }
  }
  else
  {
    v21 = *(unsigned int *)(v19 + 744);
    if ( !(_DWORD)v21 )
      goto LABEL_25;
  }
  snd_soc_component_update_bits(*v2, v21, *(unsigned __int8 *)(v19 + 748), (unsigned int)(1 << *(_BYTE *)(v19 + 749)));
  v19 = *(_QWORD *)(a1 + 56);
  if ( !*(_DWORD *)(v19 + 664) )
  {
LABEL_26:
    v22 = 234;
    v23 = *(unsigned int *)(v19 + 184);
    if ( (_DWORD)v23 )
      goto LABEL_27;
LABEL_33:
    v24 = *(unsigned int *)(v19 + 536);
    if ( !(_DWORD)v24 )
      goto LABEL_35;
    goto LABEL_34;
  }
LABEL_31:
  v25 = snd_soc_component_read(*v2);
  v19 = *(_QWORD *)(a1 + 56);
  v26 = *(unsigned __int8 *)(v19 + 668);
  v27 = *(unsigned int *)(v19 + 664);
  v22 = (v25 & (unsigned int)v26) >> *(_BYTE *)(v19 + 669);
  if ( (_DWORD)v27 )
  {
    snd_soc_component_update_bits(*v2, v27, v26, 0);
    v19 = *(_QWORD *)(a1 + 56);
    v23 = *(unsigned int *)(v19 + 184);
    if ( !(_DWORD)v23 )
      goto LABEL_33;
  }
  else
  {
    v23 = *(unsigned int *)(v19 + 184);
    if ( !(_DWORD)v23 )
      goto LABEL_33;
  }
LABEL_27:
  snd_soc_component_update_bits(*v2, v23, *(unsigned __int8 *)(v19 + 188), 0);
  v19 = *(_QWORD *)(a1 + 56);
  v24 = *(unsigned int *)(v19 + 536);
  if ( (_DWORD)v24 )
LABEL_34:
    snd_soc_component_update_bits(*v2, v24, *(unsigned __int8 *)(v19 + 540), (unsigned int)(1 << *(_BYTE *)(v19 + 541)));
LABEL_35:
  v28 = *(_DWORD **)(*v1 + 16);
  if ( v28 )
  {
    if ( *(v28 - 1) != 496203713 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v28)(v4, 1);
  }
  v29 = *(_QWORD *)(a1 + 56);
  v30 = *(unsigned int *)(v29 + 184);
  if ( (_DWORD)v30 )
    snd_soc_component_update_bits(*v2, v30, *(unsigned __int8 *)(v29 + 188), (unsigned int)(1 << *(_BYTE *)(v29 + 189)));
  v31 = *(_DWORD **)(*v1 + 16);
  if ( v31 )
  {
    if ( *(v31 - 1) != 496203713 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v31)(v4, 0);
  }
  v32 = *(_QWORD *)(a1 + 56);
  v33 = *(unsigned int *)(v32 + 664);
  if ( (_DWORD)v33 )
    snd_soc_component_update_bits(*v2, v33, *(unsigned __int8 *)(v32 + 668), (unsigned int)(1 << *(_BYTE *)(v32 + 669)));
  usleep_range_state(3000, 3100, 2);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 56) + 712LL) )
    snd_soc_component_read(*v2);
  usleep_range_state(3000, 3100, 2);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 56) + 712LL) )
    snd_soc_component_read(*v2);
  usleep_range_state(3000, 3100, 2);
  v34 = *(_QWORD *)(a1 + 56);
  if ( *(_DWORD *)(v34 + 712) )
  {
    v37 = snd_soc_component_read(*v2);
    v34 = *(_QWORD *)(a1 + 56);
    v35 = 125 * ((unsigned __int8)(v37 & *(_BYTE *)(v34 + 716)) >> *(_BYTE *)(v34 + 717));
    v36 = *(unsigned int *)(v34 + 664);
    if ( !(_DWORD)v36 )
      goto LABEL_56;
    goto LABEL_55;
  }
  v35 = 29250;
  v36 = *(unsigned int *)(v34 + 664);
  if ( (_DWORD)v36 )
LABEL_55:
    snd_soc_component_update_bits(*v2, v36, *(unsigned __int8 *)(v34 + 668), v22 << *(_BYTE *)(v34 + 669));
LABEL_56:
  v38 = *v1;
  v209 = 0;
  v39 = *(_DWORD **)(v38 + 24);
  if ( v39 )
  {
    if ( *(v39 - 1) != -2034283555 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, int *))v39)(v4, &v209);
    v40 = v209;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(a1 + 56) + 728LL) )
  {
    v40 = 50
        * ((unsigned __int8)(snd_soc_component_read(*v2) & *(_BYTE *)(*(_QWORD *)(a1 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 56) + 733LL))
        + 1000;
  }
  else
  {
    v40 = 12700;
  }
  v209 = 0;
  v41 = 1954687339LL * v40 * v35;
  v42 = *(_DWORD **)(*v1 + 24);
  v43 = (unsigned __int64)v41 >> 63;
  v44 = v41 >> 45;
  if ( v42 )
  {
    if ( *(v42 - 1) != -2034283555 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, int *))v42)(v4, &v209);
    v45 = v209;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
  {
    v45 = 50
        * ((unsigned __int8)(snd_soc_component_read(*v2) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
        + 1000;
  }
  else
  {
    v45 = 12700;
  }
  v46 = *v207;
  if ( *v207 )
  {
    v47 = *(_DWORD *)(v203 - 624);
    if ( v47 != v45 )
      v46 = v46 * v45 / v47;
  }
  else
  {
    v46 = 1700 * v45 / 1800;
  }
  v48 = *v1;
  v17 = v44 + v43;
  v209 = 0;
  v49 = *(_DWORD **)(v48 + 24);
  if ( v49 )
  {
    if ( *(v49 - 1) != -2034283555 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, int *))v49)(v4, &v209);
    v51 = v209;
    v50 = v203;
  }
  else
  {
    v50 = v203;
    if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
      v51 = 50
          * ((unsigned __int8)(snd_soc_component_read(*v2) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
          + 1000;
    else
      v51 = 12700;
  }
  v52 = v50;
  v53 = *(_DWORD *)(v50 - 628);
  if ( v53 )
  {
    v54 = *(_DWORD *)(v52 - 624);
    if ( v54 != v51 )
      v53 = v53 * v51 / v54;
  }
  else
  {
    v53 = 75 * v51 / 1800;
  }
  if ( v46 >= v17 )
    v55 = 1;
  else
    v55 = 3;
  printk(&unk_E2B3, "wcd_correct_swch_plug");
  if ( v53 > v17 )
    v18 = 2;
  else
    v18 = v55;
  if ( (v53 > v17 || v46 >= v17) && !wcd_swch_level_remove((__int64)v4) )
  {
    mutex_lock(v190);
    wcd_mbhc_find_plug_and_report((__int64)v4, v18);
    mutex_unlock(v190);
  }
  if ( (*(unsigned __int8 *)(v203 - 639) | 4) == 5 )
  {
    v56 = *(_QWORD *)(v203 + 56);
    v57 = *(unsigned int *)(v56 + 744);
    if ( (_DWORD)v57 )
    {
      snd_soc_component_update_bits(*v2, v57, *(unsigned __int8 *)(v56 + 748), 0);
      v56 = *(_QWORD *)(v203 + 56);
      v58 = *(unsigned int *)(v56 + 664);
      if ( !(_DWORD)v58 )
      {
LABEL_100:
        v59 = *(unsigned int *)(v56 + 760);
        if ( !(_DWORD)v59 )
          goto LABEL_102;
        goto LABEL_101;
      }
    }
    else
    {
      v58 = *(unsigned int *)(v56 + 664);
      if ( !(_DWORD)v58 )
        goto LABEL_100;
    }
    snd_soc_component_update_bits(*v2, v58, *(unsigned __int8 *)(v56 + 668), 0);
    v56 = *(_QWORD *)(v203 + 56);
    v59 = *(unsigned int *)(v56 + 760);
    if ( (_DWORD)v59 )
LABEL_101:
      snd_soc_component_update_bits(
        *v2,
        v59,
        *(unsigned __int8 *)(v56 + 764),
        (unsigned int)(1 << *(_BYTE *)(v56 + 765)));
  }
LABEL_102:
  v205 = v2;
  v60 = *(_DWORD **)(*v1 + 32);
  if ( v60 )
  {
    if ( *(v60 - 1) != 496203713 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v60)(v4, 0);
  }
  v204 = 0;
  v61 = 0;
  v195 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v65 = 1;
  v201 = jiffies + 750LL;
  v200 = v203 - 688;
  v202 = (_BYTE *)(v203 - 594);
  v194 = (_BYTE *)(v203 - 593);
  v208 = (unsigned int *)(v203 - 624);
  v188 = (_BYTE *)(v203 - 639);
  v206 = (unsigned int *)(v203 - 628);
  v199 = 1;
LABEL_107:
  v66 = v195;
  v192 = v64;
LABEL_108:
  v67 = v61;
  v195 = v66;
  v196 = v62;
  v197 = v63;
  while ( 1 )
  {
    if ( v201 - jiffies < 0 )
    {
      v68 = v203;
      v69 = v205;
      if ( !v192 && v18 == 1 )
      {
        if ( *v188 != 1 )
        {
          v18 = 1;
          goto LABEL_335;
        }
        v134 = *(_QWORD *)(v203 + 56);
        v129 = (_BYTE *)(v203 - 594);
        v135 = *(unsigned int *)(v134 + 744);
        if ( (_DWORD)v135 )
        {
          snd_soc_component_update_bits(*v205, v135, *(unsigned __int8 *)(v134 + 748), 0);
          v134 = *(_QWORD *)(v203 + 56);
        }
        v136 = *(unsigned int *)(v134 + 664);
        if ( (_DWORD)v136 )
        {
          snd_soc_component_update_bits(*v205, v136, *(unsigned __int8 *)(v134 + 668), 0);
          v134 = *(_QWORD *)(v203 + 56);
        }
        goto LABEL_374;
      }
      if ( v18 != 3 )
        goto LABEL_335;
      v132 = *v1;
      v133 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(*v1 + 240);
      if ( *(_QWORD *)(*v1 + 208) )
      {
        if ( !v133 )
          goto LABEL_332;
      }
      else if ( !v133 )
      {
LABEL_301:
        v138 = *(_DWORD **)(v132 + 24);
        v209 = 0;
        if ( v138 )
        {
          if ( *(v138 - 1) != -2034283555 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, int *))v138)(v4, &v209);
          v139 = v209;
        }
        else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
        {
          v139 = 50
               * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
               + 1000;
        }
        else
        {
          v139 = 12700;
        }
        v140 = *v207;
        if ( *v207 && (v141 = *v208, *v208 != 1800) )
        {
          if ( v141 != v139 )
            v140 = v140 * v139 / v141;
        }
        else
        {
          v140 = 1700 * v139 / 1800;
        }
        v142 = 0;
        v143 = 2000;
        while ( 1 )
        {
          if ( v142 )
          {
            printk(&unk_E338, "wcd_is_special_headset");
            goto LABEL_320;
          }
          if ( *v202 == 1 )
            break;
          msleep(50);
          v144 = wcd_measure_adc_once(v4, 1);
          v142 = v144 <= v140;
          v143 -= 50;
          if ( !v143 )
          {
            v145 = v144;
            printk(&unk_E338, "wcd_is_special_headset");
            if ( v145 > v140 )
              goto LABEL_322;
LABEL_320:
            v146 = 1;
            *v194 = 1;
            goto LABEL_323;
          }
        }
        printk(&unk_E338, "wcd_is_special_headset");
LABEL_322:
        v146 = 0;
LABEL_323:
        v147 = *(_DWORD **)(*v1 + 240);
        if ( v147 && (*v194 & 1) == 0 )
        {
          v148 = *v205;
          if ( *(v147 - 1) != -1065592060 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v147)(v148, 2, 0);
          if ( (v146 & 1) != 0 )
            goto LABEL_326;
        }
        else if ( (v146 & 1) != 0 )
        {
LABEL_326:
          v18 = 1;
          goto LABEL_335;
        }
LABEL_332:
        v149 = *(_QWORD *)(v203 + 56);
        v150 = *(unsigned int *)(v149 + 776);
        if ( (_DWORD)v150 )
          snd_soc_component_update_bits(
            *v205,
            v150,
            *(unsigned __int8 *)(v149 + 780),
            (unsigned int)(1 << *(_BYTE *)(v149 + 781)));
        v18 = 3;
        goto LABEL_335;
      }
      v137 = *v205;
      if ( *((_DWORD *)v133 - 1) != -1065592060 )
        __break(0x8229u);
      if ( v133(v137, 2, 1) )
      {
        printk(&unk_E168, "wcd_is_special_headset");
        goto LABEL_332;
      }
      v132 = *v1;
      goto LABEL_301;
    }
    v68 = v203;
    v69 = v205;
    if ( *v202 == 1 )
      break;
    msleep(20);
    if ( *v202 == 1 )
      break;
    msleep(180);
    v17 = wcd_measure_adc_once(v4, 1);
    if ( v65 )
      printk(&unk_DD2B, "wcd_correct_swch_plug");
    v70 = *v1;
    v209 = 0;
    v71 = *(_DWORD **)(v70 + 24);
    if ( v71 )
    {
      if ( *(v71 - 1) != -2034283555 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, int *))v71)(v4, &v209);
      v72 = v209;
    }
    else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
    {
      v72 = 50
          * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
          + 1000;
    }
    else
    {
      v72 = 12700;
    }
    v73 = *v207;
    if ( *v207 )
    {
      if ( *v208 != v72 )
        v73 = v73 * v72 / *v208;
    }
    else
    {
      v73 = 1700 * v72 / 1800;
    }
    v74 = *v1;
    v209 = 0;
    v75 = *(_DWORD **)(v74 + 24);
    if ( v75 )
    {
      if ( *(v75 - 1) != -2034283555 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, int *))v75)(v4, &v209);
      v76 = v209;
    }
    else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
    {
      v76 = 50
          * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
          + 1000;
    }
    else
    {
      v76 = 12700;
    }
    v77 = *v206;
    if ( *v206 )
    {
      if ( *v208 != v76 )
        v77 = v77 * v76 / *v208;
    }
    else
    {
      v77 = 75 * v76 / 1800;
    }
    v78 = v73 >= v17;
    v65 = 0;
    if ( v78 )
      v79 = 1;
    else
      v79 = 3;
    if ( v77 <= v17 )
      v18 = v79;
    else
      v18 = 2;
    if ( (int)v17 > v13 && v204 <= 0 )
    {
      v80 = *(void (__fastcall **)(__int64, __int64, __int64))(*v1 + 240);
      if ( !v80 )
        goto LABEL_183;
      v81 = *v205;
      v82 = *(unsigned int *)(*(_QWORD *)v200 + 76LL);
      if ( *((_DWORD *)v80 - 1) != -1065592060 )
        __break(0x8228u);
      v80(v81, v82, 1);
      usleep_range_state(10000, 10100, 2);
      v83 = wcd_measure_adc_once(v4, 1);
      v84 = *v1;
      v85 = v83;
      v209 = 0;
      v86 = *(_DWORD **)(v84 + 24);
      if ( v86 )
      {
        if ( *(v86 - 1) != -2034283555 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, int *))v86)(v4, &v209);
        v87 = v209;
      }
      else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
      {
        v87 = 50
            * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
            + 1000;
      }
      else
      {
        v87 = 12700;
      }
      v88 = *v207;
      if ( *v207 && (v89 = *v208, *v208 != 1800) )
      {
        if ( v89 != v87 )
          v88 = v88 * v87 / v89;
      }
      else
      {
        v88 = 1700 * v87 / 1800;
      }
      v90 = *v1;
      v209 = 0;
      v91 = *(_DWORD **)(v90 + 24);
      if ( v91 )
      {
        if ( *(v91 - 1) != -2034283555 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, int *))v91)(v4, &v209);
        v92 = v209;
      }
      else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
      {
        v92 = 50
            * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
            + 1000;
      }
      else
      {
        v92 = 12700;
      }
      v93 = *v206;
      if ( *v206 )
      {
        if ( *v208 != v92 )
          v93 = v93 * v92 / *v208;
      }
      else
      {
        v93 = 75 * v92 / 1800;
      }
      if ( v199 >= 1 )
      {
        printk(&unk_E3CC, "wcd_mbhc_adc_check_for_spl_headset");
        if ( v85 > v88 )
        {
LABEL_180:
          v69 = v205;
          v98 = *v205;
          v99 = *(_DWORD **)(*v1 + 240);
          v100 = *(unsigned int *)(*(_QWORD *)v200 + 76LL);
          if ( *(v99 - 1) != -1065592060 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v99)(v98, v100, 0);
          usleep_range_state(10000, 10100, 2);
LABEL_183:
          v17 = wcd_measure_adc_once(v4, 1);
          v65 = 0;
          goto LABEL_184;
        }
      }
      else if ( v85 > v88 )
      {
        goto LABEL_180;
      }
      if ( v85 < v93 )
        goto LABEL_180;
      v69 = v205;
      v94 = wcd_measure_adc_once(v4, 1);
      v95 = *v1;
      v17 = v94;
      v209 = 0;
      v96 = *(_DWORD **)(v95 + 24);
      if ( v96 )
      {
        if ( *(v96 - 1) != -2034283555 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, int *))v96)(v4, &v209);
        v97 = v209;
      }
      else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
      {
        v97 = 50
            * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
            + 1000;
      }
      else
      {
        v97 = 12700;
      }
      v65 = 2;
      v13 = v97 * v13 / v193;
      v204 = 1;
      *v194 = 1;
    }
LABEL_184:
    v101 = *(__int64 (__fastcall **)(_QWORD))(*v1 + 184);
    if ( v101 )
    {
      v102 = *v69;
      if ( *((_DWORD *)v101 - 1) != -67188162 )
        __break(0x8228u);
      v67 = v101(v102);
    }
    v61 = v67;
    v64 = (int)v17 > v13;
    if ( (int)v17 > v13 )
    {
      v62 = v196;
      v63 = v197;
      v199 = 0;
      v18 = 3;
      goto LABEL_107;
    }
    if ( (v67 & 1) != 0 )
    {
      v62 = v196;
      v116 = v197;
      goto LABEL_235;
    }
    v103 = wcd_check_cross_conn(v4);
    v67 = 0;
    if ( (v103 & 0x80000000) == 0 )
    {
      if ( v103 )
      {
        v67 = 0;
        v104 = *v191;
        v196 = 0;
        if ( ++v197 >= *v191 )
        {
          if ( v197 > v104 )
          {
            v129 = (_BYTE *)(v203 - 594);
            if ( wcd_swch_level_remove((__int64)v4) )
            {
              v68 = v203;
              v69 = v205;
              v18 = 4;
              goto LABEL_384;
            }
            v68 = v203;
            v69 = v205;
LABEL_338:
            if ( *(_DWORD *)(*(_QWORD *)v200 + 88LL) )
            {
              v151 = *v1;
              v209 = 0;
              v152 = *(_DWORD **)(v151 + 24);
              if ( v152 )
              {
                if ( *(v152 - 1) != -2034283555 )
                  __break(0x8228u);
                ((void (__fastcall *)(_QWORD *, int *))v152)(v4, &v209);
                v153 = v209;
              }
              else if ( *(_DWORD *)(*(_QWORD *)(v68 + 56) + 728LL) )
              {
                v153 = 50
                     * ((unsigned __int8)(snd_soc_component_read(*v69) & *(_BYTE *)(*(_QWORD *)(v68 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v68 + 56) + 733LL))
                     + 1000;
              }
              else
              {
                v153 = 12700;
              }
              v154 = *v207;
              if ( *v207 )
              {
                if ( *v208 != v153 )
                  v154 = v154 * v153 / *v208;
              }
              else
              {
                v154 = 1700 * v153 / 1800;
              }
              v155 = *v1;
              v209 = 0;
              v156 = *(_DWORD **)(v155 + 24);
              if ( v156 )
              {
                if ( *(v156 - 1) != -2034283555 )
                  __break(0x8228u);
                ((void (__fastcall *)(_QWORD *, int *))v156)(v4, &v209);
                v157 = v209;
              }
              else if ( *(_DWORD *)(*(_QWORD *)(v68 + 56) + 728LL) )
              {
                v157 = 50
                     * ((unsigned __int8)(snd_soc_component_read(*v69) & *(_BYTE *)(*(_QWORD *)(v68 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v68 + 56) + 733LL))
                     + 1000;
              }
              else
              {
                v157 = 12700;
              }
              v158 = *v206;
              if ( *v206 )
              {
                if ( *v208 != v157 )
                  v158 = v158 * v157 / *v208;
              }
              else
              {
                v158 = 75 * v157 / 1800;
              }
              if ( v154 >= v17 )
                v159 = 1;
              else
                v159 = 3;
              if ( v158 <= v17 )
                v18 = v159;
              else
                v18 = 2;
              printk(&unk_E255, "wcd_correct_swch_plug");
            }
            else
            {
              v18 = 4;
            }
LABEL_369:
            v160 = *(_QWORD *)(v68 + 56);
            v161 = *(unsigned int *)(v160 + 744);
            if ( (_DWORD)v161 )
            {
              snd_soc_component_update_bits(*v69, v161, *(unsigned __int8 *)(v160 + 748), 0);
              v160 = *(_QWORD *)(v68 + 56);
            }
            v162 = *(unsigned int *)(v160 + 664);
            if ( (_DWORD)v162 )
              snd_soc_component_update_bits(*v69, v162, *(unsigned __int8 *)(v160 + 668), 0);
            mutex_lock(v190);
            wcd_mbhc_find_plug_and_report((__int64)v4, v18);
            mutex_unlock(v190);
            v134 = *(_QWORD *)(v68 + 56);
            if ( v18 != 1 )
            {
              v163 = *(unsigned int *)(v134 + 760);
              if ( (_DWORD)v163 )
              {
                v164 = *v69;
                v165 = *(unsigned __int8 *)(v134 + 764);
                v166 = 0;
                goto LABEL_378;
              }
LABEL_379:
              v167 = *v1;
              v168 = *(_DWORD **)(*v1 + 32);
              if ( v168 )
              {
                if ( *(v168 - 1) != 496203713 )
                  __break(0x8229u);
                ((void (__fastcall *)(_QWORD *, __int64))v168)(v4, 1);
                v167 = *v1;
              }
              if ( *(_QWORD *)(v167 + 208) )
              {
                v180 = *(_DWORD **)(v167 + 152);
                if ( *(v180 - 1) != -1840370871 )
                  __break(0x8228u);
                v181 = ((__int64 (__fastcall *)(_QWORD *, __int64))v180)(v4, 2);
                if ( v18 == 1 )
                {
                  if ( ((*(unsigned __int8 *)(v68 - 591) | v181) & 1) == 0
                    && (v184 = *(_QWORD *)(v68 + 56), v185 = *(unsigned int *)(v184 + 360), (_DWORD)v185) )
                  {
                    snd_soc_component_update_bits(
                      *v69,
                      v185,
                      *(unsigned __int8 *)(v184 + 364),
                      (unsigned int)(3 << *(_BYTE *)(v184 + 365)));
                    v18 = 1;
                  }
                  else
                  {
                    v18 = 1;
                  }
                }
                else if ( v18 == 2 )
                {
                  v182 = *(_QWORD *)(v68 + 56);
                  v183 = *(unsigned int *)(v182 + 360);
                  if ( (_DWORD)v183 )
                    snd_soc_component_update_bits(
                      *v69,
                      v183,
                      *(unsigned __int8 *)(v182 + 364),
                      (unsigned int)(3 << *(_BYTE *)(v182 + 365)));
                  v18 = 2;
                }
                else
                {
                  v186 = *(_QWORD *)(v68 + 56);
                  v187 = *(unsigned int *)(v186 + 360);
                  if ( (_DWORD)v187 )
                    snd_soc_component_update_bits(*v69, v187, *(unsigned __int8 *)(v186 + 364), 0);
                }
              }
              goto LABEL_384;
            }
LABEL_374:
            v163 = *(unsigned int *)(v134 + 760);
            v18 = 1;
            if ( (_DWORD)v163 )
            {
              v164 = *v69;
              v165 = *(unsigned __int8 *)(v134 + 764);
              v166 = (unsigned int)(1 << *(_BYTE *)(v134 + 765));
LABEL_378:
              snd_soc_component_update_bits(v164, v163, v165, v166);
              goto LABEL_379;
            }
            goto LABEL_379;
          }
          if ( v197 != v104 )
          {
            v63 = v197;
            v61 = 0;
            v62 = 0;
            v18 = 4;
            goto LABEL_107;
          }
          v105 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v200 + 24LL);
          if ( !v105 )
          {
            v63 = v197;
            v61 = 0;
            v62 = 0;
            v18 = 4;
            v65 = 3;
            goto LABEL_107;
          }
          if ( *((_DWORD *)v105 - 1) != -206509543 )
            __break(0x8228u);
          v67 = 0;
          v18 = 4;
          v65 = 3;
          v196 = 0;
          if ( (v105(v189, 1) & 1) == 0 )
          {
            v63 = v197;
            v61 = 0;
            v62 = 0;
            goto LABEL_107;
          }
        }
      }
      else
      {
        v106 = *v1;
        v209 = 0;
        v107 = *(_DWORD **)(v106 + 24);
        if ( v107 )
        {
          if ( *(v107 - 1) != -2034283555 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, int *))v107)(v4, &v209);
          v108 = v209;
          v109 = v191;
        }
        else
        {
          v109 = v191;
          if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
            v108 = 50
                 * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
                 + 1000;
          else
            v108 = 12700;
        }
        v110 = *v207;
        if ( *v207 )
        {
          if ( *v208 != v108 )
            v110 = v110 * v108 / *v208;
        }
        else
        {
          v110 = 1700 * v108 / 1800;
        }
        v111 = *v1;
        v209 = 0;
        v112 = *(_DWORD **)(v111 + 24);
        if ( v112 )
        {
          if ( *(v112 - 1) != -2034283555 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, int *))v112)(v4, &v209);
          v113 = v209;
        }
        else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
        {
          v113 = 50
               * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
               + 1000;
        }
        else
        {
          v113 = 12700;
        }
        v114 = *v206;
        if ( *v206 )
        {
          if ( *v208 != v113 )
            v114 = v114 * v113 / *v208;
        }
        else
        {
          v114 = 75 * v113 / 1800;
        }
        if ( v110 >= v17 )
          v115 = 1;
        else
          v115 = 3;
        if ( v114 <= v17 )
          v18 = v115;
        else
          v18 = 2;
        if ( v196 + 1 >= *v109 )
        {
          v62 = 0;
          v116 = 0;
LABEL_235:
          v117 = *v1;
          v209 = 0;
          v198 = v116;
          v118 = *(_DWORD **)(v117 + 24);
          if ( v118 )
          {
            if ( *(v118 - 1) != -2034283555 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, int *))v118)(v4, &v209);
            v119 = v209;
          }
          else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
          {
            v119 = 50
                 * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
                 + 1000;
          }
          else
          {
            v119 = 12700;
          }
          v120 = *v207;
          if ( *v207 )
          {
            if ( *v208 != v119 )
              v120 = v120 * v119 / *v208;
          }
          else
          {
            v120 = 1700 * v119 / 1800;
          }
          v121 = *v1;
          v209 = 0;
          v122 = *(_DWORD **)(v121 + 24);
          if ( v122 )
          {
            if ( *(v122 - 1) != -2034283555 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, int *))v122)(v4, &v209);
            v123 = v209;
          }
          else if ( *(_DWORD *)(*(_QWORD *)(v203 + 56) + 728LL) )
          {
            v123 = 50
                 * ((unsigned __int8)(snd_soc_component_read(*v205) & *(_BYTE *)(*(_QWORD *)(v203 + 56) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(v203 + 56) + 733LL))
                 + 1000;
          }
          else
          {
            v123 = 12700;
          }
          v124 = *v206;
          if ( *v206 )
          {
            if ( *v208 != v123 )
              v124 = v124 * v123 / *v208;
          }
          else
          {
            v124 = 75 * v123 / 1800;
          }
          if ( v120 >= v17 )
            v125 = 1;
          else
            v125 = 3;
          if ( v124 <= v17 )
            v18 = v125;
          else
            v18 = 2;
          if ( !(v195 & 1 | (v204 != 1)) )
          {
            mutex_lock(v190);
            wcd_mbhc_find_plug_and_report((__int64)v4, v18);
            mutex_unlock(v190);
            v66 = 1;
            v63 = v198;
            v204 = 1;
            goto LABEL_108;
          }
          v63 = v198;
          v66 = 1;
          if ( (v195 & 1) != 0 )
            goto LABEL_108;
          v195 = 0;
          if ( ((unsigned __int8)*v188 | 4) != 5 )
          {
            v126 = wcd_swch_level_remove((__int64)v4);
            v63 = v198;
            v195 = 0;
            if ( !v126 )
            {
LABEL_335:
              if ( wcd_swch_level_remove((__int64)v4) )
              {
                v129 = (_BYTE *)(v203 - 594);
                v68 = v203;
                v69 = v205;
                goto LABEL_384;
              }
              v129 = (_BYTE *)(v203 - 594);
              v68 = v203;
              v69 = v205;
              if ( v18 == 4 )
                goto LABEL_338;
              goto LABEL_369;
            }
          }
          goto LABEL_107;
        }
        v67 = 0;
        v62 = 0;
        v116 = 0;
        ++v196;
        v197 = 0;
        if ( v204 == 1 )
          goto LABEL_235;
      }
    }
  }
  if ( *v194 == 1 )
  {
    v127 = *v205;
    v128 = *(_DWORD **)(*v1 + 240);
    if ( *(v128 - 1) != -1065592060 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v128)(v127, 2, 0);
    v129 = (_BYTE *)(v203 - 594);
    v130 = *(void (__fastcall **)(_QWORD))(*v1 + 64);
    if ( v130 )
    {
      v131 = *v205;
      if ( *((_DWORD *)v130 - 1) != 933030000 )
        __break(0x8228u);
      v130(v131);
    }
    *v194 = 0;
  }
  else
  {
    v129 = (_BYTE *)(v203 - 594);
  }
LABEL_384:
  v169 = *(void (__fastcall **)(__int64, __int64, __int64))(*v1 + 208);
  if ( v169 && (*v194 & 1) == 0 )
  {
    if ( *((_DWORD *)v169 - 1) != -1208669315 )
      __break(0x8228u);
    v169(v189, 2, 3);
  }
  if ( v18 == 2 && *v194 == 1 )
  {
    v170 = *v1;
    v171 = *(void (__fastcall **)(__int64, __int64, __int64))(*v1 + 208);
    if ( v171 )
    {
      if ( *((_DWORD *)v171 - 1) != -1208669315 )
        __break(0x8229u);
      v171(v189, 2, 3);
      v170 = *v1;
      v172 = *(_DWORD **)(*v1 + 240);
      if ( v172 )
        goto LABEL_398;
LABEL_393:
      v173 = *(void (__fastcall **)(_QWORD))(v170 + 64);
      if ( v173 )
      {
LABEL_401:
        if ( *((_DWORD *)v173 - 1) != 933030000 )
          __break(0x8228u);
        v173(v189);
        v174 = *(_QWORD *)(v68 + 56);
        v175 = *(unsigned int *)(v174 + 392);
        if ( (_DWORD)v175 )
          snd_soc_component_update_bits(*v69, v175, *(unsigned __int8 *)(v174 + 396), 0);
      }
    }
    else
    {
      v172 = *(_DWORD **)(v170 + 240);
      if ( !v172 )
        goto LABEL_393;
LABEL_398:
      if ( *(v172 - 1) != -1065592060 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v172)(v189, 2, 0);
      v173 = *(void (__fastcall **)(_QWORD))(*v1 + 64);
      if ( v173 )
        goto LABEL_401;
    }
    *v194 = 0;
  }
  if ( *(_BYTE *)(*(_QWORD *)v200 + 16LL) == 1 && (unsigned int)(v18 - 1) <= 1 && (*v129 & 1) == 0 )
  {
    mutex_lock(v190);
    wcd_mbhc_hs_elec_irq(v4, 1u, 1);
    mutex_unlock(v190);
  }
  if ( v18 == 2 )
  {
    mutex_lock(v190);
    wcd_mbhc_hs_elec_irq(v4, 0, 1);
    mutex_unlock(v190);
  }
  v176 = *v1;
  v177 = *(void (__fastcall **)(__int64, __int64))(*v1 + 256);
  if ( v177 )
  {
    if ( *((_DWORD *)v177 - 1) != -1918869124 )
      __break(0x8229u);
    v177(v189, 1);
    v176 = *v1;
  }
  v178 = *(_DWORD **)(v176 + 144);
  if ( *(v178 - 1) != 1996337026 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, _QWORD))v178)(v4, 0);
  result = printk(&unk_E05B, "wcd_correct_swch_plug");
  _ReadStatusReg(SP_EL0);
  return result;
}
