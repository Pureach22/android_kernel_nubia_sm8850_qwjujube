__int64 __fastcall smmu_pmu_event_stop(__int64 result, char a2)
{
  unsigned int v2; // w22
  __int64 v3; // x21
  __int64 v4; // x19
  char v5; // w23
  int v6; // w25
  int v7; // w24
  unsigned int v8; // w0

  if ( (*(_BYTE *)(result + 480) & 1) == 0 )
  {
    v2 = *(unsigned __int16 *)(result + 224);
    v3 = *(_QWORD *)(result + 152);
    v4 = result;
    if ( v2 <= 0x7F )
    {
      v5 = a2;
      v6 = *(_DWORD *)(result + 396);
      v7 = *(_DWORD *)(v3 + 312) / *(_DWORD *)(v3 + 316);
      writel_relaxed((unsigned int)(1LL << v6), *(_QWORD *)(v3 + 328) + 3168LL);
      writel_relaxed((unsigned int)(1LL << v6), *(_QWORD *)(v3 + 328) + 3104LL);
      result = writel_relaxed(0, *(_QWORD *)(v3 + 328) + (unsigned int)(4 * (v6 / v7) + 2048));
      a2 = v5;
    }
    if ( (a2 & 4) != 0 )
      result = smmu_pmu_event_update(v4);
    *(_DWORD *)(v4 + 480) |= 3u;
    if ( v2 >= 0x80 )
    {
      v8 = qcom_scm_io_writel(*(_QWORD *)(v3 + 352) + 1412LL, 2);
      if ( v8 )
      {
        return dev_err(
                 *(_QWORD *)(v3 + 320) + 16LL,
                 "%s: Failed to write to TCU STATS CFG! rc: %d\n",
                 "smmu_pmu_event_stop",
                 v8);
      }
      else
      {
        result = qcom_scm_io_writel(*(_QWORD *)(v3 + 352) + 1680LL, 196608);
        if ( (_DWORD)result )
          return dev_err(
                   *(_QWORD *)(v3 + 320) + 16LL,
                   "%s: Failed to write to TCU STATS CB CFG! rc: %d\n",
                   "smmu_pmu_event_stop",
                   (unsigned int)result);
      }
    }
  }
  return result;
}
