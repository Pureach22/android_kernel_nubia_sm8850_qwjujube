__int64 __fastcall sde_hdcp_1x_auth_work(__int64 a1)
{
  _BYTE *v1; // x21
  int *v2; // x27
  __int64 v4; // x1
  __int64 result; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x0
  void *v8; // x0
  int v9; // w8
  __int64 v10; // x20
  int v11; // w0
  __int64 v12; // x22
  int v13; // w25
  unsigned int v14; // w20
  _BYTE *v15; // x23
  int v16; // w28
  __int64 v17; // x2
  __int64 v18; // x1
  int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x20
  __int64 v22; // x22
  __int64 v23; // x23
  __int64 v24; // x0
  unsigned int v25; // w8
  __int64 v26; // x23
  void *v27; // x0
  const char *v28; // x1
  const char *v29; // x1
  void *v30; // x0
  __int64 v31; // x0
  __int64 v32; // x22
  __int64 v33; // x0
  __int64 v34; // x22
  __int64 v35; // x22
  __int64 v36; // x23
  int v37; // w0
  int v38; // w8
  int v39; // w0
  int v40; // w8
  int v41; // w0
  __int64 v42; // x1
  int v43; // w0
  int v44; // w8
  int v45; // w20
  unsigned int v46; // w23
  __int64 v47; // x24
  int v48; // w28
  unsigned int v49; // w8
  unsigned int v50; // w9
  unsigned int v51; // w10
  unsigned int v52; // w11
  unsigned int v53; // w23
  int v54; // w9
  int v55; // w10
  int v56; // w20
  unsigned int v57; // w22
  __int64 *v58; // x23
  int v59; // w26
  _BOOL4 v60; // w8
  int v61; // w10
  int v62; // w20
  unsigned int v63; // w22
  int *v64; // x23
  int v65; // w26
  int v66; // w8
  int v67; // w8
  int v68; // w20
  unsigned int v69; // w22
  _BYTE *v70; // x23
  int v71; // w26
  int v72; // w25
  int v73; // w20
  unsigned int v74; // w22
  _BYTE *v75; // x23
  int v76; // w28
  void *v77; // x0
  int v78; // w22
  int v79; // w20
  unsigned int v80; // w23
  __int64 *v81; // x24
  int v82; // w28
  int v83; // w8
  int v84; // w20
  unsigned int v85; // w22
  __int64 *v86; // x23
  int v87; // w26
  int v88; // w9
  int v89; // w8
  char v90; // w10
  __int64 v91; // x0
  __int64 v92; // x1
  unsigned int v93; // w12
  int v94; // w8
  unsigned int v95; // w9
  __int64 v96; // x24
  unsigned int v97; // w23
  unsigned int v98; // w28
  unsigned int v99; // w9
  int v100; // w8
  unsigned int v101; // w22
  void *v102; // x22
  const char *v103; // x1
  void *v104; // x0
  int v105; // w8
  unsigned int v106; // w9
  unsigned int v107; // w9
  unsigned int v108; // w9
  __int64 *v109; // x25
  int v110; // w20
  int v111; // w26
  __int64 v112; // x2
  __int64 v113; // x23
  __int64 v114; // x22
  int v115; // w20
  unsigned int v116; // w20
  int v117; // w24
  __int64 v118; // x0
  __int64 v119; // x21
  __int64 v120; // x0
  __int64 v121; // x21
  int v122; // w20
  void *v123; // x0
  __int64 v124; // x0
  __int64 v125; // x21
  __int64 v126; // x0
  __int64 v127; // x21
  __int64 v128; // x0
  int v129; // w10
  int v130; // w9
  unsigned int v131; // w0
  int v132; // w8
  int v133; // w23
  int v134; // w26
  unsigned int v135; // w28
  __int64 v136; // x21
  int v137; // w25
  _DWORD *v138; // [xsp+0h] [xbp-150h]
  _BYTE *v139; // [xsp+8h] [xbp-148h]
  int v140; // [xsp+10h] [xbp-140h]
  unsigned int v141; // [xsp+18h] [xbp-138h]
  unsigned int v142; // [xsp+20h] [xbp-130h]
  __int64 v143; // [xsp+28h] [xbp-128h]
  _BYTE *v144; // [xsp+28h] [xbp-128h]
  unsigned int v145; // [xsp+28h] [xbp-128h]
  _BYTE *v146; // [xsp+30h] [xbp-120h]
  __int64 v147; // [xsp+30h] [xbp-120h]
  int v148; // [xsp+38h] [xbp-118h] BYREF
  char v149; // [xsp+3Ch] [xbp-114h]
  __int64 v150; // [xsp+40h] [xbp-110h] BYREF
  __int64 v151; // [xsp+48h] [xbp-108h]
  __int64 v152; // [xsp+50h] [xbp-100h]
  __int64 v153; // [xsp+58h] [xbp-F8h]
  __int64 v154; // [xsp+60h] [xbp-F0h]
  __int64 v155; // [xsp+68h] [xbp-E8h]
  __int64 v156; // [xsp+70h] [xbp-E0h]
  __int64 v157; // [xsp+78h] [xbp-D8h]
  __int64 v158; // [xsp+80h] [xbp-D0h]
  __int64 v159; // [xsp+88h] [xbp-C8h]
  __int64 v160; // [xsp+90h] [xbp-C0h]
  __int64 v161; // [xsp+98h] [xbp-B8h]
  __int64 v162; // [xsp+A0h] [xbp-B0h]
  __int64 v163; // [xsp+A8h] [xbp-A8h]
  __int64 v164; // [xsp+B0h] [xbp-A0h]
  __int64 v165; // [xsp+B8h] [xbp-98h]
  __int64 v166; // [xsp+C0h] [xbp-90h]
  __int64 v167; // [xsp+C8h] [xbp-88h]
  __int64 v168; // [xsp+D0h] [xbp-80h]
  __int64 v169; // [xsp+D8h] [xbp-78h]
  __int64 v170; // [xsp+E0h] [xbp-70h]
  __int64 v171; // [xsp+E8h] [xbp-68h]
  __int64 v172; // [xsp+F0h] [xbp-60h]
  __int64 v173; // [xsp+F8h] [xbp-58h]
  __int64 v174; // [xsp+100h] [xbp-50h]
  __int64 v175; // [xsp+108h] [xbp-48h]
  __int64 v176; // [xsp+110h] [xbp-40h]
  __int64 v177; // [xsp+118h] [xbp-38h]
  __int64 v178; // [xsp+120h] [xbp-30h]
  __int64 v179; // [xsp+128h] [xbp-28h]
  _QWORD v180[4]; // [xsp+130h] [xbp-20h]

  v1 = (_BYTE *)(a1 - 704);
  v180[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 704 )
  {
    v8 = &unk_255B25;
LABEL_15:
    result = printk(v8, "sde_hdcp_1x_auth_work");
    goto LABEL_16;
  }
  v2 = (int *)(a1 - 664);
  if ( *(_DWORD *)(a1 - 664) != 1 )
  {
    v8 = &unk_21817B;
    goto LABEL_15;
  }
  if ( *(_DWORD *)(a1 - 668) )
    goto LABEL_4;
  v9 = *(_DWORD *)(a1 + 296);
  *(_WORD *)(a1 - 672) = 0;
  *(_BYTE *)(a1 - 670) = 0;
  if ( v9 == 1 )
  {
    dss_reg_w(*(_QWORD *)(a1 + 192), 24, 65555, 1);
    v9 = *(_DWORD *)(a1 + 296);
  }
  if ( !v9 || *(_BYTE *)(a1 - 669) == 1 )
    hdcp1_set_enc(*(_QWORD *)(a1 + 744), 1);
  if ( *v2 != 1 )
  {
    printk(&unk_21817B, "sde_hdcp_1x_authentication_part1");
    goto LABEL_4;
  }
  v10 = *(_QWORD *)(a1 + 184);
  v11 = dss_reg_r(v10, *(unsigned int *)(a1 + 424), 1);
  dss_reg_w(
    v10,
    *(unsigned int *)(a1 + 424),
    *(_DWORD *)(a1 + 452)
  | *(_DWORD *)(a1 + 456)
  | v11
  | *(_DWORD *)(a1 + 460)
  | *(_DWORD *)(a1 + 472)
  | *(_DWORD *)(a1 + 464)
  | *(_DWORD *)(a1 + 468)
  | *(_DWORD *)(a1 + 476)
  | *(_DWORD *)(a1 + 428)
  | *(_DWORD *)(a1 + 432)
  | (unsigned int)(*(_DWORD *)(a1 + 436) | *(_DWORD *)(a1 + 440)),
    1);
  if ( *v2 != 1 )
  {
    v27 = &unk_21817B;
LABEL_46:
    v28 = "sde_hdcp_1x_read_bcaps";
    goto LABEL_47;
  }
  v146 = (_BYTE *)(a1 - 670);
  v12 = *(_QWORD *)(a1 + 224);
  if ( *(_DWORD *)(a1 + 296) == 1 )
  {
    v13 = *(_DWORD *)(a1 + 516);
    v14 = *(_DWORD *)(a1 + 512);
    v15 = v1;
    while ( 1 )
    {
      v16 = v13 >= 15 ? 15 : v13;
      if ( v16 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v14, v15, v16) )
        break;
      v13 -= v16;
      v15 += v16;
      v14 += v16;
      if ( v13 <= 0 )
        goto LABEL_31;
    }
    printk(&unk_26ECF1, "sde_hdcp_1x_read");
    v27 = &unk_21F82D;
    goto LABEL_46;
  }
