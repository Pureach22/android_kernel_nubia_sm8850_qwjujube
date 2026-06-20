__int64 __fastcall _cam_isp_ctx_notify_v4l2_error_event(unsigned int a1, int a2, __int64 a3, _DWORD *a4)
{
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  __int64 result; // x0
  __int64 v12; // [xsp+18h] [xbp-48h] BYREF
  unsigned __int64 v13; // [xsp+20h] [xbp-40h]
  unsigned __int64 v14; // [xsp+28h] [xbp-38h]
  __int64 v15; // [xsp+30h] [xbp-30h]
  __int64 v16; // [xsp+38h] [xbp-28h]
  __int64 v17; // [xsp+40h] [xbp-20h]
  __int64 v18; // [xsp+48h] [xbp-18h]
  __int64 v19; // [xsp+50h] [xbp-10h]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a4[14];
  v9 = a4[15];
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v12 = v8;
  v10 = a4[16];
  v18 = 0;
  v19 = 0;
  v14 = __PAIR64__(v10, v9);
  v16 = 0;
  v17 = 0;
  v13 = __PAIR64__(a3, a1);
  HIDWORD(v15) = a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_notify_v4l2_error_event",
      893,
      "v4l2 error event [type: %u code: %u] for req: %llu in ctx: %u on link: 0x%x notified successfully",
      a1,
      a2,
      a3,
      a4[8],
      v10);
  result = cam_req_mgr_notify_message(&v12, 1, 0x8000000);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "__cam_isp_ctx_notify_v4l2_error_event",
               901,
               "Notifying v4l2 error [type: %u code: %u] failed for req id:%llu in ctx %u on link: 0x%x",
               a1,
               a2,
               a3,
               a4[8],
               a4[16]);
  _ReadStatusReg(SP_EL0);
  return result;
}
