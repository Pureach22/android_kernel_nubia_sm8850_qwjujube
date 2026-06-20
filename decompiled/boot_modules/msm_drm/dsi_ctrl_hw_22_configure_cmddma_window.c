__int64 __fastcall dsi_ctrl_hw_22_configure_cmddma_window(_BYTE *a1, __int64 a2, int a3, int a4)
{
  int v5; // w23
  int v9; // w0
  unsigned int v10; // w0
  __int64 result; // x0

  v5 = *(unsigned __int8 *)(a2 + 9);
  v9 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 132LL));
  if ( v5 != 1 )
  {
    writel_relaxed_17(v9 & 0xFFFFFFF0 | 0xC, (unsigned int *)(*(_QWORD *)a1 + 132LL));
LABEL_8:
    result = writel_relaxed_17(a3 | (unsigned int)(a4 << 16), (unsigned int *)(*(_QWORD *)a1 + 260LL));
    goto LABEL_9;
  }
  if ( *(_BYTE *)(a2 + 10) )
    v10 = v9 & 0xFFFFFFF0 | 0xC;
  else
    v10 = v9 & 0xFFFEFFF0 | 0x10000;
  result = writel_relaxed_17(v10, (unsigned int *)(*(_QWORD *)a1 + 132LL));
  if ( (*(_BYTE *)(a2 + 10) & 1) != 0 )
    goto LABEL_8;
LABEL_9:
  a1[1507] = 1;
  return result;
}
