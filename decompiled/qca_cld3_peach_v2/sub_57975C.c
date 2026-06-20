__int64 sub_57975C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hal_rx_get_phy_ppdu_id_size_be();
}
