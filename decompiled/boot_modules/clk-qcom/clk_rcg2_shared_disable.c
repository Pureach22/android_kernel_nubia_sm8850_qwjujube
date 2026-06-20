__int64 __fastcall clk_rcg2_shared_disable(__int64 a1)
{
  _DWORD *v2; // x20

  v2 = (_DWORD *)(a1 - 48);
  regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), a1 + 148);
  clk_rcg2_set_force_enable(a1);
  regmap_write(*(_QWORD *)(a1 + 24), (unsigned int)(*v2 + 4), *(unsigned __int8 *)(a1 - 42) << 8);
  update_config(v2);
  return regmap_update_bits_base(*(_QWORD *)(a1 + 24), (unsigned int)*v2, 2, 0, 0, 0, 0);
}
