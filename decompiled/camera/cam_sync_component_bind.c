__int64 __fastcall cam_sync_component_bind(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 i; // x8
  _QWORD *v7; // x22
  __int64 v8; // x0
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x0
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x8
  unsigned int v15; // w0
  __int64 v16; // x8
  unsigned int v17; // w0
  __int64 v18; // x3
  unsigned __int64 *v19; // x8
  __int64 v20; // x9
  unsigned __int64 v21; // x9
  __int64 v22; // x10
  __int64 v24; // x0
  unsigned int v25; // w0
  __int64 debugfs; // x0
  unsigned int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x22
  _QWORD *v30; // x0
  unsigned __int64 v36; // x8
  _QWORD v37[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v38[3]; // [xsp+18h] [xbp-18h] BYREF

  v38[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38[0] = 0;
  v38[1] = 0;
  v37[0] = 0;
  v37[1] = 0;
  ktime_get_real_ts64(v38);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(8688, 0xCC0u, 0, "cam_sync_component_bind", 0xADDu);
  else
    v2 = _kvmalloc_node_noprof(8688, 0, 3520, 0xFFFFFFFFLL);
  sync_dev = v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_52;
  }
  v3 = vzalloc_noprof(442368);
  v4 = sync_dev;
  *(_QWORD *)(sync_dev + 128) = v3;
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_component_bind",
      2787,
      "Mem Allocation failed for sync table");
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)sync_dev, 0);
    else
      kvfree(sync_dev);
    result = 4294967284LL;
    goto LABEL_52;
  }
  v5 = _mutex_init(v4 + 8328, "&sync_dev->table_lock", &cam_sync_component_bind___key);
  *(_DWORD *)(sync_dev + 8408) = 0;
  for ( i = 34; i != 2082; ++i )
    *(_DWORD *)(sync_dev + 4 * i) = 0;
  *(_QWORD *)sync_dev = video_device_alloc(v5);
  v7 = (_QWORD *)sync_dev;
  if ( !*(_QWORD *)sync_dev )
  {
    v10 = -12;
LABEL_48:
    vfree(v7[16]);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)sync_dev, 0);
    else
      kvfree(sync_dev);
    result = v10;
    goto LABEL_52;
  }
  if ( mem_trace_en == 1 )
  {
    v8 = cam_mem_trace_alloc(696, 0xCC0u, 0, "cam_sync_media_controller_init", 0xA30u);
    v7[2] = v8;
    if ( !v8 )
      goto LABEL_46;
  }
  else
  {
    v11 = _kvmalloc_node_noprof(696, 0, 3520, 0xFFFFFFFFLL);
    v7[2] = v11;
    if ( !v11 )
    {
LABEL_46:
      v10 = -12;
      goto LABEL_47;
    }
  }
  media_device_init();
  strcpy((char *)(v7[2] + 16LL), "cam_sync_device");
  *(_QWORD *)v7[2] = a1;
  v12 = _media_device_register(v7[2], &_this_module);
  if ( (v12 & 0x80000000) != 0 )
  {
    v10 = v12;
LABEL_31:
    media_device_cleanup(v7[2]);
LABEL_47:
    video_unregister_device(*(_QWORD *)sync_dev);
    video_device_release(*(_QWORD *)sync_dev);
    v7 = (_QWORD *)sync_dev;
    goto LABEL_48;
  }
  v13 = media_entity_pads_init(*v7, 0, 0);
  if ( (v13 & 0x80000000) != 0 )
  {
    v10 = v13;
    media_device_unregister(v7[2]);
    goto LABEL_31;
  }
  v14 = sync_dev;
  *(_QWORD *)(*(_QWORD *)sync_dev + 1104LL) = sync_dev + 8;
  v15 = v4l2_device_register(a1, *(_QWORD *)(*(_QWORD *)v14 + 1104LL));
  if ( (v15 & 0x80000000) != 0 )
  {
    v10 = v15;
    goto LABEL_39;
  }
  v16 = sync_dev;
  strcpy((char *)(*(_QWORD *)sync_dev + 1144LL), "cam_sync");
  *(_QWORD *)(*(_QWORD *)v16 + 1272LL) = &video_device_release_empty;
  *(_QWORD *)(*(_QWORD *)v16 + 168LL) = &cam_sync_v4l2_fops;
  *(_QWORD *)(*(_QWORD *)v16 + 1280LL) = &g_cam_sync_ioctl_ops;
  *(_DWORD *)(*(_QWORD *)v16 + 1216LL) = -1;
  *(_DWORD *)(*(_QWORD *)v16 + 176LL) |= 1u;
  *(_DWORD *)(*(_QWORD *)v16 + 1208LL) = 0;
  v17 = _video_register_device();
  v19 = (unsigned __int64 *)sync_dev;
  v20 = *(_QWORD *)sync_dev;
  if ( (v17 & 0x80000000) != 0 )
  {
    v10 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_component_bind",
      2826,
      "video device registration failure rc = %d, name = %s, device_caps = %d",
      v17,
      (const char *)(v20 + 1144),
      *(_DWORD *)(v20 + 176));
