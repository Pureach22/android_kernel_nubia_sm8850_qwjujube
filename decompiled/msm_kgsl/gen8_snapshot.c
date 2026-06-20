__int64 __fastcall gen8_snapshot(_QWORD *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x27
  _QWORD *v5; // x20
  __int64 v6; // x8
  int v7; // w9
  int v8; // w25
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 *v12; // x21
  __int64 v13; // t1
  unsigned int *v14; // x21
  __int64 v15; // x8
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x10
  _QWORD *v18; // x8
  __int64 v19; // x11
  __int64 v20; // x9
  unsigned int *v21; // x12
  __int64 v22; // x14
  __int64 v23; // x13
  unsigned int v24; // t1
  __int64 v25; // x9
  unsigned int *v26; // x23
  __int64 (__fastcall *v27)(); // x3
  _QWORD *v28; // x0
  __int64 v29; // x2
  unsigned int *v30; // x4
  __int64 v31; // x8
  unsigned __int64 v32; // x9
  unsigned int v33; // w19
  __int64 v34; // x21
  __int64 result; // x0
  unsigned int v36; // w23
  int v37; // w24
  unsigned int v38; // w25
  int v39; // w0
  int v40; // w26
  int v41; // w21
  unsigned int v42; // w23
  int v43; // w24
  unsigned int v44; // w25
  int v45; // w0
  int v46; // w21
  unsigned __int64 v47; // x0
  unsigned __int64 v48; // x26
  unsigned __int64 v49; // x23
  int v50; // w0
  int v51; // w0
  _QWORD *resource_byname; // x24
  __int64 v53; // x0
  _QWORD *v54; // x25
  __int64 v55; // x2
  __int64 v56; // x24
  __int64 v57; // x2
  __int64 v58; // x0
  __int16 v59; // w8
  unsigned int v60; // w0
  int v61; // w8
  int v62; // w8
  int v63; // w9
  __int64 v64; // x9
  __int64 (__fastcall *v65)(); // x3
  _QWORD *v66; // x0
  __int64 v67; // x2
  int v68; // w24
  _QWORD *v69; // x8
  unsigned __int64 v70; // x9
  unsigned int v71; // w19
  __int64 v72; // x21
  unsigned __int64 v73; // x9
  unsigned int v74; // w19
  __int64 v75; // x21
  unsigned __int64 v76; // x19
  __int64 *v77; // x8
  unsigned int v78; // w10
  __int64 v79; // x9
  unsigned int v80; // w21
  unsigned int v81; // w24
  int v82; // w10
  __int64 v83; // x25
  __int64 v84; // x10
  int *v85; // x26
  unsigned int v87; // w27
  __int64 v88; // x9
  unsigned __int64 v89; // x10
  unsigned int v90; // w8
  int v91; // w8
  unsigned int v92; // w9
  char v93; // w10
  int *v94; // x8
  unsigned __int64 v95; // x24
  __int64 v96; // x8
  __int64 (__fastcall *v97)(_QWORD); // x8
  unsigned int **v98; // x27
  int *v99; // x19
  unsigned int v100; // w21
  __int64 v101; // x28
  __int64 v102; // x11
  int v103; // w8
  __int64 v104; // x23
  unsigned int v105; // w8
  int *v106; // x28
  unsigned int v107; // w21
  __int64 v108; // x19
  int v109; // w8
  __int64 v110; // x27
  int v111; // w8
  unsigned int v112; // w25
  __int64 v113; // x9
  unsigned __int64 v114; // x10
  unsigned int v115; // w8
  int v116; // w8
  char v117; // w10
  int v118; // w8
  unsigned int v119; // w9
  __int64 v120; // x8
  unsigned __int64 v121; // x10
  int v122; // w25
  unsigned int *v123; // x10
  unsigned __int64 *v124; // x8
  __int64 v125; // x11
  __int64 v126; // x12
  _QWORD *v127; // x8
  unsigned int v128; // w26
  int v129; // w11
  __int64 v130; // x11
  unsigned int *v131; // x10
  __int64 v132; // x9
  __int64 v133; // x13
  __int64 v134; // x12
  unsigned int v135; // t1
  __int64 v136; // x9
  int v137; // w8
  char v138; // w9
  __int64 v139; // x8
  __pid_t v140; // w23
  int v141; // w25
  unsigned __int64 v142; // x9
  int v143; // w19
  unsigned __int64 v144; // x10
  unsigned __int64 v145; // x19
  char v146; // w8
  char v147; // w20
  unsigned int v148; // w9
  unsigned int v149; // w27
  unsigned __int64 v150; // x8
  unsigned int v151; // w26
  char v152; // w11
  int v153; // w9
  __int64 v154; // x28
  unsigned int *v155; // x21
  unsigned int v157; // w25
  __int64 v158; // x8
  unsigned __int64 v159; // x9
  __int64 v160; // x6
  char v161; // w0
  unsigned int v162; // w23
  int v163; // w8
  unsigned int v164; // w9
  char v165; // w10
  char v166; // w21
  __int64 v167; // x10
  __int64 v168; // x10
  unsigned int v169; // [xsp+0h] [xbp-60h]
  int v170; // [xsp+4h] [xbp-5Ch]
  __pid_t v171; // [xsp+8h] [xbp-58h]
  __int64 v172; // [xsp+10h] [xbp-50h]
  char v173; // [xsp+1Ch] [xbp-44h]
  int *v174; // [xsp+20h] [xbp-40h]
  unsigned __int64 v175; // [xsp+20h] [xbp-40h]
  struct sched_param param; // [xsp+2Ch] [xbp-34h] BYREF
  int *v177; // [xsp+30h] [xbp-30h] BYREF
  __int64 v178; // [xsp+38h] [xbp-28h]
  __int64 v179; // [xsp+40h] [xbp-20h]
  __int64 v180; // [xsp+48h] [xbp-18h]
  __int64 v181; // [xsp+50h] [xbp-10h]
  __int64 v182; // [xsp+58h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v5 = a1;
  v182 = *(_QWORD *)(StatusReg + 1808);
  v6 = a1[1783];
  v7 = *(_DWORD *)(v3 + 148);
  v8 = *(_DWORD *)(v3 + 1352);
  gen8_crashdump_timedout = 0;
  v9 = *(_QWORD *)(v6 + 192);
  param.__sched_priority = v7;
  gen8_snapshot_block_list = v9;
  if ( (gmu_core_isenabled(a1) & 1) == 0 )
  {
    v10 = *(_QWORD *)(v5[1783] + 192LL);
    v11 = *(unsigned int *)(v10 + 72);
    gen8_snapshot_block_list = v10;
    if ( v11 )
    {
      v12 = *(__int64 **)(v10 + 64);
      do
      {
        v13 = *v12++;
        kgsl_snapshot_add_section(v5, 514, a2, adreno_snapshot_registers_v2, v13);
        --v11;
      }
      while ( v11 );
      v10 = gen8_snapshot_block_list;
    }
    v14 = *(unsigned int **)(v10 + 120);
    if ( (adreno_smmu_is_stalled((__int64)v5) & 1) == 0 )
    {
      v15 = v5[11];
      if ( !v15 )
        goto LABEL_19;
      v16 = *(__int64 (__fastcall **)(_QWORD))(v15 + 16);
      if ( !v16 )
        goto LABEL_19;
      if ( *((_DWORD *)v16 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v16(v5 + 7) & 1) == 0 )
      {
LABEL_19:
        if ( *((_BYTE *)v5 + 11305) == 1
          && gen8_capturescript
          && (unsigned __int64)gen8_capturescript <= 0xFFFFFFFFFFFFF000LL
          && gen8_crashdump_registers
          && (unsigned __int64)gen8_crashdump_registers <= 0xFFFFFFFFFFFFF000LL
          && (gen8_crashdump_timedout & 1) == 0
          && gen8_gmu_rpmh_pwr_state_is_active((__int64)v5)
          && gen8_gmu_gx_is_on((__int64)v5) )
        {
          v17 = *v14;
          v18 = *(_QWORD **)(gen8_capturescript + 8);
          if ( (_DWORD)v17 == -1 )
          {
            v25 = 0;
          }
          else
          {
            v19 = gen8_crashdump_registers;
            v20 = 0;
            v21 = v14 + 2;
            do
            {
              v22 = *(_QWORD *)(v19 + 24) + v20;
              v23 = *(v21 - 1) - (unsigned int)v17 + 1;
              v20 += 4LL * (unsigned int)v23;
              *v18 = v22;
              v18[1] = v23 | (v17 << 44);
              v18 += 2;
              v24 = *v21;
              v21 += 2;
              v17 = v24;
            }
            while ( v24 != -1 );
            v25 = (unsigned int)v20 & 0xFFFFFFFC;
          }
          v167 = gen8_crashdump_registers;
          gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + v25;
          *(_DWORD *)gen8_cd_reg_end = -1431655766;
          v168 = *(_QWORD *)(v167 + 24);
          v18[2] = 0;
          v18[3] = 0;
          *v18 = v168 + v25;
          v18[1] = 0x84500000000001LL;
          result = gen8_do_crashdump(v5);
          if ( (result & 1) == 0 )
            goto LABEL_212;
          v27 = gen8_snapshot_cx_misc_registers;
          v28 = v5;
          v29 = a2;
          v30 = *(unsigned int **)(gen8_snapshot_block_list + 120);
          goto LABEL_26;
        }
      }
    }
    v26 = *(unsigned int **)(gen8_snapshot_block_list + 120);
    if ( (kgsl_regmap_valid_offset(v5 + 1650, *v26) & 1) != 0 )
    {
      v27 = (__int64 (__fastcall *)())adreno_snapshot_registers_v2;
      v28 = v5;
      v29 = a2;
      v30 = v26;
LABEL_26:
      kgsl_snapshot_add_section(v28, 514, v29, v27, v30);
      goto LABEL_29;
    }
    if ( (gen8_cx_misc_regs_snapshot___already_done & 1) == 0 )
    {
      gen8_cx_misc_regs_snapshot___already_done = 1;
      _warn_printk("cx_misc registers are not defined in device tree");
      __break(0x800u);
    }
  }
LABEL_29:
  kgsl_snapshot_add_section(v5, 2305, a2, gen8_snapshot_slice_mask, 0);
  if ( !*((_DWORD *)v5 + 3295) )
  {
    kgsl_regmap_write(v5 + 1650, 4026531840LL);
    kgsl_regmap_write(v5 + 1650, 251658240);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 1985229328);
    kgsl_regmap_write(v5 + 1650, 4275878552LL);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    if ( (kgsl_regmap_valid_offset(v5 + 1650, 99328) & 1) != 0 )
    {
      v31 = gen8_snapshot_block_list;
      if ( *(_QWORD *)(gen8_snapshot_block_list + 56) )
      {
        v32 = 0;
        v33 = 1;
        do
        {
          v34 = 4 * v32;
          kgsl_snapshot_add_section(v5, 2561, a2, gen8_snapshot_cx_dbgc_debugbus_block, *(_QWORD *)(v31 + 48) + 4 * v32);
          kgsl_snapshot_add_section(
            v5,
            6145,
            a2,
            gen8_snapshot_cx_side_dbgc_debugbus_block,
            *(_QWORD *)(gen8_snapshot_block_list + 48) + v34);
          v31 = gen8_snapshot_block_list;
          v32 = v33++;
        }
        while ( *(_QWORD *)(gen8_snapshot_block_list + 56) > v32 );
      }
    }
  }
  result = gen8_gmu_rpmh_pwr_state_is_active((__int64)v5);
  if ( (result & 1) == 0 )
    goto LABEL_212;
  result = gen8_gmu_gx_is_on((__int64)v5);
  if ( (result & 1) == 0 )
    goto LABEL_212;
  v171 = v3;
  v170 = v8;
  WORD2(v177) = 0;
  LODWORD(v177) = 0;
  v36 = kgsl_regmap_read(v5 + 1650);
  v37 = kgsl_regmap_read(v5 + 1650);
  HIWORD(v178) = (unsigned __int8)(v37 | v36);
  HIWORD(v177) = ((v37 | v36) >> 16) & 0x1FF;
  v38 = kgsl_regmap_read(v5 + 1650);
  v39 = kgsl_regmap_read(v5 + 1650);
  v40 = v39 | v37;
  v41 = v38 | v36;
  LOWORD(v179) = (unsigned __int8)(v39 | v38);
  LOWORD(v178) = ((v39 | v38) >> 16) & 0x1FF;
  v42 = kgsl_regmap_read(v5 + 1650);
  v43 = kgsl_regmap_read(v5 + 1650);
  WORD1(v179) = (unsigned __int8)(v43 | v42);
  WORD1(v178) = ((v43 | v42) >> 16) & 0x1FF;
  v44 = kgsl_regmap_read(v5 + 1650);
  v45 = kgsl_regmap_read(v5 + 1650);
  v46 = v41 | v42 | v44;
  WORD2(v179) = (unsigned __int8)(v45 | v44);
  WORD2(v178) = ((v45 | v44) >> 16) & 0x1FF;
  if ( v46 | v40 | v43 | v45 )
  {
    v47 = clk_get(v5[1396] + 16LL, "apb_pclk");
    v48 = v3;
    if ( v47 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(*v5, "Unable to get QDSS clock\n");
    }
    else
    {
      v49 = v47;
      v50 = clk_prepare();
      if ( v50 )
      {
        v68 = v50;
      }
      else
      {
        v51 = clk_enable(v49);
        if ( !v51 )
        {
          resource_byname = (_QWORD *)platform_get_resource_byname(v5[1396], 512, "qdss_etr");
          v53 = platform_get_resource_byname(v5[1396], 512, "qdss_tmc");
          if ( resource_byname )
          {
            v54 = (_QWORD *)v53;
            if ( v53 )
            {
              if ( arm64_use_ng_mappings )
                v55 = 0x68000000000F13LL;
              else
                v55 = 0x68000000000713LL;
              v56 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v55);
              if ( arm64_use_ng_mappings )
                v57 = 0x68000000000F13LL;
              else
                v57 = 0x68000000000713LL;
              v58 = ioremap_prot(*v54, v54[1] - *v54 + 1LL, v57);
              tmc_virt_0 = v58;
              if ( v56 && v58 )
              {
                if ( v46 )
                  v59 = 1;
                else
                  v59 = 2;
                LOWORD(v177) = v59;
                v60 = kgsl_regmap_read(v5 + 1650);
                WORD2(v177) = (v60 >> 12) & 7;
                WORD1(v177) = v60 >> 28;
                v61 = *(_DWORD *)(tmc_virt_0 + 32);
                __dsb(0xDu);
                if ( v61 )
                {
                  v62 = *(_DWORD *)(v56 + 32);
                  __dsb(0xDu);
                  v63 = *(_DWORD *)(v56 + 28704);
                  __dsb(0xDu);
                  if ( !(v62 | v63) )
                    kgsl_snapshot_add_section(v5, 6401, a2, gen8_snapshot_trace_buffer_etb, &v177);
                  v64 = tmc_virt_0;
                  __dsb(0xEu);
                  *(_DWORD *)(v64 + 32) = 0;
                }
                else
                {
                  if ( v46 )
                  {
                    v65 = gen8_snapshot_trace_buffer_gfx_trace;
                    v66 = v5;
                    v67 = a2;
                  }
                  else
                  {
                    v66 = v5;
                    v67 = a2;
                    v65 = nullptr;
                  }
                  kgsl_snapshot_add_section(v66, 6401, v67, v65, &v177);
                }
              }
              iounmap(tmc_virt_0);
              iounmap(v56);
              v48 = v3;
            }
          }
          clk_disable(v49);
          clk_unprepare(v49);
          clk_put(v49);
          goto LABEL_68;
        }
        v68 = v51;
        clk_unprepare(v49);
      }
      dev_err(*v5, "QDSS Clock enable error: %d\n", v68);
      clk_put(v49);
    }
  }
  else
  {
    kgsl_snapshot_add_section(v5, 6401, a2, 0, &v177);
    v48 = v3;
  }
