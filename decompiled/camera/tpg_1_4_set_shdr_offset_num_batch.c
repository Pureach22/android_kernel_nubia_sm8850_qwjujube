__int64 __fastcall tpg_1_4_set_shdr_offset_num_batch(__int64 a1, int a2)
{
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    3,
    "tpg_1_4_set_shdr_offset_num_batch",
    892,
    "set shdr_num_batch : %d",
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 48LL));
  *(_DWORD *)(*(_QWORD *)(a1 + 32) + 48LL) = a2;
  return 0;
}
