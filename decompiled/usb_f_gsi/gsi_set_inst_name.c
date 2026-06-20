__int64 __fastcall gsi_set_inst_name(_QWORD *a1, char *s)
{
  unsigned __int64 v4; // x22
  int v5; // w22
  unsigned __int64 v6; // x23
  char *v7; // x21
  __int64 v8; // x24
  __int64 v9; // x9
  int v10; // w8
  size_t v11; // x0
  __int64 v12; // x24
  size_t v13; // x2
  const char *v14; // x1
  unsigned int v15; // w24
  unsigned int v16; // w0
  unsigned __int64 v17; // x0
  unsigned int v18; // w26
  unsigned int v19; // w26
  unsigned __int64 StatusReg; // x24
  __int64 v21; // x25
  __int64 v22; // x0
  _QWORD v24[7]; // [xsp+8h] [xbp-38h] BYREF

  v24[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 46);
  if ( (int)(strlen(s) + 1) > 40 )
  {
    LODWORD(v4) = -36;
    goto LABEL_67;
  }
  if ( !s )
    goto LABEL_54;
  v5 = strncasecmp(s, "rndis", 5u);
  if ( !v5 )
  {
    LODWORD(v6) = 0;
    goto LABEL_14;
  }
  if ( !strncasecmp(s, "ecm", 3u) )
  {
    LODWORD(v6) = 1;
    goto LABEL_14;
  }
  if ( !strncasecmp(s, "rmnet", 5u) )
  {
    LODWORD(v6) = 2;
    goto LABEL_14;
  }
  if ( !strncasecmp(s, "mbim", 4u) )
  {
    LODWORD(v6) = 3;
    goto LABEL_14;
  }
  if ( strncasecmp(s, "dpl", 3u) )
  {
LABEL_54:
    printk(&unk_1069F, "gsi_set_inst_name");
    LODWORD(v4) = -22;
    goto LABEL_67;
  }
  LODWORD(v6) = 4;
LABEL_14:
  v7 = (char *)&inst_status + 64 * (unsigned __int64)(unsigned int)v6;
  mutex_lock(v7);
  v8 = *((_QWORD *)v7 + 7);
  mutex_unlock(v7);
  if ( v8 )
  {
    printk(&unk_10EB2, "gsi_set_inst_name");
    LODWORD(v4) = -16;
    goto LABEL_67;
  }
  if ( !v5 )
    config_group_init_type_name(a1, *a1, &gsi_func_rndis_type);
  v4 = _kmalloc_cache_noprof(memcpy, 3520, 1408);
  if ( !v4 )
  {
LABEL_62:
    v4 = -12;
    goto LABEL_63;
  }
  while ( 1 )
  {
    *(_QWORD *)(v4 + 576) = 0xFFFFFFFE00000LL;
    *(_DWORD *)(v4 + 572) = 0;
    *(_QWORD *)(v4 + 584) = v4 + 584;
    *(_QWORD *)(v4 + 592) = v4 + 584;
    *(_QWORD *)(v4 + 600) = ipa_work_handler;
    init_timer_key(v4 + 608, &delayed_work_timer_fn, 0x200000, 0, 0);
    v9 = ipa_usb_wq;
    *(_DWORD *)(v4 + 224) = v6;
    *(_QWORD *)(v4 + 532) = 0xFFFFFFEAFFFFFFEALL;
    *(_QWORD *)(v4 + 680) = v9;
    *(_QWORD *)(v4 + 1264) = v4 + 1264;
    *(_QWORD *)(v4 + 1272) = v4 + 1264;
    v6 = v4 + 1056;
    *(_QWORD *)(v4 + 1280) = v4 + 1280;
    *(_QWORD *)(v4 + 1288) = v4 + 1280;
    *(_DWORD *)(v4 + 1304) = 0;
    _init_waitqueue_head(v4 + 1240, "&gsi->c_port.read_wq", &gsi_function_ctrl_port_init___key);
    v10 = *(_DWORD *)(v4 + 224);
    switch ( v10 )
    {
      case 4:
        v11 = strnlen((const char *)(v4 + 1056), 0xFu);
        if ( v11 >= 0x10 )
          goto LABEL_60;
        if ( v11 == 15 )
          goto LABEL_50;
        v12 = v11 >= 7 ? 14LL : v11 + 8;
        v13 = v11 >= 7 ? 14 - v11 : 8LL;
        v14 = "dpl_ctrl";
        break;
      case 3:
        v11 = strnlen((const char *)(v4 + 1056), 0xFu);
        if ( v11 >= 0x10 )
          goto LABEL_60;
        if ( v11 == 15 )
          goto LABEL_50;
        v12 = v11 >= 3 ? 14LL : v11 + 12;
        v13 = v11 >= 3 ? 14 - v11 : 12LL;
        v14 = "android_mbim";
        break;
      case 2:
        v11 = strnlen((const char *)(v4 + 1056), 0xFu);
        if ( v11 >= 0x10 )
        {
LABEL_60:
          _fortify_panic(2, 15, v11 + 1);
          goto LABEL_61;
        }
        if ( v11 == 15 )
          goto LABEL_50;
        v12 = v11 >= 5 ? 14LL : v11 + 10;
        v13 = v11 >= 5 ? 14 - v11 : 10LL;
        v14 = "rmnet_ctrl";
        break;
      default:
        goto LABEL_53;
    }
    memcpy((void *)(v6 + v11), v14, v13);
    if ( (unsigned __int64)(v12 - 352) >= 0xFFFFFFFFFFFFFA80LL )
      break;
LABEL_61:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &gsi_function_init__alloc_tag;
    v4 = _kmalloc_cache_noprof(memcpy, 3520, 1408);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v4 )
      goto LABEL_62;
  }
  *(_BYTE *)(v6 + v12) = 0;
