__int64 __fastcall target_if_alloc_pdev_tgt_info(
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

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x20u, "target_if_alloc_pdev_tgt_info", 731);
    if ( v10 )
    {
      v11 = v10;
      wlan_minidump_log(v10, 32, *(_QWORD *)(a1 + 80), 54, "target_pdev_info");
      *(_QWORD *)(a1 + 1232) = v11;
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: pdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_alloc_pdev_tgt_info");
    return 4;
  }
}
