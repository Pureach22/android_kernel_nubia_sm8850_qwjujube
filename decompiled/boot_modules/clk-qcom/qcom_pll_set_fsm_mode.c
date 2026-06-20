__int64 __fastcall qcom_pll_set_fsm_mode(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  unsigned int v6; // w21

  v6 = a2;
  regmap_update_bits_base(a1, a2, 0x200000, 0, 0, 0, 0);
  regmap_update_bits_base(a1, v6, 1048320, (a4 << 8) | (a3 << 14), 0, 0, 0);
  return regmap_update_bits_base(a1, v6, 0x100000, 0x100000, 0, 0, 0);
}
