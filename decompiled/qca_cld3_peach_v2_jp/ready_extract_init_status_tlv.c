__int64 __fastcall ready_extract_init_status_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  __int64 v10; // x19

  v10 = *a10;
  qdf_trace_msg(
    0x31u,
    4u,
    "%s: %s:%d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "ready_extract_init_status_tlv",
    "ready_extract_init_status_tlv",
    *(unsigned int *)(*a10 + 36));
  return *(unsigned int *)(v10 + 36);
}
