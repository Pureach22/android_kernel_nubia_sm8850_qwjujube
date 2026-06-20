__int64 __fastcall sdhci_enable_ext_fb_clk(__int64 a1)
{
  __int64 (*v2)(void); // x8
  int v3; // w0
  _DWORD *v4; // x8

  v2 = **(__int64 (***)(void))(a1 + 64);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != 1381278590 )
      __break(0x8228u);
    v3 = v2();
  }
  else
  {
    v3 = readl((unsigned int *)(*(_QWORD *)(a1 + 24) + 608LL));
  }
  v4 = *(_DWORD **)(*(_QWORD *)(a1 + 64) + 24LL);
  if ( !v4 )
    return writel(v3 | 0x1000000u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 608LL));
  if ( *(v4 - 1) != 1259614694 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v4)(a1, v3 | 0x1000000u, 608);
}
