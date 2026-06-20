__int64 __fastcall extract_green_ap_ll_ps_param_tlv(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  const char *v12; // x2

  if ( a1 )
  {
    v10 = *a1;
    if ( *a1 )
    {
      *(_DWORD *)(a2 + 4) = *(_DWORD *)(v10 + 4);
      *(_QWORD *)(a2 + 8) = *(_QWORD *)(v10 + 8);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: cookie : %u next_tsf %llu",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "extract_green_ap_ll_ps_param_tlv");
      return 0;
    }
    v12 = "%s: Invalid low latency power save event buffer";
  }
  else
  {
    v12 = "%s: Invalid XGAP SAP info status";
  }
  qdf_trace_msg(0x31u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "extract_green_ap_ll_ps_param_tlv");
  return 4;
}
