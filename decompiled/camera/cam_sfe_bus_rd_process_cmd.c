__int64 __fastcall cam_sfe_bus_rd_process_cmd(int *a1, int a2, __int64 *a3)
{
  __int64 v5; // x21
  __int64 v6; // x9
  __int64 v7; // x9
  int v8; // w0
  const char *v9; // x5
  __int64 v10; // x0
  __int64 v11; // x1
  const char *v12; // x3
  __int64 v13; // x4
  __int64 result; // x0
  int *v15; // x19
  int v16; // w8
  int v17; // w6
  _DWORD *v18; // x9
  unsigned int v19; // w8
  int *v20; // x20
  __int64 v21; // x6
  __int64 v22; // x22
  int v23; // w0
  int v24; // w20
  unsigned int v25; // w24
  __int64 v26; // x9
  int v27; // w8
  __int64 v28; // x8
  __int64 v29; // x21
  __int64 v30; // x22
  __int64 v31; // x8
  int v32; // w7
  int v33; // w6
  __int64 v34; // x8
  __int64 v35; // x20
  _DWORD *v36; // x19
  int v37; // w10
  _DWORD *v38; // x11
  int v39; // w8
  int v40; // w9
  int v41; // w12
  int v42; // w10
  _DWORD *v43; // x12
  int v44; // w8
  int v45; // w9
  int v46; // w11
  __int64 v47; // x8
  _QWORD *v48; // x26
  int v49; // w6
  int v50; // w7
  __int64 v51; // x22
  unsigned int v52; // w21
  _DWORD **v53; // x28
  __int64 v54; // x8
  unsigned int v55; // w24
  unsigned int v56; // w25
  unsigned int v57; // w27
  unsigned __int64 v58; // x23
  char v59; // w0
  unsigned int v60; // w21
  int v61; // w9
  __int64 v62; // x0
  int v63; // w8
  int v64; // w10
  _QWORD *v65; // x23
  int v66; // w26
  _DWORD *v67; // x8
  _DWORD *v68; // x9
  __int64 v69; // x22
  __int64 v70; // x21
  __int64 v71; // x20
  unsigned int v72; // w19
  int *v73; // x9
  __int64 v74; // x22
  int *v75; // x23
  __int64 v76; // x8
  int v77; // w27
  int v78; // w25
  int v79; // w26
  int v80; // w28
  int v81; // w21
  int v82; // w24
  int v83; // w0
  unsigned int v84; // w1
  __int64 v85; // x21
  int v86; // w24
  int v88; // w0
  const char *v89; // x5
  __int64 v90; // x0
  __int64 v91; // x1
  __int64 v92; // x2
  const char *v93; // x3
  __int64 v94; // x4
  const char *v95; // x3
  const char *v96; // x5
  __int64 v97; // x1
  __int64 v98; // x2
  __int64 v99; // x4
  const char *v100; // x5
  __int64 v101; // x4
  __int64 v102; // x22
  _DWORD *v103; // x23
  __int64 v104; // x8
  _DWORD *v105; // x10
  unsigned int v106; // w20
  __int64 v107; // x8
  _DWORD *v108; // x9
  __int64 (__fastcall *v109)(_QWORD); // x8
  unsigned int v110; // w21
  const char *v111; // x3
  __int64 v112; // x4
  _DWORD *v113; // x8
  __int64 v114; // x0
  _DWORD *v115; // x2
  __int64 v116; // x1
  __int64 v117; // x8
  int v118; // w19
  int v119; // w20
  int v120; // w24
  int v121; // w25
  int v122; // w21
  int v123; // w23
  int v124; // w0
  unsigned __int64 v125; // x22
  unsigned int v126; // w25
  _DWORD *v127; // x27
  __int64 v128; // x28
  _DWORD *v129; // x10
  int *v130; // x8
  unsigned int *v131; // x9
  int *v132; // x10
  int v133; // w26
  unsigned int v134; // w24
  _DWORD **v135; // x21
  int v136; // w25
  unsigned __int64 v137; // x23
  char is_expanded_memory; // w0
  int v139; // w10
  int v140; // w9
  int v141; // w8
  int v142; // w9
  int v143; // w10
  int v144; // w11
  int v145; // w10
  _DWORD *v146; // x24
  int v147; // w8
  int v148; // w8
  _DWORD *v149; // x8
  int v150; // w8
  _DWORD *v151; // x9
  int v152; // w8
  __int64 (__fastcall *v153)(_QWORD); // x8
  const char *v154; // x7
  const char *v155; // x7
  int *v156; // x10
  int v157; // w11
  int v158; // w7
  int v159; // w9
  int v160; // w6
  const char *v161; // x10
  int *v162; // x10
  int v163; // w11
  int v164; // w7
  int v165; // w9
  int v166; // w6
  const char *v167; // x10
  __int64 v168; // [xsp+30h] [xbp-30h]
  __int64 v169; // [xsp+38h] [xbp-28h]
  __int64 v170; // [xsp+40h] [xbp-20h]
  __int64 v171; // [xsp+48h] [xbp-18h]
  __int64 v172; // [xsp+48h] [xbp-18h]
  unsigned int v173; // [xsp+50h] [xbp-10h]
  int v174; // [xsp+50h] [xbp-10h]
  unsigned int v175; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v176; // [xsp+58h] [xbp-8h]

  v176 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v8 = __ratelimit(&cam_sfe_bus_rd_process_cmd__rs, "cam_sfe_bus_rd_process_cmd");
    v9 = "Invalid input arguments";
    if ( v8 )
      v10 = 3;
    else
      v10 = 2;
    v11 = 0x40000000;
    v12 = "cam_sfe_bus_rd_process_cmd";
    v13 = 2020;
    goto LABEL_22;
  }
  if ( a2 <= 42 )
  {
    if ( a2 <= 16 )
    {
      if ( a2 != 2 )
      {
        if ( a2 == 7 )
        {
          result = 0;
          *(_DWORD *)a3[5] = *(_DWORD *)(*(_QWORD *)(*a3 + 24) + 80LL) == 1;
          goto LABEL_24;
        }
        goto LABEL_120;
      }
      v28 = *a3;
      v175 = 0;
      v29 = *(_QWORD *)(v28 + 24);
      if ( !v29 || (v30 = *(_QWORD *)(v29 + 64)) == 0 )
      {
        v12 = "cam_sfe_bus_rd_update_rm";
        v9 = "Invalid data";
        v10 = 3;
        v11 = 0x40000000;
        v13 = 1517;
        goto LABEL_22;
      }
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      {
        if ( *((_BYTE *)a3 + 32) )
          v155 = "true";
        else
          v155 = "false";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_bus_rd_update_rm",
          1524,
          "#of RM: %d scratch_buf_cfg: %s",
          *(_DWORD *)(v29 + 24),
          v155);
      }
      v31 = a3[5];
      v32 = *(_DWORD *)(v29 + 24);
      v33 = *(_DWORD *)(v31 + 20);
      if ( v33 != v32 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_rd_update_rm",
          1529,
          "Failed! Invalid number buffers:%d required:%d",
          v33,
          v32);
        goto LABEL_23;
      }
      if ( (a3[4] & 1) != 0 )
        v34 = 0;
      else
        v34 = *(_QWORD *)(v31 + 56);
      if ( v33 )
      {
        v168 = v30;
        v125 = 0;
        v126 = 0;
        v127 = (_DWORD *)(v34 + 24);
        v174 = 0;
        v170 = v29;
        v172 = *(_QWORD *)(v29 + 8) + 40LL;
        v169 = v29 + 32;
        do
        {
          v128 = v126;
          if ( v126 >= 0x38 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_rd_update_rm",
              1541,
              "reg_val_pair %d exceeds the array limit %lu",
              v126,
              84);
            result = 4294967284LL;
            goto LABEL_24;
          }
          if ( v125 == 2 )
            goto LABEL_254;
          if ( *((_BYTE *)a3 + 32) == 1 )
          {
            v129 = (_DWORD *)a3[5];
            v130 = v129 + 12;
            v131 = v129 + 10;
            v132 = v129 + 11;
          }
          else
          {
            v130 = v127 + 2;
            v132 = v127 + 1;
            v131 = v127;
          }
          v133 = *v132;
          v134 = *v131;
          v135 = *(_DWORD ***)(*(_QWORD *)(v169 + 8 * v125) + 24LL);
          if ( *((_DWORD *)v135 + 10) && *((_DWORD *)v135 + 11) )
          {
            v134 = *((_DWORD *)v135 + 10);
            v133 = *((_DWORD *)v135 + 11);
          }
          v136 = *v130;
          v137 = *(_QWORD *)(*(_QWORD *)a3[5] + 8 * v125) + *((unsigned int *)v135 + 21);
          is_expanded_memory = cam_smmu_is_expanded_memory();
          v139 = v174;
          if ( (is_expanded_memory & 1) != 0 )
          {
            v139 = (unsigned __int8)v137;
            LODWORD(v137) = v137 >> 8;
          }
          v174 = v139;
          cam_sfe_bus_rd_pxls_to_bytes(v134, *((unsigned int *)v135 + 15), &v175);
          *((_DWORD *)v135 + 10) = v134;
          *((_DWORD *)v135 + 11) = v133;
          v140 = *((unsigned __int8 *)v135 + 88);
          v141 = *((_DWORD *)v135 + 19);
          *((_DWORD *)v135 + 19) = a1[704];
          if ( v140 == 1
            && (*((_BYTE *)a1 + 1849) != 1 || (a3[4] & 1) == 0)
            && (*((_BYTE *)a1 + 1851) != 1 || *((_BYTE *)a3 + 32) == 1) )
          {
            v142 = *((_DWORD *)v135 + 20);
            v143 = (v142 << 8) | 0x30;
            v144 = v142 << 8;
            *((_DWORD *)v135 + 19) = v143;
            if ( *((_BYTE *)a3 + 32) == 1 )
            {
              if ( *((_BYTE *)a1 + 1850) == 1 )
                v144 = a1[460];
              else
                v143 = 55;
            }
            else if ( *((_BYTE *)a1 + 1852) == 1 )
            {
              v144 = a1[461];
            }
            else
            {
              v143 = 54;
            }
            v145 = v144 | v143;
            *((_DWORD *)v135 + 19) = v145;
            if ( *((_BYTE *)a1 + 1853) == 1 && v141 != v145 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                3,
                "cam_sfe_bus_rd_update_rm",
                1607,
                "SFE:%d RM:%d current_scid:%d cache_cfg:0x%x",
                **v135,
                *((_DWORD *)v135 + 6),
                v142,
                v145);
          }
          v146 = (_DWORD *)(v172 + 4 * v128);
          *v146 = v135[1][7];
          v147 = *((_DWORD *)v135 + 19);
          v146[1] = v147;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_rd_update_rm",
              1619,
              "SFE:%d RM:%d cache_cfg:0x%x",
              **v135,
              *((_DWORD *)v135 + 6),
              v147);
          v148 = v175;
          v146[2] = v135[1][2];
          v146[3] = v148;
          v146[4] = v135[1][3];
          v146[5] = v133;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_rd_update_rm",
              1630,
              "SFE:%d RM:%d width:%d [in bytes: %d] height:%d",
              **v135,
              *((_DWORD *)v135 + 6),
              *((_DWORD *)v135 + 10),
              v148,
              *((_DWORD *)v135 + 11));
          v149 = v135[1];
          *((_DWORD *)v135 + 12) = v136;
          v146[6] = v149[4];
          v150 = *((_DWORD *)v135 + 12);
          v146[7] = v150;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_rd_update_rm",
              1638,
              "SFE:%d RM:%d image_stride:%d",
              **v135,
              *((_DWORD *)v135 + 6),
              v150);
          v126 = v128 + 10;
          v146[8] = v135[1][1];
          v146[9] = v137;
          if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
          {
            v151 = (_DWORD *)(v172 + 4LL * v126);
            v126 = v128 + 12;
            *v151 = v135[1][8];
            v151[1] = v174;
          }
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_rd_update_rm",
              1649,
              "SFE:%d RM:%d image_address:0x%x image_offset:0x%x",
              **v135,
              *((_DWORD *)v135 + 6),
              v137,
              v174);
          ++v125;
          v127 += 12;
        }
        while ( v125 < *(unsigned int *)(v170 + 24) );
        v153 = *(__int64 (__fastcall **)(_QWORD))(v168 + 24);
        if ( *((_DWORD *)v153 - 1) != 2010610996 )
          __break(0x8228u);
        v110 = 4 * v153(v126 >> 1);
        if ( v110 > *((_DWORD *)a3 + 6) )
        {
          v111 = "cam_sfe_bus_rd_update_rm";
          v112 = 1661;
          goto LABEL_154;
        }
        v113 = *(_DWORD **)(v168 + 120);
        v114 = a3[2];
        v116 = v126 >> 1;
        v115 = (_DWORD *)v172;
