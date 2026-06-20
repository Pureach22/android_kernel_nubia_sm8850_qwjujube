__int64 __fastcall cam_req_mgr_component_master_bind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w0
  unsigned int v4; // w19
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 v10; // x0
  int v11; // w9
  unsigned int v12; // w8
  unsigned int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x0
  unsigned int v20; // w0
  __int64 v21; // x0
  const char *v22; // x5
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x4
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x8
  __int64 v29; // x20
  _QWORD v30[4]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+28h] [xbp-28h] BYREF
  __int64 v32; // [xsp+30h] [xbp-20h]
  __int64 v33; // [xsp+38h] [xbp-18h] BYREF
  __int64 v34; // [xsp+40h] [xbp-10h]
  __int64 v35; // [xsp+48h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  ktime_get_real_ts64(&v33);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_component_master_bind",
      1044,
      "Master bind called");
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(120, 3264, 0, "cam_v4l2_device_setup", 99);
  else
    v2 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  qword_2FDA58 = v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_53;
  }
  v3 = v4l2_device_register(a1, v2);
  if ( v3 )
  {
    v4 = v3;
    if ( mem_trace_en )
      cam_mem_trace_free(qword_2FDA58, 0);
    else
      kvfree(qword_2FDA58);
    qword_2FDA58 = 0;
    result = v4;
    goto LABEL_53;
  }
  if ( mem_trace_en )
    v6 = cam_mem_trace_alloc(696, 3264, 0, "cam_media_device_setup", 62);
  else
    v6 = _kvmalloc_node_noprof(696, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(qword_2FDA58 + 8) = v6;
  if ( !*(_QWORD *)(qword_2FDA58 + 8) )
  {
    v9 = -12;
LABEL_49:
    v4l2_device_unregister(qword_2FDA58);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(qword_2FDA58, 0);
    else
      kvfree(qword_2FDA58);
    result = v9;
    qword_2FDA58 = 0;
    byte_2FDA98 = 0;
    goto LABEL_53;
  }
  media_device_init();
  **(_QWORD **)(qword_2FDA58 + 8) = a1;
  v7 = qword_2FDA58;
  strcpy((char *)(*(_QWORD *)(qword_2FDA58 + 8) + 16LL), "cam-req-mgr-devnode");
  v8 = _media_device_register(*(_QWORD *)(v7 + 8), &_this_module);
  if ( v8 )
  {
    v9 = v8;
LABEL_45:
    v21 = *(_QWORD *)(qword_2FDA58 + 8);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v21, 0);
    else
      kvfree(v21);
    *(_QWORD *)(qword_2FDA58 + 8) = 0;
    goto LABEL_49;
  }
  v10 = video_device_alloc();
  g_dev = v10;
  if ( !v10 )
  {
    v9 = -12;
LABEL_44:
    media_device_unregister(*(_QWORD *)(qword_2FDA58 + 8));
    media_device_cleanup(*(_QWORD *)(qword_2FDA58 + 8));
    goto LABEL_45;
  }
  *(_QWORD *)(v10 + 1104) = qword_2FDA58;
  v11 = *(_DWORD *)(v10 + 176);
  *(_DWORD *)(v10 + 1208) = 0;
  strcpy((char *)(v10 + 1144), "cam-req-mgr");
  *(_QWORD *)(v10 + 1272) = &video_device_release_empty;
  *(_QWORD *)(v10 + 168) = &g_cam_fops;
  *(_QWORD *)(v10 + 1280) = &g_cam_ioctl_ops;
  *(_DWORD *)(v10 + 1216) = -1;
  *(_DWORD *)(v10 + 176) = v11 | 1;
  v12 = _video_register_device();
  if ( v12 )
  {
    v9 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_video_device_setup",
      863,
      "video device registration failure rc = %d, name = %s, device_caps = %d",
      v12,
      (const char *)(g_dev + 1144),
      *(_DWORD *)(g_dev + 176));
