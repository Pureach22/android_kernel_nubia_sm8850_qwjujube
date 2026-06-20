__int64 __fastcall cam_ife_mgr_cmd_get_sof_timestamp(__int64 a1, __int64 *a2, _QWORD *a3, _QWORD *a4, char a5)
{
  char v7; // w21
  bool v8; // w22
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 (__fastcall *v12)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v13; // x11
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 (__fastcall *v21)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v22; // x11
  __int64 v23; // x0
  unsigned int v24; // w21
  __int64 v25; // x7
  __int64 v26; // x0
  __int64 v27; // [xsp+0h] [xbp-30h] BYREF
  __int64 v28; // [xsp+8h] [xbp-28h]
  __int64 v29; // [xsp+10h] [xbp-20h]
  __int64 v30; // [xsp+18h] [xbp-18h]
  __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v7 = a5 & 1;
  v8 = a4 != nullptr;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 208);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v10 = *(_QWORD *)(v9 + 32);
  v27 = 0;
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 16);
    v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v11 + 88);
    if ( !v12 )
    {
      result = 4294967274LL;
      v19 = *(_QWORD *)(v9 + 40);
      if ( !v19 )
        goto LABEL_15;
      goto LABEL_11;
    }
    v13 = *a2;
    v14 = *(_QWORD *)(v11 + 112);
    LOBYTE(v31) = a4 != nullptr;
    BYTE1(v31) = a5 & 1;
    v27 = v10;
    v28 = v13;
    if ( *((_DWORD *)v12 - 1) != -1055839300 )
      __break(0x8229u);
    result = v12(v14, 45, &v27, 40);
    if ( !(_DWORD)result )
    {
      v18 = v29;
      result = 0;
      *a2 = v28;
      *a3 = v18;
      if ( a4 )
      {
        *a4 = v30;
        v19 = *(_QWORD *)(v9 + 40);
        if ( !v19 )
          goto LABEL_15;
        goto LABEL_11;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  v19 = *(_QWORD *)(v9 + 40);
  if ( !v19 )
    goto LABEL_15;
LABEL_11:
  v20 = *(_QWORD *)(v19 + 16);
  v21 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v20 + 88);
  if ( v21 )
  {
    v22 = *a2;
    v23 = *(_QWORD *)(v20 + 112);
    LOBYTE(v31) = v8;
    BYTE1(v31) = v7;
    v27 = v19;
    v28 = v22;
    if ( *((_DWORD *)v21 - 1) != -1055839300 )
      __break(0x8228u);
    result = v21(v23, 45, &v27, 40);
  }
LABEL_15:
  if ( (_DWORD)result )
  {
    v24 = result;
    if ( (unsigned int)__ratelimit(&cam_ife_mgr_cmd_get_sof_timestamp__rs, "cam_ife_mgr_cmd_get_sof_timestamp") )
      v26 = 3;
    else
      v26 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
      v26,
      8,
      1,
      "cam_ife_mgr_cmd_get_sof_timestamp",
      print_fmt_cam_log_event,
      "Getting sof time stamp failed, ctx_idx: %u",
      (const char *)*(unsigned int *)(a1 + 56),
      v25,
      v27);
    result = v24;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
