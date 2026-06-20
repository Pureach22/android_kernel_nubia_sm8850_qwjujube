__int64 __fastcall gf_probe(__int64 a1)
{
  int v2; // w24
  unsigned __int64 v3; // x0
  unsigned int v4; // w21
  void *v6; // x2
  __int64 v7; // x0
  __int64 device; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x10

  printk(&unk_95C1);
  qword_8378 = (__int64)&qword_8378;
  qword_8380 = (__int64)&qword_8378;
  qword_83AC = 0xFFFFFFEAFFFFFFEALL;
  qword_8388 = a1;
  unk_83B4 = 4294967274LL;
  word_83E0 = 0;
  qword_8408 = alloc_workqueue(&unk_8F3E, 393226, 1, "screen_state_wq");
  if ( qword_8408 )
  {
    qword_8410 = 0xFFFFFFFE00000LL;
    qword_8418 = (__int64)&qword_8418;
    qword_8420 = (__int64)&qword_8418;
    qword_8428 = (__int64)goodixfp_init_drm_notifier;
    init_timer_key(&unk_8430, &delayed_work_timer_fn, 0x200000, 0, 0);
    queue_delayed_work_on(32, qword_8408, &qword_8410, 1250);
  }
  mutex_lock(&device_list_lock);
  if ( (minors[0] | 0xFFFFFFFF00000000LL) == 0xFFFFFFFFFFFFFFFFLL )
  {
    mutex_unlock(&device_list_lock);
    v4 = -19;
  }
  else
  {
    v2 = __clz(__rbit64(~(minors[0] | 0xFFFFFFFF00000000LL)));
    gf = v2 | (SPIDEV_MAJOR << 20);
    v3 = device_create(gf_class, qword_8388 + 16);
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      _X9 = minors;
      __asm { PRFM            #0x11, [X9] }
      do
        v17 = __ldxr((unsigned __int64 *)minors);
      while ( __stxr(v17 | (1LL << v2), (unsigned __int64 *)minors) );
      v6 = device_list;
      if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)device_list) != &device_list
        || &qword_8378 == (__int64 *)&device_list
        || device_list == (_UNKNOWN *)&qword_8378 )
      {
        _list_add_valid_or_report(&qword_8378, &device_list);
      }
      else
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)device_list) = &qword_8378;
        qword_8378 = (__int64)v6;
        qword_8380 = (__int64)&device_list;
        device_list = &qword_8378;
      }
      v7 = mutex_unlock(&device_list_lock);
      device = input_allocate_device(v7);
      qword_83A0 = device;
      if ( device )
      {
        input_set_capability(device, 1, 102);
        input_set_capability(qword_83A0, 1, 139);
        input_set_capability(qword_83A0, 1, 158);
        input_set_capability(qword_83A0, 1, 116);
        input_set_capability(qword_83A0, 1, 103);
        input_set_capability(qword_83A0, 1, 108);
        input_set_capability(qword_83A0, 1, 106);
        input_set_capability(qword_83A0, 1, 105);
        input_set_capability(qword_83A0, 1, 212);
        input_set_capability(qword_83A0, 1, 114);
        input_set_capability(qword_83A0, 1, 115);
        input_set_capability(qword_83A0, 1, 217);
        input_set_capability(qword_83A0, 1, 216);
        *(_QWORD *)qword_83A0 = "goodix_fp";
        v4 = input_register_device(qword_83A0);
        if ( !v4 )
        {
          wakeup_source_add(&fp_wakelock);
          printk(&unk_8A2B);
          return v4;
        }
        printk(&unk_8B07);
        if ( qword_83A0 )
          input_free_device();
      }
      else
      {
        printk(&unk_96B6);
        v4 = -12;
      }
      if ( gf )
      {
        printk(&unk_9165);
        v9 = mutex_lock(&device_list_lock);
        list_del(v9);
        device_destroy(gf_class, (unsigned int)gf);
        v10 = 1LL << gf;
        _X9 = (unsigned __int64 *)&minors[((unsigned __int64)(unsigned int)gf >> 6) & 0x3FFF];
        __asm { PRFM            #0x11, [X9] }
        do
          v20 = __ldxr(_X9);
        while ( __stxr(v20 & ~v10, _X9) );
        mutex_unlock(&device_list_lock);
      }
    }
    else
    {
      v4 = v3;
      gf = 0;
    }
  }
  gf_cleanup(&gf);
  LOBYTE(word_83E0) = 0;
  return v4;
}
