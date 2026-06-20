void *qdf_clear_dp_pkt_add_ts_info()
{
  dp_pkt_add_timestamp = 0;
  return qdf_mem_set(&dp_pkt_ts_info, 0x24u, 0);
}
