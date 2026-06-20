unsigned __int64 __fastcall walt_irq_work(unsigned __int64 result, __int64 a2)
{
  char **v2; // x28
  __int64 v3; // x8
  _QWORD *v4; // x25
  char v5; // w8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x10
  char v10; // w9
  __int64 v11; // x22
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x8
  char *v16; // x11
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x27
  char *v20; // x23
  __int64 v21; // x24
  unsigned __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x26
  char *v25; // x11
  _QWORD *v26; // x14
  _QWORD *v27; // x21
  char *v28; // x20
  char *v29; // x24
  char v30; // w8
  char **v31; // x19
  char v32; // w27
  char *v33; // x4
  char *v34; // x4
  char *v35; // x4
  char *v36; // x4
  _QWORD *v37; // x19
  _QWORD *v38; // x19
  _QWORD *v39; // x9
  _QWORD *v40; // x8
  unsigned __int64 v41; // x11
  unsigned __int64 v42; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v44; // x9
  char *v45; // x8
  int v46; // w19
  const void *v47; // x26
  const void *v48; // x0
  char v49; // w8
  char v50; // w8
  __int64 v51; // x20
  __int64 v52; // x8
  __int64 v53; // x23
  __int64 v54; // x0
  __int64 v55; // x1
  char v56; // w8
  int v57; // w27
  unsigned __int64 v58; // x8
  unsigned __int64 v59; // x19
  __int64 v60; // x8
  unsigned int v61; // w24
  _BYTE *v62; // x8
  int v63; // w8
  char *v64; // x8
  __int64 v65; // x8
  _DWORD *v66; // x26
  __int64 v67; // x1
  char v68; // w26
  __int64 v69; // x8
  _DWORD *v70; // x28
  __int64 v71; // x1
  char v72; // w10
  unsigned __int64 v73; // x8
  unsigned __int64 v74; // x9
  unsigned __int64 v75; // x10
  unsigned __int64 v76; // x10
  char *v77; // x12
  __int64 v78; // x11
  _BYTE *v79; // x11
  unsigned __int64 v80; // x13
  unsigned __int64 v81; // x14
  bool v82; // cf
  unsigned __int64 v83; // x13
  unsigned __int64 v84; // x13
  bool v85; // w14
  unsigned __int64 v86; // x14
  __int64 v87; // x12
  unsigned __int64 v88; // x15
  unsigned __int64 v89; // x12
  unsigned __int64 v90; // x15
  unsigned __int64 v91; // x13
  bool v92; // w12
  __int64 v93; // x0
  __int64 v94; // x10
  char v95; // w9
  __int64 v96; // x8
  __int64 v97; // x3
  unsigned int v98; // w9
  unsigned int v99; // w8
  char *v100; // x9
  unsigned int v101; // w8
  unsigned __int64 v102; // x2
  unsigned int v103; // w23
  int v104; // w4
  int v105; // w4
  __int64 v106; // x5
  unsigned __int64 v107; // x3
  char *v108; // x2
  int v109; // w1
  char *v110; // x2
  char *v111; // x3
  unsigned __int64 v112; // x2
  unsigned __int64 v113; // x4
  unsigned __int64 v114; // x5
  unsigned __int64 v115; // x4
  unsigned __int64 v116; // x5
  bool v117; // zf
  int v118; // w5
  __int64 i; // x9
  __int64 v120; // x11
  char v121; // w12
  unsigned __int64 v122; // x12
  unsigned __int64 v123; // x12
  __int64 v124; // x13
  bool v125; // cc
  char v126; // w10
  int v127; // w8
  __int64 v128; // x9
  unsigned __int64 v129; // x11
  __int64 v130; // x9
  unsigned int v131; // w11
  unsigned int v132; // w20
  unsigned __int64 v133; // x10
  unsigned __int64 v134; // x10
  int v135; // w12
  int v136; // w13
  char v137; // w9
  __int64 v138; // x9
  unsigned __int64 v139; // x22
  char *v140; // x9
  int v141; // w27
  _BYTE *v142; // x8
  __int64 *v143; // x24
  int v144; // w28
  int v145; // w19
  char v146; // w8
  unsigned __int64 v147; // x8
  unsigned __int64 v148; // x20
  __int64 v149; // x8
  char *v150; // x19
  unsigned int v151; // w20
  __int64 *j; // x20
  char v153; // w20
  unsigned __int64 v154; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v156; // x0
  __int64 v157; // x8
  const void *v158; // [xsp+38h] [xbp-68h]
  __int64 v159; // [xsp+40h] [xbp-60h]
  __int64 v160; // [xsp+48h] [xbp-58h]
  int v161; // [xsp+50h] [xbp-50h]
  int v162; // [xsp+54h] [xbp-4Ch]
  _QWORD *v163; // [xsp+58h] [xbp-48h]
  _QWORD *v164; // [xsp+58h] [xbp-48h]
  char *v165; // [xsp+60h] [xbp-40h]
  __int64 v166; // [xsp+68h] [xbp-38h]
  __int64 *v167; // [xsp+70h] [xbp-30h]
  unsigned __int64 v168; // [xsp+78h] [xbp-28h]
  __int64 v169; // [xsp+80h] [xbp-20h]
  int v170; // [xsp+80h] [xbp-20h]
  char *v171; // [xsp+88h] [xbp-18h]
  _QWORD v172[2]; // [xsp+90h] [xbp-10h] BYREF

  v2 = (char **)&_per_cpu_offset;
  v172[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = _cpu_possible_mask;
  v4 = walt_rq;
  v167 = (__int64 *)result;
  v172[0] = _cpu_possible_mask;
  if ( (__int64 *)result != &walt_migration_irq_work )
  {
    v162 = 0;
    goto LABEL_3;
  }
  for ( i = cluster_head; (__int64 *)i != &cluster_head; i = *(_QWORD *)i )
  {
    v120 = *(unsigned int *)(i + 16);
    v121 = 0;
    do
    {
      v122 = v120 & (-1LL << v121);
      if ( !v122 )
        break;
      v123 = __clz(__rbit64(v122));
      v124 = *(unsigned int *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v123) + 3632);
      if ( (unsigned int)v124 >= 0x20 )
        goto LABEL_268;
      if ( (walt_rq[*((_QWORD *)&_per_cpu_offset + v124) + 540] & 1) != 0 )
        goto LABEL_192;
      v125 = v123 > 0x1E;
      v121 = v123 + 1;
    }
    while ( !v125 );
    v3 &= v120 ^ 0xFFFFFFFFLL;
    v172[0] = v3;
LABEL_192:
    ;
  }
  if ( !(_DWORD)v3 )
    goto LABEL_257;
  if ( sched_boost_type )
  {
LABEL_202:
    v162 = 0;
    goto LABEL_263;
  }
  if ( pipeline_nr || (v162 = 0, sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) && have_heavy_list )
  {
    if ( ((unsigned int)v3 & (unsigned int)pipeline_sync_cpus) != 0 )
    {
      v172[0] = pipeline_sync_cpus | v3;
      v162 = 1;
      goto LABEL_263;
    }
    goto LABEL_202;
  }
LABEL_263:
  result = _sw_hweight64((unsigned int)part_haltable_cpus);
  if ( (_DWORD)result
    && (~((unsigned int)_cpu_halt_mask | (unsigned int)_cpu_partial_halt_mask) & (unsigned int)part_haltable_cpus) == 0 )
  {
    v161 = 0;
    goto LABEL_4;
  }
  if ( (v172[0] & (unsigned int)asym_cap_sibling_cpus) != 0 )
  {
    v172[0] |= asym_cap_sibling_cpus;
    v161 = 1;
    goto LABEL_4;
  }
LABEL_3:
  v161 = 0;
LABEL_4:
  v5 = 0;
  do
  {
    v6 = (unsigned int)(-1LL << v5) & v172[0];
    if ( !(_DWORD)v6 )
      break;
    v7 = __clz(__rbit64(v6));
    result = raw_spin_lock((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v7));
    v5 = v7 + 1;
  }
  while ( v7 < 0x1F );
  if ( walt_clock_suspended == 1 )
    goto LABEL_269;
  v165 = (char *)sched_clock(result, a2);
LABEL_9:
  if ( v167 != &walt_migration_irq_work )
    walt_load_reported_window = walt_irq_work_lastq_ws;
  v8 = cluster_head;
  if ( (__int64 *)cluster_head == &cluster_head )
    goto LABEL_79;
  v9 = 0;
  do
  {
    v159 = v8 - 8;
    v160 = v9;
    raw_spin_lock(v8 - 8);
    v10 = 0;
    v11 = 0;
    v166 = v8;
    do
    {
      v17 = *(unsigned int *)(v8 + 16);
      v18 = v17 & (-1LL << v10);
      if ( !v18 )
        break;
      v19 = __clz(__rbit64(v18));
      v20 = (char *)&runqueues + (_QWORD)v2[v19];
      v21 = *((unsigned int *)v20 + 908);
      if ( (unsigned int)v21 >= 0x20 )
        goto LABEL_268;
      v22 = *((_QWORD *)v20 + 418);
      if ( !v22 )
        goto LABEL_22;
      v16 = v2[v21];
      if ( (v17 & v172[0]) == 0 )
        goto LABEL_21;
      v171 = v2[v21];
      if ( !*(_DWORD *)v20 )
      {
        v170 = nr_cpu_ids;
        v46 = (unsigned __int8)walt_clock_suspended;
        v28 = (char *)sched_clock_last;
        v47 = (const void *)return_address(1);
        v48 = (const void *)return_address(2);
        printk_deferred(
          "WALT-BUG %s unlocked cpu=%d is_migration=%d is_asym_migration=%d is_pipeline_sync_migration=%d lock_cpus=%*pbl"
          " suspended=%d last_clk=%llu stack[%pS <= %pS <= %pS]\n",
          "__walt_irq_work_locked",
          v21,
          v167 == &walt_migration_irq_work,
          v161,
          v162,
          v170,
          v172,
          v46,
          v28,
          v158,
          v47,
          v48);
        if ( !in_sched_bug )
          goto LABEL_276;
        v22 = *((_QWORD *)v20 + 418);
      }
      walt_update_task_ravg(v22, v20, 4u, v165, nullptr);
      v23 = *((unsigned int *)v20 + 908);
      if ( (unsigned int)v23 >= 0x20 )
        goto LABEL_268;
      v168 = v19;
      v169 = v11;
      v24 = 0;
      v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      v11 = (__int64)v4 + (_QWORD)v2[v23];
      v20 = *(char **)(v11 + 64);
      v2 = (char **)(v11 + 208);
      v26 = (_QWORD *)(v11 + 152);
      v27 = (_QWORD *)(v11 + 168);
      v28 = (char *)(v11 + 144);
      v29 = &v20[-*(unsigned int *)(v11 + 72)];
      v4 = (_QWORD *)(v11 + 160);
      v30 = 1;
      do
      {
        v31 = &v2[3 * v24];
        v32 = v30;
        if ( *v31 != v20 )
        {
          if ( *v31 != v29 )
            goto LABEL_30;
          v35 = v31[1];
          if ( *v26 < (unsigned __int64)v35 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
          {
            if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
            {
              v164 = v26;
              printk_deferred(
                "WALT-BUG for prev_ws=%llu i=%d wrq->prev_runnable_sum=%llu is lesser than ls[i].subs=%llu",
                v29,
                v24,
                *v26,
                v35);
              v26 = v164;
              v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
              if ( (sysctl_panic_on_walt_bug & 2) != 0 )
                goto LABEL_48;
            }
            else if ( (sysctl_panic_on_walt_bug & 2) != 0 )
            {
LABEL_48:
              if ( !in_sched_bug )
                goto LABEL_274;
            }
          }
          v36 = v31[2];
          if ( *v27 < (unsigned __int64)v36 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
          {
            if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
            {
              v38 = v26;
              printk_deferred(
                "WALT-BUG for prev_ws=%llu i=%d wrq->nt_prev_runnable_sum=%llu is lesser than ls[i].new_subs=%llu",
                v29,
                v24,
                *v27,
                v36);
              v26 = v38;
              v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
              if ( (sysctl_panic_on_walt_bug & 2) == 0 )
                goto LABEL_30;
            }
            else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
            {
              goto LABEL_30;
            }
            if ( !in_sched_bug )
              goto LABEL_275;
          }
          goto LABEL_30;
        }
        v33 = v31[1];
        if ( *(_QWORD *)v28 < (unsigned __int64)v33 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
        {
          if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
          {
            v163 = v26;
            printk_deferred(
              "WALT-BUG for ws=%llu i=%d wrq->curr_runnable_sum=%llu is lesser than ls[i].subs=%llu",
              v20,
              v24,
              *(_QWORD *)v28,
              v33);
            v26 = v163;
            v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            if ( (sysctl_panic_on_walt_bug & 2) == 0 )
              goto LABEL_37;
          }
          else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
          {
            goto LABEL_37;
          }
          if ( !in_sched_bug )
          {
            in_sched_bug = 1;
            walt_dump();
            __break(0x800u);
LABEL_273:
            *((_DWORD *)v25 + 815) = 1;
            walt_dump();
            __break(0x800u);
LABEL_274:
            *((_DWORD *)v25 + 815) = 1;
            walt_dump();
            __break(0x800u);
LABEL_275:
            *((_DWORD *)v25 + 815) = 1;
            walt_dump();
            __break(0x800u);
LABEL_276:
            in_sched_bug = 1;
            walt_dump();
            __break(0x800u);
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                             + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
                & 1) != 0 )
            {
              ++*(_DWORD *)(StatusReg + 16);
              v156 = _traceiter_sched_ravg_window_change(0);
              v157 = *(_QWORD *)(StatusReg + 16) - 1LL;
              *(_DWORD *)(StatusReg + 16) = v157;
              if ( !v157 || !*(_QWORD *)(StatusReg + 16) )
                preempt_schedule_notrace(v156);
            }
LABEL_162:
            sched_ravg_window = v11;
            if ( num_sched_clusters > 0 )
            {
              v98 = __clz(__rbit64(*(unsigned int *)(sched_cluster[0] + 24)));
              if ( *(_DWORD *)(sched_cluster[0] + 24) )
                v99 = v98;
              else
                v99 = 32;
              if ( v99 < 0x20 )
              {
                v100 = v2[v99];
                v101 = (unsigned int)v11 >> 10;
                LODWORD(v100) = ((unsigned int)v11 >> 10) * *(_DWORD *)((char *)&cpu_scale + (_QWORD)v100);
                sched_group_upmigrate = (unsigned int)sysctl_sched_group_upmigrate_pct
                                      * (unsigned __int64)(unsigned int)v100
                                      / 0x64;
                sched_group_downmigrate = (unsigned int)sysctl_sched_group_downmigrate_pct
                                        * (unsigned __int64)(unsigned int)v100
                                        / 0x64;
                goto LABEL_168;
              }
LABEL_268:
              __break(0x5512u);
LABEL_269:
              v165 = (char *)sched_clock_last;
              goto LABEL_9;
            }
            v101 = (unsigned int)v11 >> 10;
LABEL_168:
            walt_scale_demand_divisor = v101;
            sched_init_task_load_windows = ((unsigned __int64)(15 * v11) * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64;
            walt_cpu_high_irqload = (95 * (unsigned __int64)(unsigned int)v11 * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64;
            sched_init_task_load_windows_scaled = sched_init_task_load_windows / v101;
LABEL_169:
            result = raw_spin_unlock_irqrestore(&sched_ravg_window_lock, v20);
            v102 = *((unsigned int *)v28 + 780);
            v103 = 0;
            last_migration_irqwork_ts = (__int64)v165;
            if ( !v102 )
              goto LABEL_187;
            while ( 1 )
            {
              result = __clz(__rbit64(v102));
              v108 = v2[result];
              v109 = *(_DWORD *)((char *)&wakeup_ctr + (_QWORD)v108);
              *(_DWORD *)((char *)&wakeup_ctr + (_QWORD)v108) = 0;
              v110 = v2[result];
              v111 = (char *)v4 + (_QWORD)v110;
              v112 = *(_QWORD *)((char *)&cpu_scale + (_QWORD)v110);
              if ( *((_QWORD *)v111 + 8) <= (unsigned __int64)(walt_core_utilization_timestamp + 1000000000) )
              {
                if ( (unsigned int)result > 8 )
                  goto LABEL_268;
                if ( (_DWORD)result == 8 || result > 7 )
                {
LABEL_186:
                  __break(1u);
LABEL_187:
                  if ( num_sched_clusters < 2 )
                    goto LABEL_242;
                  v126 = 0;
                  v127 = 0;
                  v128 = *(_QWORD *)cpu_array + 8LL * (unsigned int)num_sched_clusters;
                  v129 = *(unsigned int *)(v128 - 16);
                  v130 = *(unsigned int *)(v128 - 8);
                  v117 = v129 == 0;
                  v131 = __clz(__rbit64(v129));
                  if ( v117 )
                    v132 = 32;
                  else
                    v132 = v131;
                  do
                  {
                    v133 = v130 & (-1LL << v126);
                    if ( !v133 )
                      break;
                    v134 = __clz(__rbit64(v133));
                    v135 = *(_DWORD *)((char *)&big_task_pid + (_QWORD)v2[v134]);
                    if ( v127 == v135 )
                      v136 = v127;
                    else
                      v136 = -1;
                    if ( !v127 )
                      v136 = *(_DWORD *)((char *)&big_task_pid + (_QWORD)v2[v134]);
                    if ( v135 )
                      v127 = v136;
                    if ( v135 == -1 )
                      v127 = -1;
                    v82 = v134 >= 0x1F;
                    v126 = v134 + 1;
                  }
                  while ( !v82 );
                  v137 = 0;
                  is_obet = (unsigned int)(v127 - 1) < 0xFFFFFFFE;
                  _ReadStatusReg(SP_EL0);
LABEL_220:
                  v138 = -1LL << v137;
                  if ( ((unsigned int)v138
                      & (unsigned int)*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1))) == 0 )
                    goto LABEL_241;
                  v139 = __clz(
                           __rbit64(
                             (unsigned int)v138
                           & (unsigned int)*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1))));
                  v140 = v2[v139];
                  v141 = *(_DWORD *)((char *)&big_task_pid + (_QWORD)v140);
                  if ( !v141 )
                  {
                    v142 = &force_big_task_pid_eval[(_QWORD)v140];
                    if ( force_big_task_pid_eval[(_QWORD)v140] != 1 )
                      goto LABEL_240;
                  }
                  v143 = *(__int64 **)((char *)&runqueues + (_QWORD)v140 + 3640);
                  if ( v143 == (__int64 *)((char *)&runqueues + (_QWORD)v140 + 3640) )
                  {
                    v141 = 0;
                    goto LABEL_239;
                  }
                  v144 = 0;
                  v145 = 9;
                  while ( 1 )
                  {
                    result = task_fits_max((__int64)(v143 - 32), v132);
                    if ( (result & 1) != 0 )
                    {
                      if ( !v145 )
                        goto LABEL_236;
                    }
                    else
                    {
                      ++v144;
                      v141 = *((_DWORD *)v143 + 386);
                      if ( v144 == 2 || !v145 )
                      {
                        if ( !v145 )
                        {
LABEL_236:
                          v141 = -1;
LABEL_238:
                          v2 = (char **)&_per_cpu_offset;
                          goto LABEL_239;
                        }
LABEL_233:
                        if ( !v144 )
                        {
                          v141 = 0;
                          goto LABEL_238;
                        }
                        v117 = v144 == 1;
                        v2 = (char **)&_per_cpu_offset;
                        if ( !v117 )
                          v141 = -1;
LABEL_239:
                        *(_DWORD *)((char *)&big_task_pid + (_QWORD)v2[v139]) = v141;
                        v142 = &force_big_task_pid_eval[(_QWORD)v2[v139]];
LABEL_240:
                        *v142 = 0;
                        v137 = v139 + 1;
                        if ( v139 >= 0x1F )
                        {
LABEL_241:
                          v4 = walt_rq;
                          goto LABEL_242;
                        }
                        goto LABEL_220;
                      }
                      v144 = 1;
                    }
                    v143 = (__int64 *)*v143;
                    --v145;
                    if ( v143 == (__int64 *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v139) + 3640) )
                      goto LABEL_233;
                  }
                }
                v104 = walt_core_utilization_nr_windows[result] + 1;
              }
              else
              {
                if ( (unsigned int)result > 7 )
                  goto LABEL_268;
                if ( result > 8 )
                  goto LABEL_186;
                v113 = walt_core_utilization_sum[result];
                v114 = walt_core_utilization_nr_windows[result];
                walt_core_utilization_sum[result] = 0;
                walt_core_utilization_nr_windows[result] = 0;
                v115 = v113 / v114;
                v116 = *((unsigned int *)v28 + 780);
                v117 = v116 == 0;
                v118 = 63 - __clz(v116);
                if ( v117 )
                  v118 = 32;
                sysctl_sched_walt_core_util[result] = v115;
                if ( v118 == (_DWORD)result )
                  walt_core_utilization_timestamp = *((_QWORD *)v111 + 8);
                v104 = 1;
                if ( result > 7 )
                  goto LABEL_186;
              }
              walt_core_utilization_nr_windows[result] = v104;
              v105 = *((_DWORD *)v28 + 780);
              v106 = -2LL << result;
              v107 = *((_QWORD *)v111 + 5);
              v103 += v109;
              if ( v112 < v107 )
                v107 = v112;
              v102 = (unsigned int)v106 & v105;
              walt_core_utilization_sum[result] += v107;
              if ( ((unsigned int)v106 & v105) == 0 )
                goto LABEL_187;
            }
          }
        }
LABEL_37:
        v34 = v31[2];
        if ( *v4 < (unsigned __int64)v34 && (sysctl_panic_on_walt_bug & 0xFFFFFF00) == 0x4544DE00 )
        {
          if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
          {
            v37 = v26;
            printk_deferred(
              "WALT-BUG for ws=%llu i=%d wrq->nt_curr_runnable_sum=%llu is lesser than ls[i].new_subs=%llu",
              v20,
              v24,
              *v4,
              v34);
            v26 = v37;
            v25 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
            if ( (sysctl_panic_on_walt_bug & 2) == 0 )
              goto LABEL_30;
          }
          else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
          {
            goto LABEL_30;
          }
          if ( !in_sched_bug )
            goto LABEL_273;
        }
LABEL_30:
        v30 = 0;
        v24 = 1;
      }
      while ( (v32 & 1) != 0 );
      v39 = (_QWORD *)(v11 + 144);
      v40 = (_QWORD *)(v11 + 160);
      if ( *v2 == v20 || (v39 = v26, v40 = (_QWORD *)(v11 + 168), *v2 == v29) )
      {
        v41 = *(_QWORD *)(v11 + 216);
        v42 = *v39 - v41;
        if ( *v39 < v41 )
          v42 = 0;
        *v39 = v42;
        v43 = *(_QWORD *)(v11 + 224);
        v44 = *v40 - v43;
        if ( *v40 < v43 )
          v44 = 0;
        *v40 = v44;
      }
      v45 = *(char **)(v11 + 232);
      v19 = v168;
      v2 = (char **)&_per_cpu_offset;
      *(_QWORD *)(v11 + 216) = 0;
      *(_QWORD *)(v11 + 224) = 0;
      if ( v45 == v20 || (v28 = (char *)v26, v4 = (_QWORD *)(v11 + 168), v45 == v29) )
      {
        v12 = *(_QWORD *)(v11 + 240);
        v13 = *(_QWORD *)v28 - v12;
        if ( *(_QWORD *)v28 < v12 )
          v13 = 0;
        *(_QWORD *)v28 = v13;
        v14 = *(_QWORD *)(v11 + 248);
        v15 = *v4 - v14;
        if ( *v4 < v14 )
          v15 = 0;
        *v4 = v15;
      }
      *(_QWORD *)(v11 + 240) = 0;
      *(_QWORD *)(v11 + 248) = 0;
      v11 = v169;
      v16 = v171;
      v8 = v166;
      v4 = walt_rq;
LABEL_21:
      v11 += *(_QWORD *)((char *)v4 + (_QWORD)v16 + 184);
LABEL_22:
      v10 = v19 + 1;
    }
    while ( v19 < 0x1F );
    raw_spin_unlock(v159);
    *(_QWORD *)(v8 + 56) = v11;
    v8 = *(_QWORD *)v8;
    v9 = v11 + v160;
  }
  while ( (__int64 *)v8 != &cluster_head );
  if ( !v9 )
  {
LABEL_79:
    v50 = 0;
    goto LABEL_80;
  }
  v49 = qword_67BA0;
  if ( qword_67BA0 )
    v49 = *(_BYTE *)(qword_67BA0 + 40);
  v50 = v49 & 1;
