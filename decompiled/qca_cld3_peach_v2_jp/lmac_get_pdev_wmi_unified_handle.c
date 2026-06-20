__int64 __fastcall lmac_get_pdev_wmi_unified_handle(
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
  __int64 v9; // x8
  const char *v11; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 1232);
    if ( v9 )
      return *(_QWORD *)v9;
    v11 = "%s: target_pdev_info is null";
  }
  else
  {
    v11 = "%s: pdev is null";
  }
  qdf_trace_msg(0x49u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "lmac_get_pdev_wmi_handle");
  return 0;
}
