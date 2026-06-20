__int64 __fastcall msm_pdev_probe(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x26
  unsigned int v5; // w24
  unsigned __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x22
  int v9; // w0
  __int64 matched; // x0
  int v11; // w0
  __int64 v12; // x1
  int v13; // w0
  int v14; // w0
  __int64 result; // x0
  int v16; // w23
  int v17; // w23
  unsigned int v18; // w8
  unsigned int v25; // w10
  __int64 v26; // x8
  unsigned int v27; // w22
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x21
  __int64 v31; // x4
  unsigned int v32; // w23
  __int64 v33; // x21
  unsigned int v34; // w0
  __int64 child; // x0
  __int64 v36; // x22
  __int64 v37; // x23
  __int64 next_endpoint; // x0
  __int64 v39; // x24
  unsigned int v40; // w0
  __int64 remote_port_parent; // x0
  __int64 v42; // x27
  unsigned int v43; // w20
  unsigned int v44; // w20
  __int64 v45; // [xsp+0h] [xbp-60h] BYREF
  __int64 v46; // [xsp+8h] [xbp-58h] BYREF
  __int64 v47; // [xsp+10h] [xbp-50h]
  __int64 v48; // [xsp+18h] [xbp-48h]
  __int64 v49; // [xsp+20h] [xbp-40h]
  __int64 v50; // [xsp+28h] [xbp-38h]
  __int64 v51; // [xsp+30h] [xbp-30h]
  __int64 v52; // [xsp+38h] [xbp-28h]
  __int64 v53; // [xsp+40h] [xbp-20h]
  __int64 v54; // [xsp+48h] [xbp-18h]
  __int64 v55; // [xsp+50h] [xbp-10h]
  __int64 v56; // [xsp+58h] [xbp-8h]

  v2 = a1 + 16;
  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 760);
  v45 = 0;
  v46 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(v3, "connectors", 0, 0, 0, &v46) )
  {
    v4 = v46;
    if ( v46 )
    {
      v5 = 1;
      while ( (of_node_name_eq(v4, "qcom,sde_rscc") & 1) == 0 && (of_node_name_eq(v4, "qcom,sde_cesta") & 1) == 0
           || (of_device_is_available(v4) & 1) == 0
           || (*(_QWORD *)(v4 + 232) & 8) == 0 )
      {
        v54 = 0;
        v55 = 0;
        v52 = 0;
        v53 = 0;
        v50 = 0;
        v51 = 0;
        v48 = 0;
        v49 = 0;
        v46 = 0;
        v47 = 0;
        if ( !(unsigned int)_of_parse_phandle_with_args(v3, "connectors", 0, 0, v5, &v46) )
        {
          v4 = v46;
          ++v5;
          if ( v46 )
            continue;
        }
        goto LABEL_12;
      }
      if ( !*(_QWORD *)(of_find_device_by_node(v4) + 168) )
      {
        dev_err(v2, "[%s:%d] qcom,sde_rscc/qcom,sde_cesta not probed yet\n", "msm_drm_component_dependency_check", 2468);
        result = 4294966779LL;
        goto LABEL_76;
      }
    }
  }
