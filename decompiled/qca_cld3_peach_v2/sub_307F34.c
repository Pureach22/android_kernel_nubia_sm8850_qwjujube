__int64 sub_307F34()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_fatal_event_enabled();
}
