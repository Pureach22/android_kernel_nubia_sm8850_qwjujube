__int64 __fastcall cam_ife_mgr_start_hw(__int64 a1, __int64 *a2)
{
  __int64 v3; // x19
  __int64 result; // x0
  int drv_enable; // w0
  unsigned __int64 v6; // x9
  _QWORD *v7; // x8
  unsigned __int64 v8; // x24
  __int64 **v9; // x22
  int *v10; // x26
  __int64 *v11; // x10
  int v12; // w6
  __int64 v13; // x10
  __int64 v14; // x21
  __int64 *v15; // x10
  __int64 *v16; // x10
  __int64 *v17; // x10
  __int64 *v18; // x10
  __int64 *v19; // x10
  __int64 *v20; // x10
  __int64 *v21; // x10
  void (__fastcall *v22)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v23; // x0
  __int64 v24; // x8
  unsigned int v25; // w10
  _DWORD *v26; // x11
  _DWORD *v27; // x12
  int v28; // w10
  unsigned int v29; // w10
  _DWORD *v30; // x11
  unsigned int v31; // w10
  _DWORD *v32; // x11
  unsigned int v33; // w10
  _DWORD *v34; // x11
  unsigned int v35; // w10
  _DWORD *v36; // x9
  __int64 v37; // x24
  __int64 v38; // x22
  __int64 v39; // x27
  unsigned __int64 v40; // x23
  int *v41; // x21
  int v42; // w8
  __int64 v43; // x26
  __int64 *v44; // x8
  __int64 v45; // x8
  unsigned int (__fastcall *v46)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v47; // x0
  __int64 *v48; // x8
  __int64 v49; // x8
  unsigned int (__fastcall *v50)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v51; // x0
  __int64 v52; // x8
  unsigned int (__fastcall *v53)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v54; // x0
  _QWORD *v55; // x26
  unsigned int core_idx; // w0
  __int64 v57; // x23
  __int64 (__fastcall *v58)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v59; // x0
  unsigned int v60; // w0
  __int64 (__fastcall *v61)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v62; // x0
  _QWORD *v63; // x26
  __int64 v64; // x24
  __int64 (__fastcall *v65)(__int64, __int64, char *, __int64); // x8
  __int64 v66; // x0
  int v67; // w0
  __int64 v68; // x24
  __int64 (__fastcall *v69)(__int64, __int64, char *, __int64); // x8
  __int64 v70; // x0
  int v71; // w0
  unsigned int inited; // w0
  unsigned int v73; // w20
  unsigned int v74; // w0
  unsigned int v75; // w0
  __int64 v76; // x6
  __int64 v77; // x21
  unsigned __int64 v78; // x22
  unsigned int started; // w0
  int v80; // w0
  int v81; // w21
  unsigned int ife_csid_rdi_res_type; // w22
  __int64 v83; // x7
  unsigned int v84; // w21
  const char *v85; // x5
  __int64 v86; // x4
  __int64 v87; // x6
  __int64 *v88; // x23
  char v89; // w8
  unsigned int v90; // w0
  char v91; // w8
  int v92; // w9
  __int64 v93; // x21
  unsigned __int64 v94; // x23
  unsigned int v95; // w0
  __int64 *v96; // x23
  unsigned int v97; // w0
  __int64 *v98; // x23
  unsigned int v99; // w0
  __int64 v100; // x1
  __int64 v101; // x9
  __int64 v102; // x21
  unsigned int v109; // w8
  __int64 v111; // [xsp+30h] [xbp-110h] BYREF
  __int64 v112; // [xsp+38h] [xbp-108h] BYREF
  __int64 v113; // [xsp+40h] [xbp-100h] BYREF
  __int64 v114; // [xsp+48h] [xbp-F8h] BYREF
  __int64 *v115; // [xsp+50h] [xbp-F0h]
  __int64 v116; // [xsp+58h] [xbp-E8h] BYREF
  __int64 v117; // [xsp+60h] [xbp-E0h]
  __int64 v118; // [xsp+68h] [xbp-D8h]
  __int64 v119; // [xsp+70h] [xbp-D0h]
  __int64 v120; // [xsp+78h] [xbp-C8h]
  __int64 v121; // [xsp+80h] [xbp-C0h]
  __int64 v122; // [xsp+88h] [xbp-B8h]
  __int64 v123; // [xsp+90h] [xbp-B0h]
  __int64 v124; // [xsp+98h] [xbp-A8h]
  __int64 v125; // [xsp+A0h] [xbp-A0h]
  __int64 v126; // [xsp+A8h] [xbp-98h] BYREF
  __int64 v127; // [xsp+B0h] [xbp-90h]
  __int64 v128; // [xsp+B8h] [xbp-88h]
  __int64 v129; // [xsp+C0h] [xbp-80h]
  __int64 v130; // [xsp+C8h] [xbp-78h]
  __int64 v131; // [xsp+D0h] [xbp-70h]
  __int64 v132; // [xsp+D8h] [xbp-68h]
  __int64 v133; // [xsp+E0h] [xbp-60h]
  __int64 v134; // [xsp+E8h] [xbp-58h]
  __int64 v135; // [xsp+F0h] [xbp-50h]
  __int64 v136; // [xsp+F8h] [xbp-48h] BYREF
  int v137; // [xsp+100h] [xbp-40h]
  int v138; // [xsp+104h] [xbp-3Ch]
  __int64 v139; // [xsp+108h] [xbp-38h]
  __int64 v140; // [xsp+110h] [xbp-30h]
  __int64 v141; // [xsp+118h] [xbp-28h]
  __int64 v142; // [xsp+120h] [xbp-20h]
  __int64 v143; // [xsp+128h] [xbp-18h]
  __int64 v144; // [xsp+130h] [xbp-10h]

  v144 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v114 = 0;
  v115 = nullptr;
  v112 = 0;
  v113 = 0;
  v111 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_start_hw",
      8992,
      "Invalid arguments");
    result = 4294967274LL;
    goto LABEL_10;
  }
  v3 = *a2;
  if ( !*a2 || (*(_BYTE *)(v3 + 9376) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_start_hw",
      8999,
      "Invalid context is used");
    result = 0xFFFFFFFFLL;
    goto LABEL_10;
  }
  if ( (*(_BYTE *)(v3 + 9377) & 1) == 0 && *((_BYTE *)a2 + 65) == 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_start_hw",
      9005,
      "Invalid args init_done %d start_only %d, ctx_idx: %u",
      0,
      1,
      *(_DWORD *)(v3 + 56));
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_start_hw",
      9010,
      "Enter... ctx id:%u",
      *(_DWORD *)(v3 + 56));
  drv_enable = cam_cpas_query_drv_enable((unsigned __int64)&byte_3A88D4, (unsigned __int64)&byte_3A88D5);
  if ( drv_enable )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_start_hw",
      9015,
      "Failed to query DRV enable rc: %d",
      drv_enable);
    result = 4294967274LL;
    goto LABEL_10;
  }
  cam_tasklet_start(*(_QWORD *)(v3 + 16));
  if ( *(_BYTE *)(v3 + 9377) == 1 && *((_BYTE *)a2 + 65) == 1 )
  {
    v6 = *(unsigned int *)(v3 + 8716);
    v7 = (_QWORD *)a1;
    if ( (_DWORD)v6 )
    {
      v8 = 0;
      v9 = (__int64 **)(a1 + 160);
      v10 = (int *)(v3 + 8584);
      while ( 1 )
      {
        if ( v8 == 11 )
          goto LABEL_276;
        v11 = *v9;
        v12 = *v10;
        LODWORD(v126) = 0;
        if ( v11 )
        {
          v13 = *v11;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 0;
            goto LABEL_45;
          }
        }
        v15 = (__int64 *)v7[21];
        if ( v15 )
        {
          v13 = *v15;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 1;
            goto LABEL_45;
          }
        }
        v16 = (__int64 *)v7[22];
        if ( v16 )
        {
          v13 = *v16;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 2;
            goto LABEL_45;
          }
        }
        v17 = (__int64 *)v7[23];
        if ( v17 )
        {
          v13 = *v17;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 3;
            goto LABEL_45;
          }
        }
        v18 = (__int64 *)v7[24];
        if ( v18 )
        {
          v13 = *v18;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 4;
            goto LABEL_45;
          }
        }
        v19 = (__int64 *)v7[25];
        if ( v19 )
        {
          v13 = *v19;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 5;
            goto LABEL_45;
          }
        }
        v20 = (__int64 *)v7[26];
        if ( v20 )
        {
          v13 = *v20;
          if ( *(_DWORD *)(v13 + 4) == v12 )
            break;
        }
        v21 = (__int64 *)v7[27];
        if ( v21 )
        {
          v13 = *v21;
          if ( *(_DWORD *)(v13 + 4) == v12 )
          {
            v14 = 7;
LABEL_45:
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_unmask_bus_wr_irq",
                8743,
                "Unmask VFE:%d BUS_WR IRQ",
                v12);
              v13 = *v9[v14];
            }
            v22 = *(void (__fastcall **)(__int64, __int64, __int64 *, __int64))(v13 + 88);
            v23 = *(_QWORD *)(v13 + 112);
            if ( *((_DWORD *)v22 - 1) != -1055839300 )
              __break(0x8228u);
            v22(v23, 35, &v126, 4);
            v6 = *(unsigned int *)(v3 + 8716);
            v7 = (_QWORD *)a1;
          }
        }
        ++v8;
        v10 += 3;
        if ( v8 >= v6 )
          goto LABEL_184;
      }
      v14 = 6;
      goto LABEL_45;
    }
    goto LABEL_184;
  }
  v24 = *(_QWORD *)(v3 + 72);
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v139 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  v136 = *(_QWORD *)(v24 + 80896);
  v137 = *(_DWORD *)(v24 + 80904);
  BYTE4(v139) = *(_BYTE *)(v24 + 81025);
  v138 = *(_DWORD *)(v24 + 80932);
  BYTE5(v139) = *(_BYTE *)(v24 + 81029);
  LODWORD(v139) = *(_DWORD *)(v24 + 80968);
  BYTE6(v139) = *(_BYTE *)(v24 + 81031);
  if ( *(_BYTE *)(v24 + 81033) == 1 )
  {
    v25 = *(_DWORD *)(v24 + 81092);
    if ( v25 )
    {
      v26 = *(_DWORD **)(v24 + 81000);
      HIDWORD(v140) = *v26;
      v27 = *(_DWORD **)(v24 + 81008);
      LODWORD(v142) = *v27;
      if ( v25 != 1 )
      {
        LODWORD(v141) = v26[1];
        HIDWORD(v142) = v27[1];
        if ( v25 >= 3 )
        {
          HIDWORD(v141) = v26[2];
          LODWORD(v143) = v27[2];
          if ( v25 != 3 )
            goto LABEL_276;
        }
      }
    }
    v28 = *(_DWORD *)(v24 + 80992);
    HIBYTE(v139) = 1;
    LODWORD(v140) = v28;
  }
  BYTE4(v135) = 0;
  v126 = *(_QWORD *)(v24 + 80924);
  v29 = *(_DWORD *)(v24 + 81080);
  LODWORD(v127) = v29;
  if ( v29 )
  {
    v30 = *(_DWORD **)(v24 + 80960);
    HIDWORD(v127) = *v30;
    if ( v29 != 1 )
    {
      LODWORD(v128) = v30[1];
      if ( v29 >= 3 )
      {
        HIDWORD(v128) = v30[2];
        if ( v29 != 3 )
        {
          LODWORD(v129) = v30[3];
          if ( v29 >= 5 )
          {
            HIDWORD(v129) = v30[4];
            if ( v29 != 5 )
            {
              LODWORD(v130) = v30[5];
              if ( v29 >= 7 )
              {
                HIDWORD(v130) = v30[6];
                if ( v29 != 7 )
                {
                  LODWORD(v131) = v30[7];
                  if ( v29 > 8 )
                    goto LABEL_276;
                }
              }
            }
          }
        }
      }
    }
  }
  v31 = *(_DWORD *)(v24 + 81088);
  if ( v31 )
  {
    v32 = *(_DWORD **)(v24 + 80984);
    HIDWORD(v131) = *v32;
    if ( v31 != 1 )
    {
      LODWORD(v132) = v32[1];
      if ( v31 >= 3 )
      {
        HIDWORD(v132) = v32[2];
        if ( v31 != 3 )
        {
          LODWORD(v133) = v32[3];
          if ( v31 >= 5 )
          {
            HIDWORD(v133) = v32[4];
            if ( v31 != 5 )
            {
              LODWORD(v134) = v32[5];
              if ( v31 >= 7 )
              {
                HIDWORD(v134) = v32[6];
                if ( v31 != 7 )
                {
                  LODWORD(v135) = v32[7];
                  if ( v31 > 8 )
                    goto LABEL_276;
                }
              }
            }
          }
        }
      }
    }
  }
  WORD2(v125) = *(_WORD *)(v24 + 81023);
  v33 = *(_DWORD *)(v24 + 81076);
  LODWORD(v117) = v33;
  v116 = *(_QWORD *)(v24 + 80912);
  BYTE6(v125) = *(_BYTE *)(v24 + 81034);
  HIBYTE(v125) = byte_3A8575;
  if ( v33 )
  {
    v34 = *(_DWORD **)(v24 + 80952);
    HIDWORD(v117) = *v34;
    if ( v33 != 1 )
    {
      LODWORD(v118) = v34[1];
      if ( v33 >= 3 )
      {
        HIDWORD(v118) = v34[2];
        if ( v33 != 3 )
        {
          LODWORD(v119) = v34[3];
          if ( v33 >= 5 )
          {
            HIDWORD(v119) = v34[4];
            if ( v33 != 5 )
            {
              LODWORD(v120) = v34[5];
              if ( v33 >= 7 )
              {
                HIDWORD(v120) = v34[6];
                if ( v33 != 7 )
                {
                  LODWORD(v121) = v34[7];
                  if ( v33 > 8 )
                    goto LABEL_276;
                }
              }
            }
          }
        }
      }
    }
  }
  v35 = *(_DWORD *)(v24 + 81084);
  if ( v35 )
  {
    v36 = *(_DWORD **)(v24 + 80976);
    HIDWORD(v121) = *v36;
    if ( v35 != 1 )
    {
      LODWORD(v122) = v36[1];
      if ( v35 >= 3 )
      {
        HIDWORD(v122) = v36[2];
        if ( v35 != 3 )
        {
          LODWORD(v123) = v36[3];
          if ( v35 >= 5 )
          {
            HIDWORD(v123) = v36[4];
            if ( v35 != 5 )
            {
              LODWORD(v124) = v36[5];
              if ( v35 >= 7 )
              {
                HIDWORD(v124) = v36[6];
                if ( v35 != 7 )
                {
                  LODWORD(v125) = v36[7];
                  if ( v35 > 8 )
LABEL_276:
                    __break(0x5512u);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(v3 + 8716) )
  {
    v37 = v24 + 96;
    v38 = v24 + 224;
    v39 = v24 + 160;
    v40 = 0;
    v41 = (int *)(v3 + 8592);
    do
    {
      if ( v40 == 11 )
        goto LABEL_276;
      v42 = *v41;
      v43 = (unsigned int)*(v41 - 2);
      if ( *v41 )
      {
        if ( v42 == 7 )
        {
          if ( (unsigned int)v43 > 2 )
            goto LABEL_276;
          v48 = *(__int64 **)(v38 + 8 * v43);
          if ( v48 )
          {
            v49 = *v48;
            v50 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v49 + 88);
            v51 = *(_QWORD *)(v49 + 112);
            if ( *((_DWORD *)v50 - 1) != -1055839300 )
              __break(0x8229u);
            if ( v50(v51, 43, &v126, 80) && (debug_mdl & 8) != 0 && !debug_priority )
              goto LABEL_97;
          }
        }
        else if ( v42 == 2 )
        {
          if ( (unsigned int)v43 > 7 )
            goto LABEL_276;
          v44 = *(__int64 **)(v39 + 8 * v43);
          if ( v44 )
          {
            v45 = *v44;
            v46 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v45 + 88);
            v47 = *(_QWORD *)(v45 + 112);
            if ( *((_DWORD *)v46 - 1) != -1055839300 )
              __break(0x8229u);
            if ( v46(v47, 61, &v116, 80) && (debug_mdl & 8) != 0 && !debug_priority )
              goto LABEL_97;
          }
        }
      }
      else
      {
        if ( (unsigned int)v43 > 7 )
          goto LABEL_276;
        v52 = *(_QWORD *)(v37 + 8 * v43);
        if ( v52 )
        {
          v53 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v52 + 88);
          v54 = *(_QWORD *)(v52 + 112);
          if ( *((_DWORD *)v53 - 1) != -1055839300 )
            __break(0x8229u);
          if ( v53(v54, 46, &v136, 56) && (debug_mdl & 8) != 0 && !debug_priority )
LABEL_97:
            ((void (__fastcall *)(__int64))cam_print_log)(3);
        }
      }
      ++v40;
      v41 += 3;
    }
    while ( v40 < *(unsigned int *)(v3 + 8716) );
  }
  if ( *(_BYTE *)(v3 + 9384) != 1 || (v55 = *(_QWORD **)(v3 + 208), v55 == (_QWORD *)(v3 + 208)) )
  {
LABEL_162:
    v63 = *(_QWORD **)(v3 + 224);
    for ( HIDWORD(v112) = qword_3A8508; v63 != (_QWORD *)(v3 + 224); v63 = (_QWORD *)*v63 )
    {
      v64 = v63[4];
      if ( v64 )
      {
        v65 = *(__int64 (__fastcall **)(__int64, __int64, char *, __int64))(v64 + 104);
        if ( v65 )
        {
          if ( !*(_DWORD *)(v64 + 4) )
          {
            v66 = v63[4];
            if ( *((_DWORD *)v65 - 1) != -1380041226 )
              __break(0x8228u);
            v67 = v65(v66, 19, (char *)&v112 + 4, 4);
            if ( v67 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_start_hw",
                9103,
                "VFE process cmd failed for rsrc_id:%d, rc:%d",
                *(_DWORD *)(v64 + 4),
                v67);
          }
        }
      }
      v68 = v63[5];
      if ( v68 )
      {
        v69 = *(__int64 (__fastcall **)(__int64, __int64, char *, __int64))(v68 + 104);
        if ( v69 )
        {
          if ( !*(_DWORD *)(v68 + 4) )
          {
            v70 = v63[5];
            if ( *((_DWORD *)v69 - 1) != -1380041226 )
              __break(0x8228u);
            v71 = v69(v70, 19, (char *)&v112 + 4, 4);
            if ( v71 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_start_hw",
                9103,
                "VFE process cmd failed for rsrc_id:%d, rc:%d",
                *(_DWORD *)(v68 + 4),
                v71);
          }
        }
      }
    }
    inited = cam_ife_hw_mgr_init_hw(v3);
    if ( inited )
    {
      v73 = inited;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_start_hw",
        9111,
        "Init failed, ctx_idx: %u",
        *(_DWORD *)(v3 + 56));
      goto LABEL_207;
    }
    *(_BYTE *)(v3 + 9377) = 1;
    mutex_lock(&unk_394A30);
    _X9 = &dword_394A60;
    __asm { PRFM            #0x11, [X9] }
    do
      v109 = __ldxr((unsigned int *)&dword_394A60);
    while ( __stlxr(v109 + 1, (unsigned int *)&dword_394A60) );
    __dmb(0xBu);
    if ( !v109 && (unsigned int)cam_ife_notify_safe_lut_scm(1) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_start_hw",
        9123,
        "SAFE SCM call failed:Check TZ/HYP dependency, ctx_idx: %u",
        *(_DWORD *)(v3 + 56));
      mutex_unlock(&unk_394A30);
      v73 = -14;
      goto LABEL_190;
    }
    mutex_unlock(&unk_394A30);
    v74 = cam_cdm_stream_on(*(_DWORD *)(v3 + 8720));
    v7 = (_QWORD *)a1;
    if ( v74 )
    {
      v73 = v74;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_start_hw",
        9134,
        "Can not start cdm (%d), ctx_idx: %u",
        *(_DWORD *)(v3 + 8720),
        *(_DWORD *)(v3 + 56));
LABEL_189:
      cam_ife_notify_safe_lut_scm(0);
LABEL_190:
      cam_ife_hw_mgr_deinit_hw(v3);
      goto LABEL_207;
    }
LABEL_184:
    *(_DWORD *)(v3 + 8844) = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_start_hw",
        9143,
        "Config HW, ctx_idx: %u",
        *(_DWORD *)(v3 + 56));
      v7 = (_QWORD *)a1;
    }
    v75 = cam_ife_mgr_config_hw(v7, a2);
    if ( v75 )
    {
      v76 = *((unsigned __int8 *)a2 + 65);
      v73 = v75;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_start_hw",
        9148,
        "Config HW failed, start_only=%d, rc=%d ctx_idx: %u",
        v76);
      cam_cdm_stream_off(*(_DWORD *)(v3 + 8720));
      goto LABEL_189;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_start_hw",
        9153,
        "START IFE OUT ... in ctx id:%u",
        *(_DWORD *)(v3 + 56));
      if ( *(_DWORD *)(v3 + 8512) )
      {
LABEL_194:
        v77 = 0;
        v78 = 0;
        while ( 1 )
        {
          started = cam_ife_hw_mgr_start_hw_res(*(_QWORD *)(v3 + 272) + v77, v3);
          if ( started )
            break;
          ++v78;
          v77 += 128;
          if ( v78 >= *(unsigned int *)(v3 + 8512) )
            goto LABEL_197;
        }
        v83 = *(unsigned int *)(v3 + 56);
        v84 = started;
        v85 = "Can not start IFE OUT (%d), ctx_idx: %u";
        v86 = 9160;
        v87 = (unsigned int)v78;
        goto LABEL_269;
      }
    }
    else if ( *(_DWORD *)(v3 + 8512) )
    {
      goto LABEL_194;
    }
