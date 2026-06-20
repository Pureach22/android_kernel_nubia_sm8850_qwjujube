__int64 __fastcall sub_1F574(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a5 & 0x40000000000000LL) == 0 )
    JUMPOUT(0x1ED6C);
  return qcom_cc_register_board_clk();
}
