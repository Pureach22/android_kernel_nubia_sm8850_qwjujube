__int64 __fastcall _cam_isp_ctx_notify_error_util(int a1, __int64 a2, __int64 *a3)
{
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w9
  int v9; // w11
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 result; // x0
  int v12; // w8
  int v13; // w9
  unsigned int v14; // w21
  _DWORD v15[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v16; // [xsp+20h] [xbp-30h]
  __int64 v17; // [xsp+28h] [xbp-28h]
  __int64 v18; // [xsp+30h] [xbp-20h]
  __int64 v19; // [xsp+38h] [xbp-18h]
  __int64 v20; // [xsp+40h] [xbp-10h]
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a3[4663];
  v7 = *a3;
  v6 = a3[1];
  v20 = 0;
  v19 = v5;
  v18 = 1;
  v9 = *(_DWORD *)(v7 + 60);
  v8 = *(_DWORD *)(v7 + 64);
  LODWORD(v20) = a1;
  v16 = a2;
  v17 = v6;
  v15[0] = v8;
  v15[1] = v9;
  if ( a1 == 7 || a1 == 1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_notify_error_util",
      925,
      "Notify CRM about bubble req: %llu frame: %llu in ctx: %u on link: 0x%x",
      a2,
      v6,
      *(_DWORD *)(v7 + 32),
      v8);
  else
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_notify_error_util",
      929,
      "Notify CRM about fatal error: %u req: %llu frame: %llu in ctx: %u on link: 0x%x",
      a1,
      a2,
      v6,
      *(_DWORD *)(v7 + 32),
      v8);
  v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v7 + 216) + 8LL);
  if ( *((_DWORD *)v10 - 1) != -472843750 )
    __break(0x8228u);
  result = v10(v15);
  if ( (_DWORD)result )
  {
    v12 = *(_DWORD *)(v7 + 32);
    v13 = *(_DWORD *)(v7 + 64);
    v14 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_notify_error_util",
      935,
      "Failed to notify error: %u for req: %lu on ctx: %u in link: 0x%x",
      a1,
      a2,
      v12,
      v13);
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
