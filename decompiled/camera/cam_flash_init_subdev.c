__int64 __fastcall cam_flash_init_subdev(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w21
  const char *v4; // x5
  __int64 v5; // x4
  int v7; // w4
  unsigned int v8; // w0
  __int16 v9; // w8
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 5944) = &cam_flash_subdev_ops;
  *(_QWORD *)(a1 + 5960) = "cam-flash-dev";
  *(_DWORD *)(a1 + 5968) = 12;
  strcpy((char *)a1, "cam-flash");
  *(_DWORD *)(a1 + 5984) = 65547;
  *(_QWORD *)(a1 + 5952) = &cam_flash_internal_ops;
  *(_QWORD *)(a1 + 5976) = a1;
  *(_DWORD *)(a1 + 6016) = 1;
  v2 = cam_register_subdev(a1 + 5552);
  if ( v2 )
  {
    v3 = v2;
    v4 = "Fail to create subdev with %d";
    v5 = 504;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_init_subdev",
      v5,
      v4,
      v3);
    goto LABEL_4;
  }
  v12 = 0;
  v13 = 0;
  *(_QWORD *)s = 0;
  v11 = 0;
  *(_QWORD *)(a1 + 6880) = 0;
  *(_QWORD *)(a1 + 6888) = 0;
  hrtimer_init(a1 + 6752, 1, 1);
  hrtimer_init(a1 + 6816, 1, 1);
  v7 = *(_DWORD *)(a1 + 44);
  *(_QWORD *)(a1 + 6792) = on_timer_function;
  *(_QWORD *)(a1 + 6856) = &off_timer_function;
  *(_BYTE *)(a1 + 6896) = 0;
  *(_DWORD *)(a1 + 6900) = 1;
  snprintf(s, 0x20u, "%s%d%s", "camflash", v7, "_wq");
  v8 = cam_req_mgr_workq_create(s, 1u, (__int64 *)(a1 + 6904), 1, 0, (__int64)cam_flash_work_queue_handler);
  if ( v8 )
  {
    v3 = v8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "precise_flash_timer_init",
      275,
      "unable to create workq for %s",
      s);
    if ( (v3 & 0x80000000) == 0 )
      goto LABEL_4;
    v4 = "Precise Flash Init Failed: rc: %d";
    v5 = 509;
    goto LABEL_3;
  }
  v9 = debug_mdl;
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 6904) + 296LL) + 8LL) = a1;
  if ( (v9 & 0x1000) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v9 & 0x1000,
      4,
      "precise_flash_timer_init",
      286,
      "fctrl: %p on_timer: %p off_timer: %p ",
      (const void *)a1,
      (const void *)(a1 + 6752),
      (const void *)(a1 + 6816));
  v3 = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v3;
}
