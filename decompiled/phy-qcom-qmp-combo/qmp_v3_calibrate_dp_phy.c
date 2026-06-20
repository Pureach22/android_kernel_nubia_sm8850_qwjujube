__int64 __fastcall qmp_v3_calibrate_dp_phy(__int64 a1)
{
  __int64 v1; // x1
  unsigned int v2; // w9
  unsigned int v3; // w8

  v1 = *(_QWORD *)(a1 + 120) + 36LL;
  v2 = (*(_DWORD *)(a1 + 296) + 1) % 3u;
  v3 = qmp_v3_calibrate_dp_phy_cfg1_settings[v2];
  *(_DWORD *)(a1 + 296) = v2;
  writel(v3, v1);
  return 0;
}
