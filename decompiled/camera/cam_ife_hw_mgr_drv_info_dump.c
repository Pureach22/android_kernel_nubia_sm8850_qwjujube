__int64 __fastcall cam_ife_hw_mgr_drv_info_dump(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x20
  int v7; // w6
  int v8; // w25
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // [xsp+40h] [xbp-30h] BYREF
  __int64 v12; // [xsp+48h] [xbp-28h]
  __int64 v13; // [xsp+50h] [xbp-20h]
  __int64 v14; // [xsp+58h] [xbp-18h]
  __int64 v15; // [xsp+60h] [xbp-10h]
  __int64 v16; // [xsp+68h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v11 = 0;
  v3 = ktime_get_with_offset(2);
  v4 = ns_to_timespec64(v3);
  v6 = v5;
  time64_to_tm(v4, 0, &v11);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_hw_mgr_drv_info_dump",
    1475,
    "time[%d-%d %d:%d:%d.%lld]: hw_mgr_ctx->applied_req_id = %lld wr_index:%d",
    v13 + 1,
    HIDWORD(v12),
    v12,
    HIDWORD(v11),
    v11,
    v6 / 1000000,
    *(_QWORD *)(a2 + 9304),
    *(unsigned __int8 *)(a2 + 9984));
  v7 = 0;
  do
  {
    v8 = v7 + 1;
    v9 = a2 + 9536 + 56LL * (((_BYTE)v7 + 1 + *(_BYTE *)(a2 + 9984)) & 7);
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_hw_mgr_drv_info_dump",
               1491,
               "Index[%d] Apply IFE Req[%llu]  frame_dur[%llu] blanking_dur[%llu] drv_timeout[%u] drv_en[%d], path_idle[0"
               "x%x], update_drv[%d], blob_valid[%d] mup_en[%d]",
               v7,
               *(_QWORD *)v9,
               *(_QWORD *)(v9 + 16),
               *(_QWORD *)(v9 + 24),
               *(_DWORD *)(v9 + 40),
               *(unsigned __int8 *)(v9 + 45),
               *(_DWORD *)(v9 + 8),
               *(unsigned __int8 *)(v9 + 44),
               *(unsigned __int8 *)(v9 + 46),
               *(unsigned __int8 *)(v9 + 48));
    v7 = v8;
  }
  while ( v8 != 8 );
  _ReadStatusReg(SP_EL0);
  return result;
}
