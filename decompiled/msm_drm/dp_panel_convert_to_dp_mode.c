__int64 __fastcall dp_panel_convert_to_dp_mode(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int v6; // w22
  int v7; // w8
  int v8; // w8
  int v9; // w9
  int v10; // w8
  char v11; // w8
  __int64 is_420_only; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  _UNKNOWN **mode_bpp; // x0
  unsigned int v16; // w7
  unsigned int v17; // w23
  unsigned int v18; // w21
  bool v19; // cf
  char v20; // w24
  unsigned __int8 *v21; // x10
  __int64 v22; // x9
  __int64 v23; // x0
  unsigned int v24; // w11
  __int64 v25; // x11
  __int64 v26; // x0
  unsigned __int64 v27; // x20
  __int64 v28; // x0
  unsigned __int64 v29; // x20
  unsigned int v30; // w8
  __int64 result; // x0
  int v32; // w13
  unsigned int v33; // w10
  unsigned int v34; // w12
  unsigned int v35; // w1
  __int64 v36; // x16
  unsigned int v37; // w9
  int v38; // w14
  __int64 v39; // x16
  int v40; // w15
  unsigned int v41; // w13
  unsigned int v42; // w11
  unsigned int v43; // w2
  signed int v44; // w1
  char *v45; // x11
  unsigned int v46; // w10
  char v47; // w13
  unsigned __int64 v48; // t2
  unsigned __int64 v49; // t2
  __int16 v50; // w8
  unsigned int v51; // kr00_4
  __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 v54; // x20
  __int64 v55; // x0
  __int64 v56; // x0
  unsigned __int64 v57; // x20
  signed int v58; // w11
  unsigned int v59; // w13
  int v60; // w12
  unsigned int v61; // w8
  unsigned int v62; // w9
  int v63; // w17
  signed int v64; // w14
  unsigned int v65; // w16
  unsigned __int64 v66; // x15
  unsigned __int64 v67; // x1
  unsigned __int64 v68; // x1
  __int64 v69; // x3
  int v70; // w11
  int v71; // w16
  __int64 v72; // x13
  __int64 v73; // x15
  __int64 v74; // x14
  __int64 v75; // x14
  __int64 v76; // x16
  unsigned int v77; // w16
  unsigned int v78; // w15
  __int64 v79; // x13
  __int64 v80; // x14
  __int64 v81; // x12
  bool v82; // cc
  unsigned __int64 v83; // x12
  char v84; // w16
  __int64 v85; // x12
  __int64 v86; // x12
  char v87; // w13
  __int64 v88; // x12
  unsigned __int64 v89; // x13
  unsigned __int64 v90; // x13
  unsigned int v91; // w21
  unsigned int v92; // w15
  unsigned int v93; // w16
  unsigned __int64 v94; // x13
  unsigned __int64 v95; // x16
  int v96; // w14
  unsigned __int64 v97; // x16
  __int64 v98; // x0
  __int64 v99; // x11
  __int64 v100; // x13
  __int64 v101; // x14
  unsigned int v102; // w14
  unsigned int v103; // w13
  __int64 v104; // x11
  bool v105; // zf
  unsigned __int64 v106; // x12
  unsigned __int64 v107; // x11
  unsigned int v108; // w10
  __int16 v109; // w11
  __int64 v110; // x0
  unsigned int num_extra_pclk; // w0
  unsigned int v112; // w8
  unsigned int v113; // w11
  unsigned int v114; // w8
  int v115; // w10
  unsigned int v116; // w9
  int v117; // w8
  int v118; // w12
  int v119; // w9
  int v120; // w10
  signed int v121; // w8
  int v122; // w21
  __int64 v123; // x12
  unsigned __int64 v124; // x10
  unsigned __int64 v125; // x11
  unsigned __int64 v126; // x13
  int v127; // w12
  unsigned __int64 v128; // x13
  unsigned __int64 v129; // x15
  signed __int64 v130; // x8
  unsigned __int64 v131; // x9
  unsigned __int64 v132; // x8
  signed int v133; // [xsp+8h] [xbp-28h]
  _DWORD v134[2]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v135; // [xsp+1Ch] [xbp-14h]
  int v136; // [xsp+24h] [xbp-Ch]
  __int64 v137; // [xsp+28h] [xbp-8h]

  v137 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a3[192];
  *a3 = *(unsigned __int16 *)(a2 + 4);
  v7 = *(unsigned __int16 *)(a2 + 10) - *(unsigned __int16 *)(a2 + 8);
  a3[2] = v7;
  a3[4] = *(unsigned __int16 *)(a2 + 10) - *(unsigned __int16 *)(a2 + 6) - v7;
  a3[3] = *(unsigned __int16 *)(a2 + 6) - *(unsigned __int16 *)(a2 + 4);
  a3[10] = *(unsigned __int16 *)(a2 + 12);
  a3[1] = *(unsigned __int16 *)(a2 + 14);
  v8 = *(unsigned __int16 *)(a2 + 20) - *(unsigned __int16 *)(a2 + 18);
  a3[6] = v8;
  a3[8] = *(unsigned __int16 *)(a2 + 20) - *(unsigned __int16 *)(a2 + 16) - v8;
  a3[7] = *(unsigned __int16 *)(a2 + 16) - *(unsigned __int16 *)(a2 + 14);
  a3[11] = drm_mode_vrefresh(a2);
  a3[12] = *(_DWORD *)a2;
  a3[9] = (*(_DWORD *)(a2 + 24) >> 3) & 1;
  a3[5] = (*(_DWORD *)(a2 + 24) >> 1) & 1;
  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 944) + 224LL);
  if ( v9 )
    v10 = 3 * v9;
  else
    v10 = 24;
  a3[13] = v10;
  v11 = *(_BYTE *)(a1 + 969);
  *(_QWORD *)(a3 + 19) = 0x1800000018LL;
  *((_QWORD *)a3 + 94) = 0;
  *(_QWORD *)(a3 + 17) = 0x6400000000LL;
  *((_BYTE *)a3 + 64) = 0;
  *((_BYTE *)a3 + 56) = v11;
  a3[198] = 0;
  is_420_only = drm_mode_is_420_only(*(_QWORD *)(a1 + 944) + 216LL, a2);
  if ( (is_420_only & 1) != 0 )
  {
    a3[198] = 1;
    ipc_log_context = get_ipc_log_context(is_420_only);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]YCBCR420 was not supported", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]YCBCR420 was not supported", *(_DWORD *)(StatusReg + 1800));
  }
  mode_bpp = (_UNKNOWN **)dp_panel_get_mode_bpp(a1, a3[13], a3[12], v6 & 1);
  a3[13] = (unsigned int)mode_bpp;
  if ( (v6 & 1) == 0 )
    goto LABEL_178;
  v16 = *(unsigned __int8 *)(a1 + 962);
  v17 = a3[12];
  v18 = v16 >> 4;
  v19 = (v16 & 0xF) != 1 || (v16 >> 4) - 1 >= 2;
  v20 = !v19;
  if ( (_drm_debug & 4) != 0 )
    mode_bpp = (_UNKNOWN **)_drm_dev_dbg(
                              0,
                              0,
                              0,
                              "[msm-dp-debug][%-4d]DSC version: %d.%d, dpcd value: %x\n",
                              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                              v16 & 0xF,
                              v18,
                              v16);
  if ( (v20 & 1) == 0 )
  {
    v23 = get_ipc_log_context(mode_bpp);
    LOBYTE(v18) = 1;
    ipc_log_string(
      v23,
      "[e][%-4d]invalid sink DSC version, fallback to %d.%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      1,
      1);
    mode_bpp = (_UNKNOWN **)printk(&unk_22320F, "dp_panel_dsc_prepare_basic_params");
  }
  *((_BYTE *)a3 + 214) = v18;
  *((_BYTE *)a3 + 215) = 1;
  *((_BYTE *)a3 + 224) = 0;
  a3[64] = 0;
  if ( v17 < 0x3E8 )
    goto LABEL_40;
  if ( v17 < 0x53408 )
  {
    v22 = 1;
    v21 = (unsigned __int8 *)&slice_per_line_tbl;
  }
  else if ( v17 < 0xA6428 )
  {
    v21 = (unsigned __int8 *)&unk_280DAC;
    v22 = 2;
  }
  else if ( v17 < 0x14C468 )
  {
    v21 = (unsigned __int8 *)&unk_280DB8;
    v22 = 3;
  }
  else if ( v17 < 0x30D7E8 )
  {
    v21 = (unsigned __int8 *)&unk_280DC4;
    v22 = 4;
  }
  else if ( v17 < 0x4941E8 )
  {
    v21 = (unsigned __int8 *)&unk_280DD0;
    v22 = 5;
  }
  else if ( v17 < 0x61ABE8 )
  {
    v21 = (unsigned __int8 *)&unk_280DDC;
    v22 = 6;
  }
  else if ( v17 < 0x7A15E8 )
  {
    v21 = (unsigned __int8 *)&unk_280DE8;
    v22 = 7;
  }
  else
  {
    if ( v17 > 0x927FE7 )
      goto LABEL_40;
    v21 = (unsigned __int8 *)&unk_280DF4;
    v22 = 8;
  }
  v24 = v21[8];
  a3[64] = v24;
  if ( v24 )
  {
    v25 = *(_BYTE *)(a1 + 55) & 0xF;
    *(_BYTE *)(a1 + 55) = v25;
    if ( (_DWORD)v25 == 15 || !(_DWORD)v25 )
    {
      v26 = get_ipc_log_context(mode_bpp);
      v27 = _ReadStatusReg(SP_EL0);
      mode_bpp = (_UNKNOWN **)ipc_log_string(v26, "[d][%-4d]Throughput mode 0 not supported", *(_DWORD *)(v27 + 1800));
      if ( (_drm_debug & 4) != 0 )
        mode_bpp = (_UNKNOWN **)_drm_dev_dbg(
                                  0,
                                  0,
                                  0,
                                  "[msm-dp-debug][%-4d]Throughput mode 0 not supported",
                                  *(_DWORD *)(v27 + 1800));
      goto LABEL_40;
    }
    if ( ((8 * v25) | 4uLL) > 0x78 )
LABEL_184:
      __break(1u);
    v32 = v21[8];
    v33 = v17 / 0x3E8;
    v34 = peak_throughput_mode_0_tbl[2 * v25 + 1];
    if ( v32 == 8 && v33 <= 4 * v34 )
    {
      v35 = 4;
      a3[64] = 4;
    }
    else
    {
      v35 = a3[64];
    }
    v36 = 3 * v22;
    v37 = *a3;
    v38 = *(unsigned __int8 *)(a1 + 48);
    v39 = 4 * v36;
    v40 = *(_BYTE *)(a1 + 57) & 7;
    mode_bpp = &off_280EC8;
    v41 = 320 * *(unsigned __int8 *)(a1 + 56);
    while ( 1 )
    {
      v42 = v37 / v35;
      if ( v37 / v35 <= v41 && v33 / v35 <= v34 )
      {
        v43 = v35 >= 0xD ? v40 : v38;
        if ( v35 <= 0x18 )
        {
          v44 = v35 - 1;
          if ( ((0x888AABu >> v44) & 1) != 0 && ((v43 >> *((_DWORD *)*(&off_280EC8 + v44) + 1)) & 1) != 0 )
            break;
        }
      }
      if ( v39 == 96 )
        goto LABEL_40;
      if ( (unsigned __int64)(v39 - 88) < 0xFFFFFFFFFFFFFFA0LL )
        goto LABEL_184;
      v45 = (char *)&slice_per_line_tbl + v39;
      v39 += 12;
      v35 = (unsigned __int8)v45[8];
      a3[64] = v35;
    }
    v46 = a3[1];
    v47 = *(_BYTE *)(a1 + 963);
    *((_WORD *)a3 + 49) = v37;
    *((_BYTE *)a3 + 114) = v47;
    *((_WORD *)a3 + 50) = v46;
    *((_WORD *)a3 + 46) = v42;
    HIDWORD(v48) = 1749801491 * (unsigned __int16)v46;
    LODWORD(v48) = HIDWORD(v48);
    if ( (unsigned int)(v48 >> 2) <= 0x25ED097 )
    {
      v50 = 108;
    }
    else if ( (v46 & 0xF) != 0 )
    {
      HIDWORD(v49) = -1431655765 * (unsigned __int16)v46;
      LODWORD(v49) = HIDWORD(v49);
      if ( (unsigned int)(v49 >> 2) <= 0x15555555 )
        v50 = 12;
      else
        v50 = 15;
    }
    else
    {
      v50 = 16;
    }
    *((_WORD *)a3 + 47) = v50;
    v51 = a3[13];
    *((_WORD *)a3 + 52) = 128;
    a3[19] = v51;
    a3[20] = 8;
    *((_BYTE *)a3 + 64) = 1;
    a3[17] = 1;
    a3[18] = ((v51 >> 1) & 0x1FFFFFFF) + 12 * v51;
    *((_BYTE *)a3 + 89) = v51 / 3;
    *((_BYTE *)a3 + 91) = (v37 + v42 - 1) / v42;
    v52 = sde_dsc_populate_dsc_config(a3 + 22, 0);
    if ( (_DWORD)v52 )
    {
      v53 = get_ipc_log_context(v52);
      v54 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v53, "[d][%-4d]failed populating dsc params \n", *(_DWORD *)(v54 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]failed populating dsc params \n", *(unsigned int *)(v54 + 1800));
      goto LABEL_42;
    }
    v55 = sde_dsc_populate_dsc_private_params(a3 + 22, *a3, *((unsigned __int8 *)a3 + 56));
    if ( (_DWORD)v55 )
    {
      v56 = get_ipc_log_context(v55);
      v57 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v56, "[d][%-4d]failed populating other dsc params\n", *(_DWORD *)(v57 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]failed populating other dsc params\n", *(unsigned int *)(v57 + 1800));
      goto LABEL_42;
    }
    v58 = *((unsigned __int16 *)a3 + 46);
    if ( !*((_WORD *)a3 + 46) || (v59 = a3[64]) == 0 || (v60 = *a3, (int)*a3 < v58) )
    {
LABEL_178:
      result = 0;
      *((_QWORD *)a3 + 97) = *(_QWORD *)(a1 + 1000);
      goto LABEL_179;
    }
    v62 = a3[19];
    v61 = a3[20];
    v63 = -32;
    v64 = 0x64 % v61 * v62 / v61 + 0x64 / v61 * v62;
    if ( v64 >= 0 )
      v65 = 0x64 % v61 * v62 / v61 + 0x64 / v61 * v62;
    else
      v65 = -v64;
    v66 = v65 / 0x64uLL;
    v67 = v65 % 0x64;
    do
    {
      v68 = 2 * v67;
      if ( v68 <= 0x63 )
        v69 = 0;
      else
        v69 = -100;
      v19 = __CFADD__(v63++, 1);
      v66 = (v68 > 0x63) | (2 * v66);
      v67 = v69 + v68;
    }
    while ( !v19 );
    v70 = (v60 - 1 + v58) / v58;
    v71 = 8 * v59;
    if ( 2 * v67 <= 0x63 )
      v72 = v66;
    else
      v72 = v66 + 1;
    v73 = 62;
    if ( v64 < 0 )
      v72 = -v72;
    if ( v71 >= 0 )
      v74 = (unsigned int)v71;
    else
      v74 = (unsigned int)-v71;
    v75 = v74 << 32;
    if ( v71 < 0 )
      v75 = -v75;
    do
    {
      if ( (((unsigned __int64)v72 >> v73) & 1) != (unsigned __int64)v72 >> 63 )
        break;
      --v73;
    }
    while ( v73 );
    v76 = 62;
    do
    {
      if ( (((unsigned __int64)v75 >> v76) & 1) != (unsigned __int64)v75 >> 63 )
        break;
      --v76;
    }
    while ( v76 );
    v77 = v76 + v73;
    v78 = v77 - 61;
    if ( v77 <= 0x3D )
    {
      v79 = v75 * v72;
      LOBYTE(v78) = 0;
    }
    else
    {
      v79 = (v72 >> ((v78 >> 1) + (v78 & 1))) * (v75 >> (v78 >> 1));
      if ( v78 >= 0x21 )
      {
        v79 <<= (unsigned __int8)v77 - 93;
        goto LABEL_105;
      }
      if ( v77 == 93 )
      {
LABEL_105:
        v80 = 62;
        LODWORD(v81) = 3 * v60 * *((unsigned __int8 *)a3 + 89);
        v82 = (int)v81 < 0;
        if ( (int)v81 >= 0 )
          v81 = (unsigned int)v81;
        else
          v81 = (unsigned int)-(int)v81;
        v83 = v81 << 32;
        if ( v82 )
          v83 = -(__int64)v83;
        do
        {
          if ( ((v83 >> v80) & 1) != v83 >> 63 )
            break;
          --v80;
        }
        while ( v80 );
        v84 = v80 - 30;
        v85 = v83 << (62 - (unsigned __int8)v80);
        if ( (unsigned int)(62 - v80) >= 0x20 )
          v84 = 0;
        v86 = v85 / (v79 >> v84);
        v87 = 30 - v80;
        if ( (unsigned int)(62 - v80) <= 0x20 )
          v87 = 0;
        v88 = v86 >> v87;
        v89 = 0xFFFFFFFF00000001LL;
        if ( v88 >= 0 )
          v89 = 0xFFFFFFFFLL;
        v90 = (v89 + v88) >> 32;
        if ( v88 )
          v91 = v90;
        else
          v91 = 0;
        if ( v91 * v70 == 3 * (v91 * v70 / 3) )
          v92 = 0;
        else
          v92 = (v91 * v70 % 3) ^ 3;
        if ( v70 >= 0 )
          v93 = v70;
        else
          v93 = -v70;
        a3[61] = v92;
        v94 = v93 / 6uLL;
        v95 = v93 % 6;
        v96 = -32;
        do
        {
          v97 = 2 * v95;
          if ( v97 <= 5 )
            v98 = 0;
          else
            v98 = -6;
          v19 = __CFADD__(v96++, 1);
          v94 = (v97 > 5) | (2 * v94);
          v95 = v98 + v97;
        }
        while ( !v19 );
        if ( 2 * v95 > 5 )
          ++v94;
        if ( v70 >= 0 )
          v99 = v94;
        else
          v99 = -(__int64)v94;
        v100 = 62;
        do
        {
          if ( (((unsigned __int64)v88 >> v100) & 1) != (unsigned __int64)v88 >> 63 )
            break;
          --v100;
        }
        while ( v100 );
        v101 = 62;
        do
        {
          if ( (((unsigned __int64)v99 >> v101) & 1) != (unsigned __int64)v99 >> 63 )
            break;
          --v101;
        }
        while ( v101 );
        v102 = v101 + v100;
        v103 = v102 - 61;
        if ( v102 <= 0x3D )
        {
          v104 = v99 * v88;
          LOBYTE(v103) = 0;
        }
        else
        {
          v104 = (v88 >> ((v103 >> 1) + (v103 & 1))) * (v99 >> (v103 >> 1));
          if ( v103 >= 0x21 )
          {
            v104 <<= (unsigned __int8)v102 - 93;
LABEL_149:
            v105 = v104 == 0;
            v106 = 0xFFFFFFFF00000001LL;
            v136 = 0;
            if ( v104 >= 0 )
              v106 = 0xFFFFFFFFLL;
            v135 = 0;
            v134[0] = v62;
            v134[1] = v61;
            v107 = (v106 + v104) >> 32;
            if ( v105 )
              v108 = 0;
            else
              v108 = v107;
            v109 = *((_WORD *)a3 + 49);
            a3[62] = v108;
            v110 = *(unsigned int *)(a1 + 976);
            LOWORD(v135) = v109;
            HIDWORD(v135) = v108;
            num_extra_pclk = dp_tu_dsc_get_num_extra_pclk(v110, v134);
            v112 = a3[62];
            a3[69] = num_extra_pclk;
            v113 = a3[64];
            a3[62] = v112 - 1;
            v114 = *(_DWORD *)(*(_QWORD *)(a1 + 1200) + 128LL);
            v115 = v91 % v114;
            v116 = v114 - v91 % v114;
            v117 = v114 + v91;
            v118 = v116 * v113;
            v119 = v113 * v91;
            if ( v115 )
              v120 = v118;
            else
              v120 = 0;
            v121 = v120 + v113 * v117;
            if ( (_drm_debug & 4) != 0 )
            {
              v122 = v113 * v91;
              v133 = v121;
              _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]dwidth_dsc_bytes:%d, tot_num_hor_bytes:%d\n",
                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                v121,
                v119);
              v121 = v133;
              v119 = v122;
            }
            if ( v121 >= 0LL )
              LODWORD(v123) = v121;
            else
              v123 = -(__int64)v121;
            if ( v119 >= 0LL )
              v124 = v119;
            else
              v124 = -(__int64)v119;
            v125 = (unsigned int)v123 / (unsigned int)v124;
            v126 = (unsigned int)v123 % (unsigned int)v124;
            v127 = -32;
            do
            {
              v128 = 2 * v126;
              if ( v128 < v124 )
                v129 = 0;
              else
                v129 = v124;
              v19 = __CFADD__(v127++, 1);
              v125 = (v128 >= v124) | (2 * v125);
              v126 = v128 - v129;
            }
            while ( !v19 );
            v130 = v121 ^ (unsigned __int64)v119;
            if ( v124 > 2 * v126 )
              v131 = v125;
            else
              v131 = v125 + 1;
            if ( v130 >= 0 )
              v132 = v131;
            else
              v132 = -(__int64)v131;
            *((_QWORD *)a3 + 98) = v132;
            *((_QWORD *)a3 + 94) = v132;
            goto LABEL_178;
          }
          if ( v102 == 93 )
            goto LABEL_149;
        }
        v104 >>= 32 - (unsigned __int8)v103;
        goto LABEL_149;
      }
    }
    v79 >>= 32 - (unsigned __int8)v78;
    goto LABEL_105;
  }
LABEL_40:
  v28 = get_ipc_log_context(mode_bpp);
  v29 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v28, "[d][%-4d]prepare DSC basic params failed\n", *(_DWORD *)(v29 + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]prepare DSC basic params failed\n", *(unsigned int *)(v29 + 1800));
LABEL_42:
  v30 = a3[192];
  *((_BYTE *)a3 + 64) = 0;
  result = 4294967285LL;
  a3[192] = v30 & 0xFFFFFFFE;
LABEL_179:
  _ReadStatusReg(SP_EL0);
  return result;
}
