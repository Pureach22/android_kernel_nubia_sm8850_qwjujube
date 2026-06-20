__int64 wlan_dp_ml_mon_supported()
{
  __int64 context; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  unsigned int v11; // w0
  __int64 v12; // x4
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, "wlan_dp_ml_mon_supported");
  if ( !context )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Unable to get dp_soc", v1, v2, v3, v4, v5, v6, v7, v8, "wlan_dp_ml_mon_supported");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v1, v2, v3, v4, v5, v6, v7, v8, "cdp_txrx_get_psoc_param");
LABEL_11:
    v12 = 16;
LABEL_12:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get psoc param status: %d",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "wlan_dp_ml_mon_supported",
      v12,
      0,
      0,
      0,
      v14);
    goto LABEL_13;
  }
  v9 = *(_QWORD *)(*(_QWORD *)context + 8LL);
  if ( !v9 )
    goto LABEL_11;
  v10 = *(__int64 (**)(void))(v9 + 192);
  if ( !v10 )
    goto LABEL_11;
  if ( *((_DWORD *)v10 - 1) != 875927212 )
    __break(0x8228u);
  v11 = v10();
  v12 = v11;
  if ( v11 )
    goto LABEL_12;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return 0;
}
