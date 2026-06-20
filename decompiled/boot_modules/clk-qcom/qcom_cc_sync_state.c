__int64 __fastcall qcom_cc_sync_state(__int64 a1, __int64 a2)
{
  dev_info(a1, "sync_state\n");
  clk_sync_state(a1);
  return clk_vdd_proxy_unvote(a1, a2);
}
