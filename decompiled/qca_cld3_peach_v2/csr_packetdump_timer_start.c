__int64 __fastcall csr_packetdump_timer_start(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  __int64 v19; // x4

  result = (__int64)_cds_get_context(52, (__int64)"csr_packetdump_timer_start", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    v9 = result;
    if ( (unsigned int)qdf_mc_timer_get_current_state(result + 17304) == 20 )
    {
      v18 = "%s: packetdump_timer is already started: %d";
      v19 = 20;
    }
    else
    {
      result = qdf_mc_timer_start(v9 + 17304, 0xEA60u);
      if ( !(_DWORD)result )
        return result;
      v19 = (unsigned int)result;
      v18 = "%s: cannot start packetdump timer status: %d";
    }
    return qdf_trace_msg(0x34u, 8u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "csr_packetdump_timer_start", v19);
  }
  return result;
}
