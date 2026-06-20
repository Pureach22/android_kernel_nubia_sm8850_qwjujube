void walt_init()
{
  __int64 v0; // x22
  __int64 *v1; // x25
  unsigned __int64 j; // x26
  __int64 v3; // x28
  _QWORD *v4; // x21
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 i; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  char v16; // w8
  __int64 v17; // x27
  char *v18; // x17
  unsigned __int64 v19; // x20
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x15
  char *v23; // x8
  _DWORD *v24; // x8
  int v25; // t1
  char v26; // w9
  unsigned __int64 v31; // x11
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x9
  __int64 v35; // x0
  __int64 *v36; // x8
  unsigned __int64 v37; // x10
  int v38; // w9
  char v39; // w11
  unsigned __int64 v40; // x11
  unsigned __int64 v41; // x11
  __int64 v42; // x12
  __int64 *v43; // x2
  __int64 *v44; // x1
  unsigned int v45; // w11
  unsigned int v46; // w10
  int v47; // w12
  unsigned int v48; // w11
  int v49; // w9
  __int64 v50; // x0
  __int64 v51; // x9
  char v52; // w8
  __int64 v53; // x0
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  __int64 v56; // x10
  _QWORD *v57; // x8
  __int64 v58; // x10
  int v59; // w8
  __int64 v60; // x10
  __int64 *v61; // x8
  __int64 *v62; // x11
  unsigned __int64 v63; // x15
  int v64; // w12
  unsigned __int64 v65; // x16
  __int64 *v66; // x9
  __int64 *v67; // x10
  unsigned int v68; // w16
  unsigned int v69; // w10
  unsigned int v70; // w15
  unsigned int v71; // w9
  __int64 *v72; // x12
  __int64 v73; // x8
  __int64 *v74; // x1
  __int64 v75; // x8
  __int64 **v76; // x8
  __int64 *v77; // x2
  __int64 **v78; // x8
  __int64 *v79; // x8
  __int64 *v80; // x8
  __int64 *v81; // x8
  __int64 *v82; // x8
  __int64 *v83; // x8
  __int64 *v84; // x8
  __int64 *v85; // x8
  __int64 v86; // x8
  __int64 v87; // x19
  unsigned int v88; // w9
  __int64 v89; // x0
  __int64 raw; // x0
  char v91; // w8
  unsigned __int64 v92; // x8
  unsigned __int64 v93; // x8
  __int64 v94; // x9
  int v95; // w8
  __int64 *v96; // x8
  __int64 v97; // x8
  unsigned __int64 v98; // x9
  unsigned __int64 v99; // x10
  int v100; // w15
  unsigned int v101; // w14
  int v102; // w15
  unsigned __int64 v103; // x14
  unsigned int v104; // w9
  unsigned int v105; // w8
  unsigned int v106; // w8
  __int64 v107; // x0
  _QWORD *v108; // x19
  int v109; // w8
  __int64 v110; // x0
  int v111; // w1
  unsigned int v112; // w9
  unsigned __int64 v113; // x8
  __int64 v114; // x9
  int v115; // w10
  __int64 v116; // x11
  __int64 v117; // x14
  unsigned __int64 v118; // x15
  unsigned __int64 v119; // x15
  char v120; // w8
  unsigned __int64 v121; // x8
  __int64 cpu_node; // x0
  __int64 v123; // x24
  char v124; // w8
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x21
  __int64 v127; // x0
  int v128; // w0
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x19
  unsigned int v132; // w9
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 node_opts_by_path; // x0
  __int64 v136; // x0
  char *v137; // x8
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x0
  unsigned int matched; // w0
  char v144; // w19
  unsigned int v147; // w8
  int *v148; // [xsp+10h] [xbp-80h]
  unsigned __int64 v149; // [xsp+18h] [xbp-78h]
  __int64 v150; // [xsp+20h] [xbp-70h] BYREF
  __int64 *v151; // [xsp+28h] [xbp-68h]
  int *v152; // [xsp+30h] [xbp-60h] BYREF
  __int64 v153; // [xsp+38h] [xbp-58h] BYREF
  __int64 v154; // [xsp+40h] [xbp-50h]
  __int64 v155; // [xsp+48h] [xbp-48h]
  __int64 v156; // [xsp+50h] [xbp-40h]
  __int64 v157; // [xsp+58h] [xbp-38h]
  __int64 v158; // [xsp+60h] [xbp-30h]
  __int64 v159; // [xsp+68h] [xbp-28h]
  __int64 v160; // [xsp+70h] [xbp-20h]
  __int64 v161; // [xsp+78h] [xbp-18h]
  __int64 v162; // [xsp+80h] [xbp-10h]
  __int64 v163; // [xsp+88h] [xbp-8h]

  v163 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( _cpu_active_mask )
  {
    v4 = &_per_cpu_offset;
    j = *(_QWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + __clz(__rbit64(_cpu_active_mask))) + 3528);
    goto LABEL_204;
  }
