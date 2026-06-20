// Alternative name is 'init_module'
__int64 qcom_common_init()
{
  __int64 v0; // x0
  unsigned int file_ns; // w0
  unsigned int v2; // w0
  unsigned int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w20

  qcom_device_shutdown_in_progress = 0;
  v0 = kobject_create_and_add("qcom_rproc", kernel_kobj);
  sysfs_kobject = v0;
  if ( v0 )
  {
    file_ns = sysfs_create_file_ns(v0, &shutdown_requested_attr, 0);
    if ( file_ns )
    {
      v5 = file_ns;
      printk(&unk_8549);
    }
    else
    {
      v2 = sysfs_create_file_ns(sysfs_kobject, &both_coredumps_attr, 0);
      if ( v2 )
      {
        v5 = v2;
        printk(&unk_842A);
      }
      else
      {
        v3 = tracepoint_probe_register(&_tracepoint_android_vh_rproc_recovery, qcom_check_ssr_status, 0);
        if ( v3 )
        {
          v5 = v3;
          printk(&unk_83CC);
        }
        else
        {
          result = tracepoint_probe_register(&_tracepoint_android_vh_rproc_recovery_set, rproc_recovery_notifier, 0);
          if ( !(_DWORD)result )
            return result;
          v5 = result;
          printk(&unk_860A);
          tracepoint_probe_unregister(&_tracepoint_android_vh_rproc_recovery, qcom_check_ssr_status, 0);
        }
        sysfs_remove_file_ns(sysfs_kobject, &both_coredumps_attr, 0);
      }
      sysfs_remove_file_ns(sysfs_kobject, &shutdown_requested_attr, 0);
    }
    kobject_put(sysfs_kobject);
    return v5;
  }
  else
  {
    printk(&unk_85B0);
    return 4294967274LL;
  }
}
