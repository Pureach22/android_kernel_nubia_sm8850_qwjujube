__int64 __fastcall tdls_set_extctrl_param(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        char a12)
{
  __int64 v12; // x29
  __int64 v13; // x30

  if ( a1 )
  {
    *(_BYTE *)(a1 + 490) = a12;
    *(_DWORD *)(a1 + 492) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      (unsigned __int8)a1,
      2u,
      "%s: peer is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_set_extctrl_param",
      v12,
      v13);
    return 16;
  }
}
