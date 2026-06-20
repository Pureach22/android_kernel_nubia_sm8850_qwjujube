__int64 __fastcall cam_isp_validate_scratch_buffer_blob(unsigned int a1, __int64 a2, int *a3)
{
  int v3; // w6

  if ( (*(_BYTE *)(a2 + 9388) & 1) != 0 || (*(_BYTE *)(a2 + 9387) & 1) != 0 )
  {
    if ( a1 > 0x37 )
    {
      v3 = *a3;
      if ( (unsigned int)(*a3 - 6) > 0xFFFFFFFA )
      {
        if ( 48 * (unsigned __int64)(unsigned int)(v3 - 1) + 56 <= a1 )
          return 0;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_validate_scratch_buffer_blob",
          12516,
          "Invalid blob size: %u expected: %lu ctx_idx: %u",
          a1);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_validate_scratch_buffer_blob",
          12489,
          "Invalid num_ports %u in scratch buf config, ctx_idx: %u",
          v3,
          *(_DWORD *)(a2 + 56));
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_validate_scratch_buffer_blob",
        12480,
        "Invalid blob size %u, ctx_idx: %u",
        a1,
        *(_DWORD *)(a2 + 56));
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_validate_scratch_buffer_blob",
      12473,
      "Not SFE sHDR/FS context: %u scratch buf blob not supported, ctx_idx: %u",
      *(_DWORD *)(a2 + 56),
      *(_DWORD *)(a2 + 56));
  }
  return 4294967274LL;
}
