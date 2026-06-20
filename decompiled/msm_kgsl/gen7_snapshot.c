__int64 __fastcall gen7_snapshot(_QWORD *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x10
  int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x19
  __int64 *v10; // x20
  __int64 v11; // t1
  unsigned int v12; // w23
  int v13; // w24
  unsigned int v14; // w25
  int v15; // w0
  int v16; // w20
  int v17; // w19
  unsigned int v18; // w23
  int v19; // w24
  unsigned int v20; // w25
  int v21; // w0
  int v22; // w19
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x23
  int v25; // w0
  int v26; // w0
  _QWORD *resource_byname; // x24
  __int64 v28; // x0
  _QWORD *v29; // x25
  __int64 v30; // x2
  __int64 v31; // x24
  __int64 v32; // x2
  __int64 v33; // x0
  __int16 v34; // w8
  unsigned int v35; // w0
  int v36; // w8
  int v37; // w8
  int v38; // w9
  __int64 v39; // x9
  __int64 (__fastcall *v40)(); // x3
  _QWORD *v41; // x0
  __int64 v42; // x2
  int v43; // w24
  __int64 (__fastcall *v44)(_QWORD); // x8
  unsigned int v45; // w24
  unsigned int v46; // w25
  _QWORD *v47; // x8
  unsigned __int64 v48; // x9
  int v49; // w19
  __int64 v50; // x20
  unsigned __int64 v51; // x9
  int v52; // w19
  __int64 v53; // x20
  __int64 v54; // x8
  unsigned __int64 v55; // x9
  int v56; // w19
  __int64 v57; // x20
  __int64 (__fastcall *v58)(_QWORD); // x8
  unsigned int *v59; // x19
  __int64 v60; // x11
  __int64 v61; // x9
  _QWORD *v62; // x8
  __int64 v63; // x10
  unsigned int *v64; // x12
  __int64 v65; // x14
  __int64 v66; // x13
  unsigned int v67; // t1
  __int64 v68; // x10
  __int64 v69; // x9
  __int64 (__fastcall *v70)(); // x3
  _QWORD *v71; // x0
  __int64 v72; // x2
  unsigned int *v73; // x4
  unsigned int *v74; // x24
  __int64 result; // x0
  __int64 v76; // x1
  unsigned int v77; // w2
  __int64 v78; // x1
  unsigned int v79; // w2
  __int64 v80; // x1
  unsigned int v81; // w2
  __int64 v82; // x1
  __int64 v83; // x1
  __int64 v84; // x1
  __int64 v85; // x1
  unsigned int v86; // w2
  __int64 v87; // x1
  unsigned int v88; // w2
  __int64 v89; // x1
  __int64 v90; // x1
  unsigned int **v91; // x25
  __int64 v92; // x11
  unsigned int *v93; // x14
  _QWORD *v94; // x8
  int v95; // w11
  unsigned int *v96; // x10
  unsigned int **v97; // x15
  unsigned int *v98; // x16
  __int64 v99; // x15
  __int64 v100; // x15
  unsigned int *v101; // x14
  __int64 v102; // x16
  __int64 v103; // x17
  unsigned int v104; // t1
  int v105; // w19
  unsigned int **v106; // x4
  __int64 (__fastcall *v107)(_QWORD); // x8
  __int64 (__fastcall *v108)(_QWORD); // x8
  __int64 v109; // x8
  unsigned __int64 v110; // x9
  unsigned int v111; // w19
  unsigned int v112; // w0
  int *v113; // x8
  int v114; // w10
  unsigned int v115; // w9
  unsigned int v116; // w0
  unsigned int v117; // w0
  int v118; // w8
  __int64 v119; // x19
  unsigned __int64 v120; // x24
  __int64 v121; // x11
  unsigned __int64 *v122; // x8
  __int64 v123; // x15
  int v124; // w11
  __int64 v125; // x10
  int *v126; // x16
  int v127; // w15
  int v128; // w17
  unsigned __int64 v129; // x0
  unsigned int *v130; // x15
  __int64 v131; // x16
  __int64 v132; // x17
  __int64 v133; // x16
  unsigned int *v134; // x15
  __int64 v135; // x17
  unsigned __int64 v136; // x0
  unsigned int v137; // t1
  unsigned __int64 v138; // x8
  int v139; // w20
  __int64 v140; // x19
  unsigned __int64 v141; // x24
  __int64 v142; // x11
  unsigned __int64 *v143; // x8
  __int64 v144; // x14
  int v145; // w11
  __int64 v146; // x10
  __int64 v147; // x14
  char v148; // w15
  int *v149; // x16
  int v150; // w17
  __int64 v151; // x15
  int *v152; // x16
  __int64 v153; // x0
  __int64 v154; // x1
  unsigned __int64 v155; // x17
  int v156; // t1
  unsigned __int64 v157; // x8
  int v158; // w20
  int *v159; // x8
  int v160; // w8
  __int64 v161; // x19
  unsigned __int64 v162; // x24
  unsigned __int16 v163; // w9
  unsigned __int64 v164; // x8
  int v165; // w9
  _DWORD *v166; // x20
  unsigned int v167; // w9
  unsigned int v168; // w11
  unsigned __int64 *v169; // x8
  unsigned __int64 v170; // x15
  unsigned int i; // w10
  __int64 v172; // x13
  __int64 v173; // x11
  unsigned __int64 v174; // x12
  __int64 v175; // x15
  __int64 v176; // x16
  __int64 v177; // x10
  __int64 v178; // x10
  char v179; // w0
  unsigned int v180; // w8
  __int64 (__fastcall *v181)(); // x23
  unsigned int v182; // w9
  unsigned int v183; // w26
  unsigned int j; // w28
  unsigned int k; // w27
  __int64 v186; // x8
  unsigned int v187; // w25
  unsigned int v188; // w20
  _DWORD *v189; // x26
  unsigned int v190; // w8
  unsigned int v191; // w9
  unsigned int m; // w27
  unsigned int n; // w28
  int v194; // w8
  unsigned __int16 v195; // w9
  __int64 v196; // x9
  __int64 v197; // x9
  __int64 v198; // x9
  __int64 v199; // x10
  __int64 (__fastcall *v200)(); // x24
  int v201; // w19
  unsigned int **v202; // x4
  __int64 v203; // x10
  __int64 (__fastcall *v204)(); // x23
  unsigned __int64 v205; // x8
  int v206; // w20
  __int64 v207; // x10
  __int64 (__fastcall *v208)(); // x23
  unsigned __int64 v209; // x8
  int v210; // w20
  unsigned int v211; // [xsp+Ch] [xbp-44h]
  int policy; // [xsp+10h] [xbp-40h]
  unsigned int v213; // [xsp+14h] [xbp-3Ch]
  int v214; // [xsp+14h] [xbp-3Ch]
  __pid_t pid[2]; // [xsp+18h] [xbp-38h]
  struct sched_param param; // [xsp+24h] [xbp-2Ch] BYREF
  _DWORD *v217; // [xsp+28h] [xbp-28h] BYREF
  unsigned __int64 v218; // [xsp+30h] [xbp-20h]
  __int64 v219; // [xsp+38h] [xbp-18h]
  __int64 v220; // [xsp+40h] [xbp-10h]
  __int64 v221; // [xsp+48h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v221 = *(_QWORD *)(StatusReg + 1808);
  v6 = *(_DWORD *)(v3 + 148);
  v7 = a1[1783];
  *(_QWORD *)pid = v3;
  gen7_crashdump_timedout = 0;
  param.__sched_priority = v6;
  policy = *(_DWORD *)(v3 + 1352);
  gen7_snapshot_block_list = *(_QWORD *)(v7 + 208);
  if ( (gmu_core_isenabled(a1) & 1) == 0 )
  {
    v8 = *(_QWORD *)(a1[1783] + 208LL);
    v9 = *(unsigned int *)(v8 + 64);
    gen7_snapshot_block_list = v8;
    if ( v9 )
    {
      v10 = *(__int64 **)(v8 + 56);
      do
      {
        v11 = *v10++;
        kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, v11);
        --v9;
      }
      while ( v9 );
    }
  }
  WORD2(v217) = 0;
  LODWORD(v217) = 0;
  v12 = kgsl_regmap_read(a1 + 1650);
  v13 = kgsl_regmap_read(a1 + 1650);
  HIWORD(v218) = (unsigned __int8)(v13 | v12);
  HIWORD(v217) = ((v13 | v12) >> 16) & 0x1FF;
  v14 = kgsl_regmap_read(a1 + 1650);
  v15 = kgsl_regmap_read(a1 + 1650);
  v16 = v15 | v13;
  v17 = v14 | v12;
  LOWORD(v219) = (unsigned __int8)(v15 | v14);
  LOWORD(v218) = ((v15 | v14) >> 16) & 0x1FF;
  v18 = kgsl_regmap_read(a1 + 1650);
  v19 = kgsl_regmap_read(a1 + 1650);
  WORD1(v219) = (unsigned __int8)(v19 | v18);
  WORD1(v218) = ((v19 | v18) >> 16) & 0x1FF;
  v20 = kgsl_regmap_read(a1 + 1650);
  v21 = kgsl_regmap_read(a1 + 1650);
  v22 = v17 | v18 | v20;
  WORD2(v219) = (unsigned __int8)(v21 | v20);
  WORD2(v218) = ((v21 | v20) >> 16) & 0x1FF;
  if ( v22 | v16 | v19 | v21 )
  {
    v23 = clk_get(a1[1396] + 16LL, "apb_pclk");
    if ( v23 < 0xFFFFFFFFFFFFF001LL )
    {
      v24 = v23;
      v25 = clk_prepare();
      if ( v25 )
      {
        v43 = v25;
      }
      else
      {
        v26 = clk_enable(v24);
        if ( !v26 )
        {
          resource_byname = (_QWORD *)platform_get_resource_byname(a1[1396], 512, "qdss_etr");
          v28 = platform_get_resource_byname(a1[1396], 512, "qdss_tmc");
          if ( resource_byname )
          {
            v29 = (_QWORD *)v28;
            if ( v28 )
            {
              if ( arm64_use_ng_mappings )
                v30 = 0x68000000000F13LL;
              else
                v30 = 0x68000000000713LL;
              v31 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v30);
              if ( arm64_use_ng_mappings )
                v32 = 0x68000000000F13LL;
              else
                v32 = 0x68000000000713LL;
              v33 = ioremap_prot(*v29, v29[1] - *v29 + 1LL, v32);
              tmc_virt = v33;
              if ( v31 && v33 )
              {
                if ( v22 )
                  v34 = 1;
                else
                  v34 = 2;
                LOWORD(v217) = v34;
                v35 = kgsl_regmap_read(a1 + 1650);
                WORD2(v217) = (v35 >> 12) & 7;
                WORD1(v217) = v35 >> 28;
                v36 = *(_DWORD *)(tmc_virt + 32);
                __dsb(0xDu);
                if ( v36 )
                {
                  v37 = *(_DWORD *)(v31 + 32);
                  __dsb(0xDu);
                  v38 = *(_DWORD *)(v31 + 28704);
                  __dsb(0xDu);
                  if ( !(v37 | v38) )
                    kgsl_snapshot_add_section(a1, 6401, a2, gen7_snapshot_trace_buffer_etb, &v217);
                  v39 = tmc_virt;
                  __dsb(0xEu);
                  *(_DWORD *)(v39 + 32) = 0;
                }
                else
                {
                  if ( v22 )
                  {
                    v40 = gen7_snapshot_trace_buffer_gfx_trace;
                    v41 = a1;
                    v42 = a2;
                  }
                  else
                  {
                    v41 = a1;
                    v42 = a2;
                    v40 = nullptr;
                  }
                  kgsl_snapshot_add_section(v41, 6401, v42, v40, &v217);
                }
              }
              iounmap(tmc_virt);
              iounmap(v31);
            }
          }
          clk_disable(v24);
          clk_unprepare(v24);
          goto LABEL_37;
        }
        v43 = v26;
        clk_unprepare(v24);
      }
      dev_err(*a1, "QDSS Clock enable error: %d\n", v43);
LABEL_37:
      clk_put(v24);
      goto LABEL_38;
    }
    dev_err(*a1, "Unable to get QDSS clock\n");
  }
  else
  {
    kgsl_snapshot_add_section(a1, 6401, a2, 0, &v217);
  }
