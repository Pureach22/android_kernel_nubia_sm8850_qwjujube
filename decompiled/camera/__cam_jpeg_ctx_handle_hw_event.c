__int64 __fastcall _cam_jpeg_ctx_handle_hw_event(unsigned int *a1, int a2, __int64 a3)
{
  const char *v4; // x6
  const char *v5; // x7

  if ( a1 && a3 )
  {
    if ( a2 == 1 )
      return cam_context_apply_evt_injection(a1, a3);
    if ( !a2 )
      return cam_context_buf_done_from_hw((__int64)a1, *(_QWORD *)a3, *(_DWORD *)(a3 + 8));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_handle_hw_event",
      177,
      "Invalid event id: %u",
      a2);
  }
  else
  {
    if ( a1 )
      v4 = "Non-NULL";
    else
      v4 = "NULL";
    if ( a3 )
      v5 = "Non-NULL";
    else
      v5 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_handle_hw_event",
      165,
      "Invalid parameters ctx %s evt_data: %s",
      v4,
      v5);
  }
  return 4294967274LL;
}
