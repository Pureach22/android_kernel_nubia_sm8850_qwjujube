__int64 __fastcall wlansap_update_ll_lt_sap_acs_result(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  const char *v22; // x2

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    if ( a1 )
    {
      result = wlansap_set_acs_ch_freq((__int64)context, a1, a2, v13, v14, v15, v16, v17, v18, v19, v20);
      *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 564LL) = a2;
      *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 568LL) = 0;
      return result;
    }
    v22 = "%s: Invalid sap context";
  }
  else
  {
    v22 = "%s: Invalid MAC context";
  }
  return qdf_trace_msg(0x39u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "wlansap_update_ll_lt_sap_acs_result");
}