LABEL_197:
    if ( (*(_BYTE *)(v3 + 9385) & 1) == 0 && *(_BYTE *)(v3 + 9399) != 1
      || *(_DWORD *)(v3 + 9532) >= (unsigned int)dword_3A85A4 )
    {
      v81 = 10;
      ife_csid_rdi_res_type = 12;
      goto LABEL_218;
    }
    *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v3 + 272)
                         + ((unsigned __int64)*(unsigned __int8 *)(*(_QWORD *)(v3 + 8496)
                                                                 + (unsigned __int8)*(_DWORD *)(v3 + 9532)) << 7)
                         + 32)
             + 144LL) = 1;
    v80 = *(_DWORD *)(v3 + 9532);
    if ( v80 <= 12295 )
    {
      if ( v80 == 12294 )
      {
        v81 = 3;
        goto LABEL_217;
      }
      if ( v80 == 12295 )
      {
        v81 = 4;
        goto LABEL_217;
      }
    }
    else
    {
      switch ( v80 )
      {
        case 12296:
          v81 = 5;
          goto LABEL_217;
        case 12297:
          v81 = 6;
          goto LABEL_217;
        case 12327:
          v81 = 7;
LABEL_217:
          ife_csid_rdi_res_type = cam_ife_hw_mgr_get_ife_csid_rdi_res_type();
LABEL_218:
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_start_hw",
              9177,
              "START IFE SRC ... in ctx id:%u",
              *(_DWORD *)(v3 + 56));
          v88 = (__int64 *)(v3 + 224);
          while ( 1 )
          {
            v88 = (__int64 *)*v88;
            if ( v88 == (__int64 *)(v3 + 224) )
              break;
            if ( v81 == *((_DWORD *)v88 + 5) )
            {
              if ( (*(_BYTE *)(v3 + 9385) & 1) != 0 )
                v89 = 1;
              else
                v89 = *(_BYTE *)(v3 + 9399);
              *(_BYTE *)(v88[4] + 144) = v89 & 1;
            }
            v90 = cam_ife_hw_mgr_start_hw_res(v88, v3);
            if ( v90 )
            {
              v87 = *((unsigned int *)v88 + 5);
              v83 = *(unsigned int *)(v3 + 56);
              v84 = v90;
              v85 = "Can not start IFE Mux (%d), ctx_idx: %u";
              v86 = 9188;
              goto LABEL_269;
            }
          }
          v91 = debug_mdl;
          v92 = debug_priority;
          if ( *(_DWORD *)(v3 + 9312) == 2 )
          {
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_start_hw",
                9195,
                "START SFE OUT ... in ctx id:%u",
                *(_DWORD *)(v3 + 56));
              if ( *(_DWORD *)(v3 + 8516) )
              {
LABEL_233:
                v93 = 0;
                v94 = 0;
                while ( 1 )
                {
                  v95 = cam_ife_hw_mgr_start_hw_res(*(_QWORD *)(v3 + 280) + v93, v3);
                  if ( v95 )
                    break;
                  ++v94;
                  v93 += 128;
                  if ( v94 >= *(unsigned int *)(v3 + 8516) )
                    goto LABEL_236;
                }
                v83 = *(unsigned int *)(v3 + 56);
                v84 = v95;
                v85 = "Can not start SFE OUT (%d), ctx_idx: %u";
                v86 = 9202;
                v87 = (unsigned int)v94;
LABEL_269:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_ife_mgr_start_hw",
                  v86,
                  v85,
                  v87,
                  v83);
                goto LABEL_270;
              }
            }
            else if ( *(_DWORD *)(v3 + 8516) )
            {
              goto LABEL_233;
            }
