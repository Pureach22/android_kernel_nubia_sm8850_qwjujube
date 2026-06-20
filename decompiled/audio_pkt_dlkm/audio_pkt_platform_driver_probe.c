__int64 __fastcall audio_pkt_platform_driver_probe(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x19
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  unsigned int v7; // w21
  unsigned __int64 v8; // x0
  __int64 v9; // x1
  unsigned int v10; // w0
  __int64 v12; // x0
  __int64 v13; // x9
  char v14; // w10

  v2 = devm_kmalloc(a1 + 16, 304, 3520);
  if ( !v2 )
    return (unsigned int)-12;
  v3 = (_DWORD *)(v2 + 288);
  v4 = v2;
  v5 = alloc_chrdev_region(v2 + 288, 0, 1, "aud_pasthru_adsp");
  if ( (v5 & 0x80000000) == 0 )
  {
    v6 = class_create("aud_pasthru_adsp");
    v7 = v6;
    *(_QWORD *)(v4 + 296) = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (unsigned int)__ratelimit(&audio_pkt_platform_driver_probe__rs_46, "audio_pkt_platform_driver_probe") )
        printk(&unk_8082, "audio_pkt_platform_driver_probe");
      ipc_log_string(0, "[%s]: class_create failed ret:%ld\n", "audio_pkt_platform_driver_probe", *(_QWORD *)(v4 + 296));
      goto LABEL_21;
    }
    v8 = device_create(v6, 0, *(unsigned int *)(v4 + 288), 0, "aud_pasthru_adsp");
    v7 = v8;
    *(_QWORD *)v4 = v8;
    if ( v8 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (unsigned int)__ratelimit(&audio_pkt_platform_driver_probe__rs_49, "audio_pkt_platform_driver_probe") )
        printk(&unk_8515, "audio_pkt_platform_driver_probe");
      ipc_log_string(0, "[%s]: device_create failed ret:%ld\n", "audio_pkt_platform_driver_probe", *(_QWORD *)v4);
      goto LABEL_20;
    }
    strcpy((char *)(v4 + 248), "aud_pasthru_adsp");
    strcpy((char *)(v4 + 268), "adsp_apps");
    dev_set_name(v8, v4 + 248);
    _mutex_init(v4 + 144, "&audpkt_dev->lock", &audio_pkt_platform_driver_probe___key);
    *(_DWORD *)(v4 + 192) = 0;
    *(_QWORD *)(v4 + 200) = v4 + 200;
    *(_QWORD *)(v4 + 208) = v4 + 200;
    *(_QWORD *)(v4 + 216) = 0;
    _init_waitqueue_head(v4 + 224, "&audpkt_dev->readq", &audio_pkt_platform_driver_probe___key_54);
    audio_pkt_backup_buffers = (__int64)&audio_pkt_backup_buffers;
    qword_7DB0 = (__int64)&audio_pkt_backup_buffers;
    qword_7DB8 = 0;
    audio_pkt_skb_backup_work = 0xFFFFFFFE00000LL;
    qword_7DC8 = (__int64)&qword_7DC8;
    qword_7DD0 = (__int64)&qword_7DC8;
    qword_7DD8 = (__int64)audio_pkt_alloc_backup;
    queue_work_on(32, system_unbound_wq);
    cdev_init(v4 + 8, &audio_pkt_fops);
    v9 = *(unsigned int *)(v4 + 288);
    *(_QWORD *)(v4 + 104) = &_this_module;
    v10 = cdev_add(v4 + 8, v9, 1);
    if ( v10 )
    {
      v7 = v10;
      if ( (unsigned int)__ratelimit(&audio_pkt_platform_driver_probe__rs_57, "audio_pkt_platform_driver_probe") )
        printk(&unk_7EC7, "audio_pkt_platform_driver_probe");
      ipc_log_string(
        0,
        "[%s]: cdev_add failed for %s ret:%d\n",
        "audio_pkt_platform_driver_probe",
        (const char *)(v4 + 248),
        v7);
      goto LABEL_19;
    }
    v12 = devm_kmalloc(a1 + 16, 80, 3520);
    ap_priv = v12;
    if ( v12 )
    {
      *(_DWORD *)(v12 + 72) = 0;
      _mutex_init(v12 + 24, "&ap_priv->lock", &audio_pkt_plaform_driver_register_gpr___key);
      *(_QWORD *)(ap_priv + 16) = v4;
      v7 = _gpr_driver_register(audio_pkt_driver, &_this_module);
      if ( (v7 & 0x80000000) == 0 )
      {
        v13 = ap_priv;
        v14 = audio_pkt_debug_mask;
        *(_QWORD *)(ap_priv + 8) = *(_QWORD *)v4;
        *(_QWORD *)(a1 + 168) = v13;
        if ( (v14 & 1) != 0 )
          ipc_log_string(0, "[%s]: Audio Packet Port Driver Initialized\n", "audio_pkt_platform_driver_probe");
        return v7;
      }
      dev_err(a1 + 16, "%s: registering to gpr driver failed, err = %d\n", "audio_pkt_plaform_driver_register_gpr", v7);
    }
    else
    {
      v7 = -12;
    }
    dev_err(a1 + 16, "%s: Failed to register with gpr, err = %d\n", "audio_pkt_platform_driver_probe", v7);
LABEL_19:
    device_destroy(*(_QWORD *)(v4 + 296), *(unsigned int *)(v4 + 288));
LABEL_20:
    class_destroy(*(_QWORD *)(v4 + 296));
LABEL_21:
    unregister_chrdev_region(*v3 >> 20, 1);
    return v7;
  }
  v7 = v5;
  if ( (unsigned int)__ratelimit(&audio_pkt_platform_driver_probe__rs, "audio_pkt_platform_driver_probe") )
    printk(&unk_8298, "audio_pkt_platform_driver_probe");
  ipc_log_string(0, "[%s]: alloc_chrdev_region failed ret:%d\n", "audio_pkt_platform_driver_probe", v7);
  return v7;
}
