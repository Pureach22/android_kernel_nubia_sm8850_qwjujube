double __fastcall dsi_ctrl_hw_cmn_enable_error_interrupts(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  int v5; // w0
  int v6; // w0
  int v7; // w0
  unsigned int v8; // w0
  int v9; // w9
  int v10; // w5
  int v11; // w4

  v4 = 2147433471;
  writel_relaxed_16(0x11111u, (unsigned int *)(*(_QWORD *)a1 + 180LL));
  writel_relaxed_16(0xCCCC0789, (unsigned int *)(*(_QWORD *)a1 + 12LL));
  writel_relaxed_16(0x11111111u, (unsigned int *)(*(_QWORD *)a1 + 192LL));
  writel_relaxed_16(0x1193BFFFu, (unsigned int *)(*(_QWORD *)a1 + 104LL));
  v5 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 288LL));
  writel_relaxed_16(v5 | 0x10000, (unsigned int *)(*(_QWORD *)a1 + 288LL));
  v6 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 8LL));
  writel_relaxed_16(v6 | 0x80000000, (unsigned int *)(*(_QWORD *)a1 + 8LL));
  v7 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL));
  if ( *(_BYTE *)(a1 + 1504) == 1 )
  {
    v8 = v7 & 0xFDFFFFFF;
  }
  else
  {
    v9 = 2147433470;
    if ( (a2 & 1) == 0 )
      v9 = 2147433471;
    if ( (a2 & 2) != 0 )
      v9 &= 0x7FFF3BFDu;
    if ( (a2 & 4) != 0 )
      v9 &= 0x7FFF3BFBu;
    if ( (a2 & 8) != 0 )
      v9 &= 0x7FFF3BF7u;
    if ( (a2 & 0x10) != 0 )
      v9 &= 0x7FFF3BEFu;
    if ( (a2 & 0x20) != 0 )
      v9 &= 0x7FFF3BDFu;
    if ( (a2 & 0x40) != 0 )
      v9 &= 0x7FFFFFBFu;
    if ( (a2 & 0x80) != 0 )
      v9 &= 0x7FFFFF7Fu;
    if ( (a2 & 0x100) != 0 )
      v9 &= 0x6FFFFFFFu;
    if ( (a2 & 0x1000000) != 0 )
      v9 &= 0x7EFFFFFFu;
    if ( (a2 & 0x10000000) != 0 )
      v9 &= ~0x2000000u;
    if ( (a2 & 0x200) != 0 )
      v9 &= ~0x200000u;
    if ( (a2 & 0x400) != 0 )
      v9 &= ~0x400000u;
    if ( (a2 & 0x800) != 0 )
      v9 &= ~0x800000u;
    if ( (a2 & 0x4000) != 0 )
      v9 &= ~0x200u;
    if ( (a2 & 0x8000) != 0 )
      v9 &= ~0x800u;
    if ( (a2 & 0x10000) != 0 )
      v9 &= ~0x10000u;
    if ( (a2 & 0x20000) != 0 )
      v9 &= ~0x20000u;
    if ( (a2 & 0x40000) != 0 )
      v9 &= ~0x40000u;
    if ( (a2 & 0x80000) != 0 )
      v9 &= ~0x80000u;
    if ( (a2 & 0x100000) != 0 )
      v9 &= ~0x4000000u;
    if ( (a2 & 0x200000) != 0 )
      v9 &= ~0x8000000u;
    if ( (a2 & 0x400000) != 0 )
      v9 &= ~0x20000000u;
    if ( (a2 & 0x800000) != 0 )
      v9 &= ~0x40000000u;
    v8 = v7 & 0xA8EEAAFE | ((a2 != 0) << 25);
    if ( (a2 & 0x2000) != 0 )
      v4 = v9 & 0xFFFFFEFF;
    else
      v4 = v9;
  }
  writel_relaxed_16(v8, (unsigned int *)(*(_QWORD *)a1 + 272LL));
  writel_relaxed_16(v4, (unsigned int *)(*(_QWORD *)a1 + 268LL));
  if ( a1 )
  {
    v10 = *(_DWORD *)(a1 + 56);
    v11 = v10;
  }
  else
  {
    v11 = -1;
    v10 = 2747744;
  }
  return _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dsi-debug]: DSI_%d: [DSI_%d] enable errors = 0x%llx, int_mask0=0x%x\n",
           v11,
           v10,
           a2,
           v4);
}
