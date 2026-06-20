__int64 __fastcall clk_rcg_lcc_enable(__int64 a1)
{
  return regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1024, 1024, 0, 0, 0);
}
