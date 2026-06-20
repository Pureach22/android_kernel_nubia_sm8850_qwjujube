__int64 __fastcall msm_drm_bind(__int64 a1)
{
  __int64 v1; // d8
  __int64 v2; // d14
  __int64 v3; // x22
  __int64 v4; // x26
  _QWORD *v5; // x27
  __int64 v6; // x24
  unsigned int v7; // w0
  unsigned int v8; // w23
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 matched; // x0
  int v14; // w8
  __int64 (***v15)(void); // x0
  unsigned __int64 v16; // x20
  __int64 (*v17)(void); // x8
  int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x25
  unsigned __int64 v21; // x28
  __int64 v22; // x23
  _QWORD *v23; // x21
  __int64 v24; // x20
  __int64 v25; // x22
  int v26; // w4
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x19
  __int64 v29; // x8
  __int64 v30; // x20
  int v31; // w4
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x19
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x0
  unsigned __int64 v36; // x19
  unsigned int v37; // w0
  _QWORD *i; // x19
  unsigned int irq; // w0
  _QWORD *v40; // x6
  unsigned int v41; // w21
  __int64 v42; // x0
  void (*v43)(void); // x8
  _DWORD *v44; // x8
  unsigned int v45; // w0
  __int64 v47; // x8
  unsigned int v48; // w0
  __int64 (__fastcall *v49)(_QWORD); // x8
  unsigned int v50; // w0
  unsigned int v51; // w0
  __int64 v52; // x0
  unsigned __int64 v53; // x21
  __int64 v54; // x0
  __int64 (*v55)(void); // x8
  unsigned int v56; // w8
  unsigned int v63; // w10
  int v64; // w21
  __int64 v65; // x19
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  _QWORD *v70; // [xsp+0h] [xbp-80h]
  __int64 v71; // [xsp+10h] [xbp-70h]
  __int64 v72; // [xsp+18h] [xbp-68h] BYREF
  __int64 v73; // [xsp+20h] [xbp-60h]
  __int64 v74; // [xsp+28h] [xbp-58h]
  __int64 v75; // [xsp+30h] [xbp-50h]
  __int64 v76; // [xsp+38h] [xbp-48h]
  __int64 v77; // [xsp+40h] [xbp-40h]
  __int64 v78; // [xsp+48h] [xbp-38h]
  __int64 v79; // [xsp+50h] [xbp-30h]
  __int64 v80; // [xsp+58h] [xbp-28h]
  __int64 v81; // [xsp+60h] [xbp-20h]
  __int64 v82; // [xsp+68h] [xbp-18h]
  __int64 v83; // [xsp+70h] [xbp-10h]
  __int64 v84; // [xsp+78h] [xbp-8h]

  v3 = a1;
  v4 = a1 - 16;
  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 152);
  v6 = v5[7];
  *(_QWORD *)(v6 + 688) = alloc_workqueue("msm_drm", 131074, 1);
  _init_waitqueue_head(v6 + 704, "&priv->pending_crtcs_event", &msm_drm_component_init___key);
  *(_QWORD *)(v6 + 5664) = v6 + 5664;
  *(_QWORD *)(v6 + 5672) = v6 + 5664;
  *(_QWORD *)(v6 + 624) = v6 + 624;
  *(_QWORD *)(v6 + 632) = v6 + 624;
  *(_QWORD *)(v6 + 5752) = v6 + 5752;
  *(_QWORD *)(v6 + 5760) = v6 + 5752;
  *(_QWORD *)(v6 + 5816) = v6 + 5816;
  *(_QWORD *)(v6 + 5824) = v6 + 5816;
  _init_rwsem(v6 + 5840, "&(&priv->component_notifier_list)->rwsem", &msm_drm_component_init___key_79);
  *(_QWORD *)(v6 + 5904) = 0;
  _mutex_init(v6 + 640, "&priv->mm_lock", &msm_drm_component_init___key_81);
  _mutex_init(v6 + 5704, "&priv->vm_client_lock", &msm_drm_component_init___key_83);
  _mutex_init(v6 + 5768, "&priv->fence_error_client_lock", &msm_drm_component_init___key_85);
  v7 = component_bind_all(v3, v5);
  if ( v7 )
  {
    v8 = v7;
    _drm_err("component_bind_all failed: %d\n", v7);
    if ( v8 == -517 )
    {
      destroy_workqueue(*(_QWORD *)(v6 + 688));
    }
    else
    {
      sde_dbg_destroy();
      ((void (__fastcall *)(__int64, __int64))sde_power_resource_deinit)(v4, v6 + 16);
      drm_dev_put(v5);
    }
    goto LABEL_60;
  }
  v9 = v5[7];
  v10 = *(_QWORD *)(v5[1] + 744LL);
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v10, "memory-region", 0, 0, 0, &v72) || (v11 = v72) == 0 )
  {
    if ( (iommu_present(&platform_bus_type) & 1) != 0 )
      goto LABEL_10;
    v52 = *(_QWORD *)(v5[1] + 744LL);
    LODWORD(v72) = 0;
    if ( (of_property_read_variable_u32_array(v52, "qcom,vram-size", &v72, 1, 0) & 0x80000000) != 0 )
      v53 = memparse(vram, 0);
    else
      v53 = (unsigned int)v72;
    printk(&unk_251F5B, v53);
  }
  else
  {
    v82 = 0;
    v83 = 0;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v12 = of_address_to_resource(v11, 0, &v72);
    if ( v12 )
    {
      v8 = v12;
      goto LABEL_59;
    }
    v53 = v73 - v72;
    printk(&unk_26B0EC, v73 - v72);
  }
  if ( v53 )
  {
    *(_QWORD *)(v9 + 5232) = v53;
    drm_mm_init(v9 + 5248, 0, (v53 >> 12) - 1);
    *(_DWORD *)(v9 + 5488) = 0;
    v68 = dma_alloc_attrs(v5[1], v53, v9 + 5240, 3264, 20);
    v69 = v5[1];
    if ( !v68 )
    {
      dev_err(v69, "[%s:%d] failed to allocate VRAM\n", "msm_init_vram", 726);
      *(_QWORD *)(v9 + 5240) = 0;
      v8 = -12;
      goto LABEL_59;
    }
    dev_info(v69, "VRAM: %08x->%08x\n", *(_DWORD *)(v9 + 5240), *(_DWORD *)(v9 + 5240) + v53);
  }
