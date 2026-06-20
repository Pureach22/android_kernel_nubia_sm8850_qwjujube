__int64 __fastcall dsi_ctrl_hw_22_configure_splitlink(__int64 a1, __int64 a2, __int16 a3)
{
  int v5; // w0
  int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w0
  __int64 result; // x0

  v5 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 816LL));
  if ( (a3 & 0x800) != 0 )
    v6 = 0x2000;
  else
    v6 = 12288;
  if ( (a3 & 0x400) != 0 )
    v6 = 4096;
  v7 = v5 & 0xFFFF8FFF | v6;
  if ( (a3 & 1) != 0 )
    v8 = v7 & 0xFFFF9FFF;
  else
    v8 = v7;
  result = writel_relaxed_17(v8, (unsigned int *)(*(_QWORD *)a1 + 816LL));
  __dsb(0xEu);
  return result;
}
