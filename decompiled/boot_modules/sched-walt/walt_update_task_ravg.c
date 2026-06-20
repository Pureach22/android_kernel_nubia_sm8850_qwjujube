unsigned __int64 __fastcall walt_update_task_ravg(
        unsigned __int64 result,
        _DWORD *a2,
        unsigned int a3,
        char *a4,
        unsigned int *a5)
{
  unsigned int v5; // w16
  unsigned __int64 v6; // x17
  unsigned int *v7; // x22
  void **v8; // x24
  unsigned __int64 v9; // x26
  unsigned __int64 v10; // x27
  const void *v11; // x30
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x1
  char *v14; // x28
  unsigned __int64 v15; // x21
  unsigned __int64 v16; // x25
  __int64 v17; // x8
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x5
  unsigned __int64 v20; // x19
  unsigned __int64 v21; // x4
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x28
  __int64 v24; // x10
  __int64 v25; // x8
  _QWORD *v26; // x8
  __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x21
  _QWORD *v33; // x8
  _QWORD *v34; // x8
  __int64 v35; // x8
  char *v36; // x19
  __int64 (__fastcall *v37)(_QWORD, unsigned __int64); // x8
  char *v38; // x8
  _DWORD *v39; // x9
  _DWORD *v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  __int64 v43; // x8
  char *v44; // x9
  unsigned __int64 v45; // x8
  __int64 (__fastcall *v46)(_QWORD, unsigned __int64); // x8
  int v48; // w9
  _DWORD *v49; // x9
  unsigned int v50; // w9
  unsigned int v51; // w10
  _DWORD *v52; // x9
  unsigned __int64 v53; // x10
  __int64 v54; // x9
  unsigned __int64 v55; // x8
  unsigned int v56; // w9
  unsigned int v57; // w2
  __int64 v58; // x8
  unsigned __int64 v59; // x8
  __int64 v60; // x9
  unsigned __int64 v61; // x8
  unsigned int v62; // w9
  unsigned int v63; // w8
  __int64 v64; // x30
  __int64 v65; // x2
  char *v66; // x9
  unsigned int v67; // w8
  unsigned __int64 v68; // x6
  __int64 v69; // x10
  __int64 v70; // x10
  void *v71; // x10
  unsigned int *v72; // x12
  int v73; // w13
  unsigned int v74; // w14
  unsigned int v75; // w14
  unsigned int v76; // w13
  unsigned int v77; // w13
  unsigned int v78; // w13
  unsigned int v79; // w13
  unsigned int v80; // w13
  unsigned int v81; // w13
  unsigned int v82; // w12
  unsigned __int64 v83; // x11
  unsigned __int64 v84; // x11
  _QWORD *v85; // x13
  _QWORD *v86; // x14
  _QWORD *v87; // x12
  _QWORD *v88; // x15
  __int64 v89; // x5
  __int64 v90; // x7
  char *v91; // x21
  _QWORD *v92; // x20
  char *v93; // x8
  __int64 v94; // x8
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x8
  __int64 v97; // x9
  unsigned __int64 v98; // x9
  __int64 v99; // x8
  unsigned __int64 v100; // x8
  __int64 v101; // x8
  unsigned __int64 v102; // x9
  unsigned int *v103; // x10
  unsigned __int64 v104; // x9
  unsigned int v105; // w9
  __int64 v106; // x8
  __int64 v107; // x8
  char *v108; // x8
  __int64 v109; // x9
  __int64 v110; // x13
  __int64 v111; // x10
  unsigned int v112; // w12
  __int64 v113; // x14
  unsigned int v114; // w15
  unsigned int v115; // w11
  unsigned int v116; // w16
  bool v117; // zf
  unsigned __int64 v118; // x15
  bool v119; // zf
  unsigned __int64 v120; // x13
  int v121; // w10
  unsigned __int64 v122; // x13
  unsigned __int8 v123; // w12
  unsigned __int64 v124; // x8
  __int64 v125; // x8
  __int64 v126; // x8
  unsigned __int64 v127; // x5
  unsigned __int64 v128; // x20
  unsigned int v129; // w9
  _BOOL4 v130; // w8
  unsigned int v131; // w8
  __int64 v132; // x1
  unsigned __int64 v133; // x27
  unsigned int v134; // w11
  int v135; // w10
  unsigned __int64 v136; // x11
  __int64 v137; // x6
  __int64 v138; // x8
  __int64 v139; // x8
  unsigned __int64 v140; // x8
  unsigned __int64 v141; // x8
  unsigned int v142; // w8
  char *v143; // x0
  unsigned __int64 StatusReg; // x8
  int v145; // w20
  const void *v146; // x0
  char *v147; // x8
  unsigned int v148; // w9
  __int64 v149; // x1
  unsigned __int64 v155; // x9
  unsigned int v156; // w8
  _DWORD **v157; // x19
  _DWORD *v158; // x20
  __int64 v159; // x1
  unsigned __int64 v160; // x20
  __int64 v161; // x8
  int v162; // w8
  unsigned __int64 v163; // x19
  __int64 v164; // x8
  unsigned int v167; // w10
  __int64 v168; // x0
  __int64 v169; // x1
  _QWORD *v170; // [xsp+20h] [xbp-80h]
  char *v171; // [xsp+28h] [xbp-78h]
  unsigned int v172; // [xsp+30h] [xbp-70h]
  __int64 v173; // [xsp+38h] [xbp-68h]
  __int64 v174; // [xsp+38h] [xbp-68h]
  _QWORD *v175; // [xsp+40h] [xbp-60h]
  _QWORD *v176; // [xsp+40h] [xbp-60h]
  _QWORD *v177; // [xsp+48h] [xbp-58h]
  _QWORD *v178; // [xsp+48h] [xbp-58h]
  _QWORD *v179; // [xsp+50h] [xbp-50h]
  _QWORD *v180; // [xsp+50h] [xbp-50h]
  unsigned __int64 v181; // [xsp+58h] [xbp-48h]
  unsigned __int64 v182; // [xsp+58h] [xbp-48h]
  unsigned int v183; // [xsp+64h] [xbp-3Ch]
  _DWORD *v184; // [xsp+68h] [xbp-38h]
  const void *v185; // [xsp+70h] [xbp-30h]
  unsigned __int64 v186; // [xsp+78h] [xbp-28h]
  char *v187; // [xsp+80h] [xbp-20h]
  __int64 v188; // [xsp+88h] [xbp-18h]
  unsigned int v189; // [xsp+94h] [xbp-Ch]
  unsigned __int64 v190; // [xsp+98h] [xbp-8h]

  v12 = (unsigned __int64)a2;
  v13 = (unsigned int)a2[908];
  if ( (unsigned int)v13 >= 0x20 )
    goto LABEL_399;
  v8 = (void **)&_per_cpu_offset;
  v6 = (unsigned __int64)a4;
  a4 = (char *)&walt_rq;
  v14 = (char *)result;
  v15 = (unsigned __int64)&walt_rq + *((_QWORD *)&_per_cpu_offset + (unsigned int)v13);
  if ( (_UNKNOWN *)result == &init_task )
    v7 = (unsigned int *)&vendor_data_pad;
  else
    v7 = (unsigned int *)(result + 5184);
  if ( *(_QWORD *)(v15 + 64) && *((_QWORD *)v7 + 1) != v6 )
  {
    v16 = (unsigned __int64)a5;
    v5 = a3;
    v189 = a3;
    v190 = v6;
    if ( !*(_DWORD *)v12 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v145 = *(_DWORD *)(result + 1800);
      v10 = (unsigned __int8)walt_clock_suspended;
      LODWORD(v20) = 1;
      LODWORD(v187) = *(_DWORD *)(StatusReg + 40);
      v188 = sched_clock_last;
      LODWORD(v184) = v13;
      v185 = v11;
      v9 = return_address(1);
      v146 = (const void *)return_address(2);
      result = printk_deferred(
                 "WALT-BUG CPU%d: %s task %s(%d) unlocked access for cpu=%d suspended=%d last_clk=%llu stack[%pS <== %pS <== %pS]\n",
                 (_DWORD)v187,
                 "walt_update_task_ravg",
                 v14 + 2320,
                 v145,
                 (_DWORD)v184,
                 v10,
                 v188,
                 v185,
                 (const void *)v9,
                 v146);
      v147 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      if ( !in_sched_bug )
      {
LABEL_413:
        *((_DWORD *)v147 + 815) = v20;
        v168 = walt_dump();
        __break(0x800u);
        return update_history(v168, v169);
      }
      v13 = *(unsigned int *)(v12 + 3632);
      v5 = v189;
      a4 = (char *)&walt_rq;
      v6 = v190;
      if ( (unsigned int)v13 >= 0x20 )
        goto LABEL_399;
    }
    v17 = *((_QWORD *)&_per_cpu_offset + (unsigned int)v13);
    v18 = (unsigned __int64)&walt_rq + v17;
    v19 = *(_QWORD *)((char *)&walt_rq + v17 + 616);
    v20 = *(_QWORD *)((char *)&walt_rq + v17 + 64);
    v21 = v20;
    if ( v19 > v6 )
    {
      result = printk_deferred(
                 "WALT-BUG CPU%d; wallclock=%llu(0x%llx) is lesser than latest_clock=%llu(0x%llx)",
                 v13,
                 v6,
                 v6,
                 *(_QWORD *)((char *)&walt_rq + v17 + 616),
                 v19);
      if ( !in_sched_bug )
      {
        in_sched_bug = 1;
        walt_dump();
        __break(0x800u);
        goto LABEL_408;
      }
      v21 = *(_QWORD *)(v18 + 64);
      v5 = v189;
      a4 = (char *)&walt_rq;
      v6 = v190;
    }
    v185 = (const void *)v20;
    v20 = v6 - v21;
    if ( (__int64)(v6 - v21) < 0 )
    {
      result = printk_deferred(
                 "WALT-BUG CPU%d; wallclock=%llu(0x%llx) is lesser than window_start=%llu(0x%llx)",
                 *(_DWORD *)(v12 + 3632),
                 v6,
                 v6,
                 v21,
                 v21);
      v6 = v190;
      v5 = v189;
      a4 = (char *)&walt_rq;
      if ( !in_sched_bug )
      {
        in_sched_bug = 1;
        result = walt_dump();
        __break(0x800u);
        goto LABEL_176;
      }
    }
    a5 = (unsigned int *)&unk_6B000;
    *(_QWORD *)(v18 + 616) = v6;
    v22 = (unsigned int)sched_ravg_window;
    v187 = (char *)v15;
    v188 = (__int64)v14;
    v186 = v16;
    if ( (__int64)v20 >= (unsigned int)sched_ravg_window )
    {
      v23 = v20 / (unsigned int)sched_ravg_window;
      v24 = *(_QWORD *)(v18 + 64);
      *(_DWORD *)(v18 + 72) = sched_ravg_window;
      *(_QWORD *)(v18 + 64) = v24 + (int)(v20 / v22) * v22;
      v25 = *(unsigned int *)(v12 + 3632);
      if ( (unsigned int)v25 >= 0x20 )
        goto LABEL_399;
      v10 = (unsigned __int64)&_per_cpu_offset;
      v26 = (_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v25));
      if ( (int)v23 >= 2 )
      {
        v27 = 0;
        v28 = 0;
        v29 = 0;
        v30 = 0;
      }
      else
      {
        v27 = v26[18];
        v28 = v26[20];
        v29 = v26[22];
        v30 = v26[24];
      }
      v26[18] = 0;
      v26[19] = v27;
      v26[20] = 0;
      v26[21] = v28;
      v26[22] = 0;
      v26[23] = v29;
      v26[24] = 0;
      v26[25] = v30;
      v31 = *(unsigned int *)(v12 + 3632);
      v184 = (_DWORD *)v12;
      if ( (unsigned int)v31 >= 0x20 )
        goto LABEL_399;
      v9 = (unsigned __int64)&walt_rq + *((_QWORD *)&_per_cpu_offset + v31);
      v32 = *(unsigned __int8 *)(v9 + 528);
      v12 = (unsigned int)(1 - v32);
      if ( (unsigned __int8)(1 - v32) > 1u )
        goto LABEL_399;
      v8 = (void **)(v9 + 512);
      v18 = *(unsigned int *)(v9 + 536);
      result = (unsigned __int64)memset(*(void **)(v9 + 512 + 8LL * (unsigned __int8)(1 - v32)), 0, 0x3E8u);
      v20 = v9 + 256;
      v33 = (_QWORD *)(v9 + 256 + ((unsigned __int64)(unsigned __int8)(1 - v32) << 7));
      *v33 = 0;
      v33[1] = 0;
      v33[2] = 0;
      v33[3] = 0;
      v33[4] = 0;
      v33[5] = 0;
      v33[6] = 0;
      v33[7] = 0;
      v33[8] = 0;
      v33[9] = 0;
      v33[10] = 0;
      v33[11] = 0;
      v33[12] = 0;
      v33[13] = 0;
      v33[14] = 0;
      v33[15] = 0x10000000000LL;
      if ( (int)v23 >= 2 )
      {
        if ( (unsigned int)v32 > 1 )
          goto LABEL_399;
        result = (unsigned __int64)memset(v8[v32], 0, 0x3E8u);
        v34 = (_QWORD *)(v20 + (v32 << 7));
        v18 = 0;
        v34[14] = 0;
        v34[15] = 0x10000000000LL;
        *v34 = 0;
        v34[1] = 0;
        v34[2] = 0;
        v34[3] = 0;
        v34[4] = 0;
        v34[5] = 0;
        v34[6] = 0;
        v34[7] = 0;
        v34[8] = 0;
        v34[9] = 0;
        v34[10] = 0;
        v34[11] = 0;
        v34[12] = 0;
        v34[13] = 0;
      }
      *(_BYTE *)(v9 + 528) = 1 - v32;
      v12 = (unsigned __int64)v184;
      v5 = v189;
      *(_DWORD *)(v9 + 532) = v18;
      v8 = (void **)&_per_cpu_offset;
      a4 = (char *)&walt_rq;
      *(_DWORD *)(v9 + 536) = 0;
      v6 = v190;
      v15 = (unsigned __int64)v187;
      v14 = (char *)v188;
      a5 = (unsigned int *)&unk_6B000;
      if ( !v184[908] )
      {
        result = account_yields(v190);
        v6 = v190;
        v5 = v189;
        a5 = (unsigned int *)&unk_6B000;
        a4 = (char *)&walt_rq;
      }
    }
    v10 = *(_QWORD *)(v15 + 656);
    if ( !*((_QWORD *)v7 + 2) )
      *((_QWORD *)v7 + 2) = *(_QWORD *)(v15 + 64);
    v9 = *(unsigned int *)(v12 + 3632);
    v183 = *v7;
    if ( !*((_QWORD *)v7 + 1) )
    {
      if ( use_cycle_counter == 1 )
      {
        if ( (unsigned int)v9 >= 0x20 )
          goto LABEL_399;
        v36 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v9);
        if ( *((_QWORD *)v36 + 68) == v6 )
        {
          *((_QWORD *)v7 + 33) = *((_QWORD *)v36 + 69);
        }
        else
        {
          v46 = (__int64 (__fastcall *)(_QWORD, unsigned __int64))walt_get_cycle_counts_cb;
          if ( *((_DWORD *)walt_get_cycle_counts_cb - 1) != 449908202 )
            __break(0x8228u);
          result = v46((unsigned int)v9, v6);
          v6 = v190;
          v5 = v189;
          a5 = (unsigned int *)&unk_6B000;
          a4 = (char *)&walt_rq;
          *((_QWORD *)v36 + 69) = result;
          *((_QWORD *)v36 + 68) = v190;
          *((_QWORD *)v7 + 33) = result;
        }
      }
      goto LABEL_334;
    }
    if ( (unsigned int)v9 >= 0x20 )
      goto LABEL_399;
    v35 = *((_QWORD *)&_per_cpu_offset + v9);
    v184 = (_DWORD *)v10;
    v14 = (char *)&walt_rq + v35;
    if ( (use_cycle_counter & 1) == 0 )
    {
      *((_QWORD *)v14 + 15) = ((unsigned int)(*(_DWORD *)(*((_QWORD *)v14 + 1) + 40LL) - 1)
                             + *(_QWORD *)((char *)&cpu_scale + v35)
                             * (unsigned __int64)*(unsigned int *)(*((_QWORD *)v14 + 1) + 36LL))
                            / *(unsigned int *)(*((_QWORD *)v14 + 1) + 40LL);
      goto LABEL_47;
    }
    if ( *((_QWORD *)v14 + 68) == v6 )
    {
      result = *((_QWORD *)v14 + 69);
    }
    else
    {
      v37 = (__int64 (__fastcall *)(_QWORD, unsigned __int64))walt_get_cycle_counts_cb;
      if ( *((_DWORD *)walt_get_cycle_counts_cb - 1) != 449908202 )
        __break(0x8228u);
      result = v37((unsigned int)v9, v6);
      v6 = v190;
      v5 = v189;
      a5 = (unsigned int *)&unk_6B000;
      *((_QWORD *)v14 + 69) = result;
      *((_QWORD *)v14 + 68) = v190;
    }
    v38 = *(char **)(v12 + 3344);
    v39 = v38 + 5184;
    _ZF = v38 == (char *)&init_task;
    v40 = &vendor_data_pad;
    if ( !_ZF )
      v40 = v39;
    if ( v16 || (*v40 & 4) == 0 )
    {
      v41 = *((_QWORD *)v7 + 33);
      v18 = result - v41;
      if ( result < v41 )
      {
        v18 = result + ~v41;
        if ( v5 == 5 )
        {
LABEL_42:
          v10 = v16;
          if ( (*(_BYTE *)v7 & 4) != 0 )
            goto LABEL_44;
        }
      }
      else if ( v5 == 5 )
      {
        goto LABEL_42;
      }
      v10 = v6 - *((_QWORD *)v7 + 1);
LABEL_44:
      if ( (v10 & 0x8000000000000000LL) != 0 )
      {
        v20 = result;
        printk_deferred(
          "WALT-BUG pid=%u CPU%d wallclock=%llu(0x%llx) < mark_start=%llu(0x%llx) event=%d irqtime=%llu",
          *(_DWORD *)(v188 + 1800),
          *(_DWORD *)(v12 + 3632),
          v6,
          v6,
          *((_QWORD *)v7 + 1),
          *((_QWORD *)v7 + 1),
          v5,
          v16);
        v6 = v190;
        v5 = v189;
        a5 = (unsigned int *)&unk_6B000;
        result = v20;
        if ( !in_sched_bug )
        {
          in_sched_bug = 1;
          walt_dump();
          __break(0x800u);
          goto LABEL_304;
        }
      }
      v42 = v10 * *(unsigned int *)(*((_QWORD *)v14 + 1) + 40LL);
      *((_QWORD *)v14 + 15) = (v42
                             + *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + v9)) * 1000000 * v18
                             - 1)
                            / v42;
      goto LABEL_46;
    }
    while ( 1 )
    {
LABEL_46:
      a4 = (char *)&walt_rq;
      *((_QWORD *)v7 + 33) = result;
LABEL_47:
      v43 = *(unsigned int *)(v12 + 3632);
      v14 = (char *)v188;
      if ( (unsigned int)v43 >= 0x20 )
        goto LABEL_399;
      v18 = (unsigned __int64)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      v10 = a5[98];
      v44 = (char *)&walt_rq + (_QWORD)v8[v43];
      v45 = *((_QWORD *)v7 + 1);
      v16 = *((_QWORD *)v44 + 8);
      if ( !sched_boost_type )
      {
        if ( pipeline_nr
          || (sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres ? (_ZF = have_heavy_list == 0) : (_ZF = 1),
              _ZF ? (v48 = 0) : (v48 = 1),
              v48) )
        {
          v49 = *((_DWORD **)v7 + 30);
          if ( v49 )
          {
            if ( *v49 == 1 )
              break;
          }
        }
      }
      while ( 1 )
      {
LABEL_49:
        if ( (*(_BYTE *)v7 & 4) != 0 )
          goto LABEL_77;
        if ( v5 == 4 )
        {
          if ( *(char **)(v12 + 3344) != v14 && (!*((_DWORD *)v14 + 36) || v14[273]) )
          {
LABEL_77:
            if ( v16 > v45 )
            {
              result = update_history(v12, v14);
              v6 = v190;
              v5 = v189;
              a5 = (unsigned int *)&unk_6B000;
              a4 = (char *)&walt_rq;
            }
            goto LABEL_98;
          }
        }
        else if ( v5 == 2 || v5 == 1 && *(_QWORD *)(v12 + 3344) == *(_QWORD *)(v12 + 3360) )
        {
          goto LABEL_77;
        }
        v53 = v16 - v45;
        if ( v16 <= v45 )
        {
          v60 = *(unsigned int *)(v12 + 3632);
          if ( (unsigned int)v60 >= 0x20 )
            break;
          v59 = *(_QWORD *)&a4[(_QWORD)v8[v60] + 120] * (v6 - v45);
          goto LABEL_93;
        }
        v54 = *(unsigned int *)(v12 + 3632);
        if ( (unsigned int)v54 >= 0x20 )
          break;
        v9 = v53 / v10;
        v55 = (*(_QWORD *)&a4[(_QWORD)v8[v54] + 120] * (v16 - (v45 + (int)(v53 / v10) * v10))) >> 10;
        if ( v7[84] && *((_QWORD *)v7 + 30) )
          v55 = ((*((_QWORD *)v7 + 43) + 1024LL) * v55) >> 10;
        v56 = a5[98];
        v57 = v7[6] + v55;
        v7[6] = v57;
        if ( v57 > v56 )
          v7[6] = v56;
        result = update_history(v12, v14);
        if ( (_DWORD)v9 )
        {
          if ( *(_DWORD *)(v12 + 3632) >= 0x20u )
            break;
          result = update_history(v12, v14);
        }
        v58 = *(unsigned int *)(v12 + 3632);
        v6 = v190;
        a4 = (char *)&walt_rq;
        if ( (unsigned int)v58 >= 0x20 )
          break;
        v5 = v189;
        a5 = (unsigned int *)&unk_6B000;
        v59 = *(_QWORD *)((char *)&walt_rq + (_QWORD)v8[v58] + 120) * (v190 - v16);
LABEL_93:
        v61 = v59 >> 10;
        if ( v7[84] && *((_QWORD *)v7 + 30) )
          v61 = ((*((_QWORD *)v7 + 43) + 1024LL) * v61) >> 10;
        v62 = a5[98];
        v63 = v7[6] + v61;
        v7[6] = v63;
        if ( v63 > v62 )
          v7[6] = v62;
LABEL_98:
        v16 = *(unsigned int *)(v12 + 3632);
        if ( (unsigned int)v16 >= 0x20 )
          break;
        v9 = *((_QWORD *)v7 + 1);
        v64 = *(_QWORD *)(v12 + 3344);
        v65 = v7[33];
        v13 = 100000000;
        v66 = &a4[(_QWORD)v8[v16]];
        v67 = *v7;
        v10 = *((_QWORD *)v66 + 8);
        v68 = *((unsigned int *)v66 + 18);
        v15 = v10 - v9;
        if ( v10 > v9 )
        {
          if ( (v67 & 4) == 0 )
          {
            v69 = *((unsigned int *)v14 + 10);
            if ( (unsigned int)v69 >= 0x20 )
              break;
            v70 = *(unsigned int *)((char *)&runqueues + (_QWORD)v8[v69] + 3632);
            if ( (unsigned int)v70 > 0x1F )
              break;
            v71 = v8[v70];
            v72 = v7 + 17;
            v73 = nr_cpu_ids;
            if ( v15 >= v68 )
              v74 = 0;
            else
              v74 = v7[33];
            if ( v15 >= v68 )
              v72 = (unsigned int *)&empty_windows;
            v7[33] = 0;
            v7[34] = v74;
            if ( v73 )
            {
              v75 = *v72;
              v7[17] = 0;
              v7[25] = v75;
              if ( v73 != 1 )
              {
                v76 = v72[1];
                v7[18] = 0;
                v7[26] = v76;
                if ( nr_cpu_ids >= 3u )
                {
                  v77 = v72[2];
                  v7[19] = 0;
                  v7[27] = v77;
                  if ( nr_cpu_ids >= 4u )
                  {
                    v78 = v72[3];
                    v7[20] = 0;
                    v7[28] = v78;
                    if ( nr_cpu_ids >= 5u )
                    {
                      v79 = v72[4];
                      v7[21] = 0;
                      v7[29] = v79;
                      if ( nr_cpu_ids >= 6u )
                      {
                        v80 = v72[5];
                        v7[22] = 0;
                        v7[30] = v80;
                        if ( nr_cpu_ids >= 7u )
                        {
                          v81 = v72[6];
                          v7[23] = 0;
                          v7[31] = v81;
                          if ( nr_cpu_ids >= 8u )
                          {
                            v82 = v72[7];
                            v7[24] = 0;
                            v7[32] = v82;
                            if ( nr_cpu_ids > 8u )
                              break;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            v83 = *((_QWORD *)v7 + 21);
            if ( v83 < 0x5F5E100 )
              *((_QWORD *)v7 + 21) = v83 + *(unsigned int *)&a4[(_QWORD)v71 + 72];
          }
          *((_QWORD *)v7 + 2) = v10;
        }
        v84 = *((_QWORD *)v7 + 21);
        if ( (v67 & 4) != 0 )
        {
          if ( v5 == 1 || !v186 && !*(_DWORD *)(v12 + 3504) )
            goto LABEL_218;
        }
        else if ( v5 && v5 != 5 && (v5 != 4 || *(char **)(v12 + 3344) != v14) )
        {
          goto LABEL_218;
        }
        v14 = v66 + 144;
        if ( *((_QWORD *)v7 + 30) )
        {
          v85 = v66 + 176;
          v86 = v66 + 184;
          v87 = v66 + 192;
          v88 = v66 + 200;
        }
        else
        {
          v86 = v66 + 152;
          v87 = v66 + 160;
          v88 = v66 + 168;
          v85 = v66 + 144;
        }
        v89 = *((_QWORD *)v7 + 2);
        v90 = *((_QWORD *)v66 + 8);
        if ( v89 == v90 )
          goto LABEL_139;
        v20 = (unsigned __int64)&unk_68000;
        if ( (unsigned int)sysctl_panic_on_walt_bug >> 8 != 4539614 )
          goto LABEL_139;
        if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
        {
          v171 = (char *)v68;
          v172 = v65;
          v182 = *((_QWORD *)v7 + 21);
          v170 = v87;
          v178 = v86;
          v180 = v85;
          v174 = v64;
          v176 = v88;
          result = printk_deferred(
                     "WALT-BUG CPU%d: %s task %s(%d)'s ws=%llu not equal to rq %d's ws=%llu",
                     *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                     "update_cpu_busy_time",
                     (const char *)(v188 + 2320),
                     *(_DWORD *)(v188 + 1800),
                     v89,
                     *(_DWORD *)(v12 + 3632),
                     v90);
          v64 = v174;
          v88 = v176;
          v86 = v178;
          v85 = v180;
          v13 = 100000000;
          v87 = v170;
          v68 = (unsigned __int64)v171;
          a5 = (unsigned int *)&unk_6B000;
          v84 = v182;
          v65 = v172;
          a4 = (char *)&walt_rq;
          v6 = v190;
          v5 = v189;
          if ( (sysctl_panic_on_walt_bug & 2) == 0 )
            goto LABEL_139;
        }
        else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
        {
          goto LABEL_139;
        }
        result = v188;
        if ( v188 )
        {
          LODWORD(v20) = v65;
          v91 = (char *)v68;
          v181 = v84;
          v92 = v87;
          v177 = v86;
          v179 = v85;
          v173 = v64;
          v175 = v88;
          result = walt_task_dump((unsigned __int64 *)v188);
          v64 = v173;
          v88 = v175;
          v86 = v177;
          v85 = v179;
          v68 = (unsigned __int64)v91;
          v84 = v181;
          v15 = v10 - v9;
          v87 = v92;
          v6 = v190;
          v5 = v189;
          v13 = 100000000;
          v18 = (unsigned __int64)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
          v65 = (unsigned int)v20;
          a5 = (unsigned int *)&unk_6B000;
          a4 = (char *)&walt_rq;
        }
        v93 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
        if ( in_sched_bug )
        {
LABEL_139:
          if ( v10 <= v9 )
          {
            if ( !v186 || (*(_BYTE *)v7 & 4) == 0 || (v96 = v186, *(_DWORD *)(v12 + 3504)) )
              v96 = v6 - v9;
            v97 = *(unsigned int *)(v12 + 3632);
            v14 = (char *)v188;
            if ( (unsigned int)v97 >= 0x20 )
              break;
            v98 = (*(_QWORD *)&a4[(_QWORD)v8[v97] + 120] * v96) >> 10;
            if ( v7[84] && *((_QWORD *)v7 + 30) )
              v98 = ((*((_QWORD *)v7 + 43) + 1024LL) * v98) >> 10;
            *v85 += v98;
            if ( v84 < 0x5F5E100 )
              *v87 += v98;
            v67 = *v7;
            if ( (*v7 & 4) == 0 )
            {
              v7[33] += v98;
              if ( (unsigned int)v16 > 7 )
                break;
              v7[v16 + 17] += v98;
            }
            goto LABEL_218;
          }
          if ( v64 != v188 )
          {
            v94 = *(unsigned int *)(v12 + 3632);
            if ( v15 >= v68 )
            {
LABEL_176:
              v14 = (char *)v188;
              if ( (unsigned int)v94 >= 0x20 )
                break;
              v95 = (*(_QWORD *)&a4[(_QWORD)v8[v94] + 120] * v68) >> 10;
              if ( v7[84] && *((_QWORD *)v7 + 30) )
                v95 = ((*((_QWORD *)v7 + 43) + 1024LL) * v95) >> 10;
              v7[34] = v95;
              if ( (unsigned int)v16 > 7 )
                break;
              v7[v16 + 25] = v95;
            }
            else
            {
              v14 = (char *)v188;
              if ( (unsigned int)v94 >= 0x20 )
                break;
              v95 = (*(_QWORD *)&a4[(_QWORD)v8[v94] + 120] * v15) >> 10;
              if ( v7[84] && *((_QWORD *)v7 + 30) )
                v95 = ((*((_QWORD *)v7 + 43) + 1024LL) * v95) >> 10;
              v7[34] += v95;
              if ( (unsigned int)v16 > 7 )
                break;
              v7[v16 + 25] += v95;
            }
            *v86 += v95;
            if ( v84 < v13 )
              *v88 += v95;
            v101 = *(unsigned int *)(v12 + 3632);
            if ( (unsigned int)v101 >= 0x20 )
              break;
            v102 = (*(_QWORD *)&a4[(_QWORD)v8[v101] + 120] * (v6 - v10)) >> 10;
            if ( v7[84] && *((_QWORD *)v7 + 30) )
              v102 = ((*((_QWORD *)v7 + 43) + 1024LL) * v102) >> 10;
            *v85 += v102;
            if ( v84 < v13 )
              *v87 += v102;
            v103 = &v7[v16];
            v67 = *v7;
            v7[33] = v102;
LABEL_217:
            v103[17] = v102;
            goto LABEL_218;
          }
          if ( v186 && (*(_BYTE *)v7 & 4) != 0 && !*(_DWORD *)(v12 + 3504) )
          {
LABEL_304:
            if ( v10 >= v6 - v186 )
            {
              if ( v10 - (v6 - v186) >= v68 )
                v143 = (char *)v68;
              else
                v143 = (char *)(v10 - (v6 - v186));
              v20 = v6;
              *v86 += scale_exec_time(v143, v12, v7);
              result = scale_exec_time(v20 - v10, v12, v7);
              *(_QWORD *)v14 += result;
            }
            else
            {
              v20 = (unsigned __int64)v85;
              result = scale_exec_time(v186, v12, v7);
              *(_QWORD *)v20 += result;
            }
            v14 = (char *)v188;
            v5 = v189;
            a4 = (char *)&walt_rq;
            a5 = (unsigned int *)&unk_6B000;
          }
          else
          {
            v99 = *(unsigned int *)(v12 + 3632);
            if ( v15 >= v68 )
            {
              v14 = (char *)v188;
              if ( (unsigned int)v99 >= 0x20 )
                break;
              v100 = (*(_QWORD *)&a4[(_QWORD)v8[v99] + 120] * v68) >> 10;
              if ( v7[84] && *((_QWORD *)v7 + 30) )
                v100 = ((*((_QWORD *)v7 + 43) + 1024LL) * v100) >> 10;
              if ( (*(_BYTE *)v7 & 4) == 0 )
              {
                v7[34] = v100;
                if ( (unsigned int)v16 > 7 )
                  break;
                v7[v16 + 25] = v100;
              }
            }
            else
            {
              v14 = (char *)v188;
              if ( (unsigned int)v99 >= 0x20 )
                break;
              v100 = (*(_QWORD *)&a4[(_QWORD)v8[v99] + 120] * v15) >> 10;
              if ( v7[84] && *((_QWORD *)v7 + 30) )
                v100 = ((*((_QWORD *)v7 + 43) + 1024LL) * v100) >> 10;
              if ( (*(_BYTE *)v7 & 4) == 0 )
              {
                v7[34] += v100;
                if ( (unsigned int)v16 > 7 )
                  break;
                v7[v16 + 25] += v100;
              }
            }
            *v86 += v100;
            if ( v84 < 0x5F5E100 )
              *v88 += v100;
            v106 = *(unsigned int *)(v12 + 3632);
            if ( (unsigned int)v106 >= 0x20 )
              break;
            v102 = (*(_QWORD *)&a4[(_QWORD)v8[v106] + 120] * (v6 - v10)) >> 10;
            if ( v7[84] && *((_QWORD *)v7 + 30) )
              v102 = ((*((_QWORD *)v7 + 43) + 1024LL) * v102) >> 10;
            *v85 += v102;
            if ( v84 < 0x5F5E100 )
              *v87 += v102;
            v67 = *v7;
            if ( (*v7 & 4) == 0 )
            {
              v7[33] = v102;
              if ( (unsigned int)v16 > 7 )
                break;
              v103 = &v7[v16];
              goto LABEL_217;
            }
LABEL_218:
            if ( (v67 & 4) == 0 )
            {
              v107 = *(unsigned int *)(v12 + 3632);
              if ( (unsigned int)v107 >= 0x20 )
                break;
              v108 = &a4[(_QWORD)v8[v107]];
              v109 = (unsigned __int8)v108[528];
              if ( (unsigned int)v109 > 1 )
                break;
              v110 = 1 - v109;
              v111 = *(_QWORD *)&v108[8 * v109 + 512];
              v112 = v7[33];
              v6 = v7[34];
              v113 = *(_QWORD *)&v108[8 * (1 - v109) + 512];
              if ( v10 > v9 || v112 != (_DWORD)v65 )
              {
                result = 999;
                v13 = v112 / sched_load_granule;
                if ( (unsigned int)v65 / sched_load_granule >= 0x3E7 )
                  v114 = 999;
                else
                  v114 = (unsigned int)v65 / sched_load_granule;
                if ( (unsigned int)v13 >= 0x3E7 )
                  v115 = 999;
                else
                  v115 = v112 / sched_load_granule;
                if ( v10 <= v9 )
                {
                  v5 = v189;
                  if ( v112 )
                    v119 = (_DWORD)v65 == 0;
                  else
                    v119 = 0;
                  if ( v119 || v114 != v115 )
                  {
                    if ( (_DWORD)v65 )
                      --*(_BYTE *)(v111 + v114);
                    if ( v112 )
                      ++*(_BYTE *)(v111 + v115);
                    if ( (signed int)v115 > *((_DWORD *)v108 + 134) )
                      *((_DWORD *)v108 + 134) = v115;
                  }
                  if ( !*(_BYTE *)(v111 + v114) )
                  {
                    v120 = (unsigned __int64)&v108[128 * v109 + (((unsigned __int64)(999 - v114) >> 3) & 0x78)];
                    *(_QWORD *)(v120 + 256) &= ~(1LL << (-25 - (unsigned __int8)v114));
                  }
                  v121 = *(unsigned __int8 *)(v111 + v115);
LABEL_269:
                  if ( v121 == 1 )
                  {
                    v124 = (unsigned __int64)&v108[128 * v109 + (((unsigned __int64)(999 - v115) >> 3) & 0x78)];
                    *(_QWORD *)(v124 + 256) |= 1LL << (-25 - (unsigned __int8)v115);
                  }
                }
                else
                {
                  v116 = (unsigned int)v6 / sched_load_granule;
                  if ( (unsigned int)v6 / sched_load_granule >= 0x3E7 )
                    v116 = 999;
                  if ( v15 >= v68 )
                  {
                    if ( (_DWORD)v6 )
                    {
                      ++*(_BYTE *)(v113 + v116);
                      *((_DWORD *)v108 + 133) = v116;
                    }
LABEL_263:
                    if ( *(_BYTE *)(v113 + v116) == 1 )
                    {
                      v122 = (unsigned __int64)&v108[128 * v110 + (((unsigned __int64)(999 - v116) >> 3) & 0x78)];
                      *(_QWORD *)(v122 + 256) |= 1LL << (-25 - (unsigned __int8)v116);
                    }
                  }
                  else
                  {
                    if ( (_DWORD)v65 )
                      v117 = 1;
                    else
                      v117 = (_DWORD)v6 == 0;
                    v6 = !v117;
                    if ( v114 != v116 || (_DWORD)v6 )
                    {
                      if ( (_DWORD)v65 )
                        --*(_BYTE *)(v113 + v114);
                      ++*(_BYTE *)(v113 + v116);
                      if ( (signed int)v116 > *((_DWORD *)v108 + 133) )
                        *((_DWORD *)v108 + 133) = v116;
                      v6 = *(unsigned __int8 *)(v113 + v114);
                      if ( !*(_BYTE *)(v113 + v114) )
                      {
                        v118 = 999 - v114;
                        v6 = (unsigned __int64)&v108[128 * v110 + ((v118 >> 3) & 0x78)];
                        result = *(_QWORD *)(v6 + 256);
                        *(_QWORD *)(v6 + 256) = result & ~(1LL << v118);
                      }
                      goto LABEL_263;
                    }
                  }
                  v5 = v189;
                  if ( v112 )
                  {
                    v123 = *(_BYTE *)(v111 + v115) + 1;
                    *(_BYTE *)(v111 + v115) = v123;
                    if ( (signed int)v115 > *((_DWORD *)v108 + 134) )
                    {
                      *((_DWORD *)v108 + 134) = v115;
                      v123 = *(_BYTE *)(v111 + v115);
                    }
                    v121 = v123;
                    goto LABEL_269;
                  }
                }
              }
            }
          }
          if ( !(v5 & 0xFFFFFFFB | (4 * ((*v7 >> 2) & 1))) && (v5 != 4 || *((_DWORD *)v14 + 36) && !v14[273]) )
          {
            v65 = v7[33] / walt_scale_demand_divisor;
            if ( *((unsigned __int16 *)v7 + 80) < (unsigned int)(unsigned __int16)v65 )
            {
              v131 = (unsigned __int16)v65 >> 6;
              if ( v131 >= 0xF )
                v131 = 15;
              if ( (v65 & 0xFFC0) != 0 )
                v132 = v131;
              else
                v132 = 1;
              result = get_pred_busy(v14, v132);
              if ( *((_DWORD *)v14 + 36) == 1 && !v14[273] )
              {
                LODWORD(v9) = result;
                fixup_walt_sched_stats_common(v12, v14, *((unsigned __int16 *)v7 + 79), (unsigned int)result);
                result = (unsigned int)v9;
              }
              v5 = v189;
              a4 = (char *)&walt_rq;
              a5 = (unsigned int *)&unk_6B000;
              *((_WORD *)v7 + 80) = result;
            }
          }
          v125 = *((unsigned int *)v14 + 10);
          if ( (unsigned int)v125 >= 0x20 )
            break;
          v6 = v190;
          v9 = (unsigned __int64)&a4[(_QWORD)v8[v125]];
          v126 = 4000000;
          if ( a5[98] > 0x7A1200 )
            v126 = 8000000;
          if ( v126 + *(_QWORD *)(v9 + 656) < v190 )
            *(_QWORD *)(v9 + 656) = 0;
          if ( *(_DWORD *)(v18 + 3428)
            || !pipeline_nr && (!(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) || !have_heavy_list)
            || v7[91] == -1 )
          {
            goto LABEL_330;
          }
          v127 = *((_QWORD *)v7 + 1);
          if ( v127 > v190 )
          {
            result = printk_deferred(
                       "WALT-BUG CPU%d: %s task %s(%d) mark_start %llu is higher than wallclock %llu\n",
                       *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                       "update_busy_bitmap",
                       v14 + 2320,
                       *((_DWORD *)v14 + 450),
                       v127,
                       v190);
            if ( !in_sched_bug )
            {
              in_sched_bug = 1;
              walt_dump();
              __break(0x800u);
              goto LABEL_413;
            }
            v127 = *((_QWORD *)v7 + 1);
            v5 = v189;
            a4 = (char *)&walt_rq;
            v6 = v190;
            a5 = (unsigned int *)&unk_6B000;
            v128 = v127;
            v129 = *v7;
            if ( (*v7 & 4) != 0 )
              goto LABEL_308;
LABEL_284:
            if ( !v5 || v5 == 5 )
            {
              v130 = 1;
            }
            else
            {
              if ( v5 != 4 )
                goto LABEL_309;
              v130 = *(_QWORD *)(v12 + 3344) == (_QWORD)v14;
            }
          }
          else
          {
            v128 = v190;
            v129 = *v7;
            if ( (*v7 & 4) == 0 )
              goto LABEL_284;
LABEL_308:
            if ( v5 == 1 )
LABEL_309:
              v130 = 0;
            else
              v130 = *(_DWORD *)(v12 + 3504) != 0;
          }
          if ( !*((_DWORD *)v14 + 36) || v14[273] )
            *v7 = v129 & 0xFFFFFFF7;
          v133 = 1000000 * ((v127 + 999999) / 0xF4240);
          if ( v128 < v133 )
          {
            if ( v130 )
              v7[98] += v128 - v127;
            goto LABEL_330;
          }
          if ( v130 )
            v134 = v7[98] + v133 - v127;
          else
            v134 = v7[98];
          v7[98] = 0;
          LOWORD(v135) = (v134 > 0x7A120) | (unsigned __int16)(2 * *((_WORD *)v7 + 194));
          v136 = (v128 - v133) / 0xF4240;
          *((_WORD *)v7 + 194) = v135;
          if ( (_DWORD)v136 )
          {
            if ( (int)v136 >= 16 )
              LOBYTE(v136) = 16;
            v135 = (unsigned __int16)v135 << v136;
            if ( v130 )
            {
              v135 |= ~(-1 << v136);
              *((_WORD *)v7 + 194) = v135;
              goto LABEL_326;
            }
            *((_WORD *)v7 + 194) = v135;
          }
          else if ( v130 )
          {
LABEL_326:
            v7[98] = v128 % 0xF4240;
          }
          if ( !*((_DWORD *)v14 + 36) || v14[273] )
            goto LABEL_330;
          v142 = a5[98];
          if ( v142 >= 0x7A1201 )
          {
LABEL_351:
            if ( v142 != 12000000 )
              goto LABEL_354;
            result = _sw_hweight16(v7[97] & 0xFFF, v13, v65, a4);
            if ( HIDWORD(sysctl_sched_lrpb_active_ms) - 1 < (unsigned int)result )
            {
              a5 = (unsigned int *)&unk_6B000;
              v5 = v189;
              v6 = v190;
              v142 = sched_ravg_window;
              a4 = (char *)&walt_rq;
LABEL_354:
              if ( v142 < 0xF42400
                || (result = _sw_hweight16(*((unsigned __int16 *)v7 + 194), v13, v65, a4),
                    v6 = v190,
                    v5 = v189,
                    a5 = (unsigned int *)&unk_6B000,
                    a4 = (char *)&walt_rq,
                    dword_68B34 - 1 < (unsigned int)result) )
              {
                if ( !*(_QWORD *)(v9 + 656) )
                {
                  *v7 |= 8u;
                  *(_QWORD *)(v9 + 656) = v128;
                }
              }
              goto LABEL_330;
            }
          }
          else
          {
            result = _sw_hweight16((unsigned __int8)v135, v13, v65, a4);
            if ( (int)sysctl_sched_lrpb_active_ms - 1 < (unsigned int)result )
            {
              a5 = (unsigned int *)&unk_6B000;
              v5 = v189;
              v6 = v190;
              v142 = sched_ravg_window;
              a4 = (char *)&walt_rq;
              goto LABEL_351;
            }
          }
          v5 = v189;
          v6 = v190;
          a4 = (char *)&walt_rq;
          a5 = (unsigned int *)&unk_6B000;
          while ( 1 )
          {
LABEL_330:
            if ( !v5 && *((_DWORD *)v14 + 12) )
              *((_BYTE *)v7 + 272) = (v14[1728] & 8) != 0;
            v18 = (unsigned __int64)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            v10 = (unsigned __int64)v184;
            v15 = (unsigned __int64)v187;
LABEL_334:
            v137 = *((_QWORD *)v7 + 2);
            v138 = a5[98];
            *((_QWORD *)v7 + 1) = v6;
            if ( v137 + v138 >= v6 || (unsigned int)sysctl_panic_on_walt_bug >> 8 != 4539614 )
              break;
            if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
            {
              result = printk_deferred(
                         "WALT-BUG CPU%d: %s task %s(%d)'s ms=%llu is ahead of ws=%llu by more than 1 window on rq=%d event=%d",
                         *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
                         "walt_update_task_ravg",
                         v14 + 2320,
                         *((_DWORD *)v14 + 450),
                         v6,
                         v137,
                         *(_DWORD *)(v12 + 3632),
                         v5);
              a4 = (char *)&walt_rq;
              if ( (sysctl_panic_on_walt_bug & 2) == 0 )
                break;
            }
            else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
            {
              break;
            }
            if ( v14 )
            {
              result = walt_task_dump((unsigned __int64 *)v14);
              a4 = (char *)&walt_rq;
            }
            if ( in_sched_bug )
              break;
            in_sched_bug = 1;
            result = walt_dump();
            __break(0x800u);
            v163 = _ReadStatusReg(SP_EL0);
            if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                             + (((unsigned __int64)*(unsigned int *)(v163 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v163 + 40))
                & 1) != 0 )
            {
              ++*(_DWORD *)(v163 + 16);
              result = _traceiter_sched_update_busy_bitmap(0, v14, v12, v7, v9, v5, v18, v10, v162);
              v6 = v190;
              v5 = v189;
              a5 = (unsigned int *)&unk_6B000;
              a4 = (char *)&walt_rq;
              v164 = *(_QWORD *)(v163 + 16) - 1LL;
              *(_DWORD *)(v163 + 16) = v164;
              if ( !v164 || !*(_QWORD *)(v163 + 16) )
              {
                result = preempt_schedule_notrace(result);
                v6 = v190;
                v5 = v189;
                a5 = (unsigned int *)&unk_6B000;
                a4 = (char *)&walt_rq;
              }
            }
          }
          v139 = *(unsigned int *)(v12 + 3632);
          if ( (unsigned int)v139 < 0x20 )
          {
            v140 = *(_QWORD *)&a4[(_QWORD)v8[v139] + 64];
            if ( (const void *)v140 != v185 )
            {
              _X10 = &walt_irq_work_lastq_ws;
              __asm { PRFM            #0x11, [X10] }
              while ( 1 )
              {
                v155 = __ldxr((unsigned __int64 *)&walt_irq_work_lastq_ws);
                if ( v155 != (unsigned __int64)v185 )
                  break;
                if ( !__stlxr(v140, (unsigned __int64 *)&walt_irq_work_lastq_ws) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              if ( (const void *)v155 == v185 )
              {
                v141 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
                if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v141 >> 3) & 0x1FFFFFF8)) >> v141) & 1) != 0 )
                  return irq_work_queue(&walt_cpufreq_irq_work);
                v148 = __clz(__rbit64(_cpu_online_mask));
                if ( _cpu_online_mask )
                  v149 = v148;
                else
                  v149 = 32;
                return irq_work_queue_on(&walt_cpufreq_irq_work, v149);
              }
            }
            if ( v7[91] == -1
              || (v156 = *((_DWORD *)v14 + 10), v156 != *(_DWORD *)(v12 + 3632))
              || (v183 & 8) != 0
              || (*(_BYTE *)v7 & 8) == 0 )
            {
              if ( !v10 || *(_QWORD *)(v15 + 656) )
                return result;
              v156 = *(_DWORD *)(v12 + 3632);
            }
            if ( v156 < 0x20 )
            {
              v157 = *(_DWORD ***)((char *)&waltgov_cb_data + (_QWORD)v8[v156]);
              if ( v157 )
              {
                v158 = *v157;
                if ( walt_clock_suspended == 1 )
                  v159 = sched_clock_last;
                else
                  v159 = sched_clock(result, v13);
                if ( *(v158 - 1) != 1756229429 )
                  __break(0x8234u);
                return ((__int64 (__fastcall *)(_DWORD **, __int64, __int64))v158)(v157, v159, 2048);
              }
              return result;
            }
          }
          break;
        }
LABEL_408:
        *((_DWORD *)v93 + 815) = 1;
        result = walt_dump();
        __break(0x800u);
LABEL_409:
        _X9 = v7 + 110;
        __asm { PRFM            #0x11, [X9] }
        do
          v167 = __ldxr(_X9);
        while ( __stxr(v167 + 1, _X9) );
      }
LABEL_399:
      __break(0x5512u);
      v20 = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v20 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v20 + 40))
          & 1) != 0 )
      {
        v160 = result;
        ++*(_DWORD *)(v20 + 16);
        result = _traceiter_sched_get_task_cpu_cycles(0, (unsigned int)v9, v5, a4, v10, v188);
        v6 = v190;
        v5 = v189;
        a5 = (unsigned int *)&unk_6B000;
        v161 = *(_QWORD *)(v20 + 16) - 1LL;
        *(_DWORD *)(v20 + 16) = v161;
        if ( !v161 || (result = v160, !*(_QWORD *)(v20 + 16)) )
        {
          preempt_schedule_notrace(result);
          v6 = v190;
          v5 = v189;
          a5 = (unsigned int *)&unk_6B000;
          result = v160;
        }
      }
    }
    if ( v45 && 3 * v10 + v45 < v6 )
    {
      v50 = v7[106];
      v7[106] = v50 + 1;
      v51 = (v50 + 6) / 5;
      if ( v51 >= 0xA )
        v51 = 10;
      *((_BYTE *)v7 + 432) = 1;
      *((_QWORD *)v7 + 52) = 250000000 * v51 + v6;
      v52 = v7 + 107;
    }
    else
    {
      v104 = *((_QWORD *)v7 + 52);
      if ( v104 && v104 < v6 )
      {
        *((_BYTE *)v7 + 432) = 0;
        *((_QWORD *)v7 + 52) = 0;
      }
      v105 = v7[107] + 1;
      v7[107] = v105;
      if ( v105 < 0xB )
      {
LABEL_197:
        if ( v16 <= v45 )
          goto LABEL_49;
        goto LABEL_409;
      }
      v52 = v7 + 107;
      v7[106] -= 10;
    }
    *v52 = 0;
    goto LABEL_197;
  }
  return result;
}
