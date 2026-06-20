__int64 __fastcall clk_rpmh_bcm_recalc_rate(__int64 a1)
{
  return (unsigned int)(*(_DWORD *)(a1 + 60) * *(_DWORD *)(a1 + 48));
}
