size_t __fastcall dsi_ctrl_hw_cmn_kickoff_command(int *a1, __int64 a2, unsigned int a3)
{
  int v6; // w0
  unsigned int v7; // w9
  int v8; // w10
  int v9; // w9
  int v10; // w10
  int v11; // w0
  int v12; // w0
  int v13; // w0
  char v15; // [xsp+0h] [xbp+0h]

  v6 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 60LL));
  if ( *(_BYTE *)(a2 + 9) )
    v7 = 0x80000000;
  else
    v7 = 0;
  if ( *(_BYTE *)(a2 + 10) )
    v8 = 0x40000000;
  else
    v8 = 0;
  v9 = v7 | v8;
  if ( *(_BYTE *)(a2 + 11) )
    v10 = 0x4000000;
  else
    v10 = 0;
  writel_relaxed_16(v6 & 0xAFFFFFF | v9 | v10 | 0x10000000, (unsigned int *)(*(_QWORD *)a1 + 60LL));
  v11 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 912LL));
  writel_relaxed_16(v11 & 0xFFFFFFFD | (2 * ((a3 >> 12) & 1)), (unsigned int *)(*(_QWORD *)a1 + 912LL));
  v12 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 80LL));
  writel_relaxed_16(v12 | 0x110000, (unsigned int *)(*(_QWORD *)a1 + 80LL));
  writel_relaxed_16(*(_DWORD *)a2, (unsigned int *)(*(_QWORD *)a1 + 72LL));
  writel_relaxed_16(*(_DWORD *)(a2 + 4) & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + 76LL));
  if ( (unsigned int)*(a1 - 2) >= 8 )
  {
    v13 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 460LL));
    writel_relaxed_16(v13 | 7, (unsigned int *)(*(_QWORD *)a1 + 460LL));
  }
  __dsb(0xEu);
  if ( (a3 & 1) == 0 )
    writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 144LL));
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "dsi_ctrl_hw_cmn_kickoff_command",
           920,
           -1,
           a1[14],
           *(_DWORD *)(a2 + 4),
           a3,
           -1059143953,
           v15);
}
