bool __fastcall hdd_sap_create_ctx(
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
  __int64 ctx; // x8

  qdf_trace_msg(0x33u, 8u, "%s: creating sap context", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sap_create_ctx");
  ctx = sap_create_ctx(a1);
  *(_QWORD *)(a1 + 272) = ctx;
  return ctx != 0;
}