LABEL_38:
  if ( *(_DWORD *)a1[1783] >> 1 == 230528 )
    goto LABEL_44;
  v44 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 240LL);
  if ( *((_DWORD *)v44 - 1) != 33171575 )
    __break(0x8228u);
  if ( (v44(a1) & 1) == 0 )
  {
LABEL_44:
    v213 = 0;
    v45 = 0;
    v46 = 0;
    if ( *((_DWORD *)a1 + 3295) )
      goto LABEL_55;
  }
  else
  {
    v213 = kgsl_regmap_read(a1 + 1650);
    v45 = kgsl_regmap_read(a1 + 1650);
    v46 = kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_rmw(a1 + 1650, 180, 7340032, 0);
    kgsl_regmap_rmw(a1 + 1650, 192, 7, 0);
    kgsl_regmap_rmw(a1 + 1650, 200, 28672, 0);
    if ( *((_DWORD *)a1 + 3295) )
      goto LABEL_55;
  }
  kgsl_regmap_write(a1 + 1650, 4026531840LL);
  kgsl_regmap_write(a1 + 1650, 251658240);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 1985229328);
  kgsl_regmap_write(a1 + 1650, 4275878552LL);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 4026531840LL);
  kgsl_regmap_write(a1 + 1650, 251658240);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 1985229328);
  kgsl_regmap_write(a1 + 1650, 4275878552LL);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  kgsl_regmap_write(a1 + 1650, 0);
  v47 = (_QWORD *)gen7_snapshot_block_list;
  if ( *(_QWORD *)(gen7_snapshot_block_list + 16) )
  {
    v48 = 0;
    v49 = 1;
    do
    {
      v50 = 4 * v48;
      kgsl_snapshot_add_section(a1, 2561, a2, gen7_snapshot_dbgc_debugbus_block, v47[1] + 4 * v48);
      kgsl_snapshot_add_section(
        a1,
        6145,
        a2,
        gen7_snapshot_dbgc_side_debugbus_block,
        *(_QWORD *)(gen7_snapshot_block_list + 8) + v50);
      v47 = (_QWORD *)gen7_snapshot_block_list;
      v48 = v49++;
    }
    while ( *(_QWORD *)(gen7_snapshot_block_list + 16) > v48 );
  }
  if ( v47[4] )
  {
    v51 = 0;
    v52 = 1;
    do
    {
      v53 = 4 * v51;
      kgsl_snapshot_add_section(a1, 2561, a2, gen7_snapshot_dbgc_debugbus_block, v47[3] + 4 * v51);
      kgsl_snapshot_add_section(
        a1,
        6145,
        a2,
        gen7_snapshot_dbgc_side_debugbus_block,
        *(_QWORD *)(gen7_snapshot_block_list + 24) + v53);
      v47 = (_QWORD *)gen7_snapshot_block_list;
      v51 = v52++;
    }
    while ( *(_QWORD *)(gen7_snapshot_block_list + 32) > v51 );
  }
  if ( (kgsl_regmap_valid_offset(a1 + 1650, 99328) & 1) != 0 )
  {
    v54 = gen7_snapshot_block_list;
    if ( *(_QWORD *)(gen7_snapshot_block_list + 48) )
    {
      v55 = 0;
      v56 = 1;
      do
      {
        v57 = 4 * v55;
        kgsl_snapshot_add_section(a1, 2561, a2, gen7_snapshot_cx_dbgc_debugbus_block, *(_QWORD *)(v54 + 40) + 4 * v55);
        kgsl_snapshot_add_section(
          a1,
          6145,
          a2,
          gen7_snapshot_cx_side_dbgc_debugbus_block,
          *(_QWORD *)(gen7_snapshot_block_list + 40) + v57);
        v54 = gen7_snapshot_block_list;
        v55 = v56++;
      }
      while ( *(_QWORD *)(gen7_snapshot_block_list + 48) > v55 );
    }
  }
