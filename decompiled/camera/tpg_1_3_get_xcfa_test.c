__int64 __fastcall tpg_1_3_get_xcfa_test(__int64 a1, _QWORD *a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_3_get_xcfa_test",
    765,
    "get xcfa test %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 40LL));
  *a2 = *(int *)(*(_QWORD *)(a1 + 32) + 40LL);
  return 0;
}
