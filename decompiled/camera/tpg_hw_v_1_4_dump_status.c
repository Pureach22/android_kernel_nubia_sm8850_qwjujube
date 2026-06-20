__int64 __fastcall tpg_hw_v_1_4_dump_status(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 32)) != 0 && *(_QWORD *)(v1 + 24) )
  {
    result = 0;
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "tpg_hw_v_1_4_dump_status",
        816,
        "TPG V1.4 HWL status dump");
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_v_1_4_dump_status",
      812,
      "invalid params");
    return 4294967274LL;
  }
  return result;
}
