__int64 __fastcall tpg_1_4_get_shdr_offset_num_batch(__int64 a1, _QWORD *a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_4_get_shdr_offset_num_batch",
    850,
    "get shdr_num_batch : %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 48LL));
  *a2 = *(int *)(*(_QWORD *)(a1 + 32) + 48LL);
  return 0;
}
