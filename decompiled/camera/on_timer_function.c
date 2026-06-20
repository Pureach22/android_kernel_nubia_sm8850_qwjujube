__int64 __fastcall on_timer_function(__int64 a1)
{
  _DWORD *v2; // x23
  __int64 v3; // x0
  __int64 (*v4)(void); // x8
  int v5; // w20
  __int64 v6; // x0
  __int64 (*v7)(void); // x8
  int v8; // w0
  int v9; // w6
  __int64 v10; // x8
  __int16 v12; // w8
  char v13; // nf

  if ( !a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "on_timer_function",
      429,
      "Invalid Timer: %p",
      nullptr);
    return 0;
  }
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "on_timer_function",
      433,
      "timer: %p",
      (const void *)a1);
  v2 = (_DWORD *)(a1 - 608);
  if ( !*(_DWORD *)(a1 - 608) )
    goto LABEL_23;
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "on_timer_function",
      443,
      "LED_FLASH[%d]: set TRUE for LED Flash STROBE",
      0);
    v3 = *(_QWORD *)(a1 - 16);
    if ( v3 )
      goto LABEL_9;
LABEL_14:
    v5 = -22;
    goto LABEL_15;
  }
  v3 = *(_QWORD *)(a1 - 16);
  if ( !v3 )
    goto LABEL_14;
LABEL_9:
  v4 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 448) + 16LL);
  if ( *((_DWORD *)v4 - 1) != 1213401784 )
    __break(0x8228u);
  v5 = v4();
LABEL_15:
  if ( *v2 < 2u )
  {
    v9 = 1;
    if ( v5 < 0 )
    {
LABEL_30:
      *(_BYTE *)(a1 + 144) = 0;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "on_timer_function",
        450,
        "LED_Flash[%d]:set flash strobe failed, rc=%d",
        v9,
        v5);
      return 0;
    }
LABEL_23:
    v10 = *(_QWORD *)(a1 + 136);
    if ( v10 )
      hrtimer_start_range_ns(a1 + 64, 1000000 * v10, 0, 1);
    *(_BYTE *)(a1 + 144) = 1;
    return 0;
  }
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "on_timer_function",
      443,
      "LED_FLASH[%d]: set TRUE for LED Flash STROBE",
      1);
    v6 = *(_QWORD *)(a1 - 8);
    if ( v6 )
      goto LABEL_19;
LABEL_27:
    v8 = -22;
    goto LABEL_28;
  }
  v6 = *(_QWORD *)(a1 - 8);
  if ( !v6 )
    goto LABEL_27;
LABEL_19:
  v7 = *(__int64 (**)(void))(*(_QWORD *)(v6 + 448) + 16LL);
  if ( *((_DWORD *)v7 - 1) != 1213401784 )
    __break(0x8228u);
  v8 = v7();
LABEL_28:
  if ( *v2 < 3u )
  {
    v5 |= v8;
    v9 = 2;
    if ( v5 < 0 )
      goto LABEL_30;
    goto LABEL_23;
  }
  v12 = debug_mdl;
  if ( (debug_mdl & 0x1000) == 0 || debug_priority )
    __break(0x5512u);
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v12 & 0x1000,
    4,
    "on_timer_function",
    443,
    "LED_FLASH[%d]: set TRUE for LED Flash STROBE",
    2);
  __break(0x5512u);
  if ( !v13 )
    JUMPOUT(0x32578C);
  return cam_flash_i2c_apply_setting();
}
