__int64 cam_req_mgr_core_device_init()
{
  _QWORD *v0; // x0
  _QWORD *v1; // x6

  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_core_device_init",
      6271,
      "Enter g_crm_core_dev %pK",
      (const void *)g_crm_core_dev);
    if ( g_crm_core_dev )
      goto LABEL_4;
  }
  else if ( g_crm_core_dev )
  {
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      2,
      "cam_req_mgr_core_device_init",
      6274,
      "core device is already initialized");
    return 0;
  }
  if ( mem_trace_en == 1 )
    v0 = (_QWORD *)cam_mem_trace_alloc(72, 3264, 0, "cam_req_mgr_core_device_init", 6278);
  else
    v0 = (_QWORD *)_kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
  v1 = v0;
  g_crm_core_dev = (__int64)v0;
  if ( v0 )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_core_device_init",
        6282,
        "g_crm_core_dev %pK",
        v0);
      v1 = (_QWORD *)g_crm_core_dev;
    }
    *v1 = v1;
    v1[1] = v1;
    _mutex_init(v1 + 2, "&g_crm_core_dev->crm_lock", &cam_req_mgr_core_device_init___key);
    cam_req_mgr_debug_register(g_crm_core_dev);
    _mutex_init(&unk_2C4818, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    dword_2C4848 = 0;
    qword_2C47D8 = 0;
    dword_2C4880 = 0;
    cam_req_mgr_core_link_reset((__int64)&g_links);
    _mutex_init(&unk_2CCA90, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2CCAC0 = 0;
    unk_2CCA50 = 0;
    unk_2CCAF8 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2C4900);
    _mutex_init(&unk_2D4D08, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2D4D38 = 0;
    unk_2D4CC8 = 0;
    dword_2D4D70 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2CCB78);
    _mutex_init(&unk_2DCF80, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2DCFB0 = 0;
    unk_2DCF40 = 0;
    dword_2DCFE8 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2D4DF0);
    _mutex_init(&unk_2E51F8, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2E5228 = 0;
    unk_2E51B8 = 0;
    dword_2E5260 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2DD068);
    _mutex_init(&unk_2ED470, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2ED4A0 = 0;
    unk_2ED430 = 0;
    dword_2ED4D8 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2E52E0);
    _mutex_init(&unk_2F56E8, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2F5718 = 0;
    unk_2F56A8 = 0;
    dword_2F5750 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2ED558);
    _mutex_init(&unk_2FD960, "&g_links[i].lock", &cam_req_mgr_core_device_init___key_113);
    unk_2FD990 = 0;
    unk_2FD920 = 0;
    dword_2FD9C8 = 0;
    cam_req_mgr_core_link_reset((__int64)&unk_2F57D0);
    cam_common_register_mini_dump_cb(cam_req_mgr_core_mini_dump_cb, "CAM_CRM", 0);
    return 0;
  }
  return 4294967284LL;
}
