__int64 __fastcall os_if_fwol_enable_mdns_offload(
        __int64 a1,
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  const char *v20; // x2

  if ( !a1 )
  {
    v20 = "%s: Null pointer for psoc";
LABEL_7:
    qdf_trace_msg(0x48u, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_fwol_enable_mdns_offload");
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v20 = "%s: Invalid mDNS config";
    goto LABEL_7;
  }
  result = ucfg_fwol_set_mdns_config(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to set mDNS Config",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "os_if_fwol_enable_mdns_offload");
    return qdf_status_to_os_return(v19);
  }
  return result;
}
