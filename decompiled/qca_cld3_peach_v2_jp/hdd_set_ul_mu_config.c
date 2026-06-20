__int64 __fastcall hdd_set_ul_mu_config(unsigned __int8 *a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 *v5; // x19
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  __int64 v17; // x8
  unsigned int v18; // w20
  unsigned int v19; // w21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v4 = *(_QWORD *)(a2 + 800);
  v5 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v6 = _wlan_hdd_validate_context(v5, "hdd_set_ul_mu_config");
  if ( !v6 )
  {
    if ( !v4 )
    {
      v17 = *(_QWORD *)(a2 + 760);
      if ( v17 )
      {
        v18 = *(unsigned __int8 *)(v17 + 4);
        if ( v18 >= 2 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid ulmu value, ulmu : %d",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "hdd_set_ul_mu_config",
            *(unsigned __int8 *)(v17 + 4));
          return (unsigned int)-22;
        }
        v19 = a1[8];
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: UL MU value : %d",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "hdd_set_ul_mu_config",
          *(unsigned __int8 *)(v17 + 4));
        if ( (unsigned int)wlan_mlme_set_ul_mu_config(*v5, v19, v18 ^ 1) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set MLO UL MU",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "hdd_set_ul_mu_config");
          return (unsigned int)-22;
        }
      }
    }
    return 0;
  }
  v15 = v6;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid HDD ctx, errno : %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "hdd_set_ul_mu_config",
    v6);
  return v15;
}
