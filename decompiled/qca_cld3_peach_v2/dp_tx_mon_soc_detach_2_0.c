__int64 __fastcall dp_tx_mon_soc_detach_2_0(
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
  __int64 v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v9 = *(_QWORD *)(a1 + 20112);
  if ( v9 )
  {
    dp_mon_desc_pool_free(a1, v9 + 696, 0xDu, a2, a3, a4, a5, a6, a7, a8, a9);
    dp_srng_free(a1, v9 + 456, v11, v12, v13, v14, v15, v16, v17, v18);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x92u, 2u, "%s: DP MON SOC NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_tx_mon_soc_detach_2_0");
    return 16;
  }
}
