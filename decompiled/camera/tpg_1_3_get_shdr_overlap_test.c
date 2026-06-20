__int64 __fastcall tpg_1_3_get_shdr_overlap_test(__int64 a1, _QWORD *a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_3_get_shdr_overlap_test",
    773,
    "get shdr test : %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 44LL));
  *a2 = *(int *)(*(_QWORD *)(a1 + 32) + 44LL);
  return 0;
}
