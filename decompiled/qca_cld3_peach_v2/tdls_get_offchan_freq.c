__int64 __fastcall tdls_get_offchan_freq(
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
  __int64 v10; // x20
  unsigned int v11; // w19
  unsigned int v12; // w21

  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 )
  {
    v12 = *(_DWORD *)(a2 + 160);
    v11 = *(_DWORD *)(a2 + 164);
    if ( v11 && (tdls_is_6g_freq_allowed(*(_QWORD *)(a1 + 216), v11) & 1) != 0 )
      qdf_trace_msg(
        0,
        8u,
        "%s: 6 GHz freq: %d supported for TDLS",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "tdls_get_offchan_freq",
        v11);
    else
      return (unsigned int)wlan_reg_legacy_chan_to_freq(v10, v12, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "tdls_get_offchan_freq");
    return 0;
  }
  return v11;
}
