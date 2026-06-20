__int64 __fastcall cam_flash_high(__int64 a1, __int64 a2)
{
  unsigned int v2; // w9
  __int64 v3; // x19
  __int64 v4; // x19
  unsigned int v5; // w9
  __int64 v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w19
  __int64 v9; // x8
  __int64 v10; // x20

  if ( a2 )
  {
    v2 = *(_DWORD *)(a1 + 6148);
    if ( v2 )
    {
      if ( *(_QWORD *)(a1 + 6256) )
      {
        v3 = a1;
        cam_res_mgr_led_trigger_event(*(_QWORD *)(a1 + 6256));
        v2 = *(_DWORD *)(v3 + 6148);
        a1 = v3;
      }
      if ( v2 >= 2 )
      {
        if ( *(_QWORD *)(a1 + 6264) )
        {
          v4 = a1;
          cam_res_mgr_led_trigger_event(*(_QWORD *)(a1 + 6264));
          v2 = *(_DWORD *)(v4 + 6148);
          a1 = v4;
        }
        if ( v2 > 2 )
          goto LABEL_29;
      }
    }
    if ( *(_DWORD *)(a1 + 6716) == 1 )
    {
      v5 = *(_DWORD *)(a1 + 6144);
      if ( v5 )
      {
        v6 = *(_QWORD *)(a1 + 6720);
        if ( v6 )
        {
          if ( (debug_mdl & 0x1000) != 0 )
          {
            v7 = a1;
            if ( !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x1000,
                4,
                "cam_flash_high",
                810,
                "Led_Torch[%d]: brightness: 0 (LED_OFF)",
                0);
              v6 = *(_QWORD *)(v7 + 6720);
            }
          }
          else
          {
            v7 = a1;
          }
          led_set_brightness_sync(v6, 0);
          v5 = *(_DWORD *)(v7 + 6144);
          a1 = v7;
        }
        if ( v5 >= 2 )
        {
          v9 = *(_QWORD *)(a1 + 6728);
          if ( v9 )
          {
            if ( (debug_mdl & 0x1000) != 0 )
            {
              v10 = a1;
              if ( !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x1000,
                  4,
                  "cam_flash_high",
                  810,
                  "Led_Torch[%d]: brightness: 0 (LED_OFF)",
                  1);
                v9 = *(_QWORD *)(v10 + 6728);
              }
            }
            else
            {
              v10 = a1;
            }
            led_set_brightness_sync(v9, 0);
            v5 = *(_DWORD *)(v10 + 6144);
            a1 = v10;
          }
          if ( v5 > 2 )
          {
LABEL_29:
            __break(0x5512u);
            JUMPOUT(0x2AE940);
          }
        }
      }
    }
    v8 = cam_flash_ops(a1);
    if ( v8 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_high",
        819,
        "Fire Flash Failed: %d",
        v8);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_high",
      797,
      "Flash Data Null");
    return (unsigned int)-22;
  }
  return v8;
}
