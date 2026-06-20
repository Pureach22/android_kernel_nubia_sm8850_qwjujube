double __fastcall dsi_ctrl_hw_cmn_kickoff_fifo_command(_DWORD *a1, __int64 *a2, unsigned int a3)
{
  __int64 v5; // x22
  __int64 v7; // x23
  unsigned int v8; // w8
  int v9; // w0
  unsigned int v10; // w9
  int v11; // w10
  int v12; // w9
  int v13; // w10
  int v14; // w0
  int v15; // w4

  v5 = *a2;
  writel_relaxed_16(0x30006u, (unsigned int *)(*(_QWORD *)a1 + 348LL));
  if ( *((_DWORD *)a2 + 2) )
  {
    v7 = 0;
    do
    {
      writel_relaxed_16(*(_DWORD *)(v5 + v7), (unsigned int *)(*(_QWORD *)a1 + 380LL));
      v8 = *((_DWORD *)a2 + 2);
      v7 += 4;
    }
    while ( (unsigned int)v7 < v8 );
    if ( (v8 & 4) != 0 )
      writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 380LL));
  }
  v9 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 60LL));
  if ( *((_BYTE *)a2 + 12) )
    v10 = 0x80000000;
  else
    v10 = 0;
  if ( *((_BYTE *)a2 + 13) )
    v11 = 0x40000000;
  else
    v11 = 0;
  v12 = v10 | v11;
  if ( *((_BYTE *)a2 + 14) )
    v13 = 0x4000000;
  else
    v13 = 0;
  writel_relaxed_16(v9 & 0x2BFFFFFF | v12 | v13 | 0x10000000, (unsigned int *)(*(_QWORD *)a1 + 60LL));
  v14 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 912LL));
  writel_relaxed_16(v14 & 0xFFFFFFFD | (2 * ((a3 >> 12) & 1)), (unsigned int *)(*(_QWORD *)a1 + 912LL));
  writel_relaxed_16(*((_DWORD *)a2 + 2), (unsigned int *)(*(_QWORD *)a1 + 76LL));
  __dsb(0xEu);
  if ( (a3 & 1) == 0 )
    writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 144LL));
  if ( a1 )
    v15 = a1[14];
  else
    v15 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: size=%d, trigger = %d\n", v15, *((_DWORD *)a2 + 2), !(a3 & 1));
}
