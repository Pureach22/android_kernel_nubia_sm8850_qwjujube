__int64 __fastcall aw882xx_device_start(__int64 a1)
{
  __int64 *v2; // x8
  __int64 v3; // x1
  void *v4; // x0
  __int64 v5; // x1
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x1
  void (__fastcall *v16)(__int64, __int64, __int64, __int64); // x8
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 *v20; // x8
  __int64 v21; // x1
  __int64 v22; // x1
  void (__fastcall *v23)(__int64, __int64, __int64, __int64); // x8
  __int64 v24; // x0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 *v27; // x8
  __int64 v28; // x1
  __int64 *v29; // x8
  __int64 v30; // x1
  void *v31; // x0
  int v32; // w1
  __int64 v33; // x1
  void (__fastcall *v34)(__int64, __int64, __int64, __int64); // x8
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 *v38; // x8
  __int64 v39; // x1
  int v40; // w1
  int *v41; // x22
  void (__fastcall *v42)(_QWORD); // x8
  __int64 v43; // x0
  int v44; // w24
  int v45; // w21
  void (__fastcall *v46)(__int64, __int64, unsigned int *); // x8
  __int64 v47; // x0
  __int64 v48; // x1
  __int64 *v49; // x8
  __int64 v50; // x1
  __int64 v51; // x1
  void (__fastcall *v52)(__int64, __int64, __int64, __int64); // x8
  __int64 v53; // x0
  __int64 v54; // x2
  __int64 v55; // x3
  void (__fastcall *v56)(__int64, __int64, __int64, __int64); // x8
  __int64 v57; // x0
  __int64 v58; // x1
  __int64 v59; // x2
  __int64 v60; // x3
  void (__fastcall *v61)(__int64, __int64, __int64, __int64); // x8
  __int64 v62; // x0
  __int64 v63; // x1
  __int64 v64; // x2
  __int64 v65; // x3
  __int64 v66; // x1
  __int64 *v67; // x8
  __int64 v68; // x1
  void (__fastcall *v69)(_QWORD); // x8
  __int64 *v70; // x8
  __int64 v71; // x1
  int v72; // w24
  unsigned int v73; // w20
  _DWORD *v74; // x8
  __int64 v75; // x0
  __int64 *v76; // x8
  __int64 v77; // x1
  __int64 v78; // x1
  void (__fastcall *v79)(__int64, __int64, __int64, __int64); // x8
  __int64 v80; // x0
  __int64 v81; // x2
  __int64 v82; // x3
  __int64 v83; // x1
  __int64 v84; // x1
  __int64 result; // x0
  void (__fastcall *v86)(__int64, __int64, __int64, __int64); // x8
  __int64 v87; // x0
  __int64 v88; // x2
  __int64 v89; // x3
  void (__fastcall *v90)(_QWORD); // x8
  __int64 v91; // x0
  int v92; // w3
  void (__fastcall *v93)(__int64, __int64); // x8
  __int64 v94; // x0
  __int64 v95; // x1
  int v96; // w0
  void (__fastcall *v97)(__int64, __int64, __int64, __int64); // x9
  int v98; // w21
  __int64 v99; // x1
  __int64 v100; // x2
  __int64 v101; // x3
  __int64 v102; // x0
  __int64 *v103; // x8
  int v104; // w24
  unsigned int v105; // w20
  _DWORD *v106; // x8
  __int64 v107; // x0
  __int64 *v108; // x8
  __int64 v109; // x1
  __int64 v110; // x1
  __int64 v111; // x1
  void (__fastcall *v112)(__int64, __int64, __int64, __int64); // x8
  __int64 v113; // x0
  __int64 v114; // x2
  __int64 v115; // x3
  __int64 *v116; // x8
  __int64 v117; // x1
  bool v118; // w0
  unsigned int v119; // w1
  __int64 *v120; // x8
  __int64 v121; // x1
  void (__fastcall *v122)(__int64, __int64, __int64, __int64); // x8
  __int64 v123; // x0
  __int64 v124; // x2
  __int64 v125; // x3
  __int64 *v126; // x8
  __int64 v127; // x1
  void (__fastcall *v128)(__int64, unsigned int *); // x8
  __int64 *v129; // x8
  __int64 v130; // x1
  __int64 v131; // x1
  void (__fastcall *v132)(__int64, __int64, __int64); // x9
  __int64 v133; // x0
  __int64 v134; // x1
  __int64 v135; // x2
  __int64 *v136; // x8
  __int64 v137; // x1
  __int64 *v138; // x8
  __int64 *v139; // x8
  __int64 v140; // x1
  void (__fastcall *v141)(__int64, __int64, __int64, __int64); // x8
  __int64 v142; // x0
  __int64 v143; // x2
  __int64 v144; // x3
  __int64 *v145; // x8
  __int64 v146; // x1
  void (__fastcall *v147)(__int64, __int64, __int64, __int64); // x8
  __int64 v148; // x0
  __int64 v149; // x2
  __int64 v150; // x3
  __int64 *v151; // x8
  __int64 v152; // x1
  unsigned int v153; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v154; // [xsp+8h] [xbp-8h]

  v154 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)a1 == 1 )
  {
    v2 = *(__int64 **)(a1 + 112);
    v3 = v2[14];
    if ( !v3 )
      v3 = *v2;
    v4 = &unk_24076;
LABEL_150:
    printk(v4, v3, "aw882xx_device_start");
    result = 0;
    goto LABEL_151;
  }
  v5 = *(unsigned int *)(a1 + 260);
  if ( (_DWORD)v5 != 255 && *(_DWORD *)(a1 + 276) != 255 )
  {
    v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v7 = *(_QWORD *)(a1 + 120);
    v8 = *(unsigned int *)(a1 + 264);
    v9 = *(unsigned int *)(a1 + 268);
    if ( *((_DWORD *)v6 - 1) != 370515439 )
      __break(0x8228u);
    v6(v7, v5, v8, v9);
    v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v11 = *(_QWORD *)(a1 + 120);
    v12 = *(unsigned int *)(a1 + 276);
    v13 = *(unsigned int *)(a1 + 280);
    v14 = *(unsigned int *)(a1 + 284);
    if ( *((_DWORD *)v10 - 1) != 370515439 )
      __break(0x8228u);
    v10(v11, v12, v13, v14);
  }
  v15 = *(unsigned int *)(a1 + 1000);
  if ( (_DWORD)v15 != 255 )
  {
    v16 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v17 = *(_QWORD *)(a1 + 120);
    v18 = *(unsigned int *)(a1 + 1004);
    v19 = *(unsigned int *)(a1 + 1012);
    if ( *((_DWORD *)v16 - 1) != 370515439 )
      __break(0x8228u);
    v16(v17, v15, v18, v19);
    v20 = *(__int64 **)(a1 + 112);
    v21 = v20[14];
    if ( !v21 )
      v21 = *v20;
    printk(&unk_25B06, v21, "aw_dev_switch");
  }
  v22 = *(unsigned int *)(a1 + 336);
  if ( (_DWORD)v22 != 255 )
  {
    v23 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v24 = *(_QWORD *)(a1 + 120);
    v25 = *(unsigned int *)(a1 + 340);
    v26 = *(unsigned int *)(a1 + 348);
    if ( *((_DWORD *)v23 - 1) != 370515439 )
      __break(0x8228u);
    v23(v24, v22, v25, v26);
    v27 = *(__int64 **)(a1 + 112);
    v28 = v27[14];
    if ( !v28 )
      v28 = *v27;
    printk(&unk_25B06, v28, "aw_dev_switch");
  }
  usleep_range_state(2000, 2010, 2);
  if ( (aw_dev_mode1_pll_check(a1) & 0x80000000) == 0 )
    goto LABEL_32;
  v29 = *(__int64 **)(a1 + 112);
  v30 = v29[14];
  if ( *(_DWORD *)(a1 + 548) != 255 )
  {
    if ( !v30 )
      v30 = *v29;
    printk(&unk_26DCA, v30, "aw_dev_syspll_check");
    v32 = *(_DWORD *)(a1 + 548);
    v153 = 0;
    if ( v32 != 255 )
    {
      v90 = *(void (__fastcall **)(_QWORD))(a1 + 1160);
      v91 = *(_QWORD *)(a1 + 120);
      if ( *((_DWORD *)v90 - 1) != 1983062130 )
        __break(0x8228u);
      v90(v91);
      v92 = *(_DWORD *)(a1 + 556);
      v153 &= ~*(_DWORD *)(a1 + 552);
      if ( v153 == v92 )
        goto LABEL_93;
      v93 = *(void (__fastcall **)(__int64, __int64))(a1 + 1168);
      v94 = *(_QWORD *)(a1 + 120);
      v95 = *(unsigned int *)(a1 + 548);
      if ( *((_DWORD *)v93 - 1) != 370515439 )
        __break(0x8228u);
      v93(v94, v95);
      v96 = aw_dev_mode1_pll_check(a1);
      v97 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
      v98 = v96;
      v99 = *(unsigned int *)(a1 + 548);
      v100 = *(unsigned int *)(a1 + 552);
      v101 = *(unsigned int *)(a1 + 560);
      v102 = *(_QWORD *)(a1 + 120);
      if ( *((_DWORD *)v97 - 1) != 370515439 )
        __break(0x8229u);
      v97(v102, v99, v100, v101);
      if ( v98 || (usleep_range_state(2000, 2010, 2), (aw_dev_mode1_pll_check(a1) & 0x80000000) != 0) )
      {
LABEL_93:
        v103 = *(__int64 **)(a1 + 112);
        v30 = v103[14];
        if ( !v30 )
          v30 = *v103;
        v31 = &unk_23B9B;
        goto LABEL_96;
      }
    }
LABEL_32:
    v33 = *(unsigned int *)(a1 + 360);
    if ( (_DWORD)v33 != 255 )
    {
      v34 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
      v35 = *(_QWORD *)(a1 + 120);
      v36 = *(unsigned int *)(a1 + 364);
      v37 = *(unsigned int *)(a1 + 372);
      if ( *((_DWORD *)v34 - 1) != 370515439 )
        __break(0x8228u);
      v34(v35, v33, v36, v37);
      v38 = *(__int64 **)(a1 + 112);
      v39 = v38[14];
      if ( !v39 )
        v39 = *v38;
      printk(&unk_25B06, v39, "aw_dev_switch");
    }
    usleep_range_state(1000, 1050, 2);
    v40 = *(_DWORD *)(a1 + 1024);
    v41 = (int *)(a1 + 536);
    v153 = 0;
    if ( v40 != 255 )
    {
      v42 = *(void (__fastcall **)(_QWORD))(a1 + 1160);
      v43 = *(_QWORD *)(a1 + 120);
      if ( *((_DWORD *)v42 - 1) != 1983062130 )
        __break(0x8228u);
      v42(v43);
      if ( (v153 & ~*(_DWORD *)(a1 + 1028)) == 0 )
        v41 = (int *)(a1 + 540);
    }
    v44 = *v41;
    v45 = 0;
    while ( 1 )
    {
      v46 = *(void (__fastcall **)(__int64, __int64, unsigned int *))(a1 + 1160);
      v47 = *(_QWORD *)(a1 + 120);
      v48 = *(unsigned int *)(a1 + 528);
      if ( *((_DWORD *)v46 - 1) != 1983062130 )
        __break(0x8228u);
      v46(v47, v48, &v153);
      v49 = *(__int64 **)(a1 + 112);
      v50 = v49[14];
      if ( (v44 & ~*(_DWORD *)(a1 + 532) & v153) == v44 )
        break;
      if ( !v50 )
        v50 = *v49;
      printk(&unk_24772, v50, "aw_dev_sysst_check");
      usleep_range_state(2000, 2010, 2);
      if ( ++v45 == 10 )
      {
        v70 = *(__int64 **)(a1 + 112);
        v71 = v70[14];
        if ( !v71 )
          v71 = *v70;
        printk(&unk_2298D, v71, "aw_dev_sysst_check");
        v72 = *(_DWORD *)(a1 + 28);
        v153 = 0;
        if ( v72 >= 1 )
        {
          v73 = 0;
          do
          {
            v74 = *(_DWORD **)(a1 + 1160);
            v75 = *(_QWORD *)(a1 + 120);
            if ( *(v74 - 1) != 1983062130 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, unsigned int *))v74)(v75, v73, &v153);
            v76 = *(__int64 **)(a1 + 112);
            v77 = v76[14];
            if ( !v77 )
              v77 = *v76;
            printk(&unk_23BC5, v77, "aw_dev_reg_dump");
            ++v73;
          }
          while ( v72 > (unsigned int)(unsigned __int8)v73 );
        }
        v78 = *(unsigned int *)(a1 + 424);
        if ( (_DWORD)v78 == 255 )
        {
          v139 = *(__int64 **)(a1 + 112);
          v140 = v139[14];
          if ( !v140 )
            v140 = *v139;
          printk(&unk_27FF7, v140, "aw_dev_i2s_enable");
        }
        else
        {
          v79 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
          v80 = *(_QWORD *)(a1 + 120);
          v81 = *(unsigned int *)(a1 + 428);
          v82 = *(unsigned int *)(a1 + 436);
          if ( *((_DWORD *)v79 - 1) != 370515439 )
            __break(0x8228u);
          v79(v80, v78, v81, v82);
        }
        aw882xx_dev_clear_int_status(a1);
        v83 = *(unsigned int *)(a1 + 360);
        if ( (_DWORD)v83 != 255 )
        {
          v141 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
          v142 = *(_QWORD *)(a1 + 120);
          v143 = *(unsigned int *)(a1 + 364);
          v144 = *(unsigned int *)(a1 + 368);
          if ( *((_DWORD *)v141 - 1) != 370515439 )
            __break(0x8228u);
          v141(v142, v83, v143, v144);
          v145 = *(__int64 **)(a1 + 112);
          v146 = v145[14];
          if ( !v146 )
            v146 = *v145;
          printk(&unk_25B06, v146, "aw_dev_switch");
        }
        v84 = *(unsigned int *)(a1 + 336);
        if ( (_DWORD)v84 == 255 )
        {
          result = 4294967274LL;
        }
        else
        {
          v147 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
          v148 = *(_QWORD *)(a1 + 120);
          v149 = *(unsigned int *)(a1 + 340);
          v150 = *(unsigned int *)(a1 + 344);
          if ( *((_DWORD *)v147 - 1) != 370515439 )
            __break(0x8228u);
          v147(v148, v84, v149, v150);
          v151 = *(__int64 **)(a1 + 112);
          v152 = v151[14];
          if ( !v152 )
            v152 = *v151;
          printk(&unk_25B06, v152, "aw_dev_switch");
          result = 4294967274LL;
        }
        goto LABEL_151;
      }
    }
    if ( !v50 )
      v50 = *v49;
    printk(&unk_22D82, v50, "aw_dev_sysst_check");
    if ( *(_DWORD *)(a1 + 260) != 255 )
    {
      v51 = *(unsigned int *)(a1 + 276);
      if ( (_DWORD)v51 != 255 )
      {
        v52 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
        v53 = *(_QWORD *)(a1 + 120);
        v54 = *(unsigned int *)(a1 + 280);
        v55 = *(unsigned int *)(a1 + 288);
        if ( *((_DWORD *)v52 - 1) != 370515439 )
          __break(0x8228u);
        v52(v53, v51, v54, v55);
        usleep_range_state(5000, 5050, 2);
        v56 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
        v57 = *(_QWORD *)(a1 + 120);
        v58 = *(unsigned int *)(a1 + 276);
        v59 = *(unsigned int *)(a1 + 280);
        v60 = *(unsigned int *)(a1 + 292);
        if ( *((_DWORD *)v56 - 1) != 370515439 )
          __break(0x8228u);
        v56(v57, v58, v59, v60);
        v61 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
        v62 = *(_QWORD *)(a1 + 120);
        v63 = *(unsigned int *)(a1 + 260);
        v64 = *(unsigned int *)(a1 + 264);
        v65 = *(unsigned int *)(a1 + 272);
        if ( *((_DWORD *)v61 - 1) != 370515439 )
          __break(0x8228u);
        v61(v62, v63, v64, v65);
      }
    }
    v66 = *(unsigned int *)(a1 + 424);
    if ( (_DWORD)v66 == 255 )
    {
      v67 = *(__int64 **)(a1 + 112);
      v68 = v67[14];
      if ( !v68 )
        v68 = *v67;
      printk(&unk_27FF7, v68, "aw_dev_i2s_enable");
      v69 = *(void (__fastcall **)(_QWORD))(a1 + 1200);
      if ( !v69 )
        goto LABEL_112;
    }
    else
    {
      v86 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
      v87 = *(_QWORD *)(a1 + 120);
      v88 = *(unsigned int *)(a1 + 428);
      if ( *(_BYTE *)(a1 + 649) )
        v89 = *(unsigned int *)(a1 + 432);
      else
        v89 = *(unsigned int *)(a1 + 440);
      if ( *((_DWORD *)v86 - 1) != 370515439 )
        __break(0x8228u);
      v86(v87, v66, v88, v89);
      v69 = *(void (__fastcall **)(_QWORD))(a1 + 1200);
      if ( !v69 )
        goto LABEL_112;
    }
    if ( *((_DWORD *)v69 - 1) != -835398270 )
      __break(0x8228u);
    v69(a1);