LABEL_197:
  __break(0x5512u);
LABEL_198:
  __break(1u);
LABEL_199:
  v107 = 0;
  while ( 1 )
  {
LABEL_132:
    v19 = (unsigned __int64)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
    v108 = &unk_6B000;
    v109 = in_sched_bug;
    cpu_array = v107;
    if ( !v107 && !in_sched_bug )
    {
      in_sched_bug = 1;
      walt_dump();
      __break(0x800u);
LABEL_212:
      in_sched_bug = 1;
      walt_dump();
      __break(0x800u);
LABEL_213:
      *((_DWORD *)v137 + 815) = 1;
      walt_dump();
      __break(0x800u);
      goto LABEL_214;
    }
    if ( (int)v0 >= 1 )
      break;
LABEL_143:
    if ( !v107 && !v109 )
      goto LABEL_212;
    v111 = num_sched_clusters;
    v112 = num_sched_clusters - 1;
    if ( (unsigned int)(num_sched_clusters - 1) < 4 )
    {
      v113 = qword_6C6E8[v112];
      v114 = (__int64)*(&off_6B218 + v112);
LABEL_147:
      v115 = 0;
      v116 = 0;
LABEL_148:
      v117 = 0;
      while ( 1 )
      {
        v118 = v115 + (int)v117;
        if ( v113 <= v118 )
          goto LABEL_198;
        v119 = *(unsigned __int8 *)(v114 + v118);
        if ( v119 >= 8 )
          goto LABEL_197;
        *(_QWORD *)(*(_QWORD *)(cpu_array + 8 * v116) + 8 * v117++) = *(_QWORD *)(sched_cluster[v119] + 24);
        if ( v111 == v117 )
        {
          ++v116;
          v115 += v111;
          if ( v116 != v111 )
            goto LABEL_148;
          goto LABEL_153;
        }
      }
    }
    printk(&unk_636CF);
    if ( in_sched_bug )
    {
      v111 = num_sched_clusters;
      if ( num_sched_clusters > 0 )
      {
        v113 = 0;
        v114 = 0;
        goto LABEL_147;
      }
LABEL_153:
      v120 = 0;
      v0 = -1;
      do
      {
        v121 = (unsigned int)(-1LL << v120) & *(_DWORD *)(j + 3192);
        if ( !(_DWORD)v121 )
          break;
        v19 = __clz(__rbit64(v121));
        cpu_node = of_get_cpu_node((unsigned int)v19, 0);
        if ( cpu_node )
        {
          v161 = 0;
          v162 = 0;
          v159 = 0;
          v160 = 0;
          v157 = 0;
          v158 = 0;
          v155 = 0;
          v156 = 0;
          v153 = 0;
          v154 = 0;
          if ( !(unsigned int)_of_parse_phandle_with_args(cpu_node, "next-level-cache", 0, 0, 0, &v153) )
          {
            v123 = v153;
            if ( v153 )
            {
              v124 = 0;
              do
              {
                v125 = (unsigned int)(-1LL << v124) & *(_DWORD *)(j + 3192);
                if ( !(_DWORD)v125 )
                  break;
                v126 = __clz(__rbit64(v125));
                if ( v19 != v126 )
                {
                  v127 = of_get_cpu_node((unsigned int)v126, 0);
                  if ( v127 )
                  {
                    v161 = 0;
                    v162 = 0;
                    v159 = 0;
                    v160 = 0;
                    v157 = 0;
                    v158 = 0;
                    v155 = 0;
                    v156 = 0;
                    v153 = 0;
                    v154 = 0;
                    v128 = _of_parse_phandle_with_args(v127, "next-level-cache", 0, 0, 0, &v153);
                    v129 = v153;
                    if ( v128 )
                      v129 = 0;
                    if ( v123 == v129 )
                    {
                      if ( (v19 & 0x1F) >= 8 )
                        goto LABEL_197;
                      cpu_l2_sibling[v19 & 0x1F] = v126;
                      break;
                    }
                  }
                }
                v124 = v126 + 1;
              }
              while ( v126 < 0x1F );
            }
          }
        }
        v120 = v19 + 1;
      }
      while ( v19 < 0x1F );
      v130 = early_walt_config();
      v50 = ((__int64 (__fastcall *)(__int64))create_freq_to_cost)(v130);
LABEL_170:
      v131 = *v1;
      if ( (__int64 *)*v1 != v1 )
      {
        v19 = 32;
        do
        {
          v132 = __clz(__rbit64(*(unsigned int *)(v131 + 16)));
          if ( *(_DWORD *)(v131 + 16) )
            v133 = v132;
          else
            v133 = 32;
          v50 = cpufreq_cpu_get(v133);
          if ( v50 )
          {
            *(_BYTE *)(v50 + 611) = 0;
            v50 = cpufreq_cpu_put();
          }
          v131 = *(_QWORD *)v131;
        }
        while ( (__int64 *)v131 != v1 );
      }
      v134 = ((__int64 (__fastcall *)(__int64))walt_config)(v50);
      if ( (soc_flags & 0x40) != 0 )
      {
        walt_cycle_counter_init(v134);
      }
      else
      {
        node_opts_by_path = of_find_node_opts_by_path("/soc/walt", 0);
        of_platform_populate(node_opts_by_path, 0, 0, 0);
      }
      wait_for_completion_interruptible(&walt_get_cycle_counts_cb_completion);
      v136 = stop_machine(&walt_init_stop_handler, 0, 0);
      if ( *(_QWORD *)(v3 + 1808)
        || num_sched_clusters < 2
        || (v108 = &unk_68000, (unsigned int)sysctl_panic_on_walt_bug >> 8 != 4539614) )
      {
LABEL_187:
        v138 = walt_register_sysctl(v136);
        v139 = walt_register_debugfs(v138);
        v140 = input_boost_init(v139);
        v141 = core_ctl_init(v140);
        v142 = walt_boost_init(v141);
        waltgov_register(v142);
        matched = match_string(&sched_feat_names, 27, "TTWU_QUEUE");
        if ( (matched & 0x80000000) == 0 )
        {
          v144 = matched;
          if ( matched > 0x1B )
            goto LABEL_197;
          static_key_disable((char *)&sched_feat_keys + 16 * matched);
          sysctl_sched_features &= ~(unsigned int)(1LL << v144);
        }
        topology_clear_scale_freq_source(1, &_cpu_online_mask);
        goto LABEL_191;
      }
      if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
      {
        v136 = printk_deferred("WALT-BUG root domain's perf-domain values not initialized rd->pd=%p.", nullptr);
        if ( (sysctl_panic_on_walt_bug & 2) == 0 )
          goto LABEL_187;
      }
      else if ( (sysctl_panic_on_walt_bug & 2) == 0 )
      {
        goto LABEL_187;
      }
      v137 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      if ( in_sched_bug )
        goto LABEL_187;
      goto LABEL_213;
    }
LABEL_214:
    *(_DWORD *)(v19 + 3260) = 1;
    walt_dump();
    __break(0x800u);
    v107 = 0;
    v3 = (__int64)v148;
    v108[10] = v19;
    v1 = &cluster_head;
    j = (unsigned __int64)"n";
  }
  v4 = nullptr;
  v0 *= 8;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v110 = num_sched_clusters < 0 ? 0LL : _kmalloc_noprof(8LL * (unsigned int)num_sched_clusters, 35104);
    *(_QWORD *)((char *)v4 + cpu_array) = v110;
    v109 = in_sched_bug;
    v107 = cpu_array;
    if ( !*(_QWORD *)((char *)v4 + cpu_array) && !in_sched_bug )
      break;
    if ( (_QWORD *)v0 == ++v4 )
      goto LABEL_143;
  }
