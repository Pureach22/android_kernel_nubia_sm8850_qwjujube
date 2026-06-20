__int64 __fastcall clk_rcg2_shared_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = clk_rcg2_regmap_ops;
  regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), a1 + 148);
  clk_rcg2_set_force_enable(a1);
  regmap_write(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4), *(unsigned __int8 *)(a1 - 42) << 8);
  update_config(a1 - 48);
  regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 0, 0, 0, 0);
  return 0;
}
