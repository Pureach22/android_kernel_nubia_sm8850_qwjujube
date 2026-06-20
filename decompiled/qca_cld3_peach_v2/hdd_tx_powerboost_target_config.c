__int64 __fastcall hdd_tx_powerboost_target_config(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  char v12; // w8

  if ( *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)a1) + 4020) == 1 )
    v12 = *(_BYTE *)(a2 + 872);
  else
    v12 = 0;
  *(_BYTE *)(a1 + 8496) = v12 & 1;
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: TPB Enable: %d (Host: %d FW: %d)",
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "hdd_tx_powerboost_target_config");
}
