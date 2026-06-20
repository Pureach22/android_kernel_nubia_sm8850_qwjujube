__int64 sub_58BC7C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hal_tx_get_num_tcl_banks_peach();
}
