__int64 __fastcall cam_jpeg_hw_mgr_init(const void *a1, _QWORD *a2, _DWORD *a3, void *a4)
{
  int string_helper; // w0
  int v8; // w21
  unsigned int variable_u32_array; // w0
  const char *v10; // x24
  __int64 v11; // x0
  unsigned int v12; // w22
  unsigned int v13; // w0
  __int64 v14; // x0
  unsigned int v15; // w23
  unsigned int v16; // w0
  __int64 node_by_name; // x0
  __int64 *v18; // x22
  __int64 device_by_node; // x0
  unsigned int *v20; // x22
  __int64 v21; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x10
  __int64 v24; // x6
  const char *v25; // x5
  __int64 v26; // x4
  const char *v27; // x5
  __int64 v28; // x4
  void (__fastcall *v29)(__int64, __int64, void *, __int64); // x9
  __int64 v30; // x0
  __int64 (__fastcall *v31)(__int64, __int64, void *, __int64); // x9
  __int64 v32; // x0
  const char *v33; // x5
  __int64 v34; // x4
  int v36; // w19
  int v37; // w20
  unsigned int handle; // w0
  unsigned int iommu_handle; // w0
  unsigned int v40; // w0
  unsigned int v41; // w0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 i; // x9
  __int64 v46; // x11
  __int64 v47; // x8
  __int64 j; // x9
  __int64 v49; // x12
  __int64 v50; // x11
  __int64 **v51; // x9
  _QWORD *v52; // x12
  __int64 *v53; // x10
  __int64 **v54; // x1
  __int64 v56; // x0
  __int64 v57; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v59; // x23
  __int64 v60; // [xsp+10h] [xbp-20h] BYREF
  __int64 v61; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v62[2]; // [xsp+20h] [xbp-10h] BYREF

  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_hw_mgr_init",
      2303,
      "Invalid args of_node %pK hw_mgr %pK",
      a1,
      a2);
    v12 = -22;
    goto LABEL_57;
  }
  a2[2] = 0;
  a2[3] = 0;
  *a2 = &g_jpeg_hw_mgr;
  a2[1] = cam_jpeg_mgr_get_hw_caps;
  a2[8] = 0;
  a2[9] = 0;
  a2[3] = &cam_jpeg_mgr_acquire_hw;
  a2[4] = 0;
  a2[4] = &cam_jpeg_mgr_release_hw;
  a2[5] = 0;
  a2[9] = cam_jpeg_mgr_config_hw;
  a2[10] = 0;
  a2[14] = 0;
  a2[15] = 0;
  a2[15] = &cam_jpeg_mgr_hw_flush;
  a2[16] = 0;
  a2[6] = 0;
  a2[7] = 0;
  a2[6] = cam_jpeg_mgr_hw_stop;
  a2[7] = cam_jpeg_mgr_prepare_hw_update;
  a2[11] = 0;
  a2[12] = 0;
  a2[12] = &cam_jpeg_mgr_cmd;
  a2[13] = 0;
  a2[17] = 0;
  a2[18] = 0;
  a2[17] = &cam_jpeg_mgr_hw_dump;
  a2[19] = 0;
  a2[20] = 0;
  a2[19] = cam_jpeg_mgr_inject_evt;
  _mutex_init(&g_jpeg_hw_mgr, "&g_jpeg_hw_mgr.hw_mgr_mutex", &cam_jpeg_hw_mgr_init___key);
  dword_3A8CC8 = 0;
  _mutex_init(&unk_3A8CD8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A8DA8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A8E78, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A8F48, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9018, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A90E8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A91B8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9288, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9358, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9428, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A94F8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A95C8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9698, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9768, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9838, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9908, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A99D8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9AA8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9B78, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9C48, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9D18, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9DE8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9EB8, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  _mutex_init(&unk_3A9F88, "&g_jpeg_hw_mgr.ctx_data[i].ctx_mutex", &cam_jpeg_hw_mgr_init___key_2);
  v61 = 0;
  v62[0] = 0;
  string_helper = of_property_read_string_helper(a1, "compat-hw-name", 0, 0, 0);
  if ( !string_helper )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_init_devices",
      1733,
      "no compat hw found in dev tree, count = %d",
      0);
    v12 = -22;
    goto LABEL_55;
  }
  v8 = string_helper;
  variable_u32_array = of_property_read_variable_u32_array(a1, "num-jpeg-enc", (char *)v62 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v12 = variable_u32_array;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_init_devices",
      1740,
      "read num enc devices failed %d",
      variable_u32_array);
    goto LABEL_55;
  }
  v10 = (const char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v11 = cam_mem_trace_alloc(8LL * HIDWORD(v62[0]), 0xCC0u, 0, "cam_jpeg_init_devices", 0x6D0u);
  else
    v11 = _kvmalloc_node_noprof(8LL * HIDWORD(v62[0]), 0, 3520, 0xFFFFFFFFLL);
LABEL_11:
  qword_3AA0E0 = v11;
  if ( !v11 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_init_devices",
      1747,
      "getting number of dma dev nodes failed");
    v12 = -12;
    goto LABEL_55;
  }
  v13 = of_property_read_variable_u32_array(a1, "num-jpeg-dma", v62, 1, 0);
  if ( (v13 & 0x80000000) != 0 )
  {
    v12 = v13;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_init_devices",
      1753,
      "get num dma dev nodes failed %d",
      v13);
    goto LABEL_47;
  }
  if ( v10[2904] == 1 )
    v14 = cam_mem_trace_alloc(8LL * LODWORD(v62[0]), 0xCC0u, 0, "cam_jpeg_init_devices", 0x6DEu);
  else
    v14 = _kvmalloc_node_noprof(8LL * LODWORD(v62[0]), 0, 3520, 0xFFFFFFFFLL);
  qword_3AA0E8 = v14;
  if ( !v14 )
  {
    v12 = -12;
    goto LABEL_47;
  }
  if ( v8 < 1 )
  {
LABEL_50:
    qword_3AA110 = *(_QWORD *)(*(_QWORD *)qword_3AA0E0 + 112LL) + 384LL;
    qword_3AA118 = *(_QWORD *)(*(_QWORD *)v14 + 112LL) + 384LL;
    v29 = *(void (__fastcall **)(__int64, __int64, void *, __int64))(*(_QWORD *)qword_3AA0E0 + 88LL);
    v30 = *(_QWORD *)(*(_QWORD *)qword_3AA0E0 + 112LL);
    if ( *((_DWORD *)v29 - 1) != -1055839300 )
      __break(0x8229u);
    v29(v30, 3, &unk_3AB738, 4);
    v31 = *(__int64 (__fastcall **)(__int64, __int64, void *, __int64))(*(_QWORD *)qword_3AA0E8 + 88LL);
    v32 = *(_QWORD *)(*(_QWORD *)qword_3AA0E8 + 112LL);
    if ( *((_DWORD *)v31 - 1) != -1055839300 )
      __break(0x8229u);
    v12 = v31(v32, 3, &unk_3AB73C, 4);
    if ( v12 )
      goto LABEL_55;
    v37 = v62[0];
    v36 = HIDWORD(v62[0]);
    handle = cam_smmu_get_handle("jpeg", &dword_3AA098);
    if ( handle )
    {
      v12 = handle;
      v33 = "jpeg get iommu handle failed %d";
      v34 = 2334;
      goto LABEL_56;
    }
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_hw_mgr_init",
        2338,
        "mmu handle :%d",
        dword_3AA098);
    iommu_handle = cam_cdm_get_iommu_handle("jpegenc", (__int64)&v60);
    if ( iommu_handle )
    {
      v12 = iommu_handle;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_hw_mgr_init",
        2342,
        "acquire cdm iommu handle Fail  %d",
        iommu_handle);
      qword_3AA0C0 = -1;
    }
    else
    {
      qword_3AA0C0 = v60;
      qword_3AA058 = v60;
      dword_3AA050 = dword_3AA098;
      dword_3AA054 = dword_3AA09C;
      dword_3AA060 = v36;
      dword_3AA064 = v37;
      qword_3AA070 = 0x200000004LL;
      qword_3AA078 = 0;
      qword_3AA088 = 0x200000004LL;
      qword_3AA090 = 0;
      off_3AB740 = a4;
      v40 = cam_req_mgr_workq_create(
              "jpeg_command_queue",
              0x1Eu,
              &qword_3AA0A0,
              0,
              0,
              (__int64)cam_req_mgr_process_workq_jpeg_command_queue);
      if ( v40 )
      {
        v12 = v40;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_setup_workqs",
          1649,
          "unable to create a worker %d",
          v40);
      }
      else
      {
        v41 = cam_req_mgr_workq_create(
                "jpeg_message_queue",
                0x1Eu,
                &qword_3AA0A8,
                1,
                0,
                (__int64)cam_req_mgr_process_workq_jpeg_message_queue);
        if ( v41 )
        {
          v12 = v41;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_setup_workqs",
            1660,
            "unable to create a worker %d",
            v41);
        }
        else
        {
          if ( v10[2904] == 1 )
            v42 = cam_mem_trace_alloc(720, 0xCC0u, 0, "cam_jpeg_setup_workqs", 0x682u);
          else
            v42 = _kvmalloc_node_noprof(720, 0, 3520, 0xFFFFFFFFLL);
          qword_3AA0B0 = v42;
          if ( v42 )
          {
            if ( v10[2904] == 1 )
              v43 = cam_mem_trace_alloc(720, 0xCC0u, 0, "cam_jpeg_setup_workqs", 0x68Au);
            else
              v43 = _kvmalloc_node_noprof(720, 0, 3520, 0xFFFFFFFFLL);
            qword_3AA0B8 = v43;
            if ( v43 )
            {
              v44 = 0;
              for ( i = 8; i != 2168; i += 72 )
              {
                v46 = qword_3AA0B8 + v44;
                v44 += 24;
                *(_QWORD *)(*(_QWORD *)(qword_3AA0A8 + 296) + i) = v46;
              }
              v47 = 0;
              for ( j = 8; j != 2168; j += 72 )
              {
                v49 = qword_3AA0B0 + v47;
                v47 += 24;
                *(_QWORD *)(*(_QWORD *)(qword_3AA0A0 + 296) + j) = v49;
              }
              v50 = 50;
              qword_3AA138 = (__int64)&qword_3AA138;
              v51 = (__int64 **)&unk_3AA158;
              qword_3AA140 = (__int64)&qword_3AA138;
              v52 = &unk_3AA000;
              qword_3AA148 = (__int64)&qword_3AA148;
              qword_3AA150 = (__int64)&qword_3AA148;
              v53 = &qword_3AA148;
              do
              {
                *v51 = (__int64 *)v51;
                v51[1] = (__int64 *)v51;
                v54 = (__int64 **)v52[42];
                if ( v51 != v54 && *v54 == v53 )
                {
                  v53[1] = (__int64)v51;
                  *v51 = v53;
                  v51[1] = (__int64 *)v54;
                  *v54 = (__int64 *)v51;
                }
                else
                {
                  _list_add_valid_or_report(v51);
                }
                --v50;
                v51 += 14;
              }
              while ( v50 );
              if ( a3 )
                *a3 = dword_3AA098;
              v56 = cam_common_register_mini_dump_cb((__int64)cam_jpeg_hw_mgr_mini_dump_cb, "CAM_JPEG", 0);
              cam_jpeg_mgr_create_debugfs_entry(v56);
              v12 = 0;
              goto LABEL_57;
            }
            if ( (v10[2904] & 1) != 0 )
              cam_mem_trace_free((_QWORD *)qword_3AA0B0, 0);
            else
              kvfree(qword_3AA0B0);
          }
          cam_req_mgr_workq_destroy(&qword_3AA0A8);
          v12 = -12;
        }
        cam_req_mgr_workq_destroy(&qword_3AA0A0);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_hw_mgr_init",
        2373,
        "setup work qs failed  %d",
        v12);
    }
    cam_smmu_destroy_handle(dword_3AA098);
    dword_3AA098 = 0;
    goto LABEL_57;
  }
  v15 = 0;
  v10 = "compat-hw-name";
  while ( 1 )
  {
    v16 = of_property_read_string_helper(a1, "compat-hw-name", &v61, 1, v15);
    if ( (v16 & 0x80000000) != 0 )
    {
      v12 = v16;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_init_devices",
        1768,
        "getting dev object name failed");
      goto LABEL_44;
    }
    node_by_name = of_find_node_by_name(0, v61);
    if ( !node_by_name )
    {
      v24 = v61;
      v25 = "error! Cannot find node in dtsi %s";
      v26 = 1775;
LABEL_39:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_init_devices",
        v26,
        v25,
        v24);
      goto LABEL_43;
    }
    v18 = (__int64 *)node_by_name;
    device_by_node = of_find_device_by_node();
    if ( !device_by_node )
    {
      v24 = *v18;
      v25 = "failed to find device on bus %s";
      v26 = 1783;
      goto LABEL_39;
    }
    v20 = *(unsigned int **)(device_by_node + 168);
    if ( !v20 )
      break;
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_init_devices",
        1800,
        "child_intf %pK type %d id %d",
        v20,
        *v20,
        v20[1]);
    v21 = *v20;
    if ( (_DWORD)v21 == 1 )
    {
      v22 = v20[1];
      v23 = LODWORD(v62[0]);
    }
    else
    {
      if ( (_DWORD)v21 )
      {
        __break(0x5512u);
        v57 = HIDWORD(v62[0]);
        StatusReg = _ReadStatusReg(SP_EL0);
        v59 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_jpeg_init_devices__alloc_tag;
        v11 = _kvmalloc_node_noprof(8 * v57, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v59;
        goto LABEL_11;
      }
      v22 = v20[1];
      v23 = HIDWORD(v62[0]);
    }
    if ( v22 >= v23 )
    {
      v27 = "index out of range";
      v28 = 1806;
      goto LABEL_42;
    }
    ++v15;
    *(_QWORD *)(*((_QWORD *)&g_jpeg_hw_mgr + v21 + 649) + 8 * v22) = v20;
    if ( v8 == v15 )
    {
      v10 = (const char *)&unk_2FD000;
      v14 = qword_3AA0E8;
      goto LABEL_50;
    }
  }
  v27 = "no child device";
  v28 = 1792;
LABEL_42:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    512,
    1,
    "cam_jpeg_init_devices",
    v28,
    v27);
LABEL_43:
  v12 = -19;
LABEL_44:
  v10 = (const char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3AA0E8, 0);
  else
    kvfree(qword_3AA0E8);
LABEL_47:
  if ( v10[2904] == 1 )
    cam_mem_trace_free((_QWORD *)qword_3AA0E0, 0);
  else
    kvfree(qword_3AA0E0);
LABEL_55:
  v33 = "jpeg init devices %d";
  v34 = 2328;
LABEL_56:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    512,
    1,
    "cam_jpeg_hw_mgr_init",
    v34,
    v33,
    v12);
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return v12;
}
