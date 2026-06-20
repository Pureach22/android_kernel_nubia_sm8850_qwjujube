__int64 __fastcall _cam_isp_ctx_issue_resume_util(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w20
  __int64 *v4; // x10
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64 *); // x8
  __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w20
  int v10; // w8
  unsigned int started; // w0
  __int64 v12; // x7
  unsigned int v13; // w8
  _QWORD v15[12]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v16; // [xsp+78h] [xbp-28h] BYREF
  __int64 v17; // [xsp+80h] [xbp-20h]
  _QWORD *v18; // [xsp+88h] [xbp-18h]
  int v19[2]; // [xsp+90h] [xbp-10h] BYREF
  __int64 v20; // [xsp+98h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v17 = 0;
  memset(v15, 0, sizeof(v15));
  raw_spin_lock_bh(a1 + 120);
  v3 = *(_DWORD *)(a1 + 240);
  raw_spin_unlock_bh(a1 + 120);
  if ( v3 == 4 )
  {
    v4 = *(__int64 **)(a1 + 208);
    v5 = *(_QWORD *)(v2 + 37296);
    LODWORD(v15[0]) = 2;
    LODWORD(v17) = 0;
    v16 = v5;
    v6 = (__int64 (__fastcall *)(__int64, __int64 *))v4[12];
    v18 = v15;
    v7 = *v4;
    if ( *((_DWORD *)v6 - 1) != 1863972096 )
      __break(0x8228u);
    v8 = v6(v7, &v16);
    if ( v8 )
    {
      v9 = v8;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_issue_resume_util",
        9217,
        "Failed to resume HW rc: %d, ctx_id %u link: 0x%x",
        v8,
        *(unsigned int *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
    }
    else
    {
      v10 = *(_DWORD *)(a1 + 60);
      v19[0] = *(_DWORD *)(a1 + 56);
      v19[1] = v10;
      started = _cam_isp_ctx_start_dev_in_ready((_DWORD *)a1, v19);
      v12 = *(unsigned int *)(a1 + 32);
      v13 = *(_DWORD *)(a1 + 64);
      v9 = started;
      if ( started )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_issue_resume_util",
          9227,
          "Failed to re-start HW after flush rc: %d, ctx_id %u link: 0x%x",
          started,
          v12,
          v13);
      else
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_issue_resume_util",
          9231,
          "Received init after flush. Re-start HW complete in ctx:%d, link: 0x%x",
          (unsigned int)v12,
          v13);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_issue_resume_util",
          9234,
          "next state %d sub_state:%d ctx_id %u link: 0x%x",
          *(unsigned int *)(a1 + 240),
          *(unsigned int *)(v2 + 20),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_issue_resume_util",
      9204,
      "Cannot perform a resume if not in flushed state ctx: %u link: 0x%x state: %u",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
    v9 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
