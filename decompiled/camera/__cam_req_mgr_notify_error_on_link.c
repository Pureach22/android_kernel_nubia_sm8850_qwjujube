__int64 __fastcall _cam_req_mgr_notify_error_on_link(_DWORD *a1, __int64 a2)
{
  _DWORD *v2; // x22
  _DWORD *v4; // x23
  int v5; // w20
  __int64 result; // x0
  unsigned int v7; // w6
  __int64 v8; // x0
  unsigned int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x21
  _DWORD *v14; // x27
  int v15; // w28
  _DWORD *v16; // x8
  unsigned int *v17; // x8
  const char *v18; // x6
  __int64 v19; // x9
  int v20; // w8
  int v21; // w9
  int v22; // w20
  __int64 v23; // x0
  unsigned int v25; // [xsp+54h] [xbp-4Ch] BYREF
  __int64 v26; // [xsp+58h] [xbp-48h] BYREF
  __int64 v27; // [xsp+60h] [xbp-40h]
  __int64 v28; // [xsp+68h] [xbp-38h]
  __int64 v29; // [xsp+70h] [xbp-30h]
  __int64 v30; // [xsp+78h] [xbp-28h]
  __int64 v31; // [xsp+80h] [xbp-20h]
  __int64 v32; // [xsp+88h] [xbp-18h]
  __int64 v33; // [xsp+90h] [xbp-10h]
  __int64 v34; // [xsp+98h] [xbp-8h]

  v2 = a1 + 0x2000;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_DWORD **)a1 + 4145);
  if ( v4 )
  {
    v5 = *(_DWORD *)(a2 + 288);
    if ( v5 < 3 )
    {
      v7 = a1[3];
      if ( v7 < 3 )
      {
        _cam_req_mgr_send_evt(*(_QWORD *)&a1[6 * v7 + 20], 5, 2, a1);
        if ( (*((_BYTE *)v2 + 593) & 1) != 0 )
        {
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     16,
                     3,
                     "__cam_req_mgr_notify_error_on_link",
                     614,
                     "Internal recovery succeeded on link: 0x%x",
                     *a1);
        }
        else
        {
          if ( (unsigned int)__ratelimit(&_cam_req_mgr_notify_error_on_link__rs, "__cam_req_mgr_notify_error_on_link") )
            v8 = 3;
          else
            v8 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v8,
            16,
            1,
            "__cam_req_mgr_notify_error_on_link",
            620,
            "Notifying userspace to trigger recovery on link 0x%x for session %d",
            *a1,
            *v4);
          v9 = v2[70];
          v29 = 0;
          v30 = 0;
          v27 = 0;
          v28 = 0;
          v25 = v9;
          v26 = 0;
          v10 = ktime_get_with_offset(2);
          v11 = ns_to_timespec64(v10);
          v13 = v12;
          time64_to_tm(v11, 0, &v26);
          v14 = a1 + 54;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            3,
            "__cam_req_mgr_dump_state_monitor_array",
            382,
            "Link %x start dump state monitor array, time: %d-%d %d:%d:%d.%lld",
            *a1,
            v28 + 1,
            HIDWORD(v27),
            v27,
            HIDWORD(v26),
            v26,
            v13 / 1000000);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            3,
            "__cam_req_mgr_dump_state_monitor_array",
            385,
            "%16s  %6s  %10s  %8s  %10s",
            "state",
            "req id",
            "dev hdl",
            "frame id",
            "time stamp");
          raw_spin_lock_bh(a1 + 8276);
          v15 = 108;
          do
          {
            if ( v25 >= 0x6C )
              goto LABEL_30;
            v16 = &v14[76 * v25];
            if ( *v16 != 6 )
            {
              time64_to_tm(*((_QWORD *)v16 + 4), 0, &v26);
              if ( v25 > 0x6B )
                goto LABEL_30;
              v17 = &v14[76 * v25];
              v18 = "INVALID_TYPE";
              v19 = *v17;
              if ( (unsigned int)v19 <= 5 )
                v18 = off_448570[v19];
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                16,
                3,
                "__cam_req_mgr_dump_state_monitor_array",
                398,
                "%16s  %6d  %10x  %8d  %d-%d %d:%d:%d.%lld",
                v18,
                *((_QWORD *)v17 + 1),
                v17[4],
                *((_QWORD *)v17 + 3),
                v28 + 1,
                HIDWORD(v27),
                v27,
                HIDWORD(v26),
                v26,
                *((_QWORD *)v17 + 5) / 1000000LL);
            }
            cam_common_inc_idx(&v25, 1, 108);
            --v15;
          }
          while ( v15 );
          raw_spin_unlock_bh(a1 + 8276);
          v26 = 0;
          v27 = 0;
          v28 = 0;
          v29 = 0;
          v30 = 0;
          v31 = 0;
          v32 = 0;
          v33 = 0;
          v20 = *v4;
          LODWORD(v27) = 3;
          LODWORD(v26) = v20;
          if ( (unsigned int)v5 > 2 )
LABEL_30:
            __break(0x5512u);
          v21 = *a1;
          HIDWORD(v29) = 1;
          HIDWORD(v28) = v21;
          HIDWORD(v27) = *(_QWORD *)&a1[6 * v5 + 20];
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_notify_error_on_link",
              635,
              "Failed for device: %s while applying request: %lld",
              a2 + 28);
          result = cam_req_mgr_notify_message(&v26, 1, 0x8000000);
          if ( (_DWORD)result )
          {
            v22 = result;
            if ( (unsigned int)__ratelimit(
                                 &_cam_req_mgr_notify_error_on_link__rs_235,
                                 "__cam_req_mgr_notify_error_on_link") )
              v23 = 3;
            else
              v23 = 2;
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       v23,
                       16,
                       1,
                       "__cam_req_mgr_notify_error_on_link",
                       644,
                       "Error in notifying recovery for session %d link 0x%x rc %d",
                       *v4,
                       *a1,
                       v22);
          }
        }
      }
      else
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   16,
                   1,
                   "__cam_req_mgr_notify_error_on_link",
                   600,
                   "min pd : %d is more than expected",
                   v7);
      }
    }
    else
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 16,
                 1,
                 "__cam_req_mgr_notify_error_on_link",
                 594,
                 "pd : %d is more than expected",
                 v5);
    }
  }
  else
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               16,
               2,
               "__cam_req_mgr_notify_error_on_link",
               588,
               "session ptr NULL %x",
               *a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
