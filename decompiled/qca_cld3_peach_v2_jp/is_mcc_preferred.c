__int64 __fastcall is_mcc_preferred(
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
  __int64 v12; // x8

  if ( a2 - 2467 > 0x11 )
    return 0;
  v12 = *(_QWORD *)(a1 + 1536);
  if ( *(_DWORD *)(v12 + 8) < 0x96Cu || *(_DWORD *)(v12 + 12) > 0x99Eu )
    return 0;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: conc ch freq %d & sap acs ch list is 1-11, prefer mcc",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "is_mcc_preferred",
    a2,
    v10,
    v11);
  return 1;
}
