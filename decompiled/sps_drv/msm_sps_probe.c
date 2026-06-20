__int64 __fastcall msm_sps_probe(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  unsigned int *v5; // x8
  unsigned int v6; // w9
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 resource_byname; // x0
  __int64 v10; // x9
  __int64 v11; // x8
  unsigned int v12; // w11
  char v13; // w8
  const char *v14; // x3
  __int64 matched; // x0
  __int64 v16; // x2
  unsigned int v17; // w0
  __int64 v18; // x2
  unsigned int v19; // w20
  unsigned __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x2
  __int64 v26; // x8
  int v27; // w9
  unsigned __int64 v28; // x0
  __int64 v29; // x2
  unsigned __int64 v30; // x19
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x2
  unsigned int v34; // w0
  __int64 v35; // x19
  int v37; // w9
  __int64 v38; // x8
  const char *v39; // x2
  __int64 v40; // x2
  __int64 v41; // x2
  int v42; // w0

  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&msm_sps_probe__rs, "msm_sps_probe")) )
  {
    printk(&unk_299F7, "msm_sps_probe", a3);
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Enter\n", "msm_sps_probe");
  v4 = *(_QWORD *)(a1 + 760);
  if ( v4 )
  {
    if ( (of_property_read_variable_u32_array(v4, "qcom,device-type", &d_type, 1, 0) & 0x80000000) == 0 )
    {
      if ( (unsigned __int8)logging_option >= 2u
        && debug_level_option
        && (!print_limit_option || (unsigned int)__ratelimit(&get_device_tree_data__rs_365, "get_device_tree_data")) )
      {
        printk(&unk_2735F, "get_device_tree_data", (unsigned int)d_type);
      }
      if ( sps && *(_DWORD *)(sps + 288) <= 3u )
        ipc_log_string(
          *(_QWORD *)(sps + 272),
          "%s: sps:device type is %d\n",
          "get_device_tree_data",
          (unsigned int)d_type);
      goto LABEL_34;
    }
    d_type = 3;
    if ( (unsigned __int8)logging_option >= 2u && debug_level_option )
    {
      if ( print_limit_option )
      {
        if ( !(unsigned int)__ratelimit(&get_device_tree_data__rs, "get_device_tree_data") )
          goto LABEL_31;
        v40 = (unsigned int)d_type;
      }
      else
      {
        v40 = 3;
      }
      printk(&unk_229F1, "get_device_tree_data", v40);
    }
LABEL_31:
    if ( sps && *(_DWORD *)(sps + 288) < 4u )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:default device type %d\n",
        "get_device_tree_data",
        (unsigned int)d_type);
LABEL_34:
    v13 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,pipe-attr-ee", 0) != 0;
    enhd_pipe = v13;
    if ( (unsigned __int8)logging_option >= 2u && debug_level_option )
    {
      if ( print_limit_option )
      {
        if ( !(unsigned int)__ratelimit(&get_device_tree_data__rs_369, "get_device_tree_data") )
          goto LABEL_35;
        v13 = enhd_pipe;
      }
      if ( (v13 & 1) != 0 )
        v39 = (const char *)&unk_24626;
      else
        v39 = "not";
      printk(&unk_25072, "get_device_tree_data", v39);
    }
LABEL_35:
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    {
      if ( enhd_pipe )
        v14 = (const char *)&unk_24626;
      else
        v14 = "not";
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:PIPE_ATTR_EE is %s supported\n", "get_device_tree_data", v14);
    }
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&msm_sps_probe__rs_331, "msm_sps_probe")) )
    {
      printk(&unk_2919C, "msm_sps_probe", "sps:get data from device tree\n");
    }
    if ( sps && !*(_DWORD *)(sps + 288) )
      ipc_log_string(*(_QWORD *)(sps + 248), "%s: %s", "msm_sps_probe", "sps:get data from device tree\n");
    matched = of_match_device(&msm_sps_match, a1 + 16);
    if ( matched )
    {
      v16 = **(unsigned int **)(matched + 192);
      bam_type = **(_DWORD **)(matched + 192);
      if ( (unsigned __int8)logging_option >= 2u && debug_level_option )
      {
        if ( print_limit_option )
        {
          if ( !(unsigned int)__ratelimit(&msm_sps_probe__rs_333, "msm_sps_probe") )
            goto LABEL_47;
          v16 = (unsigned int)bam_type;
        }
        printk(&unk_2946C, "msm_sps_probe", v16);
      }
LABEL_47:
      if ( sps && *(_DWORD *)(sps + 288) <= 3u )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:BAM type is:%d\n", "msm_sps_probe", (unsigned int)bam_type);
      goto LABEL_54;
    }
    bam_type = 1;
    if ( (unsigned __int8)logging_option < 2u || !debug_level_option )
      goto LABEL_51;
    if ( print_limit_option )
    {
      if ( !(unsigned int)__ratelimit(&msm_sps_probe__rs_336, "msm_sps_probe") )
        goto LABEL_51;
      v41 = (unsigned int)bam_type;
    }
    else
    {
      v41 = 1;
    }
    printk(&unk_280F1, "msm_sps_probe", v41);