LABEL_31:
  v17 = (unsigned __int8)*v1;
  v18 = *(unsigned int *)(a1 + 408);
  if ( (*(_DWORD *)(a1 + 420) & (unsigned int)v17) != 0 )
    v19 = 2;
  else
    v19 = 1;
  *(_DWORD *)(a1 - 660) = v19;
  v20 = dss_reg_w(v12, v18, v17, 1);
  if ( *v2 != 1 )
  {
    v27 = &unk_21817B;
    v28 = "sde_hdcp_1x_wait_for_hw_ready";
LABEL_47:
    printk(v27, v28);
LABEL_48:
    v29 = "sde_hdcp_1x_authentication_part1";
    goto LABEL_49;
  }
  v21 = *(_QWORD *)(a1 + 184);
  v22 = *(_QWORD *)(a1 + 192);
  v23 = ktime_get(v20);
  v24 = readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312));
  v25 = ((unsigned int)v24 >> *(_DWORD *)(a1 + 316)) & 7;
  if ( v25 != 3 )
  {
    if ( *v2 == 1 )
    {
      v26 = v23 + 2000000000;
      while ( ktime_get(v24) <= v26 )
      {
        usleep_range_state(5001, 20000, 2);
        __yield();
        v24 = readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312));
        v25 = ((unsigned int)v24 >> *(_DWORD *)(a1 + 316)) & 7;
        if ( v25 == 3 )
          goto LABEL_54;
        if ( *v2 != 1 )
          goto LABEL_51;
      }
      v25 = ((unsigned int)readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312)) >> *(_DWORD *)(a1 + 316)) & 7;
    }
