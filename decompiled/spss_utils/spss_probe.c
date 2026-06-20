__int64 __fastcall spss_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  char v3; // w23
  char v4; // w26
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x2
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x27
  int v12; // w23
  int v13; // w0
  int v14; // w8
  int v15; // w9
  int v17; // w8
  unsigned int variable_u32_array; // w0
  unsigned int v19; // w0
  unsigned int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x0
  __int64 v23; // x21
  char v24; // w8
  int v25; // w8
  __int64 result; // x0
  const char *v27; // x8
  __int64 property; // x0
  __int64 v29; // x0
  __int64 v30; // x20
  int v31; // w0
  __int64 v32; // x0
  __int64 v33; // x8
  unsigned int v34; // w21
  unsigned __int64 v35; // x0
  unsigned __int64 v36; // x0
  _QWORD *v37; // x8
  __int64 v38; // x8
  unsigned int v39; // w0
  unsigned int file; // w0
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w0
  _QWORD *v45; // x1
  unsigned int v46; // w19
  void *v47; // x0
  int spss_image_size; // w0
  const char *v49; // x1
  unsigned int v50; // w20
  unsigned __int64 v51; // x0
  _QWORD v52[12]; // [xsp+8h] [xbp-C8h] BYREF
  int v53; // [xsp+68h] [xbp-68h] BYREF
  unsigned int v54; // [xsp+6Ch] [xbp-64h] BYREF
  __int64 v55; // [xsp+70h] [xbp-60h] BYREF
  _QWORD v56[11]; // [xsp+78h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v56[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(a1 + 168) = a1 + 16;
  spss_dev = a1 + 16;
  v55 = 0;
  v54 = 0;
  v53 = 0;
  memset(v52, 0, sizeof(v52));
  if ( (of_property_read_string(v2, "qcom,spss-dev-firmware-name", &dev_firmware_name) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_8BB2;
    goto LABEL_86;
  }
  if ( (of_property_read_string(v2, "qcom,spss-test-firmware-name", &test_firmware_name) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_8AA2;
    goto LABEL_86;
  }
  if ( (of_property_read_string(v2, "qcom,spss-prod-firmware-name", &prod_firmware_name) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_8E8C;
    goto LABEL_86;
  }
  if ( (of_property_read_variable_u32_array(v2, "qcom,spss-fuse1-addr", (char *)&v55 + 4, 1, 0) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_90AC;
    goto LABEL_86;
  }
  if ( (of_property_read_variable_u32_array(v2, "qcom,spss-fuse2-addr", &v54, 1, 0) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_88B8;
    goto LABEL_86;
  }
  if ( (of_property_read_variable_u32_array(v2, "qcom,spss-fuse1-bit", &v55, 1, 0) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_8ACD;
    goto LABEL_86;
  }
  if ( (of_property_read_variable_u32_array(v2, "qcom,spss-fuse2-bit", &v53, 1, 0) & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_899E;
    goto LABEL_86;
  }
  v3 = v53;
  v4 = v55;
  if ( arm64_use_ng_mappings )
    v5 = 0x68000000000F13LL;
  else
    v5 = 0x68000000000713LL;
  v6 = ioremap_prot(HIDWORD(v55), 4, v5);
  if ( !v6 )
  {
    v46 = -22;
    v47 = &unk_8C32;
    goto LABEL_86;
  }
  v7 = v6;
  if ( arm64_use_ng_mappings )
    v8 = 0x68000000000F13LL;
  else
    v8 = 0x68000000000713LL;
  v9 = ioremap_prot(v54, 4, v8);
  if ( !v9 )
  {
    iounmap(v7);
    v46 = -22;
    v47 = &unk_8956;
    goto LABEL_86;
  }
  v10 = v9;
  v11 = 1LL << v3;
  v12 = readl_relaxed(v7);
  v13 = readl_relaxed(v10);
  v14 = v12 & (1LL << v4);
  if ( v14 | v13 & (unsigned int)v11 )
    v15 = 116;
  else
    v15 = 112;
  if ( (v13 & (unsigned int)v11) == 0 || v14 == 0 )
    v17 = v15;
  else
    v17 = 112;
  firmware_type = v17;
  iounmap(v7);
  iounmap(v10);
  variable_u32_array = of_property_read_variable_u32_array(v2, "qcom,spss-debug-reg-addr", &spss_debug_reg_addr, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v46 = variable_u32_array;
    v47 = &unk_84E2;
    goto LABEL_86;
  }
  v19 = of_property_read_variable_u32_array(v2, "qcom,spss-debug-reg-addr1", &spss_debug_reg_addr1, 1, 0);
  if ( (v19 & 0x80000000) != 0 )
  {
    v46 = v19;
    v47 = &unk_8DCD;
    goto LABEL_86;
  }
  v20 = of_property_read_variable_u32_array(v2, "qcom,spss-debug-reg-addr3", &spss_debug_reg_addr3, 1, 0);
  if ( (v20 & 0x80000000) != 0 )
  {
    v46 = v20;
    v47 = &unk_863C;
    goto LABEL_86;
  }
  if ( (of_property_read_variable_u32_array(v2, "qcom,spss-emul-type-reg-addr", &spss_emul_type_reg_addr, 1, 0)
      & 0x80000000) != 0 )
  {
    v46 = -22;
    v47 = &unk_8C95;
    goto LABEL_86;
  }
  if ( arm64_use_ng_mappings )
    v21 = 0x68000000000F13LL;
  else
    v21 = 0x68000000000713LL;
  v22 = ioremap_prot((unsigned int)spss_emul_type_reg_addr, 4, v21);
  if ( !v22 )
  {
    v46 = -22;
    v47 = &unk_84A8;
    goto LABEL_86;
  }
  v23 = v22;
  v24 = readl_relaxed(v22);
  if ( (v24 & 3) != 0 )
  {
    if ( (v24 & 1) != 0 )
      v25 = 116;
    else
      v25 = 122;
    firmware_type = v25;
  }
  iounmap(v23);
  memset(v56, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "pil-mem", 0, 0, 0, v56) || !v56[0] )
  {
    printk(&unk_9019, "spss_parse_dt");
    if ( (of_property_read_variable_u32_array(v2, "qcom,pil-addr", &pil_addr, 1, 0) & 0x80000000) != 0 )
    {
      v46 = -14;
      v47 = &unk_904E;
      goto LABEL_86;
    }
    goto LABEL_84;
  }
  result = of_address_to_resource(v56[0], 0, v52);
  if ( !(_DWORD)result )
  {
    pil_addr = v52[0];
LABEL_84:
    spss_image_size = get_spss_image_size((unsigned __int64)(unsigned __int16)word_9772 << 16);
    if ( (spss_image_size & 0x80000000) == 0 )
    {
      cmac_mem_addr = (unsigned int)(pil_addr + spss_image_size);
      printk(&unk_8FDA, "spss_parse_dt");
      memset(&saved_fw_cmac, 165, 128);
      goto LABEL_42;
    }
    v46 = -14;
    v47 = &unk_8E04;
LABEL_86:
    v49 = "spss_parse_dt";
LABEL_87:
    printk(v47, v49);
LABEL_88:
    result = v46;
    goto LABEL_89;
  }
  if ( (result & 0x80000000) != 0 )
    goto LABEL_89;
LABEL_42:
  switch ( firmware_type )
  {
    case 'p':
      v27 = (const char *)prod_firmware_name;
      break;
    case 'z':
      v27 = "nospss";
      break;
    case 't':
      v27 = (const char *)test_firmware_name;
      break;
    default:
      printk(&unk_86AB, "spss_probe");
      result = 4294967274LL;
      goto LABEL_89;
  }
  firmware_name = v27;
  property = of_find_property(v2, "qcom,rproc-handle", 0);
  if ( !property )
  {
    result = 4294967274LL;
    goto LABEL_89;
  }
  v29 = rproc_get_by_phandle(bswap32(**(_DWORD **)(property + 16)));
  if ( !v29 )
  {
LABEL_74:
    result = 4294966779LL;
    goto LABEL_89;
  }
  v30 = v29;
  v31 = qcom_spss_set_fw_name(v29, firmware_name);
  if ( v31 < 0 )
  {
    if ( v31 != -22 )
    {
      printk(&unk_8D8B, "spss_probe");
      result = 4294966779LL;
      goto LABEL_89;
    }
    goto LABEL_74;
  }
  rproc_put(v30);
  spss_utils_dev = _kmalloc_cache_noprof(cdev_add, 3520, 40);
  if ( !spss_utils_dev )
    goto LABEL_63;
  v32 = _kmalloc_cache_noprof(alloc_chrdev_region, 3520, 136);
  v33 = spss_utils_dev;
  *(_QWORD *)spss_utils_dev = v32;
  if ( !v32 )
    goto LABEL_63;
  v34 = alloc_chrdev_region(v33 + 8, 0, 1, "spss_utils");
  if ( (v34 & 0x80000000) != 0 )
  {
    printk(&unk_8F84, "spss_utils_create_chardev");
    result = v34;
    goto LABEL_89;
  }
  v35 = class_create("spss_utils");
  *(_QWORD *)(spss_utils_dev + 16) = v35;
  if ( v35 >= 0xFFFFFFFFFFFFF001LL )
  {
    v46 = -12;
    printk(&unk_90F7, "spss_utils_create_chardev");
LABEL_98:
    unregister_chrdev_region(*(unsigned int *)(spss_utils_dev + 8), 1);
    goto LABEL_88;
  }
  v36 = device_create();
  v37 = (_QWORD *)spss_utils_dev;
  *(_QWORD *)(spss_utils_dev + 24) = v36;
  if ( v36 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_8B0F, "spss_utils_create_chardev");
    v46 = -12;
LABEL_97:
    class_destroy(*(_QWORD *)(spss_utils_dev + 16));
    goto LABEL_98;
  }
  cdev_init(*v37, &spss_utils_fops);
  v38 = spss_utils_dev;
  *(_QWORD *)(*(_QWORD *)spss_utils_dev + 96LL) = &_this_module;
  v39 = cdev_add(*(_QWORD *)v38, *(_DWORD *)(v38 + 8) & 0xFFF00000, 1);
  if ( (v39 & 0x80000000) != 0 )
  {
    v46 = v39;
    printk(&unk_8CD0, "spss_utils_create_chardev");
    device_destroy(*(_QWORD *)(spss_utils_dev + 16), *(unsigned int *)(spss_utils_dev + 8));
    goto LABEL_97;
  }
  file = device_create_file(v1, &dev_attr_firmware_name);
  if ( (file & 0x80000000) != 0 )
  {
    v49 = "spss_create_sysfs";
    v46 = file;
    v47 = &unk_91FF;
    goto LABEL_87;
  }
  v41 = device_create_file(v1, &dev_attr_test_fuse_state);
  if ( (v41 & 0x80000000) != 0 )
  {
    v50 = v41;
    printk(&unk_9273, "spss_create_sysfs");
LABEL_106:
    device_remove_file(v1, &dev_attr_firmware_name);
    result = v50;
    goto LABEL_89;
  }
  v42 = device_create_file(v1, &dev_attr_spss_debug_reg);
  if ( (v42 & 0x80000000) != 0 )
  {
    v50 = v42;
    printk(&unk_8510, "spss_create_sysfs");
LABEL_105:
    device_remove_file(v1, &dev_attr_test_fuse_state);
    goto LABEL_106;
  }
  v43 = device_create_file(v1, &dev_attr_calc_fw_cmac);
  if ( (v43 & 0x80000000) != 0 )
  {
    v50 = v43;
    printk(&unk_87B5, "spss_create_sysfs");
LABEL_104:
    device_remove_file(v1, &dev_attr_spss_debug_reg);
    goto LABEL_105;
  }
  v44 = device_create_file(v1, &dev_attr_calc_apps_cmac);
  if ( (v44 & 0x80000000) != 0 )
  {
    v50 = v44;
    printk(&unk_8F2C, "spss_create_sysfs");
    device_remove_file(v1, &dev_attr_calc_fw_cmac);
    goto LABEL_104;
  }
  v45 = (_QWORD *)_kmalloc_cache_noprof(cdev_init, 3520, 24);
  iar_nb = (__int64)v45;
  if ( !v45 )
  {
LABEL_63:
    result = 4294967284LL;
    goto LABEL_89;
  }
  *v45 = spss_utils_rproc_callback;
  v51 = qcom_register_ssr_notifier("spss");
  iar_notif_handle = v51;
  if ( !v51 || v51 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_8586, "spss_probe");
    kfree(iar_nb);
    iar_notif_handle = 0;
    iar_nb = 0;
  }
  spss_events = 0;
  _init_swait_queue_head(&unk_9630, "&x->wait", &init_completion___key);
  spss_events_signaled = 0;
  dword_9648 = 0;
  _init_swait_queue_head(&unk_9650, "&x->wait", &init_completion___key);
  LOBYTE(word_9729) = 0;
  dword_9668 = 0;
  _init_swait_queue_head(&unk_9670, "&x->wait", &init_completion___key);
  HIBYTE(word_9729) = 0;
  dword_9688 = 0;
  _init_swait_queue_head(&unk_9690, "&x->wait", &init_completion___key);
  byte_972B = 0;
  dword_96A8 = 0;
  _init_swait_queue_head(&unk_96B0, "&x->wait", &init_completion___key);
  byte_972C = 0;
  dword_96C8 = 0;
  _init_swait_queue_head(&unk_96D0, "&x->wait", &init_completion___key);
  byte_972D = 0;
  dword_96E8 = 0;
  _init_swait_queue_head(&unk_96F0, "&x->wait", &init_completion___key);
  LOBYTE(word_972E) = 0;
  dword_9708 = 0;
  _init_swait_queue_head(&unk_9710, "&x->wait", &init_completion___key);
  HIBYTE(word_972E) = 0;
  _mutex_init(&event_lock, "&event_lock", &spss_probe___key);
  is_iar_active = 0;
  is_ssr_disabled = 0;
  printk(&unk_8B7A, "spss_probe");
  result = 0;
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return result;
}
