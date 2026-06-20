size_t __fastcall cam_cpas_update_monitor_array(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x24
  __int64 v4; // x23
  unsigned __int64 v5; // x21
  __int64 v7; // x25
  unsigned __int64 v8; // x27
  __int64 v9; // x19
  _DWORD *v10; // x20
  size_t result; // x0
  unsigned __int64 v12; // x2
  unsigned int v13; // w8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x9
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x11
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 v32; // x9
  __int64 v33; // x11
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x11
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x9
  __int64 v42; // x10
  __int64 v43; // x11
  __int64 v44; // x9
  __int64 v45; // x10
  __int64 v46; // x9
  __int64 v47; // x11
  __int64 v48; // x9
  __int64 v49; // x10
  __int64 v50; // x9
  __int64 v51; // x11
  __int64 v52; // x10
  __int64 v53; // x9
  __int64 v54; // x10
  __int64 v55; // x10
  char v56; // w12
  __int64 v57; // x10
  __int64 v58; // x11
  __int64 v59; // x10
  __int64 v60; // x11
  __int64 v61; // x10
  __int64 v62; // x11
  __int64 v63; // x10
  __int64 v64; // x11
  __int64 v65; // x10
  __int64 v66; // x11
  __int64 v67; // x10
  __int64 v68; // x11
  __int64 v69; // x10
  __int64 v70; // x11
  __int64 v71; // x10
  __int64 v72; // x10
  __int64 v73; // x11
  __int64 v74; // x10
  __int64 v75; // x11
  __int64 v76; // x10
  __int64 v77; // x11
  __int64 v78; // x10
  __int64 v79; // x11
  __int64 v80; // x10
  __int64 v81; // x11
  __int64 v82; // x10
  __int64 v83; // x11
  __int64 v84; // x10
  __int64 v85; // x11
  __int64 v86; // x10
  __int64 v87; // x10
  __int64 v88; // x11
  char v89; // w9
  __int64 v90; // x10
  __int64 v91; // x11
  __int64 v92; // x10
  __int64 v93; // x11
  __int64 v94; // x10
  __int64 v95; // x11
  __int64 v96; // x10
  __int64 v97; // x11
  __int64 v98; // x10
  __int64 v99; // x11
  __int64 v100; // x10
  __int64 v101; // x11
  __int64 v102; // x10
  __int64 v103; // x9
  __int64 v104; // x10
  __int64 v105; // x8
  __int64 v106; // x9
  __int64 v107; // x8
  __int64 v108; // x9
  unsigned int v109; // w8
  int v110; // w9
  int v111; // w10
  int v112; // w12
  int v113; // w11
  __int64 v114; // x19
  __int64 v115; // x27
  __int64 v116; // x0
  unsigned int v117; // w8
  __int64 v118; // x9
  int *v119; // x10
  __int64 v120; // x8
  int v121; // w28
  unsigned int v122; // w9
  unsigned int v129; // w13
  unsigned __int64 v130; // x11
  __int64 v131; // x9
  __int64 v132; // x26
  __int64 v133; // x27
  _DWORD *v134; // x19
  char v135; // w8
  _DWORD *v136; // x8
  unsigned __int64 v137; // x8
  __int64 v138; // x9
  __int64 v139; // x8
  unsigned int v140; // w9
  __int64 v141; // x19
  _DWORD *v142; // x20
  unsigned __int64 v145; // x26
  unsigned __int64 v146; // x26
  unsigned int v149; // w10
  __int64 v150; // [xsp+10h] [xbp-10h]

  v3 = *(_QWORD *)(a1 + 3680);
  v4 = *(_QWORD *)(a1 + 3392);
  LODWORD(v5) = a3;
  v7 = *(_QWORD *)(*(_QWORD *)v3 + 56LL);
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v3 + 8216);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v145 = __ldxr(_X8);
      v146 = v145 + 1;
    }
    while ( __stlxr(v146, _X8) );
    __dmb(0xBu);
    v8 = v146 / 0x64;
    v9 = v3 + 1512 * (v146 % 0x64);
    v10 = (_DWORD *)(v9 + 8224);
    *(_QWORD *)(v9 + 9728) = a1;
    ktime_get_real_ts64(v9 + 8224);
    result = strnlen((const char *)a2, 0x80u);
    if ( result == -1 )
      goto LABEL_54;
    v12 = result == 128 ? 128LL : result + 1;
    if ( v12 < 0x81 )
      break;
