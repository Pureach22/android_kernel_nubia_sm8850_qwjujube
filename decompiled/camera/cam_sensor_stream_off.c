__int64 __fastcall cam_sensor_stream_off(__int64 a1)
{
  int v2; // w7
  int v3; // w8
  unsigned int v4; // w20
  _QWORD *v6; // x22
  _QWORD *v7; // x24
  __int64 v8; // x0
  __int64 v9; // x1
  unsigned __int64 v10; // [xsp+28h] [xbp-18h] BYREF
  __int64 v11; // [xsp+30h] [xbp-10h]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 6544);
  v10 = 0;
  v11 = 0;
  if ( v2 == 2 || v2 == 4 )
  {
    if ( (*(_BYTE *)(a1 + 7622) & 1) != 0 || (v3 = *(_DWORD *)(a1 + 7208)) == 0 || *(_QWORD *)(a1 + 7216) )
    {
      v4 = 0;
    }
    else
    {
      if ( v3 == 1 )
      {
        v4 = 0;
        v6 = (_QWORD *)(a1 + 7192);
        v7 = (_QWORD *)(a1 + 7192);
        while ( 1 )
        {
          v7 = (_QWORD *)*v7;
          if ( v7 == v6 )
            break;
          if ( (*(_BYTE *)(a1 + 7632) & 1) == 0 )
            v4 = cam_sensor_i2c_modes_util(a1 + 6480, v7 - 9);
          if ( (v4 & 0x80000000) != 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              32,
              1,
              "cam_sensor_apply_settings",
              2175,
              "Failed to apply settings: %d",
              v4);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              32,
              1,
              "cam_sensor_stream_off",
              1343,
              "cannot apply streamoff settings for %s",
              (const char *)(a1 + 7560));
            goto LABEL_7;
          }
        }
      }
      else
      {
        v4 = 0;
      }
      v8 = ktime_get_with_offset(2);
      *(_QWORD *)(a1 + 7224) = ns_to_timespec64(v8);
      *(_QWORD *)(a1 + 7232) = v9;
    }
LABEL_7:
    cam_sensor_release_per_frame_resource(a1);
    *(_DWORD *)(a1 + 7552) = 0;
    *(_DWORD *)(a1 + 6544) = 1;
    *(_BYTE *)(a1 + 7622) = 0;
    memset((void *)(a1 + 3664), 0, 0xB00u);
    ktime_get_real_ts64(&v10);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      3,
      "cam_sensor_stream_off",
      1360,
      "%llu:%llu:%llu.%llu CAM_STOP_DEV Success for %s sensor_id:0x%x,sensor_slave_addr:0x%x",
      (_QWORD)(v10 / 0xE10 - 24 * ((v10 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
      v10 / 0x3C - 60 * ((unsigned __int64)((v10 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
      v10 % 0x3C,
      v11 / 1000000,
      (const char *)(a1 + 7560),
      *(_DWORD *)(*(_QWORD *)(a1 + 3656) + 8LL),
      **(_DWORD **)(a1 + 3656));
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      32,
      2,
      "cam_sensor_stream_off",
      1331,
      "Not in right state to stop %s state: %d",
      a1 + 7560);
    v4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
