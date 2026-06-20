__int64 __fastcall hdd_set_power_config_params(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  const char *v16; // x2
  __int64 result; // x0

  v6 = wma_set_power_config_ito(*(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL), a3);
  if ( v6 )
  {
    v15 = v6;
    v16 = "%s: failed to configure power ito: %d";
  }
  else
  {
    result = wma_set_power_config_spec_wake(*(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL), a4);
    if ( !(_DWORD)result )
      return result;
    v15 = (unsigned int)result;
    v16 = "%s: failed to configure power spec wake: %d";
  }
  qdf_trace_msg(0x33u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_power_config_params", v15);
  return 4294967274LL;
}
