__int64 __fastcall cam_icp_context_dump_active_request(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v10; // w21
  _QWORD *v12; // x27
  _QWORD *v13; // x26
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7

  if ( a1 && a2 )
  {
    if ( *(_BYTE *)(a2 + 57) == 1 )
    {
      if ( (unsigned int)cam_context_dump_pf_info_to_hw(a1, a2, 0, a4, a5, a6, a7, a8) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_context_dump_active_request",
          44,
          "[%s] Failed to check PID info",
          (const char *)a1);
      if ( *(_DWORD *)(a2 + 60) == 1 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_context_dump_active_request",
          48,
          "[%s] Client with the issue PID is not detected, stop dumping or notifying to the userspace, wait for the next "
          "handler to check",
          (const char *)a1);
      return 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        3,
        "cam_icp_context_dump_active_request",
        53,
        "[%s] iommu fault for icp ctx %d state %d",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 240));
      v12 = *(_QWORD **)(a1 + 128);
      if ( v12 == (_QWORD *)(a1 + 128) )
      {
        v10 = 0;
      }
      else
      {
        do
        {
          v13 = (_QWORD *)*v12;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            3,
            "cam_icp_context_dump_active_request",
            57,
            "[%s] ctx[%u]: Active req_id: %llu",
            (const char *)a1,
            *(_DWORD *)(a1 + 32),
            v12[3]);
          v10 = cam_context_dump_pf_info_to_hw(a1, a2, (__int64)(v12 + 16), v14, v15, v16, v17, v18);
          if ( v10 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_icp_context_dump_active_request",
              62,
              "[%s] ctx[%u]: Failed to dump pf info.ctx->state: %d",
              (const char *)a1,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 240));
          v12 = v13;
        }
        while ( v13 != (_QWORD *)(a1 + 128) );
      }
      if ( *(_BYTE *)(a2 + 48) == 1 )
      {
        v10 = cam_context_send_pf_evt(a1, (__int64 *)a2);
        if ( v10 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_context_dump_active_request",
            76,
            "[%s] ctx[%u]: Failed to notify PF event to userspace rc: %d",
            (const char *)a1,
            *(_DWORD *)(a1 + 32),
            v10);
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_context_dump_active_request",
      36,
      "Invalid ctx %pK or pf args %pK",
      (const void *)a1,
      (const void *)a2);
    return (unsigned int)-22;
  }
  return v10;
}
