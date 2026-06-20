__int64 __fastcall clk_alpha_pll_stromer_set_rate(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x8
  unsigned __int64 v5; // x2
  __int64 v6; // x9
  unsigned __int64 v7; // x20
  char is_enabled; // w8
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x1
  unsigned int *v12; // x19

  v3 = a3;
  v5 = a2 / a3;
  v6 = a2 - v5 * v3;
  if ( v6 )
    v7 = ((v6 << 32) / v3) << 8;
  else
    v7 = 0;
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
    v5);
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
    (unsigned int)v7);
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL),
    HIDWORD(v7));
  regmap_update_bits_base(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
    0x1000000,
    0x1000000,
    0,
    0,
    0);
  is_enabled = clk_hw_is_enabled(a1);
  result = 0;
  if ( (is_enabled & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 24);
    v11 = *(unsigned int *)(a1 - 48);
    v12 = (unsigned int *)(a1 - 48);
    regmap_update_bits_base(v10, v11, 0x400000, 0x400000, 0, 0, 0);
    result = wait_for_pll(v12, 0x400000, 1u, "update");
    if ( !(_DWORD)result )
      return wait_for_pll(v12, 0x80000000, 0, "enable");
  }
  return result;
}
