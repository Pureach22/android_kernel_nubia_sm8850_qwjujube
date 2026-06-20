__int64 __fastcall dp_reset_rx_hw_ext_stats(__int64 result)
{
  *(_QWORD *)(result + 18568) = 0;
  return result;
}
