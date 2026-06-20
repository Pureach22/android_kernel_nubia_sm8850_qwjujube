__int64 __fastcall dwc3_msm_set_ss_pwr_events(__int64 a1, char a2)
{
  unsigned int v4; // w0
  int v5; // w8
  int v6; // w9

  v4 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 1017944LL));
  writel(v4, (unsigned int *)(*(_QWORD *)(a1 + 8) + 1017944LL));
  v5 = readl((unsigned int *)(*(_QWORD *)(a1 + 8) + 1017948LL)) & 0xFFFFEFF7;
  if ( (a2 & 1) != 0 )
    v6 = 4104;
  else
    v6 = 0;
  return writel(v5 | (unsigned int)v6, (unsigned int *)(*(_QWORD *)(a1 + 8) + 1017948LL));
}
