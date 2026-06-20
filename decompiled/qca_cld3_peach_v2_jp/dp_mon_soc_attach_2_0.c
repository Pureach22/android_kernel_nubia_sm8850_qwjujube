__int64 __fastcall dp_mon_soc_attach_2_0(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v19; // w20

  if ( *(_QWORD *)(a1 + 20056) )
  {
    if ( (unsigned int)dp_tx_mon_soc_attach_2_0() )
    {
      v18 = "%s: %pK: SRNG setup failed fortx_mon_buf_ring";
    }
    else
    {
      if ( !(unsigned int)dp_tx_mon_buf_desc_pool_alloc(a1) )
        return 0;
      v18 = "%s: %pK: Tx mon desc pool allocation failed";
    }
    v19 = 2;
    qdf_trace_msg(0x92u, 2u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "dp_mon_soc_attach_2_0", a1);
    dp_tx_mon_soc_detach_2_0(a1, 0);
  }
  else
  {
    qdf_trace_msg(0x92u, 2u, "%s: DP MON SOC is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_soc_attach_2_0");
    return 16;
  }
  return v19;
}