LABEL_51:
    if ( v25 != 3 && *v2 == 1 )
    {
      v30 = &unk_233AFC;
LABEL_65:
      printk(v30, "sde_hdcp_1x_wait_for_hw_ready");
      goto LABEL_48;
    }
  }
LABEL_54:
  v31 = dss_reg_w(v22, *(unsigned int *)(a1 + 368), 0, 1);
  v32 = ktime_get(v31);
  v33 = readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312));
  if ( (v33 & 0x300) == 0 && *v2 == 1 )
  {
    v34 = v32 + 2000000000;
    while ( ktime_get(v33) <= v34 )
    {
      usleep_range_state(5001, 20000, 2);
      __yield();
      v33 = readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312));
      if ( (v33 & 0x300) != 0 || *v2 != 1 )
        goto LABEL_62;
    }
    LOWORD(v33) = readl(*(_QWORD *)(v21 + 8) + *(unsigned int *)(a1 + 312));
  }
LABEL_62:
  if ( (v33 & 0x300) == 0 && *v2 == 1 )
  {
    v30 = &unk_24E7EE;
    goto LABEL_65;
  }
  msleep(20);
  if ( *v2 != 1 )
    goto LABEL_48;
  v36 = *(_QWORD *)(a1 + 184);
  v35 = *(_QWORD *)(a1 + 192);
  v37 = dss_reg_r(v36, *(unsigned int *)(a1 + 372), 1);
  v38 = *(_DWORD *)(a1 + 296);
  *(_DWORD *)(a1 - 696) = v37;
  if ( v38 == 1 )
  {
    _const_udelay(4295);
    *(_DWORD *)(a1 - 696) = dss_reg_r(v36, *(unsigned int *)(a1 + 372), 1);
  }
  v138 = (_DWORD *)(a1 - 660);
  v39 = dss_reg_r(v36, *(unsigned int *)(a1 + 376), 1);
  v40 = *(_DWORD *)(a1 + 296);
  *(_DWORD *)(a1 - 692) = v39;
  if ( v40 == 1 )
  {
    _const_udelay(4295);
    *(_DWORD *)(a1 - 692) = dss_reg_r(v36, *(unsigned int *)(a1 + 376), 1);
  }
  v41 = dss_reg_r(v35, *(unsigned int *)(a1 + 364), 1);
  v42 = *(unsigned int *)(a1 + 368);
  *(_DWORD *)(a1 - 688) = v41;
  v43 = dss_reg_r(v35, v42, 1);
  v44 = *(_DWORD *)(a1 + 296);
  v143 = *(_QWORD *)(a1 + 224);
  *(_DWORD *)(a1 - 684) = v43;
  if ( v44 == 1 )
  {
    v45 = *(_DWORD *)(a1 + 532);
    v46 = *(_DWORD *)(a1 + 528);
    v47 = a1 - 656;
    while ( 1 )
    {
      v48 = v45 >= 15 ? 15 : v45;
      if ( v48 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v46, v47, v48) )
        break;
      v45 -= v48;
      v47 += v48;
      v46 += v48;
      if ( v45 <= 0 )
        goto LABEL_78;
    }
    printk(&unk_26ECF1, "sde_hdcp_1x_read");
    v27 = &unk_244ABE;
    v28 = "sde_hdcp_1x_get_bksv_from_sink";
    goto LABEL_47;
  }
