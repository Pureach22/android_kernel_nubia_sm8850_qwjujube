__int64 __fastcall cam_ife_set_csid_testbus_debug(__int64 a1, __int64 a2)
{
  dword_3A851C = a2;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_set_csid_testbus_debug",
    19163,
    "Set CSID test bus value :%lld",
    a2);
  return 0;
}
