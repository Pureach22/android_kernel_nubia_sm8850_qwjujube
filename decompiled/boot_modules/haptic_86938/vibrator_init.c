__int64 __fastcall vibrator_init(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 result; // x0

  printk(&unk_14A18, "haptic_hv", 4008, "vibrator_init");
  printk(&unk_15421, "haptic_hv", 4037, "vibrator_init");
  a1[21] = "zte_vibrator";
  a1[27] = brightness_get;
  v2 = a1[101];
  a1[25] = brightness_set;
  if ( (devm_led_classdev_register_ext(v2 + 32) & 0x80000000) != 0 )
    printk(&unk_145A6, "haptic_hv", 4053, "vibrator_init");
  if ( (sysfs_create_group(a1[31], &vibrator_attribute_group) & 0x80000000) != 0 )
    printk(&unk_14152, "haptic_hv", 4059, "vibrator_init");
  hrtimer_init(a1 + 102, 1, 1);
  a1[107] = vibrator_timer_func;
  a1[133] = 0xFFFFFFFE00000LL;
  a1[134] = a1 + 134;
  a1[135] = a1 + 134;
  a1[116] = 0xFFFFFFFE00000LL;
  a1[136] = vibrator_work_routine;
  a1[117] = a1 + 117;
  a1[118] = a1 + 117;
  a1[119] = rtp_work_routine;
  _mutex_init(a1 + 94, "&aw_haptic->lock", &vibrator_init___key_89);
  result = _mutex_init(a1 + 110, "&aw_haptic->rtp_lock", &vibrator_init___key_91);
  a1[217] = 0x100000000LL;
  a1[218] = a1 + 218;
  a1[219] = a1 + 218;
  return result;
}
