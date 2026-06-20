__int64 __fastcall sdhci_msm_enhanced_strobe_mask(__int64 result, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v5; // w11
  int v6; // w8

  if ( *(_BYTE *)(result + 1059) == 1 )
  {
    v2 = *(_QWORD *)(result + 3416);
    v3 = result;
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(result + 1816) + *(unsigned int *)(v2 + 96))) & 0xFFFFDFFF;
    if ( (a2 & 1) != 0 )
      v6 = 0x2000;
    else
      v6 = 0;
    return writel_relaxed(v5 | (unsigned int)v6, (unsigned int *)(*(_QWORD *)(v3 + 1816) + *(unsigned int *)(v2 + 96)));
  }
  return result;
}
