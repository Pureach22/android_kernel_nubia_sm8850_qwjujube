__int64 __fastcall _cam_isp_ctx_handle_secondary_events(__int64 a1, int *a2)
{
  _DWORD *v2; // x20
  __int64 v3; // x21
  __int64 v4; // x6
  __int64 v5; // x7
  int v6; // w8
  const char *v7; // x5
  __int64 v8; // x4
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x22
  __int64 v13; // x23
  unsigned __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w9
  __int64 v18; // x1
  int v19; // w9
  _DWORD *v20; // x20
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // x19
  int v24; // w8
  char v25; // w8
  int v26; // w11
  __int64 v27; // x8
  __int64 v28; // x10
  unsigned __int64 v29; // x8
  unsigned int v30; // w19
  int v31; // w22
  __int64 v32; // x2
  __int64 v33; // x19
  char v34; // w8
  _QWORD *v35; // x23
  _QWORD *v36; // x20
  __int64 v37; // x6
  __int64 v38; // x7
  __int64 v39; // x20
  __int64 v40; // x9
  __int64 v41; // x1
  int v42; // w10
  __int64 v43; // x23
  unsigned int v44; // w0
  int v45; // w7
  int v46; // w8
  unsigned int v47; // w19
  _QWORD *v48; // x8
  _QWORD *v49; // x8
  __int64 v50; // x9
  _QWORD *v51; // x2
  _QWORD *v52; // x19
  __int64 v53; // t1
  int v54; // [xsp+10h] [xbp-30h]

  v2 = *(_DWORD **)a1;
  v3 = a1 + 45232;
  if ( (*(_BYTE *)(a1 + 45748) & 1) == 0 )
  {
    v4 = (unsigned int)v2[8];
    v5 = (unsigned int)v2[16];
    v6 = *a2;
    v7 = "Recovery not supported for non-AEB ctx: %u on link: 0x%x reject sec evt: %u";
    v8 = 5409;
    goto LABEL_5;
  }
  if ( *(_DWORD *)(a1 + 45572) )
  {
    v4 = (unsigned int)v2[8];
    v5 = (unsigned int)v2[16];
    v6 = *a2;
    v7 = "Internal recovery in progress in ctx: %u on link: 0x%x reject sec evt: %u";
    v8 = 5416;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_handle_secondary_events",
      v8,
      v7,
      v4,
      v5,
      v6);
    return 0;
  }
  v10 = *a2;
  v11 = a1 + 37320;
  if ( *a2 == 2 )
  {
    v23 = a1;
    _cam_isp_ctx_update_state_monitor_array(a1, 10, *(_QWORD *)(a1 + 37352));
    if ( !*(_QWORD *)(v23 + 8) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_handle_secondary_events",
        5478,
        "Sensor sync [vc mismatch] frame dropped at stream on ctx: %u link: 0x%x frame_id: %u last_applied_req: %lld",
        v2[8],
        v2[16],
        0,
        *(_QWORD *)(v11 + 32));
      return 0xFFFFFFFFLL;
    }
    v26 = *(_DWORD *)(v11 + 64);
    v27 = *(_QWORD *)(v11 + 32);
    v28 = *(_QWORD *)(v11 + 40);
    *(_DWORD *)(v11 + 64) = v26 + 1;
    if ( !v26 && v28 == v27 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, __int64, int))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_secondary_events",
        5488,
        "Sensor sync [vc mismatch] frame dropped ctx: %u on link: 0x%x last_applied_req: %llu last_recovered_req: %llu ou"
        "t_of_sync_cnt: %u, recovery maybe in progress...",
        (unsigned int)v2[8],
        (unsigned int)v2[16],
        v27,
        v27,
        v26 + 1);
      return 0;
    }
    *(_DWORD *)(v11 + 64) = 0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_handle_secondary_events",
      5498,
      "Sensor sync [vc mismatch] frame dropped ctx: %u on link: 0x%x last_applied_req: %llu last_recovered_req: %llu out_"
      "of_sync_cnt: %u, kicking in internal recovery....",
      v2[8],
      v2[16],
      v27,
      v28,
      0);
    v25 = 1;
    goto LABEL_30;
  }
  if ( v10 == 1 )
  {
    v23 = a1;
    _cam_isp_ctx_update_state_monitor_array(a1, 9, *(_QWORD *)(a1 + 37352));
    v24 = *(_DWORD *)(v23 + 20);
    *(_DWORD *)(v11 + 64) = 0;
    if ( v24 != 4 )
    {
      result = 0;
      if ( v24 != 1 )
        return result;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_handle_secondary_events",
      5465,
      "Programming delay input frame dropped ctx: %u on link: 0x%x last_applied_req: %llu, kicking in internal recovery....",
      v2[8],
      v2[16],
      *(_QWORD *)(v11 + 32));
    v25 = 0;
LABEL_30:
    if ( (byte_3A8B8C & 1) != 0 )
      return 0;
    v32 = v23;
    v33 = *(_QWORD *)v23;
    v34 = v25 ^ 1;
    v35 = *(_QWORD **)(v33 + 160);
    if ( v35 != (_QWORD *)(v33 + 160) )
      v34 = 1;
    if ( (v34 & 1) != 0 )
    {
      if ( v35 != (_QWORD *)(v33 + 160) )
      {
LABEL_38:
        v37 = v35[3];
        v38 = *(_QWORD *)(v11 + 32);
        if ( v37 != v38 )
        {
          v39 = v32;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_trigger_internal_recovery",
            5356,
            "Top of wait list req: %llu does not match with last applied: %llu in ctx: %u on link: 0x%x",
            v37,
            v38,
            *(_DWORD *)(v33 + 32),
            *(_DWORD *)(v33 + 64));
          v32 = v39;
        }
        v36 = v35;
LABEL_41:
        v40 = v36[4];
        *(_DWORD *)(v3 + 340) = 1;
        *(_DWORD *)(v32 + 24) = 1;
        v41 = v36[3];
        v42 = *(_DWORD *)v11;
        *(_QWORD *)(v11 + 40) = v41;
        if ( v42 )
        {
          *(_BYTE *)(v40 + 4504) = 1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_trigger_internal_recovery",
            5374,
            "Active req cnt: %u wait for all buf dones before kicking in recovery on req: %lld ctx: %u on link: 0x%x",
            *(_DWORD *)v11,
            *(_QWORD *)(v11 + 40),
            *(_DWORD *)(v33 + 32),
            *(_DWORD *)(v33 + 64));
        }
        else
        {
          v43 = v32;
          v44 = _cam_isp_ctx_notify_error_util(7, v41, v32);
          if ( v44 )
          {
            v45 = *(_DWORD *)(v33 + 32);
            v46 = *(_DWORD *)(v33 + 64);
            v47 = v44;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "__cam_isp_ctx_trigger_internal_recovery",
              5382,
              "Unable to perform internal recovery [bubble reporting failed] for req: %llu in ctx: %u on link: 0x%x",
              *(_QWORD *)(v11 + 40),
              v45,
              v46);
            *(_DWORD *)(v3 + 340) = 0;
            *(_DWORD *)(v43 + 24) = 0;
            *(_QWORD *)(v11 + 56) = 0;
            *(_DWORD *)(v11 + 68) = 0;
            *(_BYTE *)(v3 + 514) = 0;
            return v47;
          }
          *(_DWORD *)(v43 + 20) = 3;
          v49 = (_QWORD *)v36[1];
          if ( (_QWORD *)*v49 == v36 && (v50 = *v36, *(_QWORD **)(*v36 + 8LL) == v36) )
          {
            *(_QWORD *)(v50 + 8) = v49;
            *v49 = v50;
          }
          else
          {
            _list_del_entry_valid_or_report(v36);
          }
          *v36 = v36;
          v36[1] = v36;
          v53 = *(_QWORD *)(v33 + 144);
          v52 = (_QWORD *)(v33 + 144);
          v51 = (_QWORD *)v53;
          if ( *(_QWORD **)(v53 + 8) == v52 && v36 != v52 && v36 != v51 )
          {
            v51[1] = v36;
            *v36 = v51;
            v36[1] = v52;
            *v52 = v36;
            return 0;
          }
          _list_add_valid_or_report(v36);
        }
        return 0;
      }
    }
    else
    {
      v36 = *(_QWORD **)(v33 + 144);
      if ( v36 != (_QWORD *)(v33 + 144) )
      {
        if ( v36 )
          goto LABEL_41;
        goto LABEL_38;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _QWORD, int))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_trigger_internal_recovery",
      5346,
      "No request to perform recovery - ctx: %u on link: 0x%x last_applied: %lld last_buf_done: %lld",
      *(unsigned int *)(v33 + 32),
      *(unsigned int *)(v33 + 64),
      *(_QWORD *)(v11 + 32),
      *(_QWORD *)(v11 + 72),
      v54);
    return 0;
  }
  if ( v10 )
    return 0;
  _cam_isp_ctx_update_state_monitor_array(a1, 8, *(_QWORD *)(a1 + 37352));
  v13 = a1 + 45240;
  v14 = a1 + 45240 + ((*(_QWORD *)v3 % 5uLL) << 6);
  v15 = ktime_get_with_offset(1);
  v16 = ns_to_timespec64(v15);
  v17 = *(_DWORD *)(a1 + 20);
  *(_QWORD *)(v14 + 48) = v16;
  *(_QWORD *)(v14 + 56) = v18;
  if ( v17 != 4 && v17 != 1 )
  {
    *(_DWORD *)(v11 + 60) = 0;
    return 0;
  }
  v19 = *(_DWORD *)(v11 + 60);
  v20 = *(_DWORD **)a1;
  *(_DWORD *)(v11 + 60) = v19 + 1;
  v21 = (unsigned int)v20[8];
  v22 = (unsigned int)v20[16];
  if ( (unsigned int)(v19 + 1) <= 6 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD, int))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_notify_aeb_error_for_sec_event",
      5288,
      "AEB slave RDI's current request's SOF seen after next req is applied for ctx: %u on link: 0x%x last_applied_req: %llu err_cnt: %u",
      v21,
      v22,
      *(_QWORD *)(v11 + 32),
      v19 + 1);
    return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "__cam_isp_ctx_notify_aeb_error_for_sec_event",
    5294,
    "Fatal - AEB slave RDI's current request's SOF seen after next req is applied, EPOCH height need to be re-configured "
    "for ctx: %u on link: 0x%x err_cnt: %u",
    v21,
    v22,
    v19 + 1);
  if ( (*(_BYTE *)(v3 + 505) & 1) == 0 )
    _cam_isp_ctx_pause_crm_timer(v20);
  _cam_isp_ctx_trigger_reg_dump(3u, (__int64)v20, 0);
  _cam_isp_ctx_notify_error_util(2, *(_QWORD *)(v11 + 32), a1);
  _cam_isp_ctx_notify_v4l2_error_event(3u, 256, *(_QWORD *)(v11 + 32), v20);
  *(_DWORD *)(a1 + 20) = 6;
  v29 = *(_QWORD *)v3;
  if ( (*(_QWORD *)v3 & 0x8000000000000000LL) != 0 )
    return 0;
  if ( v29 > 4 )
  {
    v31 = 5;
    v30 = (v29 + 1) % 5;
  }
  else
  {
    v30 = 0;
    v31 = v29 + 1;
  }
  do
  {
    v48 = (_QWORD *)(v13 + ((unsigned __int64)v30 << 6));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_dump_frame_timing_record",
      614,
      "Index: %u SOF_TS: %llu.%llu EPOCH_TS: %llu.%llu EOF_TS: %llu.%llu SEC_SOF: %llu.%llu",
      v30,
      *v48,
      v48[1] / 1000LL,
      v48[4],
      v48[5] / 1000LL,
      v48[2],
      v48[3] / 1000LL,
      v48[6],
      v48[7] / 1000LL);
    result = 0;
    if ( v30 + 1 < 5 )
      ++v30;
    else
      v30 -= 4;
    --v31;
  }
  while ( v31 );
  return result;
}
