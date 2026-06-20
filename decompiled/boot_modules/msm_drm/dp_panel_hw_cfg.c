__int64 __fastcall dp_panel_hw_cfg(unsigned __int8 *a1, char a2)
{
  unsigned int v2; // w8
  void (*v5)(void); // x8
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 v12; // x0
  void (__fastcall *v13)(__int64, bool, __int64, __int64, __int64, __int64, __int64, __int64, int, int); // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  __int64 v16; // x0
  __int64 v17; // x23
  __int64 v18; // x21
  __int64 (*v19)(void); // x8
  int v20; // w0
  int v21; // w9
  int v22; // w8
  int v23; // w9
  _DWORD *v24; // x9
  __int64 v25; // x21
  __int64 v26; // x22
  __int64 (*v27)(void); // x8
  int v28; // w0
  __int64 v29; // x9
  int v30; // w22
  int v31; // w24
  __int64 (__fastcall *v32)(_QWORD); // x9
  __int64 v33; // x0
  int v34; // w0
  int v35; // w8
  int v36; // w8
  int v37; // w9
  int v38; // w8
  void (__fastcall *v39)(_QWORD); // x9
  __int64 v40; // x21
  unsigned int v41; // w0
  __int64 v42; // x2
  _DWORD *v43; // x8
  __int64 v44; // x21
  int v45; // w22
  unsigned int (*v46)(void); // x8
  char v47; // w8
  unsigned int v48; // w9
  unsigned int v49; // w8
  int v50; // w9
  char v51; // w9
  void (*v52)(void); // x8
  int v53; // w8
  __int64 v54; // x21
  int v55; // w9
  __int64 pps_buf_cmd; // x0
  __int64 v57; // x8
  unsigned int v58; // w9
  unsigned int v59; // w10
  int v60; // w11
  bool v61; // cf
  __int64 v62; // x9
  int v63; // w0
  int v64; // w15
  char v65; // w1
  int v66; // w16
  unsigned int v67; // w17
  __int64 v68; // x14
  int v69; // w0
  unsigned int v70; // w2
  unsigned __int8 v71; // w1
  char v72; // w5
  unsigned int v73; // w3
  unsigned int v74; // w10
  int v75; // w12
  int v76; // w13
  int v77; // w14
  unsigned int v78; // w8
  unsigned int v79; // w8
  int v80; // w8
  int v81; // w22
  __int64 v82; // x0
  __int64 v83; // x0
  unsigned __int8 v84; // w8
  int v85; // w9
  __int64 (__fastcall *v86)(_QWORD); // x9
  __int64 (__fastcall *v87)(_QWORD); // x8
  __int64 v88; // x8
  __int64 v89; // x21
  __int64 v90; // x0
  int v91; // w0
  __int64 v92; // x13
  int v93; // w12
  __int64 v94; // x11
  int v95; // w14
  int v96; // w9
  int v97; // w10
  int v98; // w9
  int v99; // w10
  __int64 v100; // x10
  int v101; // w8
  __int64 v102; // x0
  int v103; // w23
  int v104; // w24
  int v105; // w22
  __int64 v106; // x0
  unsigned __int64 StatusReg; // x26
  __int64 (__fastcall *v108)(_QWORD); // x8
  __int64 v109; // x21
  __int64 v110; // x0
  int v111; // w4
  int v112; // w5
  unsigned __int64 v113; // x22
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 (__fastcall *v116)(_QWORD); // x8
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  int v121; // [xsp+0h] [xbp-D0h]
  int v122; // [xsp+8h] [xbp-C8h]
  __int64 v123; // [xsp+58h] [xbp-78h] BYREF
  __int64 v124; // [xsp+60h] [xbp-70h]
  __int64 v125; // [xsp+68h] [xbp-68h]
  int v126; // [xsp+70h] [xbp-60h]
  __int64 v127; // [xsp+78h] [xbp-58h] BYREF
  __int64 v128; // [xsp+80h] [xbp-50h]
  __int64 v129; // [xsp+88h] [xbp-48h]
  __int64 v130; // [xsp+90h] [xbp-40h]
  int v131; // [xsp+98h] [xbp-38h]
  int v132; // [xsp+9Ch] [xbp-34h]
  int v133; // [xsp+A0h] [xbp-30h]
  int v134; // [xsp+A4h] [xbp-2Ch]
  int v135; // [xsp+A8h] [xbp-28h]
  int v136; // [xsp+ACh] [xbp-24h]
  __int64 v137; // [xsp+B0h] [xbp-20h]
  __int64 v138; // [xsp+B8h] [xbp-18h]
  __int64 v139; // [xsp+C0h] [xbp-10h]
  __int64 v140; // [xsp+C8h] [xbp-8h]

  v140 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_hw_cfg");
    result = 4294967274LL;
    goto LABEL_10;
  }
  v2 = *((_DWORD *)a1 + 228);
  if ( v2 >= 2 )
  {
    v16 = get_ipc_log_context(a1);
    ipc_log_string(
      v16,
      "[e][%-4d]invalid stream_id: %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *((_DWORD *)a1 + 228));
    printk(&unk_2184C8, "dp_panel_hw_cfg");
    result = 4294967274LL;
    goto LABEL_10;
  }
  *(_DWORD *)(*((_QWORD *)a1 + 152) + 204LL) = v2;
  if ( (a2 & 1) != 0 )
  {
    v17 = *((_QWORD *)a1 + 118);
    v18 = *((_QWORD *)a1 + 152);
    v19 = *(__int64 (**)(void))(*((_QWORD *)a1 + 150) + 144LL);
    if ( *((_DWORD *)v19 - 1) != -1342967168 )
      __break(0x8228u);
    v20 = v19();
    if ( v20 == -1 || a1[168] == 1 )
      v20 = 1;
    v21 = (16 * *(_DWORD *)(*((_QWORD *)a1 + 150) + 128LL) - 16) | (v20 << 8);
    v22 = v21 | 0x4000;
    if ( *a1 >= 0x11u )
    {
      v23 = v21 | 0x4040;
      if ( (a1[2] & 0x80u) != 0 )
        v22 = v23;
    }
    v24 = *(_DWORD **)(v18 + 664);
    if ( *(v24 - 1) != 1646357783 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD))v24)(v18, v22 | 7u);
    v25 = *((_QWORD *)a1 + 152);
    v26 = *((_QWORD *)a1 + 118);
    v27 = *(__int64 (**)(void))(*((_QWORD *)a1 + 150) + 144LL);
    if ( *((_DWORD *)v27 - 1) != -1342967168 )
      __break(0x8228u);
    v28 = v27();
    v29 = *(_QWORD *)(v26 + 2512);
    v30 = v28;
    v31 = *(_DWORD *)(v29 + 128);
    v32 = *(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)a1 + 150) + 160LL);
    v33 = *((_QWORD *)a1 + 150);
    if ( *((_DWORD *)v32 - 1) != -1720141962 )
      __break(0x8229u);
    v34 = v32(v33);
    if ( v34 )
    {
      v35 = 2 * (unsigned __int8)v34;
    }
    else if ( (unsigned int)(v31 - 7) > 7 )
    {
      v35 = 0;
    }
    else
    {
      v35 = dword_29D3A0[v31 - 7];
    }
    v36 = v35 | (32 * v30);
    if ( a1[1233] )
      v37 = 16385;
    else
      v37 = 1;
    v38 = v36 | v37;
    v39 = *(void (__fastcall **)(_QWORD))(v25 + 640);
    *(_DWORD *)(v25 + 200) = v38;
    if ( *((_DWORD *)v39 - 1) != 440525842 )
      __break(0x8229u);
    v39(v25);
    v40 = *((_QWORD *)a1 + 152);
    *(_BYTE *)(v40 + 208) = a1[969];
    *(_DWORD *)(v40 + 584) = *((_DWORD *)a1 + 244);
    v41 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(*((_QWORD *)a1 + 150) + 132LL));
    v42 = *((unsigned int *)a1 + 38);
    v43 = *(_DWORD **)(v40 + 648);
    if ( *(v43 - 1) != 1468721727 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v43)(v40, v41, v42);
    if ( a1[1233] == 1 )
    {
      v44 = *((_QWORD *)a1 + 152);
      v45 = *(_DWORD *)(*(_QWORD *)(v17 + 2512) + 128LL);
      *(_DWORD *)(v44 + 32) = 319096576;
      v46 = *(unsigned int (**)(void))(*((_QWORD *)a1 + 150) + 160LL);
      if ( *((_DWORD *)v46 - 1) != -1720141962 )
        __break(0x8228u);
      if ( v46() )
      {
        LOBYTE(v48) = 0;
        LOBYTE(v49) = 0x80;
      }
      else if ( (unsigned int)(v45 - 9) > 3 )
      {
        LOBYTE(v48) = 0;
        LOBYTE(v49) = 0;
      }
      else
      {
        v47 = 8 * (v45 - 9);
        v48 = 0x4040006u >> v47;
        v49 = 0x80u >> v47;
      }
      *(_BYTE *)(v44 + 52) = v48;
      *(_BYTE *)(v44 + 53) = v49;
      v50 = (unsigned __int8)(*((_DWORD *)a1 + 39) / 3u);
      if ( v50 != 6 )
      {
        if ( v50 == 8 )
          v51 = 1;
        else
          v51 = 2;
        *(_BYTE *)(v44 + 53) = v51 | v49;
      }
      *(_BYTE *)(v44 + 54) = 1;
      *(_DWORD *)(*((_QWORD *)a1 + 152) + 204LL) = *((_DWORD *)a1 + 228);
      v52 = *(void (**)(void))(*((_QWORD *)a1 + 152) + 608LL);
      if ( *((_DWORD *)v52 - 1) != -1453310454 )
        __break(0x8228u);
      v52();
    }
    v53 = *((_DWORD *)a1 + 43);
    v54 = *((_QWORD *)a1 + 152);
    v55 = *((_DWORD *)a1 + 45);
    LODWORD(v127) = *((_DWORD *)a1 + 46);
    HIDWORD(v127) = v55;
    if ( v53 == 1 )
    {
      pps_buf_cmd = sde_dsc_create_pps_buf_cmd((int)a1 + 192, (void *)(v54 + 214), 0, 0x80u);
      if ( (_DWORD)pps_buf_cmd )
      {
        v81 = pps_buf_cmd;
        v82 = get_ipc_log_context(pps_buf_cmd);
        ipc_log_string(v82, "[e][%-4d]failed to create pps cmd %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v81);
        v83 = printk(&unk_21C0B1, "dp_panel_config_dsc");
LABEL_81:
        if ( !*((_DWORD *)a1 + 228) )
        {
          v88 = *((_QWORD *)a1 + 150);
          v89 = *((_QWORD *)a1 + 152);
          v138 = 0;
          v139 = 0;
          v137 = 0;
          v90 = *(unsigned int *)(v88 + 132);
          v126 = 0;
          v124 = 0;
          v125 = 0;
          v123 = 0;
          v91 = drm_dp_bw_code_to_link_rate(v90);
          v92 = *((_QWORD *)a1 + 150);
          v93 = *((_DWORD *)a1 + 30);
          v94 = *((unsigned int *)a1 + 26);
          v95 = a1[968];
          v96 = *((_DWORD *)a1 + 28);
          v97 = *((_DWORD *)a1 + 29);
          v135 = 0;
          v136 = v95;
          v129 = v94;
          v130 = (unsigned int)(v97 + v96 + v93);
          v98 = a1[168];
          v99 = *(_DWORD *)(v92 + 128);
          v134 = v98;
          v131 = v99;
          v100 = *((unsigned int *)a1 + 38);
          LODWORD(v94) = *((_DWORD *)a1 + 39);
          v127 = v91 / 1000;
          v128 = v100;
          LODWORD(v100) = *((_DWORD *)a1 + 90);
          v132 = v94;
          v133 = 444;
          v101 = *((_DWORD *)a1 + 244);
          HIDWORD(v137) = v100;
          LODWORD(v139) = v101;
          if ( v98 == 1 )
            LODWORD(v137) = 0x64u % *((_DWORD *)a1 + 46) * *((_DWORD *)a1 + 45) / *((_DWORD *)a1 + 46)
                          + 0x64u / *((_DWORD *)a1 + 46) * *((_DWORD *)a1 + 45);
          v102 = dp_tu_calculate(&v127, &v123);
          v103 = v126;
          v104 = v123 | (HIDWORD(v123) << 16);
          v105 = (unsigned __int8)v124 | (2 * HIDWORD(v124)) | ((_DWORD)v125 << 16) | (HIDWORD(v125) << 20);
          v106 = get_ipc_log_context(v102);
          StatusReg = _ReadStatusReg(SP_EL0);
          ipc_log_string(
            v106,
            "[d][%-4d]dp_tu=0x%x, valid_boundary=0x%x, valid_boundary2=0x%x\n",
            *(_DWORD *)(StatusReg + 1800),
            v103,
            v104,
            v105);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]dp_tu=0x%x, valid_boundary=0x%x, valid_boundary2=0x%x\n",
              *(_DWORD *)(StatusReg + 1800),
              v103,
              v104,
              v105);
          v108 = *(__int64 (__fastcall **)(_QWORD))(v89 + 656);
          *(_DWORD *)(v89 + 188) = v103;
          *(_DWORD *)(v89 + 192) = v104;
          *(_DWORD *)(v89 + 196) = v105;
          if ( *((_DWORD *)v108 - 1) != 440525842 )
            __break(0x8228u);
          v83 = v108(v89);
        }
        v109 = *((_QWORD *)a1 + 152);
        v110 = get_ipc_log_context(v83);
        v111 = *((_DWORD *)a1 + 28);
        v112 = *((_DWORD *)a1 + 29);
        v113 = _ReadStatusReg(SP_EL0);
        v114 = ipc_log_string(
                 v110,
                 "[d][%-4d]width=%d hporch= %d %d %d\n",
                 *(_DWORD *)(v113 + 1800),
                 *((_DWORD *)a1 + 26),
                 v111,
                 v112,
                 *((_DWORD *)a1 + 30));
        if ( (_drm_debug & 4) != 0 )
          v114 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]width=%d hporch= %d %d %d\n",
                   *(_DWORD *)(v113 + 1800),
                   *((_DWORD *)a1 + 26),
                   *((_DWORD *)a1 + 28),
                   *((_DWORD *)a1 + 29),
                   *((_DWORD *)a1 + 30));
        v115 = get_ipc_log_context(v114);
        ipc_log_string(
          v115,
          "[d][%-4d]height=%d vporch= %d %d %d\n",
          *(_DWORD *)(v113 + 1800),
          *((_DWORD *)a1 + 27),
          *((_DWORD *)a1 + 32),
          *((_DWORD *)a1 + 33),
          *((_DWORD *)a1 + 34));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]height=%d vporch= %d %d %d\n",
            *(_DWORD *)(v113 + 1800),
            *((_DWORD *)a1 + 27),
            *((_DWORD *)a1 + 32),
            *((_DWORD *)a1 + 33),
            *((_DWORD *)a1 + 34));
        *(_DWORD *)v109 = (*((_DWORD *)a1 + 28) + *((_DWORD *)a1 + 26) + *((_DWORD *)a1 + 29) + *((_DWORD *)a1 + 30))
                        | ((*((_DWORD *)a1 + 32) + *((_DWORD *)a1 + 27) + *((_DWORD *)a1 + 33) + *((_DWORD *)a1 + 34)) << 16);
        *(_DWORD *)(v109 + 4) = (*((_DWORD *)a1 + 30) + *((_DWORD *)a1 + 28))
                              | ((*((_DWORD *)a1 + 34) + *((_DWORD *)a1 + 32)) << 16);
        *(_DWORD *)(v109 + 8) = (*((_DWORD *)a1 + 35) << 31)
                              | (*((_DWORD *)a1 + 34) << 16)
                              | *((_DWORD *)a1 + 30)
                              | (*((_DWORD *)a1 + 31) << 15);
        *(_DWORD *)(v109 + 12) = *((_DWORD *)a1 + 26) | (*((_DWORD *)a1 + 27) << 16);
        *(_BYTE *)(v109 + 208) = a1[160];
        v116 = *(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)a1 + 152) + 592LL);
        if ( *((_DWORD *)v116 - 1) != -238884201 )
          __break(0x8228u);
        v117 = v116(v109);
        a1[1232] = 1;
        v118 = get_ipc_log_context(v117);
        ipc_log_string(v118, "[i][%-4d]DP RESOLUTION: active(back|front|width|low)\n", *(_DWORD *)(v113 + 1800));
        if ( (_drm_debug & 4) != 0 )
          v119 = printk(&unk_218521, *(unsigned int *)(v113 + 1800));
        else
          v119 = printk(&unk_2263B1, "dp_panel_resolution_info");
        v120 = get_ipc_log_context(v119);
        ipc_log_string(
          v120,
          "[i][%-4d]%d(%d|%d|%d|%d)x%d(%d|%d|%d|%d)@%dfps %dbpp %dKhz %dLR %dLn\n",
          *(_DWORD *)(v113 + 1800),
          *((_DWORD *)a1 + 26),
          *((_DWORD *)a1 + 28),
          *((_DWORD *)a1 + 29),
          *((_DWORD *)a1 + 30),
          *((_DWORD *)a1 + 31),
          *((_DWORD *)a1 + 27),
          *((_DWORD *)a1 + 32),
          *((_DWORD *)a1 + 33),
          *((_DWORD *)a1 + 34),
          *((_DWORD *)a1 + 35),
          *((_DWORD *)a1 + 37),
          *((_DWORD *)a1 + 39),
          *((_DWORD *)a1 + 38),
          *(_DWORD *)(*((_QWORD *)a1 + 150) + 132LL),
          *(_DWORD *)(*((_QWORD *)a1 + 150) + 128LL));
        if ( (_drm_debug & 4) != 0 )
        {
          v122 = *((_DWORD *)a1 + 33);
          v121 = *((_DWORD *)a1 + 32);
          printk(&unk_267AF6, *(unsigned int *)(v113 + 1800));
        }
        else
        {
          v122 = *((_DWORD *)a1 + 32);
          v121 = *((_DWORD *)a1 + 27);
          printk(&unk_211084, "dp_panel_resolution_info");
        }
        goto LABEL_7;
      }
      *(_DWORD *)(v54 + 344) = 88;
      v57 = *((_QWORD *)a1 + 152);
      v58 = *(_DWORD *)(v57 + 344);
      *(_QWORD *)(v57 + 496) = 0;
      *(_QWORD *)(v57 + 504) = 0;
      *(_QWORD *)(v57 + 480) = 0;
      *(_QWORD *)(v57 + 488) = 0;
      v59 = v58 >> 2;
      v60 = (v58 >> 4) & 0x3F;
      v61 = v58 >= 4;
      v62 = v57 + 480;
      *(_DWORD *)(v57 + 476) = v59;
      *(_BYTE *)(v57 + 512) = v59;
      *(_DWORD *)(v57 + 548) = v60 + 1;
      if ( !v61 )
        goto LABEL_66;
      v63 = 0;
      do
      {
        v64 = 0;
        v65 = 0;
        LOBYTE(v66) = 0;
        v67 = *(_DWORD *)(v57 + 214 + 4 * v63);
        v68 = v63;
        *(_DWORD *)(v57 + 348 + 4LL * v63) = v67;
        if ( v67 <= 0xFF )
          v69 = 2;
        else
          v69 = 8;
        do
        {
          v70 = v67 >> v64;
          --v69;
          v64 += 4;
          v71 = v70 & 0xF ^ v65;
          v72 = (v71 >> 3) ^ v71;
          v73 = v71;
          LOBYTE(v70) = 2 * v71;
          v65 = (v72 & 1
               | (4 * (((v71 >> 2) ^ (v71 >> 1)) & 1)) & 0xF5
               | (8 * (((v71 >> 2) ^ (v71 >> 3)) & 1))
               | (2 * ((v72 ^ (v71 >> 1)) & 1)))
              ^ v66;
          v66 = v70 & 0xC | (v73 >> 3) & 1 | (2 * (v72 & 1));
        }
        while ( v69 );
        v63 = v68 + 1;
        *(_BYTE *)(v62 + v68) = v65 | (16 * v66);
      }
      while ( (unsigned int)(v68 + 1) < *(_DWORD *)(v57 + 476) );
      if ( *(_DWORD *)(v57 + 548) )
      {
LABEL_66:
        v74 = 0;
        v75 = 3;
        do
        {
          v76 = *(unsigned __int16 *)(v62 + v75 - 3) | (*(unsigned __int8 *)(v62 + v75 - 1) << 16);
          v77 = *(unsigned __int8 *)(v62 + v75);
          v75 += 4;
          *(_DWORD *)(v57 + 516 + 4LL * (int)v74++) = v76 | (v77 << 24);
        }
        while ( v74 < *(_DWORD *)(v57 + 548) );
      }
      *(_DWORD *)(v54 + 552) = *((_DWORD *)a1 + 90) - 1;
      v78 = *((_DWORD *)a1 + 86);
      *(_DWORD *)(v54 + 556) = v78;
      *(_DWORD *)(v54 + 556) = v78 / *((_DWORD *)a1 + 90);
      *(_DWORD *)(v54 + 560) = *((_DWORD *)a1 + 87);
      *(_DWORD *)(v54 + 580) = *((_DWORD *)a1 + 88);
      if ( a1[971] == 1 )
      {
        v79 = *((_DWORD *)a1 + 84) * *((_DWORD *)a1 + 86) % 0xCu;
        if ( v79 )
        {
          if ( v79 >= 4 )
          {
            if ( v79 >= 7 )
            {
              if ( v79 >= 0xA )
                v80 = 8;
              else
                v80 = 4;
            }
            else
            {
              v80 = 2;
            }
          }
          else
          {
            v80 = 1;
          }
        }
        else
        {
          v80 = 8;
        }
      }
      else
      {
        v80 = 10;
      }
      *(_DWORD *)(v54 + 564) = v80;
      *(_BYTE *)(v54 + 212) = 1;
      *(_DWORD *)(v54 + 568) = 1;
      v84 = a1[970];
      v128 = 0;
      *(_BYTE *)(v54 + 213) = v84;
      dp_panel_get_dto_params(*((unsigned int *)a1 + 244), &v127);
      v85 = HIDWORD(v128);
      *(_DWORD *)(v54 + 572) = v128;
      *(_DWORD *)(v54 + 576) = v85;
    }
    else
    {
      *(_WORD *)(v54 + 212) = 0;
      *(_QWORD *)(v54 + 568) = 0;
      *(_DWORD *)(v54 + 576) = 0;
    }
    v86 = *(__int64 (__fastcall **)(_QWORD))(v54 + 680);
    *(_DWORD *)(v54 + 204) = *((_DWORD *)a1 + 228);
    if ( *((_DWORD *)v86 - 1) != 440525842 )
      __break(0x8229u);
    v83 = v86(v54);
    if ( *(_BYTE *)(v54 + 212) == 1 )
    {
      v87 = *(__int64 (__fastcall **)(_QWORD))(v54 + 688);
      if ( *((_DWORD *)v87 - 1) != 440525842 )
        __break(0x8228u);
      v83 = v87(v54);
    }
    goto LABEL_81;
  }
  *(_DWORD *)(*((_QWORD *)a1 + 152) + 204LL) = *((_DWORD *)a1 + 228);
  v5 = *(void (**)(void))(*((_QWORD *)a1 + 152) + 608LL);
  if ( *((_DWORD *)v5 - 1) != -1453310454 )
    __break(0x8228u);
  v5();
LABEL_7:
  v12 = *((_QWORD *)a1 + 152);
  v13 = *(void (__fastcall **)(__int64, bool, __int64, __int64, __int64, __int64, __int64, __int64, int, int))(v12 + 672);
  if ( *((_DWORD *)v13 - 1) != -1453310454 )
    __break(0x8228u);
  v13(v12, (a2 & 1) == 0, v6, v7, v8, v9, v10, v11, v121, v122);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
