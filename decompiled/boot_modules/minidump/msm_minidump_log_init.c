__int64 msm_minidump_log_init()
{
  __int64 v0; // x21
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x9
  unsigned __int64 v5; // x12
  __int64 v6; // x10
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x1
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x13
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x1
  char v19; // w8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x22
  __int64 v22; // x8
  unsigned __int64 v23; // x23
  __int64 v24; // x1
  __int64 v25; // x19
  char v26; // w8
  __int64 v27; // x8
  unsigned __int64 v28; // x12
  __int64 v29; // x9
  __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x23
  unsigned __int64 v33; // x24
  unsigned __int64 v34; // x24
  __int64 v35; // x8
  __int64 v36; // x8
  unsigned __int64 v37; // x12
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x8
  unsigned __int64 v41; // x12
  __int64 v42; // x9
  __int64 v43; // x8
  __int64 v44; // x8
  unsigned __int64 v45; // x12
  __int64 v46; // x9
  __int64 v47; // x1
  unsigned __int64 compatible_node; // x19
  void *v49; // x0
  int v50; // w8
  __int64 v51; // x20
  __int64 *v52; // x22
  __int64 v53; // x0
  __int64 v54; // x20
  __int64 v55; // x1
  __int64 v56; // x1
  __int64 v57; // x1
  __int64 v58; // x0
  __int64 v59; // x19
  __int64 v60; // x8
  unsigned __int64 v61; // x9
  __int64 v62; // x8
  unsigned __int64 v63; // x12
  __int64 v64; // x9
  __int64 v65; // x1
  char v66; // w14
  int v67; // w8
  bool v68; // cf
  unsigned __int64 v69; // x14
  unsigned __int64 v70; // x14
  __int64 v71; // x19
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x10
  unsigned __int64 v75; // x13
  __int64 v76; // x8
  __int64 v77; // x1
  __int64 v78; // x1
  _QWORD **v79; // x0
  _QWORD *v80; // x19
  unsigned __int64 StatusReg; // x20
  _QWORD *v82; // x21
  __int64 v83; // x8
  unsigned int v84; // w0
  unsigned int v86; // [xsp+Ch] [xbp-F4h] BYREF
  _QWORD v87[3]; // [xsp+10h] [xbp-F0h] BYREF
  unsigned __int64 v88; // [xsp+28h] [xbp-D8h]
  __int64 v89; // [xsp+30h] [xbp-D0h]
  __int64 v90; // [xsp+38h] [xbp-C8h]
  _QWORD v91[2]; // [xsp+40h] [xbp-C0h] BYREF
  __int64 v92; // [xsp+50h] [xbp-B0h]
  unsigned __int64 v93; // [xsp+58h] [xbp-A8h]
  __int64 v94; // [xsp+60h] [xbp-A0h]
  unsigned __int64 v95; // [xsp+68h] [xbp-98h]
  __int64 v96; // [xsp+70h] [xbp-90h]
  __int64 v97; // [xsp+78h] [xbp-88h]
  __int64 v98; // [xsp+80h] [xbp-80h]
  __int64 v99; // [xsp+88h] [xbp-78h]
  __int64 v100; // [xsp+90h] [xbp-70h]
  __int64 v101; // [xsp+98h] [xbp-68h]
  _QWORD v102[12]; // [xsp+A0h] [xbp-60h] BYREF

  v102[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE1(v91[1]) = 0;
  WORD1(v91[1]) = 0;
  HIDWORD(v91[1]) = 0;
  v92 = 0;
  v0 = debug_symbol_lookup_name("_sdata");
  v1 = debug_symbol_lookup_name("__bss_stop");
  v2 = debug_symbol_lookup_name("__per_cpu_start");
  v3 = debug_symbol_lookup_name("__per_cpu_end");
  v4 = v0 << 8 >> 8;
  strcpy((char *)v91, "KDATABSS");
  v5 = (unsigned __int64)(v4 + 0x8000000000LL) >> 38;
  v6 = memstart_addr + v4 + 0x8000000000LL;
  v7 = v3;
  v8 = v4 - kimage_voffset;
  v9 = v1 - v0 + 3;
  if ( !v5 )
    v8 = v6;
  if ( v9 < 0 )
    v9 = v1 - v0 + 6;
  v93 = v0;
  v94 = v8;
  LOBYTE(v91[1]) = 0;
  v95 = v9 & 0xFFFFFFFFFFFFFFFCLL;
  if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
    printk(&unk_113863, v10);
  v11 = debug_symbol_lookup_name("__start_ro_after_init");
  v12 = debug_symbol_lookup_name("__end_ro_after_init");
  v13 = v11 << 8 >> 8;
  v14 = (unsigned __int64)(v13 + 0x8000000000LL) >> 38;
  strcpy((char *)v91, "KROAIDATA");
  v15 = memstart_addr + v13 + 0x8000000000LL;
  v16 = v13 - kimage_voffset;
  v17 = v12 - v11 + 3;
  if ( !v14 )
    v16 = v15;
  if ( v17 < 0 )
    v17 = v12 - v11 + 6;
  v93 = v11;
  v94 = v16;
  v95 = v17 & 0xFFFFFFFFFFFFFFFCLL;
  if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
    printk(&unk_1132DF, v18);
  v19 = 0;
  do
  {
    v20 = (unsigned int)(-1LL << v19) & _cpu_possible_mask;
    if ( !(_DWORD)v20 )
      break;
    v91[0] = 0;
    v91[1] = 0;
    v21 = __clz(__rbit64(v20));
    v92 = 0;
    v93 = 0;
    v22 = _per_cpu_offset[v21];
    v94 = 0;
    v95 = 0;
    v23 = v22 + v2;
    scnprintf(v91, 13, "KSPERCPU%d", v21);
    v93 = v23;
    v94 = per_cpu_ptr_to_phys(v23);
    v95 = v7 - v2;
    if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
      printk(&unk_113048, v24);
    v19 = v21 + 1;
  }
  while ( v21 < 0x1F );
  is_vmap_stack = 1;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v91[0] = 0;
  v91[1] = 0;
  v25 = debug_symbol_lookup_name("irq_stack_ptr");
  v26 = 0;
  do
  {
    v31 = (unsigned int)(-1LL << v26) & _cpu_possible_mask;
    if ( !(_DWORD)v31 )
      break;
    v32 = __clz(__rbit64(v31));
    v33 = *(_QWORD *)(_per_cpu_offset[v32] + v25);
    if ( is_vmap_stack == 1 )
    {
      v34 = v33 & 0xFFFFFFFFFFFFF000LL;
      scnprintf(v91, 13, "KISTK%d_%d", v32, 0);
      v93 = v34;
      v95 = 4096;
      if ( is_vmap_stack == 1 )
      {
        v35 = (vmalloc_to_page(v34) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
      }
      else
      {
        v36 = (__int64)(v34 << 8) >> 8;
        v37 = (unsigned __int64)(v36 + 0x8000000000LL) >> 38;
        v38 = memstart_addr + v36 + 0x8000000000LL;
        v35 = v36 - kimage_voffset;
        if ( !v37 )
          v35 = v38;
      }
      v94 = v35;
      if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
        printk_deferred("Failed to add stack of entry %s in Minidump\n", (const char *)v91);
      scnprintf(v91, 13, "KISTK%d_%d", v32, 1);
      v93 = v34 + 4096;
      v95 = 4096;
      if ( (is_vmap_stack & 1) != 0 )
      {
        v39 = (vmalloc_to_page(v34 + 4096) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
      }
      else
      {
        v40 = (__int64)((v34 + 4096) << 8) >> 8;
        v41 = (unsigned __int64)(v40 + 0x8000000000LL) >> 38;
        v42 = memstart_addr + v40 + 0x8000000000LL;
        v39 = v40 - kimage_voffset;
        if ( !v41 )
          v39 = v42;
      }
      v94 = v39;
      if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
        printk_deferred("Failed to add stack of entry %s in Minidump\n", (const char *)v91);
      scnprintf(v91, 13, "KISTK%d_%d", v32, 2);
      v93 = v34 + 0x2000;
      v95 = 4096;
      if ( (is_vmap_stack & 1) != 0 )
      {
        v43 = (vmalloc_to_page(v34 + 0x2000) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
      }
      else
      {
        v44 = (__int64)((v34 + 0x2000) << 8) >> 8;
        v45 = (unsigned __int64)(v44 + 0x8000000000LL) >> 38;
        v46 = memstart_addr + v44 + 0x8000000000LL;
        v43 = v44 - kimage_voffset;
        if ( !v45 )
          v43 = v46;
      }
      v94 = v43;
      if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
        printk_deferred("Failed to add stack of entry %s in Minidump\n", (const char *)v91);
      v33 = v34 + 12288;
      scnprintf(v91, 13, "KISTK%d_%d", v32, 3);
      v93 = v33;
      v95 = 4096;
      if ( (is_vmap_stack & 1) == 0 )
      {
LABEL_19:
        v27 = (__int64)(v33 << 8) >> 8;
        v28 = (unsigned __int64)(v27 + 0x8000000000LL) >> 38;
        v29 = memstart_addr + v27 + 0x8000000000LL;
        v30 = v27 - kimage_voffset;
        if ( !v28 )
          v30 = v29;
        goto LABEL_21;
      }
    }
    else
    {
      scnprintf(v91, 13, "KISTK%d", v32);
      v93 = v33;
      v95 = 0x4000;
      if ( is_vmap_stack != 1 )
        goto LABEL_19;
    }
    v30 = (vmalloc_to_page(v33) + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6;
LABEL_21:
    v94 = v30;
    if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
      printk_deferred("Failed to add stack of entry %s in Minidump\n", (const char *)v91);
    v26 = v32 + 1;
  }
  while ( v32 < 0x1F );
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v91[0] = 0;
  v91[1] = 0;
  v86 = 0;
  v89 = 0;
  v90 = 0;
  v88 = 0;
  memset(v87, 0, sizeof(v87));
  compatible_node = of_find_compatible_node(0, 0, "qcom,ramoops");
  v49 = &unk_1128AB;
  if ( !compatible_node )
    goto LABEL_75;
  if ( compatible_node > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_75;
  memset(v102, 0, 80);
  v50 = _of_parse_phandle_with_args(compatible_node, "memory-region", 0, 0, 0, v102);
  v49 = &unk_113251;
  if ( v50 )
    goto LABEL_75;
  v51 = v102[0];
  if ( !v102[0] )
    goto LABEL_75;
  v52 = v91;
  if ( (unsigned int)of_address_to_resource(v102[0], 0, v91) )
  {
    v53 = of_reserved_mem_lookup(v51);
    if ( v53 )
    {
      v52 = (__int64 *)(v53 + 24);
      goto LABEL_55;
    }
    v49 = &unk_113989;
LABEL_75:
    printk(v49, v47);
  }
  else
  {
LABEL_55:
    v54 = *v52;
    if ( (of_property_read_variable_u32_array(compatible_node, "record-size", &v86, 1, 0) & 0x80000000) == 0 && v86 )
    {
      strcpy((char *)v87, "KDMESG");
      v88 = (v54 - memstart_addr) | 0xFFFFFF8000000000LL;
      v89 = v54;
      v90 = v86;
      if ( (msm_minidump_add_region(v87) & 0x80000000) != 0 )
        printk(&unk_1131A3, v55);
      v54 += v86;
    }
    if ( (of_property_read_variable_u32_array(compatible_node, "console-size", &v86, 1, 0) & 0x80000000) == 0 && v86 )
    {
      v90 = v86;
      strcpy((char *)v87, "KCONSOLE");
      v88 = (v54 - memstart_addr) | 0xFFFFFF8000000000LL;
      v89 = v54;
      if ( (msm_minidump_add_region(v87) & 0x80000000) != 0 )
        printk(&unk_1139A6, v56);
      v54 += v86;
    }
    if ( (of_property_read_variable_u32_array(compatible_node, "ftrace-size", &v86, 1, 0) & 0x80000000) == 0 && v86 )
    {
      strcpy((char *)v87, "KFTRACE");
      v90 = v86;
      v88 = (v54 - memstart_addr) | 0xFFFFFF8000000000LL;
      v89 = v54;
      if ( (msm_minidump_add_region(v87) & 0x80000000) != 0 )
        printk(&unk_113748, v57);
      v54 += v86;
    }
    if ( (of_property_read_variable_u32_array(compatible_node, "pmsg-size", &v86, 1, 0) & 0x80000000) == 0 )
    {
      if ( v86 )
      {
        strcpy((char *)v87, "KPMSG");
        v90 = v86;
        v88 = (v54 - memstart_addr) | 0xFFFFFF8000000000LL;
        v89 = v54;
        if ( (msm_minidump_add_region(v87) & 0x80000000) != 0 )
        {
          v49 = &unk_112F82;
          goto LABEL_75;
        }
      }
    }
  }
  v91[1] = 0;
  v92 = 0;
  v58 = _kmalloc_large_noprof(0x200000, 3520);
  v59 = v58;
  if ( v58 )
  {
    v60 = v58 << 8 >> 8;
    strcpy((char *)v91, "KFTRACE");
    v61 = v60 + 0x8000000000LL;
    v62 = v60 - kimage_voffset;
    v63 = v61 >> 38;
    v64 = memstart_addr + v61;
    if ( !v63 )
      v62 = v64;
    v93 = v58;
    v94 = v62;
    v95 = 0x200000;
    if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
      printk(&unk_113E7B, v65);
    tracepoint_probe_register(&_tracepoint_android_vh_ftrace_oops_enter, md_trace_oops_enter, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ftrace_oops_exit, md_trace_oops_exit, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ftrace_format_check, md_update_trace_fmt, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_ftrace_dump_buffer, md_dump_trace_buf, 0);
    __dmb(0xBu);
    md_ftrace_buf_addr = v59;
  }
  v66 = 0;
  v67 = max_cluster;
  do
  {
    v69 = _cpu_possible_mask & (unsigned __int64)(-1LL << v66);
    if ( !v69 )
      break;
    v70 = __clz(__rbit64(v69));
    if ( cpu_topology[12 * (unsigned int)v70 + 2] > v67 )
    {
      v67 = cpu_topology[12 * (unsigned int)v70 + 2];
      max_cluster = v67;
    }
    v68 = v70 >= 0x1F;
    v66 = v70 + 1;
  }
  while ( !v68 );
  v91[1] = 0;
  v92 = 0;
  v71 = 168LL * (v67 + 1);
  v72 = _kmalloc_noprof(v71, 3520);
  cpuclk_log = v72;
  if ( v72 )
  {
    v73 = v72 << 8 >> 8;
    v74 = v73 + 0x8000000000LL;
    v75 = (unsigned __int64)(v73 + 0x8000000000LL) >> 38;
    v76 = v73 - kimage_voffset;
    v95 = v71;
    strcpy((char *)v91, "FREQ_LOG");
    if ( !v75 )
      v76 = memstart_addr + v74;
    v93 = v72;
    v94 = v76;
    if ( (msm_minidump_add_region(v91) & 0x80000000) != 0 )
      printk(&unk_112BF0, v91);
    tracepoint_probe_register(&_tracepoint_android_vh_cpufreq_resolve_freq, log_cpu_freq, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_cpufreq_fast_switch, log_cpu_freq, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_cpufreq_target, log_cpu_freq, 0);
  }
  if ( (unsigned int)md_register_panic_entries(8, (__int64)"KMODULES", (__int64 **)&md_mod_info_seq_buf) )
  {
    printk(&unk_1131C6, v77);
  }
  else
  {
    seq_buf_printf(md_mod_info_seq_buf, "=== MODULE INFO ===\n");
    if ( (unsigned int)register_module_notifier(&md_module_nb) )
    {
      printk(&unk_1130FB, v78);
    }
    else
    {
      v79 = (_QWORD **)debug_symbol_lookup_name("modules");
      if ( v79 )
      {
        v80 = v79;
        if ( (unsigned __int64)v79 <= 0xFFFFFFFFFFFFF000LL )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(StatusReg + 16);
          v82 = *v79;
          if ( *v79 != v79 )
          {
            do
            {
              if ( v82 - 1 != (_QWORD *)&_this_module )
                md_module_process();
              v82 = (_QWORD *)*v82;
            }
            while ( v82 != v80 );
          }
          v83 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v83;
          if ( !v83 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule();
        }
      }
    }
  }
  v84 = md_minidump_memory_init();
  if ( v84 )
  {
    printk(&unk_113454, v84);
  }
  else
  {
    md_register_panic_entries(32, (__int64)"KCNTXT", (__int64 **)&md_cntxt_seq_buf);
    tracepoint_probe_register(&_tracepoint_android_vh_ipi_stop, md_ipi_stop, 0);
    md_register_panic_entries(8, (__int64)"KRUNQUEUE", (__int64 **)&md_runq_seq_buf);
    md_register_panic_entries(64, (__int64)"KTASK_STACK", (__int64 **)&md_ktask_stack_buf);
  }
  atomic_notifier_chain_register(&panic_notifier_list, &md_panic_blk);
  register_die_notifier(&md_die_context_nb);
  _ReadStatusReg(SP_EL0);
  return 0;
}
