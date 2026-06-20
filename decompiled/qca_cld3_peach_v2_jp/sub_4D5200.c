__int64 sub_4D5200()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return dp_rx_is_sg_supported();
}
