__int64 __fastcall target_if_free_pdev_tgt_info(
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
  __int64 v9; // x19
  __int64 v10; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 1232);
    v10 = *(_QWORD *)(a1 + 80);
    *(_QWORD *)(a1 + 1232) = 0;
    wlan_minidump_remove(v9, 32, v10, 54, "target_pdev_info");
    _qdf_mem_free(v9);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: pdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_free_pdev_tgt_info");
    return 4;
  }
}