LABEL_78:
  v49 = *(unsigned __int8 *)(a1 - 656);
  v50 = *(unsigned __int8 *)(a1 - 655);
  v51 = *(unsigned __int8 *)(a1 - 654);
  v52 = *(unsigned __int8 *)(a1 - 653);
  v53 = *(unsigned __int8 *)(a1 - 652);
  if ( (v49 & 1)
     + (v49 >> 7)
     + ((v49 >> 1) & 1)
     + ((v49 >> 2) & 1)
     + ((v49 >> 3) & 1)
     + ((v49 >> 4) & 1)
     + ((v49 >> 5) & 1)
     + ((v49 >> 6) & 1)
     + (v50 & 1)
     + (v50 >> 7)
     + ((v50 >> 1) & 1)
     + ((v50 >> 2) & 1)
     + ((v50 >> 3) & 1)
     + ((v50 >> 4) & 1)
     + ((v50 >> 5) & 1)
     + ((v50 >> 6) & 1)
     + (v51 & 1)
     + (v51 >> 7)
     + ((v51 >> 1) & 1)
     + ((v51 >> 2) & 1)
     + ((v51 >> 3) & 1)
     + ((v51 >> 4) & 1)
     + ((v51 >> 5) & 1)
     + ((v51 >> 6) & 1)
     + (v52 & 1)
     + (v52 >> 7)
     + ((v52 >> 1) & 1)
     + ((v52 >> 2) & 1)
     + ((v52 >> 3) & 1)
     + ((v52 >> 4) & 1)
     + ((v52 >> 5) & 1)
     + ((v52 >> 6) & 1)
     + (v53 & 1)
     + (v53 >> 7)
     + ((v53 >> 1) & 1)
     + ((v53 >> 2) & 1)
     + ((v53 >> 3) & 1)
     + ((v53 >> 4) & 1)
     + ((v53 >> 5) & 1)
     + ((v53 >> 6) & 1) != 20 )
  {
    printk(&unk_24B261, "sde_hdcp_1x_get_bksv_from_sink");
    goto LABEL_48;
  }
  dss_reg_w(v143, *(unsigned int *)(a1 + 380), v49 | (((v52 << 16) | (v51 << 8) | v50) << 8), 1);
  dss_reg_w(v143, *(unsigned int *)(a1 + 384), v53, 1);
  if ( *v2 != 1 )
  {
    v27 = &unk_21817B;
LABEL_106:
    v28 = "sde_hdcp_1x_send_an_aksv_to_sink";
    goto LABEL_47;
  }
  v54 = *(_DWORD *)(a1 + 296);
  v55 = *(_DWORD *)(a1 - 692);
  LODWORD(v150) = *(_DWORD *)(a1 - 696);
  HIDWORD(v150) = v55;
  if ( v54 == 1 )
  {
    v56 = *(_DWORD *)(a1 + 692);
    v57 = *(_DWORD *)(a1 + 688);
    v58 = &v150;
    while ( 1 )
    {
      v59 = v56 >= 16 ? 16 : v56;
      if ( v59 != (unsigned int)drm_dp_dpcd_write(*(_QWORD *)(a1 + 232), v57, v58, v59) )
        break;
      v56 -= v59;
      v58 = (__int64 *)((char *)v58 + v59);
      v57 += v59;
      if ( v56 <= 0 )
      {
        v60 = *(_DWORD *)(a1 + 296) == 1;
        goto LABEL_92;
      }
    }
    printk(&unk_26ECF1, "sde_hdcp_1x_write");
    v27 = &unk_233B1E;
    goto LABEL_106;
  }
  v60 = 0;