LABEL_112:
    v111 = *(unsigned int *)(a1 + 408);
    if ( (_DWORD)v111 != 255 )
    {
      v112 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
      v113 = *(_QWORD *)(a1 + 120);
      v114 = *(unsigned int *)(a1 + 412);
      v115 = *(unsigned int *)(a1 + 420);
      if ( *((_DWORD *)v112 - 1) != 370515439 )
        __break(0x8228u);
      v112(v113, v111, v114, v115);
      v116 = *(__int64 **)(a1 + 112);
      v117 = v116[14];
      if ( !v117 )
        v117 = *v116;
      printk(&unk_25B06, v117, "aw_dev_switch");
    }
    if ( *(_DWORD *)(a1 + 40) )
      aw_dev_switch(a1, a1 + 992, 1);
    v118 = aw882xx_cali_check_result(a1 + 648);
    aw882xx_dev_mute(a1, !v118);
    aw882xx_dev_clear_int_status(a1);
    aw882xx_monitor_start(a1 + 672);
    if ( *(_BYTE *)(a1 + 649) )
    {
      v119 = *(_DWORD *)(a1 + 652);
      if ( v119 )
      {
        if ( v119 >= *(_DWORD *)(a1 + 64) && v119 <= *(_DWORD *)(a1 + 60) )
        {
          aw882xx_dsp_write_cali_re(a1);
        }
        else
        {
          v120 = *(__int64 **)(a1 + 112);
          v121 = v120[14];
          if ( !v121 )
            v121 = *v120;
          printk(&unk_25B28, v121, "aw_dev_cali_re_update");
        }
      }
    }
    v128 = *(void (__fastcall **)(__int64, unsigned int *))(a1 + 1216);
    v153 = -1;
    if ( v128 )
    {
      if ( *((_DWORD *)v128 - 1) != 1479983538 )
        __break(0x8228u);
      v128(a1, &v153);
      if ( *(_DWORD *)(a1 + 68) )
      {
        v131 = *(unsigned int *)(a1 + 72);
        v153 = *(_DWORD *)(a1 + 72);
      }
      else
      {
        v131 = v153;
      }
      aw882xx_dsp_write_vol_offset(a1, v131);
    }
    else
    {
      v129 = *(__int64 **)(a1 + 112);
      v130 = v129[14];
      if ( !v130 )
        v130 = *v129;
      printk(&unk_2768C, v130, "aw_dev_vol_offset_update");
    }
    v132 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
    v133 = *(_QWORD *)(a1 + 120);
    v134 = *(unsigned int *)(a1 + 296);
    v135 = *(unsigned int *)(a1 + 308);
    *(_DWORD *)a1 = 1;
    if ( *((_DWORD *)v132 - 1) != -1860236611 )
      __break(0x8229u);
    v132(v133, v134, v135);
    v136 = *(__int64 **)(a1 + 112);
    v137 = v136[14];
    if ( !v137 )
      v137 = *v136;
    printk(&unk_22D82, v137, "aw882xx_dev_set_intmask");
    v138 = *(__int64 **)(a1 + 112);
    v3 = v138[14];
    if ( !v3 )
      v3 = *v138;
    v4 = &unk_22D82;
    goto LABEL_150;
  }
  if ( !v30 )
    v30 = *v29;
  v31 = &unk_2894D;
