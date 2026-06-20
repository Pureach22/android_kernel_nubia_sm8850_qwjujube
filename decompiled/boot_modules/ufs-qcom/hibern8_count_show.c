__int64 __fastcall hibern8_count_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x22
  int v5; // w20
  int v6; // w21
  int v7; // w23
  int v8; // w24
  int v9; // w25

  v3 = *(_QWORD **)(a1 + 152);
  _pm_runtime_resume(v3[8], 4);
  ufshcd_hold(v3);
  v5 = readl((unsigned int *)(*v3 + 9984LL));
  v6 = readl((unsigned int *)(*v3 + 9988LL));
  v7 = readl((unsigned int *)(*v3 + 9992LL));
  v8 = readl((unsigned int *)(*v3 + 9996LL));
  v9 = readl((unsigned int *)(*v3 + 10000LL));
  ufshcd_release(v3);
  _pm_runtime_idle(v3[8], 4);
  return (int)scnprintf(
                a3,
                4096,
                "%s: %d\n%s: %d\n%s: %d\n%s: %d\n%s: %d\n",
                "hw_h8_enter",
                v5,
                "sw_h8_enter",
                v6,
                "sw_after_hw_h8_enter",
                v7,
                "hw_h8_exit",
                v8,
                "sw_h8_exit",
                v9);
}
