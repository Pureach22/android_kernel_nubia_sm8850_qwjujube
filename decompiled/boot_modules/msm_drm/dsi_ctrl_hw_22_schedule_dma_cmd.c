__int64 __fastcall dsi_ctrl_hw_22_schedule_dma_cmd(_BYTE *a1, unsigned __int16 a2, char a3)
{
  unsigned int v4; // w0
  __int64 result; // x0

  if ( (a3 & 1) != 0 )
    v4 = 0;
  else
    v4 = a2 | (unsigned int)readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 256LL)) | 0x10000000;
  result = writel_relaxed_17(v4, (unsigned int *)(*(_QWORD *)a1 + 256LL));
  a1[1507] = 1;
  return result;
}
