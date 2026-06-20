__int64 __fastcall hdd_sap_destroy_ctx(
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
  __int64 v10; // x0
  __int64 v11; // x20

  v10 = *(_QWORD *)(a1 + 2432);
  v11 = *(_QWORD *)(a1 + 272);
  if ( v10 )
  {
    _qdf_mem_free(v10);
    *(_QWORD *)(a1 + 2432) = 0;
  }
  if ( v11 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: destroying sap context", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sap_destroy_ctx");
    if ( (unsigned int)sap_destroy_ctx(v11) )
      return 0;
    *(_QWORD *)(a1 + 272) = 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: sap context is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sap_destroy_ctx");
  }
  return 1;
}