LABEL_55:
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) != 0x70900 )
  {
    v58 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 240LL);
    if ( *((_DWORD *)v58 - 1) != 33171575 )
      __break(0x8228u);
    if ( (v58(a1) & 1) != 0 )
    {
      kgsl_regmap_write(a1 + 1650, v213);
      kgsl_regmap_write(a1 + 1650, v45);
      kgsl_regmap_write(a1 + 1650, v46);
    }
  }
  v59 = *(unsigned int **)(gen7_snapshot_block_list + 104);
  if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0
    && *((_BYTE *)a1 + 11305) == 1
    && gen7_capturescript
    && (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL
    && gen7_crashdump_registers
    && (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
    && (gen7_crashdump_timedout & 1) == 0
    && (adreno_gx_is_on((__int64)a1) & 1) != 0 )
  {
    v60 = *v59;
    v61 = gen7_crashdump_registers;
    v62 = *(_QWORD **)(gen7_capturescript + 8);
    if ( (_DWORD)v60 == -1 )
    {
      v68 = 0;
    }
    else
    {
      v63 = 0;
      v64 = v59 + 2;
      do
      {
        v65 = *(_QWORD *)(v61 + 24) + v63;
        v66 = *(v64 - 1) - (unsigned int)v60 + 1;
        v63 += 4LL * (unsigned int)v66;
        *v62 = v65;
        v62[1] = v66 | (v60 << 44);
        v62 += 2;
        v67 = *v64;
        v64 += 2;
        v60 = v67;
      }
      while ( v67 != -1 );
      v68 = (unsigned int)v63 & 0xFFFFFFFC;
    }
    gen7_cd_reg_end = *(_QWORD *)(v61 + 8) + v68;
    *(_DWORD *)gen7_cd_reg_end = -1431655766;
    v69 = *(_QWORD *)(v61 + 24);
    v62[2] = 0;
    v62[3] = 0;
    *v62 = v69 + v68;
    v62[1] = 0x90300000000001LL;
    if ( (gen7_do_crashdump(a1) & 1) != 0 )
    {
      v70 = gen7_snapshot_cx_misc_registers;
      v71 = a1;
      v72 = a2;
      v73 = *(unsigned int **)(gen7_snapshot_block_list + 104);
LABEL_77:
      kgsl_snapshot_add_section(v71, 514, v72, v70, v73);
      goto LABEL_80;
    }
  }
  v74 = *(unsigned int **)(gen7_snapshot_block_list + 104);
  if ( (kgsl_regmap_valid_offset(a1 + 1650, *v74) & 1) != 0 )
  {
    v70 = adreno_snapshot_registers_v2;
    v71 = a1;
    v72 = a2;
    v73 = v74;
    goto LABEL_77;
  }
  if ( (gen7_cx_misc_regs_snapshot___already_done & 1) == 0 )
  {
    gen7_cx_misc_regs_snapshot___already_done = 1;
    _warn_printk("cx_misc registers are not defined in device tree");
    __break(0x800u);
  }
LABEL_80:
  result = adreno_gx_is_on((__int64)a1);
  if ( (result & 1) == 0 )
    goto LABEL_263;
  v211 = *(_DWORD *)(*(_QWORD *)pid + 148LL);
  if ( v211 <= 0x63 )
    sched_set_normal(*(_QWORD *)pid, 0);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v76 = 28677;
  else
    v76 = 28674;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v77 = 28678;
  else
    v77 = 28675;
  gen7_periph_regread64((__int64)a1, v76, v77, (__int64 *)a2, 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v78 = 28681;
  else
    v78 = 28678;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v79 = 28682;
  else
    v79 = 28679;
  gen7_periph_regread64((__int64)a1, v78, v79, (__int64 *)(a2 + 8), 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v80 = 28685;
  else
    v80 = 28682;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v81 = 28686;
  else
    v81 = 28683;
  gen7_periph_regread64((__int64)a1, v80, v81, (__int64 *)(a2 + 16), 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v82 = 28679;
  else
    v82 = 28676;
  gen7_periph_regread((__int64)a1, v82, (_DWORD *)(a2 + 24), 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v83 = 28683;
  else
    v83 = 28680;
  gen7_periph_regread((__int64)a1, v83, (_DWORD *)(a2 + 28), 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v84 = 28687;
  else
    v84 = 28684;
  gen7_periph_regread((__int64)a1, v84, (_DWORD *)(a2 + 32), 1);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v85 = 28677;
  else
    v85 = 28674;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v86 = 28678;
  else
    v86 = 28675;
  gen7_periph_regread64((__int64)a1, v85, v86, (__int64 *)(a2 + 40), 3);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v87 = 28681;
  else
    v87 = 28678;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v88 = 28682;
  else
    v88 = 28679;
  gen7_periph_regread64((__int64)a1, v87, v88, (__int64 *)(a2 + 48), 3);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v89 = 28679;
  else
    v89 = 28676;
  gen7_periph_regread((__int64)a1, v89, (_DWORD *)(a2 + 56), 3);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v90 = 28683;
  else
    v90 = 28680;
  gen7_periph_regread((__int64)a1, v90, (_DWORD *)(a2 + 60), 3);
  kgsl_regmap_write(a1 + 1650, 1);
  kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, *(_QWORD *)gen7_snapshot_block_list);
  v91 = *(unsigned int ***)(gen7_snapshot_block_list + 96);
  if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0
    && *((_BYTE *)a1 + 11305) == 1
    && gen7_capturescript
    && (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL
    && (v92 = gen7_crashdump_registers) != 0
    && (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
    && !gen7_crashdump_timedout )
  {
    v93 = *v91;
    v94 = *(_QWORD **)(gen7_capturescript + 8);
    if ( *v91 )
    {
      v95 = 0;
      v96 = nullptr;
      v97 = v91;
      do
      {
        v98 = v97[1];
        v97[2] = v96;
        if ( v98 )
        {
          v99 = v98[1];
          *v94 = v98[2];
          v94[1] = (v99 << 44) | 0x200001;
          v94 += 2;
        }
        v100 = *v93;
        if ( (_DWORD)v100 != -1 )
        {
          v101 = v93 + 2;
          do
          {
            v102 = *(v101 - 1) - (unsigned int)v100 + 1;
            v103 = (__int64)v96 + *(_QWORD *)(gen7_crashdump_registers + 24);
            v96 += (unsigned int)v102;
            *v94 = v103;
            v94[1] = v102 | (v100 << 44);
            v94 += 2;
            v104 = *v101;
            v101 += 2;
            v100 = v104;
          }
          while ( v104 != -1 );
        }
        v97 = &v91[3 * ++v95];
        v93 = *v97;
      }
      while ( *v97 );
      v92 = gen7_crashdump_registers;
      v196 = (unsigned int)v96;
    }
    else
    {
      v196 = 0;
    }
    gen7_cd_reg_end = *(_QWORD *)(v92 + 8) + v196;
    *(_DWORD *)gen7_cd_reg_end = -1431655766;
    v199 = *(_QWORD *)(v92 + 24);
    v94[2] = 0;
    v94[3] = 0;
    *v94 = v199 + v196;
    v94[1] = 0x90300000000001LL;
    if ( (gen7_do_crashdump(a1) & 1) != 0 )
      v200 = gen7_snapshot_registers;
    else
      v200 = gen7_legacy_snapshot_registers;
    if ( *v91 )
    {
      v201 = 1;
      v202 = v91;
      do
      {
        kgsl_snapshot_add_section(a1, 514, a2, v200, v202);
        v202 = &v91[3 * v201++];
      }
      while ( *v202 );
    }
  }
  else if ( *v91 )
  {
    v105 = 1;
    v106 = v91;
    do
    {
      kgsl_snapshot_add_section(a1, 514, a2, gen7_legacy_snapshot_registers, v106);
      v106 = &v91[3 * v105++];
    }
    while ( *v106 );
  }
  v107 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 240LL);
  if ( *((_DWORD *)v107 - 1) != 33171575 )
    __break(0x8228u);
  if ( (v107(a1) & 1) != 0 )
  {
    v213 = kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_rmw(a1 + 1650, 608, 7, 0);
  }
  kgsl_snapshot_indexed_registers(a1, a2, 2714, 2715, 0, 16640);
  v108 = *(__int64 (__fastcall **)(_QWORD))(a1[1094] + 240LL);
  if ( *((_DWORD *)v108 - 1) != 33171575 )
    __break(0x8228u);
  if ( (v108(a1) & 1) != 0 )
    kgsl_regmap_write(a1 + 1650, v213);
  v109 = gen7_snapshot_block_list;
  if ( *(_QWORD *)(gen7_snapshot_block_list + 176) )
  {
    v110 = 0;
    v111 = 1;
    do
    {
      kgsl_snapshot_indexed_registers(
        a1,
        a2,
        *(unsigned int *)(*(_QWORD *)(v109 + 168) + 12 * v110),
        *(unsigned int *)(*(_QWORD *)(v109 + 168) + 12 * v110 + 4),
        0,
        *(unsigned int *)(*(_QWORD *)(v109 + 168) + 12 * v110 + 8));
      v109 = gen7_snapshot_block_list;
      v110 = v111++;
    }
    while ( *(_QWORD *)(gen7_snapshot_block_list + 176) > v110 );
  }
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) != 0x70900 )
  {
    kgsl_regmap_write(a1 + 1650, 28883);
    v112 = kgsl_regmap_read(a1 + 1650);
    kgsl_snapshot_indexed_registers(a1, a2, 2316, 2317, 0, (v112 >> 18) & 0x3FFC);
    v113 = (int *)a1[1783];
    v114 = *v113;
    v115 = *v113 & 0xFFFFFFFE;
    if ( v115 != 461056 )
    {
      if ( v114 != 459520 && v114 != 462336 && v114 != 463104 )
      {
        kgsl_regmap_write(a1 + 1650, 28883);
        v116 = kgsl_regmap_read(a1 + 1650);
        kgsl_snapshot_indexed_registers(a1, a2, 2691, 2692, 0, (v116 >> 18) & 0x3FFC);
        v113 = (int *)a1[1783];
        v115 = *v113 & 0xFFFFFFFE;
      }
      if ( v115 != 461056 && (*((_BYTE *)v113 + 33) & 0x40) != 0 )
      {
        kgsl_regmap_write(a1 + 1650, 28883);
        v117 = kgsl_regmap_read(a1 + 1650);
        kgsl_snapshot_indexed_registers(a1, a2, 2828, 2869, 0, (v117 >> 18) & 0x3FFC);
      }
    }
  }
  kgsl_regmap_rmw(a1 + 1650, 2113, 4, 4);
  kgsl_snapshot_indexed_registers(a1, a2, 2318, 2319, 0, 8704);
  v118 = *(_DWORD *)a1[1783];
  if ( v118 != 459520 && v118 != 462336 && v118 != 463104 )
  {
    kgsl_regmap_rmw(a1 + 1650, 2778, 4, 4);
    kgsl_snapshot_indexed_registers(a1, a2, 2710, 2711, 0, 8704);
    kgsl_regmap_rmw(a1 + 1650, 2778, 4, 0);
  }
  kgsl_regmap_rmw(a1 + 1650, 2113, 4, 0);
  v119 = *(_QWORD *)(gen7_snapshot_block_list + 128);
  v120 = *(_QWORD *)(gen7_snapshot_block_list + 136);
  if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0
    && *((_BYTE *)a1 + 11305) == 1
    && gen7_capturescript
    && (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL
    && (v121 = gen7_crashdump_registers) != 0
    && (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
    && !gen7_crashdump_timedout )
  {
    v122 = *(unsigned __int64 **)(gen7_capturescript + 8);
    if ( v120 )
    {
      v123 = 0;
      v124 = 0;
      v125 = 0;
      do
      {
        v126 = (int *)(v119 + 40 * v123);
        v128 = *v126;
        v127 = v126[1];
        v126[8] = v125;
        v129 = ((unsigned __int64)(v127 & 3) << 12) | ((unsigned __int64)(v128 & 7) << 8) | (16LL * (v126[2] & 3));
        v130 = *((unsigned int **)v126 + 2);
        *v122 = v129;
        v122[1] = 0xA0300000200001LL;
        v131 = *((_QWORD *)v126 + 3);
        if ( v131 )
        {
          v132 = *(unsigned int *)(v131 + 4);
          v122[2] = *(unsigned int *)(v131 + 8);
          v122[3] = (v132 << 44) | 0x200001;
          v122 += 4;
        }
        else
        {
          v122 += 2;
        }
        v133 = *v130;
        if ( (_DWORD)v133 != -1 )
        {
          v134 = v130 + 2;
          do
          {
            v135 = *(v134 - 1) - (unsigned int)v133 + 1;
            v136 = *(_QWORD *)(gen7_crashdump_registers + 24) + v125;
            v125 += 4LL * (unsigned int)v135;
            *v122 = v136;
            v122[1] = v135 | (v133 << 44);
            v122 += 2;
            v137 = *v134;
            v134 += 2;
            v133 = v137;
          }
          while ( v137 != -1 );
        }
        v123 = ++v124;
      }
      while ( v120 > v124 );
      v121 = gen7_crashdump_registers;
      v197 = (unsigned int)v125;
    }
    else
    {
      v197 = 0;
    }
    gen7_cd_reg_end = *(_QWORD *)(v121 + 8) + v197;
    *(_DWORD *)gen7_cd_reg_end = -1431655766;
    v203 = *(_QWORD *)(v121 + 24);
    v122[2] = 0;
    v122[3] = 0;
    *v122 = v203 + v197;
    v122[1] = 0x90300000000001LL;
    if ( (gen7_do_crashdump(a1) & 1) != 0 )
      v204 = gen7_snapshot_mvc;
    else
      v204 = gen7_legacy_snapshot_mvc;
    if ( v120 )
    {
      v205 = 0;
      v206 = 1;
      do
      {
        kgsl_snapshot_add_section(a1, 5378, a2, v204, v119 + 40 * v205);
        v205 = v206++;
      }
      while ( v120 > v205 );
    }
  }
  else if ( v120 )
  {
    v138 = 0;
    v139 = 1;
    do
    {
      kgsl_snapshot_add_section(a1, 5378, a2, gen7_legacy_snapshot_mvc, v119 + 40 * v138);
      v138 = v139++;
    }
    while ( v120 > v138 );
  }
  v140 = *(_QWORD *)(gen7_snapshot_block_list + 144);
  v141 = *(_QWORD *)(gen7_snapshot_block_list + 152);
  if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0
    && *((_BYTE *)a1 + 11305) == 1
    && gen7_capturescript
    && (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL
    && (v142 = gen7_crashdump_registers) != 0
    && (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
    && !gen7_crashdump_timedout )
  {
    v143 = *(unsigned __int64 **)(gen7_capturescript + 8);
    if ( v141 )
    {
      v144 = 0;
      v145 = 0;
      v146 = 0;
      do
      {
        v147 = v140 + 40 * v144;
        v148 = *(_DWORD *)(v147 + 16);
        *(_DWORD *)(v147 + 36) = v146;
        v149 = *(int **)(v147 + 24);
        *v143 = ((unsigned __int64)(v148 & 3) << 18)
              | ((*(_DWORD *)(v147 + 8) & 3LL) << 16)
              | ((unsigned __int64)(unsigned __int8)*(_DWORD *)(v147 + 4) << 8);
        v143[1] = 0xAE6D00000200001LL;
        v143 += 2;
        v150 = *v149;
        if ( *v149 != -1 )
        {
          v151 = gen7_crashdump_registers;
          v152 = v149 + 2;
          do
          {
            v153 = (unsigned int)(v150 - *(_DWORD *)(v147 + 32) + 49152);
            v154 = (unsigned int)(*(v152 - 1) - v150 + 1);
            v155 = *(_QWORD *)(v151 + 24) + v146;
            v146 += 4LL * (unsigned int)v154;
            *v143 = v155;
            v143[1] = v154 | (v153 << 44);
            v143 += 2;
            v156 = *v152;
            v152 += 2;
            v150 = v156;
          }
          while ( v156 != -1 );
        }
        v144 = ++v145;
      }
      while ( v141 > v145 );
      v142 = gen7_crashdump_registers;
      v198 = (unsigned int)v146;
    }
    else
    {
      v198 = 0;
    }
    gen7_cd_reg_end = *(_QWORD *)(v142 + 8) + v198;
    *(_DWORD *)gen7_cd_reg_end = -1431655766;
    v207 = *(_QWORD *)(v142 + 24);
    v143[2] = 0;
    v143[3] = 0;
    *v143 = v207 + v198;
    v143[1] = 0x90300000000001LL;
    if ( (gen7_do_crashdump(a1) & 1) != 0 )
      v208 = gen7_snapshot_cluster_dbgahb;
    else
      v208 = gen7_legacy_snapshot_cluster_dbgahb;
    if ( v141 )
    {
      v209 = 0;
      v210 = 1;
      do
      {
        kgsl_snapshot_add_section(a1, 5378, a2, v208, v140 + 40 * v209);
        v209 = v210++;
      }
      while ( v141 > v209 );
    }
  }
  else if ( v141 )
  {
    v157 = 0;
    v158 = 1;
    do
    {
      kgsl_snapshot_add_section(a1, 5378, a2, gen7_legacy_snapshot_cluster_dbgahb, v140 + 40 * v157);
      v157 = v158++;
    }
    while ( v141 > v157 );
  }
  v159 = (int *)a1[1783];
  v219 = 0;
  v220 = 0;
  v217 = nullptr;
  v218 = 0;
  v160 = *v159;
  v161 = *(_QWORD *)(gen7_snapshot_block_list + 112);
  v162 = *(_QWORD *)(gen7_snapshot_block_list + 120);
  if ( v160 > 459775 )
  {
    if ( v160 == 459776 || v160 == 463104 )
      goto LABEL_215;
    v163 = 3584;
  }
  else
  {
    if ( (unsigned int)(v160 - 458752) < 2 )
    {
LABEL_215:
      kgsl_regmap_rmw(a1 + 1650, 44657, 3, 3);
      goto LABEL_216;
    }
    v163 = 768;
  }
  if ( v160 == (v163 | 0x70000) )
    goto LABEL_215;
LABEL_216:
  if ( (adreno_smmu_is_stalled((__int64)a1) & 1) == 0
    && *((_BYTE *)a1 + 11305) == 1
    && gen7_capturescript
    && (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL
    && gen7_crashdump_registers
    && (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
    && (gen7_crashdump_timedout & 1) == 0 )
  {
    if ( v162 )
    {
      v164 = 0;
      v165 = 0;
      do
      {
        v166 = (_DWORD *)(v161 + 32 * v164);
        v214 = v165;
        v167 = 0;
        v168 = v166[2];
        v169 = *(unsigned __int64 **)(gen7_capturescript + 8);
        if ( v168 )
        {
          LODWORD(v170) = v166[3];
          for ( i = 0; i < v168; ++i )
          {
            if ( (_DWORD)v170 )
            {
              v172 = gen7_crashdump_registers;
              v173 = 0;
              v174 = 0;
              do
              {
                v175 = (unsigned __int8)v173 & 0xF0;
                ++v174;
                v173 += 16;
                *v169 = v175 & 0xFFFFFFFFFFF000FFLL
                      | i & 0xF
                      | ((v166[5] & 3LL) << 18)
                      | ((v166[4] & 3LL) << 16)
                      | ((unsigned __int64)(unsigned __int8)*v166 << 8);
                v169[1] = 0xAE6D00000200001LL;
                v176 = (unsigned int)v166[1] | 0xC00000000000000LL;
                v169[2] = *(_QWORD *)(v172 + 24) + v167;
                v169[3] = v176;
                v169 += 4;
                v170 = (unsigned int)v166[3];
                v167 += 4 * v166[1];
              }
              while ( v174 < v170 );
              v168 = v166[2];
            }
          }
        }
        v177 = gen7_crashdump_registers;
        gen7_cd_reg_end = *(_QWORD *)(gen7_crashdump_registers + 8) + v167;
        *(_DWORD *)gen7_cd_reg_end = -1431655766;
        v178 = *(_QWORD *)(v177 + 24);
        v169[3] = 0;
        *v169 = v178 + v167;
        v169[1] = 0x90300000000001LL;
        v169[2] = 0;
        v179 = gen7_do_crashdump(a1);
        v180 = v166[2];
        if ( (v179 & 1) != 0 )
          v181 = gen7_snapshot_shader_memory;
        else
          v181 = gen7_legacy_snapshot_shader;
        if ( v180 )
        {
          v182 = v166[3];
          v183 = 0;
          for ( j = 0; j < v180; ++j )
          {
            if ( v182 )
            {
              for ( k = 0; k < v182; ++k )
              {
                v217 = v166;
                v218 = __PAIR64__(k, j);
                v220 = v183;
                v183 += 4 * v166[1];
                kgsl_snapshot_add_section(a1, 4610, a2, v181, &v217);
                v182 = v166[3];
              }
              v180 = v166[2];
            }
          }
        }
        v164 = (unsigned int)(v214 + 1);
        v165 = v214 + 1;
      }
      while ( v162 > v164 );
    }
  }
  else if ( v162 )
  {
    v186 = 0;
    v187 = 0;
    v188 = 0;
    do
    {
      v189 = (_DWORD *)(v161 + 32 * v186);
      v190 = v189[2];
      if ( v190 )
      {
        v191 = v189[3];
        for ( m = 0; m < v190; ++m )
        {
          if ( v191 )
          {
            for ( n = 0; n < v191; ++n )
            {
              v217 = v189;
              v218 = __PAIR64__(n, m);
              v220 = v188;
              v188 += 4 * v189[1];
              kgsl_snapshot_add_section(a1, 4610, a2, gen7_legacy_snapshot_shader, &v217);
              v191 = v189[3];
            }
            v190 = v189[2];
          }
        }
      }
      v186 = ++v187;
    }
    while ( v162 > v187 );
  }
  v194 = *(_DWORD *)a1[1783];
  if ( v194 > 459775 )
  {
    if ( v194 != 459776 && v194 != 463104 )
    {
      v195 = 3584;
LABEL_259:
      if ( v194 != (v195 | 0x70000) )
        goto LABEL_261;
    }
  }
  else if ( (unsigned int)(v194 - 458752) >= 2 )
  {
    v195 = 768;
    goto LABEL_259;
  }
  kgsl_regmap_rmw(a1 + 1650, 44657, 3, 0);
LABEL_261:
  kgsl_snapshot_add_section(a1, 514, a2, adreno_snapshot_registers_v2, *(_QWORD *)(gen7_snapshot_block_list + 160));
  kgsl_regmap_write(a1 + 1650, 0);
  result = adreno_snapshot_preemption_record(a1, a2);
  if ( v211 <= 0x63 )
    result = sched_setscheduler(pid[0], policy, &param);
LABEL_263:
  _ReadStatusReg(SP_EL0);
  return result;
}
