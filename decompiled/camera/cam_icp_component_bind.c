__int64 __fastcall cam_icp_component_bind(__int64 a1)
{
  __int64 *v1; // x26
  _BYTE *v2; // x27
  __int64 v3; // x22
  __int64 v4; // x19
  int v5; // w0
  unsigned int v6; // w6
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned int v12; // w19
  __int64 v13; // x23
  unsigned int v14; // w0
  unsigned int v15; // w23
  __int64 v16; // x24
  __int64 *v17; // x25
  int v18; // w3
  unsigned int v19; // w0
  unsigned int v20; // w0
  unsigned __int64 v21; // x20
  __int64 v22; // x8
  __int64 v23; // x19
  __int16 v24; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v26; // x24
  _QWORD v27[2]; // [xsp+10h] [xbp-E0h] BYREF
  _QWORD v28[2]; // [xsp+20h] [xbp-D0h] BYREF
  unsigned int v29; // [xsp+30h] [xbp-C0h] BYREF
  int v30; // [xsp+34h] [xbp-BCh] BYREF
  __int64 v31[23]; // [xsp+38h] [xbp-B8h] BYREF

  v3 = a1;
  v4 = a1 - 16;
  v31[21] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v31, 0, 168);
  v29 = 0;
  v30 = -1;
  v28[0] = 0;
  v28[1] = 0;
  v27[0] = 0;
  v27[1] = 0;
  ktime_get_real_ts64(v28);
  if ( !v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_component_bind",
      301,
      "Invalid params: pdev is %s",
      "NULL");
    result = 4294967274LL;
    goto LABEL_19;
  }
  v5 = of_property_read_variable_u32_array(*(_QWORD *)(v3 + 744), "cell-index", &v29, 1, 0);
  if ( v5 < 0 )
  {
    v6 = 0;
    v29 = 0;
  }
  else
  {
    v6 = v29;
    if ( v29 >= 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_component_bind",
        311,
        "Invalid device idx: %u exceeds subdev max: %u",
        v29,
        2);
      result = 4294967274LL;
      goto LABEL_19;
    }
  }
  if ( v5 < 0 )
    v8 = (__int64)"cam-icp";
  else
    v8 = (__int64)&cam_icp_subdev_name_arr[32 * v6];
  mutex_lock(&g_dev_lock);
  if ( v29 >= 2 )
  {
LABEL_43:
    while ( 1 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v26 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_icp_component_bind__alloc_tag;
      v10 = _kvmalloc_node_noprof(343112, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v26;
      if ( !v10 )
        goto LABEL_44;
LABEL_24:
      mutex_lock(&g_dev_lock);
      if ( v29 <= 1 )
      {
        v1[v29] = v10;
        mutex_unlock(&g_dev_lock);
        *(_QWORD *)(v10 + 400) = &cam_icp_subdev_internal_ops;
        *(_DWORD *)(v10 + 464) = 1;
        v11 = cam_subdev_probe(v10, v4, v8, 65539);
        if ( v11 )
        {
          v12 = v11;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_component_bind",
            353,
            "device[%s] probe failed",
            (const char *)v8);
          v8 = v12;
          goto LABEL_13;
        }
        v13 = *(_QWORD *)(v10 + 424);
        *(_DWORD *)(v13 + 24) = v29;
        *(_QWORD *)(v13 + 336) = cam_icp_subdev_close_internal;
        _mutex_init(v10 + 343056, "&icp_dev->icp_lock", &cam_icp_component_bind___key);
        v14 = cam_icp_hw_mgr_init(*(const void **)(v3 + 744), v31, &v30, (__int64)cam_icp_dev_mini_dump_cb, v29);
        if ( v14 )
        {
          v15 = v14;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_component_bind",
            365,
            "device[%s] HW manager init failed: %d",
            v8);
LABEL_38:
          cam_node_deinit(*(void **)(v10 + 472));
          cam_subdev_remove((void **)v10);
          v8 = v15;
          goto LABEL_13;
        }
        v3 = 0;
        v16 = v10 + 480;
        v17 = (__int64 *)(v10 + 30288);
        do
        {
          v18 = v30;
          *v17 = v16;
          v19 = cam_icp_context_init((int)v17, (int)v13 + 112, v3, v18, v8);
          if ( v19 )
          {
            v15 = v19;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_component_bind",
              374,
              "device[%s] context init failed",
              (const char *)v8);
            if ( (int)v3 >= 1 )
              goto LABEL_35;
            goto LABEL_37;
          }
          ++v3;
          v17 += 724;
          v16 += 552;
        }
        while ( v3 != 54 );
        v20 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64))cam_node_init)(
                v13,
                v31,
                v10 + 480,
                54,
                v8);
        if ( v20 )
        {
          v15 = v20;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_component_bind",
            382,
            "device[%s] node init failed",
            (const char *)v8);
          v3 = 54;
LABEL_35:
          v21 = v3 + 1;
          v22 = v10 + 5792 * v3;
          v3 = -5792;
          v23 = v22 + 24496;
          do
          {
            cam_icp_context_deinit(v23);
            --v21;
            v23 -= 5792;
          }
          while ( v21 > 1 );
LABEL_37:
          cam_icp_hw_mgr_deinit(v29);
          goto LABEL_38;
        }
        cam_common_register_evt_inject_cb((__int64)cam_icp_dev_evt_inject_cb, 1u);
        cam_smmu_set_client_page_fault_handler(v30, (__int64)cam_icp_dev_iommu_fault_handler, v13);
        v24 = debug_mdl;
        *(_DWORD *)(v10 + 343104) = 0;
        if ( (v24 & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24 & 0x100,
            4,
            "cam_icp_component_bind",
            395,
            "device[%s] id: %u component bound successfully",
            (const char *)v8,
            v29);
        ktime_get_real_ts64(v27);
        cam_record_bind_latency();
        result = 0;
        goto LABEL_19;
      }
    }
  }
  v1 = g_icp_dev;
  v2 = &unk_2FD000;
  if ( !g_icp_dev[v29] )
  {
    mutex_unlock(&g_dev_lock);
    if ( mem_trace_en == 1 )
      v9 = cam_mem_trace_alloc(343112, 0xCC0u, 0, "cam_icp_component_bind", 0x150u);
    else
      v9 = _kvmalloc_node_noprof(343112, 0, 3520, 0xFFFFFFFFLL);
    v10 = v9;
    if ( v9 )
      goto LABEL_24;
LABEL_44:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_component_bind",
      340,
      "Unable to allocate memory for icp device:%s size:%llu",
      *(const char **)v4,
      343112);
    result = 4294967284LL;
    goto LABEL_19;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_component_bind",
    329,
    "Invalid device index: %u for pdev: %s, ICP device for this idx is already bound",
    v29,
    *(const char **)v4);
  mutex_unlock(&g_dev_lock);
  v8 = 4294967239LL;
LABEL_13:
  v4 = v29;
  if ( v2[2904] == 1 )
  {
    if ( v29 >= 2 )
      goto LABEL_43;
    cam_mem_trace_free((_QWORD *)v1[v29], 0);
  }
  else
  {
    if ( v29 > 1 )
      goto LABEL_43;
    kvfree(v1[v29]);
  }
  result = (unsigned int)v8;
  v1[v4] = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
