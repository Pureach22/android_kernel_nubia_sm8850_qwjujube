__int64 sub_181420()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qdf_thread_should_stop();
}
