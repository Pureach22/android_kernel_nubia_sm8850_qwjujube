__int64 __fastcall _cam_req_mgr_apply_on_bubble(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w9
  int v4; // w9
  __int64 result; // x0
  _DWORD v6[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v7; // [xsp+8h] [xbp-38h]
  __int64 v8; // [xsp+10h] [xbp-30h]
  __int64 v9; // [xsp+18h] [xbp-28h]
  __int64 v10; // [xsp+20h] [xbp-20h]
  __int64 v11; // [xsp+28h] [xbp-18h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  v11 = 0;
  v12 = 0;
  v7 = v2;
  v8 = 0;
  v3 = *(_DWORD *)(a2 + 4);
  v6[0] = *(_DWORD *)a2;
  v6[1] = v3;
  v4 = *(_DWORD *)(a2 + 24);
  v9 = *(_QWORD *)(a2 + 32);
  v10 = 0;
  LODWORD(v8) = v4;
  result = _cam_req_mgr_process_req(a1, v6);
  if ( (_DWORD)result )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               16,
               1,
               "__cam_req_mgr_apply_on_bubble",
               3694,
               "Failed to apply request on bubbled frame");
  _ReadStatusReg(SP_EL0);
  return result;
}
