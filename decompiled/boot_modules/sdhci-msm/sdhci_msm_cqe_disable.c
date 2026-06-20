__int64 __fastcall sdhci_msm_cqe_disable(__int64 a1, char a2)
{
  __int64 v4; // x21
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  int v6; // w0
  _DWORD *v7; // x8
  void (__fastcall *v8)(__int64, __int64, __int64); // x8

  if ( (*(_BYTE *)(a1 + 2589) & 0x10) != 0 )
    *(_DWORD *)(a1 + 2824) = 16;
  v4 = raw_spin_lock_irqsave(a1 + 2584);
  v5 = **(__int64 (__fastcall ***)(__int64, __int64))(a1 + 1856);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != 1381278590 )
      __break(0x8228u);
    v6 = v5(a1 + 1792, 52);
  }
  else
  {
    v6 = readl((unsigned int *)(*(_QWORD *)(a1 + 1816) + 52LL));
  }
  v7 = *(_DWORD **)(*(_QWORD *)(a1 + 1856) + 24LL);
  if ( v7 )
  {
    if ( *(v7 - 1) != 1259614694 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v7)(a1 + 1792, v6 | 1u, 52);
  }
  else
  {
    writel(v6 | 1, (unsigned int *)(*(_QWORD *)(a1 + 1816) + 52LL));
  }
  v8 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 1856) + 24LL);
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != 1259614694 )
      __break(0x8228u);
    v8(a1 + 1792, 1, 48);
  }
  else
  {
    writel(1u, (unsigned int *)(*(_QWORD *)(a1 + 1816) + 48LL));
  }
  raw_spin_unlock_irqrestore(a1 + 2584, v4);
  return sdhci_cqe_disable(a1, a2 & 1);
}
