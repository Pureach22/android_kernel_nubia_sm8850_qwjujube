__int64 __fastcall dp_catalog_panel_config_hdr(__int64 a1, char a2, int a3, char a4)
{
  unsigned int v4; // w8
  _DWORD **v6; // x24
  __int64 v7; // x26
  _DWORD *v8; // x13
  int v9; // w20
  __int64 v11; // x0
  unsigned int v12; // w28
  unsigned int v13; // w25
  int v14; // w0
  _DWORD *v15; // x8
  int v16; // w23
  int v17; // w0
  _DWORD *v18; // x8
  _DWORD **v19; // x21
  int v20; // w24
  _DWORD **v21; // x20
  _DWORD *v22; // x8
  __int64 v23; // x28
  __int64 v24; // x22
  __int64 v25; // x0
  unsigned int v26; // w8
  unsigned int v27; // w9
  int v28; // w26
  bool v29; // w10
  unsigned __int8 v30; // w11
  unsigned int v31; // w10
  unsigned int v32; // w12
  __int64 v33; // x25
  __int64 v34; // x3
  _DWORD *v35; // x9
  __int64 v36; // x1
  unsigned int v37; // w3
  bool v38; // w8
  unsigned __int8 v39; // w9
  unsigned int v40; // w8
  unsigned int v41; // w10
  __int64 v42; // x3
  _DWORD *v43; // x8
  unsigned int v44; // w8
  bool v45; // w9
  unsigned __int8 v46; // w10
  unsigned int v47; // w9
  unsigned int v48; // w11
  int v49; // w28
  _DWORD *v50; // x8
  unsigned int v51; // w0
  _DWORD *v52; // x8
  __int64 v53; // x3
  _DWORD **v54; // x21
  _DWORD *v55; // x8
  _DWORD *v56; // x8
  _DWORD *v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  unsigned __int64 v60; // x21
  __int64 result; // x0
  char v62; // w22
  _DWORD **v63; // x25
  _DWORD *v64; // x8
  _DWORD *v65; // x8
  __int64 v66; // x0
  unsigned int v67; // w8
  unsigned int v68; // w9
  int v69; // w23
  bool v70; // w10
  unsigned __int8 v71; // w11
  unsigned int v72; // w10
  unsigned int v73; // w12
  __int64 v74; // x22
  __int64 v75; // x3
  _DWORD *v76; // x9
  __int64 v77; // x1
  unsigned int v78; // w3
  bool v79; // w8
  unsigned __int8 v80; // w9
  unsigned int v81; // w8
  unsigned int v82; // w10
  __int64 v83; // x3
  _DWORD *v84; // x8
  unsigned int v85; // w8
  bool v86; // w9
  unsigned __int8 v87; // w10
  unsigned int v88; // w9
  unsigned int v89; // w11
  int v90; // w24
  _DWORD *v91; // x8
  unsigned int v92; // w0
  _DWORD *v93; // x8
  __int64 v94; // x3
  _DWORD *v95; // x8
  __int64 v96; // x3
  _DWORD *v97; // x8
  __int64 v98; // x3
  _DWORD *v99; // x8
  __int64 v100; // x3
  _DWORD *v101; // x8
  __int64 v102; // x3
  _DWORD *v103; // x8
  __int64 v104; // x3
  _DWORD *v105; // x8
  __int64 v106; // x3
  _DWORD *v107; // x8
  _DWORD *v108; // x8
  __int64 v109; // x0
  int v110; // w22
  __int64 v111; // x0
  unsigned __int64 StatusReg; // x8
  int v113; // w2
  unsigned int *v114; // x21
  __int64 v115; // x0
  unsigned __int64 v116; // x21
  __int64 v117; // x0
  unsigned int v118; // w8
  _DWORD **v119; // x22
  __int64 v120; // x19
  _DWORD *v121; // x10
  unsigned int v122; // w21
  __int64 v123; // x1
  _DWORD *v124; // x8
  __int64 v125; // x0
  __int64 ipc_log_context; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  int v130; // [xsp+Ch] [xbp-14h]
  __int64 *v133; // [xsp+18h] [xbp-8h]

  if ( a1 )
  {
    v4 = *(_DWORD *)(a1 + 204);
    if ( v4 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_config_hdr");
    }
    else
    {
      v6 = (_DWORD **)(a1 - 456);
      v7 = *(_QWORD *)(a1 - 552);
      v8 = *(_DWORD **)(a1 - 456);
      if ( v4 == 1 )
        v9 = 696;
      else
        v9 = 0;
      v133 = (__int64 *)(a1 - 552);
      v11 = a1 - 576;
      if ( v4 == 1 )
        v12 = 1068;
      else
        v12 = 44;
      if ( v4 == 1 )
        v13 = 1264;
      else
        v13 = 1260;
      if ( *(v8 - 1) != -1879227436 )
        __break(0x822Du);
      v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v8)(v11, v7, (unsigned int)(v9 + 552));
      v15 = *v6;
      v16 = v14;
      if ( *(*v6 - 1) != -1879227436 )
        __break(0x8228u);
      v17 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v15)(a1 - 576, v7, (unsigned int)(v9 + 556));
      v18 = *v6;
      v19 = (_DWORD **)(a1 - 456);
      v20 = v17;
      if ( *(v18 - 1) != -1879227436 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v18)(a1 - 576, v7, v12);
      if ( (a2 & 1) != 0 )
      {
        v130 = v9;
        if ( a3 )
        {
          v21 = (_DWORD **)(a1 - 448);
          v22 = *(_DWORD **)(a1 - 448);
          v16 |= 0x10000u;
          v23 = a1 - 576;
          v24 = v7;
          if ( *(v22 - 1) != -626862723 )
            __break(0x8228u);
          v25 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v22)(a1 - 576, v7, v13, (2 * a3) | 1u);
          v26 = *(_DWORD *)(a1 + 204);
          if ( v26 >= 2 )
          {
            v129 = get_ipc_log_context(v25);
            ipc_log_string(
              v129,
              "[e][%-4d]invalid stream_id:%d\n",
              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
              *(_DWORD *)(a1 + 204));
            printk(&unk_272496, "dp_catalog_panel_setup_vsif_infoframe_sdp");
          }
          else
          {
            v27 = *(unsigned __int8 *)(a1 + 69);
            if ( v26 == 1 )
              v28 = 408;
            else
              v28 = 0;
            v29 = (v27 & 8) != 0;
            v30 = v29 ^ v27 & 0xF;
            v31 = (v30 & 1
                 | (4 * (((v27 >> 2) & 3 ^ (v27 >> 1) & 7) & 1)) & 0xF5
                 | (8 * (((v27 >> 2) & 3 ^ v29) & 1))
                 | (2 * ((v30 ^ (v27 >> 1) & 7) & 1)))
                ^ (v27 >> 4);
            v32 = v31 >> 3;
            v33 = *v133;
            v34 = ((((v32 ^ v31) & 1
                   | (4 * (((unsigned __int8)(v31 >> 2) ^ (unsigned __int8)(v31 >> 1)) & 1)) & 0xF5
                   | (8 * (((v31 >> 2) ^ v32) & 1))
                   | (2 * (((unsigned __int8)(v32 ^ v31) ^ (unsigned __int8)(v31 >> 1)) & 1)))
                  ^ ((2 * v27) & 0xC | (2 * (v30 & 1)) | (v27 >> 3) & 1)) << 24)
                | (((2 * v31) & 0xC | (2 * ((v32 ^ v31) & 1)) | v32) << 28)
                | (v27 << 16);
            v35 = *v21;
            v36 = *v133;
            if ( *(*v21 - 1) != -626862723 )
              __break(0x8229u);
            ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v35)(a1 - 576, v36, (unsigned int)(v28 + 720), v34);
            v37 = *(unsigned __int8 *)(a1 + 70);
            v38 = (v37 & 8) != 0;
            v39 = v38 ^ v37 & 0xF;
            v40 = (v39 & 1
                 | (4 * (((*(_BYTE *)(a1 + 70) >> 2) & 3 ^ (*(_BYTE *)(a1 + 70) >> 1) & 7) & 1)) & 0xF5
                 | (8 * (((*(_BYTE *)(a1 + 70) >> 2) & 3 ^ v38) & 1))
                 | (2 * ((v39 ^ (*(_BYTE *)(a1 + 70) >> 1) & 7) & 1)))
                ^ (v37 >> 4);
            v41 = v40 >> 3;
            v42 = v37 & 0xFFFF00FF
                | (((((unsigned __int8)v41 ^ (unsigned __int8)v40) & 1
                   | (4 * (((unsigned __int8)(v40 >> 2) ^ (unsigned __int8)(v40 >> 1)) & 1)) & 0xF5
                   | (unsigned __int8)(8 * (((v40 >> 2) ^ v41) & 1))
                   | (unsigned __int8)(2 * ((v41 ^ v40 ^ (v40 >> 1)) & 1)))
                  ^ ((2 * (_BYTE)v37) & 0xC | (unsigned __int8)(2 * (v39 & 1)) | ((v37 & 8) != 0))
                  | (unsigned __int8)(16 * ((2 * v40) & 0xC | (2 * ((v41 ^ v40) & 1)) | v41))) << 8);
            v43 = *v21;
            if ( *(*v21 - 1) != -626862723 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v43)(a1 - 576, v33, (unsigned int)(v28 + 724), v42);
            v44 = *(unsigned __int8 *)(a1 + 71);
            v45 = (v44 & 8) != 0;
            v46 = v45 ^ v44 & 0xF;
            v47 = (v46 & 1
                 | (4 * (((*(_BYTE *)(a1 + 71) >> 2) & 3 ^ (*(_BYTE *)(a1 + 71) >> 1) & 7) & 1)) & 0xF5
                 | (8 * (((*(_BYTE *)(a1 + 71) >> 2) & 3 ^ v45) & 1))
                 | (2 * ((v46 ^ (*(_BYTE *)(a1 + 71) >> 1) & 7) & 1)))
                ^ (v44 >> 4);
            v48 = v47 >> 3;
            v49 = ((((v48 ^ v47) & 1
                   | (4 * (((unsigned __int8)(v47 >> 2) ^ (unsigned __int8)(v47 >> 1)) & 1)) & 0xF5
                   | (8 * (((v47 >> 2) ^ v48) & 1))
                   | (2 * (((unsigned __int8)(v48 ^ v47) ^ (unsigned __int8)(v47 >> 1)) & 1)))
                  ^ ((2 * v44) & 0xC | (2 * (v46 & 1)) | (v44 >> 3) & 1)) << 24)
                | (((2 * v47) & 0xC | (2 * ((v48 ^ v47) & 1)) | v48) << 28)
                | (v44 << 16);
            v50 = *v19;
            if ( *(*v19 - 1) != -1879227436 )
              __break(0x8228u);
            v51 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v50)(a1 - 576, v33, (unsigned int)(v28 + 724));
            v52 = *v21;
            v53 = v49 | v51;
            v23 = a1 - 576;
            if ( *(*v21 - 1) != -626862723 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v52)(a1 - 576, v33, (unsigned int)(v28 + 724), v53);
          }
        }
        else
        {
          v23 = a1 - 576;
          v24 = v7;
        }
        v63 = (_DWORD **)(a1 - 448);
        v64 = *(_DWORD **)(a1 - 448);
        if ( *(v64 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v64)(
          v23,
          v24,
          (unsigned int)(v130 + 552),
          v16 | 0x80000u);
        v65 = *v63;
        if ( *(*v63 - 1) != -626862723 )
          __break(0x8228u);
        v66 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v65)(
                v23,
                v24,
                (unsigned int)(v130 + 556),
                v20 | 0x100000u);
        v67 = *(_DWORD *)(a1 + 204);
        if ( v67 >= 2 )
        {
          v127 = get_ipc_log_context(v66);
          ipc_log_string(
            v127,
            "[e][%-4d]invalid stream_id:%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 204));
          v109 = printk(&unk_272496, "dp_catalog_panel_setup_hdr_infoframe_sdp");
        }
        else
        {
          v68 = *(unsigned __int8 *)(a1 + 73);
          if ( v67 == 1 )
            v69 = 312;
          else
            v69 = 0;
          v70 = (v68 & 8) != 0;
          v71 = v70 ^ v68 & 0xF;
          v72 = (v71 & 1
               | (4 * (((v68 >> 2) & 3 ^ (v68 >> 1) & 7) & 1)) & 0xF5
               | (8 * (((v68 >> 2) & 3 ^ v70) & 1))
               | (2 * ((v71 ^ (v68 >> 1) & 7) & 1)))
              ^ (v68 >> 4);
          v73 = v72 >> 3;
          v74 = *v133;
          v75 = ((((v73 ^ v72) & 1
                 | (4 * (((unsigned __int8)(v72 >> 2) ^ (unsigned __int8)(v72 >> 1)) & 1)) & 0xF5
                 | (8 * (((v72 >> 2) ^ v73) & 1))
                 | (2 * (((unsigned __int8)(v73 ^ v72) ^ (unsigned __int8)(v72 >> 1)) & 1)))
                ^ ((2 * v68) & 0xC | (2 * (v71 & 1)) | (v68 >> 3) & 1)) << 24)
              | (((2 * v72) & 0xC | (2 * ((v73 ^ v72) & 1)) | v73) << 28)
              | (v68 << 16);
          v76 = *v63;
          v77 = *v133;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v76)(v23, v77, (unsigned int)(v69 + 984), v75);
          v78 = *(unsigned __int8 *)(a1 + 74);
          v79 = (v78 & 8) != 0;
          v80 = v79 ^ v78 & 0xF;
          v81 = (v80 & 1
               | (4 * (((*(_BYTE *)(a1 + 74) >> 2) & 3 ^ (*(_BYTE *)(a1 + 74) >> 1) & 7) & 1)) & 0xF5
               | (8 * (((*(_BYTE *)(a1 + 74) >> 2) & 3 ^ v79) & 1))
               | (2 * ((v80 ^ (*(_BYTE *)(a1 + 74) >> 1) & 7) & 1)))
              ^ (v78 >> 4);
          v82 = v81 >> 3;
          v83 = v78 & 0xFFFF00FF
              | (((((unsigned __int8)v82 ^ (unsigned __int8)v81) & 1
                 | (4 * (((unsigned __int8)(v81 >> 2) ^ (unsigned __int8)(v81 >> 1)) & 1)) & 0xF5
                 | (unsigned __int8)(8 * (((v81 >> 2) ^ v82) & 1))
                 | (unsigned __int8)(2 * ((v82 ^ v81 ^ (v81 >> 1)) & 1)))
                ^ ((2 * (_BYTE)v78) & 0xC | (unsigned __int8)(2 * (v80 & 1)) | ((v78 & 8) != 0))
                | (unsigned __int8)(16 * ((2 * v81) & 0xC | (2 * ((v82 ^ v81) & 1)) | v82))) << 8);
          v84 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v84)(v23, v74, (unsigned int)(v69 + 988), v83);
          v85 = *(unsigned __int8 *)(a1 + 75);
          v86 = (v85 & 8) != 0;
          v87 = v86 ^ v85 & 0xF;
          v88 = (v87 & 1
               | (4 * (((*(_BYTE *)(a1 + 75) >> 2) & 3 ^ (*(_BYTE *)(a1 + 75) >> 1) & 7) & 1)) & 0xF5
               | (8 * (((*(_BYTE *)(a1 + 75) >> 2) & 3 ^ v86) & 1))
               | (2 * ((v87 ^ (*(_BYTE *)(a1 + 75) >> 1) & 7) & 1)))
              ^ (v85 >> 4);
          v89 = v88 >> 3;
          v90 = ((((v89 ^ v88) & 1
                 | (4 * (((unsigned __int8)(v88 >> 2) ^ (unsigned __int8)(v88 >> 1)) & 1)) & 0xF5
                 | (8 * (((v88 >> 2) ^ v89) & 1))
                 | (2 * (((unsigned __int8)(v89 ^ v88) ^ (unsigned __int8)(v88 >> 1)) & 1)))
                ^ ((2 * v85) & 0xC | (2 * (v87 & 1)) | (v85 >> 3) & 1)) << 24)
              | (((2 * v88) & 0xC | (2 * ((v89 ^ v88) & 1)) | v89) << 28)
              | (v85 << 16);
          v91 = *v19;
          if ( *(*v19 - 1) != -1879227436 )
            __break(0x8228u);
          v92 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v91)(v23, v74, (unsigned int)(v69 + 724));
          v93 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v93)(v23, v74, (unsigned int)(v69 + 988), v90 | v92);
          v94 = (*(_DWORD *)(a1 + 84) << 16) | 0x1A01u;
          v95 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v95)(v23, v74, (unsigned int)(v69 + 992), v94);
          v96 = (unsigned int)(*(_DWORD *)(a1 + 92) | (*(_DWORD *)(a1 + 104) << 16));
          v97 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v97)(v23, v74, (unsigned int)(v69 + 996), v96);
          v98 = (unsigned int)(*(_DWORD *)(a1 + 96) | (*(_DWORD *)(a1 + 108) << 16));
          v99 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v99)(v23, v74, (unsigned int)(v69 + 1000), v98);
          v100 = (unsigned int)(*(_DWORD *)(a1 + 100) | (*(_DWORD *)(a1 + 112) << 16));
          v101 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v101)(v23, v74, (unsigned int)(v69 + 1004), v100);
          v102 = (unsigned int)(*(_DWORD *)(a1 + 116) | (*(_DWORD *)(a1 + 120) << 16));
          v103 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v103)(v23, v74, (unsigned int)(v69 + 1008), v102);
          v104 = (unsigned int)(*(_DWORD *)(a1 + 124) | (*(_DWORD *)(a1 + 128) << 16));
          v105 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v105)(v23, v74, (unsigned int)(v69 + 1012), v104);
          v106 = (unsigned int)(*(_DWORD *)(a1 + 132) | (*(_DWORD *)(a1 + 136) << 16));
          v107 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v107)(v23, v74, (unsigned int)(v69 + 1016), v106);
          v108 = *v63;
          if ( *(*v63 - 1) != -626862723 )
            __break(0x8228u);
          v109 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v108)(
                   v23,
                   v74,
                   (unsigned int)(v69 + 1020),
                   0);
        }
        v110 = *(_DWORD *)(a1 + 84);
        v111 = get_ipc_log_context(v109);
        StatusReg = _ReadStatusReg(SP_EL0);
        v113 = *(_DWORD *)(StatusReg + 1800);
        v114 = (unsigned int *)(StatusReg + 1800);
        if ( v110 )
        {
          result = ipc_log_string(v111, "[d][%-4d]Enabled\n", v113);
          v62 = a4;
          if ( (_drm_debug & 4) != 0 )
            result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Enabled\n", *v114);
        }
        else
        {
          result = ipc_log_string(v111, "[d][%-4d]Reset\n", v113);
          v62 = a4;
          if ( (_drm_debug & 4) != 0 )
            result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Reset\n", *v114);
        }
      }
      else
      {
        v54 = (_DWORD **)(a1 - 448);
        v55 = *(_DWORD **)(a1 - 448);
        if ( *(v55 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v55)(
          a1 - 576,
          v7,
          (unsigned int)(v9 + 552),
          v16 & 0xFFF6FFFF);
        v56 = *v54;
        if ( *(*v54 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v56)(
          a1 - 576,
          v7,
          (unsigned int)(v9 + 556),
          v20 & 0xFFEFFFFF);
        v57 = *v54;
        if ( *(*v54 - 1) != -626862723 )
          __break(0x8228u);
        v58 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v57)(a1 - 576, v7, v13, 0);
        v59 = get_ipc_log_context(v58);
        v60 = _ReadStatusReg(SP_EL0);
        result = ipc_log_string(v59, "[d][%-4d]Disabled\n", *(_DWORD *)(v60 + 1800));
        v62 = a4;
        v23 = a1 - 576;
        if ( (_drm_debug & 4) != 0 )
          result = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Disabled\n", *(unsigned int *)(v60 + 1800));
      }
      if ( (v62 & 1) != 0 )
      {
        v115 = get_ipc_log_context(result);
        v116 = _ReadStatusReg(SP_EL0);
        v117 = ipc_log_string(v115, "[d][%-4d]flushing HDR metadata\n", *(_DWORD *)(v116 + 1800));
        if ( (_drm_debug & 4) != 0 )
          v117 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]flushing HDR metadata\n", *(_DWORD *)(v116 + 1800));
        v118 = *(_DWORD *)(a1 + 204);
        if ( v118 >= 2 )
        {
          v128 = get_ipc_log_context(v117);
          ipc_log_string(v128, "[e][%-4d]invalid stream_id:%d\n", *(_DWORD *)(v116 + 1800), *(_DWORD *)(a1 + 204));
          return printk(&unk_272496, "dp_catalog_panel_sdp_update");
        }
        else
        {
          v119 = (_DWORD **)(a1 - 448);
          v120 = *v133;
          v121 = *v119;
          if ( v118 == 1 )
            v122 = 1256;
          else
            v122 = 588;
          v123 = *v133;
          if ( *(v121 - 1) != -626862723 )
            __break(0x822Au);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v121)(v23, v123, v122, 1);
          v124 = *v119;
          if ( *(*v119 - 1) != -626862723 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v124)(v23, v120, v122, 0);
        }
      }
    }
  }
  else
  {
    v125 = get_ipc_log_context(0);
    ipc_log_string(v125, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_hdr");
  }
  return result;
}
