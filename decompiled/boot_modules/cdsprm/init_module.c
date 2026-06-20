__int64 init_module()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x19
  unsigned int v2; // w19
  unsigned int v3; // w0
  unsigned int v4; // w0
  void *v5; // x0

  _mutex_init(&unk_A2E8, "&gcdsprm.rm_lock", &cdsprm_init___key);
  _mutex_init(&unk_A320, "&gcdsprm.rpmsg_lock", &cdsprm_init___key_114);
  _mutex_init(&unk_A3A8, "&gcdsprm.npu_activity_lock", &cdsprm_init___key_116);
  _mutex_init(&unk_A440, "&gcdsprm.thermal_lock", &cdsprm_init___key_118);
  qword_A318 = 0;
  dword_99B8 = 0;
  _init_swait_queue_head(&unk_99C0, "&x->wait", &init_completion___key);
  dword_A3F0 = 0;
  _init_swait_queue_head(&unk_A3F8, "&x->wait", &init_completion___key);
  dword_A410 = 0;
  _init_swait_queue_head(&unk_A418, "&x->wait", &init_completion___key);
  v0 = kthread_create_on_node(process_cdsp_request_thread, 0, 0xFFFFFFFFLL, "cdsprm-wq");
  v1 = v0;
  if ( v0 < 0xFFFFFFFFFFFFF001LL )
  {
    wake_up_process(v0);
    qword_A2B8 = v1;
    qword_A2C0 = alloc_workqueue("%s", (const char *)0x6000A);
    if ( qword_A2C0 )
    {
      qword_A2C8 = 0xFFFFFFFE00000LL;
      qword_A2D0 = (__int64)&qword_A2D0;
      qword_A2D8 = (__int64)&qword_A2D0;
      qword_A2E0 = (__int64)process_delayed_rm_request;
      v3 = _platform_driver_register(&cdsp_rm, &_this_module);
      if ( v3 )
      {
        v2 = v3;
        v5 = &unk_C70D;
      }
      else
      {
        LODWORD(qword_A494) = 1;
        dword_B310 = 0;
        _init_swait_queue_head(&unk_B318, "&x->wait", &init_completion___key);
        v4 = _platform_driver_register(&hvx_rm, &_this_module);
        if ( v4 )
        {
          v2 = v4;
          v5 = &unk_BCB7;
        }
        else
        {
          HIDWORD(qword_A494) = 1;
          v2 = _register_rpmsg_driver(&cdsprm_rpmsg_client, &_this_module);
          if ( !v2 )
          {
            byte_A489 = 1;
            printk(&unk_B614);
            return v2;
          }
          v5 = &unk_BC3F;
        }
      }
      printk(v5);
      destroy_workqueue(qword_A2C0);
    }
    else
    {
      printk(&unk_C369);
      v2 = -12;
    }
    kthread_stop(qword_A2B8);
    return v2;
  }
  qword_A2B8 = v0;
  printk(&unk_B3ED);
  return (unsigned int)-12;
}
