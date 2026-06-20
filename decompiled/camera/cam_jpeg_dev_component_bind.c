__int64 __fastcall cam_jpeg_dev_component_bind(__int64 a1)
{
  __int64 v2; // x19
  unsigned int v3; // w0
  unsigned int v4; // w20
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v7; // x22
  int v8; // w0
  char *v10; // x24
  __int64 v11; // x23
  char *v12; // x25
  int v13; // w0
  int v14; // w0
  char *v15; // x8
  char *v16; // x21
  unsigned int v17; // w0
  _QWORD v18[2]; // [xsp+8h] [xbp-D8h] BYREF
  _QWORD v19[2]; // [xsp+18h] [xbp-C8h] BYREF
  unsigned int v20; // [xsp+2Ch] [xbp-B4h] BYREF
  _QWORD v21[22]; // [xsp+30h] [xbp-B0h] BYREF

  v2 = a1 - 16;
  v21[21] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v21, 0, 168);
  v20 = -1;
  v19[0] = 0;
  v19[1] = 0;
  v18[0] = 0;
  v18[1] = 0;
  ktime_get_real_ts64(v19);
  qword_3AB8E0 = (__int64)&cam_jpeg_subdev_internal_ops;
  dword_3AB920 = 1;
  v3 = cam_subdev_probe((__int64)&g_jpeg_dev, v2, (__int64)"cam-jpeg", 65541);
  if ( v3 )
  {
    v4 = v3;
    v5 = "JPEG cam_subdev_probe failed %d";
    v6 = 177;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_bind",
      v6,
      v5,
      v4);
    goto LABEL_8;
  }
  v7 = qword_3AB8F8;
  v8 = cam_jpeg_hw_mgr_init(*(const void **)(a1 + 744), v21, &v20, cam_jpeg_dev_mini_dump_cb);
  if ( v8 )
  {
    v4 = v8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_bind",
      186,
      "Can not initialize JPEG HWmanager %d",
      v8);
LABEL_5:
    if ( (unsigned int)cam_subdev_remove((void **)&g_jpeg_dev) )
    {
      v5 = "remove fail %d";
      v6 = 231;
      goto LABEL_7;
    }
  }
  else
  {
    v10 = (char *)&unk_3AB930;
    v11 = 0;
    v12 = (char *)&unk_3AECF0;
    do
    {
      v13 = cam_jpeg_context_init(v12, v10, v7 + 112, (unsigned int)v11, v20);
      if ( v13 )
      {
        v4 = v13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dev_component_bind",
          197,
          "JPEG context init failed %d %d",
          v11,
          v13);
        if ( (int)v11 < 1 )
          goto LABEL_5;
        goto LABEL_15;
      }
      ++v11;
      v12 += 3528;
      v10 += 552;
    }
    while ( v11 != 24 );
    cam_common_register_evt_inject_cb((__int64)cam_jpeg_dev_evt_inject_cb, 2u);
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD *, void *, __int64, const char *))cam_node_init)(
            v7,
            v21,
            &unk_3AB930,
            24,
            "cam-jpeg");
    if ( v14 )
    {
      v4 = v14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dev_component_bind",
        208,
        "JPEG node init failed %d",
        v14);
      v11 = 24;
LABEL_15:
      v15 = (char *)&g_jpeg_dev + 3528 * v11;
      v11 = (unsigned int)v11;
      v16 = v15 + 10200;
      do
      {
        if ( (unsigned int)cam_jpeg_context_deinit(v16) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_dev_component_bind",
            228,
            "deinit fail %d %d",
            v11 - 1,
            v4);
        --v11;
        v16 -= 3528;
      }
      while ( (unsigned __int64)(v11 + 1) > 1 );
      goto LABEL_5;
    }
    v17 = v20;
    *(_QWORD *)(v7 + 336) = cam_jpeg_subdev_close_internal;
    cam_smmu_set_client_page_fault_handler(v17, (__int64)cam_jpeg_dev_iommu_fault_handler, v7);
    _mutex_init(&unk_3C37B0, "&g_jpeg_dev.jpeg_mutex", &cam_jpeg_dev_component_bind___key);
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_dev_component_bind",
        218,
        "Component bound successfully");
    ktime_get_real_ts64(v18);
    cam_record_bind_latency();
    v4 = 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v4;
}
