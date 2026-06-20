__int64 __fastcall wma_update_num_tdls_vdevs_if_11be_mlo(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_tdls_is_fw_11be_mlo_capable();
  if ( (result & 1) != 0 )
  {
    *(_DWORD *)(a2 + 180) = 2;
    return qdf_trace_msg(
             0x36u,
             8u,
             "%s: update tdls num vdevs %d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wma_update_num_tdls_vdevs_if_11be_mlo",
             2);
  }
  return result;
}
