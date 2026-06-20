__int64 sub_605C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return is_kernel_log_driver_enabled();
}
