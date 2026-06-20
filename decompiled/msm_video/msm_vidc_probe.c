__int64 __fastcall msm_vidc_probe(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x4
  unsigned __int64 inited; // x0
  __int64 v7; // x4
  __int64 v8; // x20
  unsigned int v9; // w21
  unsigned __int64 v10; // x21
  char v11; // w8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  void *v18; // x0
  __int64 v19; // x0
  _QWORD *v20; // x20
  char v21; // w8
  int v23; // w0
  void *v24; // x0
  __int64 v25; // x0
  __int64 (__fastcall **v26)(_QWORD); // x8
  __int64 (__fastcall *v27)(_QWORD); // x8
  unsigned int v28; // w0
  __int64 (__fastcall **v29)(_QWORD); // x8
  __int64 (__fastcall *v30)(_QWORD); // x8
  void *v31; // x8
  void (__fastcall **v32)(_QWORD); // x8
  void (__fastcall *v33)(_QWORD); // x8
  unsigned int group; // w0
  __int64 v35; // x4
  unsigned __int64 v36; // x0
  __int64 v37; // x4
  __int64 next_available_child; // x0
  __int64 v39; // x23
  unsigned int v40; // w22
  int v41; // w20
  unsigned int v42; // w0
  __int64 v43; // x4
  unsigned int v44; // w0
  __int64 v45; // x8
  void (__fastcall *v46)(_QWORD); // x8
  _QWORD v47[2]; // [xsp+0h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_vidc_debug & 2) == 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_34:
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe");
    goto LABEL_36;
  }
  printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_probe");
  if ( !a1 )
    goto LABEL_34;
