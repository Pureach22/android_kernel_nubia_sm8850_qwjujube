__int64 __fastcall get_lut_entry(
        __int64 a1,
        unsigned int a2,
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

  if ( *(_DWORD *)(a1 + 80) > a2 )
    return *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (int)a2);
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: Invalid offset %d, lut_num %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "get_lut_entry",
    a2,
    v10,
    v11);
  return 0;
}
