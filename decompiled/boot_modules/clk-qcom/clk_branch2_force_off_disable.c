__int64 __fastcall clk_branch2_force_off_disable(__int64 a1)
{
  regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 32), 0x400000, 0x400000, 0, 0, 0);
  return clk_branch_toggle(a1, 0, clk_branch2_check_halt);
}
