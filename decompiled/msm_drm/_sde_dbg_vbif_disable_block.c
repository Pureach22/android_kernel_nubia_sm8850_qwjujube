__int64 __fastcall sde_dbg_vbif_disable_block(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 result; // x0

  v2 = 532;
  if ( a2 == 532 )
    v2 = 540;
  writel_relaxed_6(0, a1 + v2);
  result = writel_relaxed_6(1, a1 + 528);
  __dsb(0xEu);
  return result;
}
