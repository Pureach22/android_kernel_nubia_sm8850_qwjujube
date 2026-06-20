__int64 __fastcall hdd_wmm_connect(
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
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: qap is %d, qos_connection is %d, acm_mask is 0x%x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_wmm_connect",
    1,
    1,
    0);
  *(_BYTE *)(a1 + 1880) = 0;
  *(_WORD *)(a1 + 3000) = 257;
  *(_BYTE *)(a1 + 1885) = 1;
  *(_BYTE *)(a1 + 2160) = 0;
  *(_BYTE *)(a1 + 2165) = 1;
  *(_BYTE *)(a1 + 2440) = 0;
  *(_BYTE *)(a1 + 2445) = 1;
  *(_BYTE *)(a1 + 2720) = 0;
  *(_BYTE *)(a1 + 2725) = 1;
  return 0;
}