LABEL_80:
  rtgb_active = v50;
  if ( v167 != &walt_migration_irq_work && sysctl_sched_user_hint && sched_user_hint_reset_time - jiffies < 0 )
    sysctl_sched_user_hint = 0;
  v51 = cluster_head;
  result = (unsigned __int64)"n";
  if ( (__int64 *)cluster_head != &cluster_head )
  {
    while ( 2 )
    {
      if ( v167 != &walt_migration_irq_work )
      {
        v52 = *(_QWORD *)(v51 + 16);
        goto LABEL_90;
      }
      v52 = *(_QWORD *)(v51 + 16);
      if ( (v172[0] & (unsigned int)v52) != 0 )
      {
LABEL_90:
        v53 = _cpu_online_mask & (unsigned int)v52;
        v54 = _sw_hweight64(v53);
        v56 = 0;
        v57 = v54 - 1;
        do
        {
          v58 = (-1LL << v56) & v53;
          if ( !v58 )
            break;
          v59 = __clz(__rbit64(v58));
          v60 = *(unsigned int *)((char *)&runqueues + (_QWORD)v2[v59] + 3632);
          if ( (unsigned int)v60 > 0x1F )
            goto LABEL_268;
          if ( v167 == &walt_migration_irq_work )
          {
            v62 = &walt_rq[(_QWORD)v2[v60]];
            if ( v62[540] == 1 )
            {
              v62[540] = 0;
              v63 = 4;
            }
            else
            {
              v63 = 0;
            }
            if ( v161 )
              v63 |= 0x40u;
            if ( v162 )
              v61 = v63 | 0x80;
            else
              v61 = v63;
          }
          else
          {
            v61 = 1;
          }
          if ( (walt_rotation_enabled & 1) != 0
            || (sched_freq_aggr_en & 1) == 0
            && sysctl_sched_user_hint
            && *(_QWORD *)(v51 + 56)
            && qword_67BA0
            && (*(_BYTE *)(qword_67BA0 + 40) & 1 | (boost_policy == 1)) != (*(_DWORD *)(v51 + 24) == min_possible_cluster_id)
            && sysctl_sched_user_hint == 1000
            || (v64 = v2[v59], *(_DWORD *)&walt_rq[(_QWORD)v64 + 28]) && (sysctl_walt_features & 1) != 0 )
          {
            v68 = 1;
          }
          else
          {
            if ( v57 )
            {
              v65 = *(unsigned int *)((char *)&runqueues + (_QWORD)v64 + 3632);
              if ( (unsigned int)v65 >= 0x20 )
                goto LABEL_268;
              v4 = *(_QWORD **)((char *)&waltgov_cb_data + (_QWORD)v2[v65]);
              if ( v4 )
              {
                v66 = (_DWORD *)*v4;
                if ( walt_clock_suspended == 1 )
                  v67 = sched_clock_last;
                else
                  v67 = sched_clock(v54, v55);
                if ( *(v66 - 1) != 1756229429 )
                  __break(0x823Au);
                v54 = ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))v66)(v4, v67, v61 | 2);
              }
              goto LABEL_92;
            }
            v68 = 0;
          }
          v69 = *(unsigned int *)((char *)&runqueues + (_QWORD)v2[v59] + 3632);
          if ( (unsigned int)v69 >= 0x20 )
            goto LABEL_268;
          v4 = *(_QWORD **)((char *)&waltgov_cb_data + (_QWORD)v2[v69]);
          if ( v4 )
          {
            v70 = (_DWORD *)*v4;
            if ( walt_clock_suspended == 1 )
              v71 = sched_clock_last;
            else
              v71 = sched_clock(v54, v55);
            if ( *(v70 - 1) != 1756229429 )
              __break(0x823Cu);
            v54 = ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))v70)(v4, v71, v61);
            v2 = (char **)&_per_cpu_offset;
            if ( (v68 & 1) != 0 )
              break;
          }
          else if ( (v68 & 1) != 0 )
          {
            break;
          }
