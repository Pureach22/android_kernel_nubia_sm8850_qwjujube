__int64 __fastcall cam_jpeg_context_dump_active_request(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x27
  _QWORD *v5; // x26
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int v11; // w21

  if ( a1 && a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      3,
      "cam_jpeg_context_dump_active_request",
      38,
      "iommu fault for jpeg ctx %d state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 240));
    v4 = *(_QWORD **)(a1 + 128);
    if ( v4 == (_QWORD *)(a1 + 128) )
    {
      v11 = 0;
    }
    else
    {
      do
      {
        v5 = (_QWORD *)*v4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          3,
          "cam_jpeg_context_dump_active_request",
          43,
          "Active req_id: %lld, ctx_id: %u",
          v4[3],
          *(_DWORD *)(a1 + 32));
        v11 = cam_context_dump_pf_info_to_hw(a1, a2, (__int64)(v4 + 16), v6, v7, v8, v9, v10);
        if ( v11 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            512,
            1,
            "cam_jpeg_context_dump_active_request",
            48,
            "Failed to dump pf info ctx_id: %u state: %d",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 240));
        v4 = v5;
      }
      while ( v5 != (_QWORD *)(a1 + 128) );
    }
    if ( *(_BYTE *)(a2 + 48) == 1 )
    {
      v11 = cam_context_send_pf_evt(a1, (__int64 *)a2);
      if ( v11 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_context_dump_active_request",
          56,
          "Failed to notify PF event to userspace rc: %d",
          v11);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_dump_active_request",
      33,
      "Invalid ctx %pK or pf args %pK",
      (const void *)a1,
      (const void *)a2);
    return (unsigned int)-22;
  }
  return v11;
}
