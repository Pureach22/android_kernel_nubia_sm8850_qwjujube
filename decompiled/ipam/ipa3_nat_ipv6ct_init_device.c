__int64 __fastcall ipa3_nat_ipv6ct_init_device(__int64 a1, const char *a2, int a3, int a4, __int64 a5)
{
  __int64 v7; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  bool v13; // w8
  size_t v14; // x0
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  unsigned int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v22; // w21
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // w20
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v40; // x0

  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d In: Init of %s\n", "ipa3_nat_ipv6ct_init_device", 350, a2);
      v7 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v7 + 34160);
    if ( v12 )
      ipc_log_string(v12, "ipa %s:%d In: Init of %s\n", "ipa3_nat_ipv6ct_init_device", 350, a2);
  }
  _mutex_init(a1 + 16, "&dev->lock", &ipa3_nat_ipv6ct_init_device___key);
  v13 = ipa3_ctx + 30080 == a1;
  *(_BYTE *)(a1 + 220) = ipa3_ctx + 29528 == a1;
  *(_BYTE *)(a1 + 221) = v13;
  v14 = strnlen(a2, 0xFu);
  if ( v14 == 15 )
  {
    printk(&unk_3A9EFB, "ipa3_nat_ipv6ct_init_device");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d device name is too long\n", "ipa3_nat_ipv6ct_init_device", 358);
        v19 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v19 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d device name is too long\n", "ipa3_nat_ipv6ct_init_device", 358);
LABEL_35:
        v22 = -19;
        goto LABEL_56;
      }
LABEL_63:
      v22 = -19;
      if ( v19 )
        goto LABEL_57;
      return v22;
    }
    return (unsigned int)-19;
  }
  if ( v14 == -1 || (v14 = strnlen(a2, 0xFu), v14 == -1) )
  {
    _fortify_panic(2, -1, v14 + 1);
  }
  else
  {
    if ( v14 == 15 )
      v15 = 15;
    else
      v15 = v14 + 1;
    if ( v15 < 0x10 )
    {
      sized_strscpy(a1, a2);
      v16 = class_create(a2);
      *(_QWORD *)(a1 + 64) = v16;
      if ( v16 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( (unsigned int)alloc_chrdev_region(a1 + 216, 0, 1, a2) )
        {
          printk(&unk_3B8486, "ipa3_nat_ipv6ct_init_device");
          v27 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v28 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v28 )
            {
              ipc_log_string(v28, "ipa %s:%d alloc_chrdev_region err. for %s\n", "ipa3_nat_ipv6ct_init_device", 376, a2);
              v27 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v27 + 34160);
            if ( v29 )
              ipc_log_string(v29, "ipa %s:%d alloc_chrdev_region err. for %s\n", "ipa3_nat_ipv6ct_init_device", 376, a2);
          }
          v22 = -19;
        }
        else
        {
          v17 = device_create(*(_QWORD *)(a1 + 64), 0, *(unsigned int *)(a1 + 216), 0, a2);
          *(_QWORD *)(a1 + 72) = v17;
          if ( v17 >= 0xFFFFFFFFFFFFF001LL )
          {
            printk(&unk_3C4361, "ipa3_nat_ipv6ct_init_device");
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v31 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v31 )
              {
                ipc_log_string(
                  v31,
                  "ipa %s:%d device_create err:%ld\n",
                  "ipa3_nat_ipv6ct_init_device",
                  384,
                  *(_QWORD *)(a1 + 72));
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
                ipc_log_string(
                  v32,
                  "ipa %s:%d device_create err:%ld\n",
                  "ipa3_nat_ipv6ct_init_device",
                  384,
                  *(_QWORD *)(a1 + 72));
            }
            v22 = -19;
          }
          else
          {
            cdev_init(a1 + 80, &ipa3_nat_ipv6ct_fops);
            *(_QWORD *)(a1 + 176) = &_this_module;
            mutex_lock(a1 + 16);
            v18 = cdev_add(a1 + 80, *(unsigned int *)(a1 + 216), 1);
            if ( !v18 )
            {
              *(_QWORD *)(a1 + 296) = a5;
              *(_DWORD *)(a1 + 228) = a3;
              *(_DWORD *)(a1 + 232) = a4;
              *(_BYTE *)(a1 + 222) = 1;
              mutex_unlock(a1 + 16);
              v19 = ipa3_ctx;
              if ( !ipa3_ctx )
                return 0;
              v20 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v20 )
              {
                ipc_log_string(
                  v20,
                  "ipa %s:%d ipa dev %s added successfully. major:%d minor:%d\n",
                  "ipa3_nat_ipv6ct_init_device",
                  410,
                  a2,
                  *(_DWORD *)(a1 + 216) >> 20,
                  *(_DWORD *)(a1 + 216) & 0xFFFFF);
                v19 = ipa3_ctx;
              }
              v21 = *(_QWORD *)(v19 + 34160);
              if ( !v21 )
              {
                v22 = 0;
                if ( v19 )
                {
LABEL_57:
                  v37 = *(_QWORD *)(v19 + 34152);
                  if ( v37 )
                  {
                    ipc_log_string(v37, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_init_device", 427);
                    v19 = ipa3_ctx;
                  }
                  v38 = *(_QWORD *)(v19 + 34160);
                  if ( v38 )
                    ipc_log_string(v38, "ipa %s:%d Out\n", "ipa3_nat_ipv6ct_init_device", 427);
                }
                return v22;
              }
              ipc_log_string(
                v21,
                "ipa %s:%d ipa dev %s added successfully. major:%d minor:%d\n",
                "ipa3_nat_ipv6ct_init_device",
                410,
                a2,
                *(_DWORD *)(a1 + 216) >> 20,
                *(_DWORD *)(a1 + 216) & 0xFFFFF);
              v22 = 0;
LABEL_56:
              v19 = ipa3_ctx;
              if ( ipa3_ctx )
                goto LABEL_57;
              return v22;
            }
            v33 = -v18;
            v22 = v18;
            printk(&unk_3D2EEE, "ipa3_nat_ipv6ct_init_device");
            v34 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v35 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v35 )
              {
                ipc_log_string(v35, "ipa %s:%d cdev_add err=%d\n", "ipa3_nat_ipv6ct_init_device", 398, v33);
                v34 = ipa3_ctx;
              }
              v36 = *(_QWORD *)(v34 + 34160);
              if ( v36 )
                ipc_log_string(v36, "ipa %s:%d cdev_add err=%d\n", "ipa3_nat_ipv6ct_init_device", 398, v33);
            }
            mutex_unlock(a1 + 16);
            device_destroy(*(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 216));
          }
          unregister_chrdev_region(*(unsigned int *)(a1 + 216), 1);
        }
        class_destroy(*(_QWORD *)(a1 + 64));
        goto LABEL_56;
      }
      printk(&unk_3DB98D, "ipa3_nat_ipv6ct_init_device");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(v25, "ipa %s:%d unable to create the class for %s\n", "ipa3_nat_ipv6ct_init_device", 368, a2);
          v19 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v19 + 34160);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d unable to create the class for %s\n", "ipa3_nat_ipv6ct_init_device", 368, a2);
          goto LABEL_35;
        }
        goto LABEL_63;
      }
      return (unsigned int)-19;
    }
  }
  v40 = _fortify_panic(7, 15, v15);
  return ipa3_nat_ipv6ct_destroy_device(v40);
}