LABEL_92:
          v56 = v59 + 1;
          --v57;
        }
        while ( v59 < 0x1F );
        v4 = walt_rq;
        result = (unsigned __int64)"n";
        if ( v167 != &walt_migration_irq_work )
        {
          v72 = 0;
          v73 = (unsigned int)sched_ravg_window;
          v74 = (unsigned int)walt_cpu_high_irqload;
          while ( 1 )
          {
            v75 = (-1LL << v72) & v53;
            if ( !v75 )
              goto LABEL_86;
            v76 = __clz(__rbit64(v75));
            v77 = (char *)&runqueues + (_QWORD)v2[v76];
            v78 = *((unsigned int *)v77 + 908);
            if ( (unsigned int)v78 >= 0x20 )
              goto LABEL_268;
            v79 = &walt_rq[(_QWORD)v2[v78]];
            v80 = *((_QWORD *)v79 + 12);
            v81 = *((_QWORD *)v79 + 8);
            v82 = v81 >= v80;
            v83 = v81 - v80;
            if ( v83 == 0 || !v82 )
              break;
            v86 = v83 / v73;
            if ( (unsigned int)(v83 / v73) <= 9 )
              goto LABEL_142;
            v84 = 0;
            v85 = 0;
            *((_QWORD *)v79 + 11) = 0;
LABEL_143:
            v87 = *((unsigned int *)v77 + 908);
            if ( (unsigned int)v87 >= 0x20 )
              goto LABEL_268;
            v88 = *((_QWORD *)v79 + 13);
            v89 = *(_QWORD *)((char *)&cpu_irqtime + (_QWORD)v2[v87]);
            v82 = v89 >= v88;
            v90 = v89 - v88;
            *((_QWORD *)v79 + 13) = v89;
            if ( !v82 )
              v90 = 0;
            v91 = v90 + v84;
            *((_QWORD *)v79 + 11) = v91;
            v92 = v91 >= v74 && v85;
            v82 = v76 >= 0x1F;
            v72 = v76 + 1;
            v79[541] = v92;
            if ( v82 )
              goto LABEL_86;
          }
          LODWORD(v86) = 0;
LABEL_142:
          v85 = (unsigned int)v86 < 3;
          v84 = 3LL * (*((_QWORD *)v79 + 11) >> 2) + ((3 * (*((_QWORD *)v79 + 11) & 3uLL)) >> 2);
          *((_QWORD *)v79 + 11) = v84;
          goto LABEL_143;
        }
      }
