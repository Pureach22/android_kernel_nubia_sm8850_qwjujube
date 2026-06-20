__int64 __fastcall cam_icp_dump_debug_info(__int64 result, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 (__fastcall *v4)(__int64, __int64, int *, __int64); // x8
  __int64 v5; // x0
  const char *v6; // x5
  __int64 v7; // x6
  __int64 v8; // x4
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) == 0 )
  {
    v2 = *(_QWORD *)(result + 80);
    v3 = result;
    if ( !v2 )
    {
      v6 = "[%s] ICP device interface is NULL";
      v7 = result + 112;
      v8 = 208;
      goto LABEL_8;
    }
    v9 = 1;
    cam_icp_mgr_process_dbg_buf(result);
    cam_hfi_queue_dump(*(unsigned int *)(v3 + 156), 0);
    v4 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v2 + 88);
    v5 = *(_QWORD *)(v2 + 112);
    if ( *((_DWORD *)v4 - 1) != -1055839300 )
      __break(0x8228u);
    result = v4(v5, 15, &v9, 4);
    if ( (_DWORD)result )
    {
      v6 = "[%s] Fail to dump debug info";
      v7 = v3 + 112;
      v8 = 219;
LABEL_8:
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                 3,
                 256,
                 1,
                 "cam_icp_dump_debug_info",
                 v8,
                 v6,
                 v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
