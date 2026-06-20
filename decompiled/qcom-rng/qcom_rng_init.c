__int64 __fastcall qcom_rng_init(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v3; // x19
  unsigned int v4; // w21
  int v5; // w0
  int v6; // w0

  v1 = qcom_rng_dev;
  *(_QWORD *)(a1 + 32) = qcom_rng_dev;
  if ( (**(_BYTE **)(v1 + 216) & 1) != 0 )
    return 0;
  v3 = *(_QWORD *)(v1 + 56);
  result = clk_prepare(v3);
  if ( !(_DWORD)result )
  {
    v4 = clk_enable(v3);
    if ( !v4 )
    {
      if ( (readl_relaxed(*(_QWORD *)(v1 + 48) + 260LL) & 2) == 0 )
      {
        v5 = readl_relaxed(*(_QWORD *)(v1 + 48) + 256LL);
        writel(v5 & 0xFFFF0000 | 0xDDDD, *(_QWORD *)(v1 + 48) + 256LL);
        v6 = readl_relaxed(*(_QWORD *)(v1 + 48) + 260LL);
        writel(v6 | 2u, *(_QWORD *)(v1 + 48) + 260LL);
      }
      v3 = *(_QWORD *)(v1 + 56);
      clk_disable(v3);
    }
    clk_unprepare(v3);
    return v4;
  }
  return result;
}