LABEL_163:
        if ( *(v113 - 1) != -1401492769 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _DWORD *))v113)(v114, v116, v115);
        result = 0;
        *((_DWORD *)a3 + 7) = v110;
        goto LABEL_24;
      }
      v152 = debug_mdl;
      result = 0;
      *((_DWORD *)a3 + 7) = 0;
      if ( (v152 & 0x40000000) == 0 || debug_priority )
        goto LABEL_24;
      v95 = "cam_sfe_bus_rd_update_rm";
      v96 = "No reg val pairs. num_rms: %u";
      v97 = v152 & 0x40000000;
      v98 = 4;
      v99 = 1675;
LABEL_227:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v97,
        v98,
        v95,
        v99,
        v96);
      result = 0;
      goto LABEL_24;
    }
    if ( a2 == 17 )
    {
      v72 = *((_DWORD *)a3 + 2) - 20481;
      if ( v72 < 3 )
      {
        v73 = &a1[38 * v72];
        v74 = *((_QWORD *)v73 + 294);
        if ( *(_DWORD *)(v74 + 24) )
        {
          v75 = v73 + 582;
          v76 = *(_QWORD *)(*(_QWORD *)(v74 + 32) + 24LL);
          if ( v76 )
          {
            v77 = *(_DWORD *)(v76 + 48);
            v78 = *(_DWORD *)(v76 + 40);
            v79 = *(_DWORD *)(v76 + 44);
            v80 = *(_DWORD *)(v76 + 60);
            v81 = *a1;
            v82 = v73[583];
            v83 = cam_io_r_mb(*(_QWORD *)(*(_QWORD *)v76 + 8LL) + *(unsigned int *)(*(_QWORD *)(v76 + 8) + 4LL));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              3,
              "cam_sfe_bus_rd_print_dimensions",
              399,
              "SFE: %u RD: %u res_id: 0x%x width: %d height: %d stride: %d unpacker: 0x%x addr: 0x%x",
              v81,
              0,
              v82,
              v78,
              v79,
              v77,
              v80,
              v83);
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              2,
              "cam_sfe_bus_rd_print_dimensions",
              390,
              "Unsupported SFE RD %d",
              v72);
          }
          if ( *(_DWORD *)(v74 + 24) >= 2u )
          {
            v117 = *(_QWORD *)(*(_QWORD *)(v74 + 40) + 24LL);
            if ( v117 )
            {
              v118 = *a1;
              v119 = v75[1];
              v120 = *(_DWORD *)(v117 + 48);
              v121 = *(_DWORD *)(v117 + 60);
              v122 = *(_DWORD *)(v117 + 40);
              v123 = *(_DWORD *)(v117 + 44);
              v124 = cam_io_r_mb(*(_QWORD *)(*(_QWORD *)v117 + 8LL) + *(unsigned int *)(*(_QWORD *)(v117 + 8) + 4LL));
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                3,
                "cam_sfe_bus_rd_print_dimensions",
                399,
                "SFE: %u RD: %u res_id: 0x%x width: %d height: %d stride: %d unpacker: 0x%x addr: 0x%x",
                v118,
                1,
                v119,
                v122,
                v123,
                v120,
                v121,
                v124);
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                2,
                "cam_sfe_bus_rd_print_dimensions",
                390,
                "Unsupported SFE RD %d",
                v72);
            }
            if ( *(_DWORD *)(v74 + 24) > 2u )
              goto LABEL_254;
          }
        }
        goto LABEL_223;
      }
      result = 0;
      if ( (debug_mdl & 0x40000000) == 0 || debug_priority )
        goto LABEL_24;
      v95 = "cam_sfe_bus_rd_process_cmd";
      v96 = "Not a SFE read res: 0x%x - skip dump";
      v97 = debug_mdl & 0x40000000;
      v98 = 4;
      v99 = 2061;
      goto LABEL_227;
    }
    if ( a2 == 23 )
    {
      v35 = *(_QWORD *)(*a3 + 24);
      if ( v35 )
      {
        if ( *(_DWORD *)(v35 + 24) )
        {
          v36 = (_DWORD *)a3[5];
          v37 = debug_mdl;
          v38 = *(_DWORD **)(*(_QWORD *)(v35 + 32) + 24LL);
          v39 = v36[7];
          v38[21] = v39;
          v40 = v36[4];
          v38[10] = v40;
          v41 = v36[3];
          v38[11] = v41;
          if ( (v37 & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v37 & 0x40000000,
              4,
              "cam_sfe_bus_rd_config_update",
              1946,
              "SFE: %u RM: %d offset: %u width: %u height: %u",
              v38[6],
              v38[6],
              v39,
              v40,
              v41);
          if ( *(_DWORD *)(v35 + 24) >= 2u )
          {
            v42 = debug_mdl;
            v43 = *(_DWORD **)(*(_QWORD *)(v35 + 40) + 24LL);
            v44 = v36[7];
            v43[21] = v44;
            v45 = v36[4];
            v43[10] = v45;
            v46 = v36[3];
            v43[11] = v46;
            if ( (v42 & 0x40000000) != 0 && !debug_priority )
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v42 & 0x40000000,
                4,
                "cam_sfe_bus_rd_config_update",
                1946,
                "SFE: %u RM: %d offset: %u width: %u height: %u",
                v43[6],
                v43[6],
                v44,
                v45,
                v46);
            if ( *(_DWORD *)(v35 + 24) > 2u )
              goto LABEL_254;
          }
        }
        goto LABEL_223;
      }
      v12 = "cam_sfe_bus_rd_config_update";
      v9 = "Failed! Invalid data";
      v10 = 3;
      v11 = 0x40000000;
      v13 = 1933;
LABEL_22:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v10,
        v11,
        1,
        v12,
        v13,
        v9);
