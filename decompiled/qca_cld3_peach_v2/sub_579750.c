__int64 sub_579750()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hal_rx_en_mcast_fp_data_filter_generic_be();
}
