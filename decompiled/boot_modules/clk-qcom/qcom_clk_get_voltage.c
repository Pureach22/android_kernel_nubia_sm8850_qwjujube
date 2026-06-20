__int64 __fastcall qcom_clk_get_voltage(__int64 a1, __int64 a2)
{
  _QWORD *hw; // x19
  unsigned int vdd_level; // w0
  unsigned int v5; // w1

  hw = (_QWORD *)_clk_get_hw(a1);
  if ( clk_is_regmap_clk(hw) )
  {
    vdd_level = clk_find_vdd_level(hw, hw + 6, a2);
    v5 = vdd_level;
    if ( (vdd_level & 0x80000000) == 0 )
      return (unsigned int)clk_get_vdd_voltage(hw + 6, vdd_level);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v5;
}
