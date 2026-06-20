__int64 __fastcall cam_tpg_shutdown(__int64 a1)
{
  if ( a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "cam_tpg_shutdown",
      16,
      "TPG[%d] shutdown cleanup.",
      *(_DWORD *)(a1 + 564));
    tpg_hw_reset(a1 + 4568);
    *(_DWORD *)(a1 + 4832) = 0;
  }
  return 0;
}