LABEL_92:
  v61 = *(_DWORD *)(a1 - 684);
  v148 = *(_DWORD *)(a1 - 688);
  v149 = v61;
  if ( v60 )
  {
    v62 = *(_DWORD *)(a1 + 708);
    v63 = *(_DWORD *)(a1 + 704);
    v64 = &v148;
    while ( 1 )
    {
      v65 = v62 >= 16 ? 16 : v62;
      if ( v65 != (unsigned int)drm_dp_dpcd_write(*(_QWORD *)(a1 + 232), v63, v64, v65) )
        break;
      v62 -= v65;
      v64 = (int *)((char *)v64 + v65);
      v63 += v65;
      if ( v62 <= 0 )
        goto LABEL_99;
    }
    printk(&unk_26ECF1, "sde_hdcp_1x_write");
    v27 = &unk_244B0E;
    goto LABEL_106;
  }
LABEL_99:
  sde_hdcp_1x_enable_sink_irq_hpd(v1);
  if ( (unsigned int)sde_hdcp_1x_verify_r0(v1) )
    goto LABEL_48;
  printk(&unk_2677ED, "sde_hdcp_1x_authentication_part1");
  if ( *v138 != 2 )
  {
    *v2 = 2;
    goto LABEL_102;
  }
  if ( *v2 != 1 )
  {
    v77 = &unk_21817B;
    goto LABEL_164;
  }
  v67 = *(_DWORD *)(a1 + 296);
  if ( v67 == 1 )
  {
    v68 = *(_DWORD *)(a1 + 516);
    v69 = *(_DWORD *)(a1 + 512);
    v70 = v1;
    do
    {
      if ( v68 >= 15 )
        v71 = 15;
      else
        v71 = v68;
      if ( v71 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v69, v70, v71) )
        goto LABEL_131;
      v68 -= v71;
      v70 += v71;
      v69 += v71;
    }
    while ( v68 > 0 );
    v67 = *(_DWORD *)(a1 + 296);
  }
  v144 = (_BYTE *)(a1 - 671);
  if ( v67 )
  {
    LOBYTE(v150) = 0;
    v78 = jiffies_to_msecs(jiffies);
    while ( 1 )
    {
      if ( *(_DWORD *)(a1 + 296) == 1 )
      {
        v79 = *(_DWORD *)(a1 + 580);
        v80 = *(_DWORD *)(a1 + 576);
        v81 = &v150;
        do
        {
          if ( v79 >= 15 )
            v82 = 15;
          else
            v82 = v79;
          if ( v82 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v80, v81, v82) )
          {
            printk(&unk_26ECF1, "sde_hdcp_1x_read");
            goto LABEL_4;
          }
          v79 -= v82;
          v81 = (__int64 *)((char *)v81 + v82);
          v80 += v82;
        }
        while ( v79 > 0 );
      }
      if ( (v150 & 1) != 0 )
        break;
      v83 = v78 - jiffies_to_msecs(jiffies);
      if ( v83 < 0 )
        v83 = -v83;
      if ( v83 >= 5001 )
        goto LABEL_163;
      if ( (*v146 & 1) != 0 || (*v144 & 1) != 0 || *v2 != 1 )
        break;
      msleep(20);
    }
    if ( !v78 )
      goto LABEL_163;
    goto LABEL_150;
  }
  if ( (*v1 & 0x20) != 0 )
  {
LABEL_150:
    if ( (*v144 & 1) == 0 && *v2 == 1 )
    {
      LOWORD(v150) = 0;
      *v146 = 0;
      goto LABEL_153;
    }
LABEL_163:
    v77 = &unk_25928E;
    goto LABEL_164;
  }
  v72 = 50;
  while ( 1 )
  {
    if ( !--v72 )
      goto LABEL_163;
    if ( *(_DWORD *)(a1 + 296) == 1 )
    {
      v73 = *(_DWORD *)(a1 + 516);
      v74 = *(_DWORD *)(a1 + 512);
      v75 = v1;
      while ( 1 )
      {
        v76 = v73 >= 15 ? 15 : v73;
        if ( v76 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v74, v75, v76) )
          break;
        v73 -= v76;
        v75 += v76;
        v74 += v76;
        if ( v73 <= 0 )
          goto LABEL_127;
      }
LABEL_131:
      printk(&unk_26ECF1, "sde_hdcp_1x_read");
      v77 = &unk_21F82D;
LABEL_164:
      printk(v77, "sde_hdcp_1x_wait_for_ksv_ready");
      goto LABEL_4;
    }
