__int64 __fastcall dp_rx_mon_config_fcs_cap(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  bool v11; // w20

  v10 = *(_QWORD *)(a1 + 96456);
  if ( !*(_QWORD *)(v10 + 16) )
    return 11;
  v11 = a2 != 0;
  qdf_trace_msg(0x38u, 2u, "%s: mon_fcs_cap: %d ", a3, a4, a5, a6, a7, a8, a9, a10, "dp_rx_mon_config_fcs_cap", a2);
  *(_BYTE *)(v10 + 39318) = v11;
  return 0;
}
