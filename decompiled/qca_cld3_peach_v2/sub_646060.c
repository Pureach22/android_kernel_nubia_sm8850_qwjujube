__int64 sub_646060()
{
  __asm { PRFM            #0xC, loc_72CEDC }
  return hal_rx_flow_get_tuple_info();
}