LABEL_236:
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_start_hw",
                9208,
                "START SFE SRC RSRC ... in ctx id:%u",
                *(_DWORD *)(v3 + 56));
            v96 = (__int64 *)(v3 + 240);
            while ( 1 )
            {
              v96 = (__int64 *)*v96;
              if ( v96 == (__int64 *)(v3 + 240) )
                break;
              v97 = cam_ife_hw_mgr_start_hw_res(v96, v3);
              if ( v97 )
              {
                v87 = *((unsigned int *)v96 + 5);
                v83 = *(unsigned int *)(v3 + 56);
                v84 = v97;
                v85 = "Can not start SFE SRC (%d), ctx_idx: %u";
                v86 = 9213;
                goto LABEL_269;
              }
            }
            v91 = debug_mdl;
            v92 = debug_priority;
          }
          if ( (v91 & 8) != 0 && !v92 )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v91 & 8,
              4,
              "cam_ife_mgr_start_hw",
              9220,
              "START BUS RD ... in ctx id:%u",
              *(_DWORD *)(v3 + 56));
          v98 = (__int64 *)(v3 + 256);
          while ( 1 )
          {
            v98 = (__int64 *)*v98;
            if ( v98 == (__int64 *)(v3 + 256) )
              break;
            v99 = cam_ife_hw_mgr_start_hw_res(v98, v3);
            if ( v99 )
            {
              v87 = *((unsigned int *)v98 + 5);
              v83 = *(unsigned int *)(v3 + 56);
              v84 = v99;
              v85 = "Can not start BUS RD (%d), ctx_idx: %u";
              v86 = 9225;
              goto LABEL_269;
            }
          }
          if ( (*(_BYTE *)(v3 + 9388) & 1) != 0 || *(_BYTE *)(v3 + 9387) == 1 )
          {
            v84 = cam_ife_mgr_prog_default_settings(0, 0, 1, v3);
            if ( v84 )
              goto LABEL_270;
            *(_BYTE *)(*(_QWORD *)(v3 + 9368) + 88LL) = 0;
            *(_BYTE *)(*(_QWORD *)(v3 + 9360) + 136LL) = 0;
            *(_DWORD *)(*(_QWORD *)(v3 + 9368) + 4LL) = 0;
            *(_DWORD *)(*(_QWORD *)(v3 + 9360) + 4LL) = 0;
          }
          v100 = a2[5];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            v102 = a2[5];
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_start_hw",
              9242,
              "START CSID HW ... in ctx id:%u",
              *(_DWORD *)(v3 + 56));
            v100 = v102;
          }
          v84 = cam_ife_mgr_csid_start_hw(
                  v3,
                  v100,
                  ife_csid_rdi_res_type,
                  *((unsigned __int8 *)a2 + 64),
                  *((unsigned __int8 *)a2 + 65),
                  *((unsigned __int8 *)a2 + 66),
                  *((unsigned __int8 *)a2 + 67));
          if ( !v84 )
          {
            if ( dword_3A88C8 )
            {
              if ( *(_DWORD *)(v3 + 60) != 8 )
                cam_ife_hw_mgr_print_debug_reg(v3, 0, 5);
              if ( *(_DWORD *)(v3 + 64) != 8 )
                cam_ife_hw_mgr_print_debug_reg(v3, 0, 5);
            }
            result = 0;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_mgr_start_hw",
                9260,
                "Start success for ctx id:%u",
                *(_DWORD *)(v3 + 56));
              result = 0;
            }
            goto LABEL_10;
          }
