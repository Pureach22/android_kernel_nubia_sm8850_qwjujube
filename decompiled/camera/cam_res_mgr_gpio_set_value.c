__int64 __fastcall cam_res_mgr_gpio_set_value(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x8
  int v5; // w9
  int v6; // w9
  __int64 v7; // x0
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x4
  __int64 v11; // x0
  int v13; // w9
  __int64 v14; // x0

  mutex_lock(cam_res + 488);
  if ( cam_res && *(_BYTE *)(cam_res + 200) == 1 )
  {
    v4 = cam_res + 456;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == cam_res + 456 )
        goto LABEL_11;
    }
    while ( *(_DWORD *)(v4 + 32) != a1 );
    v5 = *(_DWORD *)(v4 + 36);
    if ( a2 )
    {
      v6 = v5 + 1;
      *(_DWORD *)(v4 + 36) = v6;
      if ( v6 <= 1 )
      {
        v7 = gpio_to_desc(a1);
        gpiod_set_raw_value_cansleep(v7, a2);
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        {
          v8 = "Shared GPIO(%d) : HIGH";
          v9 = debug_mdl & 0x200000;
          v10 = 689;
LABEL_17:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v9,
            4,
            "cam_res_mgr_gpio_set_value",
            v10,
            v8,
            a1);
        }
      }
    }
    else
    {
      v13 = v5 - 1;
      *(_DWORD *)(v4 + 36) = v13;
      if ( v13 <= 0 )
      {
        v14 = gpio_to_desc(a1);
        gpiod_set_raw_value_cansleep(v14, 0);
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        {
          v8 = "Shared GPIO(%d) : LOW";
          v9 = debug_mdl & 0x200000;
          v10 = 696;
          goto LABEL_17;
        }
      }
    }
  }
  else
  {
LABEL_11:
    v11 = gpio_to_desc(a1);
    gpiod_set_raw_value_cansleep(v11, a2);
  }
  mutex_unlock(cam_res + 488);
  return 0;
}
