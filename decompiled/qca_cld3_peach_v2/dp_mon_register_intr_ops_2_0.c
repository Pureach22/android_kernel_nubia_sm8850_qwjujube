__int64 __fastcall dp_mon_register_intr_ops_2_0(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 20112);
  *(_QWORD *)(*(_QWORD *)(v1 + 416) + 912LL) = dp_rx_mon_refill_buf_ring_2_0;
  *(_QWORD *)(*(_QWORD *)(v1 + 416) + 920LL) = 0;
  *(_QWORD *)(v1 + 432) = dp_rx_mon_process_2_0;
  return result;
}
