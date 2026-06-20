unsigned __int64 __fastcall bam_dma_probe(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x19
  __int64 matched; // x0
  unsigned __int64 result; // x0
  __int64 v8; // x0
  _QWORD *resource_byname; // x0
  _QWORD *v10; // x22
  __int64 v11; // x0
  __int64 variable_u32_array; // x0
  bool v13; // w9
  __int64 v14; // x0
  __int64 property; // x8
  char v16; // w9
  __int64 v17; // x0
  __int64 v18; // x23
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w9
  unsigned int v22; // w8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w23
  __int64 v26; // x22
  __int64 v27; // x0
  __int64 v28; // x8
  _DWORD *v29; // x8
  __int64 v30; // x10
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x20
  __int64 v34; // x20
  unsigned int v35; // w21
  const char *v36; // x1
  __int64 v37; // x8
  __int64 v38; // x19
  __int64 v39; // x19
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned __int64 v48; // x9

  v1 = a1 + 2;
  v3 = devm_kmalloc(a1 + 2, 544, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = a1[95];
  v5 = v3;
  *(_QWORD *)(v3 + 8) = v1;
  matched = of_match_node(&_mod_of__bam_of_match_device_table, v4);
  if ( !matched )
  {
    v36 = "Unsupported BAM module\n";
LABEL_55:
    dev_err(v1, v36);
    return 4294967277LL;
  }
  *(_QWORD *)(v5 + 440) = *(_QWORD *)(matched + 192);
  result = devm_platform_ioremap_resource(a1, 0);
  *(_QWORD *)v5 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  v8 = ipc_log_context_create(1, "dma_bam_log", 0);
  *(_QWORD *)(v5 + 536) = v8;
  if ( v8 || (dev_err(*(_QWORD *)(v5 + 8), "Failed to create dma bam log\n"), (v8 = *(_QWORD *)(v5 + 536)) != 0) )
    ipc_log_string(v8, "%s start %d\n", "bam_dma_probe", 1);
  _ftrace_dbg(*(_QWORD *)(v5 + 8), "%s start %d\n", "bam_dma_probe", 1);
  *(_BYTE *)(v5 + 532) = 0;
  resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "bam_remote_mem");
  if ( resource_byname )
  {
    *(_BYTE *)(v5 + 532) = 1;
    v10 = resource_byname;
    *(_DWORD *)(v5 + 528) = *resource_byname;
    v11 = devm_ioremap(v1);
    *(_QWORD *)(v5 + 512) = v11;
    if ( v11 )
    {
      *(_QWORD *)(v5 + 520) = v11;
      *(_QWORD *)(v5 + 504) = v10;
      goto LABEL_9;
    }
    dev_err(v1, "Remote mem ioremap failed\n");
    return 4294967284LL;
  }
LABEL_9:
  if ( (unsigned int)dma_set_mask(v1, 0xFFFFFFFFLL) )
  {
    v36 = "Could not set 32 bit mask\n";
    goto LABEL_55;
  }
  dma_set_coherent_mask(v1, 0xFFFFFFFFLL);
  result = platform_get_irq(a1, 0);
  *(_DWORD *)(v5 + 456) = result;
  if ( (result & 0x80000000) != 0 )
    return result;
  variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,ee", v5 + 424, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v37 = *(_QWORD *)(v5 + 8);
    v38 = variable_u32_array;
    dev_err(v37, "Execution environment unspecified\n");
    return v38;
  }
  v13 = of_find_property(a1[95], "qcom,controlled-remotely", 0) != 0;
  v14 = a1[95];
  *(_BYTE *)(v5 + 428) = v13;
  property = of_find_property(v14, "qcom,powered-remotely", 0);
  v16 = *(_BYTE *)(v5 + 428);
  v17 = *(_QWORD *)(v5 + 8);
  *(_BYTE *)(v5 + 429) = property != 0;
  if ( (v16 & 1) != 0 || property )
    result = devm_clk_get_optional(v17, "bam_clk");
  else
    result = devm_clk_get(v17, "bam_clk");
  *(_QWORD *)(v5 + 448) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  if ( !result )
  {
    if ( (of_property_read_variable_u32_array(a1[95], "num-channels", v5 + 416, 1, 0) & 0x80000000) != 0 )
      dev_err(*(_QWORD *)(v5 + 8), "num-channels unspecified in dt\n");
    if ( (of_property_read_variable_u32_array(a1[95], "qcom,num-ees", v5 + 420, 1, 0) & 0x80000000) != 0 )
      dev_err(*(_QWORD *)(v5 + 8), "num-ees unspecified in dt\n");
  }
  v18 = *(_QWORD *)(v5 + 448);
  v19 = clk_prepare(v18);
  if ( (_DWORD)v19 )
  {
    v34 = v19;
LABEL_67:
    dev_err(*(_QWORD *)(v5 + 8), "failed to prepare/enable clock\n");
    return v34;
  }
  v20 = clk_enable(v18);
  if ( (_DWORD)v20 )
  {
    v34 = v20;
    clk_unprepare(v18);
    goto LABEL_67;
  }
  v21 = *(_DWORD *)(v5 + 420);
  if ( !v21 )
  {
    v21 = ((unsigned int)readl_relaxed(
                           *(_QWORD *)v5
                         + *(unsigned int *)(*(_QWORD *)(v5 + 440) + 16LL)
                         + (unsigned int)(*(_DWORD *)(v5 + 424) * *(_DWORD *)(*(_QWORD *)(v5 + 440) + 28LL))) >> 8)
        & 0xF;
    *(_DWORD *)(v5 + 420) = v21;
  }
  v22 = *(_DWORD *)(v5 + 424);
  if ( v22 >= v21 )
  {
    v34 = 4294967274LL;
LABEL_63:
    v39 = *(_QWORD *)(v5 + 448);
    clk_disable(v39);
    clk_unprepare(v39);
    return v34;
  }
  if ( !*(_DWORD *)(v5 + 416) )
    *(_DWORD *)(v5 + 416) = (unsigned __int8)readl_relaxed(
                                               *(_QWORD *)v5
                                             + *(unsigned int *)(*(_QWORD *)(v5 + 440) + 32LL)
                                             + *(_DWORD *)(*(_QWORD *)(v5 + 440) + 44LL) * v22);
  if ( (*(_BYTE *)(v5 + 428) & 1) == 0 && (*(_BYTE *)(v5 + 429) & 1) == 0 )
    bam_reset(v5);
  v23 = *(_QWORD *)(v5 + 536);
  if ( v23 )
    ipc_log_string(v23, "%s ret:%d\n", "bam_init", 0);
  _ftrace_dbg(*(_QWORD *)(v5 + 8), "%s ret:%d\n", "bam_init", 0);
  tasklet_setup(v5 + 464, dma_tasklet);
  v24 = devm_kmalloc(*(_QWORD *)(v5 + 8), 408LL * *(unsigned int *)(v5 + 416), 3520);
  *(_QWORD *)(v5 + 408) = v24;
  if ( !v24 )
  {
    v34 = 4294967284LL;
LABEL_62:
    tasklet_kill(v5 + 464);
    goto LABEL_63;
  }
  *(_QWORD *)(v5 + 32) = v5 + 32;
  *(_QWORD *)(v5 + 40) = v5 + 32;
  if ( *(_DWORD *)(v5 + 416) )
  {
    v25 = 0;
    do
    {
      v26 = *(_QWORD *)(v5 + 408) + 408LL * (int)v25;
      *(_DWORD *)(v26 + 264) = v25;
      *(_QWORD *)(v26 + 256) = v5;
      vchan_init(v26, v5 + 16);
      *(_QWORD *)(v26 + 152) = bam_dma_free_desc;
      ++v25;
      *(_QWORD *)(v26 + 376) = v26 + 376;
      *(_QWORD *)(v26 + 384) = v26 + 376;
    }
    while ( v25 < *(_DWORD *)(v5 + 416) );
  }
  v27 = devm_request_threaded_irq(*(_QWORD *)(v5 + 8), *(unsigned int *)(v5 + 456), bam_dma_irq, 0, 4, "bam_dma", v5);
  if ( (_DWORD)v27 )
  {
LABEL_46:
    if ( *(_DWORD *)(v5 + 416) )
    {
      v34 = v27;
      v35 = 0;
      do
        tasklet_kill(*(_QWORD *)(v5 + 408) + 408LL * (int)v35++ + 112);
      while ( v35 < *(_DWORD *)(v5 + 416) );
    }
    else
    {
      v34 = v27;
    }
    goto LABEL_62;
  }
  v28 = *(_QWORD *)(v5 + 8);
  *(_QWORD *)(v5 + 128) = v28;
  v29 = *(_DWORD **)(v28 + 672);
  if ( v29 )
    *v29 = 32760;
  else
    __break(0x800u);
  a1[21] = v5;
  *(_QWORD *)(v5 + 88) = 0;
  _X8 = (unsigned __int64 *)(v5 + 88);
  __asm { PRFM            #0x11, [X8] }
  do
    v48 = __ldxr(_X8);
  while ( __stxr(v48 | 0x400, _X8) );
  *(_DWORD *)(v5 + 168) = 6;
  *(_DWORD *)(v5 + 188) = 1;
  *(_QWORD *)(v5 + 192) = bam_alloc_chan;
  *(_QWORD *)(v5 + 208) = bam_free_chan;
  *(_QWORD *)(v5 + 288) = bam_prep_slave_sg;
  *(_QWORD *)(v5 + 160) = 0x400000004LL;
  *(_QWORD *)(v5 + 328) = bam_slave_config;
  *(_QWORD *)(v5 + 336) = bam_pause;
  *(_QWORD *)(v5 + 344) = bam_resume;
  *(_QWORD *)(v5 + 352) = bam_dma_terminate_all;
  v30 = *(_QWORD *)(v5 + 8);
  *(_QWORD *)(v5 + 368) = bam_tx_status;
  *(_QWORD *)(v5 + 376) = bam_issue_pending;
  *(_QWORD *)(v5 + 128) = v30;
  v31 = dma_async_device_register(v5 + 16);
  if ( (_DWORD)v31 )
  {
    v33 = v31;
    dev_err(*(_QWORD *)(v5 + 8), "failed to register dma async device\n");
    goto LABEL_45;
  }
  v32 = of_dma_controller_register(a1[95], bam_dma_xlate, v5 + 16);
  if ( (_DWORD)v32 )
  {
    v33 = v32;
    dma_async_device_unregister(v5 + 16);
LABEL_45:
    v27 = v33;
    goto LABEL_46;
  }
  pm_runtime_irq_safe(v1);
  pm_runtime_set_autosuspend_delay(v1, 100);
  v40 = _pm_runtime_use_autosuspend(v1, 1);
  a1[67] = ktime_get_mono_fast_ns(v40);
  _pm_runtime_set_status(v1, 0);
  pm_runtime_enable(v1);
  v41 = *(_QWORD *)(v5 + 536);
  if ( v41 )
    ipc_log_string(v41, "%s end ret:%d\n", "bam_dma_probe", 0);
  _ftrace_dbg(*(_QWORD *)(v5 + 8), "%s end ret:%d\n", "bam_dma_probe", 0);
  return 0;
}
