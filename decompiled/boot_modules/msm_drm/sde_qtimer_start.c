size_t __fastcall sde_qtimer_start(__int64 a1)
{
  unsigned int v2; // w0
  unsigned __int64 v3; // x21
  unsigned __int64 v4; // x20
  int v5; // w7
  char v7; // [xsp+0h] [xbp+0h]

  v2 = readl_relaxed_10(*(_QWORD *)(a1 + 8) + 16LL);
  v3 = (*(_QWORD *)(a1 + 16) * (unsigned __int64)v2 / 0x3B9ACA00) << 11;
  v4 = *(_QWORD *)(a1 + 16) * (unsigned __int64)v2 / 0x3B9ACA00;
  writel_relaxed_8(2, *(_QWORD *)(a1 + 8) + 44LL);
  writel_relaxed_8((unsigned int)v4, *(_QWORD *)(a1 + 8) + 40LL);
  writel_relaxed_8(1, *(_QWORD *)(a1 + 8) + 44LL);
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_qtimer_start", 173, -1, v3 >> 43, v3 >> 11, -1059143953, v5, v7);
}
