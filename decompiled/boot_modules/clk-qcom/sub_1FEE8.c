__int64 __fastcall sub_1FEE8(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        __n128 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  *(_BYTE *)(a10 + 1505) = a7.n128_u8[0];
  return qcom_clk_crm_set_rate();
}
