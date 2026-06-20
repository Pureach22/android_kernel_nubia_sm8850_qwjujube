__int64 __fastcall icnss_sysfs_create(__int64 a1)
{
  int v2; // w0
  int link; // w0
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w20
  int v7; // w21
  int v8; // w21

  v2 = devm_device_add_group(*(_QWORD *)(a1 + 8) + 16LL, &icnss_attr_group);
  if ( v2 )
  {
    v6 = v2;
    printk("%sicnss2: Failed to create icnss device group, err = %d\n", byte_130B32, v2);
    return ipc_log_string(
             icnss_ipc_log_context,
             "%sicnss2: Failed to create icnss device group, err = %d\n",
             (const char *)&unk_12DBF3,
             v6);
  }
  link = sysfs_create_link(kernel_kobj, *(_QWORD *)(a1 + 8) + 16LL, "icnss");
  if ( link )
  {
    v7 = link;
    printk("%sicnss2: Failed to create icnss link, err = %d\n", byte_130B32, link);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Failed to create icnss link, err = %d\n",
      (const char *)&unk_12DBF3,
      v7);
  }
  *(_DWORD *)(a1 + 3272) = 0;
  v4 = kobject_create_and_add("shutdown_wlan", kernel_kobj);
  if ( v4 )
  {
    *(_QWORD *)(a1 + 3256) = v4;
    result = sysfs_create_file_ns();
    if ( !(_DWORD)result )
      return result;
    v8 = result;
    printk("%sicnss2: Unable to create icnss sysfs file err:%d", byte_130B32, result);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Unable to create icnss sysfs file err:%d",
      (const char *)&unk_12DBF3,
      v8);
  }
  else
  {
    printk("%sicnss2: Unable to create shutdown_wlan kernel object", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Unable to create shutdown_wlan kernel object",
      (const char *)&unk_12DBF3);
  }
  result = devres_release(
             *(_QWORD *)(a1 + 8) + 16LL,
             devm_icnss_group_remove,
             devm_icnss_group_match,
             &icnss_attr_group);
  if ( (_DWORD)result )
    __break(0x800u);
  return result;
}
