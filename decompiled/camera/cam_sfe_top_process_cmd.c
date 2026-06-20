__int64 __fastcall cam_sfe_top_process_cmd(__int64 result, int a2, __int64 *a3, unsigned int a4)
{
  _DWORD *v4; // x10
  int v5; // w11
  const char *v6; // x21
  _BYTE *v7; // x24
  __int64 *v8; // x25
  unsigned int *v9; // x26
  _DWORD *v10; // x27
  const char *v11; // x22
  const char *v12; // x19
  __int64 v13; // x23
  __int64 v14; // x6
  __int64 v15; // x8
  __int64 v16; // x8
  int v17; // w9
  __int64 v19; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  int v21; // w8
  const char *v22; // x3
  const char *v23; // x5
  __int64 v24; // x1
  __int64 v25; // x4
  int *v26; // x25
  int *v27; // x8
  __int64 v28; // x9
  int v29; // w7
  unsigned int v30; // w8
  int v31; // w9
  __int64 v32; // x8
  __int64 v33; // x8
  unsigned int v34; // w8
  __int64 v35; // x20
  __int64 (*v36)(void); // x8
  int v38; // w0
  unsigned int v39; // w6
  int v40; // w21
  __int64 v41; // x8
  _DWORD *v42; // x8
  unsigned int v43; // w20
  const char *v44; // x8
  const char *v45; // x9
  __int64 v46; // x11
  __int64 v47; // x8
  const char *v48; // x12
  unsigned int v49; // w21
  __int64 v50; // x25
  unsigned int v51; // w26
  bool v52; // cc
  const char *v53; // x3
  const char *v54; // x5
  __int64 v55; // x4
  __int64 v56; // x8
  __int64 v57; // x20
  unsigned int v59; // w0
  __int64 v60; // x6
  const char *v61; // x5
  unsigned int v62; // w19
  __int64 v63; // x4
  __int64 v64; // x8
  _DWORD *v65; // x8
  _DWORD *v66; // x10
  __int64 v67; // x1
  int v68; // w9
  __int64 *v69; // x8
  int v70; // w11
  void (__fastcall *v71)(__int64, __int64); // x9
  __int64 v72; // x0
  __int64 *v73; // x19
  unsigned int v74; // w0
  unsigned int *v75; // x21
  int v76; // w8
  int v77; // w8
  int v78; // w9
  unsigned __int64 v79; // x22
  unsigned int v80; // w0
  __int64 v81; // x6
  unsigned int v82; // w8
  const char *v83; // x8
  _DWORD *v84; // x19
  __int64 v85; // x0
  __int64 *v86; // x16
  __int64 v87; // x21
  unsigned int v88; // w0
  __int64 v89; // x6
  unsigned int v90; // w8
  const char *v91; // x8
  unsigned __int64 v92; // x22
  unsigned int v93; // w0
  unsigned int v94; // w21
  unsigned int v95; // w8
  const char *v96; // x8
  const char *v97; // x9
  const char *v98; // x7
  __int64 v99; // x22
  unsigned int v100; // w0
  unsigned int v101; // w26
  unsigned int v102; // w8
  const char *v103; // x8
  const char *v104; // x9
  const char *v105; // x7
  const char *v106; // x8
  unsigned int v107; // w9
  const char *v108; // x9
  unsigned int v109; // w9
  const char *v110; // x9
  const char *v111; // x10
  __int64 v112; // x4
  const char *v113; // x10
  __int64 v114; // x4
  unsigned int v115; // w0
  unsigned int v116; // w8
  unsigned int v117; // w0
  unsigned int v118; // w8
  unsigned int v119; // w10
  const char *v120; // x9
  const char *v121; // x10
  unsigned int v122; // w9
  const char *v123; // x9
  const char *v124; // x10
  unsigned int v125; // w9
  unsigned int v126; // w9
  unsigned int v127; // w7
  __int64 v128; // x13
  _DWORD *v129; // x14
  unsigned int v130; // w8
  unsigned int v131; // w8
  int v132; // w1
  unsigned int v133; // w6
  unsigned int v134; // w8
  signed int v135; // w8
  int v136; // w1
  unsigned int v137; // w6
  unsigned int v138; // w8
  signed int v139; // w8
  int v140; // w17
  unsigned int v141; // w15
  unsigned int v142; // w8
  int v143; // w16
  __int64 v144; // x1
  const char *v145; // x3
  int v146; // w12
  __int64 v147; // x4
  int v148; // w1
  unsigned int v149; // w6
  unsigned int v150; // w8
  signed int v151; // w8
  int v152; // w17
  unsigned int v153; // w8
  int v154; // w1
  unsigned int v155; // w6
  unsigned int v156; // w8
  signed int v157; // w8
  const char *v158; // x5
  __int64 v159; // x4
  int v160; // w8
  int v161; // w8
  unsigned int v162; // w19
  unsigned int v163; // w19
  unsigned int (__fastcall *v164)(_QWORD); // x8
  _DWORD *v165; // x8
  __int64 v166; // x0
  __int64 v167; // x4
  unsigned int v168; // w19
  unsigned int v169; // w8
  const char *v170; // x8
  unsigned int v171; // w9
  const char *v172; // x9
  const char *v173; // x10
  __int64 v174; // [xsp+20h] [xbp-50h]
  __int64 v175; // [xsp+20h] [xbp-50h]
  __int64 v176; // [xsp+20h] [xbp-50h]
  __int64 v177; // [xsp+20h] [xbp-50h]
  __int64 v178; // [xsp+20h] [xbp-50h]
  _DWORD *v179; // [xsp+28h] [xbp-48h]
  __int64 v180; // [xsp+28h] [xbp-48h]
  _DWORD *v181; // [xsp+28h] [xbp-48h]
  __int64 v182; // [xsp+28h] [xbp-48h]
  _DWORD *v183; // [xsp+28h] [xbp-48h]
  _DWORD *v184; // [xsp+28h] [xbp-48h]
  _DWORD *v185; // [xsp+28h] [xbp-48h]
  int v186; // [xsp+34h] [xbp-3Ch]
  int v187; // [xsp+34h] [xbp-3Ch]
  int v188; // [xsp+34h] [xbp-3Ch]
  int v189; // [xsp+34h] [xbp-3Ch]
  int v190; // [xsp+34h] [xbp-3Ch]
  int v191; // [xsp+34h] [xbp-3Ch]
  int v192; // [xsp+34h] [xbp-3Ch]
  int v193; // [xsp+34h] [xbp-3Ch]
  int v194; // [xsp+34h] [xbp-3Ch]
  int v195; // [xsp+34h] [xbp-3Ch]
  _DWORD *v196; // [xsp+38h] [xbp-38h]
  _DWORD *v197; // [xsp+38h] [xbp-38h]
  _DWORD *v198; // [xsp+38h] [xbp-38h]
  _DWORD *v199; // [xsp+38h] [xbp-38h]
  _DWORD *v200; // [xsp+38h] [xbp-38h]
  _DWORD *v201; // [xsp+38h] [xbp-38h]
  _DWORD *v202; // [xsp+38h] [xbp-38h]
  _DWORD *v203; // [xsp+38h] [xbp-38h]
  _DWORD *v204; // [xsp+38h] [xbp-38h]
  _DWORD *v205; // [xsp+38h] [xbp-38h]
  int v206; // [xsp+40h] [xbp-30h]
  int v207; // [xsp+40h] [xbp-30h]
  int v208; // [xsp+40h] [xbp-30h]
  int v209; // [xsp+40h] [xbp-30h]
  int v210; // [xsp+40h] [xbp-30h]
  int v211; // [xsp+40h] [xbp-30h]
  int v212; // [xsp+40h] [xbp-30h]
  int v213; // [xsp+40h] [xbp-30h]
  int v214; // [xsp+40h] [xbp-30h]
  int v215; // [xsp+40h] [xbp-30h]
  int v216; // [xsp+44h] [xbp-2Ch]
  int v217; // [xsp+44h] [xbp-2Ch]
  unsigned int v218; // [xsp+44h] [xbp-2Ch]
  unsigned int v219; // [xsp+44h] [xbp-2Ch]
  unsigned int v220; // [xsp+44h] [xbp-2Ch]
  unsigned int v221; // [xsp+44h] [xbp-2Ch]
  unsigned int v222; // [xsp+44h] [xbp-2Ch]
  unsigned int v223; // [xsp+44h] [xbp-2Ch]
  unsigned int v224; // [xsp+44h] [xbp-2Ch]
  unsigned int v225; // [xsp+44h] [xbp-2Ch]
  _QWORD *v226; // [xsp+48h] [xbp-28h]
  unsigned __int64 v227; // [xsp+50h] [xbp-20h] BYREF
  __int64 v228; // [xsp+58h] [xbp-18h] BYREF
  unsigned int *v229[2]; // [xsp+60h] [xbp-10h] BYREF

  v229[1] = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
  {
    v22 = "cam_sfe_top_process_cmd";
    v23 = "Invalid top_priv";
    v24 = 0x40000000;
    v25 = 1429;
    goto LABEL_22;
  }
  v11 = *(const char **)result;
  v12 = (const char *)result;
  v13 = *(_QWORD *)(*(_QWORD *)result + 3296LL);
  if ( !v13 )
  {
    v22 = "cam_sfe_top_process_cmd";
    v23 = "soc private is NULL";
    v24 = 0x40000000;
    v25 = 1438;
    goto LABEL_22;
  }
  v14 = a4;
  if ( a2 > 24 )
  {
    v13 = result + 31576;
    if ( a2 <= 43 )
    {
      if ( a2 == 25 )
      {
        if ( a3 && a4 == 48 )
        {
          result = 0;
          *((_DWORD *)v12 + 8054) = *((_DWORD *)a3 + 3);
          *((_DWORD *)v12 + 8056) = *((_DWORD *)a3 + 5);
          *((_DWORD *)v12 + 8055) = *((_DWORD *)a3 + 4);
          goto LABEL_24;
        }
        v22 = "cam_sfe_top_core_cfg";
        v23 = "Invalid inputs";
        v24 = 0x40000000;
        v25 = 660;
        goto LABEL_22;
      }
      if ( a2 != 43 )
        goto LABEL_85;
      if ( (*((_BYTE *)a3 + 76) & 1) == 0 )
      {
        result = 0;
        v34 = *(_DWORD *)(*((_QWORD *)v12 + 2) + 84LL);
        *((_DWORD *)v12 + 8057) = *(_DWORD *)a3;
        *((_DWORD *)v12 + 8058) = *((_DWORD *)a3 + 1);
        if ( !v34 || *((_DWORD *)a3 + 2) > v34 )
          goto LABEL_24;
        *((_DWORD *)v12 + 8059) = *((_DWORD *)a3 + 3);
        if ( v34 != 1 )
        {
          v31 = *((_DWORD *)a3 + 4);
          *((_DWORD *)v12 + 8061) = v31;
          if ( v34 != 2 )
            goto LABEL_256;
        }
      }
      goto LABEL_137;
    }
    if ( a2 == 44 )
    {
      *((_DWORD *)a3 + 1) = *(_DWORD *)(*(_QWORD *)(result + 16) + 84LL);
      v41 = *(_QWORD *)(*(_QWORD *)(result + 32296) + 8LL);
      if ( *(_BYTE *)(v41 + 40) == 1 )
      {
        v42 = *(_DWORD **)(v41 + 32);
        *((_BYTE *)a3 + 28) = 1;
        result = 0;
        *((_DWORD *)a3 + 4) = *v42;
        *((_DWORD *)a3 + 5) = v42[1];
        goto LABEL_24;
      }
      goto LABEL_137;
    }
    if ( a2 == 58 )
    {
      v7 = a3;
      v43 = cam_io_r(*((_QWORD *)v11 + 36) + *(unsigned int *)(*(_QWORD *)(result + 16) + 80LL));
      result = cam_io_r(*((_QWORD *)v11 + 36) + *(unsigned int *)(*((_QWORD *)v12 + 2) + 24LL));
      v14 = *((unsigned int *)v11 + 5);
      if ( (unsigned int)v14 < 3 )
      {
        v44 = &v11[16 * v14];
        v45 = "Y";
        v46 = *((_QWORD *)v44 + 351);
        v47 = *((_QWORD *)v44 + 352);
        if ( v43 )
          v48 = "Y";
        else
          v48 = "N";
        v49 = result;
        if ( !(_DWORD)result )
          v45 = "N";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_sfe_top_handle_overflow",
          900,
          "SFE%d src_clk_rate sw_client:%lu hw_client:[%lu %lu] bus_overflow_status:%s violation: %s",
          v14,
          *((_QWORD *)v11 + 350),
          v46,
          v47,
          v48,
          v45);
        if ( v43 )
        {
          v50 = 8;
          v51 = v43;
          do
          {
            if ( (v51 & 1) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_sfe_top_handle_overflow",
                906,
                "SFE Bus Overflow %s ",
                *(const char **)(*((_QWORD *)v12 + 4036) + v50));
            v52 = v51 > 1;
            v50 += 16;
            v51 >>= 1;
          }
          while ( v52 );
        }
        if ( v49 )
        {
          v56 = *(_QWORD *)(*((_QWORD *)v12 + 4037) + 24LL);
          if ( v56 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_top_print_ipp_violation_info",
              1805,
              "SFE[%u] IPP Violation Module id: [%u %s]",
              *(_DWORD *)(*(_QWORD *)v12 + 20LL),
              *(_DWORD *)(v56 + 16LL * v49),
              *(const char **)(v56 + 16LL * v49 + 8));
        }
        cam_sfe_top_print_debug_reg_info(v12);
        result = 0;
        if ( v43 )
        {
          cam_cpas_log_votes(0);
          result = 0;
          v7[4] = 1;
        }
        goto LABEL_24;
      }
      goto LABEL_256;
    }
    if ( a2 != 66 )
      goto LABEL_85;
    v228 = 0;
    v229[0] = nullptr;
    v227 = 0;
    if ( a4 != 24 )
    {
      v53 = "cam_sfe_top_apply_clk_bw_update";
      v54 = "Invalid arg size: %u";
      v55 = 936;
      goto LABEL_96;
    }
    v26 = (int *)*a3;
    if ( !*a3 )
    {
      v22 = "cam_sfe_top_apply_clk_bw_update";
      v23 = "Invalid hw_intf";
      v24 = 0x40000000;
      v25 = 944;
      goto LABEL_22;
    }
    if ( *(_DWORD *)(*((_QWORD *)v26 + 14) + 92LL) != 1 )
    {
      result = 0;
      if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 0x2000008,
          4,
          "cam_sfe_top_apply_clk_bw_update",
          952,
          "SFE:%d Not ready to set clocks yet :%d",
          (unsigned int)v26[1]);
        goto LABEL_218;
      }
      goto LABEL_103;
    }
    if ( *((_BYTE *)a3 + 16) == 1 )
    {
      *(_BYTE *)(result + 32320) = 1;
      result = 0;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_top_apply_clk_bw_update",
          959,
          "SFE:%u requested to avoid clk data rst",
          v26[1]);
        result = 0;
      }
      goto LABEL_24;
    }
    v57 = a3[1];
    v59 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, __int64))cam_sfe_top_calc_hw_clk_rate)(
            result,
            0,
            &v228,
            v57);
    if ( v59 )
    {
      v60 = (unsigned int)v26[1];
      v61 = "SFE:%d Failed in calculating clock rate rc=%d";
      v62 = v59;
      v63 = 967;
LABEL_130:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_clk_bw_update",
        v63,
        v61,
        v60,
        v62);
