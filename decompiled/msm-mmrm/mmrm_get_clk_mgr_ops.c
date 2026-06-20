__int64 __fastcall mmrm_get_clk_mgr_ops(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 + 24);
  if ( v1 == 1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C35C, "err ", "mmrm_get_clk_mgr_ops");
    return 4294967274LL;
  }
  else if ( v1 )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C5DF, "err ", "mmrm_get_clk_mgr_ops");
    return 0;
  }
  else
  {
    *(_QWORD *)(a1 + 104) = sw_clk_mgr_ops;
    return 0;
  }
}