LABEL_23:
      result = 4294967274LL;
      goto LABEL_24;
    }
    if ( a2 != 38 )
      goto LABEL_120;
    v15 = (int *)a3[5];
    if ( !v15 )
    {
      v12 = "cam_sfe_bus_rd_get_res_for_mid";
      v9 = "invalid get resource for mid paramas";
      v10 = 3;
      v11 = 0x40000000;
      v13 = 1780;
      goto LABEL_22;
    }
    v16 = a1[467];
    v17 = *v15;
    if ( v16 )
    {
      v18 = *((_DWORD **)a1 + 348);
      if ( v18[62] == v17 || v18[63] == v17 || v18[64] == v17 || v18[65] == v17 )
      {
        v19 = 0;
LABEL_36:
        v20 = &a1[38 * v19];
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          3,
          "cam_sfe_bus_rd_get_res_for_mid",
          1803,
          "match mid :%d  read resource: 0x%x found",
          v17,
          v20[583]);
        result = 0;
        v15[1] = v20[583];
        goto LABEL_24;
      }
      if ( v16 != 1 )
      {
        if ( v18[69] == v17 || v18[70] == v17 || v18[71] == v17 || v18[72] == v17 )
        {
          v19 = 1;
          goto LABEL_36;
        }
        if ( v16 != 2 )
        {
          if ( v18[76] == v17 || v18[77] == v17 || v18[78] == v17 || v18[79] == v17 )
          {
            v19 = 2;
            goto LABEL_36;
          }
          if ( v16 != 3 )
            goto LABEL_254;
        }
      }
    }
    v95 = "cam_sfe_bus_rd_get_res_for_mid";
    v96 = "mid:%d does not match with any read resource";
    v97 = 0x40000000;
    v98 = 3;
    v99 = 1797;
    goto LABEL_227;
  }
  if ( a2 > 64 )
  {
    if ( a2 != 65 )
    {
      if ( a2 == 77 )
      {
        v21 = *((unsigned int *)a3 + 2);
        if ( (_DWORD)v21 == 500 )
        {
          v69 = *((_QWORD *)a1 + 348);
          v70 = *(_QWORD *)(v69 + 40);
          if ( v70 )
          {
            v71 = *((_QWORD *)a1 + 4);
            cam_io_w_mb(*((unsigned int *)a3 + 3), *(_QWORD *)(v71 + 288) + *(unsigned int *)(v70 + 12));
            cam_io_w_mb(16, *(_QWORD *)(v71 + 288) + *(unsigned int *)(v69 + 48));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              3,
              "cam_sfe_bus_rd_irq_inject",
              1847,
              "Injected : irq_mask %#x set_reg_offset %#x",
              *((_DWORD *)a3 + 3),
              *(_DWORD *)(v70 + 12));
            result = 0;
            goto LABEL_24;
          }
          v12 = "cam_sfe_bus_rd_irq_inject";
          v9 = "Invalid inject_reg";
          v10 = 3;
          v11 = 8;
          v13 = 1837;
          goto LABEL_22;
        }
        v93 = "cam_sfe_bus_rd_irq_inject";
        v89 = "Invalid reg_unit %d";
        v90 = 3;
        v91 = 8;
        v92 = 2;
        v94 = 1831;
        goto LABEL_130;
      }
      if ( a2 == 78 )
      {
        v21 = *((unsigned int *)a3 + 2);
        if ( (_DWORD)v21 == 500 )
        {
          v22 = *((_QWORD *)a1 + 348);
          v23 = scnprintf(a3[4], 1500, "Printing executable IRQ for hw_type: SFE reg_unit: %d\n", 500);
          if ( !*(_DWORD *)(v22 + 328) )
            goto LABEL_223;
          v24 = v23;
          v25 = 0;
          do
          {
            v26 = *(_QWORD *)(v22 + 336) + 24LL * (int)v25;
            v27 = scnprintf(
                    a3[4] + v24,
                    1500 - v24,
                    "%#12x : %s - %s\n",
                    *(_DWORD *)v26,
                    *(const char **)(v26 + 8),
                    *(const char **)(v26 + 16));
            ++v25;
            result = 0;
            v24 += v27;
          }
          while ( v25 < *(_DWORD *)(v22 + 328) );
          goto LABEL_24;
        }
        v93 = "cam_sfe_bus_rd_dump_irq_desc";
        v89 = "Invalid reg_unit %d";
        v90 = 3;
        v91 = 8;
        v92 = 2;
        v94 = 1873;
LABEL_130:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          v90,
          v91,
          v92,
          v93,
          v94,
          v89,
          v21);
        goto LABEL_23;
      }
