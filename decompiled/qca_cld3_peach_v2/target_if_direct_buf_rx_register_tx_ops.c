_QWORD *__fastcall target_if_direct_buf_rx_register_tx_ops(_QWORD *result)
{
  result[220] = target_if_direct_buf_rx_module_register;
  result[221] = target_if_direct_buf_rx_module_unregister;
  result[222] = target_if_direct_buf_rx_register_events;
  result[223] = target_if_direct_buf_rx_unregister_events;
  result[224] = &target_if_direct_buf_rx_print_ring_stat;
  result[225] = target_if_direct_buf_rx_get_ring_params;
  return result;
}
