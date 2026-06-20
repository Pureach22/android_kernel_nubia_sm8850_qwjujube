__int64 sub_5D8858()
{
  __asm { PRFM            #0xC, unk_6BF6D4 }
  return hal_rx_flow_get_tuple_info();
}