LABEL_86:
      v51 = *(_QWORD *)v51;
      if ( (__int64 *)v51 == &cluster_head )
        break;
      continue;
    }
  }
  if ( v167 != &walt_migration_irq_work )
  {
    v28 = "n";
    v93 = raw_spin_lock_irqsave(&sched_ravg_window_lock);
    v94 = (unsigned int)new_sched_ravg_window;
    v95 = plenty_giant_tasks | (walt_rotation_stop_hyst_start_ts != 0);
    v96 = *(unsigned int *)((char *)&runqueues + _ReadStatusReg(TPIDR_EL1) + 3632);
    if ( (v95 & 1) != 0 )
      v11 = 8000000;
    else
      v11 = v94;
    if ( (unsigned int)v96 > 0x1F )
      goto LABEL_268;
    v20 = (char *)v93;
    if ( v11 != sched_ravg_window && (unsigned __int64)v165 < *(_QWORD *)((char *)v4 + (_QWORD)v2[v96] + 64) + v11 )
    {
      if ( walt_clock_suspended == 1 )
        v97 = sched_clock_last;
      else
        v97 = sched_clock(v93, (unsigned int)sched_ravg_window);
      sched_ravg_window_change_time = v97;
      goto LABEL_162;
    }
    goto LABEL_169;
  }
  v103 = 0;
  last_rollover_irqwork_ts = (__int64)v165;
