__int64 __fastcall _cam_isp_ctx_try_internal_recovery_for_bubble(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x6
  __int64 result; // x0

  if ( (byte_3A8B8C & 4) != 0 )
    return 0;
  v2 = *(_QWORD *)(a2 + 256);
  if ( !*(_DWORD *)(v2 + 24) )
    return 0;
  v4 = *(_QWORD *)(v2 + 37352);
  if ( v4 >= a1 )
  {
    if ( (unsigned int)_cam_isp_ctx_validate_for_req_reapply_util(*(_QWORD *)(a2 + 256)) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_try_internal_recovery_for_bubble",
        10024,
        "Internal recovery not possible for ctx: %u on link: 0x%x req: %lld [last_applied: %lld]",
        *(_DWORD *)(a2 + 32),
        *(_DWORD *)(a2 + 64),
        a1,
        *(_QWORD *)(v2 + 37352));
      return 0;
    }
    else
    {
      *(_DWORD *)(v2 + 45572) = 1;
      if ( (unsigned int)_cam_isp_ctx_reset_and_recover(a2) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_try_internal_recovery_for_bubble",
          10034,
          "Internal recovery failed in ctx: %u on link: 0x%x req: %lld [last_applied: %lld]",
          *(_DWORD *)(a2 + 32),
          *(_DWORD *)(a2 + 64),
          a1,
          *(_QWORD *)(v2 + 37352));
        *(_DWORD *)(v2 + 45572) = 0;
        return 0;
      }
      else
      {
        result = 1;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_try_internal_recovery_for_bubble",
            10041,
            "Internal recovery done in ctx: %u on link: 0x%x req: %lld [last_applied: %lld]",
            *(_DWORD *)(a2 + 32),
            *(_DWORD *)(a2 + 64),
            a1,
            *(_QWORD *)(v2 + 37352));
          return 1;
        }
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_try_internal_recovery_for_bubble",
      10017,
      "Skip trying for internal recovery last applied: %lld error_req: %lld for ctx: %u on link: 0x%x",
      v4,
      a1,
      *(_DWORD *)(a2 + 32),
      *(_DWORD *)(a2 + 64));
    return 0;
  }
  return result;
}
