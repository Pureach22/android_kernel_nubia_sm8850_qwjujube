__int64 __fastcall cpucp_log_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  int v5; // w0
  unsigned int v6; // w2
  unsigned __int64 v7; // x0
  unsigned __int64 qcom_scmi_device; // x0
  unsigned int v9; // w22
  __int64 (*v10)(void); // x8
  unsigned __int64 dir; // x0
  unsigned __int64 v12; // x22
  unsigned int v13; // w8
  __int64 v14; // x1
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  int v18; // w0
  unsigned __int64 v19; // x0
  __int64 v20; // x23
  __int64 v21; // x22
  int v22; // w8
  int v23; // w27
  unsigned int v24; // w25
  const char *v25; // x24
  int v26; // w9
  unsigned int v27; // w11
  __int64 v28; // x28
  __int64 resource; // x0
  __int64 v30; // x26
  __int64 v31; // x0
  __int64 v32; // x9
  int v33; // w8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x20
  __int64 v37; // x0
  int v38; // w9
  __int64 *v39; // x1
  int v40; // w9
  __int64 v41; // x8
  int v42; // w11
  _QWORD *v43; // x1
  __int64 v44; // x10
  _QWORD *v45; // x8
  int v46; // w9
  __int64 v47; // x10
  _QWORD *v48; // x1
  _QWORD *v49; // x8
  int v50; // w9
  __int64 v51; // x10
  _QWORD *v52; // x1
  _QWORD *v53; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v55; // x25
  __int64 v57; // x9
  __int64 v58; // x9
  __int64 v59; // x9
  unsigned int v60; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v61; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 3;
  v3 = devm_kmalloc(a1 + 16, 288, 3520);
  if ( !v3 )
  {
    v9 = -12;
    goto LABEL_90;
  }
  v4 = v3;
  v5 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,log-type", &v60, 1, 0);
  v6 = v60;
  if ( v60 > 2 || v5 < 0 )
  {
    dev_err(v1, "Invalid log type:%u, ret:%d\n", v60, v5 & (v5 >> 31));
    v9 = -19;
    goto LABEL_90;
  }
  *(_DWORD *)(v4 + 192) = v60;
  v7 = ops;
  *(_QWORD *)(v4 + 184) = v1;
  if ( v6 || v7 )
    goto LABEL_97;
  qcom_scmi_device = get_qcom_scmi_device();
  if ( qcom_scmi_device >= 0xFFFFFFFFFFFFF001LL )
  {
    v9 = dev_err_probe(v1, qcom_scmi_device, "Error getting scmi_dev ret=%d\n", qcom_scmi_device);
    goto LABEL_90;
  }
  v10 = *(__int64 (**)(void))(*(_QWORD *)(qcom_scmi_device + 928) + 24LL);
  if ( *((_DWORD *)v10 - 1) != -1171826031 )
    __break(0x8228u);
  v7 = v10();
  ops = v7;
  if ( v7 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_97:
    if ( *(_DWORD *)(v4 + 192) )
      goto LABEL_19;
LABEL_13:
    if ( !v7 )
      goto LABEL_19;
    dir = debugfs_create_dir("cpucp_log", 0);
    if ( dir > 0xFFFFFFFFFFFFF000LL )
    {
      dev_err(*(_QWORD *)(v4 + 184), "Debugfs cpucp directory creation failed\n");
    }
    else
    {
      v12 = dir;
      if ( (unsigned __int64)debugfs_create_file("log_level", 420, dir, 0, &log_level_ops) > 0xFFFFFFFFFFFFF000LL )
      {
        dev_err(*(_QWORD *)(v4 + 184), "Debugfs log_level file creation failed\n");
      }
      else if ( (unsigned __int64)debugfs_create_file("flush_log", 128, v12, 0, &flush_log_ops) > 0xFFFFFFFFFFFFF000LL )
      {
        dev_err(*(_QWORD *)(v4 + 184), "Debugfs flush_log file creation failed\n");
      }
      else if ( (unsigned __int64)debugfs_create_file("module_log_level", 128, v12, 0, &set_module_log_level_fops) > 0xFFFFFFFFFFFFF000LL )
      {
        dev_err(*(_QWORD *)(v4 + 184), "Debugfs directory creation failed for set_module_log_level\n");
      }
      else
      {
        if ( (unsigned __int64)debugfs_create_file("available_modules", 256, v12, 0, &avbl_module_ops) < 0xFFFFFFFFFFFFF001LL )
          goto LABEL_19;
        printk(&unk_850F);
      }
    }
    dev_err(v1, "Failed to create debugfs entries\n");
LABEL_79:
    v9 = -2;
    goto LABEL_90;
  }
  ops = 0;
  dev_err(v1, "Error getting vendor protocol ops: %d\n", v7);
  v7 = ops;
  if ( !*(_DWORD *)(v4 + 192) )
    goto LABEL_13;