LABEL_242:
  v146 = 0;
  do
  {
    v147 = (unsigned int)(-1LL << v146) & v172[0];
    if ( !(_DWORD)v147 )
      break;
    v148 = __clz(__rbit64(v147));
    result = raw_spin_unlock((char *)&runqueues + (_QWORD)v2[v148]);
    v146 = v148 + 1;
  }
  while ( v148 < 0x1F );
  if ( v167 != &walt_migration_irq_work )
  {
    v149 = *(unsigned int *)((char *)&runqueues + _ReadStatusReg(TPIDR_EL1) + 3632);
    if ( (unsigned int)v149 > 0x1F )
      goto LABEL_268;
    v150 = (char *)v4 + (_QWORD)v2[v149];
    v151 = pipeline_check(v150);
    core_ctl_check(*((_QWORD *)v150 + 8), v103);
    result = pipeline_rearrange(v150, v151);
    for ( j = (__int64 *)cluster_head; j != &cluster_head; j = (__int64 *)*j )
      result = ((__int64 (__fastcall *)(__int64 *))update_smart_freq_legacy_reason_hyst_time)(j - 1);
    v153 = is_obet;
    if ( check_obet_set_boost_prev_is_obet != is_obet )
      result = ((__int64 (__fastcall *)(_QWORD, _QWORD))core_ctl_set_cluster_boost)(
                 (unsigned int)(num_sched_clusters - 1),
                 (unsigned __int8)is_obet);
    v154 = *((_QWORD *)v150 + 8);
    check_obet_set_boost_prev_is_obet = v153;
    if ( trailblazer_boost_state_ns + 100000000 < v154 )
      trailblazer_boost_state_ns = 0;
    if ( (now_is_sbt & 1) != 0 )
      goto LABEL_256;
    if ( sbt_boost_ns + 40000000 < v154 )
    {
      v154 = 0;
LABEL_256:
      sbt_boost_ns = v154;
    }
  }
LABEL_257:
  _ReadStatusReg(SP_EL0);
  return result;
}
