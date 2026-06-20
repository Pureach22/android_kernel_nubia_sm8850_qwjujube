__int64 __fastcall ufs_qcom_dev_ref_clk_ctrl(__int64 a1, char a2)
{
  __int64 result; // x0
  char v4; // w21
  unsigned int v6; // w0
  int v7; // w22
  unsigned int v8; // w20
  __int64 v9; // x8

  result = *(_QWORD *)(a1 + 160);
  if ( result )
  {
    v4 = a2 & 1;
    if ( *(_BYTE *)(a1 + 168) != (a2 & 1) )
    {
      v6 = readl_relaxed(result);
      v7 = *(_DWORD *)(a1 + 180);
      v8 = v6;
      if ( (a2 & 1) != 0 )
      {
        writel_relaxed(v7 | v6, *(_QWORD *)(a1 + 160));
        readl(*(unsigned int **)(a1 + 160));
        result = usleep_range_state(50, 60, 2);
      }
      else
      {
        v9 = *(unsigned int *)(*(_QWORD *)(a1 + 16) + 2564LL);
        if ( (_DWORD)v9 )
          usleep_range_state(v9 + 10, v9 + 20, 2);
        else
          _const_udelay(4295);
        writel_relaxed(v8 & ~v7, *(_QWORD *)(a1 + 160));
        result = readl(*(unsigned int **)(a1 + 160));
      }
      *(_BYTE *)(a1 + 168) = v4;
    }
  }
  return result;
}
