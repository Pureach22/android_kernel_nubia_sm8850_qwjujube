__int64 __fastcall cam_icp_mgr_hw_close(__int64 a1, _BYTE *a2)
{
  __int64 v2; // x23
  _BYTE *v3; // x20
  __int64 v4; // x19
  unsigned int v5; // w8
  const char *v6; // x5
  __int64 v7; // x1
  __int64 v8; // x6
  __int64 v9; // x4
  _BYTE *v10; // x19
  __int64 v11; // x20

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_close",
      5386,
      "close args can't be NULL");
    return (unsigned int)-22;
  }
  v2 = a1 + 40960;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v10 = a2;
    v11 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_hw_close",
      5390,
      "[%s] Enter",
      (const char *)(a1 + 112));
    a2 = v10;
    a1 = v11;
    if ( (*(_BYTE *)(v2 + 3268) & 1) != 0 )
    {
LABEL_5:
      if ( *(_QWORD *)(a1 + 80) )
      {
        v3 = a2;
        v4 = a1;
        if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            3,
            "cam_icp_mgr_hw_close",
            5402,
            "PRESIL-ICP-B2B-HFI-INIT No Shutdown No Deinit No HFIfreeMem");
          return 0;
        }
        cam_icp_mgr_proc_shutdown(v4, v3[2], v3[3]);
        if ( v3[1] == 1 )
        {
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_mgr_hw_close",
              5411,
              "[%s] hw mgr is freeing hfi mem",
              (const char *)(v4 + 112));
          cam_hfi_deinit(*(unsigned int *)(v4 + 156));
          cam_icp_free_hfi_mem(v4);
          *(_BYTE *)(v2 + 3277) = 0;
        }
        *(_BYTE *)(v2 + 3268) = 0;
        v5 = 0;
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          v6 = "[%s] Exit";
          v7 = debug_mdl & 0x100;
          v8 = v4 + 112;
          v9 = 5419;
LABEL_26:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            v7,
            4,
            "cam_icp_mgr_hw_close",
            v9,
            v6,
            v8);
          return 0;
        }
      }
      else
      {
        v5 = -22;
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_hw_close",
            5397,
            "[%s] ICP device interface is NULL",
            (const char *)(a1 + 112));
          return (unsigned int)-22;
        }
      }
      return v5;
    }
  }
  else if ( (*(_BYTE *)(a1 + 44228) & 1) != 0 )
  {
    goto LABEL_5;
  }
  v5 = 0;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v6 = "[%s] hw mgr is already closed";
    v7 = debug_mdl & 0x100;
    v8 = a1 + 112;
    v9 = 5392;
    goto LABEL_26;
  }
  return v5;
}
