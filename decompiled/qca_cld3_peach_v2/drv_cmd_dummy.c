__int64 __fastcall drv_cmd_dummy(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %s: Ignoring driver command \"%s\"",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "drv_cmd_dummy",
    *(_QWORD *)(*(_QWORD *)a1 + 32LL) + 296LL,
    a11);
  return 0;
}
