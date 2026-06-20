__int64 __fastcall mdwc3_usb2_phy_soft_reset(__int64 a1)
{
  int v2; // w0
  int v3; // w0

  v2 = readl(*(_QWORD *)(a1 + 8) + 49664LL);
  writel(v2 | 0x80000000, *(_QWORD *)(a1 + 8) + 49664LL);
  _const_udelay(85900);
  v3 = readl(*(_QWORD *)(a1 + 8) + 49664LL);
  return writel(v3 & 0x7FFFFFFF, *(_QWORD *)(a1 + 8) + 49664LL);
}