LABEL_10:
  v5[116] = &mode_config_funcs;
  v5[202] = &mode_config_helper_funcs;
  matched = of_match_node(&get_mdp_ver_match_types);
  if ( !matched )
    goto LABEL_72;
  v14 = *(_DWORD *)(matched + 192);
  if ( v14 != 3 && v14 != 6 )
  {
    if ( (unsigned int)(v14 - 4) >= 2 )
    {
      v16 = -19;
      goto LABEL_73;
    }
LABEL_72:
    v16 = 0;
LABEL_73:
    dev_err(v3, "[%s:%d] failed to load kms\n", "_msm_drm_component_init_helper", 881);
    goto LABEL_19;
  }
  v15 = (__int64 (***)(void))sde_kms_init((__int64)v5);
  v16 = (unsigned __int64)v15;
  if ( !v15 || (unsigned __int64)v15 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_73;
  *(_QWORD *)(v6 + 8) = v15;
  v5[116] = &mode_config_funcs;
  v17 = **v15;
  if ( *((_DWORD *)v17 - 1) != -543790661 )
    __break(0x8228u);
  v18 = v17();
  if ( v18 )
  {
    v64 = v18;
    dev_err(v3, "[%s:%d] kms hw init failed: %d\n", "_msm_drm_component_init_helper", 897, v18);
    v16 = v64;
  }
LABEL_19:
  if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v3, "[%s:%d] msm_drm_component_init_helper failed\n", "msm_drm_component_init", 1033);
    v8 = 0;
    goto LABEL_59;
  }
  v70 = (_QWORD *)v16;
  v71 = v3;
  if ( v5 )
  {
    v19 = v5[7];
    if ( v19 )
      blocking_notifier_call_chain(v19 + 5840, 0);
  }
  if ( *(_DWORD *)(v6 + 992) )
  {
    v20 = 0;
    v21 = 0;
    v22 = v6 + 3752;
    v23 = (_QWORD *)(v6 + 3776);
    while ( 1 )
    {
      if ( v20 == 1280 )
        __break(0x5512u);
      v24 = v6 + 8 * v21;
      v25 = v6 + v20;
      *(_DWORD *)(v6 + v20 + 1144) = *(_DWORD *)(*(_QWORD *)(v24 + 1000) + 112LL);
      _kthread_init_worker(
        v6 + v20 + 1152,
        "(&priv->disp_thread[i].worker)->lock",
        &msm_drm_display_thread_create___key);
      v26 = *(_DWORD *)(v6 + v20 + 1144);
      *(_QWORD *)(v6 + v20 + 1128) = v5;
      v27 = kthread_create_on_node(&kthread_worker_fn, v6 + v20 + 1152, 0xFFFFFFFFLL, "crtc_commit:%d", v26);
      v28 = v27;
      if ( v27 <= 0xFFFFFFFFFFFFF000LL )
        wake_up_process(v27);
      *(_QWORD *)(v25 + 1136) = v28;
      *v23 = 0;
      *(_QWORD *)(v6 + 3784) = 0;
      *(_QWORD *)(v6 + 3752) = v6 + 3752;
      *(_QWORD *)(v6 + 3760) = v22;
      *(_QWORD *)(v6 + 3768) = msm_drm_display_thread_priority_worker;
      kthread_queue_work(v25 + 1152, v6 + 3752);
      kthread_flush_work(v6 + 3752);
      if ( *(_QWORD *)(v25 + 1136) >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(v71, "[%s:%d] failed to create crtc_commit kthread\n", "msm_drm_display_thread_create", 779);
        *(_QWORD *)(v25 + 1136) = 0;
      }
      v29 = *(_QWORD *)(v24 + 1000);
      v30 = v6 + v20;
      *(_DWORD *)(v6 + v20 + 2424) = *(_DWORD *)(v29 + 112);
      _kthread_init_worker(
        v6 + v20 + 2432,
        "(&priv->event_thread[i].worker)->lock",
        &msm_drm_display_thread_create___key_108);
      v31 = *(_DWORD *)(v6 + v20 + 2424);
      *(_QWORD *)(v6 + v20 + 2408) = v5;
      v32 = kthread_create_on_node(&kthread_worker_fn, v6 + v20 + 2432, 0xFFFFFFFFLL, "crtc_event:%d", v31);
      v33 = v32;
      if ( v32 <= 0xFFFFFFFFFFFFF000LL )
        wake_up_process(v32);
      *(_QWORD *)(v30 + 2416) = v33;
      *v23 = 0;
      *(_QWORD *)(v6 + 3784) = 0;
      *(_QWORD *)(v6 + 3752) = v6 + 3752;
      *(_QWORD *)(v6 + 3760) = v22;
      *(_QWORD *)(v6 + 3768) = msm_drm_display_thread_priority_worker;
      kthread_queue_work(v30 + 2432, v6 + 3752);
      kthread_flush_work(v6 + 3752);
      v34 = *(_QWORD *)(v30 + 2416);
      if ( v34 > 0xFFFFFFFFFFFFF000LL )
        break;
      if ( !v34 || !*(_QWORD *)(v25 + 1136) )
        goto LABEL_100;
      ++v21;
      v20 += 80;
      if ( v21 >= *(unsigned int *)(v6 + 992) )
        goto LABEL_37;
    }
    dev_err(v71, "[%s:%d] failed to create crtc_event kthread\n", "msm_drm_display_thread_create", 804);
    *(_QWORD *)(v6 + v20 + 2416) = 0;
    do
    {
LABEL_100:
      v65 = v6 + v20;
      v66 = *(_QWORD *)(v6 + v20 + 1136);
      if ( v66 )
      {
        kthread_stop(v66);
        *(_QWORD *)(v65 + 1136) = 0;
      }
      v67 = *(_QWORD *)(v65 + 2416);
      if ( v67 )
      {
        kthread_stop(v67);
        *(_QWORD *)(v65 + 2416) = 0;
      }
      v20 -= 80;
    }
    while ( v20 != -80 );
    v3 = v71;
    v8 = -22;
    goto LABEL_105;
  }