LABEL_51:
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:use default BAM type:%d\n",
        "msm_sps_probe",
        (unsigned int)bam_type);
    goto LABEL_54;
  }
  d_type = 0;
  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&get_platform_data__rs, "get_platform_data")) )
  {
    printk(&unk_299F7, "get_platform_data", a3);
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Enter\n", "get_platform_data");
  v5 = *(unsigned int **)(a1 + 160);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&get_platform_data__rs_374, "get_platform_data")) )
    {
      printk(&unk_258F1, "get_platform_data", a3);
    }
    v26 = sps;
    if ( sps )
    {
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: invalid platform data\n", "get_platform_data");
      v26 = sps;
    }
    v27 = (unsigned __int8)logging_option;
    *(_DWORD *)(v26 + 104) = 0;
    if ( v27 != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&msm_sps_probe__rs_339, "msm_sps_probe")) )
    {
      printk(&unk_28114, "msm_sps_probe", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: :Fail to get platform data\n", "msm_sps_probe");
    return (unsigned int)-19;
  }
  v6 = (unsigned __int8)logging_option;
  v7 = *v5;
  v8 = sps;
  *(_DWORD *)(sps + 104) = v7;
  if ( v6 >= 2 && debug_level_option )
  {
    if ( print_limit_option )
    {
      v42 = __ratelimit(&get_platform_data__rs_377, "get_platform_data");
      v8 = sps;
      if ( !v42 )
        goto LABEL_17;
      v7 = *(unsigned int *)(sps + 104);
    }
    printk(&unk_2553F, "get_platform_data", v7);
    v8 = sps;
  }
LABEL_17:
  if ( v8 && *(_DWORD *)(v8 + 288) <= 3u )
    ipc_log_string(
      *(_QWORD *)(v8 + 272),
      "%s: sps:bamdma_restricted_pipes=0x%x\n",
      "get_platform_data",
      *(_DWORD *)(v8 + 104));
  resource_byname = platform_get_resource_byname(a1, 512, "pipe_mem");
  if ( !resource_byname )
    goto LABEL_25;
  v10 = *(_QWORD *)resource_byname;
  v11 = sps;
  v12 = (unsigned __int8)logging_option;
  *(_QWORD *)(sps + 56) = *(_QWORD *)resource_byname;
  *(_DWORD *)(v11 + 64) = *(_DWORD *)(resource_byname + 8) - v10 + 1;
  if ( v12 >= 2 && debug_level_option )
  {
    if ( print_limit_option )
    {
      if ( !(unsigned int)__ratelimit(&get_platform_data__rs_381, "get_platform_data") )
        goto LABEL_22;
      v11 = sps;
    }
    printk(&unk_27DA1, "get_platform_data", v11 + 56);
  }
LABEL_22:
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    ipc_log_string(
      *(_QWORD *)(sps + 272),
      "%s: sps:pipemem.base=%pa,size=0x%x\n",
      "get_platform_data",
      (const void *)(sps + 56),
      *(_DWORD *)(sps + 64));
LABEL_25:
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&msm_sps_probe__rs_342, "msm_sps_probe")) )
  {
    printk(&unk_2919C, "msm_sps_probe", "sps:get platform data\n");
  }
  if ( sps && !*(_DWORD *)(sps + 288) )
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: %s", "msm_sps_probe", "sps:get platform data\n");
  bam_type = 0;
