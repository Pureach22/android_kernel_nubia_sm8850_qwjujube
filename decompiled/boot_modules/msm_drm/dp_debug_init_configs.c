__int64 __fastcall dp_debug_init_configs(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  debugfs_create_ulong("connect_notification_delay_ms", 420, a2, a1 + 312);
  *(_QWORD *)(a1 + 312) = 150;
  result = debugfs_create_u32("disconnect_delay_ms", 420, a2, a1 + 320);
  *(_DWORD *)(a1 + 320) = 0;
  return result;
}
