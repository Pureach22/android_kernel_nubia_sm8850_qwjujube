__int64 sub_6084()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return is_fastboot_enabled();
}
