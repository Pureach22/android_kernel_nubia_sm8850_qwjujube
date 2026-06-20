__int64 __fastcall glink_pkt_probe(__int64 a1)
{
  __int64 v1; // d8
  __int64 v2; // d14
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 next_child; // x0
  __int64 v6; // x1
  unsigned int v7; // w21
  unsigned int v8; // w0
  unsigned __int64 v9; // x0
  unsigned int v10; // w20
  __int64 v11; // x0
  __int64 v12; // x20
  const char *v13; // x26
  __int64 v14; // x25
  unsigned int v15; // w0
  unsigned int v16; // w23
  const char *v17; // x19
  int string; // w0
  const char **v19; // x27
  const char *v20; // x22
  int v21; // w0
  const char **v22; // x24
  bool v23; // zf
  __int64 v24; // x0
  const char *v25; // x3
  const char *v26; // x4
  const char *v27; // x5
  int v28; // w7
  int v29; // w6
  __int64 v30; // x8
  __int64 v31; // x1
  int v32; // w8
  int v33; // w0
  int v34; // w22
  int v35; // w26
  int v36; // w0
  int v37; // w22
  __int64 v38; // x0
  const char *v39; // x23
  __int64 v40; // x22
  size_t v41; // x0
  unsigned __int64 v42; // x2
  __int64 v43; // x0
  __int64 v45; // x0
  _QWORD *v46; // x6
  __int64 v47; // [xsp+10h] [xbp-10h]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v3 = *(_QWORD *)(a1 + 760);
  v4 = a1;
  next_child = of_get_next_child(v3, 0);
  if ( next_child )
  {
    v6 = next_child;
    v7 = 0;
    do
    {
      ++v7;
      v6 = of_get_next_child(v3, v6);
    }
    while ( v6 );
  }
  else
  {
    v7 = 0;
  }
  num_glink_pkt_devs = v7;
  v8 = alloc_chrdev_region(&glink_pkt_major, 0, v7, "glinkpkt");
  if ( (v8 & 0x80000000) != 0 )
  {
    v10 = v8;
    if ( (unsigned int)__ratelimit(&glink_pkt_probe__rs, "glink_pkt_probe") )
      printk("%s[%s]: alloc_chrdev_region failed ret:%d\n", byte_9300, "glink_pkt_probe", v10);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: alloc_chrdev_region failed ret:%d\n",
      (const char *)&unk_90F5,
      "glink_pkt_probe",
      v10);
    return v10;
  }
  v9 = class_create("glinkpkt");
  glink_pkt_class = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v9;
    if ( (unsigned int)__ratelimit(&glink_pkt_probe__rs_7, "glink_pkt_probe") )
      printk("%s[%s]: class_create failed ret:%d\n", byte_9300, "glink_pkt_probe", v10);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: class_create failed ret:%d\n",
      (const char *)&unk_90F5,
      "glink_pkt_probe",
      v10);
    class_destroy(glink_pkt_class);
    unregister_chrdev_region((unsigned int)glink_pkt_major >> 20, (unsigned int)num_glink_pkt_devs);
    return v10;
  }
  v11 = of_get_next_child(*(_QWORD *)(v4 + 760), 0);
  if ( !v11 )
  {
LABEL_58:
    ipc_log_string(glink_pkt_ilctxt, "[%s]: G-Link Packet Port Driver Initialized\n", "glink_pkt_probe");
    return 0;
  }
  v12 = v11;
  v13 = (const char *)&unk_90F5;
  _ReadStatusReg(SP_EL0);
  v47 = v4 + 16;
  v48 = v4;
  while ( 1 )
  {
    v14 = _kmalloc_cache_noprof(cdev_init, 3520, 1608);
    if ( !v14 )
      goto LABEL_17;
    v15 = ida_alloc_range(&glink_pkt_minor_ida, 0, (unsigned int)(num_glink_pkt_devs - 1), 3264);
    if ( (v15 & 0x80000000) == 0 )
      break;
    kfree(v14);
LABEL_17:
    v12 = of_get_next_child(*(_QWORD *)(v4 + 760), v12);
    if ( !v12 )
      goto LABEL_58;
  }
  v16 = v15;
  v17 = v13;
  string = of_property_read_string(v12, "qcom,glinkpkt-edge", v14 + 1520);
  if ( string < 0 )
  {
    v35 = string;
    v20 = "qcom,glinkpkt-edge";
    goto LABEL_32;
  }
  v19 = (const char **)(v14 + 1512);
  v20 = "qcom,glinkpkt-ch-name";
  v21 = of_property_read_string(v12, "qcom,glinkpkt-ch-name", v14 + 1512);
  if ( v21 < 0
    || (v22 = (const char **)(v14 + 1504),
        v20 = "qcom,glinkpkt-dev-name",
        v21 = of_property_read_string(v12, "qcom,glinkpkt-dev-name", v14 + 1504),
        v21 < 0) )
  {
    v35 = v21;
LABEL_32:
    if ( (unsigned int)__ratelimit(&glink_pkt_parse_devicetree__rs, "glink_pkt_parse_devicetree") )
      printk(
        "%s[%s]: %s: missing key: %s\n",
        byte_9300,
        "glink_pkt_parse_devicetree",
        "glink_pkt_parse_devicetree",
        v20);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: %s: missing key: %s\n",
      v17,
      "glink_pkt_parse_devicetree",
      "glink_pkt_parse_devicetree",
      v20);
    if ( (unsigned int)__ratelimit(&glink_pkt_create_device__rs, "glink_pkt_create_device") )
      printk("%s[%s]: failed to parse dt ret:%d\n", byte_9300, "glink_pkt_create_device", v35);
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: failed to parse dt ret:%d\n", v17, "glink_pkt_create_device", v35);
    ida_free(&glink_pkt_minor_ida, *(_DWORD *)(v14 + 760) & 0xFFFFF);
    kfree(v14);
    v13 = v17;
    v4 = v48;
    goto LABEL_17;
  }
  *(_BYTE *)(v14 + 1229) = of_find_property(v12, "qcom,glinkpkt-enable-ch-close", 0) != 0;
  v23 = of_find_property(v12, "qcom,glinkpkt-fragmented-read", 0) == 0;
  v24 = glink_pkt_ilctxt;
  v25 = *(const char **)(v14 + 1520);
  v26 = *(const char **)(v14 + 1512);
  v27 = *(const char **)(v14 + 1504);
  v28 = !v23;
  v29 = *(unsigned __int8 *)(v14 + 1229);
  *(_BYTE *)(v14 + 1228) = v28;
  ipc_log_string(
    v24,
    "[%s]: Parsed %s:%s /dev/%s enable channel close:%d fragmented-read:%d\n",
    "glink_pkt_parse_devicetree",
    v25,
    v26,
    v27,
    v29,
    v28);
  _mutex_init(v14 + 1048, "&gpdev->lock", &glink_pkt_create_device___key);
  _mutex_init(v14 + 1232, "&gpdev->drv_lock", &glink_pkt_create_device___key_14);
  _mutex_init(v14 + 1536, "&gpdev->rskb_read_lock", &glink_pkt_create_device___key_16);
  *(_DWORD *)(v14 + 1128) = 1;
  *(_DWORD *)(v14 + 1096) = 0;
  _init_swait_queue_head(v14 + 1104, "&x->wait", &init_completion___key);
  *(_DWORD *)(v14 + 1528) = 120;
  *(_QWORD *)(v14 + 1152) = v14 + 1152;
  *(_QWORD *)(v14 + 1160) = v14 + 1152;
  *(_DWORD *)(v14 + 1224) = 0;
  *(_BYTE *)(v14 + 1144) = 0;
  *(_DWORD *)(v14 + 1148) = 0;
  *(_QWORD *)(v14 + 1584) = 0;
  *(_QWORD *)(v14 + 1592) = 0;
  *(_QWORD *)(v14 + 1600) = 0;
  *(_QWORD *)(v14 + 1168) = 0;
  *(_QWORD *)(v14 + 1176) = v14 + 1176;
  *(_QWORD *)(v14 + 1184) = v14 + 1176;
  *(_QWORD *)(v14 + 1192) = 0;
  _init_waitqueue_head(v14 + 1200, "&gpdev->readq", &glink_pkt_create_device___key_18);
  device_initialize(v14);
  v30 = glink_pkt_class;
  *(_QWORD *)(v14 + 96) = v47;
  *(_QWORD *)(v14 + 800) = &glink_pkt_device_groups;
  *(_QWORD *)(v14 + 792) = v30;
  *(_QWORD *)(v14 + 152) = v14;
  cdev_init(v14 + 912, &glink_pkt_fops);
  v31 = *(_QWORD *)(v14 + 1504);
  v32 = glink_pkt_major;
  *(_QWORD *)(v14 + 1008) = &_this_module;
  *(_DWORD *)(v14 + 760) = v32 & 0xFFF00000 | v16;
  dev_set_name(v14, v31, v16);
  v33 = cdev_add(v14 + 912, *(unsigned int *)(v14 + 760), 1);
  if ( v33 )
  {
    v34 = v33;
    if ( (unsigned int)__ratelimit(&glink_pkt_create_device__rs_20, "glink_pkt_create_device") )
      printk("%s[%s]: cdev_add failed for %s ret:%d\n", byte_9300, "glink_pkt_create_device", *v22, v34);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: cdev_add failed for %s ret:%d\n",
      v13,
      "glink_pkt_create_device",
      *(const char **)(v14 + 1504),
      v34);
    ida_free(&glink_pkt_minor_ida, *(_DWORD *)(v14 + 760) & 0xFFFFF);
    kfree(v14);
    v4 = v48;
    goto LABEL_17;
  }
  *(_QWORD *)(v14 + 808) = glink_pkt_release_device;
  v36 = device_add(v14);
  if ( v36 )
  {
    v37 = v36;
    v4 = v48;
    if ( (unsigned int)__ratelimit(&glink_pkt_create_device__rs_22, "glink_pkt_create_device") )
      printk("%s[%s]: device_create failed for %s ret:%d\n", byte_9300, "glink_pkt_create_device", *v22, v37);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: device_create failed for %s ret:%d\n",
      v13,
      "glink_pkt_create_device",
      *v22,
      v37);