LABEL_131:
      result = v62;
      *(_QWORD *)v13 = 0;
      goto LABEL_24;
    }
    v74 = cam_sfe_top_calc_axi_bw_vote((__int64)v12, 0, v229, &v227, v57);
    if ( v74 )
    {
      v60 = (unsigned int)v26[1];
      v61 = "SFE:%d Failed in calculating bw vote rc=%d";
      v62 = v74;
      v63 = 975;
      goto LABEL_130;
    }
    v75 = v229[0];
    if ( v229[0] || (v76 = *((_DWORD *)v12 + 7895), v76 == 1) )
    {
      if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      {
        v169 = *(_DWORD *)v13 - 1;
        if ( v169 > 2 )
          v170 = "Invalid State";
        else
          v170 = off_44E3E8[v169];
        v171 = *((_DWORD *)v12 + 7895) - 1;
        if ( v171 > 2 )
          v172 = "Invalid State";
        else
          v172 = off_44E3E8[v171];
        v173 = "Y";
        if ( !*((_BYTE *)a3 + 17) )
          v173 = "N";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, const char *, const char *, const char *))cam_print_log)(
          3,
          debug_mdl & 0x2000008,
          4,
          "cam_sfe_top_apply_clk_bw_update",
          991,
          "SFE:%d APPLY CLK/BW req_id:%ld clk_state:%s bw_state:%s is_drv_config_en:%s",
          (unsigned int)v26[1],
          v57,
          v170,
          v172,
          v173);
      }
      v78 = *(_DWORD *)v13;
      v77 = *((_DWORD *)v12 + 7895);
      if ( *(_DWORD *)v13 == 1 )
      {
        if ( v77 == 1 )
        {
LABEL_218:
          result = 0;
          *(_QWORD *)v13 = 0;
          goto LABEL_24;
        }
        v79 = v227;
        v80 = cam_sfe_top_set_axi_bw_vote(v12, v75, v227, 0, v57);
        if ( v80 )
        {
          v81 = (unsigned int)v26[1];
          v62 = v80;
          v82 = *(_DWORD *)v13 - 1;
          if ( v82 > 2 )
            v83 = "Invalid State";
          else
            v83 = off_44E3E8[v82];
          v107 = *(_DWORD *)(v13 + 4) - 1;
          if ( v107 > 2 )
            v108 = "Invalid State";
          else
            v108 = off_44E3E8[v107];
          v111 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v111 = "N";
          v112 = 1006;
LABEL_205:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_apply_clk_bw_update",
            v112,
            "SFE:%d Failed in voting final bw:%llu clk_state:%s bw_state:%s is_drv_config_en:%s",
            v81,
            v79,
            v83,
            v108,
            v111);
          goto LABEL_131;
        }
        goto LABEL_217;
      }
      if ( v77 == 1 )
      {
        v87 = v228;
        v88 = cam_sfe_top_set_hw_clk_rate(v12, v228, 0, v57);
        if ( v88 )
        {
          v89 = (unsigned int)v26[1];
          v62 = v88;
          v90 = *(_DWORD *)v13 - 1;
          if ( v90 > 2 )
            v91 = "Invalid State";
          else
            v91 = off_44E3E8[v90];
          v109 = *(_DWORD *)(v13 + 4) - 1;
          if ( v109 > 2 )
            v110 = "Invalid State";
          else
            v110 = off_44E3E8[v109];
          v113 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v113 = "N";
          v114 = 1018;
LABEL_210:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_apply_clk_bw_update",
            v114,
            "SFE:%d Failed in voting final clk:%lu clk_state:%s bw_state:%s is_drv_config_en:%s",
            v89,
            v87,
            v91,
            v110,
            v113);
          goto LABEL_131;
        }
        goto LABEL_217;
      }
      if ( v78 == 3 )
      {
        v99 = v228;
        v100 = cam_sfe_top_set_hw_clk_rate(v12, v228, 0, v57);
        if ( v100 )
        {
          v101 = v100;
          v102 = *(_DWORD *)v13 - 1;
          if ( v102 > 2 )
            v103 = "Invalid State";
          else
            v103 = off_44E3E8[v102];
          v122 = *((_DWORD *)v12 + 7895) - 1;
          if ( v122 > 2 )
            v123 = "Invalid State";
          else
            v123 = off_44E3E8[v122];
          v124 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v124 = "N";
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_apply_clk_bw_update",
            1056,
            "SFE:%d Failed in voting final clk:%lu clk_state:%s bw_state:%s is_drv_config_en:%s",
            (unsigned int)v26[1],
            v99,
            v103,
            v123,
            v124);
          result = v101;
          *(_QWORD *)v13 = 0;
          goto LABEL_24;
        }
        v79 = v227;
        v117 = cam_sfe_top_set_axi_bw_vote(v12, v75, v227, 0, v57);
        if ( v117 )
        {
          v81 = (unsigned int)v26[1];
          v62 = v117;
          v118 = *(_DWORD *)v13 - 1;
          if ( v118 > 2 )
            v83 = "Invalid State";
          else
            v83 = off_44E3E8[v118];
          v126 = *(_DWORD *)(v13 + 4) - 1;
          if ( v126 > 2 )
            v108 = "Invalid State";
          else
            v108 = off_44E3E8[v126];
          v111 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v111 = "N";
          v112 = 1068;
          goto LABEL_205;
        }
        goto LABEL_217;
      }
      if ( v78 == 2 )
      {
        v92 = v227;
        v93 = cam_sfe_top_set_axi_bw_vote(v12, v75, v227, 0, v57);
        if ( v93 )
        {
          v94 = v93;
          v95 = *(_DWORD *)v13 - 1;
          if ( v95 > 2 )
            v96 = "Invalid State";
          else
            v96 = off_44E3E8[v95];
          v119 = *((_DWORD *)v12 + 7895) - 1;
          if ( v119 > 2 )
            v120 = "Invalid State";
          else
            v120 = off_44E3E8[v119];
          v121 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v121 = "N";
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_top_apply_clk_bw_update",
            1031,
            "SFE:%d Failed in voting final bw:%llu clk_state:%s bw_state:%s is_drv_config_en:%s",
            (unsigned int)v26[1],
            v92,
            v96,
            v120,
            v121);
          result = v94;
          *(_QWORD *)v13 = 0;
          goto LABEL_24;
        }
        v87 = v228;
        v115 = cam_sfe_top_set_hw_clk_rate(v12, v228, 0, v57);
        if ( v115 )
        {
          v89 = (unsigned int)v26[1];
          v62 = v115;
          v116 = *(_DWORD *)v13 - 1;
          if ( v116 > 2 )
            v91 = "Invalid State";
          else
            v91 = off_44E3E8[v116];
          v125 = *(_DWORD *)(v13 + 4) - 1;
          if ( v125 > 2 )
            v110 = "Invalid State";
          else
            v110 = off_44E3E8[v125];
          v113 = "Y";
          if ( !*((_BYTE *)a3 + 17) )
            v113 = "N";
          v114 = 1043;
          goto LABEL_210;
        }