LABEL_55:
    _fortify_panic(7, 128, v12);
  }
  result = sized_strscpy(v9 + 8240, a2);
  v13 = *(_DWORD *)(v3 + 2780);
  *(_DWORD *)(v9 + 8368) = v5;
  if ( v13 )
  {
    v14 = *(_QWORD *)(v3 + 3416);
    v15 = *(_QWORD *)(v3 + 3424);
    *(_QWORD *)(v9 + 8408) = *(_QWORD *)(v3 + 3408);
    *(_QWORD *)(v9 + 8416) = v14;
    v16 = *(_QWORD *)(v3 + 3432);
    v17 = *(_QWORD *)(v3 + 3096);
    *(_QWORD *)(v9 + 8424) = v15;
    *(_QWORD *)(v9 + 8432) = v16;
    v18 = *(_QWORD *)(v3 + 3384);
    v19 = *(_QWORD *)(v3 + 3392);
    *(_QWORD *)(v9 + 8376) = v17;
    *(_QWORD *)(v9 + 8384) = v18;
    v20 = *(_QWORD *)(v3 + 3400);
    v21 = *(_QWORD *)(v3 + 3472);
    *(_QWORD *)(v9 + 8392) = v19;
    *(_QWORD *)(v9 + 8400) = v20;
    v22 = *(_QWORD *)(v3 + 3480);
    v23 = *(_QWORD *)(v3 + 3488);
    *(_QWORD *)(v9 + 8472) = v21;
    *(_QWORD *)(v9 + 8480) = v22;
    v24 = *(_QWORD *)(v3 + 3496);
    v25 = *(_QWORD *)(v3 + 3456);
    *(_QWORD *)(v9 + 8488) = v23;
    *(_QWORD *)(v9 + 8496) = v24;
    v26 = *(_QWORD *)(v3 + 3448);
    LOBYTE(v23) = *(_BYTE *)(v3 + 3376);
    *(_QWORD *)(v9 + 8440) = 0;
    *(_QWORD *)(v9 + 8448) = v26;
    v27 = *(_QWORD *)(v3 + 3464);
    *(_BYTE *)(v9 + 8504) = v23;
    *(_QWORD *)(v9 + 8456) = v25;
    *(_QWORD *)(v9 + 8464) = v27;
    if ( v13 != 1 )
    {
      v28 = *(_QWORD *)(v3 + 3824);
      v29 = *(_QWORD *)(v3 + 3832);
      *(_QWORD *)(v9 + 8544) = *(_QWORD *)(v3 + 3816);
      *(_QWORD *)(v9 + 8552) = v28;
      v30 = *(_QWORD *)(v3 + 3840);
      v31 = *(_QWORD *)(v3 + 3504);
      *(_QWORD *)(v9 + 8560) = v29;
      *(_QWORD *)(v9 + 8568) = v30;
      v32 = *(_QWORD *)(v3 + 3792);
      v33 = *(_QWORD *)(v3 + 3800);
      *(_QWORD *)(v9 + 8512) = v31;
      *(_QWORD *)(v9 + 8520) = v32;
      v34 = *(_QWORD *)(v3 + 3808);
      v35 = *(_QWORD *)(v3 + 3880);
      *(_QWORD *)(v9 + 8528) = v33;
      *(_QWORD *)(v9 + 8536) = v34;
      v36 = *(_QWORD *)(v3 + 3888);
      v37 = *(_QWORD *)(v3 + 3896);
      *(_QWORD *)(v9 + 8608) = v35;
      *(_QWORD *)(v9 + 8616) = v36;
      v38 = *(_QWORD *)(v3 + 3904);
      v39 = *(_QWORD *)(v3 + 3864);
      *(_QWORD *)(v9 + 8624) = v37;
      *(_QWORD *)(v9 + 8632) = v38;
      v40 = *(_QWORD *)(v3 + 3856);
      LOBYTE(v37) = *(_BYTE *)(v3 + 3784);
      *(_QWORD *)(v9 + 8576) = 0;
      *(_QWORD *)(v9 + 8584) = v40;
      v41 = *(_QWORD *)(v3 + 3872);
      *(_BYTE *)(v9 + 8640) = v37;
      *(_QWORD *)(v9 + 8592) = v39;
      *(_QWORD *)(v9 + 8600) = v41;
      if ( v13 >= 3 )
      {
        v42 = *(_QWORD *)(v3 + 4232);
        v43 = *(_QWORD *)(v3 + 4240);
        *(_QWORD *)(v9 + 8680) = *(_QWORD *)(v3 + 4224);
        *(_QWORD *)(v9 + 8688) = v42;
        v44 = *(_QWORD *)(v3 + 4248);
        v45 = *(_QWORD *)(v3 + 3912);
        *(_QWORD *)(v9 + 8696) = v43;
        *(_QWORD *)(v9 + 8704) = v44;
        v46 = *(_QWORD *)(v3 + 4200);
        v47 = *(_QWORD *)(v3 + 4208);
        *(_QWORD *)(v9 + 8648) = v45;
        *(_QWORD *)(v9 + 8656) = v46;
        v48 = *(_QWORD *)(v3 + 4216);
        v49 = *(_QWORD *)(v3 + 4288);
        *(_QWORD *)(v9 + 8664) = v47;
        *(_QWORD *)(v9 + 8672) = v48;
        v50 = *(_QWORD *)(v3 + 4296);
        v51 = *(_QWORD *)(v3 + 4272);
        *(_QWORD *)(v9 + 8744) = v49;
        v52 = *(_QWORD *)(v3 + 4304);
        *(_QWORD *)(v9 + 8752) = v50;
        v53 = *(_QWORD *)(v3 + 4312);
        *(_QWORD *)(v9 + 8760) = v52;
        v54 = *(_QWORD *)(v3 + 4264);
        *(_QWORD *)(v9 + 8768) = v53;
        *(_QWORD *)(v9 + 8712) = 0;
        *(_QWORD *)(v9 + 8720) = v54;
        v55 = *(_QWORD *)(v3 + 4280);
        v56 = *(_BYTE *)(v3 + 4192);
        *(_QWORD *)(v9 + 8728) = v51;
        *(_QWORD *)(v9 + 8736) = v55;
        *(_BYTE *)(v9 + 8776) = v56;
        if ( v13 != 3 )
        {
          v57 = *(_QWORD *)(v3 + 4320);
          v58 = *(_QWORD *)(v3 + 4632);
          *(_QWORD *)(v9 + 8848) = 0;
          *(_QWORD *)(v9 + 8784) = v57;
          v59 = *(_QWORD *)(v3 + 4640);
          *(_QWORD *)(v9 + 8816) = v58;
          v60 = *(_QWORD *)(v3 + 4648);
          *(_QWORD *)(v9 + 8824) = v59;
          v61 = *(_QWORD *)(v3 + 4656);
          *(_QWORD *)(v9 + 8832) = v60;
          v62 = *(_QWORD *)(v3 + 4608);
          *(_QWORD *)(v9 + 8840) = v61;
          v63 = *(_QWORD *)(v3 + 4616);
          *(_QWORD *)(v9 + 8792) = v62;
          v64 = *(_QWORD *)(v3 + 4624);
          *(_QWORD *)(v9 + 8800) = v63;
          v65 = *(_QWORD *)(v3 + 4696);
          *(_QWORD *)(v9 + 8808) = v64;
          v66 = *(_QWORD *)(v3 + 4704);
          *(_QWORD *)(v9 + 8880) = v65;
          v67 = *(_QWORD *)(v3 + 4712);
          *(_QWORD *)(v9 + 8888) = v66;
          v68 = *(_QWORD *)(v3 + 4720);
          *(_QWORD *)(v9 + 8896) = v67;
          v69 = *(_QWORD *)(v3 + 4672);
          *(_QWORD *)(v9 + 8904) = v68;
          v70 = *(_QWORD *)(v3 + 4680);
          *(_QWORD *)(v9 + 8856) = v69;
          v71 = *(_QWORD *)(v3 + 4688);
          *(_QWORD *)(v9 + 8864) = v70;
          *(_QWORD *)(v9 + 8872) = v71;
          *(_BYTE *)(v9 + 8912) = *(_BYTE *)(v3 + 4600);
          if ( v13 >= 5 )
          {
            v72 = *(_QWORD *)(v3 + 4728);
            v73 = *(_QWORD *)(v3 + 5040);
            *(_QWORD *)(v9 + 8984) = 0;
            *(_QWORD *)(v9 + 8920) = v72;
            v74 = *(_QWORD *)(v3 + 5048);
            *(_QWORD *)(v9 + 8952) = v73;
            v75 = *(_QWORD *)(v3 + 5056);
            *(_QWORD *)(v9 + 8960) = v74;
            v76 = *(_QWORD *)(v3 + 5064);
            *(_QWORD *)(v9 + 8968) = v75;
            v77 = *(_QWORD *)(v3 + 5016);
            *(_QWORD *)(v9 + 8976) = v76;
            v78 = *(_QWORD *)(v3 + 5024);
            *(_QWORD *)(v9 + 8928) = v77;
            v79 = *(_QWORD *)(v3 + 5032);
            *(_QWORD *)(v9 + 8936) = v78;
            v80 = *(_QWORD *)(v3 + 5104);
            *(_QWORD *)(v9 + 8944) = v79;
            v81 = *(_QWORD *)(v3 + 5112);
            *(_QWORD *)(v9 + 9016) = v80;
            v82 = *(_QWORD *)(v3 + 5120);
            *(_QWORD *)(v9 + 9024) = v81;
            v83 = *(_QWORD *)(v3 + 5128);
            *(_QWORD *)(v9 + 9032) = v82;
            v84 = *(_QWORD *)(v3 + 5080);
            *(_QWORD *)(v9 + 9040) = v83;
            v85 = *(_QWORD *)(v3 + 5088);
            *(_QWORD *)(v9 + 8992) = v84;
            v86 = *(_QWORD *)(v3 + 5096);
            *(_QWORD *)(v9 + 9000) = v85;
            *(_QWORD *)(v9 + 9008) = v86;
            *(_BYTE *)(v9 + 9048) = *(_BYTE *)(v3 + 5008);
            if ( v13 != 5 )
            {
              v87 = *(_QWORD *)(v3 + 5136);
              v88 = *(_QWORD *)(v3 + 5448);
              v89 = *(_BYTE *)(v3 + 5416);
              *(_QWORD *)(v9 + 9120) = 0;
              *(_QWORD *)(v9 + 9056) = v87;
              v90 = *(_QWORD *)(v3 + 5456);
              *(_QWORD *)(v9 + 9088) = v88;
              v91 = *(_QWORD *)(v3 + 5464);
              *(_QWORD *)(v9 + 9096) = v90;
              v92 = *(_QWORD *)(v3 + 5472);
              *(_QWORD *)(v9 + 9104) = v91;
              v93 = *(_QWORD *)(v3 + 5424);
              *(_QWORD *)(v9 + 9112) = v92;
              v94 = *(_QWORD *)(v3 + 5432);
              *(_QWORD *)(v9 + 9064) = v93;
              v95 = *(_QWORD *)(v3 + 5440);
              *(_QWORD *)(v9 + 9072) = v94;
              v96 = *(_QWORD *)(v3 + 5512);
              *(_QWORD *)(v9 + 9080) = v95;
              v97 = *(_QWORD *)(v3 + 5520);
              *(_QWORD *)(v9 + 9152) = v96;
              v98 = *(_QWORD *)(v3 + 5528);
              *(_QWORD *)(v9 + 9160) = v97;
              v99 = *(_QWORD *)(v3 + 5536);
              *(_QWORD *)(v9 + 9168) = v98;
              v100 = *(_QWORD *)(v3 + 5488);
              *(_QWORD *)(v9 + 9176) = v99;
              v101 = *(_QWORD *)(v3 + 5496);
              *(_QWORD *)(v9 + 9128) = v100;
              v102 = *(_QWORD *)(v3 + 5504);
              *(_QWORD *)(v9 + 9136) = v101;
              *(_QWORD *)(v9 + 9144) = v102;
              *(_BYTE *)(v9 + 9184) = v89;
              if ( v13 > 6 )
                goto LABEL_53;
            }
          }
        }
      }
    }
  }
  v103 = *(_QWORD *)(v3 + 8184);
  v104 = *(_QWORD *)(v3 + 0x2000);
  *(_QWORD *)(v9 + 9216) = *(_QWORD *)(v3 + 8176);
  v105 = *(_QWORD *)(v3 + 8200);
  *(_QWORD *)(v9 + 9224) = v103;
  v106 = *(_QWORD *)(v3 + 8152);
  *(_QWORD *)(v9 + 9240) = v105;
  v107 = *(_QWORD *)(v3 + 8160);
  *(_QWORD *)(v9 + 9232) = v104;
  LODWORD(v104) = *(_DWORD *)(v3 + 2792);
  *(_QWORD *)(v9 + 9192) = v106;
  v108 = *(_QWORD *)(v3 + 8168);
  *(_QWORD *)(v9 + 9200) = v107;
  LODWORD(v107) = *(_DWORD *)(v3 + 2912);
  *(_QWORD *)(v9 + 9208) = v108;
  *(_DWORD *)(v9 + 9248) = v107;
  if ( !(_DWORD)v104 )
    goto LABEL_20;
  v109 = *(_DWORD *)(v3 + 2824);
  if ( v109 == -1 || !*(_DWORD *)(v4 + 1368) )
    goto LABEL_20;
  if ( v109 > 7 )
    goto LABEL_53;
  v110 = *(_DWORD *)(v4 + 1372);
  v111 = 4 * *(_DWORD *)(v4 + 1380);
  v112 = *(_DWORD *)(v4 + 1376);
  v113 = 4 * *(_DWORD *)(v4 + 1384);
  v114 = *(_QWORD *)(a1 + 24LL * v109 + 384);
  a2 = (unsigned int)(v112 + v111);
  v5 = (unsigned int)(v113 + v110);
  v115 = (unsigned int)(v112 + v113);
  v150 = (unsigned int)(v112 + 4);
  v10[257] = cam_io_r_mb(v114 + (unsigned int)(v111 + v110));
  v10[259] = cam_io_r_mb(v114 + v5);
  v10[258] = cam_io_r_mb(v114 + a2);
  v116 = v114 + v115;
  v8 = v146 / 0x64;
  v10[260] = cam_io_r_mb(v116);
  result = cam_io_r_mb(v114 + v150);
  v10[261] = result;
  if ( (debug_mdl & 4) == 0 )
    goto LABEL_20;
  if ( !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 4,
               4,
               "cam_cpas_update_monitor_array",
               3674,
               "fe_ddr=0x%x, fe_mnoc=0x%x, be_ddr=0x%x, be_mnoc=0x%x",
               v10[257],
               v10[259],
               v10[258],
               v10[260]);
    if ( !v7 )
      goto LABEL_38;
  }
  else
  {
LABEL_20:
    if ( !v7 )
      goto LABEL_38;
  }
  if ( !*(_DWORD *)(v3 + 2792) )
    goto LABEL_38;
  v117 = *(_DWORD *)(v3 + 2828);
  if ( v117 == -1 )
    goto LABEL_38;
  if ( v117 > 7 )
  {
LABEL_53:
    __break(0x5512u);
LABEL_54:
    _fortify_panic(2, -1, result + 1);
    goto LABEL_55;
  }
  v118 = a1 + 24LL * v117;
  v119 = *(int **)(v7 + 16);
  v120 = *(unsigned int *)(v7 + 8);
  v121 = *v119;
  a2 = (unsigned int)v119[1];
  v5 = *(_QWORD *)(v118 + 384);
  v122 = *(_DWORD *)(v3 + 8104);
  while ( v122 )
  {
    _X15 = (unsigned int *)(v3 + 8104);
    __asm { PRFM            #0x11, [X15] }
    while ( 1 )
    {
      v129 = __ldxr(_X15);
      if ( v129 != v122 )
        break;
      if ( !__stlxr(v122 + 1, _X15) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v129 == v122;
    v122 = v129;
    if ( _ZF )
    {
      if ( !(_DWORD)v120 )
      {
LABEL_37:
        _X8 = (unsigned int *)(v3 + 8104);
        __asm { PRFM            #0x11, [X8] }
        do
          v149 = __ldxr(_X8);
        while ( __stxr(v149 - 1, _X8) );
        result = _wake_up(v3 + 8112, 3, 1, 0);
        break;
      }
      v130 = v8;
      v131 = 1512 * v146;
      v132 = 16 * v120;
      v133 = 0;
      v134 = (_DWORD *)(v131 - 151200 * v130 + v3 + 9660);
      while ( 1 )
      {
        result = cam_io_r_mb(v5 + v121 + (unsigned int)a2 * *(unsigned __int8 *)(*(_QWORD *)v7 + v133));
        if ( v133 == 144 )
          goto LABEL_53;
        v135 = *(_BYTE *)(*(_QWORD *)v7 + v133);
        v133 += 16;
        *((_BYTE *)v134 - 4) = v135;
        *v134 = result;
        v134 += 2;
        if ( v132 == v133 )
          goto LABEL_37;
      }
    }
  }
LABEL_38:
  v136 = *(_DWORD **)(v3 + 8088);
  if ( v136 )
  {
    if ( *(v136 - 1) != -1184073750 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _DWORD *))v136)(a1, v10);
  }
  if ( *(_BYTE *)(v4 + 1608) == 1 )
  {
    v137 = *(unsigned __int8 *)(v3 + 159424);
    if ( v137 <= 3 )
    {
      v138 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)v3 + 8 * v137 + 8) + 4LL);
      if ( (unsigned int)v138 <= 9 )
      {
        v139 = *(_QWORD *)(v4 + 1616);
        if ( !*(_BYTE *)(v139 + 9) )
          return result;
        v140 = *(_DWORD *)(v3 + 4 * v138 + 2812);
        if ( v140 <= 7 )
        {
          v5 = 0;
          v141 = a1 + 24LL * v140;
          v142 = v10 + 338;
          while ( v5 != 10 )
          {
            a2 = *(_QWORD *)(v139 + 8 * v5 + 16);
            v142[10] = cam_io_r_mb(*(_QWORD *)(v141 + 384) + *(unsigned int *)(a2 + 124));
            result = cam_io_r_mb(*(_QWORD *)(v141 + 384) + *(unsigned int *)(a2 + 120));
            *v142++ = result;
            ++v5;
            v139 = *(_QWORD *)(v4 + 1616);
            if ( v5 >= *(unsigned __int8 *)(v139 + 9) )
              return result;
          }
        }
      }
    }
    goto LABEL_53;
  }
  return result;
}
