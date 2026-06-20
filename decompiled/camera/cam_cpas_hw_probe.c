__int64 __fastcall cam_cpas_hw_probe(__int64 *a1, _QWORD *a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x9
  __int64 v11; // x3
  __int64 v12; // x0
  __int64 v13; // x0
  int string_helper; // w0
  size_t v15; // x0
  int internal_ops; // w0
  unsigned int v17; // w22
  size_t v18; // x0
  __int64 v19; // x0
  __int64 v20; // x25
  __int64 v21; // x1
  unsigned int v22; // w0
  unsigned int v23; // w24
  unsigned int file_ns; // w0
  __int64 (__fastcall *v25)(__int64, __int64, __int64); // x8
  __int64 v26; // x24
  __int64 i; // x25
  unsigned int v28; // w0
  unsigned int v29; // w0
  unsigned int v30; // w0
  const char *v31; // x5
  __int64 v32; // x4
  __int64 (__fastcall *v33)(__int64, __int64); // x8
  unsigned int v34; // w0
  const char *v35; // x5
  __int64 v36; // x4
  unsigned int subpart_info; // w0
  unsigned int v38; // w0
  int debugfs; // w0
  __int64 result; // x0
  __int64 v41; // [xsp+10h] [xbp-20h]
  __int64 v42; // [xsp+18h] [xbp-18h]
  const char *v43[2]; // [xsp+20h] [xbp-10h] BYREF

  v43[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_cpas_hw_probe", 0x1471u);
  else
    v4 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v5 = (_QWORD *)v4;
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_91;
  }
  if ( mem_trace_en == 1 )
    v6 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_cpas_hw_probe", 0x1475u);
  else
    v6 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
  v7 = v6;
  if ( !v6 )
  {
    if ( !mem_trace_en )
    {
LABEL_76:
      kvfree(v5);
      result = 4294967284LL;
      goto LABEL_91;
    }
LABEL_71:
    cam_mem_trace_free(v5, 0);
    result = 4294967284LL;
    goto LABEL_91;
  }
  if ( mem_trace_en )
    v8 = cam_mem_trace_alloc(159464, 0xCC0u, 0, "cam_cpas_hw_probe", 0x147Bu);
  else
    v8 = _kvmalloc_node_noprof(159464, 0, 3520, 0xFFFFFFFFLL);
  v9 = v8;
  if ( !v8 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v7, 0);
    else
      kvfree(v7);
    if ( mem_trace_en != 1 )
      goto LABEL_76;
    goto LABEL_71;
  }
  *(_QWORD *)(v8 + 2836) = -1;
  *(_QWORD *)(v8 + 2844) = -1;
  *(_QWORD *)(v8 + 2820) = -1;
  *(_QWORD *)(v8 + 2828) = -1;
  *(_QWORD *)(v8 + 2812) = -1;
  v5[14] = v7;
  *(_QWORD *)(v7 + 3680) = v8;
  *(_DWORD *)(v7 + 92) = 0;
  *(_QWORD *)(v7 + 96) = a1;
  *(_QWORD *)(v7 + 104) = a1 + 2;
  v10 = *a1;
  *(_DWORD *)(v7 + 88) = 0;
  *(_QWORD *)(v7 + 120) = v10;
  *(_BYTE *)(v8 + 8144) = 0;
  *(_WORD *)(v8 + 159425) = 0;
  *(_BYTE *)(v8 + 159434) = 0;
  *(_QWORD *)(v8 + 8216) = -1;
  _mutex_init(v7, "&cpas_hw->hw_mutex", &cam_cpas_hw_probe___key);
  *(_DWORD *)(v7 + 48) = 0;
  *(_DWORD *)(v7 + 56) = 0;
  _init_swait_queue_head(v7 + 64, "&x->wait", &init_completion___key_1);
  v5[1] = cam_cpas_hw_get_hw_info;
  v5[2] = cam_cpas_hw_init;
  v5[7] = &cam_cpas_hw_start;
  v5[8] = &cam_cpas_hw_stop;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v5[6] = 0;
  v5[9] = 0;
  v5[10] = 0;
  v5[11] = cam_cpas_hw_process_cmd;
  v12 = alloc_workqueue("cam-cpas", 10, 5, v11);
  *(_QWORD *)(v9 + 8096) = v12;
  if ( !v12 )
  {
    v17 = -12;
LABEL_81:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v9, 0);
    else
      kvfree(v9);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v7, 0);
    else
      kvfree(v7);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      5431,
      "failed in hw probe");
    result = v17;
    goto LABEL_91;
  }
  v13 = a1[95];
  v43[0] = nullptr;
  string_helper = of_property_read_string_helper(v13, "arch-compat", v43, 1, 0);
  if ( string_helper < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_get_internal_ops",
      5053,
      "failed to get arch-compat rc=%d",
      string_helper);
    internal_ops = -22;
    goto LABEL_80;
  }
  v15 = strlen(v43[0]);
  if ( strnstr(v43[0], "camss_top", v15) )
  {
    *(_DWORD *)v5 = 1;
    internal_ops = cam_camsstop_get_internal_ops((_QWORD *)(v9 + 8000));
    if ( !internal_ops )
      goto LABEL_22;
LABEL_80:
    v17 = internal_ops;
    _flush_workqueue(*(_QWORD *)(v9 + 8096));
    destroy_workqueue(*(_QWORD *)(v9 + 8096));
    goto LABEL_81;
  }
  v18 = strlen(v43[0]);
  if ( !strnstr(v43[0], "cpas_top", v18) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_get_internal_ops",
      5064,
      "arch-compat %s not supported",
      v43[0]);
    internal_ops = -22;
    goto LABEL_80;
  }
  *(_DWORD *)v5 = 0;
  internal_ops = cam_cpastop_get_internal_ops((_QWORD *)(v9 + 8000));
  if ( internal_ops )
    goto LABEL_80;
