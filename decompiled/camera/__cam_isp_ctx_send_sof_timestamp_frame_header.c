__int64 __fastcall _cam_isp_ctx_send_sof_timestamp_frame_header(__int64 *a1, unsigned int *a2, __int64 a3)
{
  unsigned __int64 v4; // x8
  unsigned int v5; // w9
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x8
  __int64 v8; // x7
  __int64 v9; // x11
  unsigned __int64 v10; // x8
  int v11; // w10
  __int64 result; // x0
  __int64 v13[4]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v14; // [xsp+38h] [xbp-28h]
  __int64 v15; // [xsp+40h] [xbp-20h]
  __int64 v16; // [xsp+48h] [xbp-18h]
  __int64 v17; // [xsp+50h] [xbp-10h]
  __int64 v18; // [xsp+58h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a2;
  v4 = a2[1];
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v13[0] = 0;
  v13[1] = a3;
  v6 = 10000LL * (unsigned int)(__PAIR64__(v4, v5) >> 8);
  v7 = HIDWORD(v6) + 10000LL * (unsigned int)(v4 >> 8);
  v9 = *a1;
  v8 = a1[1];
  v10 = ((v7 / 0xC0) << 32)
      | (unsigned int)((unsigned __int64)((((unsigned int)v6 & 0xFFFFFFC0 | ((v7 % 0xC0) << 32))
                                         * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
  a1[4663] = v10;
  v11 = *(_DWORD *)(v9 + 56);
  LODWORD(v9) = *(_DWORD *)(v9 + 64);
  v13[2] = v8;
  v13[3] = v10;
  LODWORD(v13[0]) = v11;
  LODWORD(v14) = v9;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_send_sof_timestamp_frame_header",
      1774,
      "request id:%lld frame number:%lld SOF time stamp:0x%llx status:%u",
      a3,
      v8,
      v10,
      0);
  result = cam_req_mgr_notify_message(v13, 0, 0x8000000);
  if ( (_DWORD)result )
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "__cam_isp_ctx_send_sof_timestamp_frame_header",
               1780,
               "Error in notifying the sof time for req id:%lld",
               a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
