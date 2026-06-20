__int64 __fastcall cam_cci_component_bind(__int64 a1)
{
  _QWORD *v2; // x8
  char *v3; // x0
  __int64 v4; // x8
  char *v5; // x20
  unsigned int v6; // w0
  unsigned int v7; // w22
  __int64 v8; // x6
  const char *v9; // x5
  __int64 v10; // x4
  int v12; // w8
  unsigned int v13; // w0
  __int64 v14; // x2
  __int64 v15; // x6
  _QWORD v16[2]; // [xsp+8h] [xbp-D8h] BYREF
  _QWORD v17[2]; // [xsp+18h] [xbp-C8h] BYREF
  __int64 v18; // [xsp+28h] [xbp-B8h] BYREF
  _QWORD v19[16]; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v20; // [xsp+B0h] [xbp-30h]
  __int64 v21; // [xsp+B8h] [xbp-28h]
  char *v22; // [xsp+C0h] [xbp-20h]
  __int64 v23; // [xsp+C8h] [xbp-18h]
  __int64 v24; // [xsp+D0h] [xbp-10h]
  __int64 v25; // [xsp+D8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = nullptr;
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  v17[0] = 0;
  v17[1] = 0;
  v16[0] = 0;
  v16[1] = 0;
  ktime_get_real_ts64(v17);
  v3 = (char *)devm_kmalloc(v2, a1, 5904, 3520);
  if ( !v3 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_component_bind",
      707);
    v7 = -12;
    goto LABEL_11;
  }
  v4 = *(_QWORD *)(a1 - 16);
  v5 = v3;
  *((_QWORD *)v3 + 664) = a1 - 16;
  *((_QWORD *)v3 + 48) = a1 - 16;
  *((_QWORD *)v3 + 49) = a1;
  *((_QWORD *)v3 + 51) = v4;
  v6 = cam_cci_parse_dt_info(a1 - 16, v3);
  if ( (v6 & 0x80000000) != 0 )
  {
    v7 = v6;
    v9 = "Resource get Failed rc:%d";
    v10 = 720;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_component_bind",
      v10,
      v9,
      v7);
    goto LABEL_10;
  }
  *((_QWORD *)v5 + 714) = &cci_subdev_intern_ops;
  *((_QWORD *)v5 + 713) = &cci_subdev_ops;
  strcpy(v5 + 5793, "cam-cci-driver");
  *((_DWORD *)v5 + 1432) = 8;
  *((_QWORD *)v5 + 715) = v5 + 5793;
  *((_DWORD *)v5 + 1436) = 65546;
  *((_QWORD *)v5 + 717) = v5;
  v7 = cam_register_subdev((__int64)(v5 + 5312));
  if ( (v7 & 0x80000000) != 0 )
  {
    v9 = "Fail with cam_register_subdev rc: %d";
    v10 = 740;
    goto LABEL_9;
  }
  v8 = *((unsigned int *)v5 + 101);
  *((_QWORD *)v5 + 695) = v5;
  *(_QWORD *)(a1 + 152) = v5 + 5320;
  if ( (unsigned int)v8 >= 3 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_component_bind",
      748);
LABEL_10:
    devm_kfree(a1);
    goto LABEL_11;
  }
  g_cci_subdev[v8] = v5 + 5320;
  _mutex_init(v5 + 5840, "&(new_cci_dev->init_mutex)", &cam_cci_component_bind___key);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_component_bind",
      754,
      "Device Type :%d",
      *((_DWORD *)v5 + 101));
  v12 = *((_DWORD *)v5 + 101);
  v22 = v5;
  v23 = 0;
  v21 = a1;
  LODWORD(v20) = v12;
  LODWORD(v19[0]) = 6906723;
  v13 = cam_cpas_register_client((__int64)v19);
  if ( v13 )
  {
    v7 = v13;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_component_bind",
      763);
    cam_unregister_subdev((__int64)(v5 + 5312));
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_component_bind",
      768,
      "CPAS registration successful handle=%d",
      v24);
  v18 = 0;
  v14 = debugfs_root_0;
  *((_DWORD *)v5 + 1454) = v24;
  if ( !v14 )
  {
    if ( (unsigned int)cam_debugfs_create_subdir("cci", (unsigned __int64 *)&v18) )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_create_debugfs_entry",
        675);
      goto LABEL_26;
    }
    v14 = v18;
    debugfs_root_0 = v18;
  }
  v15 = *((unsigned int *)v5 + 101);
  if ( (unsigned int)v15 < 3 )
  {
    debugfs_create_file(cam_cci_create_debugfs_entry_filename[v15], 420, v14, v5, &cam_cci_debug);
    goto LABEL_27;
  }
  ((void (*)(__int64, const char *, ...))cam_print_log)(
    3,
    print_fmt_cam_context_state,
    (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
    "cam_cci_create_debugfs_entry",
    683);
LABEL_26:
  ((void (*)(__int64, const char *, ...))cam_print_log)(
    3,
    print_fmt_cam_context_state,
    (_BYTE *)&_ksymtab_cam_cci_dump_registers + 2,
    "cam_cci_component_bind",
    773);
LABEL_27:
  head = 0;
  tail = 0;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_component_bind",
      778,
      "Component bound successfully");
  ktime_get_real_ts64(v16);
  cam_record_bind_latency();
  v7 = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v7;
}
