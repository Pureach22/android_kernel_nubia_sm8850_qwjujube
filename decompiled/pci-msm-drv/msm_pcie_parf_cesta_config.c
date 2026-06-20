__int64 __fastcall msm_pcie_parf_cesta_config(__int64 a1)
{
  __int64 v2; // x21
  unsigned int *v3; // x19
  int v4; // w0
  unsigned int v5; // w0

  v2 = *(_QWORD *)(a1 + 3128);
  v3 = (unsigned int *)(*(_QWORD *)(a1 + 872) + *(unsigned int *)(a1 + 1344));
  v4 = readl_relaxed_0(v3);
  if ( v2 )
  {
    v5 = v4 | 9;
    v3 = (unsigned int *)(*(_QWORD *)(a1 + 872) + *(unsigned int *)(a1 + 1344));
  }
  else
  {
    v5 = v4 & 0xFFFFFFFE;
  }
  writel_relaxed_0(v5, v3);
  return readl_relaxed_0(v3);
}
