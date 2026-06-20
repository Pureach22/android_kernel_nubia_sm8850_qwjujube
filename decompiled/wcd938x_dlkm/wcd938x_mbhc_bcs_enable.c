__int64 __fastcall wcd938x_mbhc_bcs_enable(__int64 a1, char a2)
{
  return wcd938x_disable_bcs_before_slow_insert(*(_QWORD *)(a1 + 216), (a2 & 1) == 0);
}