LABEL_203:
  *(_DWORD *)(v19 + 3260) = 1;
  walt_dump();
  __break(0x800u);
LABEL_204:
  _X11 = &walt_init_already_inited;
  __asm { PRFM            #0x11, [X11] }
  while ( 1 )
  {
    v147 = __ldxr((unsigned int *)&walt_init_already_inited);
    if ( v147 )
      break;
    if ( !__stlxr(1u, (unsigned int *)&walt_init_already_inited) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( !v147 )
  {
    register_syscore_ops(&walt_syscore_ops);
    v6 = 1;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v5 = _kmalloc_cache_noprof(mem_alloc_profiling_key, 10528, 88);
      if ( !v5 )
        break;
      *(_DWORD *)v5 = v6;
      *(_DWORD *)(v5 + 4) = 0;
      *(_QWORD *)(v5 + 8) = v5 + 8;
      *(_QWORD *)(v5 + 16) = v5 + 8;
      *(_QWORD *)(v5 + 24) = v5 + 24;
      *(_QWORD *)(v5 + 32) = v5 + 24;
      related_thread_groups[v6++] = v5;
      if ( v6 == 20 )
        goto LABEL_7;
    }
    __break(0x800u);
LABEL_7:
    init_cluster = 0;
    qword_15B0 = _cpu_possible_mask;
    cluster_head = (__int64)&cluster_head;
    qword_67B48 = (__int64)&cluster_head;
    if ( &off_15A0 == (_UNKNOWN **)&cluster_head )
    {
      _list_add_valid_or_report(&off_15A0, &cluster_head, &cluster_head);
    }
    else
    {
      qword_67B48 = (__int64)&off_15A0;
      off_15A0 = &cluster_head;
      off_15A8 = (_UNKNOWN **)&cluster_head;
      cluster_head = (__int64)&off_15A0;
    }
    _rcu_read_lock();
    for ( i = css_next_child(0, &root_task_group); i; i = css_next_child(v8, &root_task_group) )
    {
      v8 = i;
      walt_update_tg_pointer();
    }
    _rcu_read_unlock(i);
    android_rvh_probe_register(&_tracepoint_android_rvh_wake_up_new_task, android_rvh_wake_up_new_task, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_update_cpu_capacity, &android_rvh_update_cpu_capacity, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_sched_cpu_starting, android_rvh_sched_cpu_starting, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_sched_cpu_dying, android_rvh_sched_cpu_dying, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_set_task_cpu, &android_rvh_set_task_cpu, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_new_task_stats, &android_rvh_new_task_stats, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_account_irq, &android_rvh_account_irq, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_flush_task, android_rvh_flush_task, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_update_misfit_status, &android_rvh_update_misfit_status, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_enqueue_task, &android_rvh_enqueue_task, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_dequeue_task, &android_rvh_dequeue_task, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_try_to_wake_up, android_rvh_try_to_wake_up, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_tick_entry, android_rvh_tick_entry, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_scheduler_tick, android_vh_scheduler_tick, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_schedule, android_rvh_schedule, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_cpu_cgroup_attach, android_rvh_cpu_cgroup_attach, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_cpu_cgroup_online, android_rvh_cpu_cgroup_online, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_sched_fork_init, android_rvh_sched_fork_init, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_ttwu_cond, android_rvh_ttwu_cond, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_sched_exec, android_rvh_sched_exec, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_build_perf_domains, android_rvh_build_perf_domains, 0);
    tracepoint_probe_register(&_tracepoint_cpu_frequency_limits, walt_cpu_frequency_limits, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_do_sched_yield, &walt_do_sched_yield, 0);
    android_rvh_probe_register(&_tracepoint_android_rvh_update_thermal_stats, android_rvh_update_thermal_stats, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_dup_task_struct, &android_vh_dup_task_struct, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_freq_qos_add_request, android_vh_freq_qos_add_request, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_freq_qos_update_request, android_vh_freq_qos_update_request, 0);
    v9 = tracepoint_probe_register(
           &_tracepoint_android_vh_freq_qos_remove_request,
           android_vh_freq_qos_remove_request,
           0);
    v10 = walt_fixup_init(v9);
    v11 = walt_lb_init(v10);
    v12 = walt_rt_init(v11);
    v13 = walt_cfs_init(v12);
    v14 = walt_halt_init(v13);
    walt_mvp_lock_ordering_init(v14);
    v15 = tracepoint_probe_register(&_tracepoint_android_vh_scheduler_tick, safg_sau_update_tick_handler, 0);
    nbia_init(v15);
    wait_for_completion_interruptible(&tick_sched_clock_completion);
    v148 = (int *)j;
    if ( !*(_QWORD *)(j + 1808) )
    {
      queue_work_on(32, system_wq, &rebuild_sd_work);
      wait_for_completion_interruptible(&rebuild_domains_completion);
    }
    j = (unsigned __int64)"n";
    v16 = 0;
    v17 = _cpu_possible_mask;
    v0 = -1;
    v1 = (_QWORD *)&_ksymtab_cpufreq_walt_reset_adaptive_freq;
    v3 = 1;
    v18 = (char *)&cpu_scale;
    v19 = (unsigned __int64)&walt_rq;
    _X19 = (unsigned __int64 *)&v152;
    v152 = nullptr;
    v150 = (__int64)&v150;
    v151 = &v150;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v21 = v17 & (-1LL << v16);
      if ( !v21 )
        break;
      v152 = nullptr;
      v22 = __clz(__rbit64(v21));
      v23 = (char *)&cpu_topology[12 * (unsigned int)v22];
      v25 = *((_DWORD *)v23 + 2);
      v24 = v23 + 8;
      if ( v25 == -1 )
        goto LABEL_47;
      v26 = 0;
      do
      {
        v33 = (unsigned int)(-1LL << v26) & _cpu_possible_mask;
        if ( !(_DWORD)v33 )
          break;
        v34 = __clz(__rbit64(v33));
        if ( *v24 == cpu_topology[12 * (unsigned int)v34 + 2] )
        {
          __asm { PRFM            #0x11, [X19] }
          do
            v31 = __ldxr((unsigned __int64 *)&v152);
          while ( __stxr(v31 | (1LL << v34), (unsigned __int64 *)&v152) );
        }
        _CF = v34 >= 0x1F;
        v26 = v34 + 1;
      }
      while ( !_CF );
      j = (unsigned __int64)v152;
      if ( !(_DWORD)v152 )
      {
LABEL_47:
        v50 = _warn_printk("WALT: Invalid cpu topology!!");
        __break(0x800u);
        v0 = v150;
        v3 = (__int64)v148;
        v1 = &cluster_head;
        for ( j = (unsigned __int64)&init_cluster; (__int64 *)v0 != &v150; v50 = kfree(v53) )
        {
          v51 = v0;
          v52 = 0;
          v53 = v0 - 8;
          v0 = *(_QWORD *)v0;
          do
          {
            v54 = (unsigned int)(-1LL << v52) & *(_DWORD *)(v51 + 16);
            if ( !(_DWORD)v54 )
              break;
            v55 = __clz(__rbit64(v54));
            v56 = v4[v55];
            _CF = v55 >= 0x1F;
            v52 = v55 + 1;
            *(_QWORD *)((char *)&walt_rq + v56 + 8) = &init_cluster;
          }
          while ( !_CF );
          v57 = *(_QWORD **)(v51 + 8);
          if ( *v57 == v51 && (v58 = *(_QWORD *)v51, *(_QWORD *)(*(_QWORD *)v51 + 8LL) == v51) )
          {
            *(_QWORD *)(v58 + 8) = v57;
            *v57 = v58;
          }
          else
          {
            _list_del_entry_valid_or_report(v51);
            v53 = v60;
          }
          v59 = num_sched_clusters;
          *(_QWORD *)v51 = 0xDEAD000000000100LL;
          *(_QWORD *)(v51 + 8) = 0xDEAD000000000122LL;
          num_sched_clusters = v59 - 1;
        }
        goto LABEL_170;
      }
      v149 = v22;
      v35 = _kmalloc_cache_noprof(_tracepoint_android_rvh_set_task_cpu, 2336, 520);
      v18 = (char *)&cpu_scale;
      if ( !v35 )
      {
        __break(0x800u);
LABEL_202:
        __break(0x800u);
        goto LABEL_203;
      }
      v36 = (__int64 *)(v35 + 8);
      *(_QWORD *)(v35 + 8) = v35 + 8;
      *(_QWORD *)(v35 + 16) = v35 + 8;
      *(_QWORD *)(v35 + 36) = 0x100000001LL;
      v37 = (unsigned __int64)v152;
      v38 = num_sched_clusters;
      *(_DWORD *)(v35 + 44) = 1;
      *(_DWORD *)v35 = 0;
      *(_QWORD *)(v35 + 24) = v37;
      *(_QWORD *)(v35 + 472) = 0;
      *(_BYTE *)(v35 + 488) = -1;
      if ( v38 > 3 )
        goto LABEL_202;
      v39 = 0;
      v17 &= ~j;
      do
      {
        v40 = (unsigned int)v37 & (unsigned __int64)(-1LL << v39);
        if ( !v40 )
          break;
        v41 = __clz(__rbit64(v40));
        v42 = v4[v41];
        _CF = v41 >= 0x1F;
        v39 = v41 + 1;
        *(_QWORD *)((char *)&walt_rq + v42 + 8) = v35;
      }
      while ( !_CF );
      v43 = &v150;
      j = (unsigned __int64)"n";
      do
      {
        v44 = v43;
        v43 = (__int64 *)*v43;
        if ( v43 == &v150 )
          break;
        v45 = __clz(__rbit64(*(unsigned int *)(v35 + 24)));
        if ( *(_DWORD *)(v35 + 24) )
          v46 = v45;
        else
          v46 = 32;
        if ( v46 >= 0x20 )
          goto LABEL_197;
        v47 = __clz(__rbit64(*((unsigned int *)v43 + 4)));
        v48 = *((_DWORD *)v43 + 4) ? v47 : 32;
        if ( v48 >= 0x20 )
          goto LABEL_197;
      }
      while ( *(_QWORD *)((char *)&cpu_scale + v4[v46]) >= *(_QWORD *)((char *)&cpu_scale + v4[v48]) );
      if ( (__int64 *)v43[1] != v44 || v36 == v44 || v43 == v36 )
      {
        _list_add_valid_or_report(v35 + 8, v44, v43);
        v18 = (char *)&cpu_scale;
        v38 = num_sched_clusters;
      }
      else
      {
        v43[1] = (__int64)v36;
        *(_QWORD *)(v35 + 8) = v43;
        *(_QWORD *)(v35 + 16) = v44;
        *v44 = (__int64)v36;
      }
      v49 = v38 + 1;
      num_sched_clusters = v49;
      v16 = v149 + 1;
      if ( v149 >= 0x1F )
        goto LABEL_59;
    }
    v49 = num_sched_clusters;
LABEL_59:
    v61 = (__int64 *)v150;
    v62 = &v150;
    v3 = (__int64)v148;
    if ( v49 == 4 && (__int64 *)v150 != &v150 )
    {
      v63 = 0;
      v64 = 0;
      v65 = 0;
      v66 = &v150;
      v67 = &v150;
      do
      {
        if ( v64 == 2 )
        {
          v68 = __clz(__rbit64(*((unsigned int *)v61 + 4)));
          if ( *((_DWORD *)v61 + 4) )
            v69 = v68;
          else
            v69 = 32;
          if ( v69 >= 0x20 )
            goto LABEL_197;
          v65 = *(_QWORD *)((char *)&cpu_scale + v4[v69]);
          v67 = v61;
        }
        else if ( v64 == 1 )
        {
          v70 = __clz(__rbit64(*((unsigned int *)v61 + 4)));
          if ( *((_DWORD *)v61 + 4) )
            v71 = v70;
          else
            v71 = 32;
          if ( v71 >= 0x20 )
            goto LABEL_197;
          v63 = *(_QWORD *)((char *)&cpu_scale + v4[v71]);
          v66 = v61;
        }
        v61 = (__int64 *)*v61;
        ++v64;
      }
      while ( v61 != &v150 );
      if ( v63 < v65 )
      {
        v72 = (__int64 *)v67[1];
        if ( (__int64 *)*v72 == v67 )
        {
          v73 = *v67;
          if ( *(__int64 **)(*v67 + 8) == v67 )
          {
            *(_QWORD *)(v73 + 8) = v72;
            *v72 = v73;
            goto LABEL_79;
          }
        }
        goto LABEL_96;
      }
    }
    while ( 1 )
    {
      v78 = (__int64 **)v150;
      v0 = (__int64)"pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
      if ( (__int64 *)v150 == v62 )
        break;
      *(_DWORD *)(v150 + 24) = 0;
      sched_cluster[0] = (__int64)(v78 - 1);
      v79 = *v78;
      if ( v79 == &v150 )
        break;
      *((_DWORD *)v79 + 6) = 1;
      qword_67B58 = (__int64)(v79 - 1);
      v80 = (__int64 *)*v79;
      if ( v80 == &v150 )
        break;
      *((_DWORD *)v80 + 6) = 2;
      qword_67B60 = (__int64)(v80 - 1);
      v81 = (__int64 *)*v80;
      if ( v81 == &v150 )
        break;
      *((_DWORD *)v81 + 6) = 3;
      qword_67B68 = (__int64)(v81 - 1);
      v82 = (__int64 *)*v81;
      if ( v82 == &v150 )
        break;
      *((_DWORD *)v82 + 6) = 4;
      qword_67B70 = (__int64)(v82 - 1);
      v83 = (__int64 *)*v82;
      if ( v83 == &v150 )
        goto LABEL_97;
      *((_DWORD *)v83 + 6) = 5;
      qword_67B78 = (__int64)(v83 - 1);
      v84 = (__int64 *)*v83;
      if ( v84 == &v150
        || (*((_DWORD *)v84 + 6) = 6, qword_67B80 = (__int64)(v84 - 1), v85 = (__int64 *)*v84, v85 == &v150)
        || (v67 = (_QWORD *)&unk_7,
            *((_DWORD *)v85 + 6) = 7,
            qword_67B88 = (__int64)(v85 - 1),
            v86 = *v85,
            (__int64 *)v86 == &v150) )
      {
LABEL_97:
        __break(0x800u);
        break;
      }
      *(_DWORD *)(v86 + 24) = 8;
      __break(0x5512u);
LABEL_96:
      _list_del_entry_valid_or_report(v67);
      v18 = (char *)&cpu_scale;
LABEL_79:
      if ( v72 == v66 )
        v74 = v67;
      else
        v74 = v72;
      *v67 = 0xDEAD000000000100LL;
      v67[1] = 0xDEAD000000000122LL;
      v75 = *v66;
      *v67 = *v66;
      *(_QWORD *)(v75 + 8) = v67;
      v76 = (__int64 **)v66[1];
      v67[1] = (__int64)v76;
      *v76 = v67;
      v77 = (__int64 *)*v74;
      if ( *(__int64 **)(*v74 + 8) != v74 || v74 == v66 || v77 == v66 )
      {
        _list_add_valid_or_report(v66, v74, v77);
        v18 = (char *)&cpu_scale;
      }
      else
      {
        v77[1] = (__int64)v66;
        *v66 = (__int64)v77;
        v66[1] = (__int64)v74;
        *v74 = (__int64)v66;
      }
    }
    v87 = v150;
    if ( (__int64 *)v150 == &v150 )
      goto LABEL_115;
    while ( 1 )
    {
      v88 = __clz(__rbit64(*(unsigned int *)(v87 + 16)));
      if ( *(_DWORD *)(v87 + 16) )
        v89 = v88;
      else
        v89 = 32;
      raw = cpufreq_cpu_get_raw(v89);
      if ( raw )
      {
        v91 = 0;
        *(_DWORD *)(v87 + 32) = *(_DWORD *)(raw + 40);
        *(_DWORD *)(v87 + 36) = *(_DWORD *)(raw + 56);
        do
        {
          v92 = (unsigned int)(-1LL << v91) & *(_DWORD *)(v87 + 16);
          if ( !(_DWORD)v92 )
            break;
          v93 = __clz(__rbit64(v92));
          v94 = v4[v93];
          _CF = v93 >= 0x1F;
          v91 = v93 + 1;
          *(_QWORD *)((char *)&walt_rq + v94 + 16) = *(_QWORD *)(raw + 8);
        }
        while ( !_CF );
        v95 = cpuinfo_max_freq_cached;
        v18 = (char *)&cpu_scale;
        if ( (unsigned int)cpuinfo_max_freq_cached <= *(_DWORD *)(raw + 40) )
          v95 = *(_DWORD *)(raw + 40);
        cpuinfo_max_freq_cached = v95;
      }
      else
      {
        v18 = (char *)&cpu_scale;
        if ( !in_sched_bug )
        {
          in_sched_bug = 1;
          walt_dump();
          __break(0x800u);
LABEL_114:
          v87 = v150;
          j = (unsigned __int64)"n";
LABEL_115:
          v96 = v151;
          v1 = &cluster_head;
          *(_QWORD *)(v87 + 8) = &cluster_head;
          qword_67B48 = (__int64)v96;
          *v96 = (__int64)&cluster_head;
          __dmb(0xBu);
          cluster_head = v87;
          v97 = v87;
          if ( (__int64 *)v87 != &cluster_head )
          {
            v98 = 0;
            v99 = -1;
            do
            {
              v100 = __clz(__rbit64(*(unsigned int *)(v97 + 16)));
              v101 = *(_DWORD *)(v97 + 16) ? v100 : 32;
              if ( v101 >= 0x20 )
                goto LABEL_197;
              v102 = *(_DWORD *)(v97 + 24);
              v103 = *(_QWORD *)&v18[v4[v101]];
              if ( v103 > v98 )
              {
                v98 = v103;
                max_possible_cluster_id = *(_DWORD *)(v97 + 24);
              }
              if ( v103 < v99 )
              {
                v99 = v103;
                min_possible_cluster_id = v102;
              }
              v97 = *(_QWORD *)v97;
            }
            while ( (__int64 *)v97 != &cluster_head );
          }
          v104 = __clz(__rbit64(*(unsigned int *)(sched_cluster[0] + 24)));
          if ( *(_DWORD *)(sched_cluster[0] + 24) )
            v105 = v104;
          else
            v105 = 32;
          if ( v105 >= 0x20 )
            goto LABEL_197;
          v106 = ((unsigned int)sched_ravg_window >> 10) * *(_DWORD *)&v18[v4[v105]];
          sched_group_upmigrate = (unsigned int)sysctl_sched_group_upmigrate_pct * (unsigned __int64)v106 / 0x64;
          v0 = (unsigned int)num_sched_clusters;
          sched_group_downmigrate = (unsigned int)sysctl_sched_group_downmigrate_pct * (unsigned __int64)v106 / 0x64;
          if ( (num_sched_clusters & 0x80000000) == 0 )
          {
            v107 = _kmalloc_noprof(8LL * (unsigned int)num_sched_clusters, 35104);
            goto LABEL_132;
          }
          goto LABEL_199;
        }
      }
      v87 = *(_QWORD *)v87;
      if ( (__int64 *)v87 == &v150 )
        goto LABEL_114;
    }
  }
LABEL_191:
  _ReadStatusReg(SP_EL0);
}
