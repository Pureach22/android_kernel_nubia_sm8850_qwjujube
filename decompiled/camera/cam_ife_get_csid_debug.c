__int64 __fastcall cam_ife_get_csid_debug(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x6

  v2 = qword_3A84F8;
  *a2 = qword_3A84F8;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_get_csid_debug",
    18572,
    "Get CSID Debug value :%lld",
    v2);
  return 0;
}
