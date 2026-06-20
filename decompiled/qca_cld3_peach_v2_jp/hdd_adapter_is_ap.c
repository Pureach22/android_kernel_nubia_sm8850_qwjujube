bool __fastcall hdd_adapter_is_ap(
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
    return (*(_DWORD *)(a1 + 40) & 0xFFFFFFFD) == 1;
  qdf_trace_msg(0x33u, 2u, "%s: null adapter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_adapter_is_ap", v9, v10);
  return 0;
}