LABEL_22:
  internal_ops = cam_cpas_soc_init_resources(v7 + 96, *(_QWORD *)(v9 + 8016), v7);
  if ( internal_ops )
    goto LABEL_80;
  v41 = *(_QWORD *)(v7 + 3392);
  mutex_lock(v7);
  v42 = *(_QWORD *)(v7 + 3392);
  if ( mem_trace_en == 1 )
    v19 = cam_mem_trace_alloc(104, 0xCC0u, 0, "cam_cpas_create_sysfs", 0x1446u);
  else
    v19 = _kvmalloc_node_noprof(104, 0, 3520, 0xFFFFFFFFLL);
  v20 = v19;
  if ( !v19 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_create_sysfs",
      5192,
      "failed to allocate memory for kobj_camera");
    v23 = -12;
    goto LABEL_78;
  }
  kobject_init(v19, &kobj_cam_cpas_hw_type);
  v21 = kernel_kobj;
  *(_QWORD *)(v20 + 96) = v7;
  *(_QWORD *)(v42 + 1328) = v20;
  v22 = kobject_add(v20, v21, "%s", "camera");
  if ( v22 )
  {
    v23 = v22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_create_sysfs",
      5203,
      "failed to add camera entry in sysfs");
LABEL_32:
    kobject_put(v20);
