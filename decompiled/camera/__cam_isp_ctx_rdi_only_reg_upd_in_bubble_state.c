__int64 __fastcall _cam_isp_ctx_rdi_only_reg_upd_in_bubble_state(__int64 a1)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "__cam_isp_ctx_rdi_only_reg_upd_in_bubble_state",
    7402,
    "Received RUP for Bubble Request, ctx %u link: 0x%x",
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 128LL) + 24LL),
    *(_DWORD *)(*(_QWORD *)a1 + 32LL));
  return 0;
}
