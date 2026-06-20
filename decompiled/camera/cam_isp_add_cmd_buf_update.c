__int64 __fastcall cam_isp_add_cmd_buf_update(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        const void *a5,
        unsigned int a6,
        __int64 a7,
        _DWORD *a8)
{
  __int64 v11; // x8
  _DWORD *v12; // x9
  __int64 result; // x0
  int v14; // w6
  __int64 v15; // x24
  __int64 v16; // [xsp+10h] [xbp-40h] BYREF
  __int64 v17; // [xsp+18h] [xbp-38h]
  const void *v18; // [xsp+20h] [xbp-30h]
  __int64 v19; // [xsp+28h] [xbp-28h]
  __int64 v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  __int64 v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v18 = a5;
  v17 = a4;
  v21 = a7;
  v22 = 0;
  v19 = a6;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v15 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_add_cmd_buf_update",
      289,
      "cmd_type %u cmd buffer 0x%pK, size %d",
      a4,
      a5,
      a6);
    a1 = v15;
  }
  v11 = *(_QWORD *)(a2 + 112);
  v12 = *(_DWORD **)(a2 + 88);
  v16 = a1;
  if ( *(v12 - 1) != -1055839300 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, __int64))v12)(v11, a4, &v16, 56);
  if ( (_DWORD)result )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_cmd_buf_update",
      299,
      "get buf cmd error:%d cmd %d",
      *(_DWORD *)(a2 + 4),
      v17);
    result = 4294967284LL;
  }
  else
  {
    v14 = HIDWORD(v19);
    *a8 = HIDWORD(v19);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_cmd_buf_update",
        306,
        "total_used_bytes %u",
        v14);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
