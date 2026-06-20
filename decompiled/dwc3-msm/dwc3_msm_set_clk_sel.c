__int64 __fastcall dwc3_msm_set_clk_sel(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w8
  __int64 v4; // x20
  int v5; // w0
  int v6; // w0
  __int64 v7; // x19
  int v8; // w0

  v1 = *(_QWORD *)(result + 40);
  v2 = result;
  if ( v1 )
  {
    v3 = *(_DWORD *)(*(_QWORD *)(v1 + 168) + 1232LL);
    if ( v3 == 3 )
      goto LABEL_6;
LABEL_5:
    if ( v3 != 2 )
      return result;
    goto LABEL_6;
  }
  v3 = *(_DWORD *)(result + 1128);
  if ( v3 != 3 )
    goto LABEL_5;
LABEL_6:
  v4 = *(_QWORD *)(result + 8);
  v5 = readl((unsigned int *)(v4 + 1017864));
  writel(v5 | 0x100, (unsigned int *)(v4 + 1017864));
  _const_udelay(21475);
  v6 = readl((unsigned int *)(*(_QWORD *)(v2 + 8) + 1017864LL));
  writel(v6 | 9, (unsigned int *)(*(_QWORD *)(v2 + 8) + 1017864LL));
  _const_udelay(21475);
  v7 = *(_QWORD *)(v2 + 8);
  v8 = readl((unsigned int *)(v7 + 1017864));
  return writel(v8 & 0xFFFFFEFF, (unsigned int *)(v7 + 1017864));
}
