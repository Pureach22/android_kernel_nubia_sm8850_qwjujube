__int64 sub_4ECAE0()
{
  __asm { STTR            H13, [X17,#0xA9] }
  return wma_set_tx_power_scale_decr_db();
}
