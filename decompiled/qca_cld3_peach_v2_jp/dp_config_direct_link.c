__int64 __fastcall dp_config_direct_link(
        __int64 a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v11; // x21
  __int64 htc_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  int v34; // w9
  __int64 hif_device; // x0
  __int64 v37; // x0
  __int64 v38; // x0

  v11 = *(__int64 **)a1;
  if ( !*(_QWORD *)a1 || !*v11 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: DP Handle is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_config_direct_link");
    return 9;
  }
  if ( v11[184] )
  {
    htc_hdl = lmac_get_htc_hdl(*v11, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( !htc_hdl )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: HTC handle is NULL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "dp_config_direct_link");
      return 13;
    }
    v24 = htc_hdl;
    qdf_mutex_acquire((__int64)(v11 + 176));
    v33 = *(unsigned __int8 *)(a1 + 3660);
    *(_BYTE *)(a1 + 3659) = a2 & 1;
    if ( (a2 & 1) != 0 )
      v34 = a3 & 1;
    else
      v34 = v33;
    *(_BYTE *)(a1 + 3660) = a3 & 1;
    if ( (a2 & 1) != 0 )
    {
      if ( v34 )
      {
        hif_device = htc_get_hif_device(v24);
        hif_prevent_link_low_power_states(hif_device);
      }
      else if ( v33 )
      {
        v38 = htc_get_hif_device(v24);
        hif_allow_link_low_power_states(v38);
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Direct link config set. Low link latency enabled: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_config_direct_link",
        a3 & 1);
    }
    else
    {
      if ( v34 )
      {
        v37 = htc_get_hif_device(v24);
        hif_allow_link_low_power_states(v37);
      }
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Direct link config cleared.",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "dp_config_direct_link");
    }
    qdf_mutex_release((__int64)(v11 + 176));
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: Direct link not enabled", a4, a5, a6, a7, a8, a9, a10, a11, "dp_config_direct_link");
  }
  return 0;
}
