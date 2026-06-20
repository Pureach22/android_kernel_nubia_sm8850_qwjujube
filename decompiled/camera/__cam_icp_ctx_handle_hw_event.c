__int64 __fastcall _cam_icp_ctx_handle_hw_event(unsigned int *a1, int a2, __int64 a3)
{
  __int64 result; // x0
  const char *v4; // x6
  const char *v5; // x7
  int v6; // w8
  unsigned int v8; // w10
  unsigned int v9; // w11
  __int64 v10; // x20
  int v11; // w23
  unsigned int v12; // w21
  __int64 v13; // [xsp+18h] [xbp-48h] BYREF
  int v14; // [xsp+20h] [xbp-40h]
  int v15; // [xsp+24h] [xbp-3Ch]
  __int64 v16; // [xsp+28h] [xbp-38h]
  __int64 v17; // [xsp+30h] [xbp-30h]
  __int64 v18; // [xsp+38h] [xbp-28h]
  __int64 v19; // [xsp+40h] [xbp-20h]
  __int64 v20; // [xsp+48h] [xbp-18h]
  __int64 v21; // [xsp+50h] [xbp-10h]
  __int64 v22; // [xsp+58h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    if ( a1 )
      v4 = "Non-NULL";
    else
      v4 = "NULL";
    if ( a3 )
      v5 = "Non-NULL";
    else
      v5 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_ctx_handle_hw_event",
      342,
      "Invalid ctx  %s and event data %s",
      v4,
      v5);
    goto LABEL_14;
  }
  if ( a2 == 2 )
  {
    result = cam_context_apply_evt_injection(a1, a3);
    goto LABEL_15;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      result = cam_context_buf_done_from_hw((__int64)a1, *(_QWORD *)a3, *(_DWORD *)(a3 + 8));
      goto LABEL_15;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_ctx_handle_hw_event",
      357,
      "Invalid event id: %u",
      a2);
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v6 = *(_DWORD *)(a3 + 8);
  v16 = 0;
  v17 = 0;
  v8 = a1[16];
  v9 = a1[14];
  v10 = *(_QWORD *)a3;
  LODWORD(v16) = a1[15];
  HIDWORD(v16) = v8;
  if ( v6 )
    v11 = (v6 == 1) << 11;
  else
    v11 = 1024;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v13 = v9;
  v14 = 3;
  v15 = v10;
  HIDWORD(v17) = v11;
  v12 = cam_req_mgr_notify_message(&v13, 1, 0x8000000);
  if ( v12 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_notify_v4l2_err_evt",
      298,
      "[%s] ctx[%u]: Error in notifying the error time for req id:%lld",
      (const char *)a1,
      a1[8],
      v10);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    3,
    "__cam_icp_notify_v4l2_err_evt",
    302,
    "[%s] ctx[%u]: notifying error to userspace err type: %d, err code: %u, req id: %llu",
    (const char *)a1,
    a1[8],
    3,
    v11,
    v10);
  result = v12;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
