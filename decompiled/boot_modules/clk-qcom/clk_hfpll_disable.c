__int64 __fastcall clk_hfpll_disable(__int64 a1)
{
  __int64 v2; // x20

  v2 = raw_spin_lock_irqsave(a1 + 144);
  regmap_update_bits_base(*(_QWORD *)(a1 + 24), **(unsigned int **)(a1 - 16), 7, 0, 0, 0, 0);
  return raw_spin_unlock_irqrestore(a1 + 144, v2);
}
