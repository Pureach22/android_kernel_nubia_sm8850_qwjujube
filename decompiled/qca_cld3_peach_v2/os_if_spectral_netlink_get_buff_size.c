__int64 __fastcall os_if_spectral_netlink_get_buff_size(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a10 )
  {
    *a10 = 3028;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: buff_size pointer is NULL!",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "os_if_spectral_netlink_get_buff_size",
      v10,
      v11);
    return 29;
  }
}
