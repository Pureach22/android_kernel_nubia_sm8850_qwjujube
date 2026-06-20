__int64 __fastcall hdd_get_link_speed_cb(
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
  __int64 v11; // x0
  __int64 v12; // x20
  __int64 v13; // x0
  int v14; // w9
  const char *v16; // x2

  if ( a1 )
  {
    v11 = osif_request_get(a2);
    if ( v11 )
    {
      v12 = v11;
      v13 = osif_request_priv(v11);
      v14 = *(_DWORD *)(a1 + 8);
      *(_QWORD *)v13 = *(_QWORD *)a1;
      *(_DWORD *)(v13 + 8) = v14;
      osif_request_complete(v12);
      return osif_request_put(v12);
    }
    v16 = "%s: Obsolete request";
  }
  else
  {
    v16 = "%s: NULL linkspeed";
  }
  return qdf_trace_msg(0x33u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_link_speed_cb");
}
