__int64 __fastcall wma_get_temperature(__int64 *a1)
{
  unsigned int temperature; // w19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  temperature = wmi_unified_get_temperature(*a1);
  if ( temperature )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send set Mimo PS ret = %d",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wma_get_temperature",
      temperature);
  return temperature;
}
