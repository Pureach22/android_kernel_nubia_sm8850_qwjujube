__int64 is_fastboot_enabled()
{
  return ((unsigned __int8)debug_policy >> 2) & 1;
}
