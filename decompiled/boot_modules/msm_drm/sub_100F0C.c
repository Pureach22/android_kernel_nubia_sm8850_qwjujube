__int64 __fastcall sub_100F0C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int128 v6; // q20
  __int128 v7; // q21

  *(_OWORD *)(a6 - 160) = v6;
  *(_OWORD *)(a6 - 144) = v7;
  return sde_core_irq_idx_lookup();
}