LABEL_38:
    v4l2_device_unregister(*(_QWORD *)(*(_QWORD *)sync_dev + 1104LL));
LABEL_39:
    v29 = sync_dev;
    media_device_unregister(*(_QWORD *)(sync_dev + 16));
    media_device_cleanup(*(_QWORD *)(v29 + 16));
    v30 = *(_QWORD **)(v29 + 16);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v30, 0);
    else
      kvfree(v30);
    goto LABEL_47;
  }
  *(_DWORD *)(v20 + 44) = 0x10000;
  v21 = *v19;
  v22 = *(_QWORD *)(*v19 + 296);
  if ( !v22 )
    v22 = *(_QWORD *)(v21 + 184);
  *(_QWORD *)(v21 + 32) = v22;
  *(_QWORD *)(*v19 + 336) = v19;
  _X9 = v19 + 1052;
  v19[1083] = 0;
  v19[1082] = 0;
  v19[1081] = 0;
  v19[1080] = 0;
  v19[1079] = 0;
  v19[1078] = 0;
  v19[1077] = 0;
  v19[1076] = 0;
  v19[1075] = 0;
  v19[1074] = 0;
  v19[1073] = 0;
  v19[1072] = 0;
  v19[1071] = 0;
  v19[1070] = 0;
  v19[1069] = 0;
  v19[1068] = 0;
  v19[1067] = 0;
  v19[1066] = 0;
  v19[1065] = 0;
  v19[1064] = 0;
  v19[1063] = 0;
  v19[1062] = 0;
  v19[1061] = 0;
  v19[1060] = 0;
  v19[1059] = 0;
  v19[1058] = 0;
  v19[1057] = 0;
  v19[1056] = 0;
  v19[1055] = 0;
  v19[1054] = 0;
  v19[1053] = 0;
  v19[1052] = 0;
  __asm { PRFM            #0x11, [X9] }
  do
    v36 = __ldxr(_X9);
  while ( __stxr(v36 | 1, _X9) );
  v24 = alloc_workqueue("HIPRIO_SYNC_WORK_QUEUE", 18, 1, v18);
  *(_QWORD *)(sync_dev + 8392) = v24;
  if ( !v24 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_component_bind",
      2845,
      "Error: high priority work queue creation failed");
    v10 = -12;
    goto LABEL_38;
  }
  v25 = cam_dma_fence_driver_init();
  if ( v25 )
  {
    v10 = v25;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_component_bind",
      2854,
      "DMA fence driver initialization failed rc: %d",
      v25);
LABEL_37:
    destroy_workqueue(*(_QWORD *)(sync_dev + 8392));
    goto LABEL_38;
  }
  trigger_cb_without_switch = 0;
  cam_sync_monitor_mask = 0;
  debugfs = cam_sync_create_debugfs();
  v27 = cam_synx_obj_driver_init(debugfs);
  if ( v27 )
  {
    v10 = v27;
    v28 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_sync_component_bind",
            2866,
            "Synx obj driver initialization failed rc: %d",
            v27);
    cam_dma_fence_driver_deinit(v28);
    goto LABEL_37;
  }
  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      (unsigned __int8)debug_mdl & 0x80,
      4,
      "cam_sync_component_bind",
      2876,
      "Component bound successfully");
  ktime_get_real_ts64(v37);
  cam_record_bind_latency();
  result = 0;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
