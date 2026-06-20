__int64 __fastcall tpg_1_3_set_xcfa_test(__int64 a1, int a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_3_set_xcfa_test",
    807,
    "set xcfa test prev : %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 40LL));
  *(_DWORD *)(*(_QWORD *)(a1 + 32) + 40LL) = a2;
  return 0;
}