LABEL_54:
  *(_QWORD *)sps = class_create("msm_sps");
  v17 = alloc_chrdev_region(sps + 8, 0, 1, "msm_sps");
  if ( v17 )
  {
    v19 = v17;
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&msm_sps_probe__rs_344, "msm_sps_probe")) )
    {
      printk(&unk_26B6D, "msm_sps_probe", v18);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: alloc_chrdev_region err\n", "msm_sps_probe");
    goto LABEL_141;
  }
  v20 = device_create(*(_QWORD *)sps, 0, *(unsigned int *)(sps + 8), sps, "msm_sps");
  v22 = sps;
  *(_QWORD *)(sps + 16) = v20;
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&msm_sps_probe__rs_347, "msm_sps_probe")) )
    {
      printk(&unk_234C5, "msm_sps_probe", v21);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: device_create err\n", "msm_sps_probe");
    v19 = 0;
    goto LABEL_140;
  }
  v23 = *(_QWORD *)(a1 + 760);
  if ( v23 )
    *(_QWORD *)(v20 + 744) = v23;
  if ( d_type )
    goto LABEL_70;
  v28 = clk_get(*(_QWORD *)(v22 + 16), "mem_clk");
  v30 = v28;
  *(_QWORD *)(sps + 24) = v28;
  if ( v28 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( v28 == -517 )
    {
      v19 = -517;
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&msm_sps_probe__rs_351, "msm_sps_probe")) )
      {
        printk(&unk_27D80, "msm_sps_probe", v29);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: fail to get pmem_clk\n", "msm_sps_probe");
      v19 = 0;
    }
    goto LABEL_139;
  }
  v19 = clk_prepare(v28);
  if ( v19 )
  {
LABEL_110:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&msm_sps_probe__rs_354, "msm_sps_probe")) )
    {
      printk(&unk_2813B, "msm_sps_probe", v33);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: failed to enable pmem_clk\n", "msm_sps_probe");
    goto LABEL_137;
  }
  v34 = clk_enable(v30);
  if ( v34 )
  {
    v19 = v34;
    clk_unprepare(v30);
    goto LABEL_110;
  }
LABEL_70:
  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_device_init__rs, "sps_device_init")) )
  {
    printk(&unk_26A3F, "sps_device_init", v21);
  }
  v24 = sps;
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
  {
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: Enter\n", "sps_device_init");
    v24 = sps;
  }
  if ( (unsigned int)sps_mem_init(*(_QWORD *)(v24 + 56), *(unsigned int *)(v24 + 64)) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_device_init__rs_384, "sps_device_init")) )
    {
      printk(&unk_23DD6, "sps_device_init", v25);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: SPS memory init failed\n", "sps_device_init");
LABEL_129:
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&msm_sps_probe__rs_357, "msm_sps_probe")) )
    {
      printk(&unk_2733F, "msm_sps_probe", v25);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps_device_init err\n", "msm_sps_probe");
    if ( d_type )
    {
      v19 = -1;
LABEL_139:
      device_destroy(*(_QWORD *)sps, *(unsigned int *)(sps + 8));
LABEL_140:
      unregister_chrdev_region(*(unsigned int *)(sps + 8), 1);
LABEL_141:
      class_destroy(*(_QWORD *)sps);
      return v19;
    }
    v35 = *(_QWORD *)(sps + 24);
    clk_disable(v35);
    clk_unprepare(v35);
    v19 = -1;
LABEL_137:
    if ( !d_type )
      clk_put(*(_QWORD *)(sps + 24));
    goto LABEL_139;
  }
  v31 = sps;
  v32 = sps + 112;
  *(_QWORD *)(sps + 160) = sps + 160;
  *(_QWORD *)(v31 + 168) = v31 + 160;
  _mutex_init(v32, "&sps->lock", &sps_device_init___key);
  if ( (unsigned int)sps_rm_init(sps + 184, *(unsigned int *)(sps + 108)) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_device_init__rs_388, "sps_device_init")) )
    {
      printk(&unk_26F9F, "sps_device_init", v25);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Fail to init SPS resource manager\n", "sps_device_init");
    goto LABEL_129;
  }
  if ( (unsigned int)sps_bam_driver_init(*(unsigned int *)(sps + 108)) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_device_init__rs_391, "sps_device_init")) )
    {
      printk(&unk_2B0F1, "sps_device_init", v25);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: SPS BAM driver init failed\n", "sps_device_init");
    goto LABEL_129;
  }
  if ( (unsigned int)sps_map_init(0, *(unsigned int *)(sps + 108)) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_device_init__rs_394, "sps_device_init")) )
    {
      printk(&unk_262D2, "sps_device_init", v25);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: SPS connection mapping init failed\n", "sps_device_init");
    goto LABEL_129;
  }
  v37 = (unsigned __int8)logging_option;
  v38 = sps;
  *(_DWORD *)(sps + 48) = 1;
  if ( v37 != 1 )
  {
    if ( (unsigned __int8)print_limit_option < 2u || (unsigned int)__ratelimit(&msm_sps_probe__rs_360, "msm_sps_probe") )
      printk(&unk_2919C, "msm_sps_probe", "sps:sps is ready\n");
    v38 = sps;
  }
  if ( v38 )
    ipc_log_string(*(_QWORD *)(v38 + 272), "%s: %s", "msm_sps_probe", "sps:sps is ready\n");
  return 0;
}
