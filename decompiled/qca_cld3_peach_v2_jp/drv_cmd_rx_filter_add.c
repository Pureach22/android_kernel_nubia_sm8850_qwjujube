__int64 __fastcall drv_cmd_rx_filter_add(_QWORD *a1, __int64 a2, __int64 a3)
{
  return hdd_driver_rxfilter_command_handler(a3, *a1, 1);
}
