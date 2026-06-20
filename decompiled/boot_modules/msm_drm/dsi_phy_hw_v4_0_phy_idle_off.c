__int64 __fastcall dsi_phy_hw_v4_0_phy_idle_off(unsigned int *a1)
{
  __int64 result; // x0
  __int64 v3; // x1

  result = readl_relaxed_13((unsigned int *)(*(_QWORD *)a1 + 60LL));
  __dsb(0xFu);
  if ( (result & 1) != 0 )
  {
    if ( a1 )
      v3 = a1[7];
    else
      v3 = 0xFFFFFFFFLL;
    result = printk(&unk_25FC9D, v3);
  }
  if ( a1[9] >= 4 )
  {
    writel_relaxed_10(1u, (unsigned int *)(*(_QWORD *)a1 + 276LL));
    return writel_relaxed_10(0, (unsigned int *)(*(_QWORD *)a1 + 48LL));
  }
  return result;
}
