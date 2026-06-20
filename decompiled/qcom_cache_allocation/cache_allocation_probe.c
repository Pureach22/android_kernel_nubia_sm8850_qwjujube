__int64 __fastcall cache_allocation_probe(__int64 a1)
{
  __int64 match_data; // x0
  const void *v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x0
  __int64 v15; // x0
  _DWORD *v16; // x8
  unsigned int file; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  unsigned int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  unsigned int v23; // w0
  const char *v25; // x1
  unsigned int v26; // w20

  match_data = of_device_get_match_data(a1 + 16);
  if ( !match_data )
    return 4294967277LL;
  v3 = (const void *)match_data;
  v4 = devm_kmalloc(a1 + 16, 280, 3520);
  if ( !v4 )
    return 4294967284LL;
  v5 = v4;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,cluster-num", v4 + 56, 1, 0) & 0x80000000) != 0 )
    return 4294967274LL;
  v6 = *(int *)(v5 + 56);
  if ( !is_mul_ok(v6, 0x28u) )
  {
    *(_QWORD *)(v5 + 16) = 0;
    return 4294967284LL;
  }
  v7 = devm_kmalloc(a1 + 16, 40 * v6, 3520);
  *(_QWORD *)(v5 + 16) = v7;
  if ( !v7 )
    return 4294967284LL;
  v8 = *(unsigned int *)(v5 + 56);
  if ( (v8 & 0x80000000) != 0 )
  {
    *(_QWORD *)(v5 + 24) = 0;
    return 4294967284LL;
  }
  v9 = devm_kmalloc(a1 + 16, 4 * v8, 3520);
  *(_QWORD *)(v5 + 24) = v9;
  if ( !v9 )
    return 4294967284LL;
  v10 = *(unsigned int *)(v5 + 56);
  if ( (v10 & 0x80000000) != 0 )
  {
    *(_QWORD *)(v5 + 32) = 0;
    return 4294967284LL;
  }
  v11 = devm_kmalloc(a1 + 16, 4 * v10, 3520);
  *(_QWORD *)(v5 + 32) = v11;
  if ( !v11 )
    return 4294967284LL;
  v12 = devm_kmalloc(a1 + 16, 8, 3520);
  *(_QWORD *)(v5 + 64) = v12;
  if ( !v12 )
    return 4294967284LL;
  v13 = devm_kmalloc(a1 + 16, 8, 3520);
  *(_QWORD *)(v5 + 72) = v13;
  if ( !v13 )
    return 4294967284LL;
  if ( (unsigned int)qcom_mpam_get_version(&mpam_version) || !HIWORD(mpam_version) )
  {
    v25 = "Platform MPAM is not available\n";
LABEL_31:
    dev_err(a1 + 16, v25);
    return 4294967277LL;
  }
  platform_get_resource_byname(a1, 512, "mon-base");
  v14 = devm_ioremap(a1 + 16);
  *(_QWORD *)(v5 + 240) = v14;
  if ( !v14 || v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    v25 = "Error ioremap mpam_mon_base\n";
    goto LABEL_31;
  }
  v15 = devm_kmalloc(a1 + 16, 96, 3520);
  *(_QWORD *)(v5 + 248) = v15;
  if ( !v15 )
    return 4294967284LL;
  memcpy(*(void **)(v5 + 16), v3, 40LL * *(int *)(v5 + 56));
  *(_WORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 80) = 10;
  *(_QWORD *)(v5 + 256) = 0x1000000000LL;
  v16 = *(_DWORD **)(v5 + 64);
  *(_DWORD *)(v5 + 272) = 1;
  *(_DWORD *)(v5 + 48) = 0;
  *(_BYTE *)(v5 + 268) = 0;
  *v16 = 0;
  *(_DWORD *)(*(_QWORD *)(v5 + 64) + 4LL) = 0;
  file = device_create_file(a1 + 16, &dev_attr_enable_monitor);
  if ( file )
  {
    v26 = file;
    dev_err(a1 + 16, "failed: create cache alloc enable monitor entry\n");
  }
  else
  {
    v18 = device_create_file(a1 + 16, &dev_attr_sampling_time_ms);
    if ( v18 )
    {
      v26 = v18;
      dev_err(a1 + 16, "failed: create cache alloc sampling time entry\n");
    }
    else
    {
      v19 = device_create_file(a1 + 16, &dev_attr_freq_mon_thresh);
      if ( v19 )
      {
        v26 = v19;
        dev_err(a1 + 16, "failed: create cache alloc freq_mon_thresh entry\n");
      }
      else
      {
        v20 = device_create_file(a1 + 16, &dev_attr_win_count_config);
        if ( v20 )
        {
          v26 = v20;
          dev_err(a1 + 16, "failed: create slc allocation win_count_config entry\n");
        }
        else
        {
          v21 = device_create_file(a1 + 16, &dev_attr_bw_mon_ratio_thresh);
          if ( v21 )
          {
            v26 = v21;
            dev_err(a1 + 16, "failed: create slc allocation bw_mon_ratio_thresh entry\n");
          }
          else
          {
            v22 = device_create_file(a1 + 16, &dev_attr_current_governor);
            if ( v22 )
            {
              v26 = v22;
              dev_err(a1 + 16, "failed: create slc allocation current_governor entry\n");
            }
            else
            {
              v23 = device_create_file(a1 + 16, &dev_attr_available_governors);
              if ( !v23 )
              {
                _mutex_init(v5 + 192, "&pd->lock", &cache_allocation_probe___key);
                *(_QWORD *)(v5 + 88) = 0xFFFFFFFE00000LL;
                *(_QWORD *)(v5 + 96) = v5 + 96;
                *(_QWORD *)(v5 + 104) = v5 + 96;
                *(_QWORD *)(v5 + 112) = &cache_allocation_monitor_work;
                init_timer_key(v5 + 120, &delayed_work_timer_fn, 0x200000, 0, 0);
                *(_QWORD *)(a1 + 168) = v5;
                return 0;
              }
              v26 = v23;
              dev_err(a1 + 16, "failed: create slc allocation available_governors entry\n");
              device_remove_file(a1 + 16, &dev_attr_current_governor);
            }
            device_remove_file(a1 + 16, &dev_attr_bw_mon_ratio_thresh);
          }
          device_remove_file(a1 + 16, &dev_attr_win_count_config);
        }
        device_remove_file(a1 + 16, &dev_attr_freq_mon_thresh);
      }
      device_remove_file(a1 + 16, &dev_attr_sampling_time_ms);
    }
    device_remove_file(a1 + 16, &dev_attr_enable_monitor);
  }
  return v26;
}
