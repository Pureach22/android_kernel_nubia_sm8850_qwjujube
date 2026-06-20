__int64 __fastcall cam_sensor_apply_settings(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w28
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x21
  __int64 v9; // x19
  __int64 v10; // x27
  __int64 v11; // x9
  char *v12; // x19
  unsigned int v13; // w20
  char *v14; // x23
  __int64 v16; // x26
  _QWORD *v17; // x28
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x1
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 v28; // x6
  unsigned __int64 v29; // x10
  __int64 v30; // x13
  bool v31; // cf
  bool v32; // cc
  __int64 v33; // x8
  bool v34; // cf
  __int64 v35; // x8
  unsigned __int64 v36; // x24
  __int64 i; // x27
  __int64 j; // x26
  __int64 k; // x25
  __int64 m; // x23
  __int64 v41; // x4
  __int64 v42; // x0
  __int64 v43; // x1

  v3 = a3;
  if ( a2 )
  {
    if ( a2 >= 1 )
    {
      v6 = *(_QWORD *)(a1 + 7304);
      v7 = *(_QWORD *)(a1 + 7288);
      v8 = *(_QWORD *)(a1 + 7312);
      v9 = *(_QWORD *)(a1 + 7296);
      v10 = v6;
      if ( a3 != 7 )
      {
        v10 = *(_QWORD *)(a1 + 7296);
        if ( a3 != 12 )
        {
          if ( a3 == 11 )
          {
            v10 = *(_QWORD *)(a1 + 7312);
            v11 = v8 + 48 * (a2 & 0x1F);
            if ( *(_DWORD *)(v11 + 16) != 1 )
            {
              if ( *(_QWORD *)(v11 + 24) == a2 )
                v10 = *(_QWORD *)(a1 + 7288);
              else
                v10 = *(_QWORD *)(a1 + 7312);
            }
          }
          else
          {
            v10 = *(_QWORD *)(a1 + 7288);
          }
        }
      }
      v16 = v10 + 48 * (a2 & 0x1F);
      if ( *(_DWORD *)(v16 + 16) == 1 && *(_QWORD *)(v16 + 24) == a2 )
      {
        v13 = 0;
        v17 = (_QWORD *)(v10 + 48 * (a2 & 0x1F));
        while ( 1 )
        {
          v17 = (_QWORD *)*v17;
          if ( v17 == (_QWORD *)v16 )
            break;
          if ( (*(_BYTE *)(a1 + 7632) & 1) == 0 )
            v13 = cam_sensor_i2c_modes_util(a1 + 6480, v17 - 9);
          if ( (v13 & 0x80000000) != 0 )
          {
            v41 = 2216;
            goto LABEL_88;
          }
        }
        if ( (debug_mdl & 0x20) != 0 )
        {
          v3 = a3;
          if ( !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x20,
              4,
              "cam_sensor_apply_settings",
              2220,
              "applied req_id: %llu",
              a2);
        }
        else
        {
          v3 = a3;
        }
      }
      else
      {
        v13 = 0;
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_apply_settings",
            2223,
            "Invalid/NOP request to apply: %lld",
            a2);
          v13 = 0;
        }
      }
      v18 = ktime_get_with_offset(1);
      v19 = ns_to_timespec64(v18);
      v21 = v20 + 1000000000 * v19;
      v22 = v20;
      v23 = debug_mdl & 0x1000020;
      *(_QWORD *)(a1 + 7624) = v21;
      if ( v23 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v23,
          4,
          "cam_sensor_apply_settings",
          2234,
          "Apply req:%lld done on %ld:%06ld last_applied_done_timestamp:0x%llx",
          a2,
          v19,
          v22 / 1000,
          v21);
      *(_QWORD *)(a1 + 7608) = a2;
      v24 = ktime_get_with_offset(2);
      *(_QWORD *)(v16 + 32) = ns_to_timespec64(v24);
      *(_QWORD *)(v16 + 40) = v25;
      if ( (debug_mdl & 0x1000020) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000020,
          4,
          "cam_sensor_apply_settings",
          2240,
          "Sensor[%d] updating last_applied [req id: %lld last_applied: %lld] with opcode:%d",
          *(_DWORD *)(a1 + 52),
          a2,
          *(_QWORD *)(a1 + 7608),
          v3);
      v26 = *(unsigned __int16 *)(a1 + 7556);
      v27 = 0;
      v28 = 0;
      v29 = 0;
      do
      {
        v30 = *(_QWORD *)(v10 + v27 + 24) + v26;
        v31 = v30 > a2 || v28 >= v30;
        if ( !v31 && *(_DWORD *)(v10 + v27 + 16) == 1 )
        {
          v29 = v28;
          v28 = *(_QWORD *)(v10 + v27 + 24);
        }
        v27 += 48;
      }
      while ( v27 != 1536 );
      v32 = v26 < a2;
      v33 = ~v26;
      v34 = !v32 || v28 >= a2;
      v35 = v33 + a2;
      if ( v34 )
        v36 = v29;
      else
        v36 = v35;
      if ( v36 )
      {
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_sensor_apply_settings",
            2267,
            "top: %llu, del_req_id:%llu",
            v28,
            v36);
        for ( i = 0; i != 32; ++i )
        {
          if ( v36 > *(_QWORD *)(v7 + 24) && *(_DWORD *)(v7 + 16) == 1 )
          {
            *(_QWORD *)(v7 + 24) = 0;
            v13 = delete_request(v7);
            if ( (v13 & 0x80000000) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_apply_settings",
                2283,
                "Delete request Fail:%lld rc:%d i:%d j:%d",
                v36,
                v13,
                0,
                i);
          }
          v7 += 48;
        }
        for ( j = 0; j != 32; ++j )
        {
          if ( v36 > *(_QWORD *)(v6 + 24) && *(_DWORD *)(v6 + 16) == 1 )
          {
            *(_QWORD *)(v6 + 24) = 0;
            v13 = delete_request(v6);
            if ( (v13 & 0x80000000) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_apply_settings",
                2283,
                "Delete request Fail:%lld rc:%d i:%d j:%d",
                v36,
                v13,
                1,
                j);
          }
          v6 += 48;
        }
        for ( k = 0; k != 32; ++k )
        {
          if ( v36 > *(_QWORD *)(v8 + 24) && *(_DWORD *)(v8 + 16) == 1 )
          {
            *(_QWORD *)(v8 + 24) = 0;
            v13 = delete_request(v8);
            if ( (v13 & 0x80000000) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_apply_settings",
                2283,
                "Delete request Fail:%lld rc:%d i:%d j:%d",
                v36,
                v13,
                2,
                k);
          }
          v8 += 48;
        }
        for ( m = 0; m != 32; ++m )
        {
          if ( v36 > *(_QWORD *)(v9 + 24) && *(_DWORD *)(v9 + 16) == 1 )
          {
            *(_QWORD *)(v9 + 24) = 0;
            v13 = delete_request(v9);
            if ( (v13 & 0x80000000) != 0 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                32,
                1,
                "cam_sensor_apply_settings",
                2283,
                "Delete request Fail:%lld rc:%d i:%d j:%d",
                v36,
                v13,
                3,
                m);
          }
          v9 += 48;
        }
      }
      return v13;
    }
    return 0;
  }
  if ( a3 > 0xA || ((0x635u >> a3) & 1) == 0 )
    return 0;
  v12 = (char *)*(&off_456410 + a3) + a1;
  if ( *((_DWORD *)v12 + 4) == 1 )
  {
    v13 = 0;
    v14 = (char *)*(&off_456410 + a3) + a1;
    while ( 1 )
    {
      v14 = *(char **)v14;
      if ( v14 == v12 )
        break;
      if ( (*(_BYTE *)(a1 + 7632) & 1) == 0 )
        v13 = cam_sensor_i2c_modes_util(a1 + 6480, v14 - 72);
      if ( (v13 & 0x80000000) != 0 )
      {
        v41 = 2175;
LABEL_88:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_apply_settings",
          v41,
          "Failed to apply settings: %d",
          v13);
        return v13;
      }
    }
  }
  else
  {
    v13 = 0;
  }
  v42 = ktime_get_with_offset(2);
  *((_QWORD *)v12 + 4) = ns_to_timespec64(v42);
  *((_QWORD *)v12 + 5) = v43;
  return v13;
}
