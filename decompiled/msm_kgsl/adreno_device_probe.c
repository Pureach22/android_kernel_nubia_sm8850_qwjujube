__int64 __fastcall adreno_device_probe(__int64 a1, _QWORD *a2)
{
  _QWORD *v4; // x25
  _QWORD *v5; // x28
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned __int64 v9; // x23
  int fuse; // w0
  _DWORD *v11; // x8
  int feature_code; // w0
  int v13; // w22
  _BOOL4 v15; // w21
  int pcode; // w0
  int v17; // w8
  __int64 v18; // x21
  __int64 node_by_name; // x0
  __int64 v20; // x23
  __int64 next_child; // x0
  __int64 v22; // x22
  int v23; // w27
  int v24; // w20
  _BOOL4 v25; // w26
  int v26; // w27
  unsigned int v27; // w26
  int v28; // w0
  __int64 v29; // x0
  __int64 v30; // x0
  int v31; // w8
  unsigned int v32; // w9
  int v33; // w8
  unsigned int v34; // w9
  int v35; // w20
  __int64 v36; // x8
  unsigned __int64 v37; // x0
  unsigned __int64 v38; // x0
  int v39; // w2
  int v41; // w8
  int v42; // w20
  unsigned __int64 v43; // x0
  unsigned __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v58; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v67; // x9
  __int64 v68; // [xsp+1Ch] [xbp-14h] BYREF
  unsigned int v69; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+28h] [xbp-8h]

  v4 = a2 + 2996;
  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2 + 2459;
  printk(&unk_13C039);
  a2[1] = "kgsl-3d0";
  a2[1094] = adreno_functable;
  *((_DWORD *)a2 + 2172) = 0;
  _init_swait_queue_head(a2 + 1087, "&x->wait", &init_completion___key);
  *((_DWORD *)a2 + 2180) = 0;
  _init_swait_queue_head(a2 + 1091, "&x->wait", &init_completion___key);
  *((_DWORD *)v4 + 100) = 0;
  _init_swait_queue_head(a2 + 3047, "&x->wait", &init_completion___key);
  complete_all(v4 + 50);
  a2[1398] = 0x1000000400000000LL;
  a2[1399] = 0;
  a2[1400] = 0;
  _rt_mutex_init(a2 + 1386, "adreno_setup_device", &adreno_setup_device___key);
  _mutex_init(a2 + 1773, "&adreno_dev->dev.file_mutex", &adreno_setup_device___key_56);
  _mutex_init(a2 + 3037, "&adreno_dev->fault_recovery_mutex", &adreno_setup_device___key_58);
  _mutex_init(a2 + 3057, "&adreno_dev->dcvs_tuning_mutex", &adreno_setup_device___key_60);
  a2[1639] = a2 + 1639;
  a2[1640] = a2 + 1639;
  a2[2458] = 194;
  *(_BYTE *)v5 = 1;
  a2[2538] = 0xFFFFFFFE00000LL;
  a2[2539] = a2 + 2539;
  a2[2540] = a2 + 2539;
  a2[2541] = adreno_input_work;
  a2[2600] = a2 + 2600;
  a2[2601] = a2 + 2600;
  *(_QWORD *)((char *)a2 + 24284) = 0;
  *((_DWORD *)v5 + 286) = 0;
  a2[1803] = a2 + 1803;
  a2[1804] = a2 + 1803;
  a2[1968] = a2 + 1968;
  a2[1969] = a2 + 1968;
  a2[2133] = a2 + 2133;
  a2[2134] = a2 + 2133;
  a2[2298] = a2 + 2298;
  a2[2299] = a2 + 2298;
  v6 = a2[1783];
  v7 = *(unsigned int *)(v6 + 56);
  if ( (_DWORD)v7 )
    a2[1782] = (v7 + *(_QWORD *)(v6 + 64) - 1) & -v7;
  *(_QWORD *)(a1 + 168) = a2;
  a2[1396] = a1;
  v8 = *(_QWORD *)(a1 + 760);
  if ( of_find_property(v8, "qcom,gpu-quirk-two-pass-use-wfi", 0) )
    *((_DWORD *)v5 + 246) |= 1u;
  if ( of_find_property(v8, "qcom,gpu-quirk-critical-packets", 0) )
    *((_DWORD *)v5 + 246) |= 2u;
  if ( of_find_property(v8, "qcom,gpu-quirk-fault-detect-mask", 0) )
    *((_DWORD *)v5 + 246) |= 4u;
  if ( of_find_property(v8, "qcom,gpu-quirk-dp2clockgating-disable", 0) )
    *((_DWORD *)v5 + 246) |= 8u;
  if ( of_find_property(v8, "qcom,gpu-quirk-lmloadkill-disable", 0) )
    *((_DWORD *)v5 + 246) |= 0x10u;
  if ( of_find_property(v8, "qcom,gpu-quirk-hfi-use-reg", 0) )
    *((_DWORD *)v5 + 246) |= 0x20u;
  if ( of_find_property(v8, "qcom,gpu-quirk-secvid-set-once", 0) )
    *((_DWORD *)v5 + 246) |= 0x40u;
  if ( of_find_property(v8, "qcom,gpu-quirk-limit-uche-gbif-rw", 0) )
    *((_DWORD *)v5 + 246) |= 0x100u;
  if ( of_find_property(v8, "qcom,gpu-quirk-cx-gdsc", 0) )
    *((_DWORD *)v5 + 246) |= 0x200u;
  LODWORD(v9) = adreno_read_fuse(a1, "speed_bin");
  if ( (v9 & 0x80000000) != 0 )
    goto LABEL_103;
  *((_DWORD *)a2 + 3294) = v9;
  fuse = adreno_read_fuse(a1, "gpu_debug_bus_bin");
  if ( fuse < 0 )
  {
    v35 = fuse;
    dev_err(*a2, "failed to read gpu_debug_bus_bin nvmem cell\n");
    fuse = v35;
  }
  v11 = (_DWORD *)a2[1783];
  *((_DWORD *)a2 + 3295) = fuse;
  if ( *v11 == 524801 )
    *((_DWORD *)a2 + 3296) = adreno_read_fuse(a1, "cpr_rev");
  feature_code = socinfo_get_feature_code();
  v13 = feature_code & ~(feature_code >> 31);
  v15 = (unsigned int)(feature_code - 209) < 0x10 || (unsigned int)(feature_code - 241) < 0x10;
  if ( v15 )
  {
    pcode = socinfo_get_pcode();
    v17 = pcode & ~(pcode >> 31);
  }
  else
  {
    LOWORD(v17) = 0;
  }
  *((_DWORD *)a2 + 3297) = (unsigned __int16)v13 | ((unsigned __int16)v17 << 16);
  if ( v15 )
  {
    if ( kgsl_gpu_sku_override != -1 )
      *((_DWORD *)a2 + 3297) = kgsl_gpu_sku_override;
    if ( kgsl_gpu_speed_bin_override != -1 )
      *((_DWORD *)a2 + 3294) = kgsl_gpu_speed_bin_override;
  }
  v18 = *(_QWORD *)(a1 + 760);
  node_by_name = of_find_node_by_name(v18, "qcom,gpu-pwrlevel-bins");
  if ( node_by_name )
  {
    v20 = node_by_name;
    next_child = of_get_next_child(node_by_name, 0);
    if ( next_child )
    {
      v22 = next_child;
      do
      {
        v68 = 0;
        if ( (of_property_read_variable_u32_array(v22, "qcom,speed-bin", &v68, 1, 0) & 0x80000000) != 0 )
        {
          if ( !of_get_property(v22, "qcom,sku-codes", (char *)&v68 + 4) )
            goto LABEL_44;
          v25 = 0;
        }
        else
        {
          v23 = v68;
          v24 = *((_DWORD *)a2 + 3294);
          v25 = v68 == v24;
          if ( !of_get_property(v22, "qcom,sku-codes", (char *)&v68 + 4) )
          {
            if ( v23 == v24 )
              goto LABEL_58;
            goto LABEL_44;
          }
        }
        v69 = 0;
        if ( !(_DWORD)v68 || v25 )
        {
          v26 = SHIDWORD(v68) >> 2;
          if ( SHIDWORD(v68) >> 2 >= 1 )
          {
            v27 = 0;
            while ( (unsigned int)of_property_read_u32_index(v22, "qcom,sku-codes", v27, &v69)
                 || v69 && *((_DWORD *)a2 + 3297) != v69 )
            {
              if ( v26 == ++v27 )
                goto LABEL_44;
            }
LABEL_58:
            v28 = adreno_of_parse_pwrlevels(a2, v22);
            if ( v28 )
            {
              LODWORD(v9) = v28;
              goto LABEL_103;
            }
            adreno_of_get_initial_pwrlevels(a2 + 1104, v22);
            if ( (*(_BYTE *)(a2[1783] + 32LL) & 8) != 0 )
            {
              v69 = 0;
              if ( (of_property_read_variable_u32_array(v18, "qcom,throttle-pwrlevel", &v69, 1, 0) & 0x80000000) == 0 )
              {
                v31 = *((_DWORD *)a2 + 2517);
                v32 = v69;
                *((_BYTE *)v5 + 760) = 1;
                if ( v32 >= v31 - 1 )
                  LOBYTE(v32) = v31 - 1;
                *((_DWORD *)a2 + 2518) = (-1LL << (v31 + ~(_BYTE)v32)) & (0xFFFFFFFFFFFFFFFFLL >> -(char)v31);
              }
            }
            if ( (*(_BYTE *)(a2[1783] + 32LL) & 8) != 0 )
            {
              v69 = 0;
              v30 = v22;
              goto LABEL_71;
            }
            goto LABEL_75;
          }
        }
LABEL_44:
        v22 = of_get_next_child(v20, v22);
      }
      while ( v22 );
    }
    dev_err(
      a2[1396] + 16LL,
      "No match for speed_bin:%d and soc_code:0x%x\n",
      *((_DWORD *)a2 + 3294),
      *((_DWORD *)a2 + 3297));
    LODWORD(v9) = -19;
    goto LABEL_103;
  }
  v29 = of_find_node_by_name(v18, "qcom,gpu-pwrlevels");
  if ( !v29 )
  {
    dev_err(a2[1396] + 16LL, "Unable to find 'qcom,gpu-pwrlevels'\n");
    LODWORD(v9) = -22;
    goto LABEL_103;
  }
  LODWORD(v9) = adreno_of_parse_pwrlevels(a2, v29);
  if ( (_DWORD)v9 )
    goto LABEL_103;
  adreno_of_get_initial_pwrlevels(a2 + 1104, v18);
  if ( (*(_BYTE *)(a2[1783] + 32LL) & 8) != 0 )
  {
    v30 = v18;
    v69 = 0;
LABEL_71:
    if ( (of_property_read_variable_u32_array(v30, "qcom,throttle-pwrlevel", &v69, 1, 0) & 0x80000000) == 0 )
    {
      v33 = *((_DWORD *)a2 + 2517);
      v34 = v69;
      *((_BYTE *)v5 + 760) = 1;
      if ( v34 >= v33 - 1 )
        LOBYTE(v34) = v33 - 1;
      *((_DWORD *)a2 + 2518) = (-1LL << (v33 + ~(_BYTE)v34)) & (0xFFFFFFFFFFFFFFFFLL >> -(char)v33);
    }
  }