LABEL_217:
        if ( *(_DWORD *)v13 == 1 )
          goto LABEL_218;
        result = 0;
        *((_BYTE *)a3 + 18) = 1;
LABEL_103:
        *(_QWORD *)v13 = 0;
        goto LABEL_24;
      }
      v104 = "INCREASE";
      if ( v77 != 2 )
        v104 = "Invalid State";
      if ( v77 == 3 )
        v105 = "DECREASE";
      else
        v105 = v104;
      v106 = "Y";
      if ( !*((_BYTE *)a3 + 17) )
        v106 = "N";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_clk_bw_update",
        1076,
        "Invalid state to apply CLK/BW clk_state:%s bw_state:%s is_drv_config_en:%s",
        "Invalid State",
        v105,
        v106);
    }
    else
    {
      v97 = "Invalid State";
      if ( v76 == 2 )
        v97 = "INCREASE";
      if ( v76 == 3 )
        v98 = "DECREASE";
      else
        v98 = v97;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_sfe_top_apply_clk_bw_update",
        981,
        "SFE:%d Invalid BW vote for state:%s",
        v26[1],
        v98);
    }
    result = 4294967274LL;
    *(_QWORD *)v13 = 0;
    goto LABEL_24;
  }
  if ( a2 <= 10 )
  {
    if ( !a2 )
    {
      if ( a4 == 56 )
      {
        if ( a3 && v11 && *a3 )
        {
          v35 = *(_QWORD *)(*a3 + 48);
          if ( v35 )
          {
            v36 = *(__int64 (**)(void))(v35 + 56);
            if ( *((_DWORD *)v36 - 1) != -605791253 )
              __break(0x8228u);
            v38 = v36();
            v39 = *((_DWORD *)a3 + 6);
            v40 = 4 * v38;
            if ( 4 * v38 > v39 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                1,
                "cam_sfe_top_get_base",
                776,
                "buf size: %d is not sufficient, expected: %d",
                v39,
                v38);
              goto LABEL_23;
            }
            v66 = *(_DWORD **)v12;
            if ( !*(_QWORD *)v12 || !v66[120] || (v67 = (unsigned int)v66[74], (_DWORD)v67 == -1) )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                0x40000000,
                1,
                "cam_sfe_top_get_base",
                785,
                "failed to get mem_base, index: %d num_reg_map: %u",
                0);
              goto LABEL_23;
            }
            v68 = *((_DWORD *)a3 + 3);
            v69 = a3;
            if ( v68 == 10 )
            {
              v70 = *(_DWORD *)(v13 + 8);
              if ( !v70 )
              {
                v22 = "cam_sfe_top_get_base";
                v23 = "rt_wrapper_base_addr is null";
                v24 = 8;
                v25 = 791;
                goto LABEL_22;
              }
              v67 = (unsigned int)(v67 - v70);
            }
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              v168 = v67;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_top_get_base",
                799,
                "core %d mem_base 0x%x, CDM Id: %d",
                v66[5],
                v67,
                v68);
              v67 = v168;
              v69 = a3;
            }
            v71 = *(void (__fastcall **)(__int64, __int64))(v35 + 152);
            v72 = v69[2];
            v73 = v69;
            if ( *((_DWORD *)v71 - 1) != 557450195 )
              __break(0x8229u);
            v71(v72, v67);
            result = 0;
            *((_DWORD *)v73 + 7) = v40;
            goto LABEL_24;
          }
          v22 = "cam_sfe_top_get_base";
          v23 = "Invalid CDM ops";
          v24 = 0x40000000;
          v25 = 769;
        }
        else
        {
          v22 = "cam_sfe_top_get_base";
          v23 = "Invalid args";
          v24 = 0x40000000;
          v25 = 755;
        }
      }
      else
      {
        v22 = "cam_sfe_top_get_base";
        v23 = "Invalid cmd size";
        v24 = 0x40000000;
        v25 = 749;
      }
      goto LABEL_22;
    }
    if ( a2 == 9 )
    {
      if ( a4 == 24 )
      {
        if ( a3 )
        {
          if ( v11 )
          {
            v27 = (int *)*a3;
            if ( *a3 )
            {
              v28 = *((_QWORD *)v27 + 2);
              if ( !*(_QWORD *)(v28 + 112) )
              {
                v22 = "cam_sfe_top_clock_update";
                v23 = "Invalid inputs";
                v24 = 0x2000000;
                v25 = 831;
                goto LABEL_22;
              }
              v29 = *v27;
              v30 = v27[1];
              if ( v29 != 10 || v30 > 5 )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                  3,
                  0x2000000,
                  1,
                  "cam_sfe_top_clock_update",
                  841,
                  "SFE: %d Invalid res_type: %d res_id: %d",
                  *(unsigned int *)(v28 + 4));
                goto LABEL_23;
              }
              v31 = *(_DWORD *)(result + 23496);
              if ( v31 )
              {
                if ( *(_DWORD *)(result + 22588) == v30 )
                {
                  v32 = 0;
LABEL_48:
                  v33 = result + 8 * v32;
                  result = 0;
                  *(_QWORD *)(v33 + 23512) = a3[1];
                  goto LABEL_24;
                }
                if ( v31 != 1 )
                {
                  if ( *(_DWORD *)(result + 22740) == v30 )
                  {
                    v32 = 1;
                    goto LABEL_48;
                  }
                  if ( v31 != 2 )
                  {
                    if ( *(_DWORD *)(result + 22892) == v30 )
                    {
                      v32 = 2;
                      goto LABEL_48;
                    }
                    if ( v31 != 3 )
                    {
                      if ( *(_DWORD *)(result + 23044) == v30 )
                      {
                        v32 = 3;
                        goto LABEL_48;
                      }
                      if ( v31 != 4 )
                      {
                        v5 = *(_DWORD *)(result + 23196);
                        if ( v5 == v30 )
                        {
                          v32 = 4;
                          goto LABEL_48;
                        }
                        if ( v31 != 5 )
                        {
                          v4 = (_DWORD *)*(unsigned int *)(result + 23348);
                          if ( (_DWORD)v4 == v30 )
                          {
                            v32 = 5;
                            goto LABEL_48;
                          }
                          if ( v31 != 6 )
                          {
LABEL_256:
                            __break(0x5512u);
                            goto LABEL_257;
                          }
                        }
                      }
                    }
                  }
                }
              }
LABEL_137:
              result = 0;
              goto LABEL_24;
            }
          }
        }
        v22 = "cam_sfe_top_clock_update";
        v23 = "Invalid args";
        v24 = 0x40000000;
        v25 = 824;
      }
      else
      {
        v22 = "cam_sfe_top_clock_update";
        v23 = "Invalid cmd size";
        v24 = 0x40000000;
        v25 = 816;
      }
