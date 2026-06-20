__int64 __fastcall wlansap_set_invalid_session(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    *(_BYTE *)(a1 + 12) = -1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlansap_set_invalid_session",
      v9,
      v10);
    return 16;
  }
}
