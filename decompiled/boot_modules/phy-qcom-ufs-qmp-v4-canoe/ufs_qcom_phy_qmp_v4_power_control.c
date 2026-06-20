__int64 __fastcall ufs_qcom_phy_qmp_v4_power_control(__int64 a1, char a2)
{
  __int64 v2; // x20
  int v4; // w0
  int v5; // w0
  __int64 result; // x0
  int v7; // w0
  int v8; // w0

  v2 = *(_QWORD *)(a1 + 16);
  if ( (a2 & 1) != 0 )
  {
    if ( !*(_QWORD *)(a1 + 264) )
      _pm_runtime_resume(*(_QWORD *)(a1 + 16), 4);
    v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 5104LL));
    writel_relaxed(v4 & 0xFFFFFFBF, (unsigned int *)(*(_QWORD *)(a1 + 24) + 5104LL));
    if ( *(_DWORD *)(a1 + 352) != 1 )
    {
      v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 7152LL));
      writel_relaxed(v5 & 0xFFFFFFBF, (unsigned int *)(*(_QWORD *)(a1 + 24) + 7152LL));
    }
    __dsb(0xFu);
    result = writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 1028LL));
    __dsb(0xFu);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 24) + 1028LL));
    __dsb(0xFu);
    v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 5104LL));
    writel_relaxed(v7 | 0x40, (unsigned int *)(*(_QWORD *)(a1 + 24) + 5104LL));
    if ( *(_DWORD *)(a1 + 352) != 1 )
    {
      v8 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 7152LL));
      writel_relaxed(v8 | 0x40, (unsigned int *)(*(_QWORD *)(a1 + 24) + 7152LL));
    }
    __dsb(0xFu);
    if ( *(_QWORD *)(a1 + 264) )
    {
      result = ufs_qcom_phy_disable_vreg(v2, a1 + 256);
      if ( (_DWORD)result )
        return dev_err(v2, "%s disable phy_gdsc err = %d\n", "ufs_qcom_phy_qmp_v4_power_control", result);
    }
    else
    {
      return _pm_runtime_idle(v2, 4);
    }
  }
  return result;
}