LABEL_50:
  v15 = ida_alloc_range(&gsi_ida, 0, 2, 3264);
  if ( (v15 & 0x80000000) != 0 )
  {
    printk(&unk_11FD5, "gsi_function_ctrl_port_init");
  }
  else
  {
    cdev_init(v4 + 1072, &gsi_ctrl_dev_fops);
    v16 = cdev_add(v4 + 1072, v15 | (major << 20), 1);
    if ( v16 )
    {
      v18 = v16;
      ipc_log_string(
        *(_QWORD *)(v4 + 1344),
        "%s: Failed to add cdev for (%s)\n",
        "gsi_function_ctrl_port_init",
        (const char *)(v4 + 1056));
      printk(&unk_114BE, "gsi_function_ctrl_port_init");
      ida_free(&gsi_ida, v15);
      v15 = v18;
    }
    else
    {
      v17 = device_create(gsi_class, 0, v15 | (major << 20), 0, v4 + 1056);
      if ( v17 < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_53:
        *(_WORD *)(v4 + 1402) = 500;
        init_timer_key(v4 + 1360, gsi_rw_timer_func, 0, 0, 0);
        goto LABEL_63;
      }
      v19 = v17;
      ipc_log_string(
        *(_QWORD *)(v4 + 1344),
        "%s: device_create failed for (%s)\n",
        "gsi_function_ctrl_port_init",
        (const char *)(v4 + 1056));
      printk(&unk_11B38, "gsi_function_ctrl_port_init");
      cdev_del(v4 + 1072);
      ida_free(&gsi_ida, v15);
      v15 = v19;
    }
  }
  kfree(v4);
  v4 = (int)v15;
LABEL_63:
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
  {
    a1[22] = v4;
    scnprintf(v24, 46, "gsi.%s", s);
    v22 = ipc_log_context_create(10, v24, 0);
    if ( !v22 )
    {
      printk(&unk_11519, "gsi_set_inst_name");
      v22 = 0;
    }
    *(_QWORD *)(a1[22] + 1344LL) = v22;
    mutex_lock(v7);
    *((_QWORD *)v7 + 7) = a1;
    v7[48] = 1;
    mutex_unlock(v7);
    LODWORD(v4) = 0;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
