__int64 __fastcall spectral_control_cmn(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  _QWORD *comp_private_obj; // x0
  unsigned int v14; // w10
  unsigned int v15; // w8
  _DWORD *v16; // x8
  __int64 v17; // x1
  const char *v18; // x2
  const char *v19; // x3
  unsigned int v20; // w1
  unsigned int (__fastcall *v22)(__int64, __int64); // x8
  _DWORD *v23; // x8
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x1
  __int64 v26; // x2
  int v27; // w8
  _DWORD *v28; // x10
  _QWORD *v29; // x23
  int v30; // w8
  int v31; // w8
  _DWORD *v32; // x9
  _QWORD *v33; // x22
  int v34; // w8
  int v35; // w8
  _DWORD *v36; // x10
  _QWORD *v37; // x23
  int v38; // w8
  int v39; // w8
  _DWORD *v40; // x10
  _QWORD *v41; // x22
  int v42; // w8
  int v43; // w8
  _DWORD *v44; // x10
  _QWORD *v45; // x23
  int v46; // w8
  int v47; // w8
  _DWORD *v48; // x10
  _QWORD *v49; // x22
  int v50; // w8
  int v51; // w8
  _DWORD *v52; // x10
  _QWORD *v53; // x23
  int v54; // w8
  int v55; // w8
  _DWORD *v56; // x10
  _QWORD *v57; // x22
  int v58; // w8
  int v59; // w8
  _DWORD *v60; // x10
  _QWORD *v61; // x23
  int v62; // w8
  int v63; // w8
  _DWORD *v64; // x10
  _QWORD *v65; // x22
  int v66; // w8
  int v67; // w8
  _DWORD *v68; // x10
  _QWORD *v69; // x22
  int v70; // w8
  int v71; // w8
  _QWORD *v72; // x22
  _DWORD *v73; // x10
  int v74; // w8
  _DWORD *v75; // x10
  int v76; // w8
  _DWORD *v77; // x10
  int v78; // w8
  _DWORD *v79; // x10
  int v80; // w8
  _DWORD *v81; // x10
  int v82; // w8
  _DWORD *v83; // x9
  int v84; // w0
  int v85; // w8
  _DWORD *v86; // x10
  int v87; // w8
  _DWORD *v88; // x10
  int v89; // w8
  _DWORD *v90; // x10
  __int64 vdev; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x23
  __int64 cmpt_obj; // x0
  unsigned int *v102; // x8
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  int v111; // w24
  _DWORD *v112; // x8
  _DWORD *v113; // x8
  int v114; // w1
  _QWORD *first_vdev; // x0
  _DWORD *v116; // x8
  int v117; // w9
  int v118; // w10
  __int64 v119; // x8
  __int64 v120; // x9
  __int64 v121; // x8
  __int64 v122; // x10
  unsigned int (__fastcall *v123)(__int64, __int64); // x8
  __int64 v124; // x1
  void (__fastcall *v125)(__int64, __int64); // x8
  __int64 (__fastcall *v126)(_QWORD); // x8
  __int64 v127; // x20
  double ch_width; // d0
  int v129; // w0
  int v130; // w21
  unsigned int *v131; // x8
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  int v139; // w8
  _DWORD *v140; // x10
  int v141; // w8
  int v142; // w10
  _DWORD *v143; // x8
  int v144; // w8
  _DWORD *v145; // x10
  int v146; // w8
  _DWORD *v147; // x10
  __int64 v148; // [xsp+8h] [xbp-68h] BYREF
  int v149; // [xsp+10h] [xbp-60h]
  _QWORD v150[5]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v151; // [xsp+40h] [xbp-30h]
  __int64 v152; // [xsp+48h] [xbp-28h]
  __int128 v153; // [xsp+50h] [xbp-20h]
  __int64 v154; // [xsp+60h] [xbp-10h]
  __int64 v155; // [xsp+68h] [xbp-8h]

  v155 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v154 = 0;
  v152 = 0;
  v153 = 0u;
  v151 = 0;
  memset(v150, 0, sizeof(v150));
  v149 = 0;
  v148 = 0;
  if ( !a1 )
  {
    v18 = "%s: PDEV is NULL!";
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(a1 + 80)
    || (comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x13u)) == nullptr )
  {
    v18 = "%s: Spectral context is NULL!";
LABEL_15:
    v19 = "spectral_control_cmn";
    v20 = 2;
LABEL_16:
    qdf_trace_msg(0x56u, v20, v18, a3, a4, a5, a6, a7, a8, a9, a10, v19);
    goto LABEL_17;
  }
  v14 = *((unsigned __int8 *)a2 + 4);
  v15 = 16;
  if ( v14 > 0x26 )
  {
    if ( *((unsigned __int8 *)a2 + 4) <= 0x2Eu )
    {
      switch ( v14 )
      {
        case '\'':
          v112 = (_DWORD *)comp_private_obj[17];
          if ( *(v112 - 1) != -907325943 )
            __break(0x8228u);
          *((_BYTE *)a2 + 9) = ((__int64 (__fastcall *)(__int64, _QWORD))v112)(a1, v10) & 1;
          goto LABEL_149;
        case '-':
          v123 = (unsigned int (__fastcall *)(__int64, __int64))comp_private_obj[20];
          if ( *((_DWORD *)v123 - 1) != 1111351996 )
            __break(0x8228u);
          if ( !v123(a1, (__int64)(a2 + 2)) )
            goto LABEL_149;
          break;
        case '.':
          v22 = (unsigned int (__fastcall *)(__int64, __int64))comp_private_obj[21];
          if ( *((_DWORD *)v22 - 1) != 1414237872 )
            __break(0x8228u);
          if ( !v22(a1, (__int64)(a2 + 2)) )
            goto LABEL_149;
          break;
        default:
          goto LABEL_18;
      }
      goto LABEL_17;
    }
    if ( v14 != 47 )
    {
      if ( v14 == 52 )
      {
        v126 = (__int64 (__fastcall *)(_QWORD))comp_private_obj[19];
        if ( *((_DWORD *)v126 - 1) != -317336512 )
          __break(0x8228u);
        a2[2] = v126(a1);
        goto LABEL_149;
      }
      if ( v14 == 53 )
      {
        v24 = (void (__fastcall *)(__int64, __int64, __int64))comp_private_obj[28];
        if ( v24 )
        {
          v25 = (unsigned int)a2[3];
          v26 = *((unsigned __int8 *)a2 + 8);
          if ( *((_DWORD *)v24 - 1) != -1770268 )
            __break(0x8228u);
          v24(a1, v25, v26);
        }
        goto LABEL_149;
      }
      goto LABEL_18;
    }
    v114 = *((unsigned __int8 *)a2 + 5);
    if ( v114 == 255 )
      first_vdev = wlan_objmgr_pdev_get_first_vdev(a1, 0x1Bu);
    else
      first_vdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, v114, 0x1Bu);
    if ( first_vdev )
    {
      v127 = (__int64)first_vdev;
      ch_width = spectral_vdev_get_ch_width();
      v130 = v129;
      wlan_objmgr_vdev_release_ref(v127, 0x1Bu, v131, ch_width, v132, v133, v134, v135, v136, v137, v138);
      a2[2] = v130;
LABEL_149:
      v15 = 0;
      goto LABEL_18;
    }
    v18 = "%s: Unable to get first vdev of pdev";
    v19 = "spectral_get_vdev";
    v20 = 3;
    goto LABEL_16;
  }
  if ( *((unsigned __int8 *)a2 + 4) > 0x23u )
  {
    if ( v14 != 36 )
    {
      if ( v14 == 37 )
      {
        v124 = (unsigned int)a2[2];
        v125 = (void (__fastcall *)(__int64, __int64))comp_private_obj[18];
        if ( *((_DWORD *)v125 - 1) != -1349071724 )
          __break(0x8228u);
        v125(a1, v124);
        goto LABEL_149;
      }
      if ( v14 == 38 )
      {
        v23 = (_DWORD *)comp_private_obj[16];
        if ( *(v23 - 1) != -907325943 )
          __break(0x8228u);
        *((_BYTE *)a2 + 8) = ((__int64 (__fastcall *)(__int64, _QWORD))v23)(a1, v10) & 1;
        goto LABEL_149;
      }
      goto LABEL_18;
    }
    v113 = (_DWORD *)comp_private_obj[15];
    if ( *(v113 - 1) != -1629486387 )
      __break(0x8228u);
    if ( !((unsigned int (__fastcall *)(__int64, _QWORD, int *))v113)(a1, v10, a2 + 2) )
      goto LABEL_149;
    goto LABEL_17;
  }
  switch ( v14 )
  {
    case 0x1Eu:
      v27 = *((unsigned __int16 *)a2 + 7);
      if ( v27 != 0xFFFF )
      {
        v28 = (_DWORD *)comp_private_obj[12];
        v29 = comp_private_obj;
        LODWORD(v148) = 3;
        HIDWORD(v148) = v27;
        if ( *(v28 - 1) != 1408301630 )
          __break(0x822Au);
        v30 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v28)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v29;
        if ( v30 )
          goto LABEL_17;
      }
      v31 = *((unsigned __int16 *)a2 + 4);
      if ( v31 != 0xFFFF )
      {
        v32 = (_DWORD *)comp_private_obj[12];
        v33 = comp_private_obj;
        LODWORD(v148) = 0;
        HIDWORD(v148) = v31;
        if ( *(v32 - 1) != 1408301630 )
          __break(0x8229u);
        v34 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v32)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v33;
        if ( v34 )
          goto LABEL_17;
      }
      v35 = *((unsigned __int16 *)a2 + 5);
      if ( v35 != 0xFFFF )
      {
        v36 = (_DWORD *)comp_private_obj[12];
        v37 = comp_private_obj;
        LODWORD(v148) = 1;
        HIDWORD(v148) = v35;
        if ( *(v36 - 1) != 1408301630 )
          __break(0x822Au);
        v38 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v36)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v37;
        if ( v38 )
          goto LABEL_17;
      }
      v39 = *((unsigned __int16 *)a2 + 6);
      if ( v39 != 0xFFFF )
      {
        v40 = (_DWORD *)comp_private_obj[12];
        v41 = comp_private_obj;
        LODWORD(v148) = 2;
        HIDWORD(v148) = v39;
        if ( *(v40 - 1) != 1408301630 )
          __break(0x822Au);
        v42 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v40)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v41;
        if ( v42 )
          goto LABEL_17;
      }
      v43 = *((unsigned __int16 *)a2 + 8);
      if ( v43 != 0xFFFF )
      {
        v44 = (_DWORD *)comp_private_obj[12];
        v45 = comp_private_obj;
        LODWORD(v148) = 4;
        HIDWORD(v148) = v43 != 0;
        if ( *(v44 - 1) != 1408301630 )
          __break(0x822Au);
        v46 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v44)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v45;
        if ( v46 )
          goto LABEL_17;
      }
      v47 = *((unsigned __int16 *)a2 + 10);
      if ( v47 != 0xFFFF )
      {
        v48 = (_DWORD *)comp_private_obj[12];
        v49 = comp_private_obj;
        LODWORD(v148) = 5;
        HIDWORD(v148) = v47;
        if ( *(v48 - 1) != 1408301630 )
          __break(0x822Au);
        v50 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v48)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v49;
        if ( v50 )
          goto LABEL_17;
      }
      v51 = *((unsigned __int16 *)a2 + 11);
      if ( v51 != 0xFFFF )
      {
        v52 = (_DWORD *)comp_private_obj[12];
        v53 = comp_private_obj;
        LODWORD(v148) = 6;
        HIDWORD(v148) = v51;
        if ( *(v52 - 1) != 1408301630 )
          __break(0x822Au);
        v54 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v52)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v53;
        if ( v54 )
          goto LABEL_17;
      }
      v55 = *((unsigned __int16 *)a2 + 12);
      if ( v55 != 0xFFFF )
      {
        v56 = (_DWORD *)comp_private_obj[12];
        v57 = comp_private_obj;
        LODWORD(v148) = 7;
        HIDWORD(v148) = v55;
        if ( *(v56 - 1) != 1408301630 )
          __break(0x822Au);
        v58 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v56)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v57;
        if ( v58 )
          goto LABEL_17;
      }
      v59 = *((unsigned __int16 *)a2 + 13);
      if ( v59 != 0xFFFF )
      {
        v60 = (_DWORD *)comp_private_obj[12];
        v61 = comp_private_obj;
        LODWORD(v148) = 8;
        HIDWORD(v148) = v59;
        if ( *(v60 - 1) != 1408301630 )
          __break(0x822Au);
        v62 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v60)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v61;
        if ( v62 )
          goto LABEL_17;
      }
      v63 = *((unsigned __int16 *)a2 + 14);
      if ( v63 != 0xFFFF )
      {
        v64 = (_DWORD *)comp_private_obj[12];
        v65 = comp_private_obj;
        LODWORD(v148) = 9;
        HIDWORD(v148) = v63;
        if ( *(v64 - 1) != 1408301630 )
          __break(0x822Au);
        v66 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v64)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v65;
        if ( v66 )
          goto LABEL_17;
      }
      v67 = *((unsigned __int16 *)a2 + 15);
      if ( v67 != 0xFFFF )
      {
        v68 = (_DWORD *)comp_private_obj[12];
        v69 = comp_private_obj;
        LODWORD(v148) = 10;
        HIDWORD(v148) = v67;
        if ( *(v68 - 1) != 1408301630 )
          __break(0x822Au);
        v70 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v68)(a1, &v148, v10, a2 + 22);
        comp_private_obj = v69;
        if ( v70 )
          goto LABEL_17;
      }
      v71 = *((unsigned __int16 *)a2 + 16);
      v72 = comp_private_obj;
      if ( v71 != 0xFFFF )
      {
        v73 = (_DWORD *)comp_private_obj[12];
        LODWORD(v148) = 11;
        HIDWORD(v148) = v71;
        if ( *(v73 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v73)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v74 = *((unsigned __int16 *)a2 + 17);
      if ( v74 != 0xFFFF )
      {
        v75 = (_DWORD *)v72[12];
        LODWORD(v148) = 12;
        HIDWORD(v148) = v74;
        if ( *(v75 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v75)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v76 = *((unsigned __int16 *)a2 + 18);
      if ( v76 != 0xFFFF )
      {
        v77 = (_DWORD *)v72[12];
        LODWORD(v148) = 13;
        HIDWORD(v148) = v76;
        if ( *(v77 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v77)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v78 = *((unsigned __int16 *)a2 + 19);
      if ( v78 != 0xFFFF )
      {
        v79 = (_DWORD *)v72[12];
        LODWORD(v148) = 14;
        HIDWORD(v148) = v78;
        if ( *(v79 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v79)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v80 = *((unsigned __int16 *)a2 + 20);
      if ( v80 != 0xFFFF )
      {
        v81 = (_DWORD *)v72[12];
        LODWORD(v148) = 15;
        HIDWORD(v148) = v80;
        if ( *(v81 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v81)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v82 = *((unsigned __int16 *)a2 + 21);
      if ( v82 != 0xFFFF )
      {
        v83 = (_DWORD *)v72[12];
        LODWORD(v148) = 16;
        HIDWORD(v148) = v82;
        if ( *(v83 - 1) != 1408301630 )
          __break(0x8229u);
        v84 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, int *))v83)(a1, &v148, v10, a2 + 22);
        v15 = 16;
        if ( v84 )
          break;
      }
      v85 = *((unsigned __int16 *)a2 + 22);
      if ( v85 != 0xFFFF )
      {
        v86 = (_DWORD *)v72[12];
        LODWORD(v148) = 17;
        HIDWORD(v148) = v85;
        if ( *(v86 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v86)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v87 = *((unsigned __int16 *)a2 + 23);
      if ( v87 != 0xFFFF )
      {
        v88 = (_DWORD *)v72[12];
        LODWORD(v148) = 18;
        HIDWORD(v148) = v87;
        if ( *(v88 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v88)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      v89 = *((unsigned __int16 *)a2 + 24);
      if ( v89 != 0xFFFF )
      {
        v90 = (_DWORD *)v72[12];
        LODWORD(v148) = 19;
        HIDWORD(v148) = v89;
        if ( *(v90 - 1) != 1408301630 )
          __break(0x822Au);
        if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v90)(a1, &v148, v10, a2 + 22) )
          goto LABEL_17;
      }
      if ( *((__int16 *)a2 + 25) == -1 )
        goto LABEL_156;
      vdev = spectral_get_vdev(a1, *((unsigned __int8 *)a2 + 5));
      if ( !vdev )
      {
LABEL_17:
        v15 = 16;
        break;
      }
      v100 = vdev;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(vdev, v92, v93, v94, v95, v96, v97, v98, v99);
      if ( cmpt_obj )
        v111 = *(unsigned __int8 *)(cmpt_obj + 417);
      else
        v111 = 0;
      wlan_objmgr_vdev_release_ref(v100, 0x1Bu, v102, v103, v104, v105, v106, v107, v108, v109, v110);
      v139 = *((unsigned __int16 *)a2 + 25);
      if ( (v139 & v111) != 0 )
      {
        v140 = (_DWORD *)v72[12];
        LODWORD(v148) = 20;
        HIDWORD(v148) = v139;
        if ( *(v140 - 1) != 1408301630 )
          __break(0x822Au);
        if ( !((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v140)(a1, &v148, v10, a2 + 22) )
        {
LABEL_156:
          v141 = a2[17];
          if ( v141 == 0xFFFF )
            goto LABEL_172;
          v142 = a2[18];
          LODWORD(v148) = 24;
          HIDWORD(v148) = v141;
          v143 = (_DWORD *)v72[12];
          v149 = v142;
          if ( *(v143 - 1) != 1408301630 )
            __break(0x8228u);
          if ( !((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v143)(a1, &v148, v10, a2 + 22) )
          {
LABEL_172:
            v144 = *((unsigned __int16 *)a2 + 38);
            if ( v144 == 0xFFFF )
              goto LABEL_173;
            v145 = (_DWORD *)v72[12];
            LODWORD(v148) = 26;
            HIDWORD(v148) = v144;
            if ( *(v145 - 1) != 1408301630 )
              __break(0x822Au);
            if ( !((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v145)(a1, &v148, v10, a2 + 22) )
            {
LABEL_173:
              v146 = a2[21];
              if ( v146 == 0xFFFF )
                goto LABEL_149;
              v147 = (_DWORD *)v72[12];
              LODWORD(v148) = 27;
              HIDWORD(v148) = v146;
              if ( *(v147 - 1) != 1408301630 )
                __break(0x822Au);
              if ( !((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD, int *))v147)(a1, &v148, v10, a2 + 22) )
                goto LABEL_149;
            }
          }
          goto LABEL_17;
        }
        goto LABEL_17;
      }
      v18 = "%s: Invalid Spectral Chainmask - Inactive Rx antenna chain cannot be an active spectral chain";
      goto LABEL_15;
    case 0x1Fu:
      v116 = (_DWORD *)comp_private_obj[13];
      if ( *(v116 - 1) != -570468167 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v116)(a1, v150, v10);
      v117 = *(_DWORD *)((char *)v150 + 2);
      v118 = *(_DWORD *)((char *)v150 + 6);
      *((_WORD *)a2 + 4) = v150[0];
      v119 = *(_QWORD *)((char *)&v150[1] + 4);
      *(int *)((char *)a2 + 10) = v117;
      v120 = *(_QWORD *)((char *)&v150[2] + 4);
      *(_QWORD *)(a2 + 5) = v119;
      v121 = *(_QWORD *)((char *)&v150[3] + 4);
      *(_QWORD *)(a2 + 7) = v120;
      *(_QWORD *)(a2 + 9) = v121;
      LODWORD(v120) = HIDWORD(v150[4]);
      LODWORD(v121) = v151;
      *(int *)((char *)a2 + 14) = v118;
      v122 = *(_QWORD *)((char *)&v153 + 4);
      a2[11] = v120;
      a2[12] = v121;
      LOWORD(v121) = WORD6(v153);
      LODWORD(v120) = HIDWORD(v154);
      *(_QWORD *)(a2 + 17) = v122;
      *((_WORD *)a2 + 38) = v121;
      a2[21] = v120;
      goto LABEL_149;
    case 0x23u:
      v16 = (_DWORD *)comp_private_obj[14];
      v17 = *((unsigned __int8 *)a2 + 5);
      if ( *(v16 - 1) != 694774377 )
        __break(0x8228u);
      if ( !((unsigned int (__fastcall *)(__int64, __int64, _QWORD, int *))v16)(a1, v17, v10, a2 + 2) )
        goto LABEL_149;
      goto LABEL_17;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v15;
}
