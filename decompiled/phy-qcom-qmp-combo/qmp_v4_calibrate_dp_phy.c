__int64 __fastcall qmp_v4_calibrate_dp_phy(__int64 a1)
{
  __int64 v1; // x9

  v1 = ((unsigned __int8)*(_DWORD *)(a1 + 296) + 1) & 3;
  *(_DWORD *)(a1 + 296) = v1;
  writel(qmp_v4_calibrate_dp_phy_cfg1_settings[v1], (unsigned int *)(*(_QWORD *)(a1 + 120) + 36LL));
  return 0;
}
