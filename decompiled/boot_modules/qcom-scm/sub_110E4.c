__int64 sub_110E4()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qtee_shmbridge_is_enabled();
}
