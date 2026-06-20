__int64 __fastcall dp_pdev_post_attach_wifi3(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  void (*v14)(void); // x8
  const char *v16; // x2

  if ( a2 || (v11 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: DP PDEV is Null for pdev id %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_pdev_post_attach_wifi3",
      a1,
      a2);
    return 16;
  }
  v12 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 20112LL);
  if ( v12 )
  {
    v13 = *(_QWORD *)(v12 + 416);
    if ( v13 )
    {
      v14 = *(void (**)(void))(v13 + 328);
      if ( v14 )
      {
        if ( *((_DWORD *)v14 - 1) != -1116635294 )
          __break(0x8228u);
        v14();
        return 0;
      }
    }
    v16 = "%s: callback not registered";
  }
  else
  {
    v16 = "%s: monitor soc is NULL";
  }
  qdf_trace_msg(0x92u, 8u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_tx_capture_debugfs_init", a1);
  return 0;
}
