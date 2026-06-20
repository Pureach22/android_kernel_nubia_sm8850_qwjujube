__int64 __fastcall qcom_cc_register_sleep_clk(__int64 a1)
{
  return qcom_cc_register_board_clk(a1, (__int64)"sleep_clk", (__int64)"sleep_clk_src", 0x8000);
}