LABEL_270:
          v101 = *a2;
          LODWORD(v113) = 1;
          BYTE5(v113) = 0;
          v114 = v101;
          v115 = &v113;
          cam_ife_mgr_stop_hw(a1, &v114);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_start_hw",
              9271,
              "Exit...(rc=%d), ctx_idx: %u",
              v84,
              *(_DWORD *)(v3 + 56));
          result = v84;
          goto LABEL_10;
      }
    }
    v81 = 10;
    goto LABEL_217;
  }
  while ( 1 )
  {
    if ( !v55[4] )
      goto LABEL_145;
    if ( *(_DWORD *)(v3 + 9312) == 2 )
    {
      LODWORD(v111) = 2;
      core_idx = cam_ife_mgr_find_core_idx(0, v3, 7, (char *)&v111 + 4);
      if ( core_idx )
        break;
    }
    else
    {
      LODWORD(v111) = 1;
    }
    if ( *(_BYTE *)(v3 + 9380) == 1 )
      LOBYTE(v112) = 1;
    if ( *(_BYTE *)(v3 + 9388) == 1 )
      BYTE1(v112) = 1;
    v57 = *(_QWORD *)(v55[4] + 16LL);
    v58 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v57 + 88);
    v59 = *(_QWORD *)(v57 + 112);
    if ( *((_DWORD *)v58 - 1) != -1055839300 )
      __break(0x8228u);
    v60 = v58(v59, 50, &v111, 12);
    if ( v60 )
    {
LABEL_205:
      v73 = v60;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_start_hw",
        9074,
        "CSID: %u top config cmd failed, rc:%d",
        *(_DWORD *)(v57 + 4),
        v60);
      goto LABEL_207;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_start_hw",
        9081,
        "CSID: %u split_id: %d core_idx: %u core_type: %u is_sfe_offline: %d ctx_idx: %u",
        *(_DWORD *)(v57 + 4),
        0,
        HIDWORD(v111),
        v111,
        (unsigned __int8)v112,
        *(_DWORD *)(v3 + 56));
      if ( !v55[5] )
        goto LABEL_130;
    }
    else
    {
LABEL_145:
      if ( !v55[5] )
        goto LABEL_130;
    }
    if ( *(_DWORD *)(v3 + 9312) != 2 )
    {
      LODWORD(v111) = 1;
      goto LABEL_150;
    }
    LODWORD(v111) = 2;
    core_idx = cam_ife_mgr_find_core_idx(1, v3, 7, (char *)&v111 + 4);
    if ( core_idx )
      break;
LABEL_150:
    if ( *(_BYTE *)(v3 + 9380) == 1 )
      LOBYTE(v112) = 1;
    if ( *(_BYTE *)(v3 + 9388) == 1 )
      BYTE1(v112) = 1;
    v57 = *(_QWORD *)(v55[5] + 16LL);
    v61 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v57 + 88);
    v62 = *(_QWORD *)(v57 + 112);
    if ( *((_DWORD *)v61 - 1) != -1055839300 )
      __break(0x8228u);
    v60 = v61(v62, 50, &v111, 12);
    if ( v60 )
      goto LABEL_205;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_start_hw",
        9081,
        "CSID: %u split_id: %d core_idx: %u core_type: %u is_sfe_offline: %d ctx_idx: %u",
        *(_DWORD *)(v57 + 4),
        1,
        HIDWORD(v111),
        v111,
        (unsigned __int8)v112,
        *(_DWORD *)(v3 + 56));
LABEL_130:
    v55 = (_QWORD *)*v55;
    if ( v55 == (_QWORD *)(v3 + 208) )
      goto LABEL_162;
  }
  v73 = core_idx;
LABEL_207:
  cam_tasklet_stop(*(_QWORD *)(v3 + 16));
  result = v73;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
