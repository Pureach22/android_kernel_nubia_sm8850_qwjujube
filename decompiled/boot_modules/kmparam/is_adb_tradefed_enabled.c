__int64 is_adb_tradefed_enabled()
{
  return ((unsigned __int8)debug_policy >> 4) & 1;
}
