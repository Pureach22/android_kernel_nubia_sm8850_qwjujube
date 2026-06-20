__int64 __fastcall wma_tx_detach(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 **context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  void (*v20)(void); // x8

  context = (__int64 **)_cds_get_context(71, (__int64)"wma_tx_detach", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  if ( *context )
  {
    v19 = **context;
    if ( v19 )
    {
      v20 = *(void (**)(void))(v19 + 296);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != -1593903812 )
          __break(0x8228u);
        v20();
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_mgmt_tx_cb_set");
  }
  a1[42] = 0;
  a1[53] = 0;
  a1[55] = 0;
  return 0;
}
