__int64 __fastcall cam_sensor_process_evt(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  int v4; // w8
  unsigned int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w8
  int v10; // w9
  const char *v11; // x7
  unsigned __int64 v12; // [xsp+38h] [xbp-18h] BYREF
  __int64 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
    if ( device_priv )
    {
      v3 = device_priv;
      if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20,
          4,
          "cam_sensor_process_evt",
          2576,
          "Received evt:%d",
          *(_DWORD *)(a1 + 20));
      mutex_lock(v3 + 3608);
      v4 = *(_DWORD *)(a1 + 20);
      v5 = 0;
      if ( v4 > 6 )
      {
        if ( v4 == 7 )
        {
          v10 = *(_DWORD *)(a1 + 24);
          v5 = 0;
          *(_BYTE *)(v3 + 7621) = v10 & 1;
          if ( (debug_mdl & 0x20) == 0 || debug_priority )
            goto LABEL_23;
          if ( (v10 & 1) != 0 )
            v11 = "Y";
          else
            v11 = "N";
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_process_evt",
            2603,
            "sensor %s stream off after eof:%s",
            (const char *)(v3 + 7560),
            v11);
          goto LABEL_22;
        }
        if ( v4 == 9 )
        {
          v6 = *(_QWORD *)(a1 + 8);
          *(_BYTE *)(a1 + 24) = 0;
          v7 = *(_QWORD *)(v3 + 7304) + 48 * (v6 & 0x1F);
          if ( !*(_DWORD *)(v7 + 16) || *(_QWORD *)(v7 + 24) != v6 )
          {
LABEL_22:
            v5 = 0;
            goto LABEL_23;
          }
          v5 = 0;
          *(_BYTE *)(a1 + 24) = 1;
        }
      }
      else
      {
        if ( v4 == 3 )
        {
          v8 = *(_DWORD *)(v3 + 7160);
          v12 = 0;
          v13 = 0;
          if ( v8 && !*(_QWORD *)(v3 + 7168) )
          {
            v5 = cam_sensor_apply_settings(v3, 0, 0);
            if ( (v5 & 0x80000000) != 0 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_process_evt",
                2616,
                "cannot apply streamon settings for %s",
                (const char *)(v3 + 7560));
            }
            else
            {
              *(_BYTE *)(v3 + 7622) = 0;
              *(_DWORD *)(v3 + 6544) = 4;
              ktime_get_real_ts64(&v12);
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                3,
                "cam_sensor_process_evt",
                2630,
                "%llu:%llu:%llu.%llu CAM_START_DEV for %s sensor_id:0x%x,sensor_slave_addr:0x%x num_batched_frames:%d post flush",
                (_QWORD)(v12 / 0xE10 - 24 * ((v12 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
                v12 / 0x3C
              - 60 * ((unsigned __int64)((v12 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
                v12 % 0x3C,
                v13 / 1000000,
                (const char *)(v3 + 7560),
                *(_DWORD *)(*(_QWORD *)(v3 + 3656) + 8LL),
                **(_DWORD **)(v3 + 3656),
                *(_DWORD *)(v3 + 7616));
            }
            goto LABEL_23;
          }
          goto LABEL_22;
        }
        if ( v4 == 6 )
        {
          if ( *(_BYTE *)(v3 + 7621) == 1 && (*(_BYTE *)(v3 + 7622) & 1) == 0 )
          {
            v5 = cam_sensor_stream_off(v3);
            if ( v5 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_process_evt",
                2586,
                "Failed to stream off %s",
                (const char *)(v3 + 7560));
              cam_sensor_notify_v4l2_error_event(v3);
            }
            goto LABEL_23;
          }
          goto LABEL_22;
        }
      }
LABEL_23:
      mutex_unlock(v3 + 3608);
      goto LABEL_24;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_process_evt",
      2572,
      "Device data is NULL");
    v5 = -22;
  }
  else
  {
    v5 = -22;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v5;
}
