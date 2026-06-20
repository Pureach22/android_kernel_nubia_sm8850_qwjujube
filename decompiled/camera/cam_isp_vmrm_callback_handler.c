__int64 __fastcall cam_isp_vmrm_callback_handler(__int64 a1, __int64 a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    2,
    "cam_isp_vmrm_callback_handler",
    107,
    "isp dev type %d msg type %d",
    *(_DWORD *)(a1 + 540),
    *(_DWORD *)(a2 + 8));
  return 0;
}
