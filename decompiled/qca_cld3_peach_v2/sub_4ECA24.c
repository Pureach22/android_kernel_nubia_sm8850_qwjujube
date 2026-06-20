__int64 sub_4ECA24()
{
  __asm { STTR            H13, [X17,#0xA9] }
  return wma_set_tx_power_scale();
}