LABEL_127:
    if ( *v2 != 1 )
      break;
    msleep(100);
    if ( (*v1 & 0x20) != 0 )
      goto LABEL_150;
  }
  printk(&unk_21F82D, "sde_hdcp_1x_wait_for_ksv_ready");
  v132 = *v2;
  LOWORD(v150) = 0;
  *v146 = 0;
  if ( v132 != 1 )
  {
    v104 = &unk_21817B;
    goto LABEL_248;
  }
LABEL_153:
  if ( *(_DWORD *)(a1 + 296) == 1 )
  {
    v84 = *(_DWORD *)(a1 + 564);
    v85 = *(_DWORD *)(a1 + 560);
    v86 = &v150;
    do
    {
      if ( v84 >= 15 )
        v87 = 15;
      else
        v87 = v84;
      if ( v87 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v85, v86, v87) )
      {
        printk(&unk_26ECF1, "sde_hdcp_1x_read");
        v104 = &unk_21819D;
        goto LABEL_248;
      }
      v84 -= v87;
      v86 = (__int64 *)((char *)v86 + v87);
      v85 += v87;
    }
    while ( v84 > 0 );
    v88 = (char)v150;
    if ( (char)v150 < 0 )
    {
      v104 = &unk_24E80F;
    }
    else
    {
      v89 = BYTE1(v150);
      if ( (v150 & 0x800) == 0 )
      {
        v90 = BYTE1(v150) & 7;
        goto LABEL_166;
      }
      v104 = &unk_24E84C;
    }
LABEL_248:
    v103 = "sde_hdcp_1x_validate_downstream";
LABEL_249:
    printk(v104, v103);
LABEL_250:
    v29 = "sde_hdcp_1x_authentication_part2";
LABEL_49:
    printk(&unk_260C51, v29);
LABEL_4:
    if ( *v2 )
      *v2 = 3;
LABEL_6:
    v4 = *(_QWORD *)(a1 + 736);
LABEL_7:
    *(_QWORD *)(v4 + 8) = 0;
    *(_QWORD *)(v4 + 16) = 0;
    *(_QWORD *)v4 = 0;
    goto LABEL_8;
  }
  v89 = 0;
  v88 = 0;
  v90 = 0;
LABEL_166:
  v91 = *(_QWORD *)(a1 + 224);
  v139 = (_BYTE *)(a1 - 651);
  v92 = *(unsigned int *)(a1 + 408);
  *(_BYTE *)(a1 - 651) = v88;
  v93 = (unsigned __int8)*v1;
  *(_QWORD *)(a1 - 12) = 0;
  *(_BYTE *)(a1 - 650) = v90;
  dss_reg_w(v91, v92, (v88 << 8) | (v89 << 16) | v93, 1);
  if ( *v2 != 1 )
  {
    v102 = &unk_21817B;
LABEL_171:
    v103 = "sde_hdcp_1x_read_ksv_fifo";
    v104 = v102;
    goto LABEL_249;
  }
  v147 = a1 - 649;
  memset((void *)(a1 - 649), 0, 0x27Bu);
  v94 = (unsigned __int8)*v139;
  *(_DWORD *)(a1 + 596) = 5 * v94;
  if ( v94 )
  {
    v133 = 19;
    v102 = &unk_272199;
    while ( *(_DWORD *)(a1 + 296) == 1 )
    {
      v134 = *(_DWORD *)(a1 + 596);
      v135 = *(_DWORD *)(a1 + 592);
      v136 = a1 - 649;
      while ( 1 )
      {
        v137 = v134 >= 15 ? 15 : v134;
        if ( v137 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v135, v136, v137) )
          break;
        v134 -= v137;
        v136 += v137;
        if ( v134 <= 0 )
          goto LABEL_168;
      }
      printk(&unk_26ECF1, "sde_hdcp_1x_read");
      printk(&unk_26ED33, "sde_hdcp_1x_read_ksv_fifo");
      if ( !--v133 )
        goto LABEL_171;
    }
  }
