__int64 __fastcall mlo_is_link_recfg_supported(
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
  __int64 v11; // x8
  const char *v12; // x2

  v11 = *(_QWORD *)(a1 + 216);
  if ( v11 && *(_QWORD *)(v11 + 80) )
  {
    if ( *(_QWORD *)(a1 + 1360) )
      v12 = "%s: link_recfg not enabled";
    else
      v12 = "%s: null mlo_dev_ctx";
  }
  else
  {
    v12 = "%s: null psoc";
  }
  qdf_trace_msg(0x8Fu, 8u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_is_link_recfg_supported", v9, v10);
  return 0;
}
