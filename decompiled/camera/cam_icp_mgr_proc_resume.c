__int64 __fastcall cam_icp_mgr_proc_resume(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  const char *v4; // x7
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // x9
  __int64 v9; // x19

  v2 = *(_QWORD *)(a1 + 80);
  if ( v2 )
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      if ( (a2 & 1) != 0 )
        v4 = "Y";
      else
        v4 = "N";
      v6 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_proc_resume",
        4507,
        "%s use_proxy_boot_up:%s",
        (const char *)(a1 + 112),
        v4);
      a1 = v6;
      if ( (a2 & 1) != 0 )
        goto LABEL_5;
    }
    else if ( (a2 & 1) != 0 )
    {
LABEL_5:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_proc_resume",
        4517,
        "[%s] Failed in sending icp resume command to PVM rc %d",
        (const char *)(a1 + 112),
        -22);
      return 4294967274LL;
    }
    v7 = *(_QWORD *)(v2 + 112);
    v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v2 + 88);
    v9 = a1;
    if ( *((_DWORD *)v8 - 1) != -1055839300 )
      __break(0x8229u);
    result = v8(v7, 3, a1 + 44233, 1);
    if ( !(_DWORD)result )
      *(_BYTE *)(v9 + 44229) = 1;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_proc_resume",
      4502,
      "ICP device interface is NULL");
    return 4294967274LL;
  }
  return result;
}