LABEL_12:
  v6 = drm_dev_alloc(&msm_driver, v2);
  v7 = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v2, "[%s:%d] failed to allocate drm_device\n", "msm_drm_device_init", 914);
    result = (unsigned int)v7;
    if ( (_DWORD)v7 )
      goto LABEL_76;
    goto LABEL_45;
  }
  drmm_mode_config_init(v6);
  *(_QWORD *)(a1 + 168) = v7;
  v8 = _kmalloc_cache_noprof(kthread_unpark, 3520, 5928);
  if ( !v8 )
  {
    v9 = -12;
LABEL_44:
    v26 = *(_QWORD *)(v8 + 5920);
    v27 = v9;
    kfree(v26);
    drm_dev_put(v7);
    result = v27;
    if ( v27 )
      goto LABEL_76;
    goto LABEL_45;
  }
  *(_QWORD *)(v7 + 56) = v8;
  *(_QWORD *)v8 = v7;
  v9 = hfi_msm_drv_init(v7);
  if ( v9 )
    goto LABEL_44;
  matched = of_match_node(&get_mdp_ver_match_types);
  if ( matched && *(_DWORD *)(matched + 192) == 6 )
  {
    *(_DWORD *)(v8 + 5912) = 1;
  }
  else
  {
    *(_DWORD *)(v8 + 5912) = 0;
    v11 = sde_power_resource_init(a1, (unsigned int *)(v8 + 16));
    if ( v11 )
    {
      v17 = v11;
      printk(&unk_26435A, v12);
      v9 = v17;
      goto LABEL_44;
    }
  }
  v13 = sde_dbg_init(v2);
  if ( v13 )
  {
    v16 = v13;
    dev_err(v2, "[%s:%d] failed to init sde dbg: %d\n", "msm_drm_device_init", 949, v13);
LABEL_42:
    ((void (__fastcall *)(__int64, __int64))sde_power_resource_deinit)(a1, v8 + 16);
    v9 = v16;
    goto LABEL_44;
  }
  pm_runtime_enable(v2);
  if ( *(_DWORD *)(v8 + 5912) )
    goto LABEL_23;
  v14 = _pm_runtime_resume(v2, 4);
  if ( v14 < 0 )
  {
    v18 = *(_DWORD *)(a1 + 496);
    v16 = v14;
    do
    {
      if ( !v18 )
        break;
      _X12 = (unsigned int *)(a1 + 496);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v25 = __ldxr(_X12);
        if ( v25 != v18 )
          break;
        if ( !__stlxr(v18 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v25 == v18;
      v18 = v25;
    }
    while ( !_ZF );
    dev_err(v2, "[%s:%d] failed to enable power resource %d\n", "msm_drm_device_init", 958, v14);
    sde_dbg_destroy();
    goto LABEL_42;
  }
  sde_power_data_bus_set_quota(v8 + 16, 0, 3000000000LL, 3000000000LL);
  sde_power_data_bus_set_quota(v8 + 16, 1u, 3000000000LL, 3000000000LL);
  sde_power_data_bus_set_quota(v8 + 16, 2u, 3000000000LL, 3000000000LL);
  sde_power_data_bus_set_quota(v8 + 16, 3u, 3000000000LL, 3000000000LL);
LABEL_23:
  device_set_wakeup_capable(v2, 1);
  result = device_set_wakeup_enable(v2, 1);
  if ( (result & 0x80000000) != 0 )
  {
    dev_err(v2, "[%s:%d] failed to enable wakeup on device  %d\n", "msm_drm_device_init", 971, result);
    device_set_wakeup_capable(v2, 0);
  }
  else if ( (_DWORD)result )
  {
    goto LABEL_76;
  }
LABEL_45:
  v28 = of_match_node(&get_mdp_ver_match_types);
  if ( v28 && *(_DWORD *)(v28 + 192) == 3
    || (v29 = of_match_node(&get_mdp_ver_match_types)) != 0 && *(_DWORD *)(v29 + 192) == 6 )
  {
    v30 = *(_QWORD *)(a1 + 760);
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    if ( !(unsigned int)_of_parse_phandle_with_args(v30, "connectors", 0, 0, 0, &v46) )
    {
      v31 = v46;
      if ( v46 )
      {
        v32 = 1;
        do
        {
          component_match_add_release(v2, &v45, 0, compare_of, v31);
          v54 = 0;
          v55 = 0;
          v52 = 0;
          v53 = 0;
          v50 = 0;
          v51 = 0;
          v48 = 0;
          v49 = 0;
          v46 = 0;
          v47 = 0;
          if ( (unsigned int)_of_parse_phandle_with_args(v30, "connectors", 0, 0, v32, &v46) )
            break;
          v31 = v46;
          ++v32;
        }
        while ( v46 );
      }
    }
    goto LABEL_70;
  }
  v33 = v2;
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,mdss") )
  {
    v34 = of_platform_populate(*(_QWORD *)(a1 + 760), 0, 0, v2);
    if ( v34 )
    {
      v43 = v34;
      dev_err(v2, "[%s:%d] failed to populate children devices\n", "add_display_components", 2266);
      result = v43;
      goto LABEL_76;
    }
    child = device_find_child(v2, 0, compare_name_mdp);
    if ( !child )
    {
      dev_err(v2, "[%s:%d] failed to find MDSS MDP node\n", "add_display_components", 2272);
      of_platform_depopulate(v2);
      goto LABEL_75;
    }
    v33 = child;
    put_device();
    component_match_add_release(v2, &v45, 0, compare_of, *(_QWORD *)(v33 + 744));
  }
  v36 = *(_QWORD *)(v33 + 744);
  v37 = v33;
  if ( !(unsigned int)of_device_is_compatible(v36, "qcom,mdp4") )
    v37 = *(_QWORD *)(v33 + 96);
  next_endpoint = of_graph_get_next_endpoint(v36, 0);
  if ( !next_endpoint )
  {
LABEL_70:
    if ( v45 )
    {
      *(_QWORD *)(a1 + 664) = 0xFFFFFFFFLL;
      result = component_master_add_with_match(v2, msm_drm_ops);
      goto LABEL_76;
    }
LABEL_75:
    result = 4294967277LL;
    goto LABEL_76;
  }
  v39 = next_endpoint;
  while ( 1 )
  {
    v46 = 0;
    v47 = 0;
    v40 = of_graph_parse_endpoint(v39, &v46);
    if ( v40 )
      break;
    if ( !(unsigned int)of_device_is_compatible(v36, "qcom,mdp4") || (_DWORD)v46 )
    {
      remote_port_parent = of_graph_get_remote_port_parent(v39);
      if ( remote_port_parent )
      {
        v42 = remote_port_parent;
        if ( (of_device_is_available(remote_port_parent) & 1) != 0 )
          drm_of_component_match_add(v37, &v45, compare_of, v42);
      }
    }
    v39 = of_graph_get_next_endpoint(v36, v39);
    if ( !v39 )
      goto LABEL_70;
  }
  v44 = v40;
  dev_err(v33, "[%s:%d] unable to parse port endpoint\n", "add_components_mdp", 2191);
  of_platform_depopulate(v2);
  result = v44;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
