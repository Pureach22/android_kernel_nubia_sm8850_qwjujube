__int64 __fastcall qcusb_emu_phy_init(__int64 *a1)
{
  int v2; // w0
  int v3; // w0
  int v4; // w20
  __int64 v5; // x20
  unsigned int v6; // w0
  __int64 v7; // x8
  int v8; // w0

  writel_relaxed(0xFFFFFFFFLL, a1[47] + 4);
  usleep_range_state(10000, 12000, 2);
  v2 = readl_relaxed(a1[47] + 52);
  writel_relaxed(v2 | 0x2000000u, a1[47] + 52);
  usleep_range_state(10000, 12000, 2);
  v3 = readl_relaxed(a1[47] + 52);
  writel_relaxed(v3 & 0xFDFFFFFF, a1[47] + 52);
  usleep_range_state(10000, 12000, 2);
  writel_relaxed(4294967283LL, a1[47] + 4);
  usleep_range_state(10000, 12000, 2);
  writel_relaxed(4294967280LL, a1[47] + 4);
  usleep_range_state(10000, 12000, 2);
  if ( *((int *)a1 + 100) >= 1 )
  {
    v4 = 0;
    do
    {
      writel_relaxed(*(unsigned int *)(a1[49] + 4LL * v4), a1[47] + *(int *)(a1[49] + 4LL * (v4 + 1)));
      usleep_range_state(10000, 12000, 2);
      v4 += 2;
    }
    while ( v4 < *((_DWORD *)a1 + 100) );
  }
  writel_relaxed(0, a1[47] + 4);
  usleep_range_state(10000, 12000, 2);
  writel_relaxed(9, a1[47] + 20);
  usleep_range_state(10000, 12000, 2);
  v5 = *a1;
  v6 = readl_relaxed(a1[47] + 16);
  dev_info(v5, "PHY UTMI/ULPI CLK frequency:%d MHz\n", v6 / 0x3E8);
  v7 = a1[48];
  if ( v7 )
  {
    v8 = readl_relaxed(v7 + 16);
    writel_relaxed(v8 & 0xEFFFFFFF, a1[48] + 16);
  }
  return 0;
}