LABEL_22:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v24,
        1,
        v22,
        v25,
        v23);
LABEL_23:
      result = 4294967274LL;
      goto LABEL_24;
    }
LABEL_85:
    v53 = "cam_sfe_top_process_cmd";
    v54 = "Invalid cmd type: %d";
    v14 = (unsigned int)a2;
    v55 = 1493;
LABEL_96:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x40000000,
      1,
      v53,
      v55,
      v54,
      v14);
    goto LABEL_23;
  }
  if ( a2 == 11 )
  {
    result = cam_sfe_top_bw_update(result, (_DWORD *)result, (int **)a3);
    goto LABEL_24;
  }
  if ( a2 == 12 )
  {
    result = cam_sfe_top_bw_control(result, (_DWORD *)result, a3);
    goto LABEL_24;
  }
  if ( a2 != 13 )
    goto LABEL_85;
  if ( a4 != 40 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_fcg_config",
      1388,
      "Invalid cmd size, arg_size: %u, expected size: %u",
      a4,
      40);
    goto LABEL_23;
  }
  if ( !a3 || !*a3 )
  {
    v22 = "cam_sfe_top_fcg_config";
    v23 = "Invalid cmd args";
    v24 = 0x40000000;
    v25 = 1394;
    goto LABEL_22;
  }
  v13 = *(_QWORD *)(*a3 + 48);
  if ( !v13 )
  {
    v22 = "cam_sfe_top_fcg_config";
    v23 = "Invalid CDM ops";
    v24 = 0x40000000;
    v25 = 1401;
    goto LABEL_22;
  }
  if ( *((_BYTE *)a3 + 12) == 1 )
  {
    v15 = *(_QWORD *)(result + 32296);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v15 + 8);
      if ( v16 )
      {
        if ( (*(_BYTE *)(v16 + 40) & 1) == 0 )
        {
          result = 0;
          *((_BYTE *)a3 + 28) = 0;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_top_get_fcg_buf_size",
              1360,
              "FCG is not supported by hardware");
            result = 0;
          }
          goto LABEL_24;
        }
        v17 = *((_DWORD *)a3 + 4);
        *((_BYTE *)a3 + 28) = 1;
        if ( v17 )
        {
          v19 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v16 + 32) + 16LL) * v17);
          v20 = *(__int64 (__fastcall **)(_QWORD))(v13 + 24);
          if ( *((_DWORD *)v20 - 1) != 2010610996 )
            __break(0x8228u);
          v21 = v20(v19);
          result = 0;
          *((_DWORD *)a3 + 6) = v21;
          goto LABEL_24;
        }
        v22 = "cam_sfe_top_get_fcg_buf_size";
        v23 = "Number of types(STATS/PHASE) requested is empty";
        v24 = 0x40000000;
        v25 = 1367;
      }
      else
      {
        v22 = "cam_sfe_top_get_fcg_buf_size";
        v23 = "Invalid modules hw info";
        v24 = 0x40000000;
        v25 = 1354;
      }
    }
    else
    {
      v22 = "cam_sfe_top_get_fcg_buf_size";
      v23 = "Invalid config params";
      v24 = 0x40000000;
      v25 = 1348;
    }
    goto LABEL_22;
  }
  if ( !*((_DWORD *)a3 + 7) )
  {
    v22 = "cam_sfe_top_apply_fcg_update";
    v23 = "Invalid args";
    v24 = 0x40000000;
    v25 = 1167;
    goto LABEL_22;
  }
  v9 = (unsigned int *)a3[4];
  if ( !v9 || (v64 = *(_QWORD *)(result + 32296)) == 0 )
  {
    v22 = "cam_sfe_top_apply_fcg_update";
    v23 = "Invalid config params";
    v24 = 0x40000000;
    v25 = 1174;
    goto LABEL_22;
  }
  v65 = *(_DWORD **)(*(_QWORD *)(v64 + 8) + 32LL);
  if ( !v65 )
  {
    v22 = "cam_sfe_top_apply_fcg_update";
    v23 = "Invalid FCG common data";
    v24 = 0x40000000;
    v25 = 1180;
    goto LABEL_22;
  }
  v14 = *v9;
  if ( (unsigned int)v14 >= 4 )
  {
    v53 = "cam_sfe_top_apply_fcg_update";
    v54 = "out of bound %d";
    v55 = 1186;
    goto LABEL_96;
  }
  v7 = &unk_2FD000;
  v8 = a3;
  if ( mem_trace_en != 1 )
  {
    v84 = v65;
    v85 = _kvmalloc_node_noprof(4LL * (unsigned int)v65[3], 0, 3520, 0xFFFFFFFFLL);
    if ( v85 )
      goto LABEL_156;
LABEL_167:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_apply_fcg_update",
      1194,
      "Failed allocating memory for reg val pair");
    result = 4294967284LL;
    goto LABEL_24;
  }
  v84 = v65;
  v85 = cam_mem_trace_alloc(4LL * (unsigned int)v65[3], 0xCC0u, 0, "cam_sfe_top_apply_fcg_update", 0x4A8u);
  if ( !v85 )
    goto LABEL_167;
