__int64 __fastcall ucfg_scan_init_ssid_params(
        __int64 a1,
        unsigned int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: null request", a4, a5, a6, a7, a8, a9, a10, a11, "ucfg_scan_init_ssid_params");
    return 29;
  }
  if ( a2 )
  {
    if ( !a3 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: null ssid_list while num_ssid: %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ucfg_scan_init_ssid_params",
        a2);
      return 29;
    }
    if ( a2 >= 0x11 )
    {
      qdf_trace_msg(
        0x15u,
        3u,
        "%s: overflow: received %d, max supported : %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ucfg_scan_init_ssid_params");
      return 18;
    }
    *(_DWORD *)(a1 + 112) = a2;
    qdf_mem_copy((void *)(a1 + 1348), a3, 33 * a2);
  }
  else
  {
    *(_DWORD *)(a1 + 112) = 0;
    qdf_mem_set((void *)(a1 + 1348), 0x210u, 0);
  }
  return 0;
}
