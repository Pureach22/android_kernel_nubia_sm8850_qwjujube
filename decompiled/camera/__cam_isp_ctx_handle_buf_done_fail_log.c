__int64 __fastcall _cam_isp_ctx_handle_buf_done_fail_log(_DWORD *a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w6
  unsigned int v4; // w7
  _DWORD *v6; // x25
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  unsigned int v11; // w8
  int v12; // w9
  __int64 v13; // x19
  unsigned int *v14; // x9
  int v15; // w8
  __int64 v16; // x0
  const char *v17; // x26
  __int64 v18; // x0
  unsigned int v19; // w8
  __int64 v20; // x19
  __int64 v21; // x9
  __int64 *v22; // x10
  _DWORD *v23; // x8
  __int64 v24; // x0
  _QWORD *v25; // [xsp+28h] [xbp-98h]
  _QWORD v27[2]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v28; // [xsp+48h] [xbp-78h]
  __int64 v29; // [xsp+50h] [xbp-70h]
  __int64 v30; // [xsp+58h] [xbp-68h]
  __int64 v31; // [xsp+60h] [xbp-60h]
  __int64 v32; // [xsp+68h] [xbp-58h]
  __int64 v33; // [xsp+70h] [xbp-50h]
  __int64 v34; // [xsp+78h] [xbp-48h]
  __int64 v35; // [xsp+80h] [xbp-40h]
  __int64 v36; // [xsp+88h] [xbp-38h]
  __int64 v37; // [xsp+90h] [xbp-30h]
  _QWORD v38[5]; // [xsp+98h] [xbp-28h] BYREF

  v38[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a3 + 32);
  v4 = *(_DWORD *)(*(_QWORD *)a1 + 476LL);
  if ( v3 >= v4 )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               1,
               "__cam_isp_ctx_handle_buf_done_fail_log",
               1859,
               "Num Resources exceed mMAX %d >= %d",
               v3,
               v4);
  }
  else
  {
    v25 = *(_QWORD **)a1;
    v6 = a1 + 11395;
    if ( (unsigned int)__ratelimit(&_cam_isp_ctx_handle_buf_done_fail_log__rs, "__cam_isp_ctx_handle_buf_done_fail_log") )
      v8 = 3;
    else
      v8 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v8,
      8,
      2,
      "__cam_isp_ctx_handle_buf_done_fail_log",
      1866,
      "Prev Req[%lld] : num_out=%d, num_acked=%d, bubble : report=%d, detected=%d",
      a2,
      *(_DWORD *)(a3 + 32),
      *(_DWORD *)(a3 + 52),
      *(_DWORD *)(a3 + 72),
      *(unsigned __int8 *)(a3 + 4504));
    if ( (unsigned int)__ratelimit(
                         &_cam_isp_ctx_handle_buf_done_fail_log__rs_44,
                         "__cam_isp_ctx_handle_buf_done_fail_log") )
      v9 = 3;
    else
      v9 = 2;
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               v9,
               8,
               2,
               "__cam_isp_ctx_handle_buf_done_fail_log",
               1868,
               "Resource Handles that fail to generate buf_done in prev frame");
    v11 = *(_DWORD *)(a3 + 32);
    if ( v11 )
    {
      v12 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v13 = v12;
        v14 = (unsigned int *)(*(_QWORD *)(a3 + 24) + ((__int64)v12 << 6));
        if ( v14[4] != -1 )
          break;
LABEL_10:
        v12 = v13 + 1;
        if ( (int)v13 + 1 >= v11 )
          goto LABEL_23;
      }
      v15 = *v6;
      v16 = *v14;
      if ( *v6 == 65555 )
        goto LABEL_15;
      if ( v15 == 65552 )
      {
        v17 = "Invalid_Resource_Type";
        if ( (unsigned int)(v16 - 1) <= 0xE )
          v17 = off_4517A8[(unsigned int)(v16 - 1)];
        goto LABEL_16;
      }
      v17 = "INVALID_DEV_TYPE";
      if ( v15 == 65538 )
LABEL_15:
        v17 = (const char *)_cam_isp_ife_sfe_resource_handle_id_to_type(v16);
LABEL_16:
      if ( (unsigned int)__ratelimit(
                           &_cam_isp_ctx_handle_buf_done_fail_log__rs_47,
                           "__cam_isp_ctx_handle_buf_done_fail_log") )
        v18 = 3;
      else
        v18 = 2;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 v18,
                 8,
                 2,
                 "__cam_isp_ctx_handle_buf_done_fail_log",
                 1882,
                 "Resource_Handle: [%s][0x%x] Sync_ID: [0x%x]",
                 v17,
                 *(_DWORD *)(*(_QWORD *)(a3 + 24) + (v13 << 6)),
                 *(_DWORD *)(*(_QWORD *)(a3 + 24) + (v13 << 6) + 16));
      v11 = *(_DWORD *)(a3 + 32);
      goto LABEL_10;
    }
LABEL_23:
    v19 = a1[9347] + 1;
    a1[9347] = v19;
    if ( v19 >= 3 && (*((_BYTE *)v6 + 166) & 1) == 0 )
    {
      v38[1] = 0;
      v36 = 0;
      v37 = 0;
      v20 = v25[32];
      v34 = 0;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v28 = 0;
      v29 = 0;
      v27[0] = 0;
      v27[1] = 0;
      _cam_isp_ctx_print_event_record(v20);
      v21 = v25[33];
      LODWORD(v27[0]) = 3;
      v22 = (__int64 *)v25[26];
      LODWORD(v28) = 1;
      v38[0] = v21;
      v38[2] = v27;
      v23 = (_DWORD *)v22[12];
      v24 = *v22;
      if ( *(v23 - 1) != 1863972096 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *))v23)(v24, v38);
      *(_BYTE *)(v20 + 45746) = 1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