LABEL_156:
  v226 = (_QWORD *)v85;
  if ( !*v9 )
  {
LABEL_311:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      2,
      "cam_sfe_top_apply_fcg_update",
      1324,
      "No reg val pairs");
LABEL_312:
    v160 = 0;
    goto LABEL_313;
  }
  v5 = v84[2];
  LODWORD(v14) = 0;
  v31 = 0;
  v4 = v84;
  v12 = "cam_sfe_top_apply_fcg_update";
  v6 = "Exceed buf size %u when adding reg/val at index %u and %u";
  v10 = &unk_393000;
  v11 = "Program FCG registers for SFE channel 0x%x, phase_index_cfg_0: %u, phase_index_cfg_1: %u";
  v86 = v8;
  while ( 1 )
  {
    v127 = v4[3];
    if ( (unsigned int)v14 >= v127 )
    {
      v158 = "reg_val_pair %d exceeds the array limit %u";
      v159 = 1203;
      goto LABEL_305;
    }
    v128 = *((_QWORD *)v9 + 2) + 16LL * v31;
    if ( !v128 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_fcg_update",
        1210,
        "Failed in FCG channel/context dereference");
      v160 = -22;
      goto LABEL_313;
    }
    v129 = (_DWORD *)(*(_QWORD *)(v128 + 8) + 24LL * (unsigned int)(*((_DWORD *)v86 + 7) - 1));
    if ( (*(_BYTE *)(v128 + 4) & 1) == 0 )
      goto LABEL_262;
    v130 = *(_DWORD *)v128;
    if ( *(_DWORD *)v128 == 4 )
    {
      if ( (unsigned int)v14 >= v127 - 1 )
      {
        v220 = v14;
        v200 = v4;
        v190 = v31;
        v210 = v5;
        v177 = *((_QWORD *)v9 + 2) + 16LL * v31;
        v182 = *(_QWORD *)(v128 + 8) + 24LL * (unsigned int)(*((_DWORD *)v86 + 7) - 1);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
          3,
          8,
          1,
          v12,
          1241,
          v6,
          v127,
          (unsigned int)v14,
          v14 + 1);
        v128 = v177;
        v129 = (_DWORD *)v182;
        v5 = v210;
        v149 = v220;
        v31 = v190;
        v4 = v200;
        v85 = (__int64)v226;
        v86 = v8;
      }
      else
      {
        v148 = v14 + 1;
        *(_DWORD *)(v85 + 4LL * (int)v14) = v4[7];
        v149 = v14 + 2;
        *(_DWORD *)(v85 + 4LL * v148) = (*v129 << v5) | v129[1];
      }
      v150 = v4[3];
      if ( v149 < v150 - 1 )
      {
        *(_DWORD *)(v85 + 4LL * (int)v149) = v4[8];
        v151 = v149 + 1;
        LODWORD(v14) = v149 + 2;
        *(_DWORD *)(v85 + 4LL * v151) = v129[2];
        v152 = debug_mdl;
        if ( (debug_mdl & 0x40000000) == 0 )
          goto LABEL_262;
LABEL_283:
        if ( v10[919] )
          goto LABEL_262;
        v141 = v129[1];
        v142 = *(_DWORD *)v128;
        v143 = v129[2];
        v144 = v152 & 0x40000000;
        v145 = v12;
        v146 = *v129 << v5;
        v147 = 1251;
LABEL_285:
        v217 = v14;
        v197 = v4;
        v187 = v31;
        v207 = v5;
        v174 = v128;
        v179 = v129;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
          3,
          v144,
          4,
          v145,
          v147,
          v11,
          v142,
          v146 | v141,
          v143);
        v128 = v174;
        v129 = v179;
        v5 = v207;
        LODWORD(v14) = v217;
        v31 = v187;
        v4 = v197;
        v85 = (__int64)v226;
        v86 = v8;
        goto LABEL_262;
      }
      v221 = v149;
      v201 = v4;
      v191 = v31;
      v211 = v5;
      v178 = v128;
      v183 = v129;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        v12,
        1245,
        v6,
        v150,
        v149,
        v149 + 1);
      v128 = v178;
      v129 = v183;
      v5 = v211;
      LODWORD(v14) = v221;
      v31 = v191;
      v4 = v201;
      v85 = (__int64)v226;
      v86 = v8;
      v152 = debug_mdl;
      if ( (debug_mdl & 0x40000000) != 0 )
        goto LABEL_283;
    }
    else
    {
      if ( v130 != 2 )
      {
        v167 = 1255;
        goto LABEL_325;
      }
      if ( (unsigned int)v14 >= v127 - 1 )
      {
        v218 = v14;
        v198 = v4;
        v188 = v31;
        v208 = v5;
        v175 = *((_QWORD *)v9 + 2) + 16LL * v31;
        v180 = *(_QWORD *)(v128 + 8) + 24LL * (unsigned int)(*((_DWORD *)v86 + 7) - 1);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
          3,
          8,
          1,
          v12,
          1224,
          v6,
          v127,
          (unsigned int)v14,
          v14 + 1);
        v128 = v175;
        v129 = (_DWORD *)v180;
        v5 = v208;
        v137 = v218;
        v31 = v188;
        v4 = v198;
        v85 = (__int64)v226;
        v86 = v8;
      }
      else
      {
        v136 = v14 + 1;
        *(_DWORD *)(v85 + 4LL * (int)v14) = v4[5];
        v137 = v14 + 2;
        *(_DWORD *)(v85 + 4LL * v136) = (*v129 << v5) | v129[1];
      }
      v138 = v4[3];
      if ( v137 < v138 - 1 )
      {
        *(_DWORD *)(v85 + 4LL * (int)v137) = v4[6];
        v139 = v137 + 1;
        LODWORD(v14) = v137 + 2;
        *(_DWORD *)(v85 + 4LL * v139) = v129[2];
        v140 = debug_mdl;
        if ( (debug_mdl & 0x40000000) == 0 )
          goto LABEL_262;
LABEL_277:
        if ( v10[919] )
          goto LABEL_262;
        v141 = v129[1];
        v142 = *(_DWORD *)v128;
        v143 = v129[2];
        v144 = v140 & 0x40000000;
        v145 = v12;
        v146 = *v129 << v5;
        v147 = 1234;
        goto LABEL_285;
      }
      v219 = v137;
      v199 = v4;
      v189 = v31;
      v209 = v5;
      v176 = v128;
      v181 = v129;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        v12,
        1228,
        v6,
        v138,
        v137,
        v137 + 1);
      v128 = v176;
      v129 = v181;
      v5 = v209;
      LODWORD(v14) = v219;
      v31 = v189;
      v4 = v199;
      v85 = (__int64)v226;
      v86 = v8;
      v140 = debug_mdl;
      if ( (debug_mdl & 0x40000000) != 0 )
        goto LABEL_277;
    }
