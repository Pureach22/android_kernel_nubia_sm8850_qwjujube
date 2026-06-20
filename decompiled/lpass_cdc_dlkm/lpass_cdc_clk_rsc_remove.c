__int64 __fastcall lpass_cdc_clk_rsc_remove(__int64 a1)
{
  lpass_cdc_unregister_res_clk((_QWORD *)(a1 + 16));
  return of_platform_depopulate(a1 + 16);
}
