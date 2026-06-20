__int64 __fastcall sub_23A230(__int64 a1)
{
  char v1; // w24

  if ( (v1 & 1) != 0 )
    return wmi_print_rx_event_log();
  else
    return wmi_unified_vdev_set_custom_aggr_size_cmd_send(a1);
}
