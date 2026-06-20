__int64 __fastcall qcom_dload_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int group; // w0
  __int64 v7; // x0
  unsigned int v8; // w19
  unsigned int v9; // w19
  __int64 v10; // x0
  int v11; // w8
  int *v12; // x9
  __int64 v13; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( (msm_minidump_enabled() & 1) != 0 )
  {
    v2 = devm_kmalloc(a1 + 16, 184, 3520);
    if ( v2 )
    {
      v4 = v2;
      v5 = kobject_init_and_add(v2 + 72, &qcom_dload_kobj_type, kernel_kobj, "dload");
      if ( v5 )
      {
        v8 = v5;
        printk(&unk_6E7F, "qcom_dload_probe");
        kobject_put(v4 + 72);
        result = v8;
      }
      else
      {
        group = sysfs_create_group(v4 + 72, &qcom_dload_attr_group);
        if ( group )
        {
          v9 = group;
          printk(&unk_7128, "qcom_dload_probe");
          kobject_del(v4 + 72);
          result = v9;
        }
        else
        {
          if ( (is_kernel_log_driver_enabled() & 1) != 0 )
          {
            v7 = printk(&unk_70CE, "qcom_dload_probe");
          }
          else
          {
            v7 = printk(&unk_6F19, "qcom_dload_probe");
            enable_dump = 0;
          }
          v10 = map_prop_mem(v7);
          v11 = enable_dump;
          *(_QWORD *)(v4 + 176) = v10;
          msm_enable_dump_mode(v11 != 0);
          if ( (unsigned int)qcom_scm_get_download_mode(&v14) )
            v12 = &dump_mode;
          else
            v12 = &v14;
          dump_mode = *v12;
          v13 = printk(&unk_7101, "qcom_dload_probe");
          if ( !enable_dump )
            qcom_scm_disable_sdi(v13);
          *(_QWORD *)v4 = qcom_dload_panic;
          *(_DWORD *)(v4 + 16) = 0x7FFFFFFF;
          atomic_notifier_chain_register(&panic_notifier_list, v4);
          *(_QWORD *)(v4 + 24) = qcom_dload_reboot;
          *(_DWORD *)(v4 + 40) = 255;
          register_reboot_notifier(v4 + 24);
          *(_QWORD *)(v4 + 48) = qcom_dload_restart;
          *(_DWORD *)(v4 + 64) = 201;
          register_restart_handler(v4 + 48);
          result = 0;
          *(_QWORD *)(a1 + 168) = v4;
        }
      }
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294966779LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