LABEL_3:
  if ( (is_video_device(a1 + 16) & 1) == 0 )
  {
    v8 = *(_QWORD *)(a1 + 760);
    if ( (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-sec-pxl")
      || (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-sec-bitstream")
      || (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-sec-non-pxl")
      || (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-ns")
      || (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-ns-bitstream")
      || (unsigned int)of_device_is_compatible(v8, "qcom,vidc,cb-ns-pxl") )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_context_bank");
      v9 = component_add(a1 + 16, msm_vidc_component_ops);
      goto LABEL_63;
    }
    __break(0x800u);
LABEL_36:
    v9 = -22;
    goto LABEL_63;
  }
  v47[0] = 0;
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90870, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
  v2 = (_QWORD *)devm_kmalloc(a1 + 16, 6760, 3520);
  if ( !v2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8387B, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
    v9 = -12;
    goto LABEL_63;
  }
  v3 = (__int64)v2;
  *v2 = a1;
  v4 = *(_QWORD *)(a1 + 760);
  g_core = v3;
  *(_QWORD *)(a1 + 168) = v3;
  if ( (of_property_read_variable_u32_array(v4, "vmid", v3 + 4760, 1, 0) & 0x80000000) != 0 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8169A, "high", 0xFFFFFFFFLL, "codec", v5);
    *(_DWORD *)(v3 + 4760) = 0;
    inited = msm_vidc_debugfs_init_drv();
    if ( !inited )
      goto LABEL_31;
  }
  else
  {
    if ( *(_DWORD *)(v3 + 4760) )
      *(_BYTE *)(v3 + 4768) = 1;
    inited = msm_vidc_debugfs_init_drv();
    if ( !inited )
      goto LABEL_31;
  }
  v10 = inited;
  if ( !(unsigned int)_devm_add_action(a1 + 16, msm_vidc_devm_debugfs_put, inited, "msm_vidc_devm_debugfs_put") )
  {
    *(_QWORD *)(v3 + 3560) = v10;
    goto LABEL_38;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_devm_debugfs_put");
  debugfs_remove(v10);
LABEL_31:
  v11 = msm_vidc_debug;
  *(_QWORD *)(v3 + 3560) = 0;
  if ( (v11 & 2) != 0 )
    printk(&unk_8D7F3, "high", 0xFFFFFFFFLL, "codec", v7);
LABEL_38:
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_initialize_core");
  msm_vidc_update_core_state(v3, 0, "msm_vidc_initialize_core");
  v12 = alloc_workqueue(&unk_89A74, 393226, 1, "pm_workq");
  *(_QWORD *)(v3 + 6216) = v12;
  if ( !v12 )
  {
    v9 = -22;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_56;
    v18 = &unk_8DA7B;
    goto LABEL_55;
  }
  v13 = alloc_workqueue(&unk_89A74, 393226, 1, "batch_workq");
  *(_QWORD *)(v3 + 6224) = v13;
  if ( !v13 )
  {
    v9 = -22;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_56;
    v18 = &unk_838ED;
    goto LABEL_55;
  }
  v14 = *(_QWORD *)v3;
  *(_DWORD *)(v3 + 6472) = 4096;
  v15 = devm_kmalloc(v14 + 16, 4096, 3520);
  *(_QWORD *)(v3 + 6464) = v15;
  if ( !v15 )
  {
    v9 = -12;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_56;
    v18 = &unk_8CE8F;
    goto LABEL_55;
  }
  v16 = devm_kmalloc(*(_QWORD *)v3 + 16LL, *(unsigned int *)(v3 + 6472), 3520);
  v17 = *(_QWORD *)(v3 + 6464);
  *(_QWORD *)(v3 + 6480) = v16;
  if ( !v17 )
  {
    v9 = -12;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_56;
    v18 = &unk_807AF;
LABEL_55:
    printk(v18, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_initialize_core");
LABEL_56:
    v19 = *(_QWORD *)(v3 + 6224);
    v20 = (_QWORD *)(v3 + 6216);
    if ( v19 )
      destroy_workqueue(v19);
    if ( *v20 )
      destroy_workqueue(*v20);
    v21 = msm_vidc_debug;
    *v20 = 0;
    v20[1] = 0;
    if ( (v21 & 1) != 0 )
    {
      printk(&unk_8CE41, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_devm_init_core");
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_62;
    }
    else if ( (msm_vidc_debug & 1) == 0 )
    {
      goto LABEL_62;
    }
    goto LABEL_70;
  }
  _mutex_init(v3 + 3856, "&core->lock", &msm_vidc_initialize_core___key);
  *(_QWORD *)(v3 + 3528) = v3 + 3528;
  *(_QWORD *)(v3 + 3536) = v3 + 3528;
  *(_QWORD *)(v3 + 3544) = v3 + 3544;
  *(_QWORD *)(v3 + 3552) = v3 + 3544;
  *(_QWORD *)(v3 + 6112) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 6120) = v3 + 6120;
  *(_QWORD *)(v3 + 6128) = v3 + 6120;
  *(_QWORD *)(v3 + 6136) = venus_hfi_pm_work_handler;
  init_timer_key(v3 + 6144, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)(v3 + 6232) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 6240) = v3 + 6240;
  *(_QWORD *)(v3 + 6248) = v3 + 6240;
  *(_QWORD *)(v3 + 6256) = msm_vidc_fw_unload_handler;
  init_timer_key(v3 + 6264, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)(v3 + 6336) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 6344) = v3 + 6344;
  *(_QWORD *)(v3 + 6352) = v3 + 6344;
  *(_QWORD *)(v3 + 6360) = msm_vidc_ssr_handler;
  *(_QWORD *)(v3 + 6368) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 6376) = v3 + 6376;
  *(_QWORD *)(v3 + 6384) = v3 + 6376;
  *(_QWORD *)(v3 + 6392) = msm_vidc_hw_virt_ssr_handler;
  if ( (unsigned int)_devm_add_action(a1 + 16, msm_vidc_devm_deinit_core, v3, "msm_vidc_devm_deinit_core") )
  {
    msm_vidc_devm_deinit_core(v3);
    v9 = -22;
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_62;
LABEL_70:
    v24 = &unk_93E02;
LABEL_71:
    printk(v24, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
    goto LABEL_62;
  }
  v23 = msm_vidc_init_platform_capabilities((__int64 *)v3);
  if ( v23 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_66;
    v31 = &unk_92722;
    goto LABEL_117;
  }
  v25 = devm_kmalloc(*(_QWORD *)v3 + 16LL, 152, 3520);
  if ( !v25 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_87795, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_resources");
      v9 = -12;
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_62;
      goto LABEL_91;
    }
    v9 = -12;
    goto LABEL_90;
  }
  v26 = *(__int64 (__fastcall ***)(_QWORD))(v3 + 6552);
  *(_QWORD *)(v3 + 3904) = v25;
  if ( v26 )
  {
    v27 = *v26;
    if ( v27 )
    {
      if ( *((_DWORD *)v27 - 1) != -1850880742 )
        __break(0x8228u);
      v28 = v27(v3);
      if ( v28 )
      {
        v9 = v28;
        if ( (msm_vidc_debug & 1) != 0 )
        {
          printk(&unk_9275F, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_resources");
          if ( (msm_vidc_debug & 1) == 0 )
            goto LABEL_62;
LABEL_91:
          v24 = &unk_80772;
          goto LABEL_71;
        }
LABEL_90:
        if ( (msm_vidc_debug & 1) == 0 )
          goto LABEL_62;
        goto LABEL_91;
      }
    }
  }
  v29 = *(__int64 (__fastcall ***)(_QWORD))(v3 + 6584);
  if ( v29 )
  {
    v30 = *v29;
    if ( v30 )
    {
      if ( *((_DWORD *)v30 - 1) != -1850880742 )
        __break(0x8228u);
      v23 = v30(v3);
      if ( v23 )
      {
        if ( (msm_vidc_debug & 1) == 0 )
          goto LABEL_66;
        v31 = &unk_96F7B;
LABEL_117:
        v41 = v23;
        printk(v31, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
        v23 = v41;
LABEL_66:
        if ( v23 == -11 )
          v9 = -517;
        else
          v9 = -22;
        goto LABEL_62;
      }
    }
  }
  v32 = *(void (__fastcall ***)(_QWORD))(v3 + 6592);
  if ( v32 )
  {
    v33 = *v32;
    if ( v33 )
    {
      if ( *((_DWORD *)v33 - 1) != -1850880742 )
        __break(0x8228u);
      v33(v3);
    }
  }
  group = sysfs_create_group(a1 + 16, &msm_vidc_core_attr_group);
  if ( group )
  {
    v9 = group;
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8F27F, "err ", 0xFFFFFFFFLL, "codec", v35);
    goto LABEL_131;
  }
  msm_vidc_check_mmrm_support(v3);
  v36 = msm_vidc_debugfs_init_core(v3);
  *(_QWORD *)(v3 + 3568) = v36;
  if ( !v36 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_95924, "high", 0xFFFFFFFFLL, "codec", v37);
  next_available_child = of_get_next_available_child(*(_QWORD *)(a1 + 760), 0);
  if ( !next_available_child )
  {
    v40 = 0;
LABEL_119:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8DA3E, "high", 0xFFFFFFFFLL, "codec", v40);
    v42 = of_platform_populate(*(_QWORD *)(a1 + 760), &_mod_of__msm_vidc_dt_match_device_table, 0, a1 + 16);
    if ( v42 )
    {
      v9 = v42;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_82CCE, "err ", 0xFFFFFFFFLL, "codec", v43);
      goto LABEL_130;
    }
    v44 = component_master_add_with_match(a1 + 16, msm_vidc_component_master_ops, v47[0]);
    if ( v44 )
    {
      v9 = v44;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8246B, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
      of_platform_depopulate(a1 + 16);
      goto LABEL_130;
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
    v9 = 0;
    goto LABEL_63;
  }
  v39 = next_available_child;
  v40 = 0;
  while ( 1 )
  {
    if ( !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-sec-pxl")
      && !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-sec-bitstream")
      && !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-sec-non-pxl")
      && !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-ns")
      && !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-ns-bitstream")
      && !(unsigned int)of_device_is_compatible(v39, "qcom,vidc,cb-ns-pxl") )
    {
      goto LABEL_114;
    }
    component_match_add_release(a1 + 16, v47, msm_vidc_component_release_of, msm_vidc_component_compare_of, v39);
    v9 = v47[0];
    if ( v47[0] >= 0xFFFFFFFFFFFFF001LL )
      break;
    ++v40;
LABEL_114:
    v39 = of_get_next_available_child(*(_QWORD *)(a1 + 760), v39);
    if ( !v39 )
      goto LABEL_119;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_886C6, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_probe_video_device");
LABEL_130:
  sysfs_remove_group(a1 + 16, &msm_vidc_core_attr_group);
LABEL_131:
  v45 = *(_QWORD *)(v3 + 6584);
  if ( v45 )
  {
    v46 = *(void (__fastcall **)(_QWORD))(v45 + 8);
    if ( v46 )
    {
      if ( *((_DWORD *)v46 - 1) != -1850880742 )
        __break(0x8228u);
      v46(v3);
    }
  }
LABEL_62:
  *(_QWORD *)(a1 + 168) = 0;
  g_core = 0;
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return v9;
}