LABEL_75:
  a2[1260] = 80;
  LODWORD(v9) = kgsl_bus_init(a2, a1);
  if ( (_DWORD)v9 )
    goto LABEL_103;
  LODWORD(v9) = kgsl_regmap_init(a1, a2 + 1650, "kgsl_3d0_reg_memory", &adreno_regmap_ops, a2);
  if ( (_DWORD)v9 )
    goto LABEL_77;
  if ( *(_DWORD *)a2[1783] >= 0x1F4u )
  {
    _X8 = a2 + 13;
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr(_X8);
    while ( __stxr(v52 | 1, _X8) );
  }
  if ( *(_DWORD *)a2[1783] >= 0x258u )
  {
    _X8 = a2 + 13;
    __asm { PRFM            #0x11, [X8] }
    do
      v55 = __ldxr(_X8);
    while ( __stxr(v55 | 0x20, _X8) );
  }
  if ( (*(_BYTE *)(a2[1783] + 32LL) & 0x80) != 0 )
  {
    _X8 = a2 + 13;
    __asm { PRFM            #0x11, [X8] }
    do
      v58 = __ldxr(_X8);
    while ( __stxr(v58 | 8, _X8) );
  }
  if ( *(_DWORD *)a2[1783] != 650 )
  {
    _X8 = a2 + 13;
    __asm { PRFM            #0x11, [X8] }
    do
      v61 = __ldxr(_X8);
    while ( __stxr(v61 | 0x80, _X8) );
  }
  if ( adreno_preemption_enable == 1 )
    *((_BYTE *)v5 + 771) = adreno_preemption_enable;
  v36 = a2[1783];
  *((_DWORD *)a2 + 2595) = *(_DWORD *)(v36 + 72);
  *((_BYTE *)a2 + 96) = (*(_BYTE *)(v36 + 32) & 2) != 0;
  v37 = llcc_slice_getd(12);
  a2[2603] = v37;
  LODWORD(v9) = v37 <= 0xFFFFFFFFFFFFF000LL ? 0 : v37;
  if ( (_DWORD)v9 == -517 )
  {
LABEL_77:
    kgsl_bus_close(a2);
LABEL_103:
    a2[1396] = 0;
    dev_err_probe(a1 + 16, (unsigned int)v9, "adreno device probe failed\n");
    goto LABEL_104;
  }
  if ( (_DWORD)v9 != -2 )
  {
    if ( (_DWORD)v9 )
      dev_warn(a1 + 16, "Unable to get the GPU LLC slice: %d\n", v9);
    else
      *((_BYTE *)v5 + 1160) = 1;
  }
  v38 = llcc_slice_getd(11);
  a2[2605] = v38;
  if ( v38 <= 0xFFFFFFFFFFFFF000LL )
    v39 = 0;
  else
    v39 = v38;
  switch ( v39 )
  {
    case 0:
      *((_BYTE *)v5 + 1176) = 1;
LABEL_106:
      if ( !v38 )
        goto LABEL_109;
      goto LABEL_107;
    case -2:
      goto LABEL_106;
    case -517:
      llcc_slice_putd(a2[2603]);
      LODWORD(v9) = -517;
      goto LABEL_77;
  }
  dev_warn(a1 + 16, "Unable to get GPU HTW LLC slice: %d\n", v39);
  v38 = a2[2605];
  if ( v38 )
  {
LABEL_107:
    if ( v38 <= 0xFFFFFFFFFFFFF000LL )
    {
      _X8 = a2 + 13;
      __asm { PRFM            #0x11, [X8] }
      do
        v67 = __ldxr(_X8);
      while ( __stxr(v67 | 0x10, _X8) );
    }
  }
LABEL_109:
  v41 = *(_DWORD *)a2[1783];
  if ( (unsigned int)(v41 - 600) > 0xFFFFFF9B
    || v41 == 203264
    || (unsigned int)(v41 - 703) > 0xFFFFFF98
    || (v41 & 0xFFFF0000) == 0x70000 && (v41 & 0x7FFFE) != 0x70900 && v41 != 462336 && v41 != 463104 )
  {
    _X8 = a2 + 13;
    __asm { PRFM            #0x11, [X8] }
    do
      v64 = __ldxr(_X8);
    while ( __stxr(v64 | 0x200, _X8) );
  }
  LODWORD(v9) = component_bind_all(a1 + 16, 0);
  if ( (_DWORD)v9 )
    goto LABEL_128;
  if ( *((_DWORD *)v5 + 304) )
  {
    LODWORD(v9) = kgsl_request_irq(a1, "kgsl_3d0_irq", adreno_irq_handler, a2);
    if ( (v9 & 0x80000000) != 0 )
      goto LABEL_127;
  }
  else
  {
    LODWORD(v9) = 0;
  }
  *((_DWORD *)a2 + 2208) = v9;
  *((_DWORD *)a2 + 3542) = kgsl_request_irq_optional(a1, "freq_limiter_irq", adreno_freq_limiter_irq_handler, a2);
  a2[1770] = _devm_reset_control_get(a1 + 16, "freq_limiter_irq_clear", 0, 0, 0, 1);
  LODWORD(v9) = kgsl_device_platform_probe(a2);
  if ( (_DWORD)v9 )
  {
LABEL_127:
    component_unbind_all(a1 + 16, 0);
LABEL_128:
    v43 = a2[2603];
    if ( v43 && v43 <= 0xFFFFFFFFFFFFF000LL )
      ((void (*)(void))llcc_slice_putd)();
    v44 = a2[2605];
    if ( v44 && v44 <= 0xFFFFFFFFFFFFF000LL )
      ((void (*)(void))llcc_slice_putd)();
    goto LABEL_77;
  }
  kgsl_regmap_add_region(a2 + 1650, a1, "cx_dbgc", 0, 0);
  kgsl_regmap_add_region(a2 + 1650, a1, "cx_misc", 0, 0);
  if ( !(unsigned int)kgsl_regmap_add_region(a2 + 1650, a1, "isense_cntl", 0, 0) )
    *((_BYTE *)v5 + 767) = 1;
  v42 = *(_DWORD *)(a2[1783] + 32LL) >> 5;
  rt_mutex_lock(a2 + 1386);
  a2[5] = kgsl_allocate_global(a2, 0x8000, 0, 0, v42 & 0x40, "memstore");
  adreno_profile_init(a2);
  rt_mutex_unlock(a2 + 1386);
  v9 = a2[5];
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    trace_array_put(a2[1676]);
    kgsl_device_platform_remove(a2);
    goto LABEL_127;
  }
  if ( !*(_DWORD *)(a2[1783] + 76LL) )
  {
    _warn_printk("The snapshot size was not specified in the gpucore\n");
    __break(0x800u);
  }
  kgsl_device_snapshot_probe(a2);
  adreno_debugfs_init(a2);
  *(_BYTE *)v4 = 0;
  adreno_sysfs_init(a2);
  v45 = *(_QWORD *)(a2[1783] + 32LL);
  if ( (v45 & 0x400000) == 0 )
  {
    v46 = 1779;
LABEL_143:
    LOBYTE(a2[v46]) = 1;
    goto LABEL_144;
  }
  if ( (v45 & 0x4000000) != 0 )
  {
    v46 = 3066;
    goto LABEL_143;
  }
LABEL_144:
  kgsl_pwrscale_init(a2, a1);
  if ( (*(_BYTE *)(a2[1783] + 33LL) & 0x20) != 0 )
    *((_BYTE *)a2 + 13416) = 1;
  if ( !of_find_property(*(_QWORD *)(a1 + 760), "qcom,disable-wake-on-touch", 0) )
  {
    adreno_input_handler = (__int64)a2;
    if ( (unsigned int)input_register_handler() )
    {
      adreno_input_handler = 0;
      dev_err(*a2, "Unable to register the input handler\n");
    }
  }
  if ( a2[1129] || a2[1128] )
  {
    a2[3043] = adreno_pm_notifier;
    register_pm_notifier(a2 + 3043);
  }
  kgsl_qcom_va_md_register(a2);
  printk(&unk_13DC7C);
  LODWORD(v9) = 0;
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v9;
}