LABEL_78:
    mutex_unlock(v7);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      5306,
      "Failed to create sysfs entries, rc: %d",
      v23);
    goto LABEL_79;
  }
  file_ns = sysfs_create_file_ns(v20, &cam_subparts_info_attribute, 0);
  if ( file_ns )
  {
    v23 = file_ns;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_create_sysfs",
      5210,
      "failed to create subparts_info file, rc: %d",
      file_ns);
    goto LABEL_32;
  }
  mutex_unlock(v7);
  *(_DWORD *)(v9 + 2776) = *(_DWORD *)(v41 + 12);
  *(_DWORD *)(v9 + 8104) = 0;
  _init_waitqueue_head(v9 + 8112, "&cpas_core->soc_access_count_wq", &cam_cpas_hw_probe___key_15);
  v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v9 + 8024);
  if ( v25 )
  {
    if ( *((_DWORD *)v25 - 1) != 1067893220 )
      __break(0x8228u);
    v23 = v25(v7 + 96, v9 + 2812, 10);
    if ( v23 )
    {
LABEL_60:
      cam_cpas_remove_sysfs(v7);
LABEL_79:
      cam_cpas_soc_deinit_resources(v7 + 96);
      internal_ops = v23;
      goto LABEL_80;
    }
  }
  v26 = *(_QWORD *)(v7 + 3680);
  for ( i = 664; i != 2728; i += 48 )
    _mutex_init(v26 + i, "&cpas_core->client_mutex[i]", &cam_cpas_util_client_setup___key);
  v28 = cam_cpas_util_register_bus_client(v7 + 96, *(_QWORD *)(*(_QWORD *)(v7 + 96) + 760LL), v9 + 2856);
  if ( v28 )
  {
    v23 = v28;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      5331,
      "failed in ahb setup, rc=%d",
      v28);
LABEL_59:
    cam_cpas_util_client_cleanup(v7);
    cam_cpas_node_tree_cleanup(v9, *(_QWORD **)(v7 + 3392));
    goto LABEL_60;
  }
  v29 = cam_cpas_util_axi_setup(v9, v7 + 96);
  if ( v29 )
  {
    v23 = v29;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      5337,
      "failed in axi setup, rc=%d",
      v29);
LABEL_58:
    cam_cpas_util_unregister_bus_client(v9 + 2856);
    goto LABEL_59;
  }
  v23 = cam_cpas_util_vote_default_ahb_axi(v7, 1);
  if ( v23 )
  {
LABEL_57:
    cam_cpas_util_axi_cleanup(v9);
    goto LABEL_58;
  }
  v30 = cam_cpas_soc_enable_resources(v7 + 96);
  if ( v30 )
  {
    v23 = v30;
    v31 = "failed in soc_enable_resources, rc=%d";
    v32 = 5350;
LABEL_46:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      v32,
      v31,
      v23);
LABEL_56:
    cam_cpas_util_vote_default_ahb_axi(v7, 0);
    goto LABEL_57;
  }
  v33 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 8000);
  if ( !v33 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      5362,
      "Invalid get_hw_info");
    v23 = 0;
    goto LABEL_55;
  }
  if ( *((_DWORD *)v33 - 1) != -502984210 )
    __break(0x8228u);
  v34 = v33(v7, v9 + 8);
  if ( v34 )
  {
    v23 = v34;
    v35 = "failed in get_hw_info, rc=%d";
    v36 = 5358;
LABEL_52:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_probe",
      v36,
      v35,
      v23);
LABEL_55:
    cam_cpas_soc_disable_resources(v7 + 96, 1u, 1u);
    goto LABEL_56;
  }
  v23 = cam_cpas_hw_init(v5[14], v9 + 8, 308);
  if ( v23 )
    goto LABEL_55;
  subpart_info = cam_get_subpart_info(v41 + 1596, 1u);
  if ( subpart_info )
  {
    v23 = subpart_info;
    v35 = "Failed to get subpart_info, rc = %d";
    v36 = 5375;
    goto LABEL_52;
  }
  *(_BYTE *)(v9 + 7992) = 1;
  v38 = cam_cpas_soc_disable_resources(v7 + 96, 1u, 1u);
  if ( v38 )
  {
    v23 = v38;
    v31 = "failed in soc_disable_resources, rc=%d";
    v32 = 5390;
    goto LABEL_46;
  }
  v23 = cam_cpas_util_vote_default_ahb_axi(v7, 0);
  if ( v23 )
    goto LABEL_57;
  debugfs = cam_cpas_util_create_debugfs(v9);
  if ( debugfs )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_hw_probe",
      5401,
      "failed to create cpas debugfs rc: %d",
      debugfs);
  result = 0;
  *a2 = v5;
LABEL_91:
  _ReadStatusReg(SP_EL0);
  return result;
}