LABEL_96:
  printk(v31, v30, "aw_dev_syspll_check");
  v104 = *(_DWORD *)(a1 + 28);
  v153 = 0;
  if ( v104 >= 1 )
  {
    v105 = 0;
    do
    {
      v106 = *(_DWORD **)(a1 + 1160);
      v107 = *(_QWORD *)(a1 + 120);
      if ( *(v106 - 1) != 1983062130 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, unsigned int *))v106)(v107, v105, &v153);
      v108 = *(__int64 **)(a1 + 112);
      v109 = v108[14];
      if ( !v109 )
        v109 = *v108;
      printk(&unk_23BC5, v109, "aw_dev_reg_dump");
      ++v105;
    }
    while ( v104 > (unsigned int)(unsigned __int8)v105 );
  }
  v110 = *(unsigned int *)(a1 + 336);
  if ( (_DWORD)v110 == 255 )
  {
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v122 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v123 = *(_QWORD *)(a1 + 120);
    v124 = *(unsigned int *)(a1 + 340);
    v125 = *(unsigned int *)(a1 + 344);
    if ( *((_DWORD *)v122 - 1) != 370515439 )
      __break(0x8228u);
    v122(v123, v110, v124, v125);
    v126 = *(__int64 **)(a1 + 112);
    v127 = v126[14];
    if ( !v127 )
      v127 = *v126;
    printk(&unk_25B06, v127, "aw_dev_switch");
    result = 0xFFFFFFFFLL;
  }
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return result;
}
