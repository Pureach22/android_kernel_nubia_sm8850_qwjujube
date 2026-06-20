__int64 __fastcall wma_set_tx_power_per_mcs(__int64 *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20

  if ( (unsigned int)_wma_validate_handle(a1, "wma_set_tx_power_per_mcs") )
    return 4;
  v12 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v12, (__int64)"wma_set_tx_power_per_mcs", v4, v5, v6, v7, v8, v9, v10, v11) )
    return 4;
  else
    return wmi_unified_send_tx_power_per_mcs_cmd(v12, a2);
}
