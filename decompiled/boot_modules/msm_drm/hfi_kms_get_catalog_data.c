__int64 __fastcall hfi_kms_get_catalog_data(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  _QWORD *cmd_buf; // x20
  int v10; // w7
  unsigned int property; // w0
  int v12; // w7
  unsigned int v13; // w20
  int v14; // w7
  void *v16; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0c; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0d; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    v13 = -22;
LABEL_15:
    printk(&unk_261C9E, "hfi_kms_get_catalog_data");
    return v13;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "_send_device_init_cmd", 486, -1, 16777217, 4369, -1059143953, a8, vars0);
  cmd_buf = hfi_adapter_get_cmd_buf(a1 + 8);
  sde_evtlog_log(sde_dbg_base_evtlog, "_send_device_init_cmd", 489, -1, 16777217, 13107, -1059143953, v10, vars0c);
  if ( !cmd_buf )
  {
    printk(&unk_237EB0, "_send_device_init_cmd");
    v13 = -22;
    goto LABEL_15;
  }
  *(_QWORD *)(a1 + 160) = hfi_kms_populate_catalog;
  property = hfi_adapter_add_get_property((__int64)cmd_buf, 16777217, 0, 0, 0, 0, a1 + 160, 6);
  if ( property )
  {
    v13 = property;
    v16 = &unk_211F27;
LABEL_14:
    printk(v16, "_send_device_init_cmd");
    goto LABEL_15;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "_send_device_init_cmd", 505, -1, 16777217, 17476, -1059143953, v12, vars0a);
  v13 = hfi_adapter_set_cmd_buf_blocking((__int64)cmd_buf);
  sde_evtlog_log(sde_dbg_base_evtlog, "_send_device_init_cmd", 507, -1, 16777217, v13, 21845, -1059143953, vars0d);
  if ( v13 )
  {
    v16 = &unk_25A62E;
    goto LABEL_14;
  }
  if ( !*(_DWORD *)(a1 + 176) )
    printk(&unk_248CA7, "_send_device_init_cmd");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "catalog wait success after :%d ms\n", 0);
  sde_evtlog_log(sde_dbg_base_evtlog, "_send_device_init_cmd", 518, -1, 16777217, 8738, -1059143953, v14, vars0b);
  return 0;
}
