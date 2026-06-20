__int64 __fastcall os_if_fwol_disable_mdns_offload(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  unsigned int v29; // w20

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x258u, "os_if_fwol_disable_mdns_offload", 186);
    if ( v10 )
    {
      *(_BYTE *)(v10 + 4) = 0;
      v19 = ucfg_fwol_set_mdns_config(a1, v10, v11, v12, v13, v14, v15, v16, v17, v18);
      if ( v19 )
      {
        v28 = v19;
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Failed to set mDNS Config",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "os_if_fwol_disable_mdns_offload");
        v19 = v28;
      }
      v29 = qdf_status_to_os_return(v19);
    }
    else
    {
      v29 = -12;
    }
    _qdf_mem_free(v10);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Null pointer for psoc",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "os_if_fwol_disable_mdns_offload");
    return (unsigned int)-22;
  }
  return v29;
}
