__int64 __fastcall wlan_register_t2lm_link_update_notify_handler(
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
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 result; // x0
  __int64 v14; // x9

  result = 0;
  v14 = a2 + 3000;
  while ( (*(_BYTE *)(v14 + result) & 1) != 0 )
  {
    if ( ++result == 50 )
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Failed to register the link disablement callback",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_register_t2lm_link_update_notify_handler",
        v10,
        v11);
      return 4294967274LL;
    }
  }
  *(_QWORD *)(v14 + 8 * result - 400) = a1;
  *(_BYTE *)(v14 + result) = 1;
  return result;
}