LABEL_168:
  v95 = *(_DWORD *)(a1 + 400);
  v96 = *(_QWORD *)(a1 + 224);
  *(_QWORD *)((char *)v180 + 7) = 0;
  v97 = *(_DWORD *)(a1 + 388);
  v98 = *(_DWORD *)(a1 + 392);
  v141 = v95;
  v99 = *(_DWORD *)(a1 + 404);
  v142 = *(_DWORD *)(a1 + 396);
  v100 = *v2;
  v101 = *(_DWORD *)(a1 + 608);
  v179 = 0;
  v180[0] = 0;
  v177 = 0;
  v178 = 0;
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
  v166 = 0;
  v163 = 0;
  v164 = 0;
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v157 = 0;
  v158 = 0;
  v155 = 0;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v145 = v99;
  v151 = 0;
  v152 = 0;
  v150 = 0;
  if ( v100 != 1 )
  {
LABEL_233:
    v104 = &unk_21817B;
    v103 = "sde_hdcp_1x_transfer_v_h";
    goto LABEL_249;
  }
  v140 = 3;
  while ( 2 )
  {
    if ( *(_DWORD *)(a1 + 296) == 1 )
    {
      v109 = &v150;
      v110 = *(_DWORD *)(a1 + 660)
           + *(_DWORD *)(a1 + 676)
           + *(_DWORD *)(a1 + 644)
           + *(_DWORD *)(a1 + 628)
           + *(_DWORD *)(a1 + 612);
      while ( 1 )
      {
        v111 = v110 >= 15 ? 15 : v110;
        if ( v111 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 232), v101, v109, v111) )
          break;
        v110 -= v111;
        v109 = (__int64 *)((char *)v109 + v111);
        v101 += v111;
        if ( v110 <= 0 )
        {
          v112 = (unsigned int)v150;
          goto LABEL_185;
        }
      }
      printk(&unk_26ECF1, "sde_hdcp_1x_read");
      printk(&unk_26780C, "sde_hdcp_1x_transfer_v_h");
      goto LABEL_250;
    }
    v112 = 0;
LABEL_185:
    dss_reg_w(v96, v97, v112, 1);
    dss_reg_w(v96, v98, HIDWORD(v150), 1);
    dss_reg_w(v96, v142, (unsigned int)v151, 1);
    dss_reg_w(v96, v141, HIDWORD(v151), 1);
    dss_reg_w(v96, v145, (unsigned int)v152, 1);
    if ( *v139 )
    {
      if ( *v2 == 1 )
      {
        v113 = *(_QWORD *)(a1 + 224);
        v114 = *(_QWORD *)(a1 + 184);
        v115 = *(_DWORD *)(a1 + 596);
        dss_reg_w(v113, *(unsigned int *)(a1 + 348), 1, 1);
        dss_reg_w(v113, *(unsigned int *)(a1 + 348), 0, 1);
        v116 = v115 - 1;
        if ( v116 )
        {
          v117 = 0;
          do
          {
            v118 = dss_reg_w(v113, *(unsigned int *)(a1 + 352), *(unsigned __int8 *)(v147 + v117) << 16, 0);
            if ( v117 )
            {
              if ( (++v117 & 0x3F) == 0 )
              {
                v119 = ktime_get(v118);
                v120 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
                if ( (v120 & 1) == 0 )
                {
                  v121 = v119 + 2000000000;
                  if ( *v2 == 1 )
                  {
                    while ( ktime_get(v120) <= v121 )
                    {
                      usleep_range_state(5001, 20000, 2);
                      __yield();
                      v120 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
                      if ( (v120 & 1) != 0 || *v2 != 1 )
                        goto LABEL_200;
                    }
                    LOBYTE(v120) = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
                  }
                }
LABEL_200:
                if ( (v120 & 1) == 0 && *v2 == 1 )
                {
                  v122 = -110;
                  v123 = &unk_260C8A;
                  goto LABEL_230;
                }
              }
            }
            else
            {
              v117 = 1;
            }
          }
          while ( v117 != v116 );
        }
        v124 = dss_reg_w(v113, *(unsigned int *)(a1 + 352), (*(unsigned __int8 *)(v147 + v116) << 16) | 1u, 0);
        v125 = ktime_get(v124);
        v126 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
        if ( (v126 & 0x10) == 0 && *v2 == 1 )
        {
          while ( ktime_get(v126) <= v125 + 2000000000 )
          {
            usleep_range_state(5001, 20000, 2);
            __yield();
            v126 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
            if ( (v126 & 0x10) != 0 || *v2 != 1 )
              goto LABEL_210;
          }
          v126 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 356));
        }
