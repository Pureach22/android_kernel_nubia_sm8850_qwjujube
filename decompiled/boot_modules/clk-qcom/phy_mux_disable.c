__int64 __fastcall phy_mux_disable(__int64 a1)
{
  return regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 8), 3, 2, 0, 0, 0);
}