LABEL_37:
  _kthread_init_worker(v6 + 3696, "(&priv->pp_event_worker)->lock", &msm_drm_display_thread_create___key_112);
  v35 = kthread_create_on_node(&kthread_worker_fn, v6 + 3696, 0xFFFFFFFFLL, "pp_event");
  v36 = v35;
  if ( v35 <= 0xFFFFFFFFFFFFF000LL )
    wake_up_process(v35);
  *(_QWORD *)(v6 + 3688) = v36;
  *(_QWORD *)(v6 + 3776) = 0;
  *(_QWORD *)(v6 + 3784) = 0;
  *(_QWORD *)(v6 + 3752) = v6 + 3752;
  *(_QWORD *)(v6 + 3760) = v6 + 3752;
  *(_QWORD *)(v6 + 3768) = msm_drm_display_thread_priority_worker;
  kthread_queue_work(v6 + 3696, v6 + 3752);
  kthread_flush_work(v6 + 3752);
  v3 = v71;
  if ( *(_QWORD *)(v6 + 3688) >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v71, "[%s:%d] failed to create pp_event kthread\n", "msm_drm_display_thread_create", 841);
    v8 = *(_DWORD *)(v6 + 3688);
    *(_QWORD *)(v6 + 3688) = 0;
    if ( v8 )
    {
LABEL_105:
      dev_err(v3, "[%s:%d] msm_drm_display_thread_create failed\n", "msm_drm_component_init", 1044);
      goto LABEL_59;
    }
  }
  v37 = drm_vblank_init(v5, *(unsigned int *)(v6 + 992));
  if ( (v37 & 0x80000000) != 0 )
  {
    v8 = v37;
    dev_err(v71, "[%s:%d] failed to initialize vblank\n", "msm_drm_component_init", 1050);
    goto LABEL_59;
  }
  for ( i = (_QWORD *)v5[108]; i != v5 + 108; i = (_QWORD *)*i )
    drm_crtc_vblank_reset(i - 2);
  v8 = _pm_runtime_resume(v71, 4);
  if ( (v8 & 0x80000000) != 0 )
  {
    v56 = *(_DWORD *)(v71 + 480);
    do
    {
      if ( !v56 )
        break;
      _X12 = (unsigned int *)(v71 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v63 = __ldxr(_X12);
        if ( v63 != v56 )
          break;
        if ( !__stlxr(v56 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v63 == v56;
      v56 = v63;
    }
    while ( !_ZF );
    dev_err(v71, "[%s:%d] failed to enable power resource %d\n", "msm_drm_component_init", 1060, v8);
    goto LABEL_59;
  }
  if ( *(_DWORD *)(v6 + 5912) )
  {
    _pm_runtime_idle(v71, 4);
    goto LABEL_53;
  }
  irq = platform_get_irq(v4, 0);
  if ( irq == 0x80000000 )
  {
    v8 = -107;
    goto LABEL_52;
  }
  v41 = irq;
  v42 = *(_QWORD *)(v5[7] + 8LL);
  if ( v42 )
  {
    v43 = *(void (**)(void))(*(_QWORD *)v42 + 16LL);
    if ( *((_DWORD *)v43 - 1) != -2100390869 )
      __break(0x8228u);
    v43();
    v8 = request_threaded_irq(v41, msm_irq, 0, 0x200000, *(_QWORD *)(v5[6] + 152LL), v5);
    if ( v8 )
    {
LABEL_52:
      msm_sde_qtimer_install(v71);
      _pm_runtime_idle(v71, 4);
      if ( (v8 & 0x80000000) != 0 )
      {
        dev_err(v71, "[%s:%d] failed to install IRQ handler\n", "msm_drm_component_init", 1075);
        goto LABEL_59;
      }
LABEL_53:
      drm_mode_config_reset(v5);
      if ( *v70 )
      {
        v44 = *(_DWORD **)(*v70 + 264LL);
        if ( v44 )
        {
          if ( *(v44 - 1) != 265361133 )
            __break(0x8228u);
          v45 = ((__int64 (__fastcall *)(_QWORD *, _QWORD))v44)(v70, 0);
          if ( v45 )
          {
            v8 = v45;
            dev_err(v71, "[%s:%d] kms cont_splash config failed.\n", "msm_drm_component_init", 1085);
            goto LABEL_59;
          }
        }
      }
      v8 = drm_dev_register(v5, 0);
      if ( !v8 )
      {
        v47 = *(_QWORD *)(v6 + 592);
        *(_BYTE *)(v6 + 5680) = 1;
        if ( !v47 )
        {
          v51 = drm_client_init(v5, v70 + 3, "kms_client", 0);
          if ( v51 )
          {
            v8 = v51;
            _drm_err("failed to init kms_client: %d\n", v51);
            v70[3] = 0;
            goto LABEL_59;
          }
          drm_client_register(v70 + 3);
        }
        v48 = sde_dbg_debugfs_register(v71);
        if ( v48 )
        {
          v8 = v48;
          dev_err(v71, "[%s:%d] failed to reg sde dbg debugfs: %d\n", "msm_drm_component_init", 1115, v48);
        }
        else
        {
          if ( !*v70 )
            goto LABEL_68;
          v49 = *(__int64 (__fastcall **)(_QWORD))(*v70 + 8LL);
          if ( !v49 )
            goto LABEL_68;
          if ( *((_DWORD *)v49 - 1) != -543790661 )
            __break(0x8228u);
          v50 = v49(v70);
          if ( !v50 )
          {
LABEL_68:
            drm_kms_helper_poll_init(v5);
            v8 = 0;
            goto LABEL_60;
          }
          v8 = v50;
          printk(&unk_24B13A, v50);
        }
      }
LABEL_59:
      ((void (__fastcall *)(__int64))msm_drm_uninit)(v3);
LABEL_60:
      _ReadStatusReg(SP_EL0);
      return v8;
    }
    v54 = *(_QWORD *)(v5[7] + 8LL);
    if ( v54 )
    {
      v55 = *(__int64 (**)(void))(*(_QWORD *)v54 + 24LL);
      if ( v55 )
      {
        if ( *((_DWORD *)v55 - 1) != -543790661 )
          __break(0x8228u);
        v8 = v55();
        if ( v8 )
          free_irq(v41, v5);
      }
      else
      {
        v8 = 0;
      }
      goto LABEL_52;
    }
  }
  else
  {
    __break(0x800u);
  }
  __break(0x800u);
  *v40 = v1;
  v40[1] = v2;
  return msm_drm_unbind();
}
