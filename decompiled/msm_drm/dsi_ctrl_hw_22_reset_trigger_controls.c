__int64 __fastcall dsi_ctrl_hw_22_reset_trigger_controls(_BYTE *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 result; // x0

  v4 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 132LL));
  v5 = *(unsigned int *)(a2 + 24);
  if ( (unsigned int)v5 >= 6 )
  {
    __break(0x5512u);
    return dsi_ctrl_hw_22_log_line_count(v4);
  }
  else
  {
    writel_relaxed_17(v4 & 0xFFF0FFF0 | byte_28FFE8[v5] & 0xF, (unsigned int *)(*(_QWORD *)a1 + 132LL));
    writel_relaxed_17(0, (unsigned int *)(*(_QWORD *)a1 + 260LL));
    result = writel_relaxed_17(0, (unsigned int *)(*(_QWORD *)a1 + 256LL));
    a1[1507] = 0;
  }
  return result;
}