LABEL_210:
        if ( (v126 & 0x10) == 0 && *v2 == 1 )
        {
          v122 = -110;
          v123 = &unk_26B237;
          goto LABEL_230;
        }
        v127 = ktime_get(v126);
        v128 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 312));
        if ( (((unsigned __int64)(unsigned int)v128 >> *(_DWORD *)(a1 + 324)) & 1) != 0 )
        {
LABEL_213:
          v122 = 0;
          goto LABEL_214;
        }
        v105 = *v2;
        if ( *v2 == 1 )
        {
          while ( ktime_get(v128) <= v127 + 2000000000 )
          {
            usleep_range_state(5001, 20000, 2);
            __yield();
            v128 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 312));
            if ( (((unsigned __int64)(unsigned int)v128 >> *(_DWORD *)(a1 + 324)) & 1) != 0 )
              goto LABEL_213;
            v105 = *v2;
            if ( *v2 != 1 )
              goto LABEL_219;
          }
          v131 = readl(*(_QWORD *)(v114 + 8) + *(unsigned int *)(a1 + 312));
          v122 = 0;
          v105 = *v2;
          if ( (((unsigned __int64)v131 >> *(_DWORD *)(a1 + 324)) & 1) == 0 && v105 == 1 )
          {
            v122 = -22;
            v123 = &unk_26ED64;
LABEL_230:
            printk(v123, "sde_hdcp_1x_write_ksv_fifo");
LABEL_214:
            v105 = *v2;
          }
        }
        else
        {
LABEL_219:
          v122 = 0;
        }
        v129 = v140;
        if ( v105 == 1 )
          v130 = v122;
        else
          v130 = -22;
        --v140;
        if ( v129 == 1 || !v130 )
        {
          if ( v130 )
            goto LABEL_250;
          break;
        }
      }
      else
      {
        printk(&unk_21817B, "sde_hdcp_1x_write_ksv_fifo");
        if ( !--v140 )
          goto LABEL_250;
        v105 = *v2;
      }
      v96 = *(_QWORD *)(a1 + 224);
      v97 = *(_DWORD *)(a1 + 388);
      *(_QWORD *)((char *)v180 + 7) = 0;
      v106 = *(_DWORD *)(a1 + 396);
      v98 = *(_DWORD *)(a1 + 392);
      v101 = *(_DWORD *)(a1 + 608);
      v179 = 0;
      v180[0] = 0;
      v142 = v106;
      v107 = *(_DWORD *)(a1 + 400);
      v177 = 0;
      v178 = 0;
      v141 = v107;
      v108 = *(_DWORD *)(a1 + 404);
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
      v166 = 0;
      v163 = 0;
      v164 = 0;
      v161 = 0;
      v162 = 0;
      v159 = 0;
      v160 = 0;
      v157 = 0;
      v158 = 0;
      v155 = 0;
      v156 = 0;
      v153 = 0;
      v154 = 0;
      v145 = v108;
      v151 = 0;
      v152 = 0;
      v150 = 0;
      if ( v105 != 1 )
        goto LABEL_233;
      continue;
    }
    break;
  }
  *v2 = 2;
  printk(&unk_2677ED, "sde_hdcp_1x_authentication_part2");
  if ( *v2 != 2 )
    goto LABEL_6;
LABEL_102:
  msm_hdcp_cache_repeater_topology(*(_QWORD *)(a1 + 168), v138);
  msm_hdcp_notify_topology(*(_QWORD *)(a1 + 168));
  v4 = *(_QWORD *)(a1 + 736);
  if ( *v2 != 2 )
    goto LABEL_7;
  *(_DWORD *)v4 = *(unsigned __int8 *)(a1 - 650);
  *(_DWORD *)(v4 + 4) = *(unsigned __int8 *)(a1 - 651);
  *(_DWORD *)(v4 + 8) = *(_DWORD *)(a1 - 8);
  v66 = *(_DWORD *)(a1 - 12);
  *(_QWORD *)(v4 + 16) = 0;
  *(_DWORD *)(v4 + 12) = v66;
LABEL_8:
  result = hdcp1_ops_notify(*(_QWORD *)(a1 + 744));
  v6 = *(__int64 (__fastcall **)(_QWORD))(a1 + 264);
  if ( v6 && *v2 )
  {
    v7 = *(_QWORD *)(a1 + 256);
    if ( *((_DWORD *)v6 - 1) != -815732472 )
      __break(0x8228u);
    result = v6(v7);
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
