__int64 __fastcall cpu_mpam_probe(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 next_child; // x0
  __int64 v5; // x1
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x20
  int v9; // w26
  int v10; // w23
  __int64 v11; // x9
  int cache_partition; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  unsigned __int64 v17; // x20
  __int64 resource_byname; // x0
  unsigned __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int64 group; // x0
  __int64 v22; // x0
  __int64 *v23; // x1
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v26; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned __int64 v27; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v28; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v27 = 0;
  v26 = 0;
  v25 = 0;
  StatusReg = _ReadStatusReg(ID_AA64PFR0_EL1);
  if ( !(StatusReg & 0xF0000000000LL | _ReadStatusReg(ID_AA64PFR1_EL1) & 0xF0000) )
  {
    dev_err(a1 + 16, "MPAM feature is not available\n");
    goto LABEL_60;
  }
  if ( (unsigned int)qcom_mpam_get_version(&v26) || !HIWORD(v26) )
  {
    dev_err(a1 + 16, "CPU MPAM is not available\n");
    goto LABEL_60;
  }
  v3 = *(_QWORD *)(a1 + 760);
  next_child = of_get_next_child(v3, 0);
  if ( !next_child )
  {
    mpam_msc_cnt = 0;
LABEL_48:
    dev_err(a1 + 16, "No MSC found\n");
    goto LABEL_60;
  }
  v5 = next_child;
  v6 = 0;
  do
  {
    ++v6;
    v5 = of_get_next_child(v3, v5);
  }
  while ( v5 );
  mpam_msc_cnt = v6;
  if ( !v6 )
    goto LABEL_48;
  if ( (v6 & 0x80000000) != 0 )
  {
LABEL_68:
    LODWORD(v17) = -12;
    mpam_mscs = 0;
    goto LABEL_61;
  }
  mpam_mscs = devm_kmalloc(a1 + 16, 16LL * v6, 3520);
  if ( mpam_mscs )
  {
    v7 = of_get_next_child(*(_QWORD *)(a1 + 760), 0);
    if ( v7 )
    {
      v8 = v7;
      v9 = 0;
      do
      {
        v10 = of_property_read_variable_u32_array(v8, "qcom,msc-id", &v28, 1, 0);
        of_property_read_string(v8, "qcom,msc-name", &v27);
        if ( (v10 & 0x80000000) == 0 && v28 <= 3 && v27 && v27 <= 0xFFFFFFFFFFFFF000LL )
        {
          v11 = mpam_mscs + 16LL * v9++;
          *(_DWORD *)v11 = v28;
          *(_QWORD *)(v11 + 8) = v27;
        }
        v8 = of_get_next_child(*(_QWORD *)(a1 + 760), v8);
      }
      while ( v8 );
      mpam_msc_cnt = v9;
      if ( v9 >= 1 )
      {
        v25 = 0x3F00000000LL;
        cache_partition = qcom_mpam_get_cache_partition(&v25, &mpam_default_val);
        if ( cache_partition )
        {
          dev_err(a1 + 16, "Error getting default value %d\n", cache_partition);
          LODWORD(mpam_default_val) = -1;
        }
        if ( mpam_msc_cnt >= 2 )
        {
          v25 = 0x3F00000001LL;
          v13 = qcom_mpam_get_cache_partition(&v25, &qword_80E0);
          if ( v13 )
          {
            dev_err(a1 + 16, "Error getting default value %d\n", v13);
            LODWORD(qword_80E0) = -1;
          }
          if ( mpam_msc_cnt >= 3 )
          {
            v25 = 0x3F00000002LL;
            v14 = qcom_mpam_get_cache_partition(&v25, &qword_80F0);
            if ( v14 )
            {
              dev_err(a1 + 16, "Error getting default value %d\n", v14);
              LODWORD(qword_80F0) = -1;
            }
            if ( mpam_msc_cnt >= 4 )
            {
              v25 = 0x3F00000003LL;
              v15 = qcom_mpam_get_cache_partition(&v25, &qword_8100);
              if ( v15 )
              {
                dev_err(a1 + 16, "Error getting default value %d\n", v15);
                LODWORD(qword_8100) = -1;
              }
              if ( mpam_msc_cnt >= 5 )
              {
                v25 = 0x3F00000004LL;
                v16 = qcom_mpam_get_cache_partition(&v25, &can_monitor);
                if ( v16 )
                {
                  dev_err(a1 + 16, "Error getting default value %d\n", v16);
LABEL_67:
                  __break(0x5512u);
                  goto LABEL_68;
                }
                if ( mpam_msc_cnt >= 6 )
                {
                  v25 = 0x3F00000005LL;
                  __break(0x5512u);
                  goto LABEL_34;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      mpam_msc_cnt = 0;
    }
    resource_byname = platform_get_resource_byname(a1, 512, "mon-base");
    if ( !resource_byname )
    {
      dev_err(a1 + 16, "cpu mpam does not have monitoring support\n");
      can_monitor = 0;
      goto LABEL_50;
    }
    v19 = devm_ioremap_resource(a1 + 16, resource_byname);
    mpam_mon_base = v19;
    if ( v19 && v19 < 0xFFFFFFFFFFFFF001LL )
    {
      can_monitor = 1;
      if ( mpam_msc_cnt >= 1 )
      {
        *(__int64 *)((char *)&mpam_default_val + 4) = 100;
        if ( mpam_msc_cnt != 1 )
        {
          *(__int64 *)((char *)&qword_80E0 + 4) = 100;
          if ( mpam_msc_cnt != 2 )
          {
            *(__int64 *)((char *)&qword_80F0 + 4) = 100;
            if ( mpam_msc_cnt != 3 )
            {
              *(__int64 *)((char *)&qword_8100 + 4) = 100;
              if ( mpam_msc_cnt != 4 )
                goto LABEL_67;
            }
          }
        }
      }
LABEL_50:
      monitor_enabled = 0x7FFFFFFF7FFFFFFFLL;
      qword_8128 = 0x7FFFFFFF7FFFFFFFLL;
      qword_8130 = 0x7FFFFFFF7FFFFFFFLL;
      qword_8138 = 0x7FFFFFFF7FFFFFFFLL;
      qword_8140 = 0x7FFFFFFF7FFFFFFFLL;
      qword_8148 = 0x7FFFFFFF7FFFFFFFLL;
      part_id_free_bitmap = bitmap_zalloc(48, 3264);
      monitor_free_bitmap = bitmap_zalloc(12, 3264);
      if ( part_id_free_bitmap )
      {
        config_group_init(&cpu_mpam_subsys);
        v20 = _mutex_init(&unk_198, "&cpu_mpam_subsys.su_mutex", &cpu_mpam_configfs_init___key);
        group = cpu_mpam_make_group(v20, "default");
        v17 = group;
        if ( group > 0xFFFFFFFFFFFFF000LL )
        {
          printk(&unk_7D75);
          if ( !(_DWORD)v17 )
            goto LABEL_61;
        }
        else
        {
          v22 = group + 120;
          v23 = (__int64 *)off_180[0];
          if ( (_UNKNOWN *)(v17 + 120) == &unk_178 || off_180[0] == v22 || *(_UNKNOWN **)off_180[0] != &unk_178 )
          {
            _list_add_valid_or_report();
          }
          else
          {
            off_180[0] = v22;
            *(_QWORD *)(v17 + 120) = &unk_178;
            *(_QWORD *)(v17 + 128) = v23;
            *v23 = v22;
          }
          LODWORD(v17) = configfs_register_subsystem(&cpu_mpam_subsys);
          if ( !(_DWORD)v17 )
          {
            tracepoint_probe_register(&_tracepoint_android_vh_mpam_set, cpu_mpam_switch_task, 0);
            goto LABEL_61;
          }
          printk(&unk_7D3F);
        }
      }
      else
      {
        printk(&unk_7DE7);
        LODWORD(v17) = -12;
      }
      dev_err(a1 + 16, "Error creating configfs %d\n", v17);
      goto LABEL_61;
    }
    dev_err(a1 + 16, "Error ioremap mpam_mon_base\n");
LABEL_60:
    LODWORD(v17) = -19;
    goto LABEL_61;
  }
LABEL_34:
  LODWORD(v17) = -12;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
