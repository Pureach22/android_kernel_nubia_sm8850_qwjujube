__int64 __fastcall dsi_ctrl_hw_cmn_mask_error_intr(__int64 a1, char a2, char a3)
{
  unsigned int v6; // w20
  int v7; // w0
  int v8; // w0
  int v9; // w0
  __int64 result; // x0

  v6 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 268LL));
  if ( (a2 & 2) != 0 )
  {
    if ( (a3 & 1) == 0 )
    {
      v6 &= 0xFFE0FDFF;
      v7 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 12LL));
      writel_relaxed_16(v7 | 0x44440400, (unsigned int *)(*(_QWORD *)a1 + 12LL));
      if ( (a2 & 4) == 0 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v6 |= 0x1F0200u;
    if ( (a2 & 4) == 0 )
      goto LABEL_10;
LABEL_7:
    v6 |= 0x6C000000u;
    goto LABEL_10;
  }
  if ( (a2 & 4) == 0 )
    goto LABEL_10;
  if ( (a3 & 1) != 0 )
    goto LABEL_7;
LABEL_9:
  v6 &= 0x93FFFFFF;
  v8 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 12LL));
  writel_relaxed_16(v8 | 0x88880000, (unsigned int *)(*(_QWORD *)a1 + 12LL));
LABEL_10:
  if ( (a2 & 8) != 0 )
  {
    if ( (a3 & 1) != 0 )
    {
      v6 |= 0x3800000u;
      if ( (a2 & 0x10) != 0 )
LABEL_16:
        v6 |= 0x10000000u;
    }
    else
    {
      v6 &= 0xFC7FFFFF;
      v9 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 192LL));
      writel_relaxed_16(v9 | 0x10, (unsigned int *)(*(_QWORD *)a1 + 192LL));
      if ( (a2 & 0x10) != 0 )
LABEL_18:
        v6 &= ~0x10000000u;
    }
  }
  else if ( (a2 & 0x10) != 0 )
  {
    if ( (a3 & 1) == 0 )
      goto LABEL_18;
    goto LABEL_16;
  }
  result = writel_relaxed_16(v6, (unsigned int *)(*(_QWORD *)a1 + 268LL));
  __dsb(0xEu);
  return result;
}
