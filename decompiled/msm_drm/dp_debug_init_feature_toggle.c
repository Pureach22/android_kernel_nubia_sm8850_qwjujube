__int64 __fastcall dp_debug_init_feature_toggle(__int64 a1, __int64 a2)
{
  debugfs_create_bool("ssc_enable", 420, a2, *(_QWORD *)(a1 + 360) + 32LL);
  return debugfs_create_bool("widebus_mode", 420, a2, *(_QWORD *)(a1 + 344) + 730LL);
}