LABEL_19:
  v13 = *(_DWORD *)(v4 + 192);
  if ( v13 - 1 > 1 )
    goto LABEL_26;
  v14 = pdp_log_dir;
  if ( !pdp_log_dir )
  {
    v15 = debugfs_create_dir("pdp_log", 0);
    pdp_log_dir = v15;
    if ( v15 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_70:
      dev_err(*(_QWORD *)(v4 + 184), "Debugfs pdp directory creation failed\n");
LABEL_78:
      dev_err(v1, "Failed to create pdp debugfs entries\n");
      goto LABEL_79;
    }
    v13 = *(_DWORD *)(v4 + 192);
    if ( v13 >= 3 )
      goto LABEL_87;
    v14 = v15;
  }
  v16 = debugfs_create_dir(cpucp_log_names[v13], v14);
  if ( v16 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_70;
  if ( (unsigned __int64)debugfs_create_file("log_enabled", 420, v16, v4, &log_enabled_ops) >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(v4 + 184), "Debugfs log_enabled file creation failed\n");
    goto LABEL_78;
  }
LABEL_26:
  *(_BYTE *)(v4 + 16) = 0;
  *(_BYTE *)(v4 + 32) = 1;
  *(_QWORD *)(v4 + 40) = cpucp_log_rx;
  *(_QWORD *)(v4 + 80) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 8) = v1;
  *(_QWORD *)(a1 + 168) = v4;
  *(_QWORD *)(v4 + 88) = v4 + 88;
  *(_QWORD *)(v4 + 96) = v4 + 88;
  *(_QWORD *)(v4 + 104) = &cpucp_log_work;
  init_timer_key(v4 + 112, &delayed_work_timer_fn, 2621440, 0, 0);
  *(_QWORD *)(v4 + 280) = 0;
  if ( !cpucp_wq )
    cpucp_wq = alloc_workqueue("%s", (const char *)0x4000E);
  v17 = mbox_request_channel(v4 + 8, 0);
  *(_QWORD *)(v4 + 64) = v17;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    v9 = v17;
    if ( (_DWORD)v17 != -517 )
    {
      dev_err(v1, "Failed to request mbox info: %d\n", (unsigned int)v17);
      goto LABEL_90;
    }
