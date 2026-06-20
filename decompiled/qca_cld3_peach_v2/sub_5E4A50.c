__int64 sub_5E4A50()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return ucfg_ipa_is_two_tx_pipes_enabled();
}