LABEL_262:
    if ( (*(_BYTE *)(v128 + 4) & 2) == 0 )
      goto LABEL_258;
    v130 = *(_DWORD *)v128;
    if ( *(_DWORD *)v128 != 4 )
      break;
    v153 = v4[3];
    if ( (unsigned int)v14 >= v153 - 1 )
    {
      v224 = v14;
      v204 = v4;
      v194 = v31;
      v214 = v5;
      v185 = v129;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
        3,
        8,
        1,
        v12,
        1285,
        v6,
        v153,
        (unsigned int)v14,
        v14 + 1);
      v129 = v185;
      v5 = v214;
      v155 = v224;
      v31 = v194;
      v4 = v204;
      v85 = (__int64)v226;
      v86 = v8;
    }
    else
    {
      v154 = v14 + 1;
      *(_DWORD *)(v85 + 4LL * (int)v14) = v4[11];
      v155 = v14 + 2;
      *(_DWORD *)(v85 + 4LL * v154) = (v129[3] << v5) | v129[4];
    }
    v156 = v4[3];
    if ( v155 >= v156 - 1 )
    {
      v225 = v155;
      v205 = v4;
      v195 = v31;
      v215 = v5;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        v12,
        1289,
        v6,
        v156,
        v155,
        v155 + 1);
      v5 = v215;
      LODWORD(v14) = v225;
      v31 = v195;
      v4 = v205;
      v85 = (__int64)v226;
      v86 = v8;
      if ( (debug_mdl & 0x40000000) == 0 )
        goto LABEL_258;
    }
    else
    {
      *(_DWORD *)(v85 + 4LL * (int)v155) = v4[12];
      v157 = v155 + 1;
      LODWORD(v14) = v155 + 2;
      *(_DWORD *)(v85 + 4LL * v157) = v129[5];
      if ( (debug_mdl & 0x40000000) == 0 )
        goto LABEL_258;
    }
    if ( v10[919] )
      goto LABEL_258;
    result = 3;
