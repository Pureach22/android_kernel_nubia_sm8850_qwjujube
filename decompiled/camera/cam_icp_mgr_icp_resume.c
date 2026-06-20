__int64 __fastcall cam_icp_mgr_icp_resume(__int64 a1, _BYTE *a2)
{
  _QWORD *v2; // x21
  char v3; // w8
  _DWORD *v4; // x9
  _BYTE *v5; // x19
  __int64 v6; // x23
  __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w19
  __int64 result; // x0
  __int64 v11; // x19
  const char *v12; // x7
  const char *v13; // x6
  unsigned int v14; // w19
  _BYTE *v15; // x19
  __int64 v16; // x23
  unsigned int v17; // w0
  unsigned int v18; // w22
  _DWORD *v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w0
  _BYTE *v22; // x19
  __int64 v23; // x23
  _BYTE *v24; // x19
  __int64 v25; // x21
  _BYTE v26[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 80);
  if ( (debug_mdl & 0x100) == 0 || debug_priority )
  {
    if ( a2 )
      goto LABEL_4;
LABEL_33:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_icp_resume",
      5745,
      "resume_args can't be NULL");
    goto LABEL_34;
  }
  v22 = a2;
  v23 = a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100,
    4,
    "cam_icp_mgr_icp_resume",
    5742,
    "[%s] Enter",
    (const char *)(a1 + 112));
  a2 = v22;
  a1 = v23;
  if ( !v22 )
    goto LABEL_33;
LABEL_4:
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_icp_resume",
      5750,
      "[%s] ICP device interface is NULL",
      (const char *)(a1 + 112));
LABEL_34:
    result = 4294967274LL;
    goto LABEL_35;
  }
  if ( (*(_BYTE *)(a1 + 44228) & 1) != 0 )
  {
    v3 = a2[3];
    v26[0] = 1;
    if ( (v3 & 1) == 0 )
    {
      v4 = (_DWORD *)v2[2];
      v5 = a2;
      v6 = a1;
      v7 = v2[14];
      if ( *(v4 - 1) != 1989616049 )
        __break(0x8229u);
      v8 = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v4)(v7, v26, 1);
      a2 = v5;
      v9 = v8;
      a1 = v6;
      if ( v9 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_icp_resume",
          5770,
          "[%s] Failed to init ICP hw rc: %d",
          (const char *)(v6 + 112),
          v9);
        result = v9;
        goto LABEL_35;
      }
    }
    v15 = a2;
    v16 = a1;
    v17 = cam_icp_mgr_proc_resume();
    if ( v17 )
    {
      v18 = v17;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_icp_resume",
        5777,
        "[%s] Failed to resume proc rc: %d",
        v16 + 112);
LABEL_23:
      v19 = (_DWORD *)v2[3];
      v20 = v2[14];
      v26[0] = 0;
      if ( *(v19 - 1) != 1989616049 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _BYTE *, __int64))v19)(v20, v26, 1);
      result = v18;
      goto LABEL_35;
    }
    if ( v15[1] == 1 )
    {
      v21 = cam_hfi_resume(*(unsigned int *)(v16 + 156));
      if ( v21 )
      {
        v18 = v21;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_icp_resume",
          5785,
          "[%s] Failed to resume HFI rc: %d",
          v16 + 112);
        _power_collapse(v16, v15);
        goto LABEL_23;
      }
    }
    result = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_icp_resume",
        5790,
        "[%s] Exit",
        (const char *)(v16 + 112));
      result = 0;
    }
  }
  else
  {
    *a2 = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      v24 = a2;
      v25 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_icp_resume",
        5756,
        "[%s] booting ICP processor",
        (const char *)(a1 + 112));
      a2 = v24;
      a1 = v25;
    }
    v11 = a1;
    result = cam_icp_mgr_hw_open(a1, a2);
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      if ( (_DWORD)result )
        v12 = "failed";
      else
        v12 = "success";
      v13 = (const char *)(v11 + 112);
      v14 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_icp_resume",
        5759,
        "[%s] hw_open from kmd %s %d",
        v13,
        v12,
        result);
      result = v14;
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