LABEL_30:
    v9 = -517;
    goto LABEL_90;
  }
  v18 = of_count_phandle_with_args(*(_QWORD *)(a1 + 760), "mboxes", "#mbox-cells");
  if ( v18 < 2 )
  {
    *(_QWORD *)(v4 + 72) = *(_QWORD *)(v4 + 64);
  }
  else
  {
    if ( v18 != 2 )
      dev_warn(v1, "Found %d mboxes which is not expected\n", v18);
    v19 = mbox_request_channel(v4 + 8, 1);
    *(_QWORD *)(v4 + 72) = v19;
    if ( v19 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v19 != -517 )
      {
        v9 = v19;
        dev_err(v1, "Failed to request tx mbox info: %d\n", (unsigned int)v19);
        goto LABEL_90;
      }
      goto LABEL_30;
    }
  }
  v20 = 16LL * *(unsigned int *)(a1 + 952);
  v21 = _kmalloc_noprof(v20, 3520);
  if ( v21 )
  {
    while ( 1 )
    {
      v22 = *(_DWORD *)(a1 + 952);
      *(_QWORD *)v4 = v21;
      if ( v22 )
      {
        v23 = 0;
        v24 = 0;
        v25 = "Failed to get the device base address\n";
        while ( 1 )
        {
          v28 = *(_QWORD *)v4;
          resource = platform_get_resource(a1, 512, v24);
          if ( !resource )
          {
            v9 = -19;
            goto LABEL_85;
          }
          v30 = resource;
          v31 = devm_ioremap(v1);
          if ( !v31 )
            break;
          v32 = v28 + 16LL * (int)v24;
          *(_DWORD *)(v32 + 12) = *(_QWORD *)v30;
          *(_QWORD *)v32 = v31;
          v33 = *(_DWORD *)(v30 + 8) - *(_DWORD *)v30 + 1;
          *(_DWORD *)(v32 + 8) = v33;
          if ( v23 && v23 != v33 )
          {
            v9 = -22;
            goto LABEL_89;
          }
          v26 = *(_DWORD *)(v4 + 216);
          v27 = *(_DWORD *)(a1 + 952);
          ++v24;
          if ( !v23 )
            v23 = v33;
          ++*(_DWORD *)(v4 + 212);
          *(_DWORD *)(v4 + 216) = v26 + v33;
          if ( v24 >= v27 )
            goto LABEL_49;
        }
        v9 = -12;
        v25 = "Failed to ioremap region\n";
LABEL_85:
        dev_err(v1, v25);
        goto LABEL_89;
      }
LABEL_49:
      if ( v20 )
        break;
      __break(1u);
LABEL_87:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v55 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &populate_free_buffers__alloc_tag;
      v20 = 16LL * *(unsigned int *)(a1 + 952);
      v21 = _kmalloc_noprof(v20, 3520);
      *(_QWORD *)(StatusReg + 80) = v55;
      if ( !v21 )
        goto LABEL_88;
    }
    v34 = devm_kmalloc(v1, (unsigned int)(4 * *(_DWORD *)(v21 + 8) + 4096), 3520);
    *(_QWORD *)(v4 + 232) = v34;
    if ( !v34 )
      goto LABEL_88;
    v35 = devm_kmalloc(v1, 1024, 3520);
    *(_QWORD *)(v4 + 224) = v35;
    if ( !v35 )
      goto LABEL_88;
    v36 = v4 + 248;
    *(_QWORD *)(v4 + 248) = v4 + 248;
    *(_QWORD *)(v4 + 256) = v4 + 248;
    *(_QWORD *)(v4 + 264) = v4 + 264;
    *(_QWORD *)(v4 + 272) = v4 + 264;
    v37 = devm_kmalloc(*(_QWORD *)(v4 + 184), 128, 3520);
    if ( !v37 )
      goto LABEL_88;
    v38 = *(_DWORD *)(v21 + 8);
    v39 = *(__int64 **)(v4 + 256);
    *(_QWORD *)(v37 + 16) = *(_QWORD *)(v4 + 232);
    *(_DWORD *)(v37 + 24) = v38;
    *(_DWORD *)(v37 + 28) = 1024;
    if ( v37 == v36 || v39 == (__int64 *)v37 || *v39 != v36 )
    {
      ((void (*)(void))_list_add_valid_or_report)();
      v37 = v57;
    }
    else
    {
      *(_QWORD *)(v4 + 256) = v37;
      *(_QWORD *)v37 = v36;
      *(_QWORD *)(v37 + 8) = v39;
      *v39 = v37;
    }
    v40 = *(_DWORD *)(v21 + 8);
    v41 = *(_QWORD *)(v4 + 232);
    v42 = 1024;
    v43 = *(_QWORD **)(v4 + 256);
    *(_DWORD *)(v37 + 56) = v40;
    *(_DWORD *)(v37 + 60) = 1024;
    v44 = v41 + (unsigned int)(v40 + 1024);
    v45 = (_QWORD *)(v37 + 32);
    *(_QWORD *)(v37 + 48) = v44;
    if ( v37 + 32 == v36 || v43 == v45 || *v43 != v36 )
    {
      _list_add_valid_or_report(v37 + 32, v43, v4 + 248);
      v37 = v58;
    }
    else
    {
      *(_QWORD *)(v4 + 256) = v45;
      *(_QWORD *)(v37 + 32) = v36;
      *(_QWORD *)(v37 + 40) = v43;
      *v43 = v45;
    }
    v46 = *(_DWORD *)(v21 + 8);
    v47 = *(_QWORD *)(v4 + 232);
    v48 = *(_QWORD **)(v4 + 256);
    *(_DWORD *)(v37 + 88) = v46;
    *(_DWORD *)(v37 + 92) = v42;
    v49 = (_QWORD *)(v37 + 64);
    *(_QWORD *)(v37 + 80) = v47 + (unsigned int)(2 * v46 + 2048);
    if ( v37 + 64 == v36 || v48 == v49 || *v48 != v36 )
    {
      _list_add_valid_or_report(v37 + 64, v48, v4 + 248);
      v37 = v59;
    }
    else
    {
      *(_QWORD *)(v4 + 256) = v49;
      *(_QWORD *)(v37 + 64) = v36;
      *(_QWORD *)(v37 + 72) = v48;
      *v48 = v49;
    }
    v50 = *(_DWORD *)(v21 + 8);
    v51 = *(_QWORD *)(v4 + 232);
    v52 = *(_QWORD **)(v4 + 256);
    *(_DWORD *)(v37 + 120) = v50;
    *(_DWORD *)(v37 + 124) = v42;
    v53 = (_QWORD *)(v37 + 96);
    *(_QWORD *)(v37 + 112) = v51 + (unsigned int)(3 * v50 + 3072);
    if ( v37 + 96 == v36 || v52 == v53 || *v52 != v36 )
    {
      _list_add_valid_or_report(v37 + 96, v52, v4 + 248);
      v9 = 0;
    }
    else
    {
      v9 = 0;
      *(_QWORD *)(v4 + 256) = v53;
      *(_QWORD *)(v37 + 96) = v36;
      *(_QWORD *)(v37 + 104) = v52;
      *v52 = v53;
    }
  }
  else
  {
LABEL_88:
    v9 = -12;
LABEL_89:
    kfree(*(_QWORD *)v4);
  }
LABEL_90:
  _ReadStatusReg(SP_EL0);
  return v9;
}