LABEL_68:
  if ( !*((_DWORD *)v5 + 3295) )
  {
    kgsl_regmap_write(v5 + 1650, 4026531840LL);
    kgsl_regmap_write(v5 + 1650, 251658240);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 1985229328);
    kgsl_regmap_write(v5 + 1650, 4275878552LL);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    kgsl_regmap_write(v5 + 1650, 0);
    v69 = (_QWORD *)gen8_snapshot_block_list;
    if ( *(_QWORD *)(gen8_snapshot_block_list + 24) )
    {
      v70 = 0;
      v71 = 1;
      do
      {
        v72 = 4 * v70;
        kgsl_snapshot_add_section(v5, 2561, a2, gen8_snapshot_dbgc_debugbus_block, v69[2] + 4 * v70);
        kgsl_snapshot_add_section(
          v5,
          6145,
          a2,
          gen8_snapshot_dbgc_side_debugbus_block,
          *(_QWORD *)(gen8_snapshot_block_list + 16) + v72);
        v69 = (_QWORD *)gen8_snapshot_block_list;
        v70 = v71++;
      }
      while ( *(_QWORD *)(gen8_snapshot_block_list + 24) > v70 );
    }
    if ( v69[5] )
    {
      v73 = 0;
      v74 = 1;
      do
      {
        v75 = 4 * v73;
        kgsl_snapshot_add_section(v5, 2561, a2, gen8_snapshot_dbgc_debugbus_block, v69[4] + 4 * v73);
        kgsl_snapshot_add_section(
          v5,
          6145,
          a2,
          gen8_snapshot_dbgc_side_debugbus_block,
          *(_QWORD *)(gen8_snapshot_block_list + 32) + v75);
        v69 = (_QWORD *)gen8_snapshot_block_list;
        v73 = v74++;
      }
      while ( *(_QWORD *)(gen8_snapshot_block_list + 40) > v73 );
    }
  }
  v169 = *(_DWORD *)(v48 + 148);
  if ( v169 <= 0x63 )
    sched_set_normal(v48, 0);
  gen8_periph_regread64((__int64)v5, 28677, 0x7006u, (unsigned __int64 *)a2, 1);
  gen8_periph_regread64((__int64)v5, 28681, 0x700Au, (unsigned __int64 *)(a2 + 8), 1);
  gen8_periph_regread64((__int64)v5, 28685, 0x700Eu, (unsigned __int64 *)(a2 + 16), 1);
  gen8_periph_regread((__int64)v5, 28679, (_DWORD *)(a2 + 24), 1);
  gen8_periph_regread((__int64)v5, 28683, (_DWORD *)(a2 + 28), 1);
  gen8_periph_regread((__int64)v5, 28687, (_DWORD *)(a2 + 32), 1);
  if ( (*(_BYTE *)(v5[1783] + 33LL) & 0x40) != 0 )
  {
    gen8_periph_regread64((__int64)v5, 28677, 0x7006u, (unsigned __int64 *)(a2 + 40), 3);
    gen8_periph_regread64((__int64)v5, 28681, 0x700Au, (unsigned __int64 *)(a2 + 48), 3);
    gen8_periph_regread((__int64)v5, 28679, (_DWORD *)(a2 + 56), 3);
    gen8_periph_regread((__int64)v5, 28683, (_DWORD *)(a2 + 60), 3);
  }
  gen8_host_aperture_set((__int64)v5, 0, 0, 0);
  v76 = *((unsigned int *)v5 + 6153);
  kgsl_regmap_write(v5 + 1650, (16 * (*((_DWORD *)v5 + 6153) & 0xF)) | 3u);
  v77 = (__int64 *)gen8_snapshot_block_list;
  if ( *(_QWORD *)(gen8_snapshot_block_list + 8) )
  {
    v78 = __clz(v76);
    v79 = 0;
    v80 = 32 - v78;
    v81 = 0;
    if ( v78 != 31 && v78 != 32 )
      v82 = 32 - v78;
    else
      v82 = 1;
    v83 = (unsigned int)(v82 - 1);
    do
    {
      v84 = *v77;
      v180 = 0;
      v181 = 0;
      v178 = 0;
      v179 = 0;
      v85 = (int *)(v84 + 32 * v79);
      v177 = nullptr;
      if ( *v85 == 1 && (v76 & 1) == 0 )
      {
        v88 = 0;
        while ( v83 != v88 )
        {
          v89 = v76 >> v88;
          v87 = ++v88;
          if ( (v89 & 2) != 0 )
            goto LABEL_94;
        }
      }
      else
      {
        v87 = 0;
LABEL_94:
        if ( v87 < v80 )
        {
LABEL_95:
          v177 = v85;
          if ( *v85 == 1 )
            v90 = v87;
          else
            v90 = 0;
          HIDWORD(v178) = v90;
          kgsl_snapshot_add_section(v5, 5379, a2, gen8_legacy_snapshot_registers, &v177);
          if ( *v85 == 1 )
          {
            v91 = 0;
            v92 = v87;
            while ( 1 )
            {
              v93 = v87 + v91;
              if ( (int)v80 <= (int)(v87 + v91 + 1) )
                break;
              ++v91;
              if ( ((v76 >> v93) & 2) != 0 )
              {
                v87 += v91;
                if ( v80 > v92 + v91 )
                  goto LABEL_95;
                break;
              }
            }
          }
          v77 = (__int64 *)gen8_snapshot_block_list;
        }
      }
      v79 = ++v81;
    }
    while ( v77[1] > (unsigned __int64)v81 );
  }
  v94 = (int *)v77[14];
  v180 = 0;
  v181 = 0;
  v178 = 0;
  v179 = 0;
  v174 = v94;
  v95 = *((unsigned int *)v5 + 6153);
  v177 = nullptr;
  if ( (adreno_smmu_is_stalled((__int64)v5) & 1) != 0 )
    goto LABEL_218;
  v96 = v5[11];
  if ( v96 )
  {
    v97 = *(__int64 (__fastcall **)(_QWORD))(v96 + 16);
    if ( v97 )
    {
      if ( *((_DWORD *)v97 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v97(v5 + 7) & 1) != 0 )
        goto LABEL_218;
    }
  }
  if ( *((_BYTE *)v5 + 11305) != 1
    || !gen8_capturescript
    || (unsigned __int64)gen8_capturescript > 0xFFFFFFFFFFFFF000LL
    || !gen8_crashdump_registers
    || (unsigned __int64)gen8_crashdump_registers > 0xFFFFFFFFFFFFF000LL
    || (gen8_crashdump_timedout & 1) != 0 )
  {
LABEL_218:
    if ( *((_QWORD *)v174 + 1) )
    {
      v105 = __clz(v95);
      v106 = v174;
      v107 = 32 - v105;
      LODWORD(v108) = 0;
      if ( v105 != 31 && v105 != 32 )
        v109 = 32 - v105;
      else
        v109 = 1;
      v110 = (unsigned int)(v109 - 1);
      do
      {
        v111 = *v106;
        v112 = 0;
        if ( *v106 != 1 || (v95 & 1) != 0 )
        {
LABEL_132:
          if ( v112 < v107 )
          {
LABEL_133:
            if ( v111 == 1 )
              v115 = v112;
            else
              v115 = 0;
            v177 = v106;
            HIDWORD(v178) = v115;
            kgsl_snapshot_add_section(v5, 5379, a2, gen8_legacy_snapshot_registers, &v177);
            if ( *v106 == 1 )
            {
              v116 = 0;
              while ( 1 )
              {
                v117 = v112 + v116;
                if ( (int)v107 <= (int)(v112 + v116 + 1) )
                  break;
                ++v116;
                if ( ((v95 >> v117) & 2) != 0 )
                {
                  v112 += v116;
                  v111 = 1;
                  if ( v107 > v112 )
                    goto LABEL_133;
                  break;
                }
              }
            }
          }
        }
        else
        {
          v113 = 0;
          while ( v110 != v113 )
          {
            v114 = v95 >> v113;
            v112 = ++v113;
            if ( (v114 & 2) != 0 )
              goto LABEL_132;
          }
        }
        v108 = (unsigned int)(v108 + 1);
        v106 = &v174[8 * v108];
      }
      while ( *((_QWORD *)v106 + 1) );
    }
  }
  else
  {
    v98 = (unsigned int **)(v174 + 2);
    if ( *((_QWORD *)v174 + 1) )
    {
      v99 = v174;
      v100 = 32 - __clz(v95);
      v101 = 0;
      LODWORD(v102) = 0;
      if ( v100 <= 1 )
        v103 = 1;
      else
        v103 = v100;
      v104 = (unsigned int)(v103 - 1);
      do
      {
        v118 = *v99;
        v119 = 0;
        *((_QWORD *)v99 + 3) = v101;
        if ( v118 != 1 || (v95 & 1) != 0 )
        {
LABEL_149:
          if ( v119 < v100 )
          {
            v122 = v102;
LABEL_151:
            v123 = *v98;
            v124 = *(unsigned __int64 **)(gen8_capturescript + 8);
            *v124 = ((unsigned __int64)(v119 & 7) << 16) | 0x800000;
            v124[1] = 0x81E00000200001LL;
            v125 = *((_QWORD *)v99 + 2);
            if ( v125 )
            {
              v126 = *(unsigned int *)(v125 + 4);
              v124[2] = *(unsigned int *)(v125 + 8);
              v124[3] = (v126 << 44) | 0x200001;
              v127 = v124 + 4;
            }
            else
            {
              v127 = v124 + 2;
            }
            v177 = v99;
            v128 = v119;
            v129 = *v99;
            v181 = v101;
            if ( v129 != 1 )
              v119 = 0;
            HIDWORD(v178) = v119;
            v130 = *v123;
            if ( (_DWORD)v130 != -1 )
            {
              v131 = v123 + 2;
              v132 = gen8_crashdump_registers;
              do
              {
                v133 = *(_QWORD *)(v132 + 24) + v101;
                v134 = *(v131 - 1) - (unsigned int)v130 + 1;
                v101 += 4LL * (unsigned int)v134;
                *v127 = v133;
                v127[1] = v134 | (v130 << 44);
                v127 += 2;
                v135 = *v131;
                v131 += 2;
                v130 = v135;
              }
              while ( v135 != -1 );
            }
            gen8_cd_reg_end = *(_QWORD *)(gen8_crashdump_registers + 8) + (unsigned int)v101;
            *(_DWORD *)gen8_cd_reg_end = -1431655766;
            v136 = *(_QWORD *)(gen8_crashdump_registers + 24);
            v127[3] = 0;
            *v127 = v136 + (unsigned int)v101;
            v127[1] = 0x84500000000001LL;
            v127[2] = 0;
            if ( (gen8_do_crashdump(v5) & 1) == 0 )
            {
              v140 = v171;
              v141 = v170;
              goto LABEL_210;
            }
            kgsl_snapshot_add_section(v5, 5379, a2, gen8_snapshot_registers, &v177);
            if ( *v99 == 1 )
            {
              v137 = 0;
              LODWORD(v102) = v122;
              while ( 1 )
              {
                v138 = v128 + v137;
                if ( (int)v100 <= (int)(v128 + v137 + 1) )
                  break;
                ++v137;
                if ( ((v95 >> v138) & 2) != 0 )
                {
                  v119 = v128 + v137;
                  if ( v100 > v128 + v137 )
                    goto LABEL_151;
                  break;
                }
              }
            }
            else
            {
              LODWORD(v102) = v122;
            }
          }
        }
        else
        {
          v120 = 0;
          while ( v104 != v120 )
          {
            v121 = v95 >> v120;
            v119 = ++v120;
            if ( (v121 & 2) != 0 )
              goto LABEL_149;
          }
        }
        v102 = (unsigned int)(v102 + 1);
        v99 = &v174[8 * v102];
        v98 = (unsigned int **)(v99 + 2);
      }
      while ( *((_QWORD *)v99 + 1) );
    }
  }
  v139 = gen8_snapshot_block_list;
  if ( *(_QWORD *)(gen8_snapshot_block_list + 200) )
  {
    v140 = v171;
    v141 = v170;
    v142 = 0;
    v143 = 1;
    while ( (gen8_snapshot_indexed_registers(
               v5,
               a2,
               *(unsigned int *)(*(_QWORD *)(v139 + 192) + 20 * v142),
               *(unsigned int *)(*(_QWORD *)(v139 + 192) + 20 * v142 + 4),
               *(unsigned int *)(*(_QWORD *)(v139 + 192) + 20 * v142 + 16),
               *(unsigned int *)(*(_QWORD *)(v139 + 192) + 20 * v142 + 12),
               0xFFFFFFFFLL)
           & 1) != 0 )
    {
      v139 = gen8_snapshot_block_list;
      v142 = v143++;
      if ( *(_QWORD *)(gen8_snapshot_block_list + 200) <= v142 )
        goto LABEL_170;
    }
  }
  else
  {
LABEL_170:
    v144 = *(_QWORD *)(v139 + 216);
    v172 = (__int64)v5;
    v145 = *((unsigned int *)v5 + 6153);
    v175 = v144;
    v146 = __clz(__rbit32(v145));
    if ( (_DWORD)v145 )
      v147 = v146;
    else
      v147 = -1;
    if ( v144 )
    {
      v148 = __clz(v145);
      v149 = 32 - v148;
      v150 = 0;
      v151 = 0;
      v152 = 1;
      if ( v148 != 31 && v148 != 32 )
        v153 = 32 - v148;
      else
        v153 = 1;
      v154 = (unsigned int)(v153 - 1);
      do
      {
        while ( 2 )
        {
          v155 = (unsigned int *)(*(_QWORD *)(gen8_snapshot_block_list + 208) + 20 * v150);
          if ( v155[2] == 1 && (v145 & 1) == 0 )
          {
            v158 = 0;
            while ( v154 != v158 )
            {
              v159 = v145 >> v158;
              v157 = ++v158;
              if ( (v159 & 2) != 0 )
                goto LABEL_188;
            }
          }
          else
          {
            v157 = 0;
LABEL_188:
            if ( v157 < v149 )
            {
LABEL_189:
              gen8_host_aperture_set(v172, v155[3], v147, 0);
              kgsl_regmap_rmw(v172 + 13200, 2226, 4, 4);
              gen8_host_aperture_set(v172, v155[3], v157, 1);
              kgsl_regmap_rmw(v172 + 13200, 2963, 4, 4);
              if ( v155[2] == 1 )
                v160 = v157;
              else
                v160 = 0xFFFFFFFFLL;
              v161 = gen8_snapshot_indexed_registers(v172, a2, *v155, v155[1], v155[4], v155[3], v160);
              if ( (v161 & 1) != 0 )
              {
                v173 = v161;
                v162 = v151;
                gen8_host_aperture_set(v172, v155[3], v147, 0);
                kgsl_regmap_rmw(v172 + 13200, 2226, 4, 0);
                gen8_host_aperture_set(v172, v155[3], v157, 1);
                kgsl_regmap_rmw(v172 + 13200, 2963, 4, 0);
                if ( v155[2] == 1 )
                {
                  v163 = 0;
                  v164 = v157;
                  while ( 1 )
                  {
                    v165 = v157 + v163;
                    if ( (int)v149 <= (int)(v157 + v163 + 1) )
                      break;
                    ++v163;
                    if ( ((v145 >> v165) & 2) != 0 )
                    {
                      v157 += v163;
                      v152 = v173;
                      if ( v149 > v164 + v163 )
                        goto LABEL_189;
                      goto LABEL_179;
                    }
                  }
                  v152 = 1;
                  ++v151;
                  v150 = v162 + 1;
                  if ( v175 > v150 )
                    continue;
                  goto LABEL_202;
                }
                v152 = 1;
              }
              else
              {
                v152 = 0;
              }
            }
          }
          break;
        }
LABEL_179:
        v150 = ++v151;
      }
      while ( v175 > v151 );
      v5 = (_QWORD *)v172;
      v166 = v152;
      gen8_host_aperture_set(v172, 0, 0, 0);
      v140 = v171;
      v141 = v170;
      if ( (v166 & 1) == 0 )
        goto LABEL_210;
    }
    else
    {
LABEL_202:
      v5 = (_QWORD *)v172;
      gen8_host_aperture_set(v172, 0, 0, 0);
      v140 = v171;
      v141 = v170;
    }
    if ( (gen8_snapshot_mvc_regs(
            v5,
            a2,
            *(_QWORD *)(gen8_snapshot_block_list + 144),
            *(_QWORD *)(gen8_snapshot_block_list + 152))
        & 1) != 0
      && (gen8_snapshot_mvc_regs(
            v5,
            a2,
            *(_QWORD *)(gen8_snapshot_block_list + 160),
            *(_QWORD *)(gen8_snapshot_block_list + 168))
        & 1) != 0
      && (gen8_snapshot_dbgahb_regs(v5, a2) & 1) != 0
      && (gen8_snapshot_shader(v5, a2) & 1) != 0 )
    {
      kgsl_regmap_write(v5 + 1650, 0);
    }
  }
LABEL_210:
  result = adreno_snapshot_preemption_record(v5, a2);
  if ( v169 <= 0x63 )
    result = sched_setscheduler(v140, v141, &param);
LABEL_212:
  _ReadStatusReg(SP_EL0);
  return result;
}
