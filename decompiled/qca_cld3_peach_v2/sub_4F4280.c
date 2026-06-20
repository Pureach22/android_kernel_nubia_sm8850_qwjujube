__int64 sub_4F4280()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wma_is_p2p_lo_capable();
}