LABEL_43:
    video_device_release(g_dev);
    g_dev = 0;
    goto LABEL_44;
  }
  v13 = media_entity_pads_init(g_dev, 0, 0);
  v14 = g_dev;
  if ( v13 )
  {
    v9 = v13;
LABEL_42:
    video_unregister_device(v14);
    goto LABEL_43;
  }
  v15 = *(_QWORD *)(g_dev + 296);
  *(_DWORD *)(g_dev + 44) = 0x10000;
  if ( !v15 )
    v15 = *(_QWORD *)(v14 + 184);
  *(_QWORD *)(v14 + 32) = v15;
  dword_2FDA9C = 0;
  byte_2FDAE4 = 0;
  _mutex_init(&unk_2FDAA8, "&g_dev.cam_lock", &cam_req_mgr_component_master_bind___key);
  dword_2FDAE0 = 0;
  v16 = _mutex_init(&unk_2FDA68, "&g_dev.dev_lock", &cam_req_mgr_component_master_bind___key_18);
  v17 = cam_req_mgr_util_init(v16);
  if ( v17 )
  {
    v9 = v17;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_component_master_bind",
      1065,
      "cam req mgr util init is failed");
LABEL_41:
    v14 = g_dev;
    goto LABEL_42;
  }
  v18 = cam_req_mgr_core_device_init();
  if ( v18 )
  {
    v9 = v18;
    v19 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_component_master_bind",
            1071,
            "core device setup failed");
LABEL_40:
    cam_req_mgr_util_deinit(v19);
    goto LABEL_41;
  }
  cam_req_mgr_ordered_sd_list = (__int64)&cam_req_mgr_ordered_sd_list;
  qword_2FDAF0 = (__int64)&cam_req_mgr_ordered_sd_list;
  if ( !g_cam_req_mgr_timer_cachep )
  {
    memset(&v30[1], 0, 24);
    v30[0] = 8;
    g_cam_req_mgr_timer_cachep = _kmem_cache_create_args("cam_req_mgr_timer", 72, v30, 0);
    if ( g_cam_req_mgr_timer_cachep )
    {
      if ( (debug_mdl & 0x10) == 0 || debug_priority )
        goto LABEL_34;
      v22 = "Name : cam_req_mgr_timer";
      v23 = debug_mdl & 0x10;
      v24 = 4;
      v25 = 1083;
    }
    else
    {
      v22 = "Failed to create kmem_cache for crm_timer";
      v23 = 16;
      v24 = 1;
      v25 = 1081;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v23,
      v24,
      "cam_req_mgr_component_master_bind",
      v25,
      v22);
  }
LABEL_34:
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_component_master_bind",
      1086,
      "All probes done, binding slave components");
  byte_2FDA98 = 1;
  v20 = component_bind_all(a1, 0);
  if ( v20 )
  {
    v9 = v20;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_component_master_bind",
      1092,
      "Error in binding all components rc: %d, Camera initialization failed!",
      v20);
LABEL_39:
    kmem_cache_destroy(g_cam_req_mgr_timer_cachep);
    g_cam_req_mgr_timer_cachep = 0;
    v19 = cam_req_mgr_core_device_deinit();
    goto LABEL_40;
  }
  ktime_get_real_ts64(&v31);
  v26 = v32;
  if ( v32 >= v34 )
  {
    v27 = v31 - v33;
  }
  else
  {
    v26 = v32 + 1000000000;
    v27 = v31 + ~v33;
  }
  v28 = (unsigned __int128)((v26 - v34) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  v29 = (v28 >> 7) + ((unsigned __int64)v28 >> 63) + 1000000 * v27;
  cam_req_mgr_debug_record_bind_time(v29);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    16,
    3,
    "cam_req_mgr_component_master_bind",
    1103,
    "All components bound successfully, Spectra camera driver initialized, Time taken(usec): %lu",
    v29);
  result = sysfs_create_file_ns(a1, &camera_debug_sysfs_attr, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_req_mgr_component_master_bind",
      1124,
      "Failed to create debug attribute, rc=%d\n",
      result);
    sysfs_remove_file_ns(a1, &camera_debug_sysfs_attr, 0);
    goto LABEL_39;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
