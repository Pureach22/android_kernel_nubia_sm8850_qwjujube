__int64 is_kernel_log_limit_disabled()
{
  return ((unsigned __int8)debug_policy >> 3) & 1;
}