LABEL_41:
    put_device(v14);
    goto LABEL_17;
  }
  v4 = v48;
  if ( (unsigned int)device_create_file(v14, &dev_attr_open_timeout) )
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_create_device__rs_24, "glink_pkt_create_device") )
      printk("%s[%s]: device_create_file failed for %s\n", byte_9300, "glink_pkt_create_device", *v22);
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: device_create_file failed for %s\n", v13, "glink_pkt_create_device", *v22);
  }
  v38 = devm_kmalloc(v14, 80, 3520);
  if ( !v38 )
    goto LABEL_41;
  v39 = *v19;
  v40 = v38;
  v41 = strnlen(*v19, 0x20u);
  if ( v41 == -1 )
    goto LABEL_61;
  if ( v41 == 32 )
    v42 = 32;
  else
    v42 = v41 + 1;
  if ( v42 < 0x21 )
  {
    sized_strscpy(v40, v39);
    v43 = devm_kasprintf(v14, 3264, "%s_%s", "glink_pkt", *(const char **)(v14 + 1504));
    if ( v43 )
    {
      *(_QWORD *)(v14 + 1280) = v43;
      *(_QWORD *)(v14 + 1464) = glink_pkt_rpdev_probe;
      *(_QWORD *)(v14 + 1472) = glink_pkt_rpdev_remove;
      *(_QWORD *)(v14 + 1480) = glink_pkt_rpdev_cb;
      *(_QWORD *)(v14 + 1456) = v40;
      mutex_lock(v14 + 1232);
      if ( (*(_BYTE *)(v14 + 1496) & 1) != 0 )
        goto LABEL_57;
      if ( !(unsigned int)_register_rpmsg_driver(v14 + 1280, &_this_module) )
      {
        *(_BYTE *)(v14 + 1496) = 1;
LABEL_57:
        mutex_unlock(v14 + 1232);
        goto LABEL_17;
      }
      mutex_unlock(v14 + 1232);
    }
    goto LABEL_41;
  }
  _fortify_panic(7, 32);
LABEL_61:
  v45 = _fortify_panic(2, -1);
  *v46 = v1;
  v46[1] = v2;
  return glink_pkt_release_device(v45);
}
