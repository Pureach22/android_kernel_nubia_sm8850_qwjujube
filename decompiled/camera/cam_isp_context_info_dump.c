__int64 __fastcall cam_isp_context_info_dump(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  if ( (_DWORD)a2 == 1 )
  {
    cam_context_dump_hw_acq_info(a1, a2, a3, a4, a5, a6, a7, a8);
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_context_info_dump",
      804,
      "DUMP id not valid %u, ctx_idx: %u, link: 0x%x",
      a2,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  return 0;
}
