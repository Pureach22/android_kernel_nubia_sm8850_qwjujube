__int64 __fastcall wlansap_set_acl_mode(
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 )
  {
    *(_DWORD *)(a1 + 824) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlansap_set_acl_mode",
      v10,
      v11);
    return 5;
  }
}
