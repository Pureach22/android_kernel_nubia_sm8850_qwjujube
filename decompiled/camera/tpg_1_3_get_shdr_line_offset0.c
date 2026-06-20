__int64 __fastcall tpg_1_3_get_shdr_line_offset0(__int64 a1, _QWORD *a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_3_get_shdr_line_offset0",
    789,
    "get shdr_offset0 : %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 52LL));
  *a2 = *(int *)(*(_QWORD *)(a1 + 32) + 52LL);
  return 0;
}
