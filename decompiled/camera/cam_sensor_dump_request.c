__int64 __fastcall cam_sensor_dump_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w22
  __int64 v9; // x10
  _QWORD *v10; // x26
  int v11; // w22
  _QWORD *v12; // x27
  unsigned int v13; // w23
  unsigned int *v14; // x8
  _DWORD *v15; // x8
  int v16; // w0
  __int64 v17; // x26
  _QWORD *v18; // x27
  int v19; // w22
  unsigned int v20; // w8
  unsigned int i; // w23
  _DWORD *v22; // x9
  __int64 result; // x0
  unsigned int v24; // [xsp+44h] [xbp-21Ch]
  unsigned __int64 v25; // [xsp+48h] [xbp-218h] BYREF
  char s[512]; // [xsp+50h] [xbp-210h] BYREF
  __int64 v27; // [xsp+250h] [xbp-10h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 28));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_dump_request",
      2753,
      "Device data is NULL");
    result = 4294967274LL;
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v3 = device_priv;
  v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
         3,
         32,
         3,
         "cam_sensor_dump_request",
         2760,
         "Sensor:[%s-%d] dump req_info, last applied sensor req:%llu error_req:%llu",
         (const char *)(device_priv + 7560),
         *(_DWORD *)(device_priv + 52),
         *(_QWORD *)(device_priv + 7608),
         *(_QWORD *)a1);
  v5 = *(_QWORD *)(v3 + 7600) & 0x1FLL;
  if ( *(__int64 *)(v3 + 7600) <= 0 )
    v5 = -(__int64)(-*(_BYTE *)(v3 + 7600) & 0x1F);
  if ( v5 < 0x20 )
  {
    v6 = v3 + 88 * v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      3,
      "cam_sensor_dump_request",
      2769,
      "Sensor[%s-%d] Feature: 0x%x updated for request id: %lu, res index: %u, width: %d, height: %d, capability: %s, fps: %u",
      (const char *)(v3 + 7560),
      *(_DWORD *)(v3 + 52),
      *(unsigned __int16 *)(v6 + 3666),
      *(_QWORD *)(v6 + 3680),
      *(unsigned __int16 *)(v6 + 3664),
      *(_DWORD *)(v6 + 3672),
      *(_DWORD *)(v6 + 3676),
      (const char *)(v6 + 3688),
      *(_DWORD *)(v6 + 3668));
    v7 = *(_QWORD *)(v3 + 7608);
    mutex_lock(v3 + 3608);
    if ( v7 )
    {
      v8 = 0;
      do
      {
        if ( v8 > (unsigned int)*(unsigned __int16 *)(v3 + 7556) + 1 )
          break;
        v25 = 0;
        memset(s, 0, sizeof(s));
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          3,
          "cam_sensor_dump_request_info",
          2670,
          "\tSensor:%s dump req info for req:%llu",
          (const char *)(v3 + 7560),
          v7);
        v9 = *(_QWORD *)(v3 + 7288) + 48 * (v7 & 0x1F);
        v24 = v8;
        if ( *(_DWORD *)(v9 + 16) && *(_QWORD *)(v9 + 24) == v7 )
        {
          v10 = *(_QWORD **)v9;
          if ( *(_QWORD *)v9 != v9 )
          {
            v11 = 0;
            do
            {
              v12 = (_QWORD *)v9;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                3,
                "cam_sensor_dump_request_info",
                2686,
                "\tSensor:%s per_frame_setting list:%d setting size:%d req:%llu at time[%llu: %09llu]",
                (const char *)(v3 + 7560),
                ++v11,
                *((_DWORD *)v10 - 16),
                v7,
                *(_QWORD *)(v9 + 32),
                *(_QWORD *)(v9 + 40));
              if ( *((_DWORD *)v10 - 16) )
              {
                v13 = 0;
                do
                {
                  v15 = (_DWORD *)(*(v10 - 9) + 16LL * (int)v13);
                  v16 = snprintf(nullptr, 0, "%04d: 0x%04x=0x%04x", v13, *v15, v15[1]);
                  if ( 512 - v25 < v16 + 50 )
                  {
                    v25 = 0;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      32,
                      3,
                      "cam_sensor_dump_request_info",
                      2696,
                      "\t Sensor:%s req:%llu %s",
                      (const char *)(v3 + 7560),
                      v7,
                      s);
                  }
                  v14 = (unsigned int *)(*(v10 - 9) + 16LL * (int)v13);
                  cam_print_to_buffer((__int64)s, 0x200u, &v25, 3u, 0x20u, "%04d: 0x%04x=0x%04x", v13++, *v14, v14[1]);
                }
                while ( v13 < *((_DWORD *)v10 - 16) );
              }
              v25 = 0;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                3,
                "cam_sensor_dump_request_info",
                2706,
                "\tSensor:%s req:%llu %s",
                (const char *)(v3 + 7560),
                v7,
                s);
              v10 = (_QWORD *)*v10;
              v9 = (__int64)v12;
            }
            while ( v10 != v12 );
          }
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            32,
            3,
            "cam_sensor_dump_request_info",
            2712,
            "\tsensor:%s per_frame_setting is_settings_valid:%d request_id:%llu",
            v3 + 7560);
        }
        v17 = *(_QWORD *)(v3 + 7304) + 48 * (v7 & 0x1F);
        if ( *(_DWORD *)(v17 + 16) && *(_QWORD *)(v17 + 24) == v7 )
        {
          v18 = *(_QWORD **)v17;
          if ( *(_QWORD *)v17 != v17 )
          {
            v19 = 0;
            do
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                3,
                "cam_sensor_dump_request_info",
                2727,
                "\tsensor:%s frame_skip_setting list:%d setting size:%d req:%llu at time[%llu: %09llu]",
                (const char *)(v3 + 7560),
                ++v19,
                *((_DWORD *)v18 - 16),
                v7,
                *(_QWORD *)(v17 + 32),
                *(_QWORD *)(v17 + 40));
              v20 = *((_DWORD *)v18 - 16);
              if ( v20 )
              {
                for ( i = 0; i < v20; ++i )
                {
                  v22 = (_DWORD *)(*(v18 - 9) + 16LL * (int)i);
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    32,
                    3,
                    "cam_sensor_dump_request_info",
                    2734,
                    "\tsensor:%s [%04d/%04d] req:%lld reg addr:0x%04x reg data:0x%04x",
                    (const char *)(v3 + 7560),
                    i,
                    v20,
                    v7,
                    *v22,
                    v22[1]);
                  v20 = *((_DWORD *)v18 - 16);
                }
              }
              v18 = (_QWORD *)*v18;
            }
            while ( v18 != (_QWORD *)v17 );
          }
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            32,
            3,
            "cam_sensor_dump_request_info",
            2740,
            "\tsensor:%s frame_skip_setting is_settings_valid:%d request_id:%llu",
            v3 + 7560);
        }
        --v7;
        v8 = v24 + 1;
      }
      while ( v7 );
    }
    mutex_unlock(v3 + 3608);
    result = 0;
    goto LABEL_32;
  }
  __break(0x5512u);
  return inline_copy_from_user_11(v4);
}
