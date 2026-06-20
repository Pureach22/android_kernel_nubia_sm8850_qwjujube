__int64 __fastcall sde_plane_add_data_to_minidump_va(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 1768);
  sde_mini_dump_add_va_region("sde_plane", 4504, a1);
  return sde_mini_dump_add_va_region("plane_state", 2952, v1);
}