LABEL_257:
    v216 = v14;
    v196 = v4;
    v186 = v31;
    v206 = v5;
    ((void (__fastcall *)(__int64))cam_print_log)(result);
    v5 = v206;
    LODWORD(v14) = v216;
    v31 = v186;
    v4 = v196;
    v85 = (__int64)v226;
    v86 = v8;
LABEL_258:
    if ( ++v31 >= *v9 )
    {
      if ( (int)v14 >= 0 )
        v161 = v14;
      else
        v161 = v14 + 1;
      if ( (unsigned int)(v14 + 1) < 3 )
        goto LABEL_311;
      v163 = v161 >> 1;
      v164 = *(unsigned int (__fastcall **)(_QWORD))(v13 + 24);
      if ( *((_DWORD *)v164 - 1) != 2010610996 )
        __break(0x8228u);
      if ( 4 * v164(v163) == *((_DWORD *)v8 + 6) )
      {
        v165 = *(_DWORD **)(v13 + 120);
        v166 = v8[2];
        if ( *(v165 - 1) != -1401492769 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *))v165)(v166, v163, v226);
        goto LABEL_312;
      }
      v158 = "Failed! Buf size:%d is wrong, expected size: %d";
      v159 = 1315;
LABEL_305:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_fcg_update",
        v159,
        v158);
      v160 = -12;
      goto LABEL_313;
    }
  }
  if ( v130 == 2 )
  {
    v131 = v4[3];
    if ( (unsigned int)v14 >= v131 - 1 )
    {
      v222 = v14;
      v202 = v4;
      v192 = v31;
      v212 = v5;
      v184 = v129;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
        3,
        8,
        1,
        v12,
        1268,
        v6,
        v131,
        (unsigned int)v14,
        v14 + 1);
      v129 = v184;
      v5 = v212;
      v133 = v222;
      v31 = v192;
      v4 = v202;
      v85 = (__int64)v226;
      v86 = v8;
    }
    else
    {
      v132 = v14 + 1;
      *(_DWORD *)(v85 + 4LL * (int)v14) = v4[9];
      v133 = v14 + 2;
      *(_DWORD *)(v85 + 4LL * v132) = (v129[3] << v5) | v129[4];
    }
    v134 = v4[3];
    if ( v133 >= v134 - 1 )
    {
      v223 = v133;
      v203 = v4;
      v193 = v31;
      v213 = v5;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        v12,
        1272,
        v6,
        v134,
        v133,
        v133 + 1);
      v5 = v213;
      LODWORD(v14) = v223;
      v31 = v193;
      v4 = v203;
      v85 = (__int64)v226;
      v86 = v8;
      if ( (debug_mdl & 0x40000000) == 0 )
        goto LABEL_258;
    }
    else
    {
      *(_DWORD *)(v85 + 4LL * (int)v133) = v4[10];
      v135 = v133 + 1;
      LODWORD(v14) = v133 + 2;
      *(_DWORD *)(v85 + 4LL * v135) = v129[5];
      if ( (debug_mdl & 0x40000000) == 0 )
        goto LABEL_258;
    }
    if ( v10[919] )
      goto LABEL_258;
    result = 3;
    goto LABEL_257;
  }
  v167 = 1299;
LABEL_325:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_top_apply_fcg_update",
    v167,
    "Unsupported channel id: 0x%x",
    v130);
  v160 = -22;
LABEL_313:
  v162 = v160;
  if ( v7[2904] == 1 )
    cam_mem_trace_free(v226, 0);
  else
    kvfree(v226);
  result = v162;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
