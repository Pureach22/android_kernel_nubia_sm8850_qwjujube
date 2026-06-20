__int64 __fastcall zte_reboot_ext_probe(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x0
  __int64 result; // x0
  _QWORD *v5; // x22
  __int64 v6; // x2
  _QWORD *v7; // x20
  unsigned int v8; // w0
  __int64 v9; // x2
  unsigned int group; // w0
  __int64 v11; // x2
  unsigned __int64 v12; // x0
  __int64 v13; // x2
  unsigned int v14; // w19
  unsigned int v15; // w19
  unsigned __int64 v16; // x0
  __int64 v17; // x2
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x0
  __int64 v20; // x2
  unsigned __int64 v21; // x0
  __int64 v22; // x2
  unsigned __int64 v23; // x20
  unsigned __int64 v24; // x0
  __int64 v25; // x2
  unsigned __int64 v26; // x0
  __int64 v27; // x2
  unsigned __int64 v28; // x20
  unsigned __int64 v29; // x0
  __int64 v30; // x2
  unsigned __int64 v31; // x0
  __int64 v32; // x2
  unsigned __int64 v33; // x20

  v1 = a1 + 16;
  _ReadStatusReg(SP_EL0);
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 160, 3520);
  if ( v3 )
  {
    v5 = v3;
    v6 = kernel_kobj;
    *v3 = v1;
    v7 = v3 + 1;
    v8 = kobject_init_and_add(v3 + 1, &bootreason_nvmem_kobj_type, v6, "bootreason");
    if ( v8 )
    {
      v14 = v8;
      printk(&unk_705D, "zte_reboot_ext_probe", v9);
      kobject_put(v7);
      result = v14;
    }
    else
    {
      group = sysfs_create_group(v7, &qcom_boot_nvmem_attr_group);
      if ( group )
      {
        v15 = group;
        printk(&unk_75B2, "zte_reboot_ext_probe", v11);
        kobject_del(v7);
        result = v15;
      }
      else
      {
        v12 = nvmem_cell_get(*v5, "vendor_zlog_ss");
        v5[16] = v12;
        if ( v12 < 0xFFFFFFFFFFFFF001LL )
        {
          v16 = nvmem_cell_read();
          v18 = v16;
          if ( v16 < 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_70EA, 0, v17);
            kfree(v18);
          }
          else
          {
            printk(&unk_7550, (unsigned int)v16, v17);
          }
        }
        else
        {
          printk(&unk_72D2, v12, v13);
        }
        v19 = nvmem_cell_get(*v5, "vendor_zlog_w");
        v5[17] = v19;
        if ( v19 < 0xFFFFFFFFFFFFF001LL )
        {
          v21 = nvmem_cell_read();
          v23 = v21;
          if ( v21 < 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_6F48, 0, v22);
            kfree(v23);
          }
          else
          {
            printk(&unk_7608, (unsigned int)v21, v22);
          }
        }
        else
        {
          printk(&unk_7589, v19, v20);
        }
        v24 = nvmem_cell_get(*v5, "vendor_zlog_p");
        v5[18] = v24;
        if ( v24 < 0xFFFFFFFFFFFFF001LL )
        {
          v26 = nvmem_cell_read();
          v28 = v26;
          if ( v26 < 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_749C, 0, v27);
            kfree(v28);
          }
          else
          {
            printk(&unk_7268, (unsigned int)v26, v27);
          }
        }
        else
        {
          printk(&unk_71F4, v24, v25);
        }
        v29 = nvmem_cell_get(*v5, "vendor_zlog_panic_ext");
        v5[19] = v29;
        if ( v29 < 0xFFFFFFFFFFFFF001LL )
        {
          v31 = nvmem_cell_read();
          v33 = v31;
          if ( v31 < 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_7006, 0, v32);
            kfree(v33);
          }
          else
          {
            printk(&unk_7292, (unsigned int)v31, v32);
          }
        }
        else
        {
          printk(&unk_7082, v29, v30);
        }
        save_panic_buf_data_to_nvmem(v5);
        register_panic_hook(a1);
        v5[13] = zte_reboot_ext_panic;
        *((_DWORD *)v5 + 30) = 0x7FFFFFFF;
        atomic_notifier_chain_register(&panic_notifier_list, v5 + 13);
        result = 0;
        *(_QWORD *)(a1 + 168) = v5;
      }
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
