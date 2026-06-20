__int64 __fastcall m31eusb2_phy_exit(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x19
  int v4; // w0

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 96) )
  {
    v2 = *(_QWORD *)(v1 + 80);
    if ( v2 )
    {
      clk_disable(*(_QWORD *)(v1 + 80));
      clk_unprepare(v2);
    }
    v3 = *(_QWORD *)(v1 + 72);
    clk_disable(v3);
    clk_unprepare(v3);
    *(_BYTE *)(v1 + 96) = 0;
  }
  if ( *(_BYTE *)(v1 + 98) )
  {
    phy_exit(*(_QWORD *)(v1 + 88));
    *(_BYTE *)(v1 + 98) = 0;
  }
  if ( *(_BYTE *)(v1 + 97) )
  {
    v4 = readl_relaxed(*(_QWORD *)(v1 + 24));
    writel_relaxed(v4 & 0xFFFFFFFE, *(_QWORD *)(v1 + 24));
    __dsb(0xFu);
    regulator_bulk_disable(3, *(_QWORD *)(v1 + 48));
    *(_BYTE *)(v1 + 97) = 0;
  }
  return 0;
}
