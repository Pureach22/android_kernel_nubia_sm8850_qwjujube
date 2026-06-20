__int64 __fastcall dsi_phy_hw_v4_0_commit_phy_timing(_QWORD *a1, unsigned __int8 *a2)
{
  writel_relaxed_10(a2[52], *a1 + 180LL);
  writel_relaxed_10(a2[53], *a1 + 184LL);
  writel_relaxed_10(a2[54], *a1 + 188LL);
  writel_relaxed_10(a2[55], *a1 + 192LL);
  writel_relaxed_10(a2[56], *a1 + 196LL);
  writel_relaxed_10(a2[57], *a1 + 200LL);
  writel_relaxed_10(a2[58], *a1 + 204LL);
  writel_relaxed_10(a2[59], *a1 + 208LL);
  writel_relaxed_10(a2[60], *a1 + 212LL);
  writel_relaxed_10(a2[61], *a1 + 216LL);
  writel_relaxed_10(a2[62], *a1 + 220LL);
  writel_relaxed_10(a2[63], *a1 + 224LL);
  writel_relaxed_10(a2[64], *a1 + 228LL);
  return writel_relaxed_10(a2[65], *a1 + 232LL);
}
