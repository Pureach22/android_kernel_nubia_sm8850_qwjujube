__int64 __fastcall smmu_pmu_event_start(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v2; // w20
  __int64 v4; // x22
  unsigned int v5; // w8
  unsigned int v6; // w9
  unsigned int v7; // w0
  unsigned int v8; // w0
  __int64 v9; // x8
  __int64 result; // x0
  int v11; // w23
  int v12; // w23
  __int64 v13; // x24
  unsigned int v14; // w19

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(unsigned __int16 *)(a1 + 224);
  v4 = *(unsigned int *)(a1 + 396);
  v5 = *(_DWORD *)(v1 + 312);
  v6 = *(_DWORD *)(v1 + 316);
  *(_DWORD *)(a1 + 480) = 0;
  if ( v2 >= 0x80 )
  {
    v7 = qcom_scm_io_writel(*(_QWORD *)(v1 + 352) + 1412LL, 1);
    if ( v7 )
      return dev_err(
               *(_QWORD *)(v1 + 320) + 16LL,
               "%s: Failed to write to TCU STATS CFG! rc: %d\n",
               "smmu_pmu_event_start",
               v7);
    v7 = qcom_scm_io_writel(*(_QWORD *)(v1 + 352) + 1412LL, 0);
    if ( v7 )
      return dev_err(
               *(_QWORD *)(v1 + 320) + 16LL,
               "%s: Failed to write to TCU STATS CFG! rc: %d\n",
               "smmu_pmu_event_start",
               v7);
    v8 = qcom_scm_io_writel(*(_QWORD *)(v1 + 352) + 1680LL, 0);
    if ( v8 )
      return dev_err(
               *(_QWORD *)(v1 + 320) + 16LL,
               "%s: Failed to write to TCU STATS CB CFG! rc: %d\n",
               "smmu_pmu_event_start",
               v8);
    v9 = *(unsigned int *)(a1 + 396);
    if ( (unsigned int)v9 < 0x100 )
    {
      if ( (*(_QWORD *)(*(_QWORD *)(v1 + 8 * v9 - 2136) + 224LL) & 0xFF80LL) != 0 )
      {
        result = readl_relaxed(
                   *(_QWORD *)(v1 + 344)
                 + (unsigned __int16)*(_QWORD *)(*(_QWORD *)(v1 + 8 * v9 - 2136) + 224LL)
                 + 1280LL);
        *(_QWORD *)(a1 + 488) = (unsigned int)result;
      }
      else
      {
        *(_QWORD *)(a1 + 488) = 0x80000000LL;
        if ( *(_BYTE *)(v1 + 376) == 1 )
          result = writel_relaxed(0x80000000LL, *(_QWORD *)(v1 + 328) + (unsigned int)(4 * v9));
        else
          result = writeq_relaxed();
        __dsb(0xEu);
      }
      return result;
    }
LABEL_25:
    __break(0x5512u);
    return smmu_pmu_event_stop();
  }
  if ( (unsigned int)v4 >= 0x100 )
    goto LABEL_25;
  v11 = v5 / v6;
  if ( (*(_QWORD *)(*(_QWORD *)(v1 + 8 * v4 - 2136) + 224LL) & 0xFF80LL) != 0 )
  {
    *(_QWORD *)(a1 + 488) = (unsigned int)readl_relaxed(
                                            *(_QWORD *)(v1 + 344)
                                          + (unsigned __int16)*(_QWORD *)(*(_QWORD *)(v1 + 8 * v4 - 2136) + 224LL)
                                          + 1280LL);
  }
  else
  {
    *(_QWORD *)(a1 + 488) = 0x80000000LL;
    if ( *(_BYTE *)(v1 + 376) == 1 )
      writel_relaxed(0x80000000LL, *(_QWORD *)(v1 + 328) + 4 * v4);
    else
      writeq_relaxed();
    __dsb(0xEu);
  }
  v12 = 4 * ((int)v4 / v11);
  v13 = (unsigned int)(v12 + 2048);
  writel_relaxed(2048, *(_QWORD *)(v1 + 328) + v13);
  if ( (*(_BYTE *)(a1 + 276) & 4) != 0 )
  {
    writel_relaxed(256, *(_QWORD *)(v1 + 328) + v13);
    v14 = *(_DWORD *)(a1 + 272);
  }
  else
  {
    v14 = -1;
  }
  writel_relaxed(v2, *(_QWORD *)(v1 + 328) + 4 * v4 + 1024);
  writel_relaxed(v14, *(_QWORD *)(v1 + 328) + (unsigned int)(v12 + 2560));
  writel_relaxed((unsigned int)(1LL << v4), *(_QWORD *)(v1 + 328) + 3136LL);
  return writel_relaxed((unsigned int)(1LL << v4), *(_QWORD *)(v1 + 328) + 3072LL);
}
