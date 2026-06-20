__int64 __fastcall cam_ife_set_csid_debug(__int64 a1, __int64 a2)
{
  qword_3A84F8 = a2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_set_csid_debug",
    18564,
    "Set CSID Debug value :%lld",
    a2);
  return 0;
}
