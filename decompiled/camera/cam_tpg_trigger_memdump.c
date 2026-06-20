__int64 __fastcall cam_tpg_trigger_memdump(__int64 a1)
{
  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "cam_tpg_trigger_memdump",
             81,
             "Invalid tpg device handle");
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "cam_tpg_trigger_memdump",
    86,
    "TPG[%d] Full memory dump triggered",
    *(_DWORD *)(*(_QWORD *)(a1 + 4608) + 20LL));
  return cam_tpg_mem_dmp(*(_QWORD *)(a1 + 4608), 1);
}
