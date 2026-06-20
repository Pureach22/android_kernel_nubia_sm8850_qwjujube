__int64 __fastcall wlan_tdls_antenna_switch(
        __int64 a1,
        int a2,
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
  __int64 v11; // x20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 608);
    if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: osif priv or tdls priv is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_tdls_antenna_switch");
      return 4294967274LL;
    }
    *(_DWORD *)(v11 + 192) = 0;
    v12 = ucfg_tdls_antenna_switch(a1, a2);
    if ( v12 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: ucfg_tdls_antenna_switch failed err %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_tdls_antenna_switch",
        v12);
    }
    else
    {
      if ( wait_for_completion_timeout(v11 + 192, 250) )
      {
        v30 = *(_DWORD *)(v11 + 236);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: tdls antenna switch status:%d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_tdls_antenna_switch",
          v30);
        return v30;
      }
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: timeout for tdls antenna switch %ld",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_tdls_antenna_switch",
        0);
    }
  }
  else
  {
    qdf_trace_msg(0x48u, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_tdls_antenna_switch");
  }
  return 4294967285LL;
}
