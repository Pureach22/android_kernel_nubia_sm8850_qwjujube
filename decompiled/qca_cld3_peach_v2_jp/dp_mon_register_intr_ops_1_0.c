__int64 __fastcall dp_mon_register_intr_ops_1_0(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 20056) + 432LL) = dp_rx_mon_process_1_0;
  return result;
}