LABEL_120:
      v88 = __ratelimit(&cam_sfe_bus_rd_process_cmd__rs_73, "cam_sfe_bus_rd_process_cmd");
      v89 = "Invalid SFE BUS RD command type: %d";
      if ( v88 )
        v90 = 3;
      else
        v90 = 2;
      v91 = 0x40000000;
      v92 = 1;
      v93 = "cam_sfe_bus_rd_process_cmd";
      v94 = 2079;
      v21 = (unsigned int)a2;
      goto LABEL_130;
    }
    v85 = *(_QWORD *)(*a3 + 24);
    if ( v85 )
    {
      if ( *(_BYTE *)a3[5] == 1 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(v85 + 8) + 1860LL) )
          v86 = 5;
        else
          v86 = 1;
      }
      else
      {
        v86 = 0;
      }
      v102 = *(_QWORD *)(v85 + 64);
      if ( v102 )
      {
        if ( *(_DWORD *)(v85 + 24) )
        {
          v103 = *(_DWORD **)(v85 + 8);
          v104 = *(_QWORD *)(*(_QWORD *)(v85 + 32) + 24LL);
          v105 = *(_DWORD **)(v104 + 8);
          *(_BYTE *)(v104 + 89) = 1;
          v103[10] = *v105;
          v103[11] = v86;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_rd_update_rm_core_cfg",
              1736,
              "SFE:%d RM:%d cfg:0x%x",
              **(_DWORD **)v104,
              *(_DWORD *)(v104 + 24),
              v86);
          v106 = 1;
          if ( *(_DWORD *)(v85 + 24) >= 2u )
          {
            v107 = *(_QWORD *)(*(_QWORD *)(v85 + 40) + 24LL);
            v108 = *(_DWORD **)(v107 + 8);
            *(_BYTE *)(v107 + 89) = 1;
            v103[12] = *v108;
            v103[13] = v86;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_bus_rd_update_rm_core_cfg",
                1736,
                "SFE:%d RM:%d cfg:0x%x",
                **(_DWORD **)v107,
                *(_DWORD *)(v107 + 24),
                v86);
            if ( *(_DWORD *)(v85 + 24) > 2u )
              goto LABEL_254;
            v106 = 2;
          }
          v109 = *(__int64 (__fastcall **)(_QWORD))(v102 + 24);
          if ( *((_DWORD *)v109 - 1) != 2010610996 )
            __break(0x8228u);
          v110 = 4 * v109(v106);
          if ( v110 > *((_DWORD *)a3 + 6) )
          {
            v111 = "cam_sfe_bus_rd_update_rm_core_cfg";
            v112 = 1748;
LABEL_154:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x40000000,
              1,
              v111,
              v112,
              "Failed! Buf size:%d insufficient, expected size:%d");
            result = 4294967284LL;
            goto LABEL_24;
          }
          v113 = *(_DWORD **)(v102 + 120);
          v114 = a3[2];
          v115 = v103 + 10;
          v116 = v106;
          goto LABEL_163;
        }
        result = 0;
        *((_DWORD *)a3 + 7) = 0;
        if ( (debug_mdl & 0x40000000) == 0 || debug_priority )
          goto LABEL_24;
        v95 = "cam_sfe_bus_rd_update_rm_core_cfg";
        v96 = "No reg val pairs. num_rms: %u";
        v97 = debug_mdl & 0x40000000;
        v98 = 4;
        v99 = 1762;
        goto LABEL_227;
      }
      v100 = "Invalid cdm ops: %pK";
      v101 = 1714;
    }
    else
    {
      v100 = "Invalid SFE rd data: %pK";
      v101 = 1701;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_rd_update_rm_core_cfg",
      v101,
      v100,
      0);
    goto LABEL_23;
  }
  if ( a2 != 43 )
  {
    if ( a2 != 57 )
    {
      if ( a2 == 63 )
      {
        v5 = *(_QWORD *)(a3[1] + 24);
        if ( v5 )
        {
          if ( (a1[462] & 1) == 0 && *(_DWORD *)(v5 + 24) )
          {
            v6 = *(_QWORD *)(*(_QWORD *)(v5 + 32) + 24LL);
            *(_BYTE *)(v6 + 88) = *((_BYTE *)a3 + 16);
            *(_DWORD *)(v6 + 80) = *((_DWORD *)a3 + 5);
            *((_BYTE *)a3 + 1) = 1;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              v156 = *(int **)v6;
              v157 = *(unsigned __int8 *)(v6 + 88);
              v158 = *(_DWORD *)(v6 + 24);
              v159 = *(_DWORD *)(v6 + 80);
              v160 = *v156;
              v161 = "true";
              if ( !v157 )
                v161 = "false";
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_bus_rd_cache_config",
                1986,
                "SFE:%d RM:%d cache_enable:%s scid:%u",
                v160,
                v158,
                v161,
                v159);
            }
            if ( *(_DWORD *)(v5 + 24) >= 2u )
            {
              v7 = *(_QWORD *)(*(_QWORD *)(v5 + 40) + 24LL);
              *(_BYTE *)(v7 + 88) = *((_BYTE *)a3 + 16);
              *(_DWORD *)(v7 + 80) = *((_DWORD *)a3 + 5);
              *((_BYTE *)a3 + 1) = 1;
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              {
                v162 = *(int **)v7;
                v163 = *(unsigned __int8 *)(v7 + 88);
                v164 = *(_DWORD *)(v7 + 24);
                v165 = *(_DWORD *)(v7 + 80);
                v166 = *v162;
                v167 = "true";
                if ( !v163 )
                  v167 = "false";
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_bus_rd_cache_config",
                  1986,
                  "SFE:%d RM:%d cache_enable:%s scid:%u",
                  v166,
                  v164,
                  v167,
                  v165);
              }
              if ( *(_DWORD *)(v5 + 24) > 2u )
                goto LABEL_254;
            }
          }
          goto LABEL_223;
        }
        v12 = "cam_sfe_bus_rd_cache_config";
        v9 = "Invalid data";
        v10 = 3;
        v11 = 0x40000000;
        v13 = 1968;
        goto LABEL_22;
      }
      goto LABEL_120;
    }
    v47 = *a3;
    v175 = 0;
    v171 = *(_QWORD *)(v47 + 24);
    if ( v171 )
    {
      v48 = &unk_393000;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      {
        if ( *((_BYTE *)a3 + 32) )
          v154 = "true";
        else
          v154 = "false";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_bus_rd_config_rm",
          1390,
          "num of RM: %d scratch_buf_cfg: %s",
          *(unsigned int *)(v171 + 24),
          v154);
      }
      v49 = *(_DWORD *)(a3[5] + 20);
      v50 = *(_DWORD *)(v171 + 24);
      if ( v49 != v50 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_rd_config_rm",
          1395,
          "Failed! Invalid number buffers:%d required:%d",
          v49,
          v50);
        goto LABEL_23;
      }
      if ( v49 )
      {
        v51 = 0;
        v52 = 0;
        while ( v51 != 2 )
        {
          v53 = *(_DWORD ***)(*(_QWORD *)(v171 + 32 + 8 * v51) + 24LL);
          v54 = a3[5];
          v55 = *((_DWORD *)v53 + 10);
          if ( !v55 || (v56 = *((_DWORD *)v53 + 11)) == 0 )
          {
            v55 = *(_DWORD *)(v54 + 40);
            v56 = *(_DWORD *)(v54 + 44);
          }
          v57 = *(_DWORD *)(v54 + 48);
          v58 = *(_QWORD *)(*(_QWORD *)v54 + 8 * v51) + *((unsigned int *)v53 + 21);
          v59 = cam_smmu_is_expanded_memory();
          if ( (v59 & 1) != 0 )
            v52 = (unsigned __int8)v58;
          v173 = v52;
          if ( (v59 & 1) != 0 )
            v60 = v58 >> 8;
          else
            v60 = v58;
          cam_sfe_bus_rd_pxls_to_bytes(v55, *((unsigned int *)v53 + 15), &v175);
          *((_DWORD *)v53 + 10) = v55;
          *((_DWORD *)v53 + 11) = v56;
          v61 = *((_DWORD *)v53 + 19);
          v62 = (unsigned int)a1[704];
          *((_DWORD *)v53 + 19) = v62;
          if ( (*((_BYTE *)a1 + 1849) & 1) == 0 && *((_BYTE *)v53 + 88) == 1 )
          {
            v63 = *((_DWORD *)v53 + 20);
            v64 = (v63 << 8) | 0x30;
            *((_DWORD *)v53 + 19) = v64;
            v62 = *((_BYTE *)a1 + 1850) == 1 ? a1[460] | (unsigned int)v64 : (v63 << 8) | 0x37u;
            *((_DWORD *)v53 + 19) = v62;
            if ( *((_BYTE *)a1 + 1853) == 1 && v61 != (_DWORD)v62 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                3,
                "cam_sfe_bus_rd_config_rm",
                1442,
                "SFE:%d Scratch Buff RM:%d current_scid:%d cache_cfg:0x%x",
                **v53,
                *((_DWORD *)v53 + 6),
                v63,
                v62);
              v62 = *((unsigned int *)v53 + 19);
            }
          }
          cam_io_w_mb(v62, *((_QWORD *)*v53 + 1) + (unsigned int)v53[1][7]);
          v65 = v48;
          if ( (v48[458] & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v48[458] & 0x40000000LL,
              4,
              "cam_sfe_bus_rd_config_rm",
              1451,
              "SFE:%d RM:%d cache_cfg:0x%x",
              **v53,
              *((_DWORD *)v53 + 6),
              *((_DWORD *)v53 + 19));
          v66 = v175;
          cam_io_w_mb(v175, *((_QWORD *)*v53 + 1) + (unsigned int)v53[1][2]);
          cam_io_w_mb(v56, *((_QWORD *)*v53 + 1) + (unsigned int)v53[1][3]);
          if ( (v65[458] & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v65[458] & 0x40000000LL,
              4,
              "cam_sfe_bus_rd_config_rm",
              1462,
              "SFE:%d RM:%d width:%d [in bytes: %d] height:%d",
              **v53,
              *((_DWORD *)v53 + 6),
              v55,
              v66,
              v56);
          v67 = *v53;
          v68 = v53[1];
          *((_DWORD *)v53 + 12) = v57;
          cam_io_w_mb(v57, *((_QWORD *)v67 + 1) + (unsigned int)v68[4]);
          v48 = v65;
          if ( (v65[458] & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v65[458] & 0x40000000LL,
              4,
              "cam_sfe_bus_rd_config_rm",
              1470,
              "SFE:%d RM:%d image_stride:%d",
              **v53,
              *((_DWORD *)v53 + 6),
              v57);
          cam_io_w_mb(v60, *((_QWORD *)*v53 + 1) + (unsigned int)v53[1][1]);
          if ( (v65[458] & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v65[458] & 0x40000000LL,
              4,
              "cam_sfe_bus_rd_config_rm",
              1479,
              "SFE:%d RM:%d image_address:0x%x offset: 0x%x",
              **v53,
              *((_DWORD *)v53 + 6),
              v60,
              *((_DWORD *)v53 + 21));
          v52 = v173;
          if ( (cam_smmu_is_expanded_memory() & 1) != 0 && (v65[458] & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v65[458] & 0x40000000LL,
              4,
              "cam_sfe_bus_rd_config_rm",
              1484,
              "SFE:%d RM:%d image address offset: 0x%x",
              **v53,
              *((_DWORD *)v53 + 6),
              v173);
          cam_io_w_mb(v173, *((_QWORD *)*v53 + 1) + (unsigned int)v53[1][8]);
          if ( ++v51 >= (unsigned __int64)*(unsigned int *)(v171 + 24) )
            goto LABEL_223;
        }
LABEL_254:
        __break(0x5512u);
      }
LABEL_223:
      result = 0;
      goto LABEL_24;
    }
    v12 = "cam_sfe_bus_rd_config_rm";
    v9 = "Invalid data";
    v10 = 3;
    v11 = 0x40000000;
    v13 = 1384;
    goto LABEL_22;
  }
  v84 = *(_DWORD *)a3;
  if ( *((_BYTE *)a3 + 76) == 1 )
  {
    cam_sfe_bus_parse_cache_cfg(1, v84, (__int64)(a1 + 460));
    result = 0;
  }
  else
  {
    result = 0;
    a1[458] = v84;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
