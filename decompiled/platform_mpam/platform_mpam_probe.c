__int64 __fastcall platform_mpam_probe(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w0
  __int64 next_child; // x0
  __int64 v5; // x1
  int v6; // w21
  unsigned int string_helper; // w0
  __int64 v8; // x21
  __int64 v9; // x27
  int v10; // w23
  unsigned __int64 v11; // x21
  __int64 resource_byname; // x0
  unsigned __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x22
  int v16; // w23
  int v17; // w26
  __int64 property; // x0
  const char *v19; // x27
  __int64 v20; // x28
  __int64 v21; // x0
  unsigned __int64 v22; // x26
  __int64 v23; // x0
  int v24; // w8
  unsigned int v25; // w9
  __int64 v26; // x1
  __int64 v27; // x1
  const char *v28; // x1
  void *v29; // x0
  unsigned __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  const char *v32; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v33; // [xsp+10h] [xbp-10h] BYREF
  int v34; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v34 = 0;
  v33 = 0;
  v31 = 0;
  v32 = nullptr;
  if ( (unsigned int)qcom_mpam_get_version(&mpam_version) || !HIWORD(mpam_version) )
  {
    dev_err(a1 + 16, "Platform MPAM is not available\n");
    goto LABEL_28;
  }
  config_group_init(&platform_mpam_subsys);
  _mutex_init(&unk_188, "&platform_mpam_subsys.su_mutex", &platform_mpam_probe___key);
  v3 = configfs_register_subsystem(&platform_mpam_subsys);
  if ( v3 )
  {
    LODWORD(v11) = v3;
    printk(&unk_6D4E, v3);
    goto LABEL_46;
  }
  next_child = of_get_next_child(v2, 0);
  if ( !next_child )
    goto LABEL_24;
  v5 = next_child;
  v6 = 0;
  do
  {
    v5 = of_get_next_child(v2, v5);
    --v6;
  }
  while ( v5 );
  if ( !v6 )
  {
LABEL_24:
    dev_err(a1 + 16, "No client found\n");
    goto LABEL_28;
  }
  string_helper = of_property_read_string_helper(v2, "qcom,gears", 0, 0, 0);
  support_gear_cnt = string_helper;
  if ( !string_helper )
  {
    dev_err(a1 + 16, "No available gears found\n");
    goto LABEL_28;
  }
  if ( (string_helper & 0x80000000) != 0 )
  {
    LODWORD(v11) = -12;
    support_gears = 0;
    goto LABEL_46;
  }
  support_gears = devm_kmalloc(a1 + 16, 16LL * string_helper, 3520);
  if ( !support_gears )
  {
    LODWORD(v11) = -12;
    goto LABEL_46;
  }
  if ( support_gear_cnt >= 1 )
  {
    v8 = 0;
    v9 = 8;
    do
    {
      of_property_read_string_helper(v2, "qcom,gears", support_gears + v9, 1, (unsigned int)v8);
      of_property_read_u32_index(v2, "qcom,gear-id", (unsigned int)v8++, support_gears + v9 - 8);
      v9 += 16;
    }
    while ( v8 < support_gear_cnt );
  }
  v10 = of_property_read_variable_u32_array(v2, "qcom,msc-id", &v34, 1, 0);
  of_property_read_string(v2, "qcom,msc-name", &v32);
  LODWORD(v11) = -19;
  if ( (v10 & 0x80000000) == 0 && v34 <= 3 )
  {
    LODWORD(v11) = -19;
    if ( v32 )
    {
      if ( (unsigned __int64)v32 <= 0xFFFFFFFFFFFFF000LL )
      {
        root_group = (__int64)&platform_mpam_subsys;
        v11 = configfs_register_default_group(&platform_mpam_subsys);
        if ( v11 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(a1 + 16, "Error register group %s\n", v32);
          goto LABEL_46;
        }
        resource_byname = platform_get_resource_byname(a1, 512, "mon-base");
        v13 = devm_ioremap_resource(a1 + 16, resource_byname);
        mpam_mon_base = v13;
        if ( v13 && v13 < 0xFFFFFFFFFFFFF001LL )
        {
          v14 = of_get_next_child(v2, 0);
          if ( v14 )
          {
            v15 = v14;
            v16 = 0;
            while ( 1 )
            {
              v17 = of_property_read_variable_u32_array(v15, "qcom,client-id", &v33, 1, 0);
              of_property_read_string(v15, "qcom,client-name", &v32);
              property = of_find_property(v15, "qcom,support-bw-limit", 0);
              if ( v17 < 0 )
                goto LABEL_30;
              v19 = v32;
              if ( !v32 || (unsigned __int64)v32 > 0xFFFFFFFFFFFFF000LL )
                goto LABEL_30;
              v20 = property;
              v21 = devm_kmalloc(a1 + 16, 168, 3520);
              if ( !v21 )
                break;
              v22 = v21;
              *(_QWORD *)(v21 + 160) = 0;
              v23 = devm_kmalloc(a1 + 16, 4, 3520);
              *(_QWORD *)(v22 + 152) = v23;
              if ( !v23 )
                break;
              config_group_init_type_name(v22, v19, &platform_mpam_item_type);
              if ( v22 >= 0xFFFFFFFFFFFFF001LL )
                break;
              v24 = v34;
              v25 = v33;
              v26 = *(_QWORD *)(v22 + 152);
              *(_DWORD *)(v22 + 136) = v34;
              *(_DWORD *)(v22 + 140) = v25;
              *(_DWORD *)(v22 + 144) = v16;
              v31 = __PAIR64__(v25, v24);
              if ( (unsigned int)qcom_mpam_get_platform_bw_ctrl(&v31, v26) )
              {
                printk(&unk_6EE9, v27);
              }
              else
              {
                if ( v20 )
                  *(_QWORD *)(v22 + 160) = qcom_mpam_get_bw_limit();
                if ( (unsigned int)configfs_register_group(v11, v22) )
                {
                  v28 = v32;
                  v29 = &unk_6E49;
                  goto LABEL_44;
                }
                ++v16;
              }
LABEL_30:
              v15 = of_get_next_child(v2, v15);
              if ( !v15 )
                goto LABEL_45;
            }
            v28 = v32;
            v29 = &unk_702D;
LABEL_44:
            printk(v29, v28);
            goto LABEL_30;
          }
LABEL_45:
          LODWORD(v11) = 0;
          goto LABEL_46;
        }
        dev_err(a1 + 16, "Error ioremap mpam_mon_base\n");
LABEL_28:
        LODWORD(v11) = -19;
      }
    }
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
