__int64 __fastcall cam_icp_mgr_process_dbg_buf(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int *v3; // x19
  unsigned __int64 v4; // x27
  unsigned int v5; // w26
  __int64 result; // x0
  unsigned int *v7; // x24
  int v8; // w8
  int v9; // w8
  bool v10; // cf
  unsigned int v11; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( a1 )
  {
    v2 = 0;
    v3 = (unsigned int *)(a1 + 3064);
    v4 = a1 + 44024;
    v5 = 10240;
    _ReadStatusReg(SP_EL0);
    do
    {
      result = hfi_read_message(*(unsigned int *)(a1 + 156), (char *)v3 + (v2 & 0xFFFFFFFC), 2, v5, &v11);
      if ( (_DWORD)result )
        break;
      v2 += 4 * v11;
      if ( v2 )
      {
        if ( v2 >> 13 > 4 || (unsigned __int64)v3 >= v4 )
        {
          v7 = v3;
LABEL_23:
          v8 = v7[1];
        }
        else
        {
          v7 = v3;
          while ( 1 )
          {
            v8 = v7[1];
            if ( v8 != 131075 )
              break;
            if ( v2 < *v7 )
            {
              result = (__int64)memcpy(v3, v7, v2);
              v9 = 10240 - (v2 >> 2);
              goto LABEL_19;
            }
            if ( !*(_QWORD *)(a1 + 44128) || (result = cam_presil_mode_enabled(result), (result & 1) != 0) )
              result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         256,
                         3,
                         "cam_icp_mgr_process_dbg_buf",
                         3469,
                         "[%s]: FW_DBG:%s",
                         (const char *)(a1 + 112),
                         (const char *)v7 + 24);
            v2 -= *v7;
            if ( !v2 )
              goto LABEL_17;
            v7 = (unsigned int *)((char *)v7 + (*v7 & 0xFFFFFFFC));
            if ( v2 >> 13 > 4 || (unsigned __int64)v7 >= v4 )
              goto LABEL_23;
          }
        }
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   256,
                   2,
                   "cam_icp_mgr_process_dbg_buf",
                   3443,
                   "Error message: remain_len:%u, dbg_buf:%p pkt_ptr:%p pkt_size:%u pkt_type:0x%x read_in_words:%d",
                   v2,
                   v3,
                   v7,
                   *v7,
                   v8,
                   v11);
        break;
      }
LABEL_17:
      v9 = 10240;
LABEL_19:
      v10 = v11 >= v5;
      v5 = v9;
    }
    while ( v10 );
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_process_dbg_buf",
               3416,
               "Invalid data");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
